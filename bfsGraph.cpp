#include<iostream>
#include <list>

//BFS in C++ using STL library
using namespace std;

class Graph{
	int v;
	list<int> *adjacentNodes;
	
	public:
		Graph(int v);
		
		void addEdge(int x, int w);
		
		void BFS(int n);
};

Graph::Graph(int v){
	this->v = v;
	adjacentNodes = new list<int>[v];
}

void Graph::addEdge(int x, int w){
	adjacentNodes[x].push_back(w);
}

void Graph::BFS(int s){
	bool *visitedNodes = new bool[v];
	
	for(int i = 0; i<v; i++){
		visitedNodes[i] = false;
	}
	
	list<int> queue;
	visitedNodes[s] = true;
	
	queue.push_back(s);
	
	list<int>::iterator i;
	
	while(!queue.empty()){
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();
		
		for(i = adjacentNodes[s].begin(); i!= adjacentNodes[s].end(); i++){
			if(!visitedNodes[*i]){
				visitedNodes[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main(){
	Graph graph(4);
	Graph g(4); 
    graph.addEdge(0, 1); 
    graph.addEdge(0, 2); 
    graph.addEdge(1, 2); 
    graph.addEdge(2, 0); 
    graph.addEdge(2, 3); 
    graph.addEdge(3, 3); 
  
    cout << "BFS order as starting node 2"<<endl; 
    graph.BFS(2); 
  
    return 0; 
}
