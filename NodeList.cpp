#include <iostream>
#include "NodeList.h"

using utils::NodeList;
using utils::Node;

size_t NodeList::Size() {
	size_t result = 0;
	for (Node* iter = Head(); iter; iter = iter->next)
		++result;
	return result;
}

NodeList* NodeList::Push(std::string data) {
	Node* node = new Node(data);
	if (!head) {
		head = node;
		tail = node;
	}
	else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	return this;
}

NodeList* NodeList::InsertAfter(std::string data, Node* after) {
	Node* node = new Node(data);
	node->next = after->next;
	node->prev = after;

	after->next = node;

	if (node->next)
		node->next->prev = node;
	else
		tail = node;

	return this;
}

NodeList* NodeList::Delete(Node* node) {
	if (node->prev != nullptr)
		node->prev->next = node->next;
	if (node->next != nullptr)
		node->next->prev = node->prev;

	if (node == head)
		head = node->next;
	if (node == tail)
		tail = node->prev;

	delete node;

	return this;
}

NodeList* NodeList::ShowNodes() {
	std::cout << "Size: " << Size() << std::endl;
	for (Node* iter = Head(); iter; iter = iter->next)
		std::cout << iter->data << std::endl;
	std::cout << std::endl;
	return this;
}

NodeList* NodeList::Reverse() {
	if (head == tail)
		return this;

	Node* oldHead = Head();
	Node* oldTail = Tail();

	for (Node* iter = Head(); iter; iter = iter->prev) {
		Node* oldPrev = iter->prev;
		iter->prev = iter->next;
		iter->next = oldPrev;
	}

	head = oldTail;
	tail = oldHead;

	return this;
}

Node* NodeList::FindNode(std::string data) {
	for (Node* iter = Head(); iter; iter = iter->next) {
		if (iter->data == data) {
			return iter;
		}
	}
	return nullptr;
}

Node* NodeList::Head() const {
	return head;
}

Node* NodeList::Tail() const {
	return tail;
}