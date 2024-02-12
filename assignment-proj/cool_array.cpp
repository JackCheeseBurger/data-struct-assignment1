#include "cool_array.h"
#include <string>

template<typename T>
// Defualt constructor for the template class CoolArray using initilization list, initiliazes a new array of type T of size initSize(10), 
// then sets the current capacity to that size and sets the number of elements to zero
CoolArray<T>::CoolArray() : DynamicArray(new T[initSize]), numElements(0), current_capacity(initSize) { }

template<typename T>
void CoolArray<T>::updateSize()      // Updates the array to have double the size
{
    // Doubles current size
    current_capacity *= 2;
    // Creates new array of the updated current size
    T* NewDynamicArray = new T[current_capacity];
    // Updates new array to contain the old arrays data
    for (size_t i = 0; i < numElements; i++)     
        NewDynamicArray[i] = DynamicArray[i];
    // Delete the old array
    delete[] DynamicArray;
    // Update the pointer
    DynamicArray = NewDynamicArray;
};


template<typename T>
void CoolArray<T>::coolPushback(const T& value)
{
    for (int i = 0; i < 1000; i++) {
        if (numElements == current_capacity)        // Checks if the array is full and if true is calls updateSize()
            updateSize();
        // Adds item to the end the items with no space by updating the element at numElements
        DynamicArray[numElements] = value;
        // Increments Num Elements
        numElements++;
    }
};


template<typename T>
int CoolArray<T>::loadNumbersFromFile(std::ifstream& file)
{
    if (!file.is_open()) {      // Ensures file is valid
        std::cerr << "Error: Unable to open file." << std::endl;
        return EXIT_FAILURE;
    }
    int num;
    while (file >> num) {    // While loop runs while the file has numbers to input, assumes file contains only numbers seperated by a space.
        // calls coolPushback for all num in file
        coolPushback(num);
    }
    return EXIT_SUCCESS;
};


template<typename T>
std::string CoolArray<T>::modify(size_t index, const T& new_element)
{
    std::string retS;
    if (index < numElements) {
        retS = std::string("Modify Success: Old[") + std::to_string(index) + std::string("] = ") + std::to_string(DynamicArray[index]) +
            std::string(", New[") + std::to_string(index) + std::string("] = ") + std::to_string(new_element);
        DynamicArray[index] = new_element;
        return retS;
    }
    else {
        throw std::out_of_range("Index out of array range");
    }
};


template<typename T>
std::string CoolArray<T>::exists(const T& target)
{
    bool flag = false;
    std::string retS = "Target element found at indexes:"; // Return string that will include every matching index.
    for (size_t i = 0; i < numElements; i++) {
        if (DynamicArray[i] == target) {
            retS = retS + std::string(" ") + std::to_string(i) + std::string(",");   // Adds target to string.
            flag = true; // Marks flag to indicate a target was found.
        }
    }
    if (flag)       // If flag is true returns found indexes, else returns failure msg.
        return retS;
    else
        return "Target was not found in array.";
};


template<typename T>
void CoolArray<T>::remove(size_t index)
{
    if (index < numElements) {
        numElements--;
        for (size_t i = index; i < numElements; i++) {    // Iterates through numElements starting from the given index and shifts every element over one.
            DynamicArray[i] = DynamicArray[i + 1];
        }
    }
    else {
        throw std::out_of_range("Index out of array range.");    
    }
}

template<typename T>
void CoolArray<T>::printArray()
{
    for (size_t i = 0; i < numElements; i++) {
        std::cout << DynamicArray[i] << " ";
    }
    std::cout << std::endl << "Number of Items: " << numElements << std::endl;
    std::cout << "Size of Array: " << current_capacity << std::endl;
};