#include "set.h"
Set::Set(std::vector<int> input)
{	
	for(std::vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
		if(!contains(*it))
			pItems.push_back(*it);
	}

	size = input.size();
}

Set::~Set()
{
	/* ... */
}

std::vector<int> Set::items() const
{
	return pItems;
}

bool Set::contains(int val)
{
	bool exists = false;
		for(std::vector<int>::iterator it = pItems.begin(); it != pItems.end(); ++it) {
			if(val == *it) {
				return true;
			}
		}
	return false;
}

Set Set::operator+(const Set& s)
{
	std::vector<int> unionSet = this->pItems;
	std::vector<int> sSet = s.items();
	for(std::vector<int>::iterator it = sSet.begin(); it != sSet.end(); ++it) {
		if(!this->contains(*it))
			unionSet.push_back(*it);
	}

	return Set(unionSet);
}

Set Set::operator*(const Set& s)
{
	std::vector<int> intersectionSet;
	std::vector<int> sSet = s.items();
	for(std::vector<int>::iterator it = sSet.begin(); it != sSet.end(); ++it) {
		if(this->contains(*it))
			intersectionSet.push_back(*it);
	}
	return Set(intersectionSet);
}

bool Set::operator==(const Set& s)
{

	std::vector<int> sSet = s.items();
	for(std::vector<int>::iterator it = sSet.begin(); it != sSet.end(); ++it) {
		if(!this->contains(*it))
			return false;
	}
	return true;
}

void Set::print_items()
{
	std::string out = "";
	std::stringstream s;
	s << "{";
	for(std::vector<int>::iterator it = pItems.begin(); it != pItems.end(); ++it) {
		s << *it;
		if(it+1 != pItems.end())
			s << ",";
	}
	s << "}";	
	std::cout << s.str() << "\n";
}
