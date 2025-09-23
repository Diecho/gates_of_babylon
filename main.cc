#include <iostream>
#include <vector>
using namespace std;

class Gate {
	private: 
		int type;
		int index = -1;
		int indexSecond = -1;
	public:	
		Gate(int t, int idx = -1, int idxSecond = -1) : type(t), index(idx), indexSecond(idxSecond) {}

		int getType() const { return type; }
    	int getIndex() const { return index; }
    	int getIndexSecond() const { return indexSecond; }

};

int main(){
	vector<Gate> Gates;
	cout << "Welcome to the Gates of Babylon!" << endl;
	cout << "How many inputs does your logic block have? (1 to 10)" << endl;

	int gates;
	cin >> gates;
	bool done = false;
	while(!done){
		int gate;
		int index;
		int indexSecond;
		cout << "What sort of gate do you want to add?\n0 - NOT, 1 - AND, 2 - OR, 3 - NAND, 4 - NOR, 5 - XOR, 6 - DONE" << endl;
		cin >> gate;
		switch (gate){
			case 0: {
				cout << "Give the index for the input:" << endl;
				cin >> index;
				Gate g(gate, index);
				Gates.push_back(g);
				break;
 			}
			case 1: {
				cout << "Give the index for the first input:" << endl;
				cin >> index;
				cout << "Give the index for the second input:" << endl;
				cin >> indexSecond;
				Gate g(gate, index, indexSecond);
				Gates.push_back(g);
				break;
 			}
			case 2: {
				cout << "Give the index for the first input:" << endl;
				cin >> index;
				cout << "Give the index for the second input:" << endl;
				cin >> indexSecond;
				Gate g(gate, index, indexSecond);
				Gates.push_back(g);
				break;
 			}
			case 3: {
				cout << "Give the index for the first input:" << endl;
				cin >> index;
				cout << "Give the index for the second input:" << endl;
				cin >> indexSecond;
				Gate g(gate, index, indexSecond);
				Gates.push_back(g);
				break;
 			}
			case 4: {
				cout << "Give the index for the first input:" << endl;
				cin >> index;
				cout << "Give the index for the second input:" << endl;
				cin >> indexSecond;
				Gate g(gate, index, indexSecond);
				Gates.push_back(g);
				break;
 			}
			case 5: {
				cout << "Give the index for the first input:" << endl;
				cin >> index;
				cout << "Give the index for the second input:" << endl;
				cin >> indexSecond;
				Gate g(gate, index, indexSecond);
				Gates.push_back(g);
				break;
 			}
			case 6: {
				done = true;
				break;
 			}
			default: {
				cout << "INVALID INPUT" << endl;
				return 0;
				break;
 			}

		}
	}
	int choice;
	cout << "\n1) Print Circuit Block or 2) Print Truth Table" << endl;

	cin >> choice;

	if(choice == 1){
		
	}



	return 0;


}
