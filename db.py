import psycopg2 as psql
import datetime as dt
import matplotlib.pyplot as plt
import struct
import csv
import numpy as np

def to_uint8(s):
    b = struct.unpack('BB', s)
    return b

def to_4uint16(m):
    return struct.unpack('HHHH', m)

writer = csv.writer(open('stuff.csv', 'w'))
conn = psql.connect("dbname=YugeData user=avinash")

curr = conn.cursor()
start = '2017-07-06 14:40:00'
end = '2017-07-06 16:00:00'

curr.execute("SELECT * FROM RoadTestData WHERE id = %s AND time_sent > TIMESTAMP '" + start + "' AND time_sent < TIMESTAMP '" + end + "' ORDER BY time_sent ASC", [0x600] )

powers = [0.0,0.0,0.0,0.0]

powers1 = []
r = curr.fetchone()
while r:
    if len(r[2]) == 8:
        d = to_4uint16(r[2])
        avolt = d[0] / 100
        acurr = d[1] / 1000
        powers1 += [avolt * acurr]
        #print(avolt * acurr)
        #print(d[2])
        #print(d[3])
    r = curr.fetchone()
p1avg = np.average(powers1)
print("p1 avg: " + str(p1avg))



curr.execute("SELECT * FROM RoadTestData WHERE id = %s AND time_sent > TIMESTAMP '" + start + "' AND time_sent < TIMESTAMP '" + end + "' ORDER BY time_sent ASC", [0x601] )

powers2 = []
r = curr.fetchone()
while r:
    if len(r[2]) == 8:
        d = to_4uint16(r[2])
        avolt = d[0] / 100
        acurr = d[1] / 1000
        powers2 += [avolt * acurr]
        #print(avolt * acurr)
        #print(d[2])
        #print(d[3])
    r = curr.fetchone()
p2avg = np.average(powers2)
print("p2 avg: " + str(p2avg))
curr.execute("SELECT * FROM RoadTestData WHERE id = %s AND time_sent > TIMESTAMP '" + start + "' AND time_sent < TIMESTAMP '" + end + "' ORDER BY time_sent ASC", [0x602] )

powers3 = []
r = curr.fetchone()
while r:
    if len(r[2]) == 8:
        d = to_4uint16(r[2])
        avolt = d[0] / 100
        acurr = d[1] / 1000
        powers3 += [avolt * acurr]
        #print(avolt * acurr)
        #print(d[2])
        #print(d[3])
    r = curr.fetchone()
p3avg = np.average(powers3)
print("p3 avg: " + str(p3avg))
curr.execute("SELECT * FROM RoadTestData WHERE id = %s AND time_sent > TIMESTAMP '" + start + "' AND time_sent < TIMESTAMP '" + end + "' ORDER BY time_sent ASC", [0x603] )

powers4 = []
r = curr.fetchone()
while r:
    if len(r[2]) == 8:
        d = to_4uint16(r[2])
        avolt = d[0] / 100
        acurr = d[1] / 1000
        powers4 += [avolt * acurr]
        #print(avolt * acurr)
        #print(d[2])
        #print(d[3])
    r = curr.fetchone()
p4avg = np.average(powers4)
print("p4 avg: " + str(p4avg))

current = 0
voltage = 0
realpower = []
curr.execute("SELECT * FROM RoadTestData WHERE id = %s OR id = %s", [0x123, 0x124] )
r = curr.fetchone()
while r:
    f = struct.unpack('f', r[2])[0]
    if (r[1] == 0x123):
        voltage = f
    else:
        current = f
    print(str(voltage) + " " + str(current))
    realpower += [voltage * current]
    r = curr.fetchone()

plt.plot(powers1)
plt.plot(powers2)
plt.plot(powers3)
plt.plot(powers4)

fig2, ax2 = plt.subplots()
ax2.plot(realpower)
plt.show()

conn.commit()


curr.close()
conn.close()

"""
curr.execute("SELECT * FROM RoadTestData WHERE id >= %s AND id <= %s AND time_sent > TIMESTAMP '2017-07-05' ORDER BY time_sent ASC", [0x600, 0x603] )

r = curr.fetchone()
while r:
    if len(r[2]) == 8:
        ind = r[1] - 0x600
        d = to_4uint16(r[2])
        avolt = d[0] / 100
        acurr = d[1] / 1000
        powers[ind] = avolt * acurr
        writer.writerow([r[0]] + powers)
    r = curr.fetchone()
    """

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

