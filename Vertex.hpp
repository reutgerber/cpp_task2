//322516840
//reutgerber@gail.com
//task2
#include <vector>

using namespace std;

class Neighbor
{
	int num;
	int weight;
public:
	Neighbor(int num, int weight)
	{
		this->num = num;
		this->weight = weight;
	}
	int get_weight() { return weight; }
	int get_num() { return num; }

};

class Vertex
{
	int num;//number of edge starting from zero
	int distance;
	int prev;//previus Edge number in short path
	vector<Neighbor> neighbors;//holds the neighber and the weight for moving to it.
public:
	vector<Neighbor> get_neighbors()
	{
		return neighbors;
	}
	int get_distance() { return distance; }


	Vertex(int num)
	{
		this->num = num;
		distance = 1000000;//big number
		prev = -1;//starts with no previous 
	}
	void add_neighbor(int v, int weight)
	{
		neighbors.push_back(Neighbor(v, weight));
	}
	void set_prev(int prev)
	{
		this->prev = prev;
	}
	int get_prev() { return prev; }
	void set_distance(int distance)
	{
		this->distance = distance;
	}



};