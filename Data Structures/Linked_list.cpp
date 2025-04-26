#include <iostream>

template <typename T>
class single_forward_list {

private:
	struct Node {
		T data;
		Node* next;
		Node(T value) : data(std::mode(value)), next(nullptr) {}
	};
	Node* m_head;

public:
	single_forward_list() : m_head(nullptr) {}

	~single_forward_list() {
		clear();
	}

	bool empty() const {
		return m_head == nullptr;
	}

	size_t size() const{
		size_t sz = 0;
		const Node* p_node = m_head;

		while (p_node != nullptr) {
			p_node = p_node->next;
			sz++;
		}

		return sz;
	}

	const Node* first() const {
		return m_head;
	}

	const Node* last() const {
		Node* node = m_head;

		while (node !nullptr && node->next != nullptr) {
			node = node->next;
		}

		return node;
	}

	void clear() {
		Node* current = m_head;
		Node* temp = nullptr;

		while (current != nullptr) {
			temp = current;
			current = current->next;
			delete temp;
		}

		m_head = nullptr;
	}

	void insert(size_t index, T data) {
		Node* new_node = new Node(data);
		Node* current = m_head;
		int count = 0;

		if (index > size()) {
			std::cerr << "Out of range!" << std::endl;
			return;
		}
		else if (index == 0) {
			new_node->next = current;
			head = new_node;
			return;
		}

		while (count != index - 1 && current->next != nullptr) {
			current = current->next;
			count++;
		}

		if (current == nullptr) {
			std::cerr << "Out of range!" << std::endl;
			return;
		}

		new_node->next = current->next;
		current->next = new_node;
	}

	void remove(size_t index) {
		Node* current = m_head;
		int count = 0;

		if (index >= size()) {
			std::cerr << "Out of range!" << std::endl;
			return;
		}
		else if (index == 0) {
			m_head = current->next;
			delete current;
			return;
		}

		while (count != index - 1 && current != nullptr) {
			current = current->next;
			count++;
		}

		if (current == nullptr || current->next == nullptr) {
			std::cerr << "Out of range!" << std::endl;
			return;
		}

		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
	}


	void push_back(T data) {
		Node* new_node = new Node(data);
		Node* current = m_head;

		if (m_head == nullptr) {
			m_head = new_node;
			return;
		}

		while (current->next != nullptr) {
			current = current->next;
		}

		current->next = new_node;
		new_node->next = nullptr;
	}

	void push_front(T data) {
		Node* newNode = new Node(data);

		if (m_head == nullptr) {
			m_head = newNode;
			newNode->next = nullptr;
			return;
		}

		newNode->next = m_head;
		m_head = newNode;
	}

	void splice(single_forward_list& other) {
		Node* current = m_head;

		if (m_head == nullptr) {
			m_head = other.m_head;
			other.clear();
			return;
		}

		while (current->next != nullptr) {
			current = current->next;
		}

		current->next = other.m_head;
		other.clear();
	}
	
	void reverse() {
		Node* prev = nullptr;
		Node* current = m_head->next;
		Node* next = nullptr;

		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
	}

};


int main() {
    single_forward_list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    list.push_front(0);
    
    std::cout << "Size of list: " << list.size() << std::endl;
    
    list.insert(2, 99);
    
    std::cout << "Size after insert: " << list.size() << std::endl;
    
    list.remove(1);
    
    std::cout << "Size after remove: " << list.size() << std::endl;

    std::cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << std::endl;

    list.reverse();

    single_forward_list<int> anotherList;
    anotherList.push_back(10);
    anotherList.push_back(20);
    anotherList.push_back(30);

    list.splice(anotherList);

    std::cout << "Final size after splice: " << list.size() << std::endl;

    return 0;
}
