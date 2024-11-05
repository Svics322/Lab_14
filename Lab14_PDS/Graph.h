#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

class Graph {
public:
	int N, M;
	vector<vector<int>> adjList;

	Graph(int n);
	void addEdge(int from, int to);
	bool readGraphFromFile(const string& fileName);
	void printAdjacencyMatrix() const;
	bool isIrreflexive() const;
	bool isAssymetric() const;
};

Graph::Graph(int n) : M(0) {
	adjList.resize(n);
	N = n;
}

void Graph::addEdge(int from, int to){
	adjList[from].push_back(to);
}

bool Graph::readGraphFromFile(const string& fileName) {
	ifstream file(fileName);
	if (!file.is_open()) {
		cerr << "Не вдалося відкрити файл." << endl;
		return false;
	}

	int n, m;
	file >> n >> m;

	if (n <= 0 || m <= 0) {
		cerr << "Кількість вершин і ребер повинно бути більше нуля." << endl;
		return false;
	}

	adjList.resize(n);

	for (int i = 0; i < m; i++) {
		int start, end;
		if (!(file >> start >> end)) {
			cerr << "Помилка при зчитуванні ребра." << endl;
			return false;
		}
		if (start < 1 || start > n || end < 1 || end > n) {
			cerr << "Помилка: невірні індекси ребра: "
				<< start << " -> " << end << endl;
		}
		addEdge(start - 1, end - 1);
	}
	file.close();
	this->N = n;
	this->M = m;
	return true;
}

void Graph::printAdjacencyMatrix() const {
	vector<vector<int>> adjMatrix(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int neighbor : adjList[i])
			adjMatrix[i][neighbor] = 1;

	cout << "Матриця суміжності графа: " << endl;
	for (const auto& row : adjMatrix) {
		for (int val : row)
			cout << setw(5) << val << " ";
		cout << endl;
	}
}

bool Graph::isIrreflexive() const {
	for (int i = 0; i < N; i++)
		for (int j : adjList[i])
			if (i == j)
				return false;
	return true;
}

bool Graph::isAssymetric() const {
	for (int from = 0; from < N; from++)
		for (int to : adjList[from])
			for (int fromto : adjList[to])
				if (fromto == from)
					return false;
	return true;
}