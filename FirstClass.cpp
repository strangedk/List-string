#include <iostream>
#include <string>
#include <sstream>
#include "NodeList.h"

using utils::NodeList;
using utils::Node;

int main() {
	// Default list with default values
	NodeList* defaultList = new NodeList(5, "Employee");
	defaultList->ShowNodes();

	// Empty list with no values at initialization moment
	NodeList* list = new NodeList();

	// Fill the list and show it
	list->Push("Peeter")
		->Push("Polina")
		->Push("Maffyn")
		->Push("Mirres")
		->Push("Huskky")
		->Push("Leilla")
		->Push("Rubent")
		->Push("Lestat")
		->ShowNodes();

	// Copy source list with copy constructor
	NodeList* copiedList = new NodeList(*list);

	list->Delete(list->FindNode("Rubent"));
	list->Delete(list->FindNode("Maffyn"));
	list->Delete(list->FindNode("Leilla"));

	list->ShowNodes();
	copiedList->ShowNodes();
}