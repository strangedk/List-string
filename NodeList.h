#pragma once
#include <string>

namespace utils {
	struct Node {
		Node* next = nullptr;
		Node* prev = nullptr;

		std::string data = nullptr;

		Node(std::string data) : data(data) { };
	};

	class NodeList {
	private:
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		NodeList() {

		}

		NodeList(size_t size, std::string defaultData = "Default") {
			if (size > 0) {
				for (size_t i = 0; i < size; ++i)
					Push(defaultData);
			}
		}

		~NodeList() {
			Node* next;
			for (Node* iter = head; iter; iter = next) {
				next = iter->next;
				delete iter;
			}
			delete head;
			delete tail;
		}

		size_t Size();

		NodeList* Push(std::string data);
		NodeList* InsertAfter(std::string data, Node* after);
		NodeList* Delete(Node* node);
		NodeList* ShowNodes();
		NodeList* Reverse();

		Node* FindNode(std::string data);
		Node* Head() const;
		Node* Tail() const;
	};
};