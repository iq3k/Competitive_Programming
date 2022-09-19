import math
n, k, m = map(int, input().split())
 
a = list()
for i in range(100000):
    a.append(1)
a[0] = 1
a[1] = 1
ok = True
for i in range(2, int(math.sqrt(m) + 1)):
    if m % i == 0:
        ok = False
if m > 1000000 and ok:
    for i in range(1, 1000003):
        a[i] = (a[i - 1] * i) % m
else:
    for i in range(1, 12500):
        a[i] = (a[i - 1] * i)

print((a[n] // (a[k] * a[n - k])) % m)