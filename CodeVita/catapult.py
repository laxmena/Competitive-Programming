n = int(input())

grid = [[],]
align = [(0) for i in range(n+1)]
consolidated = [(0) for i in range(n+1)]
zeros = []

_sum = 0

for _ in range(n):
	row = [0] + [int(i) for i in input().strip().split(',')]
	for each in range(len(row)):
		if(row[each] == 1):
			align[each] += 1
			_sum += each
	grid.append(row)

# for each in range(align):

right_sum = 0
leftSum = n

mid = round(_sum/n)

totalCost = 0

for row in range(1,len(grid)):
	for elem in range(1,len(grid[row])):
		if(grid[row][elem] == 1):
			consolidated[row] += 1
			totalCost += abs(mid-elem)


for i in range(1,len(consolidated)):
	if consolidated[i]==0:
		zeros.append(i)

zeros.sort()

for position in range(1,len(consolidated)):
	while(consolidated[position] > 1):
		cost = 52
		selectZero = -1
		for i in zeros:
			if(abs(position-1) < cost):
				selectZero = i
				cost = abs(position-i)
		totalCost += cost
		if(selectZero != -1):
			zeros.remove(selectZero)
		consolidated[position] -= 1;

print(totalCost)