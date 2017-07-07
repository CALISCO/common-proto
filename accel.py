import psycopg2 as psql
import datetime as dt
import matplotlib.pyplot as plt
import struct

def to_uint8(s):
    b = struct.unpack('BB', s)
    return b

def to_4uint16(m):
    return struct.unpack('HHHH', m)


conn = psql.connect("dbname=YugeData user=avinash")

curr = conn.cursor()

curr.execute("SELECT * FROM RoadTestData WHERE id = %s", [0x282] )

accel = []
brake = []
r = curr.fetchone()
while r:
    d = to_uint8(r[2])
    brake += [d[0]]
    accel += [d[1]]
    #print(avolt * acurr)
    #print(d[2])
    #print(d[3])
    r = curr.fetchone()

"""
rows = curr.fetchmany(100)
brake = []
accel = []
while len(rows) > 0:
    for r in rows:
        #print(r[2])
        unpacked = to_uint8(r[2])
        brake += [unpacked[0]]
        accel += [unpacked[1]]
    rows = curr.fetchmany(100)

#plt.plot(brake)
#plt.plot(accel)
plt.show()
"""

plt.plot(brake)
plt.plot(accel)

plt.show()

conn.commit()


curr.close()
conn.close()
