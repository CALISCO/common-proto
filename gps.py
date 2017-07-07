import psycopg2 as psql
import datetime as dt
import matplotlib.pyplot as plt
import struct

def to_uint8(s):
    b = struct.unpack('BB', s)
    return b

def to_2uint32(m):
    return struct.unpack('II', m)


conn = psql.connect("dbname=YugeData user=avinash")

curr = conn.cursor()

curr.execute("SELECT * FROM RoadTestData WHERE id = %s AND time_sent > TIMESTAMP '2017-07-06'", [0x750] )

lats = []
longs = []
r = curr.fetchone()
while r:
    d = to_2uint32(r[2])
    if d[0] != 0:
        lats += [d[0]]
        longs += [d[1]]
    r = curr.fetchone()


plt.scatter(lats, longs, marker = ',')
plt.show()

conn.commit()


curr.close()
conn.close()
