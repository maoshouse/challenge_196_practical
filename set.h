#ifndef SET_H
#define SET_H
#include <vector>
#include <typeinfo>
#include <iostream>
#include <sstream>

template <class T>
class Set {
public:
	Set(std::vector<T> input);
	~Set();
	std::vector<T> items() const;
	bool contains(int val);
	void print_items();
	Set operator+(const Set& s);
	Set operator*(const Set& s);	
	bool operator==(const Set&s);

private:
	std::vector<T> pItems;
	int size;
};


#endif
