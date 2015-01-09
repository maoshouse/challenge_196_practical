#include <iostream>
#include "set.h"
#include "set.cpp"

int main(int argc, char* argv[]) 
{
	// Set a = {1,2,3,4,5}
	// Set b = {3,4,5,6,7}
	// set c = a+b
	// set d = a*b
	
	std::vector<int> temp;
	for(int i = 0; i < 6; i++) {
		temp.push_back(i);
	}
	Set<int> a(temp);
	temp.erase(temp.begin(), temp.end());

	for(int i = 3; i < 8; i++) {
		temp.push_back(i);
	}
	Set<int> b(temp);
	temp.erase(temp.begin(), temp.end());

	Set<int> c = a+b;
	Set<int> d = a*b;
	
	std::cout << "{A}= ";
	a.print_items();
	std::cout << "{B}: ";
	b.print_items();
	std::cout << "{A+B}= ";
	c.print_items();
	std::cout << "{A*B}= ";
	d.print_items();
	std::cout << "{A} == {A} = " << std::boolalpha << (a==a) << "\n";
	std::cout << "{A} == {B} = " << std::boolalpha << (a==b) << "\n";


	return 0;
}
