//Clase que define los atributos y métodos un Heap con prioridad.
//Las funcionalidades de esta clase son: Agregar elementos al Heap, eliminar elementos del Heap,
//ver sus elementos y sus datos.
//Creadores: El profe, Jose Alberto Bulgarelli e Ignacio Castillo.
#pragma once

#include <stdexcept>
#include <iostream>
#include "PriorityQueue.h"
#include "Pair.h"
#include "MinHeap.h"
#include "Util.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class HeapPriorityQueue : public PriorityQueue<E> {
private:
	MinHeap<Pair<int, E>>* pairs;

public:
	HeapPriorityQueue(int max = DEFAULT_MAX) {
		pairs = new MinHeap<Pair<int, E>>(max);
	}
	~HeapPriorityQueue() {
		clear();
		delete pairs;
	}
	void insert(E element, int priority){
		Pair<int, E> p(priority, element);
		pairs->insert(p);
	}
	E min() {
		Pair<int, E> p = pairs->first();
		return p.value;
	}
	E removeMin() {
		Pair<int, E> p = pairs->removeFirst();
		return p.value;
	}
	void clear() {
		pairs->clear();
	}
	int getSize() {
		return pairs->getSize();
	}
	bool isEmpty() {
		return pairs->isEmpty();
	}
	void print() {
		pairs->print();
	}
};