n1,n2,n3 = input().strip().split(' ')
n1,n2,n3 = int(n1), int(n2), int(n3)

voterId = {}

for _ in range(n1):
	id = int(input())
	voterId[id] = 1

for _ in range(n2):
	id = int(input())
	if id in voterId:
		voterId[id] += 1 
	else:
		voterId[id] = 1	

for _ in range(n3):
	id = int(input())
	if id in voterId:
		voterId[id] += 1 
	else:
		voterId[id] = 1	

result = []

for id in voterId:
	if voterId[id] > 1:
		result.append(id)

result.sort()
print(len(result))
for each in result:
	print(each)