#CodeVita - Even Groups
graph = []

def countEven():
	count = 0
	for eachSet in graph:
		if(len(eachSet) % 2 == 0):
			count += 1
	return count

def insertNode(source, destination):
	sourceIndex,destinationIndex = -1,-1
	for setIndex in range(len(graph)):
		if graph[setIndex].issuperset([source]):
			sourceIndex = setIndex
		if graph[setIndex].issuperset([destination]):
			destinationIndex = setIndex

	#New Disconnected Graph
	if sourceIndex == destinationIndex == -1:
		newGraph = set([source,destination])
		graph.append(newGraph)

	#Both Source and Destination are in same graph
	elif sourceIndex == destinationIndex:
		return

	#If one node is present and other is not
	elif sourceIndex == -1 or destinationIndex == -1:
		if(sourceIndex == -1):
			graph[destinationIndex].add(source)
		else:
			graph[sourceIndex].add(destination)

	#Connect two disconnected graphs
	else:
		graph[sourceIndex] = graph[sourceIndex].union(graph[destinationIndex])
		del(graph[destinationIndex])

n = int(input())
while True:
	command = input()
	if command == '-1':
		break
	ex,i,j = command.strip().split(' ')
	source,destination = int(i), int(j)
	if ex == 'Q':
		print(countEven())
	else:
		insertNode(source,destination)
