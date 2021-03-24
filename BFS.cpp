// CodeForces.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

template <typename T>
struct node {
	T value = 0;
	vector<node*> nodes;
};

node<int>* generate() {
	node<int>* graph = new node<int>;
	graph->value = 5;
	graph->nodes.push_back(new node<int>);
	graph->nodes[0]->nodes.push_back(new node<int>);
	graph->nodes.push_back(new node<int>);
	return graph;
}

template <typename T>
void bfs(node<T>* graph) {
	queue<node<T>*> q;
	vector<node<int>*> used;
	q.push(graph);
	while (!q.empty()) {
		node<T>* current = q.front();
		//q.pop();
		cout << "NODE : " << current->value << endl;
		used.push_back(current);
		for (int i = 0, e = current->nodes.size(); i != e; i++) {
			if (!binary_search(used.begin(), used.end(), current->nodes[i]) ) {
				q.push(current->nodes[i]);
			}
		}
	}
}

using namespace std;
int main()
{
	node<int>* graph = generate();
	node<int>* graph2 = generate();
	bfs(graph);
}
