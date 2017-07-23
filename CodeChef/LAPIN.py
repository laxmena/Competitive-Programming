t = int(input())
for _ in range(t):
	inp = list(input().strip())
	l = len(inp)
	mid = l//2
	if l%2 == 0:
		first,last = inp[:mid],inp[mid:]
	else:
		first,last = inp[:mid],inp[mid+1:]
	frequency = [0]*26
	for i in first:
		frequency[ord(i)-ord('a')] += 1
	for i in last:
		frequency[ord(i)-ord('a')] -= 1
	flag = True
	for i in frequency:
		if i != 0:
			flag = False
			break
	if(flag):
		print("YES")
	else:
		print("NO")