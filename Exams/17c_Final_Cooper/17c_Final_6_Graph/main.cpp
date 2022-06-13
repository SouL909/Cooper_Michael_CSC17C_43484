/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Jun 9, 2022, 9:00 AM
 * Purpose: Final: Problem 6 Weighted Graph
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

struct Edge
{
	std::string src_name;
	std::string dest_name;
	int src, dest, weight;
	const bool operator==(Edge comp)
	{
		return (src_name == comp.src_name && dest_name == comp.dest_name && src == comp.src &&
			dest == comp.dest && comp.weight == weight);
	}
	const bool operator< (Edge comp) {
		return weight < comp.weight;
	}
};

bool compare(const Edge& a, const Edge& b) {
	return a.weight < b.weight;
}

struct DisjointSets
{
	int* parent, * rnk;
	int n;

	// Constructor.
	DisjointSets(int n)
	{
		// Allocate memory
		this->n = n;
		parent = new int[n + 1];
		rnk = new int[n + 1];

		// Initially, all vertices are in
		// different sets and have rank 0.
		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;

			//every element is parent of itself
			parent[i] = i;
		}
	}

	// Find the parent of a node 'u'
	// Path Compression
	int find(int u)
	{
		/* Make the parent of the nodes in the path
		   from u--> parent[u] point to parent[u] */
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	// Union by rank
	void merge(int x, int y)
	{
		x = find(x), y = find(y);

		/* Make tree with smaller height
		   a subtree of the other tree  */
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else // If rnk[x] <= rnk[y]
			parent[x] = y;

		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};
Edge make_edge(std::string src_name, std::string dest_name, int src, int dest, int weight) {
	Edge edge;
	edge.src_name = src_name;
	edge.dest_name = dest_name;
	edge.src = src;
	edge.dest = dest;
	edge.weight = weight;
	return edge;
}
class Graph
{
public:
	Graph(int vertices, std::vector<Edge> list)
	{
		edges = new std::vector<Edge>[vertices];
		this->vertices = vertices;
		for (std::vector<Edge>::iterator itr = list.begin(); itr != list.end(); itr++)
		{
			pushEdge(*itr);
		}
	}
	~Graph()
	{
		delete[] edges;
	}
	void pushEdge(Edge edge)
	{
		Edge inverted = invertedEdge(edge);
		edges[edge.src].push_back(edge);
		edges[edge.dest].push_back(inverted);
	}
	//Leave their dest and weight empty
	std::pair<int, std::vector<Edge> > cheapestPath(int start, int end)
	{
		int min_weight = std::numeric_limits<int>::max();
		std::vector<Edge> path;
		Edge current = edges[start][0];
		bool found = false;
		int current_weight = 0;
		path.push_back(edges[start][0]);
		if (start == end)
		{
			return std::make_pair(current_weight, path);
		}
		while (!found)
		{
			std::vector<Edge> check = edges[current.src];
			Edge next;
			//for (auto edge : check)
			for(std::vector<Edge>::iterator edge = check.begin(); edge != check.end(); edge++)
			{
				if (min_weight >= edge->weight)
				{
					min_weight = edge->weight;
					next = invertedEdge(*edge);
				}
				if (edge->dest == edges[end][0].src)
				{
					min_weight = edge->weight;
					found = true;
				}
			}
			current = next;
			current_weight += min_weight;
			path.push_back(current);
			min_weight = std::numeric_limits<int>::max();
		}
		return std::make_pair(current_weight, path);
	}

	int find(int u, std::vector<int>& parent) {
		if (u != parent[u])
			parent[u] = find(parent[u], parent);
		return parent[u];
	}

	void mst() {
		int mst_weight = 0;
		std::vector<int> parents_src;
		std::vector<int> ranks;
		DisjointSets ds(vertices);
		for (int i = 0; i < vertices; i++) {
			parents_src.push_back(i);
			std::sort(edges[i].begin(), edges[i].end(), compare);	// Sorting by weight
			ranks.push_back(0);
		}
		for (int i = 0; i < vertices; i++) {
			for (int j = 0; j < edges[i].size(); j++) {
				int v = edges[i][j].dest;
				int set_u = find(i, parents_src);
				int set_v = find(v, parents_src);

				if (set_u != set_v) {
					std::cout << edges[i][0].src_name << "->" << edges[v][0].src_name << std::endl;
					ds.merge(set_u, set_v);
					
				}
			}
		}
	}
private:
	Edge invertedEdge(Edge edge)
	{
		return make_edge( edge.dest_name,edge.src_name,edge.dest,edge.src,edge.weight );
	}
private:
	std::vector<Edge>* edges;
	int vertices;
};



int main()
{
	std::vector<Edge> edges;
	edges.push_back(make_edge("SFO", "BOS", 0, 1, 2703));
	edges.push_back(make_edge("SFO", "ORD", 0, 2, 1847));
	edges.push_back(make_edge("ORD", "BOS", 2, 1, 868))	;
	edges.push_back(make_edge("ORD", "JFK", 2, 3, 743))	;
	edges.push_back(make_edge("JFK", "BOS", 3, 1, 189))	;
	edges.push_back(make_edge("SFO", "DFW", 0, 4, 1465));
	edges.push_back(make_edge("DFW", "ORD", 4, 2, 803))	;
	edges.push_back(make_edge("DFW", "MIA", 4, 5, 1124));
	edges.push_back(make_edge("MIA", "JFK", 5, 3, 1093));
	edges.push_back(make_edge("MIA", "BOS", 5, 1, 1257));
	edges.push_back(make_edge("SFO", "LAX", 0, 6, 338))	;
	edges.push_back(make_edge("LAX", "DFW", 6, 4, 1234));
	edges.push_back(make_edge("LAX", "MIA", 6, 5, 2341));

	Graph graph(7, edges);


	std::pair<int, std::vector<Edge> >  pair = graph.cheapestPath(2, 3);
	std::cout << "Weight: " << pair.first << std::endl;
	std::cout << "Path:";
	//for (auto p : pair.second)
	for(std::vector<Edge>::iterator p = pair.second.begin(); p != pair.second.end(); p++)
	{
		std::cout << " ->" << p->src_name << "(" << p->weight << ")";
	}

	pair = graph.cheapestPath(3, 0);
	std::cout << std::endl << "Weight: " << pair.first << std::endl;
	std::cout << "Path:";
	for (std::vector<Edge>::iterator p = pair.second.begin(); p != pair.second.end(); p++)
	{
		std::cout << " ->" << p->src_name << "(" << p->weight << ")";
	}

	std::cout << std::endl << "Minimum spanning tree" << std::endl;

	graph.mst();
	return 0;
}