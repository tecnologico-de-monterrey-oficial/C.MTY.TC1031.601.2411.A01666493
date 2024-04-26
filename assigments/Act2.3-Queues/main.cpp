#include <iostream>

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    Node* frontPtr;
    Node* rearPtr;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            frontPtr = rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Queue underflow: Cannot pop from an empty queue");
        } else {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
            if (frontPtr == nullptr) {
                rearPtr = nullptr;
            }
        }
    }

    T front() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty: Cannot retrieve front element");
        } else {
            return frontPtr->data;
        }
    }

    bool isEmpty() const {
        return frontPtr == nullptr;
    }
};

int main() {
    Queue<int> myQueue;
    int choice, item;

    do {
        std::cout << "\nQueue Menu\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Front\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter item to push: ";
                std::cin >> item;
                myQueue.push(item);
                std::cout << "Item pushed into the queue.\n";
                break;
            case 2:
                try {
                    std::cout << "Popped item: " << myQueue.front() << std::endl;
                    myQueue.pop();
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            case 3:
                try {
                    std::cout << "Front item: " << myQueue.front() << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
