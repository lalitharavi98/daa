class Graph:
	def __init__(self,v,e):
		self.v=v
		self.e=e
		self.edges=[]
	def addEdge(self):
		
		print("enter the edges with their weight in the format (src dest weight)")
	
		for i in range(self.e):
			str=input()
			str=str.split()
			self.edges.append([int(str[0]),int(str[1]),int(str[2])])
	def bellmanFord(self,src):
		dist=[[float("inf") for i in range(self.v)]for j in range(self.v)]
		dist[src]=[0 for j in range(self.v)]
		for k in range(1,self.v):
			for v in range(self.v):
				dist[v][k]=dist[v][k-1]
				for u,v1,w in self.edges:
					if(v1==v):
						if dist[u][k-1]!=float("inf") and (dist[v][k]>(dist[u][k-1]+w)):
							dist[v][k]=dist[u][k-1]+w

		for u,v,w in self.edges:
			if dist[v][self.v-1]>dist[u][self.v-1]+w:
				print("Negative cycle:")
				return
		print("table:")
		print(dist)





def main():
	v=int(input("enter the total number of vertice:"))
	e=int(input("enter the total number of edges:"))
	g=Graph(v,e)
	g.addEdge()
	print("enter the source vertex:")
	src=int(input())
	g.bellmanFord(src)

main()
