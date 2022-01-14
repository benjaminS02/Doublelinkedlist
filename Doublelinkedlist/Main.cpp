#include "Nodes.h"
#include "DoubleLinkList.h"
#include <iostream>
using namespace std;

void main() {

	Node* n0 = new Node(0);
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);

	DLL dll;

	dll.add(n0, 0);
	//list.Add(&n1, 10); //should be a false or -1 (error/invalid) 
	//list.Add(nullptr, 1); //should be a false or -1 (error/invalid) 
	dll.add(n1, 1);
	//list.Remove(3); //should be a false or -1 (error/invalid) 
	dll.add(n2, 2);
	dll.display_forward();
	dll.add(n3, 1);
	dll.display_forward();
	dll.remove(2);
	dll.display_forward();
	dll.display_backwards();
	//list.Search(&n4); //should be a false or -1 (error/invalid) 
	dll.search(n3);
	//list.Replace(&n3, nullptr); //should be a false or -1 (error/invalid) 
	//list.Replace(&n5, &n4); //should be a false or -1 (error/invalid) 
	dll.replace(n3, n4);
	dll.display_forward();
	dll.size();

	//nodeAt() is used in the DoublyLinkedList class. //should return nullptr when its invalid position


}