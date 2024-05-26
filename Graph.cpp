//322516840
//reutgerber@gmail.com
//task2
#include "Graph.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

namespace ariel
{
	void Graph::CheckSymetric()
	{
		for (std::vector<int>::size_type i = 0; i < matrix.size(); i++)
		{
			for (std::vector<int>::size_type j = i + 1; j < matrix.size(); j++)
			{
				if (matrix[i][j] != matrix[j][i])
				{
					_symetric = false;
					return;
				}
			}
		}
		_symetric = true;
	}


	void Graph::loadGraph(vector<vector<int>> matrix)
	{
		if (matrix.size() != matrix[0].size())
			throw(std::invalid_argument("Invalid graph : The graph is not a square matrix.\n"));
		this->matrix = matrix;
		_veritx_num = matrix.size();
		_edges_num = 0;
		for (std::vector<int>::size_type i = 0; i < matrix.size(); i++)
		{
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); j++)
			{

				if (matrix[i][j] != 0)
					_edges_num++;

			}

		}
		CheckSymetric();

	}

	int Graph::weight(int x, int y)
	{
		return matrix[x][y];
	}


	bool Graph::connected(int x, int y)
	{
		if (matrix[x][y] != 0)
			return true;
		return false;
	}


	void Graph::printGraph()
	{
		_veritx_num = matrix.size();
		_edges_num = 0;
		for (std::vector<int>::size_type i = 0; i < matrix.size(); i++)
		{
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); j++)
			{
				printf("%5d", matrix[i][j]);

			}
			printf("\n");
		}
		printf("Graph with %d vertices and %d edges.\n", _veritx_num, _edges_num);

	}

	//plus operators

	Graph Graph::operator+(const Graph& gr1) const {

		if (matrix.size() != gr1.matrix.size() || matrix[0].size() != gr1.matrix[0].size()) {
			throw std::invalid_argument("Matrices must have the same dimensions for addition.");
		}
	
		std::vector<std::vector<int>> result(matrix.size(), std::vector<int>(matrix[0].size(), 0));

		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				result[i][j] = gr1.matrix[i][j] + matrix[i][j];
			}
		}

		Graph resultGraph;
		resultGraph.loadGraph(result);

		return resultGraph;
	}


	void Graph::operator+=(const int num){

		
		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				matrix[i][j] += num;
			}
		}

	}

	void Graph::operator+() const{
		return;
	}


	//minus operators

	Graph Graph::operator-(const Graph& gr1) const {

		if (matrix.size() != gr1.matrix.size() || matrix[0].size() != gr1.matrix[0].size()) {
			throw std::invalid_argument("Matrices must have the same dimensions for addition.");
		}

		std::vector<std::vector<int>> result(matrix.size(), std::vector<int>(matrix[0].size(), 0));

		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				result[i][j] = matrix[i][j] - gr1.matrix[i][j];
			}
		}

		Graph resultGraph;
		resultGraph.loadGraph(result);

		return resultGraph;
	}

	void Graph::operator-=(const int num) {


		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				matrix[i][j] -= num;
			}
		}

	}

	void Graph::operator-() {
		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				matrix[i][j] *= -1;
			}
		}
	}


	//print operator

	const vector<vector<int>>& Graph::getMatrix() const {
		return matrix;
	}

	ostream& operator<<(ostream& os, const Graph& graph) {
		const auto& matrix = graph.getMatrix();

		for (const auto& row : matrix) {
			os << "[";
			for (size_t i = 0; i < row.size(); ++i) {
				os << row[i];
				if (i != row.size() - 1) {
					os << ", ";
				}
			}
			os << "]" << endl;
		}
		os << endl;
		return os;
	}

	bool Graph::operator==(const Graph& other) const {
		// בדיקה אם המספר הצמתים שווה
		if (matrix.size() != other.matrix.size()) {
			return false;
		}

		// בדיקה אם כל הצלעות שוות
		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				if (matrix[i][j] != other.matrix[i][j]) {
					return false;
				}
			}
		}

		return true;
	}

	bool Graph::operator!=(const Graph& other) const {
		return !(*this == other);
	}

	bool Graph::operator<(const Graph& other) const {
		// בדיקה אם G1 מוכל ממש ב-G2
		if (matrix.size() <= other.matrix.size()) {
			bool isContained = true;
			for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
				for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
					if (matrix[i][j] != 0 && (i >= other.matrix.size() || j >= other.matrix[0].size() || other.matrix[i][j] == 0)) {
						isContained = false;
						break;
					}
				}
				if (!isContained) break;
			}
			if (isContained && matrix.size() < other.matrix.size()) {
				return true;
			}
		}

		// אם אף גרף לא מוכל ממש בשני, נבדוק את מספר הצלעות
		if (_edges_num != other._edges_num) {
			return _edges_num < other._edges_num;
		}

		// אם מספר הצלעות זהה, נשווה את סדר הגודל של המטריצות
		return matrix.size() < other.matrix.size();
	}

	bool Graph::operator>(const Graph& other) const {
		return !(*this < other) && !(*this == other);
	}

	bool Graph::operator<=(const Graph& other) const {
		return (*this < other) || (*this == other);
	}

	bool Graph::operator>=(const Graph& other) const {
		return (*this > other) || (*this == other);
	}


	// prefix increment:
	Graph& Graph::operator++() {
		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				++matrix[i][j];
			}
		}
		return *this;
	}

	// postfix increment:
	Graph Graph::operator++(int) {
		Graph temp = *this; 
		++(*this);
		return temp; 
	}

	// prefix increment:
	Graph& Graph::operator--() {
		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				--matrix[i][j];
			}
		}
		return *this;
	}

	// postfix increment:
	Graph Graph::operator--(int) {
		Graph temp = *this;
		--(*this);
		return temp;
	}

	Graph& Graph::operator*=(int scalar) {
		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				matrix[i][j] *= scalar;
			}
		}
		return *this;
	}

	Graph Graph::operator*(const Graph& other) const {
		if (matrix[0].size() != other.matrix.size()) {
			throw std::invalid_argument("Number of columns in the first matrix must equal number of rows in the second matrix for multiplication.");
		}

		std::vector<std::vector<int>> result(matrix.size(), std::vector<int>(other.matrix[0].size(), 0));

		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < other.matrix[0].size(); ++j) {
				for (std::vector<int>::size_type k = 0; k < matrix[0].size(); ++k) {
					result[i][j] += matrix[i][k] * other.matrix[k][j];
				}
			}
		}

		Graph resultGraph;
		resultGraph.loadGraph(result);
		return resultGraph;
	}

	Graph& Graph::operator/=(int divisor) {
		if (divisor <= 0) {
			throw std::invalid_argument("Divisor must be a positive integer");
		}
		for (std::vector<int>::size_type i = 0; i < matrix.size(); ++i) {
			for (std::vector<int>::size_type j = 0; j < matrix[0].size(); ++j) {
				matrix[i][j] /= divisor;
			}
		}
		return *this;
	}

}