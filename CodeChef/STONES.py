t = int(input())
for _ in range(t):
	count = 0
	jewels = set(list(input()))
	st = list(input())
	for i in st:
		if i in jewels:
			count+=1 
	print (count)