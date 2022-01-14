#include "DoubleLinkList.h"
#include "Nodes.h"
using namespace std;
#include <iostream>;

DLL::DLL() {
	head = nullptr;
	tail = nullptr;
}
bool DLL::add(Node* data, int pos) {
	int positionc = 0;
	while (positionc < pos) {
		if (data == tail) {
			return false;
		}
		positionc++;
	}
	if (size() == 0) {
		head = data;
		tail = data;
		data->setPrev(nullptr);
		data->setNext(nullptr);
	}
	else if (pos == 0) {
		data->setPrev(nullptr);
		data->setNext(head);
		head->setPrev(data);
		data = head;
	}else if (pos == size()) {
		data->setNext(nullptr);
		data->setPrev(tail);
		tail->setNext(data);
		data = tail;
	}
	else {
		Node* newN = head;
		int positioncurrent = 0;
		while (positioncurrent < pos) {
			positioncurrent++;
			newN = newN->getNext();
		}
		Node* newNprev = newN->getPrev();
		data->setNext(newN);
		data->setPrev(newNprev);
		newNprev->setNext(data);
		newN->setPrev(data);




	}
}
bool DLL::remove(int pos) {
	Node* n=head;
	int positioncurrent = 0;
	while (positioncurrent < pos) {
		if (n == tail) {
			return false;
		}
		positioncurrent++;
		n = n->getNext();

	}
	
	if (n == head) {
		head=n->getNext();
		head->setPrev(nullptr);
	}if (n == tail) {
		tail = n->getPrev();
		tail->setNext(nullptr);
	}
	else {
		n->getNext()->setPrev(n->getPrev());
		n->getPrev()->setNext(n->getNext());

	}
	
	delete n;
	return true;
}
bool DLL::replace(Node* old, Node* new_) {
	Node* n = head;
	Node* e = old;
	Node* g = new_;
	while (n != e) {
		n = n->getNext();
		if (n == tail) {
			return false;
		}
	}
	while (n != nullptr) {
		n = n->getNext();
		if (n == nullptr) {
			return false;
		}
	}
	e->getPrev()->setNext(g);
	e->getNext()->setPrev(g);
	g->setPrev(e->getPrev());
	g->setNext(e->getNext());
	return true;




	


}
int DLL::search(Node* data) {
	Node* n = head;
	int pos = 0;
	while (n != data) {
		if (n == tail) {
			return -1;
		}
		n = n->getNext();

	}
	return pos;

}
Node* DLL::nodeAt(int pos) {
	Node* n = head;
	int positioncurrent = 0;
	while (positioncurrent < pos) {
		if (n == tail) {
			return nullptr;
		}
		positioncurrent++;
		n = n->getNext();

	}
	return n;
	
}
void DLL::display_forward() {
	Node* n = head;
	while (n != nullptr) {
		cout << n->getData() << "<->";
		n=n->getNext();
	}

}
void DLL::display_backwards() {
	Node* n = tail;
	while (n != nullptr) {
		cout << n->getData() << "<->";
		n = n->getPrev();
	}

}
	


int DLL::size() { 
	int count = 0;
	Node* n = head;
	while (head != nullptr)
	{
		count++;
		n = n->getNext();
	}
	return count;


}