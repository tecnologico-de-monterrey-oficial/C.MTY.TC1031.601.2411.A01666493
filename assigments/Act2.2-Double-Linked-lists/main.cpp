#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& newData, Node* newPrev = nullptr, Node* newNext = nullptr)
            : data(newData), prev(newPrev), next(newNext) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void addFirst(const T& data) {
        Node* newNode = new Node(data, nullptr, head);
        if (!isEmpty())
            head->prev = newNode;
        head = newNode;
        if (isEmpty())
            tail = newNode;
        size++;
    }

    void addLast(const T& data) {
        Node* newNode = new Node(data, tail);
        if (!isEmpty())
            tail->next = newNode;
        tail = newNode;
        if (isEmpty())
            head = newNode;
        size++;
    }

    void insert(int index, const T& data) {
        if (index < 0 || index > size)
            throw std::out_of_range("Index out of range");

        if (index == 0) {
            addFirst(data);
            return;
        }

        if (index == size) {
            addLast(data);
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; ++i)
            current = current->next;

        Node* newNode = new Node(data, current, current->next);
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }

    bool deleteData(const T& data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current == head)
                    head = current->next;
                else
                    current->prev->next = current->next;

                if (current == tail)
                    tail = current->prev;
                else
                    current->next->prev = current->prev;

                delete current;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool deleteAt(int index) {
        if (index < 0 || index >= size)
            return false;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            size--;
            return true;
        }

        if (index == size - 1) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail != nullptr)
                tail->next = nullptr;
            delete temp;
            size--;
            return true;
        }

        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
        return true;
    }

    T getData(int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");

        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return current->data;
    }

    void updateData(const T& oldData, const T& newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return;
            }
            current = current->next;
        }
        throw std::out_of_range("Data not found");
    }

    void updateAt(int index, const T& newData) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");

        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        current->data = newData;
    }

    int findData(const T& data) const {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == data)
                return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    T& operator[](int index) {
        return getData(index);
    }

    const T& operator[](int index) const {
        return getData(index);
    }

    void clear() {
        while (!isEmpty())
            deleteAt(0);
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


int getRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    DoublyLinkedList<int> myList;

    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Create list" << std::endl;
    std::cout << "2. Add element at the beginning" << std::endl;
    std::cout << "3. Add element at the end" << std::endl;
    std::cout << "4. Insert element at index" << std::endl;
    std::cout << "5. Delete element by value" << std::endl;
    std::cout << "6. Delete element at index" << std::endl;
    std::cout << "7. Get data at index" << std::endl;
    std::cout << "8. Update data by value" << std::endl;
    std::cout << "9. Update data at index" << std::endl;
    std::cout << "10. Find data" << std::endl;
    std::cout << "11. Clear list" << std::endl;
    std::cout << "12. Display list" << std::endl;
    std::cout << "13. Exit" << std::endl;

    int choice;
    do {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int option;
                std::cout << "Choose how to create the list:" << std::endl;
                std::cout << "1. Random data" << std::endl;
                std::cout << "2. User input" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> option;

                if (option == 1) {
                    int n;
                    std::cout << "Enter the number of elements: ";
                    std::cin >> n;
                    for (int i = 0; i < n; ++i)
                        myList.addLast(getRandomInt(1, 100));
                } else if (option == 2) {
                    int data;
                    std::cout << "Enter elements (enter -1 to stop): ";
                    while (true) {
                        std::cin >> data;
                        if (data == -1)
                            break;
                        myList.addLast(data);
                    }
                } else {
                    std::cout << "Invalid option!" << std::endl;
                }
                break;
            }
            case 2: {
                int data;
                std::cout << "Enter element to add at the beginning: ";
                std::cin >> data;
                myList.addFirst(data);
                break;
            }
            case 3: {
                int data;
                std::cout << "Enter element to add at the end: ";
                std::cin >> data;
                myList.addLast(data);
                break;
            }
            case 4: {
                int index, data;
                std::cout << "Enter index to insert: ";
                std::cin >> index;
                std::cout << "Enter data to insert: ";
                std::cin >> data;
                myList.insert(index, data);
                break;
            }
            case 5: {
                int data;
                std::cout << "Enter element to delete: ";
                std::cin >> data;
                if (myList.deleteData(data))
                    std::cout << "Element deleted successfully" << std::endl;
                else
                    std::cout << "Element not found" << std::endl;
                break;
            }
            case 6: {
                int index;
                std::cout << "Enter index to delete: ";
                std::cin >> index;
                if (myList.deleteAt(index))
                    std::cout << "Element at index " << index << " deleted successfully" << std::endl;
                else
                    std::cout << "Invalid index" << std::endl;
                break;
            }
            case 7: {
                int index;
                std::cout << "Enter index to get data: ";
                std::cin >> index;
                try {
                    std::cout << "Data at index " << index << ": " << myList.getData(index) << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 8: {
                int oldData, newData;
                std::cout << "Enter data to update: ";
                std::cin >> oldData;
                std::cout << "Enter new data: ";
                std::cin >> newData;
                try {
                    myList.updateData(oldData, newData);
                    std::cout << "Data updated successfully" << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 9: {
                int index, newData;
                std::cout << "Enter index to update: ";
                std::cin >> index;
                std::cout << "Enter new data: ";
                std::cin >> newData;
                try {
                    myList.updateAt(index, newData);
                    std::cout << "Data updated successfully" << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 10: {
                int data;
                std::cout << "Enter data to find: ";
                std::cin >> data;
                int index = myList.findData(data);
                if (index != -1)
                    std::cout << "Data found at index " << index << std::endl;
                else
                    std::cout << "Data not found" << std::endl;
                break;
            }
            case 11: {
                myList.clear();
                std::cout << "List cleared" << std::endl;
                break;
            }
            case 12: {
                std::cout << "List: ";
                myList.display();
                break;
            }
            case 13:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 13);

    return 0;
}
