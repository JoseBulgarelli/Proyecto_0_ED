#pragma once

#include <stdexcept>
#include <iostream>
#include "Node.h"
#include "Stack.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class LinkedStack : public Stack<E> {
private:
	Node<E>* top;
	int size;

public:
	LinkedStack() {
		size = 0;
		top = nullptr;
	}

	~LinkedStack() {
		clear();
	}

	void push(E element) {
		top = new Node<E>(element, top);
		size++;
	}

	E pop() {
		if (size == 0)
			throw runtime_error("Stack is empty.");
		E result = top->element;
		Node<E>* temp = top;
		top = top->next;
		delete temp;
		size--;
		return result;
	}

	E topValue() {
		if (size == 0)
			throw runtime_error("Stack is empty.");
		return top->element;
	}

	void clear() {
		Node<E>* temp;
		for (int i = 0; i < size; i++) {
			temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
		}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	void print() {
		Node<E>* temp = top;
		cout << "[";
		for (int i = 0; i < size; i++) {
			if (i == size - 1)
				cout << temp->element;
			else
				cout << temp->element << ", ";
			temp = temp->next;
		}
		cout << "]" << endl;
	}
};