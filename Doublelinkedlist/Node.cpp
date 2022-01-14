#include "DoubleLinkList.h"
#include "Nodes.h"
#include <stdlib.h>
using namespace std;



Node::Node(int i) {
	data = i;
	prev = nullptr;
	next = nullptr;
}

int Node::getData() {
	return data;
}
void Node::setData(int d) {
	data = d;
}
Node* Node::getNext() {
	return(next);
}
void Node::setNext(Node* n) {
	next = n;
}
Node* Node::getPrev() {
	return(prev);

}
void Node::setPrev(Node* n) {
	prev = n;
}

