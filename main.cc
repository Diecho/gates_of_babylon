#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Gate {
	private: 
		int type; // 0 - NOT, 1 - AND, 2 - OR, 3 - NAND, 4 - NOR, 5 - XOR, 6 - INPUT
		int index = -1;
		int indexSecond = -1;
	public:	
		Gate(int t, int idx = -1, int idxSecond = -1) : type(t), index(idx), indexSecond(idxSecond) {}

		string numberToGate(){
			switch (this->type) {
				case 0: return "NOT";
				case 1: return "AND";
				case 2: return "OR";
				case 3: return "NAND";
				case 4: return "NOR";
				case 5: return "XOR";
				case 6: return "INPUT";
				default: return "UNKNOWN";
			}
		} 
		auto connected() {
			if(this->type == 6){
				return "N.C. and N.C.";
			}
			return "0";


		}
		int getType() const { return type; }
		int getIndex() const { return index; }
    	int getIndexSecond() const { return indexSecond; }

};

int main(){
	vector<Gate> Gates;
	cout << "Welcome to the Gates of Babylon!" << endl;
	cout << "How many inputs does your logic block have? (1 to 10)" << endl;

	int inputs;
	cin >> inputs;
	for(int i = 0; i < inputs; i++){
		Gate g(6, -1);
		Gates.push_back(g);
	}
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
			case 1: 
			case 2:
			case 3: 
			case 4: 
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
		for(size_t i = 0; i < Gates.size(); i++){

			cout << "Gate Type: " << Gates[i].numberToGate() << endl; 

			
			cout << "\tInput Connected to Index: " << endl; 
			cout << "\tOutput Connected to Index: " << Gates[i].connected() << endl; 
			cout << "\tValue: X" << endl << endl; 

		}
	}



	return 0;


}
