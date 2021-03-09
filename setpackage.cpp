#pragma once
#include <../../setpackage.hpp>

List::List() { cin >> Str; counter++; }
List::List(int flag) {}
List::List(string str) { Str = str; counter++; }

void List::getPower() { cout << counter << endl; }

inline void List::ToThePlaceElem(List* elem) {
	if (this->Str > elem->Str) {
		string swap = elem->Str;
		elem->Str = this->Str;
		this->Str = swap;
		elem->Next = this->Next;
		this->Next = elem;
	}
	else if (this->Str == elem->Str) {
		delete elem;
		counter--;
	}
	else if (this->Str < elem->Str) {
		List* current = this;
		while (current->Next != nullptr && current->Next->Str < elem->Str) {
			current = current->Next;
		}
		if (current->Next != nullptr) {
			if (current->Next->Str == elem->Str) {
				delete elem;
				counter--;
			}
			else if (current->Next->Str > elem->Str) {
				elem->Next = current->Next;
				current->Next = elem;
			}
		}
		else if (current->Next == nullptr) {
			current->Next = elem;
		}
	}
}

void List::addElem() {
	List* elem;
	elem = new List();
	this->counter++;
	ToThePlaceElem(elem);
}

void List::addElem(string elem) {
	List* addEl;
	addEl = new List(elem);
	this->counter++;
	ToThePlaceElem(addEl);
}

void List::deleteFullList() {
	List* current = this;
	List* currentNext = this->Next;
	do {
		delete current;
		current = currentNext;
		if (current == nullptr)
			break;
		currentNext = current->Next;
	} while (current->Next != nullptr);
}

void List::deleteElem(string elem) {
	List* search = this;
	if (search->Str == elem) {
		this->Str = search->Next->Str;
		List* save = this->Next;
		this->Next = save->Next;
		delete save;
		return;
	}
	while (search->Next != nullptr && search->Next->Str != elem)
		search = search->Next;
	if (search->Next != nullptr)
		if (search->Next->Str == elem) {
			List* save = search->Next->Next;
			delete search->Next;
			this->counter--;
			search->Next = save;
		}
		else if (search->Next == nullptr) {
			return;
		}
}

void List::deleteElem(List* elem) {
	List* search = this;
	if (search->Str == elem->Str) {
		this->Str = search->Next->Str;
		List* save = this->Next;
		this->Next = save->Next;
		delete save;
		return;
	}
	while (search->Next != nullptr && search->Next->Str != elem->Str)
		search = search->Next;
	if (search->Next != nullptr)
		if (search->Next->Str == elem->Str) {
			List* save = search->Next->Next;
			delete search->Next;
			this->counter--;
			search->Next = save;
		}
		else if (search->Next == nullptr) {
			return;
		}
}

void List::getList() {
	List* current = this;
	cout << current->Str << endl;
	while (current->Next != nullptr) {
		current = current->Next;
		cout << current->Str << endl;
	}
}

bool List::checkElem(string elem) {
	List* search = this;
	while (search->Next != nullptr && search->Str != elem)
		search = search->Next;
	if (search->Str == elem) {
		return true;
	}
	else
		return false;
}

Set::Set() { cin >> Name; }

Set::~Set() {}

Set::Set(string name) : List(1) { Name = name; }

Set::Set(string name, string str) : List(str) { Name = name; }

inline void Set::ToThePlaceSet(Set* set) {
	if (this->Name > set->Name) {
		List* ptrList = this->list;
		set->list = this->list;
		this->list = ptrList;

		int cntr = set->counter;
		set->counter = this->counter;
		this->counter = cntr;

		string saveName = this->Name;
		this->Name = set->Name;
		set->Name = saveName;

		Set* ptrSet = this->next;
		this->next = set;
		set->next = ptrSet;
	}
	else if (this->Name == set->Name) {
		delete set;
	}
	else if (this->Name < set->Name) {
		Set* current = this;
		while (current->next != nullptr && current->next->Name < set->Name) {
			current = current->next;
		}
		if (current->next != nullptr) {
			if (current->next->Name == set->Name) {
				delete set;
			}
			else if (current->next->Name > set->Name) {
				Set* ptrSet = current->next;
				current->next = set;
				set->next = ptrSet;
			}
		}
		else if (current->next == nullptr) {
			current->next = set;
		}
	}
}

Set* Set::ToSet(string name) {
	Set* current = this;
	if (current->Name == name)
		return current;
	while (current->Name != name && current->next != nullptr) {
		current = current->next;
	}
	if (current->next == nullptr && current->Name != name) {
		cout << "There's no such a Set with name " << name << endl;
		return nullptr;
	}
	else
		return current;
}

void Set::getName() { cout << Name << endl; }

void Set::addElemToSet(string name, string elem) { Set* add = ToSet(name); add->addElem(elem); }

void Set::deleteElemFromSet(string name, string elem) { Set* del = ToSet(name); del->deleteElem(elem); }

void Set::getPowerOfSet(string name) { Set* power = ToSet(name); power->getPower(); }

void Set::getListOfSet(string name) { Set* list = ToSet(name); list->getList(); }

void Set::addSet() {
	Set* newSet = nullptr;
	string name, str;
	cin >> name >> str;
	newSet = new Set(name, str);
	ToThePlaceSet(newSet);
}

void Set::addSet(string name) {
	Set* newSet = nullptr;
	newSet = new Set(name);
	ToThePlaceSet(newSet);
}

void Set::addSet(string name, string str) {
	Set* newSet = nullptr;
	newSet = new Set(name, str);
	ToThePlaceSet(newSet);
}

void Set::deleteSet(string name) {
	Set* search = this;
	if (search->Name == name && search->next == nullptr) {
		delete search;
		return;
	}
	else if (search->Name == name && search->next != nullptr) {
		Set* ForDelete = search->next;
		search->Str = ForDelete->Str;
		List* searchList = search->Next;
		List* ForDeleteList = ForDelete->Next;

		while (ForDeleteList != nullptr) {
			if (searchList != nullptr)
				searchList->Str = ForDeleteList->Str;

			if (ForDeleteList->Next != nullptr && searchList->Next == nullptr) {
				searchList->Next = new List(1);
			}
			if (searchList != nullptr)
				searchList = searchList->Next;
			ForDeleteList = ForDeleteList->Next;
		}
		while (searchList != nullptr) {
			ForDeleteList = searchList->Next;
			delete searchList;
			searchList = ForDeleteList;
		}
		search->counter = ForDelete->counter;
		search->Name = ForDelete->Name;
		search->next = ForDelete->next;
		delete ForDelete;
		return;
	}
	while (search->next != nullptr && search->next->Name != name)
		search = search->next;
	if (search->next != nullptr)
		if (search->next->Name == name) {
			Set* save = search->next->next;
			search->next->List::~List();
			delete search->next;
			search->next = save;
			return;
		}
		else if (search->next == nullptr) {
			return;
		}
}

bool Set::isInSet(string name, string str) {
	Set* check = ToSet(name);
	return check->checkElem(str);
}

void Set::getListOfSets() {
	if (this == nullptr) {
		cout << "There is no sets for now" << endl;
		return;
	}
	Set* current = this;
	int count = 1;
	cout << count << ".";
	current->getName();
	while (current->next != nullptr) {
		current = current->next;
		count++;
		cout << count << ".";
		current->getName();
	}
}

inline void Set::Union(Set* A, Set* B, Set* C) {
	List* listA = A->list;
	List* listB = B->list;
	while (listA != nullptr) {
		C->addElem(listA->Str);
		listA = listA->Next;
	}
	while (listB != nullptr) {
		C->addElem(listB->Str);
		listB = listB->Next;
	}
}

inline void Set::Difference(Set* A, Set* B, Set* C) {
	List* listA = A->list;
	List* listB = B->list;
	List* startListB = listB;
	while (listA != nullptr) {
		while (listB != nullptr) {
			if (listA->Str == listB->Str) {
				break;
			}
			listB = listB->Next;
		}
		if (listB == nullptr)
			C->addElem(listA->Str);
		listB = startListB;
		listA = listA->Next;
	}
}

inline void Set::Intersection(Set* A, Set* B, Set* C) {
	List* listA = A->list;
	List* listB = B->list;
	List* startListB = listB;
	while (listA != nullptr) {
		while (listB != nullptr) {
			if (listA->Str == listB->Str) {
				C->addElem(listA->Str);
			}
			listB = listB->Next;
		}
		listB = startListB;
		listA = listA->Next;
	}
}


void Set::UnionOfSets(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	Set* C = new Set(nameSetA + "UNION" + nameSetB);
	Union(A, B, C);
	ToThePlaceSet(C);
}

void Set::IntersectionOfSets(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	Set* C = new Set(nameSetA + "INTERSECT" + nameSetB);
	Intersection(A, B, C);
	ToThePlaceSet(C);
}


void Set::DifferenceOfSets(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	Set* C = new Set(nameSetA + "DIFFERENCE" + nameSetB);
	Difference(A, B, C);
	ToThePlaceSet(C);
}

void Set::SymmetricDifferenceOfSets(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	Set* C = new Set(nameSetA + "SYMDIFFERENCE" + nameSetB);
	Set* D = new Set("");
	Set* E = new Set("");
	Difference(A, B, D);
	Difference(B, A, E);
	Union(D, E, C);
	delete D;
	delete E;
	ToThePlaceSet(C);
}

bool Set::IsInConclusionSet(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	List* listA = A->list;
	while (listA != nullptr) {
		if (!(B->checkElem(listA->Str))) {
			return false;
		}
		listA = listA->Next;
	}
	return true;
}