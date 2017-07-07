import argparse
import sys
import os.path
import struct

import cobs
import psycopg2 as psql
import datetime as dt

sys.path.append(
    os.path.abspath(os.path.join(os.path.dirname(__file__), 'generated')))

from datalogger import datalogger_pb2

currdt = 0

def handleMsg(record, curr):
    msg = record.payload.receivedCanMessage
    if msg.HasField("id") and msg.HasField("data"):
        ts = currdt + dt.timedelta(0, 0, 0, record.timestamp_ms)
        #d = struct.unpack("l", msg.data)
        #print(d[0]);
        curr.execute("INSERT INTO RoadTestData VALUES (%s, %s, %s);", (ts, msg.id, msg.data))

def pbar(curr, max, sym='=', space=' ', arrow='>', nsyms=32):
  assert curr <= max
  if curr == 0:
    combined = space * nsyms
  elif curr == max:
    combined = sym * nsyms
  else:
    syms = int(curr * nsyms / max)
    if syms > 0:
      combined = (syms-1) * sym + arrow + (nsyms - syms) * space
    else:
      combined = arrow + (nsyms-1) * space

  return "[{0}] {1}/{2}".format(combined, curr, max)

if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument('infile', type=argparse.FileType('rb'), default=sys.stdin)
  args = parser.parse_args()
  
  conn = psql.connect("dbname=YugeData user=avinash")

  curr = conn.cursor()
  split = args.infile.read().split(b'\x00')

  if not split[0]:  # discard empty first message
    split = split[1:]

  msgs_raw = [cobs.decode(bytearray(x)) for x in split]
  msgs = [x for x in msgs_raw if x is not None]

  for i, msg in enumerate(msgs):
    record = datalogger_pb2.DataloggerRecord()
    record.ParseFromString(bytes(msg))
    #if i % 1000 == 999:
    #  sys.stdout.write('\r' + pbar(i+1, len(msgs)))
    #  sys.stdout.flush()
    if (record.HasField("payload") and record.payload.HasField("rtcTime")):
      #print(dir(record.payload.rtcTime))
      currdt = dt.datetime.fromtimestamp(record.payload.rtcTime.ToSeconds());
    if (record.HasField("payload") and record.payload.HasField("receivedCanMessage")):
      handleMsg(record, curr)

  conn.commit()
  # finish the progressbar
  #sys.stdout.write('\r' + pbar(i+1, len(msgs)))
  #sys.stdout.flush()    
  #sys.stdout.write('\n')

  print("Parsed %i messages" % len(msgs))
  if len(msgs) != len(msgs_raw):
    print("%i invalid messages" % len(msgs_raw) - len(msgs))

  curr.close()
  conn.close()
