//322516840
//reutgerber@gmail.com
//task2

#include "Algorithms.hpp"
#include "Vertex.hpp"
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>




using namespace ariel;
using namespace std;




bool Algorithms::in_vect(vector<int> v, int x)
{
	for (int i = 0; i < v.size(); i++)
		if (v[i] == x)
			return true;
	return false;

}

void Algorithms::fill_neighbers(Graph& g, vector<vector<int>>& gr)
{
	gr.resize(g.get_num_of_vertex());


	for (int i = 0; i < g.get_num_of_vertex(); i++)
		for (int j = 0; j < g.get_num_of_vertex(); j++)
		{
			if (g.connected(i, j))
			{
				if (!in_vect(gr[i], j))
					gr[i].push_back(j);

			}


		}
}

void Algorithms::dfs(int x, vector<vector<int>>& gr, vector<bool>& vis)
{
	vis[x] = true;

	for (auto i : gr[x])
		if (!vis[i])
			dfs(i, gr, vis);

}




void Algorithms::print_path(vector<int>& v)
{
	cout << "cycle path: ";
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << ",";
}

void Algorithms::dfs_negative(Graph& g, int x, vector<vector<int>>& gr, vector<bool>& vis, stack<int>& s, Edges& edges, bool& finished)
{
	if (finished)
		return;

	vis[x] = true;
	s.push(x);
	/*int a = s.top();
	cout << "added " << a << endl;*/



	for (auto i : gr[x])
	{
		if (finished)
			break;
		if (!vis[i] && !edges.contains(x, i))//can move to i and not visted
		{
			edges.add(x, i);
			dfs_negative(g, i, gr, vis, s, edges, finished);
		}
		else if (vis[i] && !edges.contains(x, i))//we have a cycle
		{
			s.push(i);
			vector<int> v;
			int weight = calc_path_weight(s, g, v);
			/*	cout << " cycle weight=" << weight<<" ";
				print_path(v);
				cout << endl;*/
			if (weight >= 0)
			{
				/*	int a=s.top();
					cout << "remove " << a << endl;*/
					/*int a = s.top();
					vis[a] = false;*/
				s.pop();
				continue;
			}
			finished = true;

			return;
		}
		else if (edges.contains(x, i))//this node was used in other direction
		{
			continue;
		}

	}
	if (!finished)
	{
		//cout << " remove " << s.top();
		int a = s.top();
		s.pop();
		vis[a] = false;
	}
	return;
}

void Algorithms::dfs_cycle(Graph& g, int x, vector<vector<int>>& gr, vector<bool>& vis, stack<int>& s, Edges& edges, bool& finished)
{
	if (finished)
		return;

	vis[x] = true;
	s.push(x);

	for (auto i : gr[x])
	{
		if (finished)
			break;
		if (!vis[i] && !edges.contains(x, i))//can move to i and not visted
		{
			edges.add(x, i);
			dfs_cycle(g, i, gr, vis, s, edges, finished);
		}
		else if (vis[i] && !edges.contains(x, i))//we have a cycle
		{
			s.push(i);
			vector<int> v;
			//int weight = calc_path_weight(s, g, v);
			finished = true;

			return;
		}
		else if (edges.contains(x, i))//this node was used in other direction
		{
			continue;
		}

	}
	if (!finished)
	{
		int a = s.top();
		s.pop();
		vis[a] = false;
	}
	return;
}

int Algorithms::calc_path_weight(stack<int>& s, Graph& g, vector<int>& v)
{

	while (!s.empty())
	{
		int x = s.top();
		v.push_back(x);
		s.pop();
	}

	int sum_weight = 0;
	for (int i = v.size() - 1; i > 0; i--)
	{

		sum_weight += g.weight(v[i], v[i - 1]);

	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		s.push(v[i]);
	}

	return sum_weight;

}
bool Algorithms::isNegativeCycle(Graph& g)
{
	vector<vector<int>> gr;
	vector<bool> vis(g.get_num_of_vertex(), false);

	fill_neighbers(g, gr);
	stack<int> s;
	bool finished = false;
	Edges edges(g);
	dfs_negative(g, 0, gr, vis, s, edges, finished);

	if (finished == true)
	{
		vector<int> v;
		int weight = calc_path_weight(s, g, v);
		print_path(v);
		cout << " weight=" << weight << endl;
		return true;
	}
	else
	{
		return false;
	}

}


bool Algorithms::isContainsCycle(Graph& g)
{
	vector<vector<int>> gr;
	vector<bool> vis(g.get_num_of_vertex(), false);

	fill_neighbers(g, gr);
	stack<int> s;
	bool finished = false;
	Edges edges(g);
	dfs_cycle(g, 0, gr, vis, s, edges, finished);

	if (finished == true)
	{
		vector<int> v;
		int weight = calc_path_weight(s, g, v);
		print_path(v);
		cout << " weight=" << weight << endl;
		return true;
	}
	else
	{
		return false;
	}

}



bool Algorithms::isConnected(Graph& g)
{
	vector<bool> vis1(g.get_num_of_vertex(), false);

	vector<vector<int>> gr1;

	fill_neighbers(g, gr1);



	for (int k = 0; k < g.get_num_of_vertex(); k++)
	{
		for (int j = 0; j < g.get_num_of_vertex(); j++)
			vis1[j] = false;

		dfs(k, gr1, vis1);
		for (int i = 0; i < g.get_num_of_vertex(); i++)
		{
			if (!vis1[i])
			{
				return 0;
			}
		}
	}


	return 1;
}
string Algorithms::shortestPath(Graph& g, int from, int to)
{

	vector<Vertex> vect;
	for (int i = 0; i < g.get_num_of_vertex(); i++)
	{
		Vertex v(i);
		vect.push_back(v);
	}



	for (int i = 0; i < g.get_num_of_vertex(); i++)
		for (int j = 0; j < g.get_num_of_vertex(); j++)
		{
			if (g.connected(i, j))
			{
				int w = g.weight(i, j);
				vect[i].add_neighbor(j, w);
			}
		}

	vect[from].set_distance(0);
	for (int counter = 0; counter < vect.size() - 1; counter++)
	{
		bool updated = false;
		for (int i = 0; i < vect.size(); i++)
		{
			auto neighbors = vect[i].get_neighbors();
			int d = vect[i].get_distance();
			for (int j = 0; j < neighbors.size(); j++)
			{
				int w = neighbors[j].get_weight();
				int num = neighbors[j].get_num();
				int current_distance = vect[num].get_distance();
				if (d + w < current_distance)
				{
					updated = true;
					vect[num].set_distance(d + w);
					vect[num].set_prev(i);
				}
			}

		}
		if (!updated)
			break;


	}
	bool updated = false;
	for (int i = 0; i < vect.size(); i++)
	{
		auto neighbors = vect[i].get_neighbors();
		int d = vect[i].get_distance();
		for (int j = 0; j < neighbors.size(); j++)
		{
			int w = neighbors[j].get_weight();
			int num = neighbors[j].get_num();
			int current_distance = vect[num].get_distance();
			if (d + w < current_distance)
			{
				updated = true;
				vect[num].set_distance(d + w);
				vect[num].set_prev(i);
			}
		}

	}
	if (updated)
		return "error";


	int current_vertix = to;
	int distance = vect[current_vertix].get_distance();
	if (distance == 1000000)
		return "-1";
	int prev = to;
	stack<int> path;
	path.push(to);
	do
	{
		prev = vect[current_vertix].get_prev();
		path.push(prev);
		current_vertix = prev;


	} while (prev != from);

	stringstream ss;
	while (!path.empty())
	{
		int x = path.top();
		ss << x;

		if (path.size() > 1)
		{
			ss << "->";

		}

		path.pop();

	}
	string str = ss.str();


	return str;

}


bool Algorithms::dfs(int node, int color, vector<int>& colors, vector<vector<int>>& gr)
{
	colors[node] = color;

	for (auto i : gr[node])
	{

		if (colors[i] == color)
			return false;
		if (colors[i] == 0 && !dfs(i, -color, colors, gr))
			return false;


	}
	return true;

}

string Algorithms::isBipartite(Graph& g)
{
	vector<vector<int>> gr;
	//vector<bool> vis(g.get_num_of_vertex(),false);

	fill_neighbers(g, gr);

	vector<int> colors(g.get_num_of_vertex(), 0);
	bool bipartite = true;
	for (int i = 0; i < g.get_num_of_vertex(); i++)
		if (colors[i] == 0)
			if (!dfs(i, 1, colors, gr/*, vis*/))
			{
				bipartite = false;
				break;
			}
	if (bipartite == true)
	{
		stringstream ss;
		ss << "The graph is bipartite: A={";
		vector<int> va, vb;
		for (int i = 0; i < colors.size(); i++)
			if (colors[i] == 1)
				va.push_back(i);
			else
				vb.push_back(i);
		for (int i = 0; i < va.size() - 1; i++)
			ss << va[i] << ", ";
		ss << va[va.size() - 1] << "}, B={";
		for (int i = 0; i < vb.size() - 1; i++)
			ss << vb[i] << ", ";
		ss << vb[vb.size() - 1] << "}";
		string s = ss.str();
		return s;




	}


	return "0";

}
// Should print: "The graph is bipartite: A={0, 2}, B={1}."