#include "DoubleLinkList.h"
#include "Nodes.h"
using namespace std;
#include <iostream>;

DLL::DLL() {
	head = nullptr;
	tail = nullptr;
}
bool DLL::add(Node* data, int pos) {
	if (data == nullptr) {
		return false;
	}if (pos > size()) {
		return false;
	}
	


	if (size() == 0) {
		head = data;
		tail = data;
		data->setPrev(nullptr);
		data->setNext(nullptr);
		return true;
	}else if (pos == size()) {
		tail->setNext(data);
		data->setNext(nullptr);
		data->setPrev(tail);
		tail=data;
		return true;
	}
	else if (pos > size()) {
		return false;
	}
	else {
		Node* newN = head;
		int positioncurrent = 0;
		while (positioncurrent < pos) {
			if (newN == tail) {
				return false;
			}
			newN = newN->getNext();
			positioncurrent++;

		}
		Node* newNprev = newN->getPrev();
		data->setNext(newN);
		data->setPrev(newNprev);
		newNprev->setNext(data);
		newN->setPrev(data);
		return true;




	}
}
bool DLL::remove(int pos) {
	Node* n;
	n=head;
	int positioncurrent = 0;
	while (positioncurrent < pos) {
		if (n == tail) {
			return false;
		}
		
		n = n->getNext();
		positioncurrent++;

	}
	
	if (n== head) {
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
	
	delete(n);
	return true;
}
bool DLL::replace(Node* old, Node* new_) {
	Node* n = head;
	int e = search(old);
	Node* s = nodeAt(e);
	Node* g =new_;

	while (n != old) {
		if (n == tail) {
			return false;
		}
		n = n->getNext();	

	}

	
	if (old == nullptr || new_ == nullptr) {
		return false;
	}

	


		s->getPrev()->setNext(g);
		s->getNext()->setPrev(g);
		g->setPrev(s->getPrev());
		g->setNext(s->getNext());
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
		pos++;

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
		n = n->getNext();
		positioncurrent++;

	}
	return n;
	
}
void DLL::display_forward() {
	Node* n = head;
	while (n != nullptr) {
		cout << n->getData() << "<->";
		n = n->getNext();
		
	}
	cout << endl;
}
void DLL::display_backwards() {
	Node* n = tail;
	while (n != nullptr) {
		cout << n->getData() << "<->";
		n = n->getPrev();
	}
	cout<< endl;

}
	


int DLL::size() { 
	int count = 0;
	Node* n = head;
	while (n != nullptr)
	{
		count++;
		n = n->getNext();
	}
	return count;


}