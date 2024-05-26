//322516840
//reutgerber@gmail.com
//task2
#ifndef _graphhpp_
#define _graphhpp_

#include <vector>
#include <iostream>

using namespace std;

namespace ariel
{
	class Graph
	{
	private:
		int _veritx_num;
		int _edges_num = 0;
		bool _symetric = false;
		vector<vector<int>> matrix;

	private:
		vector<bool> _vis1;
		void CheckSymetric();


	public:
		bool IsDirected()
		{
			return !_symetric;
		}
		bool connected(int x, int y);
		int weight(int x, int y);
		int get_num_of_vertex() {
			return _veritx_num;
		}

		void loadGraph(vector<vector<int>> matrix);
		void printGraph();
		friend ostream& operator<<(ostream& output, const Graph& graph);
		const vector<vector<int>>& getMatrix() const;
		Graph operator+(const Graph& other) const;
		void operator+=(const int num);
		void operator+() const;
		Graph operator-(const Graph& other) const;
		void operator-=(const int num);
		void operator-();
		bool operator==(const Graph& other) const;
		bool operator!=(const Graph& other) const;
		bool operator<(const Graph& other) const;
		bool operator>(const Graph& other) const;
		bool operator<=(const Graph& other) const;
		bool operator>=(const Graph& other) const;
		Graph& operator++();
		Graph operator++(int);
		Graph& operator--();
		Graph operator--(int);
		Graph& operator*=(int scalar);
		Graph operator*(const Graph& other) const;
		Graph& operator/=(int divisor);

	};
}
#endif