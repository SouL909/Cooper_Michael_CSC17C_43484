/* 
 * File:   GameState.h
 * Author: Michael Cooper
 * Purpose: Graph Header File
 * Created on 6/5/22
 */

#ifndef GRAPH_H
#define GRAPH_H

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

	int find(int u, std::vector<int>& parent) {
		if (u != parent[u])
			parent[u] = find(parent[u], parent);
		return parent[u];
	}

	void mst() {
		int mst_weight = 0;
		std::vector<int> parents_src;
		std::vector<int> ranks;
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

#endif // GRAPH_H
