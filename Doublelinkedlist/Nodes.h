#pragma once


class Node{
private:
	float data;
	Node* next;
	Node* prev;
public:
	Node(int i);
	int getData();
	void setData(int data);
	Node* getNext();
	void setNext(Node* next);
	Node* getPrev();
	void setPrev(Node* prev);
};

