import argparse
import sys
from subprocess import Popen, PIPE, STDOUT
import cobs

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

  msgs_raw = [cobs.decode(x) for x in split]
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
