class Node:
    def __init__(self, data):
        self.data = data
        self.dependency = 0
        self.children = []
        
class Graph:
    processOrder = []
    buildOrder = []
    
    def __init__(self, nodes):
        self.nodes = nodes
        self.adjList = []
        self.hashmap = {}

    def createNode(self, data):
        node = Node(data)
        self.hashmap[data] = node
        
    def getOrCreateNode(self, data):
        if data not in self.hashmap:
            self.createNode(data)
        return self.hashmap[data]

    def addEdge(self, source, destination):
        s = self.getOrCreateNode(source)
        d = self.getOrCreateNode(destination)
        s.children.append(d)
        d.dependency += 1

    def addZeroDepedency(self):
        for key in self.hashmap:
            value = self.hashmap[key]
            if value.dependency == 0:
                self.processOrder.append(self.hashmap[key])

    def generateBuildOrder(self):
        while(len(self.buildOrder) < self.nodes):
            self.addZeroDepedency()
            if len(self.processOrder) == 0:
                return
            for each in self.processOrder:
                self.buildOrder.append(each.data)
                for child in each.children:
                    child.dependency -= 1
            self.processOrder = []
        

projects = input().strip().split(' ')

g = Graph(len(projects))

for project in projects:
    g.createNode(project)
    
dependencyCount = int(input())
for _ in range(dependencyCount):
    parent, child = input().strip().split(' ')
    g.addEdge(parent, child)

g.generateBuildOrder()
print(g.buildOrder)
