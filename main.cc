#include <iostream>

using namespace std;


int main(){

	cout << "Welcome to the Gates of Babylon!" << endl;
	cout << "How many inputs does your logic block have? (1 to 10)" << endl;

	int gates;
	cin >> gates;

	for(int i = 0; i < gates; i++){
		int gate;
		int index;
		cout << "What sort of gate do you want to add?\n0 - NOT, 1 - AND, 2 - OR, 3 - NAND, 4 - NOR, 5 - XOR, 6 - DONE" << endl;
		cin >> gate;
		cout << "Give the index for the input: " << endl;
		cin >> index;

	}
	
	return 0;


}
