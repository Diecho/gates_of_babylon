#include <iostream>
#include <vector>
using namespace std;

enum class gateType {
   NOT, AND, OR, NAND, NOR, XOR, INPUT
};

class Gate {
    gateType type;
};

int main(){
	vector<Gate> Gates;
	cout << "Welcome to the Gates of Babylon!" << endl;
	cout << "How many inputs does your logic block have? (1 to 10)" << endl;

	int gates;
	cin >> gates;

	while(true){
		int gate;
		int index;
		int index2;
		cout << "What sort of gate do you want to add?\n0 - NOT, 1 - AND, 2 - OR, 3 - NAND, 4 - NOR, 5 - XOR, 6 - DONE" << endl;
		cin >> gate;
		switch (gate){

			case 0:
				cout << "Give the index for the input: " << endl;
				cin >> index;
				break;
			case 1:
				cout << "Give the index for the input: " << endl;
				cin >> index;
				break;
			case 2:
				cout << "Give the index for the input: " << endl;
				cin >> index;
				break;
			case 3:
				cout << "Give the index for the input: " << endl;
				cin >> index;
				break;
			case 4:
				cout << "Give the index for the input: " << endl;
				cin >> index;
				break;
			case 5:
				cout << "Give the index for the input: " << endl;
				cin >> index;
				break;
			case 6:
				cout << "Give the index for the input: " << endl;
				cin >> index;
				break;
			default:
				cout << "INVALID INPUT" << endl;
				break;




		cout << "Give the index for the input: " << endl;
		cin >> index;
			break;
		}
	}
	
	return 0;


}
