#include <iostream>

template <typename ItemType>
class List {
private:
    static const int MAX_SIZE = 100;  // Maximum number of elements the list can hold
    ItemType elements[MAX_SIZE];      // Array to hold list elements
    int size;                         // Current number of elements in the list

public:
    // Constructor
    List() {
        size = 0;
    }

    // Check if the list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get the number of elements in the list
    int getLength() const {
        return size;
    }

    // Insert an item at a given index (1-based)
    bool insert(int index, const ItemType& newItem) {
        if (index < 1 || index > size + 1 || size >= MAX_SIZE) {
            return false;
        }

        // Shift elements to the right to make space for the new item
        for (int i = size; i >= index; --i) {
            elements[i] = elements[i - 1];
        }

        elements[index - 1] = newItem;  // Insert the new item at the specified index
        size++;                         // Increase size of the list
        return true;
    }

    // Remove an item at a given index (1-based)
    bool remove(int index) {
        if (index < 1 || index > size) {
            return false;
        }

        // Shift elements to the left to fill the space left by the removed item
        for (int i = index - 1; i < size - 1; ++i) {
            elements[i] = elements[i + 1];
        }

        size--;  // Decrease the size of the list
        return true;
    }

    // Retrieve item at given index (1-based)
    bool retrieve(int index, ItemType& dataItem) const {
        if (index < 1 || index > size) {
            return false;
        }

        dataItem = elements[index - 1];  // Retrieve the item at the specified index
        return true;
    }

    // Display all items in the list
    void display() const {
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    List<int> myList;

    // Inserting elements into the list
    myList.insert(1, 10);
    myList.insert(2, 20);
    myList.insert(3, 30);

    std::cout << "List contents: ";
    myList.display();  // Output: 10 20 30

    int item;
    if (myList.retrieve(2, item)) {
        std::cout << "Item at index 2: " << item << std::endl;  // Output: 20
    }

    // Remove the item at index 1
    myList.remove(1);
    std::cout << "After removing index 1: ";
    myList.display();  // Output: 20 30

    return 0;
}
