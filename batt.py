import psycopg2 as psql
import struct

conn = psql.connect("dbname=YugeData user=avinash")

curr = conn.cursor()

curr.execute("SELECT * FROM RoadTestData WHERE id = %s OR id = %s AND time_sent > TIMESTAMP '2017-07-06' ORDER BY time_sent DESC", [0x030, 0x032] )

rows = curr.fetchall()
for r in rows:
    if r[1] == 0x30:
      print(struct.unpack('I', r[2]))
    else:
      print(struct.unpack('H', r[2]))
