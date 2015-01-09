#include "set.h"

template<class T>
Set<T>::Set(std::vector<T> input)
{	
	for(typename std::vector<T>::iterator it = input.begin(); it != input.end(); ++it) {
		if(!contains(*it))
			pItems.push_back(*it);
	}

	size = input.size();
}


template<class T>
Set<T>::~Set()
{
	/* ... */
}

template<class T>
std::vector<T> Set<T>::items() const
{
	return pItems;
}

template<class T>
bool Set<T>::contains(int val)
{
	bool exists = false;
		for(typename std::vector<T>::iterator it = pItems.begin(); it != pItems.end(); ++it) {
			if(val == *it) {
				return true;
			}
		}
	return false;
}

template<class T>
Set<T> Set<T>::operator+(const Set& s)
{
	std::vector<T> unionSet = this->pItems;
	std::vector<T> sSet = s.items();
	for(typename std::vector<T>::iterator it = sSet.begin(); it != sSet.end(); ++it) {
		if(!this->contains(*it))
			unionSet.push_back(*it);
	}

	return Set(unionSet);
}

template<class T>
Set<T> Set<T>::operator*(const Set& s)
{
	std::vector<T> intersectionSet;
	std::vector<T> sSet = s.items();
	for(typename std::vector<T>::iterator it = sSet.begin(); it != sSet.end(); ++it) {
		if(this->contains(*it))
			intersectionSet.push_back(*it);
	}
	return Set(intersectionSet);
}

template<class T>
bool Set<T>::operator==(const Set& s)
{

	std::vector<T> sSet = s.items();
	for(typename std::vector<T>::iterator it = sSet.begin(); it != sSet.end(); ++it) {
		if(!this->contains(*it))
			return false;
	}
	return true;
}

template<class T>
void Set<T>::print_items()
{
	std::string out = "";
	std::stringstream s;
	s << "{";
	for(typename std::vector<int>::iterator it = pItems.begin(); it != pItems.end(); ++it) {
		s << *it;
		if(it+1 != pItems.end())
			s << ",";
	}
	s << "}";	
	std::cout << s.str() << "\n";
}
