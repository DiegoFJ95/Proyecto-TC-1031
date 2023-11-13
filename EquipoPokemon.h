
#ifndef EQUIPOPOKEMON_H_
#define EQUIPOPOKEMON_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class Equipo;


template <class T>
class Pokemon {
private:
	Pokemon(std::string, std::string, std::string, int, int, int, int);
	Pokemon(std::string, std::string, std::string, int, int, int, int, Pokemon<T>*, Pokemon<T>*);
	Pokemon(const Pokemon<T>&);

	std::string nombre; //Definición de los atributos privados de la clase Pokemon.
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

template <class T>
Pokemon<T>::Pokemon(std::string nom, std::string ti1, std::string ti2, int vi, int at, int de, int ve) : nombre(nom), tipo1(ti1), tipo2(ti2), vida(vi), ataque(at), defensa(de), velocidad(ve), previous(0), next(0) {}

template <class T>
Pokemon<T>::Pokemon(std::string nom, std::string ti1, std::string ti2, int vi, int at, int de, int ve, Pokemon *prev, Pokemon* nxt) : nombre(nom), tipo1(ti1), tipo2(ti2), vida(vi), ataque(at), defensa(de), velocidad(ve), previous(prev), next(nxt) {}

template <class T>
Pokemon<T>::Pokemon(const Pokemon<T> &source) : nombre(source.nombre), tipo1(source.tipo1), tipo2(source.tipo2), vida(source.vida), ataque(source.ataque), defensa(source.defensa), velocidad(source.velocidad), previous(source.previous), next(source.next) {}



template <class T>
class Equipo {
public:
	Equipo();
	Equipo(const Equipo<T>&);
	~Equipo();

	void addFirst(std::string, std::string, std::string, int, int, int, int);
	void add(std::string, std::string, std::string, int, int, int, int);
	std::string    getFirst() const ;
	std::string    removeFirst() ;
	int  length() const;
	std::string get(int) const;
	bool contains(std::string) const;
	bool empty() const;
	void clear();
	std::string toString() const;
	void operator= (const Equipo&);

	bool set(int, std::string, std::string, std::string, int, int, int, int);
	int  indexOf(std::string) const;
	int  lastIndexOf(std::string) const;
	std::string remove(int);
	bool removeFirstOcurrence(std::string);
	bool removeLastOcurrence(std::string);

private:
	Pokemon<T> *head;
	Pokemon<T> *tail;
	int 	 size;
};



template <class T>
Equipo<T>::Equipo() : head(0), tail(0), size(0) {}


// NO
template <class T>
Equipo<T>::~Equipo() {
	clear();
}

template <class T>
bool Equipo<T>::empty() const {
	return (head == 0 && tail == 0);
}

// NO
template <class T>
int Equipo<T>::length() const {
	return size;
}

// NO
template <class T>
bool Equipo<T>::contains(std::string nom) const {
	Pokemon<T> *p;

	p = head;
	while (p != 0) {
		if (p->nombre == nom) {
			return true;
		}
		p = p->next;
	}
	return false;
}

// NO
template <class T>
std::string Equipo<T>::getFirst() const{
	if (empty()) {
		throw NoSuchElement();
	}
	return head->nombre;
}

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

// NO
template <class T>
std::string  Equipo<T>::get(int index) const {
	int pos;
	Pokemon<T> *p;

	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	if (index == 0) {
		return getFirst();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	return p->nombre;
}

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

// NO
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


//============================ hacer esto

// NO
template <class T>
Equipo<T>::Equipo(const Equipo<T> &source){
	Pokemon<T> *p, *q;

	if (source.empty()) {
		size = 0;
		head = 0;
		tail = 0;
	} else {
		p = source.head;
		head = new Pokemon<T>(p->nombre, p->tipo1, p->tipo2, p->vida, p->ataque, p->defensa, p->velocidad);
		if (head == 0) {
			throw OutOfMemory();
		}
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new Pokemon<T>(p->nombre, p->tipo1, p->tipo2, p->vida, p->ataque, p->defensa, p->velocidad, q, 0);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

// NO
template <class T>
void Equipo<T>::operator=(const Equipo<T> &source){
	Pokemon<T> *p, *q;

	clear();
	if (source.empty()) {
		size = 0;
		head = 0;
		tail = 0;
	} else {
		p = source.head;
		head = new Pokemon<T>(p->nombre, p->tipo1, p->tipo2, p->vida, p->ataque, p->defensa, p->velocidad);
		if (head == 0) {
			throw OutOfMemory();
		}
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new Pokemon<T>(p->nombre, p->tipo1, p->tipo2, p->vida, p->ataque, p->defensa, p->velocidad, q, 0);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

// NO
template <class T>
bool Equipo<T>::set(int index, std::string nom, std::string ti1, std::string ti2, int vi, int at, int de, int ve) {
	int pos;
	Pokemon<T> *p;

	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	p->nombre = nom;
	p->tipo1 = ti1;
	p->tipo2 = ti2;
	p->vida = vi;
	p->ataque = at;
	p->defensa = de;
	p->velocidad = ve;
	return true;
}

// NO
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

template <class T>
int Equipo<T>::lastIndexOf(std::string nom) const {
	int index;
	Pokemon<T> *p;

	index = size - 1;
	p = tail;
	while (p != 0) {
		if (p->nombre == nom) {
			return index;
		}
		index--;
		p = p->previous;
	}
	return -1;
}

// NO
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

template <class T>
bool Equipo<T>::removeFirstOcurrence(std::string nom) {
	Pokemon<T> *p;

	p = head;
	while (p != 0) {
		if (p->nombre == nom) {
			break;
		}
		p = p->next;
	}

	if (p != 0) {
		if (p->previous == 0) {
			head = p->next;
			p->next->previous = 0;
		} else {
			p->previous->next = p->next;
			if (p->next != 0) {
				p->next->previous = p->previous;
			}
		}
		size--;
		return true;
	}

	return false;
}

template <class T>
bool Equipo<T>::removeLastOcurrence(std::string nom) {
	Pokemon<T> *p;

	p = tail;
	while (p != 0) {
		if (p->nombre == nom) {
			break;
		}
		p = p->previous;
	}

	if (p != 0) {
		if (p->previous == 0) {
			head = p->next;
			p->next->previous = 0;
		} else {
			p->previous->next = p->next;
			if (p->next != 0) {
				p->next->previous = p->previous;
			}
		}
		size--;
		return true;
	}

	return false;
}

#endif /* DLIST_H_ */
