//Jacob Hamilton, jake7054, 509, jacobhamilton@tamu.edu
#include "adjacencyList.h"

int main(){
	AdjacencyMat mat;
	ifstream file;
	file.open("../graph1.data");
	cout << "Graph 1: \n";
	file >> mat;
	cout << mat << "\n";
	mat.search();
	mat.printPath();
	cout << "\n\n\n";
	file.close();




	cout << "Graph 2: \n";
	AdjacencyMat mat2;
	file.open("../graph2.data");

	file >> mat2;
	cout << mat2;
	cout << "\n";
	mat2.search();
	mat2.printPath();
	cout << "\n\n\n";
	file.close();





	cout << "Graph 3: \n";
	AdjacencyMat mat3;
	file.open("../graph3.data");

	file >> mat3;
	cout << mat3;
	cout << "\n";
	mat3.search();
	mat3.printPath();
	cout << "\n\n\n";
	file.close();




	cout << "Graph 4: \n";
	AdjacencyMat mat4;
	file.open("../graph4.data");

	file >> mat4;
	cout << mat4;
	cout << "\n";
	mat4.search();
	mat4.printPath();
	cout << "\n\n\n";
	file.close();




	cout << "Graph 5: \n";
	AdjacencyMat mat5;
	file.open("../graph5.data");

	file >> mat5;
	cout << mat5;
	cout << "\n";
	mat5.search();
	mat5.printPath();
	cout << "\n\n\n";
	file.close();



	cout << "Graph 6: \n";
	AdjacencyMat mat6;
	file.open("../graph6.data");

	file >> mat6;
	cout << mat6;
	cout << "\n";
	mat6.search();
	mat6.printPath();
	file.close();
	
}