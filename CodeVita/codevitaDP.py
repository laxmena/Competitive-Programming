from pprint import pprint

maze = []
count = 0
for row in range(20):
	eachRow = []
	for elem in range(20):
		element = {"dist":450,"rightW":False,"bottomW":False,"openDoor":False}
		eachRow.append(element)
		count += 1
	maze.append(eachRow)

def getLeft(coord):
	tup = (coord[0],coord[1]-1)
	return (tup)

def getTop(coord):
	tup = (coord[0]-1,coord[1])
	return tup

def isValid(coord):
	if(coord[0] < 0 or coord[0]>=n):
		return False
	if(coord[1] < 0 or coord[1]>=n):
		return False
	return True

def getCell(coord):
	return maze[coord[0]][coord[1]]

def dp():
	maze[n-1][n-1]['dist'] = 1
	maze[n-1][n-1]['openDoor'] = False
	cell = (n-1,n-1)
	toDo = [cell]
	while(len(toDo) != 0):
		current = getCell(toDo[0])

		left = getLeft(toDo[0])
		top = getTop(toDo[0])

		leftCell = getCell(left)
		topCell = getCell(top)

		if(isValid(left) and leftCell['dist'] >= current['dist']+1):
			if(current['openDoor'] == False):
				leftCell['dist'] = current['dist'] + 1
				if(leftCell['rightW'] == True):
					leftCell['openDoor'] = True
				else:
					leftCell['openDoor'] = False
			else:
				if(leftCell['rightW'] == False):
					leftCell['dist'] = current['dist'] + 1

		if(isValid(top) and topCell['dist'] >= current['dist']+1):
			if(current['openDoor'] == False):
				topCell['dist'] = current['dist'] + 1
				if(topCell['bottomW'] == True):
					topCell['openDoor'] = True
				else:
					topCell['openDoor'] = False
			else:
				if(topCell['bottomW'] == False):
					topCell['dist'] = current['dist'] + 1

		if(isValid(left)):
			toDo.append(left)
		if(isValid(top)):
			toDo.append(top)
		del(toDo[0])


def addWall(x1,y1,x2,y2):
	X1,Y1 = n-y1,x1
	X2,Y2 = n-y2,x2

	if(X1 == X2):
		if(Y1>Y2):
			Y1,Y2 = Y2,Y1
		for i in range(Y1,Y2):
			maze[X1-1][i]['bottomW'] = True

	if(Y1 == Y2):
		if(X1>X2):
			X1,X2 = X2,X1
		for i in range(X1,X2):
			maze[i][Y1-1]['rightW'] = True


n,k = [int(num) for num in input().strip().split(',')]
for i in range(k):
	x1,y1,x2,y2 = [int(num) for num in input().strip().split(',')]
	addWall(x1,y1,x2,y2)

dp()
for i in range(n):
	for j in range(n):
		print(maze[i][j])
	print("----------")
