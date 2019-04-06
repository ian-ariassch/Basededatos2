#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void binarySearch(string &key){
	ifstream file("new.txt");
	string line;
	int cont = 0;
	if (file.is_open()){
		while (getline(file,line)){
			cont ++;
		}
		int l = 0;
		int u = cont - 1;
		while (u >= l){
			int middle = floor((l+u)/2);
			file.seekg(middle);
			if (re.key < key){
				u = m - 1;
			} 
			else if (){
			}
			else{
			
			}
		}
		file.close();
		
	}
	//cout << cont << endl;
}

int main(){
    string key;
    cin >> key;
    binarySearch();
    return 0;
}
