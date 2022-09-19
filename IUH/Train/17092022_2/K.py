def calArea(x1, y1, x2, y2, x3, y3):
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2

def dist(x1, y1, x2, y2):
	return (x1 - x2) ** 2 + (y1 - y2) ** 2

for _ in range(int(input())):
	x1, y1, x2, y2, x3, y3, xp, yp = list(map(int, input().split()))
	ok1 = ((xp - x1) * (y2 - y1)) == ((yp - y1) * (x2 - x1))
	ok2 = ((xp - x2) * (y3 - y2)) == ((yp - y2) * (x3 - x2))
	ok3 = ((xp - x3) * (y1 - y3)) == ((yp - y3) * (x1 - x3))

	ok1 &= (abs(max(x1, x2) - xp) <= 1e-6 and abs(min(x1,x2) - xp) <= 1e-6)
	ok2 &= (abs(max(x2, x3) - xp) <= 1e-6 and abs(min(x2,x3) - xp) <= 1e-6)
	ok3 &= (abs(max(x3, x1) - xp) <= 1e-6 and abs(min(x3,x1) - xp) <= 1e-6)

	tot = calArea(x1, y1, x2, y2, x3, y3)
	AP = dist(x1, y1, xp, yp)
	BP = dist(x2, y2, xp, yp)
	CP = dist(x3, y3, xp, yp)
	AB = dist(x1, y1, x2, y2)
	BC = dist(x2, y2, x3, y3)
	CA = dist(x3, y3, x1, y1)

	if (ok1):

	else:
		print(-1)


