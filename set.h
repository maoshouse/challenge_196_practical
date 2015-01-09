#ifndef SET_H
#define SET_H
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>
#include <sstream>

class Set {
public:
	Set(std::vector<int> input);
	~Set();
	std::vector<int> items() const;
	bool contains(int val);
	void print_items();
	Set operator+(const Set& s);
	Set operator*(const Set& s);	
	bool operator==(const Set&s);

private:
	std::vector<int> pItems;
	int size;
};


#endif
