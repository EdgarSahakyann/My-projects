#include <iostream>

template <typename T>
class Queue {

	struct Node {
		Node* next;
		T data;
		Node (T value) : data(value), next(nullptr) {}
	};

public:
	Queue() : first(nullptr), last(nullptr) {}

	~Queue() {
		while (first != nullptr) {
			pop();
		}
	}

	size_t size() {
		int count = 0;
		Node* current = first;
		while (current != nullptr) {
			current = current->next;
			count++;
		}
		return count;
	}

	bool empty() {
		return first == nullptr;
	}

	T front() {
		if (first == nullptr) {
			throw std::runtime_error("Your queue is empty!");
		}
		return first->data;
	}

	T back() {
		if (last == nullptr) {
			throw std::runtime_error("Your queue is empty!");
		}
		return last->data;
	}

	void push(T value) {
		Node* new_node = new Node(value);
		if (last != nullptr) {
			last->next = new_node;
			last = new_node;
		}
		else {
			first = last = new_node;
		}
	}

	void pop() {
		Node* current = first;
		if (first == nullptr) {
			throw std::runtime_error("Your queue is empty!");
		}
		else {
			first = first->next;
			if (first == nullptr) {
				last = nullptr;
			}
			delete current;
		}
	}


private:
	Node* first;
	Node* last;
};


int main() {
	try {
		Queue<int> q;

		q.push(1);
		q.push(2);
		q.push(3);

		std::cout << "Size after adding (3): " << q.size() << std::endl;

		std::cout << "First element: " << q.front() << std::endl;
		std::cout << "Last element: " << q.back() << std::endl;

		q.pop();
		q.pop();
		q.pop();

		std::cout << "Is empty or not: " << q.empty() << std::endl;

		std::cout << "Size after removing (0) " << q.size() << std::endl;
	}

	catch (const std::runtime_error& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;

}
