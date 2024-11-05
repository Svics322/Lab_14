#include<Windows.h>

#include"Graph.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filePath;
	cout << "Введіть шлях з назвою файлу графа: ";
	getline(cin, filePath);

	Graph graph(0);

	if (!graph.readGraphFromFile(filePath)) {
		cerr << "Помилка при зчитуванні графа з файлу." << endl;
		return 1;
	}

	graph.printAdjacencyMatrix();

	graph.isIrreflexive() ? (
		cout << "Граф є іррефлексивним." << endl
		) : (
			cout << "Граф не є іррефлексивним." << endl
			);
	graph.isAssymetric() ? (
		cout << "Граф є асиметричним." << endl
		) : (
			cout << "Граф не є асиметричним." << endl
			);

	return 0;
}