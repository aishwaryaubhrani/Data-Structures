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
		
		void DFS(int n);
};

Graph::Graph(int v){
	this->v = v;
	adjacentNodes = new list<int>[v];
}

void Graph::addEdge(int x, int w){
	adjacentNodes[x].push_back(w);
}

void Graph::DFS(int s){
	bool *visitedNodes = new bool[v];
	
	for(int i = 0; i<v; i++){
		visitedNodes[i] = false;
	}
	
	list<int> stack;
	visitedNodes[s] = true;
	
	stack.push_back(s);
	
	list<int>::iterator i;
	
	while(!stack.empty()){
		s = stack.back();
		cout<<s<<" ";
		stack.pop_back();
		
		for(i = adjacentNodes[s].begin(); i!= adjacentNodes[s].end(); i++){
			if(!visitedNodes[*i]){
				visitedNodes[*i] = true;
				stack.push_back(*i);
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
  
    cout << "DFS order as starting node 2"<<endl; 
    graph.DFS(2); 
  
    return 0; 
}
