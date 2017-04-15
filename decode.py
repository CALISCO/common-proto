import argparse
import sys
from subprocess import Popen, PIPE, STDOUT

def cobs_encode(in_bytearray):
  """
  Encodes a bytearray into COBS. Does not include the start-of-frame or
  end-of-frame bytes.
  """
  out = bytearray()

  if len(in_bytearray) == 0:
    return b'\x01'

  while len(in_bytearray) > 0:
    next_zero = in_bytearray.find(b'\x00')
    if next_zero < 0:
      chunk_length = len(in_bytearray)
    else:
      chunk_length = next_zero

    while chunk_length > 253:
      out.append(255)
      out.extend(in_bytearray[:253])
      in_bytearray = in_bytearray[253:]
      chunk_length -= 253

    out.append(chunk_length + 1)
    if chunk_length > 0:
      out.extend(in_bytearray[:chunk_length])

    in_bytearray = in_bytearray[chunk_length + 1:]

    if len(in_bytearray) == 0 and next_zero >= 0:
      # if last byte is zero, add it here since there won't be any more iterations
      out.append(1)

  return out

def cobs_decode(in_bytearray):
  """
  Decodes a COBS bytearray. The input should not include the
  start-of-frame or end-of-frame bytes, it is an error (assertion) if a zero
  occurs in the sequence.
  Returns None if an invalid packet was detected.
  """
  assert in_bytearray.find(b'\x00') < 0

  out = bytearray()

  while len(in_bytearray) > 0:
    special_byte = in_bytearray[0]
    in_bytearray = in_bytearray[1:]

    if special_byte >= 255:
      chunk_length = 253
      # also invalid to end on 0xff
      if chunk_length >= len(in_bytearray):
        return None

      out.extend(in_bytearray[:chunk_length])
      in_bytearray = in_bytearray[chunk_length:]
    else:
      chunk_length = special_byte - 1
      if chunk_length > len(in_bytearray):
        return None
      out.extend(in_bytearray[:chunk_length])

      # don't append a zero if this points past the end of the input
      if chunk_length < len(in_bytearray):
        out.append(0)

      in_bytearray = in_bytearray[chunk_length:]

  return out

if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument('infile', type=argparse.FileType('rb'), default=sys.stdin)
  parser.add_argument('--count', action='store_true')
  parser.add_argument('--protopath', nargs='*')
  parser.add_argument('--message', required=True)
  parser.add_argument('--protofile', required=True)
  args = parser.parse_args()

  split = args.infile.read().split(bytes([0]))

  if args.count:
    print(len(split))
    exit()

  if not split[0]:  # discard empty first message
    split = split[1:]

  msgs_raw = [cobs_decode(x) for x in split]
  msgs = [x for x in msgs_raw if x is not None]

  protocmd = ['protoc']
  for path in args.protopath:
    protocmd.append('-I%s' % path)
  protocmd.append('--decode')
  protocmd.append(args.message)
  protocmd.append(args.protofile)

  for i, msg in enumerate(msgs):
    #print(protocmd)
    #print(msg)

    p = Popen(protocmd, stdout=PIPE, stdin=PIPE, stderr=PIPE)
    comm_data = p.communicate(input=msg)

    print("Message %i" % i)
    print(comm_data[0].decode("utf-8") )
    if (comm_data[1]):
      print("error: %s" % comm_data[1])

  if len(msgs) != len(msgs_raw):
    print("%i invalid messages")
