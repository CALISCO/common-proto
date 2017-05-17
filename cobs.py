def encode(in_bytearray):
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

def decode(in_bytearray):
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