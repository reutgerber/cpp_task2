//322516840
//reutgerber@gmail.com
//task2
#ifndef _algorithmshpp_
#define _algorithmshpp_


#include "Graph.hpp"
#include <string>
#include <queue>
#include <stack>
#include <map>
#include "Edges.hpp"
namespace ariel
{
	class Algorithms
	{
	private:
		//DFS attributes
		;
		static void dfs(int x, vector<vector<int>>& gr, vector<bool>& vis);
		static void dfs_negative(Graph& g, int x, vector<vector<int>>& gr, vector<bool>& vis, stack<int>& s, Edges& edges, bool& finished);
		static void dfs_cycle(Graph& g, int x, vector<vector<int>>& gr, vector<bool>& vis, stack<int>& s, Edges& edges, bool& finished);
		static void fill_neighbers(Graph& g, vector<vector<int>>& gr);
		static bool in_vect(vector<int> v, int x);
		static bool dfs(int node, int color, vector<int>& colors, vector<vector<int>>& gr);
		static void print_path(vector<int>& v);


		static int calc_path_weight(stack<int>& s, Graph& g, vector<int>& v);
	public:
		static bool  isConnected(Graph& g);
		static string shortestPath(Graph& g, int from, int to);
		static bool isContainsCycle(Graph& g);
		static string isBipartite(Graph& g);
		static bool isNegativeCycle(Graph& g);
	};
}

#endif