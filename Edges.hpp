//322516840
//reutgerber@gmail.com
//task2
#include <map>
#include "Graph.hpp"
using namespace std;
using namespace ariel;


class Edges
{
	map<pair<int, int>, bool> m;
	bool _is_directed = false;


public:
	Edges(Graph& g)
	{
		_is_directed = g.IsDirected();

	}


	void add(int v1, int v2)
	{
		pair<int, int> key1 = pair<int, int>(v1, v2);
		pair<int, int> key2 = pair<int, int>(v2, v1);

		m[key1] = true;
		m[key2] = true;
	}
	bool contains(int v1, int v2)
	{
		if (_is_directed)
			return false;
		pair<int, int> key1 = pair<int, int>(v1, v2);

		if (m.find(key1) != m.end() && m[key1] == true)
			return true;
		return false;
	}
	void remove(int v1, int v2)
	{
		pair<int, int> key1 = pair<int, int>(v1, v2);
		pair<int, int> key2 = pair<int, int>(v2, v1);
		m.erase(key1);
		m.erase(key2);
	}

};