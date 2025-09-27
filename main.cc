#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Gate {
	private: 
		int type; // 0 - NOT, 1 - AND, 2 - OR, 3 - NAND, 4 - NOR, 5 - XOR, 6 - INPUT
		int index = -1;
		int indexSecond = -1;
		int connectedTo = -1;
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
		string connectedInput() {
			if(this->type == 6){
				return "N.C. and N.C.";
			}
			else if(this->indexSecond < 0){
				return to_string(this->index);
			}else {
				return to_string(this->index) + " and " + to_string(this->indexSecond);
			}
			return "0";
		}
		string connectedSecond(int index, vector<Gate> Gates, int inputs) { // jun or matthew do this
			// FIX ME
			int output = 0; 

		/*	if(index < inputs){
				if(Gates[index + inputs].getType() == 0){
					
				}
				else{
					output = index + inputs;
				}
			}*/
			if(this->connectedTo == -1){
				return "OUTPUT PIN";
			}
			return to_string(this->connectedTo);
		}			
		int getType() const { return type; }
		int getIndex() const { return index; }
    	int getIndexSecond() const { return indexSecond; }
    	int getConnected() const { return connectedTo; }
    	void setConnectedTo(int i) { connectedTo = i; }
};

int main(){
	vector<Gate> Gates;
	cout << "Welcome to the Gates of Babylon!" << endl;
	cout << "How many inputs does your logic block have? (1 to 10)" << endl;

	int inputs;
	cin >> inputs;
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
	// Gates.insert(Gates.begin(), );
	int j = 0;
	int total = inputs + Gates.size();	
	for(int  i = Gates.size() - 1; i >= 0; i--){
	//for(int i = 0; i < inputs; i++){
		if(i == (Gates.size() - 1)){
			//cout << "activated" << endl;
			Gates[i].setConnectedTo(-1);	
			Gate g(6);
			g.setConnectedTo(total - 1);
			Gates.insert(Gates.begin(), g);
		}
		else if(Gates[i].getType() == 0){
		
		}else {

			//cout << "SECONDactivated" << endl;
			Gates[i + j].setConnectedTo(total - j);	
			Gate g(6);
			g.setConnectedTo(total - j - 1);
			Gates.insert(Gates.begin(), g);
			if(i == 0){
				Gates.insert(Gates.begin(), g);
			}
		}
		
		j++;	
	}

	int choice;
	cout << "\n1) Print Circuit Block or 2) Print Truth Table" << endl;

	cin >> choice;

	if(choice == 1){
		for(size_t i = 0; i < Gates.size(); i++){

			cout << "Gate Type: " << Gates[i].numberToGate() << endl; 
			cout << "\tInput Connected to Index: " << Gates[i].connectedInput() << endl; 
			cout << "\tOutput Connected to Index: " << Gates[i].connectedSecond(i, Gates, inputs) << endl; 
			cout << "\tValue: X" << endl << endl; 

		}
	}


	return 0;


}
