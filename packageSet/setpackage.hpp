#pragma once
#include <string>
#include <iostream>
using namespace std;

class List {
public:
	string Str;
	List* list = this;
	List* Next = nullptr;
	int counter = 0;

	List();
	List(int flag);
	List(string str);

	inline void ToThePlaceElem(List* elem);

	void addElem();
	void addElem(string elem);

	void deleteFullList();
	void deleteElem(string elem);
	void deleteElem(List* elem);

	void getList();
	void getPower();

	bool checkElem(string elem);
};

class Set : public List {
public:
	string Name;
	Set* next = nullptr;

	Set();
	~Set();
	Set(string name);
	Set(string name, string str);

	inline void ToThePlaceSet(Set* set);

	Set* ToSet(string name);

	void getName();

	void addElemToSet(string name, string elem);
	void deleteElemFromSet(string name, string elem);

	void getPowerOfSet(string name);

	void getListOfSet(string name);

	void addSet();
	void addSet(string name);
	void addSet(string name, string str);

	void deleteSet(string name);

	bool isInSet(string name, string str);

	void getListOfSets();

	inline void Union(Set* A, Set* B, Set* C);
	inline void Difference(Set* A, Set* B, Set* C);
	inline void Intersection(Set* A, Set* B, Set* C);

	void UnionOfSets(string nameSetA, string nameSetB);
	void IntersectionOfSets(string nameSetA, string nameSetB);
	void DifferenceOfSets(string nanameSetAmeA, string nameSetB);
	void SymmetricDifferenceOfSets(string nameSetA, string nameSetB);
	bool IsInConclusionSet(string nameSetA, string nameSetB);
};