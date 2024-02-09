#ifndef cool_array
#define cool_array
#include <iostream>
#include <fstream>
#include <string>

template<typename T> class CoolArray {
protected:
	//Elements of the CoolArray
	static const size_t initSize = 10; 
	size_t numElements;
	size_t current_capacity;

	T* DynamicArray;

	// Private Member Functions
	void updateSize();
public:
	// Constructor
	CoolArray();
	// Public Member Functions
	int loadNumbersFromFile(std::ifstream& file);
	void coolPushback(const T& value);
	std::string modify(size_t index, const T& new_element);
	std::string exists(const T& target);
	void remove(size_t index);
	void printArray();
};
#endif