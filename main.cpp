#include <../../setpackage.hpp>

void inline HelpTOSET() {
	cout << "To start working with one set enter 'TOSET' <setname>" << endl;
	cout << "after 'TOSET' you can:" << endl;
	cout << "1.add new elem to set with 'add' <name>" << endl;
	cout << "2.delete elem from set with 'del' <name>" << endl;
	cout << "3.check elem to conclusion in set with 'isin' <name>" << endl;
	cout << "4.get power of set with 'power'" << endl;
	cout << "4.get list of set with 'list'" << endl << endl;
	cout << "If you want to end working with this set enter 'OUTSET'" << endl << endl;
}

void inline HelpTOOPS() {
	cout << "If you want to start using operations with sets enter 'TOOPS'" << endl;
	cout << "after 'TOOPS' you can:" << endl;
	cout << "1.to get union of two sets enter: 'UNION' <setname1> <setname2>" << endl;
	cout << "2.to get intersection of two sets enter: 'ISECT' <setname1> <setname2>" << endl;
	cout << "3.to get difference of two sets enter: 'DIFF' <setname1> <setname2>" << endl;
	cout << "4.to get symmetric difference of two sets enter: 'SYMDIF' <setname1> <setname2>" << endl;
	cout << "after this 'TOOPS' operations will created new set with name like setname1UNIONsetname2" << endl;
	cout << "5.to check is in conclusion in set any other set enter: ISIN <setname> <checkingsetname>" << endl << endl;
	cout << "If you want to end working with this sets operations enter 'OUTOPS'" << endl;
}

void inline Help() {
	HelpTOSET();
	HelpTOOPS();

	cout << "to get list of sets enter: 'GETSETS'" << endl;
	cout << "to add new set enter: 'ADDSET' <name>" << endl;
	cout << "to delete set enter: 'DELSET' <name>" << endl << endl;
	cout << "to get help enter: 'HELP'" << endl;	
	cout << "to get help about 'TOOPS' with sets enter: 'HELPOPS'" << endl;
	cout << "to get help about 'TOSET' enter: 'HELPSET'" << endl;
	cout << "to end working enter: 'END'" << endl << endl;
}

void UseInterface() {
	Set* SetWork = nullptr;
	string operand1, operand2, operand3;
	string name, elem;
	string help;
	cout << "To start working, enter 'BEGIN'" << endl;
	while (operand1 != "BEGIN") {
		cout << "-";
		cin >> operand1;
		if(operand1 == "END") {
			return;
		}
	}
	Help();
	while (operand1 != "END") {
		cout << "-";
		cin >> operand1;
		if (operand1 == "TOSET") {
			cin >> operand2;
			if (SetWork == nullptr) {
				cout << "There is no set with " << operand2 << " name" << endl;
			}
			else{
			Set* newSet = SetWork->ToSet(operand2);
			if (newSet == nullptr) {
				cout << "There is no set with " << operand2 << " name" << endl;
			}
			else
				while (operand1 != "END" || operand1 != "OUTSET") {
					cout << "-";
					cin >> operand1;
					if (operand1 == "list") {
						newSet->getList();
					}
					else if (operand1 == "power") {
						newSet->getPower();
					}
					else if (operand1 == "add") {
						cin >> operand2;
						newSet->addElem(operand2);
					}
					else if (operand1 == "del") {
						cin >> operand2;
						newSet->deleteElem(operand2);
					}
					else if (operand1 == "isin") {
						cin >> operand2;
						newSet->checkElem(operand2);
					}
					else if (operand1 == "OUTSET") {
						break;
					}
					else if (operand1 == "END") {
						return;
					}
					else {
						cout << "Wrong operand" << endl;
					}
				}
			}
		}
		else if (operand1 == "GETSETS") {
				SetWork->getListOfSets();
		}
		else if (operand1 == "ADDSET") {
			cin >> operand2;
			if (SetWork == nullptr) {
				SetWork = new Set(operand2);
			}
			else {
				SetWork->addSet(operand2);
			}
		}
		else if (operand1 == "HELP") {
			Help();
		}
		else if (operand1 == "HELPOPS") {
			HelpTOOPS();
		}
		else if (operand1 == "HELPSET") {
			HelpTOSET();
		}
		else if (operand1 == "TOOPS") {
			while (operand1 != "END" || operand1 != "OUTOPS") {
				cout << "-";
				cin >> operand1;
				if (operand1 == "UNION") {
					cin >> operand2 >> operand3;
					SetWork->UnionOfSets(operand2, operand3);
				}
				else if (operand1 == "DIFF") {
					cin >> operand2 >> operand3;
					SetWork->DifferenceOfSets(operand2, operand3);
				}
				else if (operand1 == "ISECT") {
					cin >> operand2 >> operand3;
					SetWork->IntersectionOfSets(operand2, operand3);
				}
				else if (operand1 == "SYMDIF") {
					cin >> operand2 >> operand3;
					SetWork->SymmetricDifferenceOfSets(operand2, operand3);
				}
				else if (operand1 == "ISIN") {
					cin >> operand2 >> operand3;
					SetWork->IsInConclusionSet(operand2, operand3);
				}
				else if (operand1 == "OUTOPS") {
					break;
				}
				else if (operand1 == "END") {
					return;
				}
				else {
					cout << "Wrong operand" << endl;
				}
			}
		}
		else {
			if(operand1 != "END")
			cout << "Wrong operand" << endl;
		}
	}
}

int main() {
	UseInterface();
}