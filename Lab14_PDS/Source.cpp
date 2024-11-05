#include<Windows.h>

#include"Graph.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filePath;
	cout << "������ ���� � ������ ����� �����: ";
	getline(cin, filePath);

	Graph graph(0);

	if (!graph.readGraphFromFile(filePath)) {
		cerr << "������� ��� ��������� ����� � �����." << endl;
		return 1;
	}

	graph.printAdjacencyMatrix();

	graph.isIrreflexive() ? (
		cout << "���� � ��������������." << endl
		) : (
			cout << "���� �� � ��������������." << endl
			);
	graph.isAssymetric() ? (
		cout << "���� � ������������." << endl
		) : (
			cout << "���� �� � ������������." << endl
			);

	return 0;
}