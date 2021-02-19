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

	// Search nodes which will need to identify specific nodes
	Node* toSearch = list->FindNode("Leilla");
	Node* toPasteAfter = list->FindNode("Mirres");

	// Deleting selected node and show results
	list->Delete(toSearch)
		->ShowNodes()
		// Insert a new node and show results
		->InsertAfter("Novice", toPasteAfter)
		->ShowNodes()
		// Reverse the list and show results
		->Reverse()
		->ShowNodes();
}