#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack underflow");
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }
};

int main() {
    Stack<int> stack;
    int choice, value;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Top\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                stack.push(value);
                std::cout << "Value " << value << " pushed onto the stack.\n";
                break;
            case 2:
                try {
                    stack.pop();
                    std::cout << "Top element popped from the stack.\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << '\n';
                }
                break;
            case 3:
                try {
                    std::cout << "Top element of the stack: " << stack.top() << '\n';
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << '\n';
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
