
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

template <typename T>
struct node {
	T value = 0;
	vector<node*> nodes;
	node (T val){
	    value = val;
	};
};

node<int>* generate() {
	node<int>* graph = new node<int>(9);
	graph->nodes.push_back(new node<int>(7));
	graph->nodes[0]->nodes.push_back(new node<int>(8));
	graph->nodes.push_back(graph->nodes[0]);
	return graph;
}

template <typename T>
void bfs(node<T>* graph) {
	queue<node<T>*> q;
	vector<node<int>*> used;
	map<node<int>*, int> cnt;
	q.push(graph);
	cnt[graph] = 0;
	used.push_back(graph);
	while (!q.empty()) {
		node<T>* current = q.front();
		q.pop();
		cout << "NODE " << cnt[current] << " : " << current->value <<  endl;
		for (int i = 0, e = current->nodes.size(); i != e; i++) {
		    node<int>* neighbor = current->nodes[i];
			if (!binary_search(used.begin(), used.end(), neighbor) ) {
				q.push(neighbor);
				cnt[neighbor] = cnt[current] + 1;
                used.push_back(neighbor);
			}
		}
	}
}

vector<node<int>*> used;
void dfs(node<int>* graph, int level = 0){
    used.push_back(graph);
    cout << "NODE "  << level << " : " << graph->value << endl;
    for (int i = 0, e = graph->nodes.size(); i != e ; i++) {
        node<int>* nod = graph->nodes[i];
        if (!binary_search(used.begin(), used.end(), nod)) {
            dfs(nod, level+1);
        }
    }
}

using namespace std;
int main()
{
	node<int>* graph = generate();
	dfs(graph);
}
