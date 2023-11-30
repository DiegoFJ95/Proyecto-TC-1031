
#ifndef EQUIPOPOKEMON_H_
#define EQUIPOPOKEMON_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <algorithm>
#include <iostream>

template <class T> class Equipo;

template <class T>
class Pokemon {
private:
	Pokemon(std::string, std::string, std::string, int, int, int, int);
	Pokemon(std::string, std::string, std::string, int, int, int, int, Pokemon<T>*, Pokemon<T>*);
	Pokemon(const Pokemon<T>&);

	std::string nombre;
  std::string tipo1;
  std::string tipo2;
	int vida;
  int ataque;
  int defensa;
  int velocidad;

	Pokemon<T> *previous;
	Pokemon<T> *next;

	friend class Equipo<T>;
};

// O(1)
template <class T>
Pokemon<T>::Pokemon(std::string nom, std::string ti1, std::string ti2, int vi, int at, int de, int ve) : nombre(nom), tipo1(ti1), tipo2(ti2), vida(vi), ataque(at), defensa(de), velocidad(ve), previous(0), next(0) {}

// O(1)
template <class T>
Pokemon<T>::Pokemon(std::string nom, std::string ti1, std::string ti2, int vi, int at, int de, int ve, Pokemon *prev, Pokemon* nxt) : nombre(nom), tipo1(ti1), tipo2(ti2), vida(vi), ataque(at), defensa(de), velocidad(ve), previous(prev), next(nxt) {}

// O(1)
template <class T>
Pokemon<T>::Pokemon(const Pokemon<T> &source) : nombre(source.nombre), tipo1(source.tipo1), tipo2(source.tipo2), vida(source.vida), ataque(source.ataque), defensa(source.defensa), velocidad(source.velocidad), previous(source.previous), next(source.next) {}




template <class T>
class Equipo {
public:
	Equipo();
	~Equipo();

	void addFirst(std::string, std::string, std::string, int, int, int, int);
	void add(std::string, std::string, std::string, int, int, int, int);

	std::string removeFirst();
	std::string remove(int);

	void swapPointers(Pokemon<T>*, Pokemon<T>*);

	bool empty() const;
	void clear();

	std::string toString() const;
	std::string IndexToString(int) const;

	int  indexOf(std::string) const;

	void sort_nombre();
	void sort_tipo1();
	void sort_tipo2();
	void sort_vida();
	void sort_ataque();
	void sort_defensa();
	void sort_velocidad();


private:
	Pokemon<T> *head;
	Pokemon<T> *tail;
	int 	 size;
};

// O(1)
template <class T>
Equipo<T>::Equipo() : head(0), tail(0), size(0) {}

// O(N)
template <class T>
Equipo<T>::~Equipo() {
	clear();
}

// O(1)
template <class T>
bool Equipo<T>::empty() const {
	return (head == 0 && tail == 0);
}

// O(1)
template <class T>
void Equipo<T>::addFirst(std::string nom, std::string ti1, std::string ti2, int vi, int at, int de, int ve){
	Pokemon<T> *newLink;

	newLink = new Pokemon<T>(nom, ti1, ti2, vi, at, de, ve);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		newLink->next = head;
		head->previous = newLink;
		head = newLink;
	}
	size++;
}


// O(1)
template <class T>
void Equipo<T>::add(std::string nom, std::string ti1, std::string ti2, int vi, int at, int de, int ve){
	Pokemon<T> *newLink;

	newLink = new Pokemon<T>(nom, ti1, ti2, vi, at, de, ve);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

// O(1)
template <class T>
std::string Equipo<T>::removeFirst(){
	std::string nom;
	Pokemon<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	nom = p->nombre;

	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size--;

	return nom;
}

// O(N)
template <class T>
std::string  Equipo<T>::remove(int index) {
	int pos;
	std::string nom;
	Pokemon<T> *p;

	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	if (index == 0) {
		return removeFirst();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	nom = p->nombre;
	p->previous->next = p->next;
	if (p->next != 0) {
		p->next->previous = p->previous;
	}
	size--;

	delete p;

	return nom;
}

// O(N)
template <class T>
void Equipo<T>::clear() {
	Pokemon<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

// O(N)
template <class T>
std::string Equipo<T>::toString() const {
	std::stringstream aux;
	Pokemon<T> *p;

	p = head;

	while (p != 0) {
		aux << "Nombre: "<<p->nombre<<"\n";
		aux << "Tipo 1: "<<p->tipo1<<"\n";
		aux << "Tipo 2: "<<p->tipo2<<"\n";
		aux << "Vida: "<<p->vida<<"\n";
		aux << "Ataque: "<<p->ataque<<"\n";
		aux << "Defensa: "<<p->defensa<<"\n";
		aux << "Velocidad: "<<p->velocidad<<"\n";
		if (p->next != 0) {
			aux << "\n";
		}
		p = p->next;
	}
	return aux.str();
}

// O(N)
template <class T>
std::string Equipo<T>::IndexToString(int index) const {
	std::stringstream aux;
	Pokemon<T> *p;

	p = head;
	for(int i=0; i<index; i++){
		p = p->next;
	}
	aux << "Nombre: "<<p->nombre<<"\n";
	aux << "Tipo 1: "<<p->tipo1<<"\n";
	aux << "Tipo 2: "<<p->tipo2<<"\n";
	aux << "Vida: "<<p->vida<<"\n";
	aux << "Ataque: "<<p->ataque<<"\n";
	aux << "Defensa: "<<p->defensa<<"\n";
	aux << "Velocidad: "<<p->velocidad<<"\n";

	return aux.str();
}



// O(N)
template <class T>
int Equipo<T>::indexOf(std::string nom) const {
	int index;
	Pokemon<T> *p;

	index = 0;
	p = head;
	while (p != 0) {
		if (p->nombre == nom) {
			return index;
		}
		index++;
		p = p->next;
	}
	return -1;
}

// O(1)
template <class T>
void Equipo<T>::swapPointers(Pokemon<T>* p1, Pokemon<T>* p2) {
    Pokemon<T> *p;

		if (p1 == p2) {
			return;
		}

		if (head == nullptr || head->next == nullptr) {
			return;
		}

		p = p1->next;
		p1->next = p2->next;
		p2->next = p;

		if (p1->next != NULL){
			p1->next->previous = p1;
		}
		if (p2->next != NULL){
			p2->next->previous = p2;
		}


		p = p1->previous;
		p1->previous = p2->previous;
		p2->previous = p;

		if (p1->previous != NULL){
			p1->previous->next = p1;
		}
		if (p2->previous != NULL){
			p2->previous->next = p2;
		}

		if(p1 == head){
			head = p2;
		}
		else if (p2 == head){
			head = p1;
		};

		if(p1 == tail){
			tail = p2;
		}
		else if (p2 == tail){
			tail = p1;
		};
	}


// O(N^2)
template <class T>
void Equipo<T>::sort_nombre() {
  Pokemon<T>* p1;
  Pokemon<T>* p2;
  p1 = head;
  p2 = p1->next;

  for(int i = 0; i <=size; i++){
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->nombre > p2->nombre) {
        swapPointers(p1, p2);
  		}
		}
	}
}

// O(N^2)
template <class T>
void Equipo<T>::sort_tipo1() {
	Pokemon<T>* p1;
  Pokemon<T>* p2;
  p1 = head;
  p2 = p1->next;

  for(int i = 0; i <=size; i++){
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->tipo1 > p2->tipo1) {
        swapPointers(p1, p2);
  		}
		}
	}
}

// O(N^2)
template <class T>
void Equipo<T>::sort_tipo2() {
	Pokemon<T>* p1;
  Pokemon<T>* p2;
  p1 = head;
  p2 = p1->next;

  for(int i = 0; i <=size; i++){
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->tipo2 > p2->tipo2) {
        swapPointers(p1, p2);
  		}
		}
	}
}

// O(N^2)
template <class T>
void Equipo<T>::sort_vida() {
	Pokemon<T>* p1;
  Pokemon<T>* p2;
  p1 = head;
  p2 = p1->next;

  for(int i = 0; i <=size; i++){
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->vida < p2->vida) {
        swapPointers(p1, p2);
  		}
		}
	}
}

// O(N^2)
template <class T>
void Equipo<T>::sort_ataque() {
	Pokemon<T>* p1;
  Pokemon<T>* p2;
  p1 = head;
  p2 = p1->next;

  for(int i = 0; i <=size; i++){
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->ataque < p2->ataque) {
        swapPointers(p1, p2);
  		}
		}
	}
}

// O(N^2)
template <class T>
void Equipo<T>::sort_defensa() {
	Pokemon<T>* p1;
  Pokemon<T>* p2;
  p1 = head;
  p2 = p1->next;

  for(int i = 0; i <=size; i++){
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->defensa < p2->defensa) {
        swapPointers(p1, p2);
  		}
		}
	}
}

// O(N^2)
template <class T>
void Equipo<T>::sort_velocidad() {
	Pokemon<T>* p1;
  Pokemon<T>* p2;
  p1 = head;
  p2 = p1->next;

  for(int i = 0; i <=size; i++){
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->velocidad < p2->velocidad) {
        swapPointers(p1, p2);
  		}
		}
	}
}

#endif
