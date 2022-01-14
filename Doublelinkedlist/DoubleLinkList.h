#pragma once
#include "Nodes.h"



class DLL{
private:
	Node* head;
	Node* tail;

public:
	DLL();
	bool add(Node* data, int pos);
	bool remove(int pos);
	bool replace(Node* old, Node* new_);
	int search(Node* data);
	Node* nodeAt(int pos);
	void display_forward();
	void display_backwards();
	int size();


};