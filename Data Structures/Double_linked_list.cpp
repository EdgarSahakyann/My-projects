#include <iostream>

template <typename T>
class double_linked_list {
private:
    struct Node {
        Node* next;
        Node* prev;
        T data;

        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;

public:
    double_linked_list() : head(nullptr) {}

    ~double_linked_list() {
        clear();
    }

    bool empty() const {
        return head == nullptr;
    }

    size_t size() const {
        Node* current = head;
        size_t count = 0;

        while (current != nullptr) {
            current = current->next;
            count++;
        }

        return count;
    }

    const Node* first() const {
        return head;
    }

    const Node* last() const {
        Node* current = head;
        while (current && current->next != nullptr) {
            current = current->next;
        }
        return current;
    }

    void clear() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
    }

    void insert(T data, size_t index) {
        if (index == 0) {
            push_front(data);
            return;
        }

        Node* new_node = new Node(data);
        Node* current = head;
        size_t count = 0;

        while (count < index - 1 && current != nullptr) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            std::cerr << "Out of range!" << std::endl;
            delete new_node;
            return;
        }

        new_node->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = new_node;
        }
        current->next = new_node;
        new_node->prev = current;
    }

    void remove(size_t index) {
        if (index >= size()) {
            std::cerr << "Out of range!" << std::endl;
            return;
        }

        Node* current = head;
        size_t count = 0;

        while (count < index && current != nullptr) {
            current = current->next;
            count++;
        }

        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            delete current;
        }
    }

    void push_back(T data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new_node;
        new_node->prev = current;
    }

    void push_front(T data) {
        Node* new_node = new Node(data);

        if (head == nullptr) {
            head = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void splice(double_linked_list& other) {
        if (other.head == nullptr) {
            return;
        }

        if (head == nullptr) {
            head = other.head;
        } else {
            Node* lastNode = last();
            lastNode->next = other.head;
            other.head->prev = lastNode;
        }

        other.head = nullptr;
    }

    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    double_linked_list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);

    std::cout << "List after pushing elements: ";
    list.print();

    list.insert(99, 2);
    std::cout << "List after inserting 99 at index 2: ";
    list.print();

    list.remove(1);
    std::cout << "List after removing element at index 1: ";
    list.print();

    list.reverse();
    std::cout << "List after reversing: ";
    list.print();

    double_linked_list<int> anotherList;
    anotherList.push_back(100);
    anotherList.push_back(200);
    anotherList.push_back(300);

    std::cout << "Another list: ";
    anotherList.print();

    list.splice(anotherList);
    std::cout << "List after splicing another list: ";
    list.print();

    std::cout << "Another list after splice (should be empty): ";
    anotherList.print();

    return 0;
}
