//Jacob Hamilton, jake7054, 509, jacobhamilton@tamu.edu

#include "adjacencyList.h"

void AdjacencyMat::insert(int num1, int num2){
	bool isThere1 = false;
	bool isThere2 = false;
	for(int i = 0; i < matrix.size(); i++){
		if(matrix[i].front() == num1){
			isThere1 = true;
			matrix[i].push_back(num2);
		}
		if(matrix[i].front() == num2){
			isThere2 = true;
			matrix[i].push_back(num1);
		}
		if(isThere1 && isThere2)
			break;
	}
	if(!isThere1){
		list<int> lis;
		lis.push_back(num1);
		lis.push_back(num2);
		bool end;
		int i = 0;
		for(i; i <  matrix.size() && matrix[i].front() < num1; i++){}
		matrix.insert(matrix.begin() + i, lis);
	}
	if(!isThere2){
		list<int> lis;
		lis.push_back(num2);
		lis.push_back(num1);
		bool end;
		int i = 0;
		for(i; i <  matrix.size() && matrix[i].front() < num2; i++){}
		matrix.insert(matrix.begin() + i, lis);
		

	}

}

bool AdjacencyMat::isEmpty(list<int> u){
	for(list<int> i : matrix){
		if(i.size() > 1)
			return false;
	}
	return true;
	
}

void AdjacencyMat::search(){
	for(list<int> u : matrix)
		if(searchHelp(u)){
			cout << "Has a path\n";
			return;
		}
	cout << "Does not have a path\n";
}

bool AdjacencyMat::searchHelp(list<int> u){
	bool check;
	//cout << "\n" << u.front() << "\n" << *this << endl;
	path.push(u.front());
	if(isEmpty(u)){
		return true;
	}
	else{
		for(auto i = ++(u.begin()); i != u.end(); i++){
			vector<int> edge = {u.front(), *i};
			matrix[u.front() -1].remove(*i); //deletes u, i
			matrix[*i -1].remove(u.front()); // deletes i, u
			check = searchHelp(matrix[(*i) - 1]);
			if(check){
				return true;
			}
			else{
				matrix[edge[0]-1].push_back(edge[1]);  //undo deleting: restore e by adding to G;
				matrix[edge[1] -1].push_back(edge[0]);
			}
		}
		path.pop();
		return false;
	}
}


void AdjacencyMat::printPath(){
	if(path.empty())
		return;
	vector<int> vec;
	while(!path.empty()){
		vec.push_back(path.top());
		path.pop();
	}

	cout << "Starting vertex: " << vec[vec.size()-1] << endl;
	for(int i = vec.size() -1; i > 0; i--){
		cout << vec[i] << "->";
	}
	cout << vec[0] << endl;
}


ostream& operator<<(ostream& out, AdjacencyMat& mat){
	vector<list<int>> matrix = mat.get();
	list<int> temp;
	for(list<int> lis : matrix){
		for(int i : lis){
			if(i != lis.back())
				out << i << "->";
			else
				out << i;
		}
		out << "\n";
		
	}
	return out;
}
istream& operator>>(istream& in, AdjacencyMat& mat){
	int n1;
	int n2;
  	in >> n1;
  	in >> n2;
  	in >> n1;
  	in >> n2;
  	while(in.good()){
  		mat.insert(n1,n2);
  		in >> n1;
  		in >> n2;
  	}
	return in;
}