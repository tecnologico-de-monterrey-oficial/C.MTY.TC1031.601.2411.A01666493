#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
private:
    ListNode<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void addFirst(const T& data) {
        ListNode<T>* newNode = new ListNode<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void addLast(const T& data) {
        ListNode<T>* newNode = new ListNode<T>(data);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAfter(int index, const T& data) {
        ListNode<T>* current = head;
        for (int i = 0; i < index && current; ++i) {
            current = current->next;
        }
        if (!current) {
            std::cout << "Índice fuera de rango." << std::endl;
            return;
        }
        ListNode<T>* newNode = new ListNode<T>(data);
        newNode->next = current->next;
        current->next = newNode;
    }

    void remove(const T& data) {
        ListNode<T>* current = head;
        ListNode<T>* prev = nullptr;
        while (current && current->data != data) {
            prev = current;
            current = current->next;
        }
        if (!current) {
            std::cout << "Elemento no encontrado." << std::endl;
            return;
        }
        if (!prev) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
    }

    void removeAt(int index) {
        if (index < 0) {
            std::cout << "Índice inválido." << std::endl;
            return;
        }
        if (index == 0) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ListNode<T>* current = head;
        ListNode<T>* prev = nullptr;
        for (int i = 0; current && i < index; ++i) {
            prev = current;
            current = current->next;
        }
        if (!current) {
            std::cout << "Índice fuera de rango." << std::endl;
            return;
        }
        prev->next = current->next;
        delete current;
    }

    T get(int index) {
        ListNode<T>* current = head;
        for (int i = 0; current && i < index; ++i) {
            current = current->next;
        }
        if (!current) {
            throw std::out_of_range("Índice fuera de rango.");
        }
        return current->data;
    }

    void update(const T& oldData, const T& newData) {
        ListNode<T>* current = head;
        while (current && current->data != oldData) {
            current = current->next;
        }
        if (!current) {
            std::cout << "Elemento no encontrado." << std::endl;
            return;
        }
        current->data = newData;
    }

    bool contains(const T& data) {
        ListNode<T>* current = head;
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int size() const {
        int count = 0;
        ListNode<T>* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while (head) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    T& operator[](int index) {
        ListNode<T>* current = head;
        for (int i = 0; current && i < index; ++i) {
            current = current->next;
        }
        if (!current) {
            throw std::out_of_range("Índice fuera de rango.");
        }
        return current->data;
    }

    const T& operator[](int index) const {
        ListNode<T>* current = head;
        for (int i = 0; current && i < index; ++i) {
            current = current->next;
        }
        if (!current) {
            throw std::out_of_range("Índice fuera de rango.");
        }
        return current->data;
    }

    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        ListNode<T>* current = other.head;
        while (current) {
            addLast(current->data);
            current = current->next;
        }
        return *this;
    }
};

#endif