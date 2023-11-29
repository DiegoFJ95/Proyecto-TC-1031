
#ifndef EQUIPOPOKEMON_H_
#define EQUIPOPOKEMON_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <algorithm>

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

	std::string    removeFirst();
		std::string remove(int);

	void swaps(Pokemon<T>* p1, Pokemon<T>* p2);

	bool empty() const;
	void clear();

	std::string toString() const;

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
void Equipo<T>::swaps(Pokemon<T>* p1, Pokemon<T>* p2) {
	std::swap(p1->nombre, p2->nombre);
	std::swap(p1->tipo1, p2->tipo1);
	std::swap(p1->tipo2, p2->tipo2);
	std::swap(p1->vida, p2->vida);
	std::swap(p1->ataque, p2->ataque);
	std::swap(p1->defensa, p2->defensa);
	std::swap(p1->velocidad, p2->velocidad);
}


template <class T>
void Equipo<T>::sort_nombre() {
    for (Pokemon<T>* p1 = head; p1 != nullptr; p1 = p1->next) {
        for (Pokemon<T>* p2 = p1->next; p2 != nullptr; p2 = p2->next) {
            if (p1->nombre > p2->nombre) {
                // Intercambiar los Pokémon
								swaps(p1,p2);
            }
        }
    }
}

template <class T>
void Equipo<T>::sort_tipo1() {
    for (Pokemon<T>* p1 = head; p1 != nullptr; p1 = p1->next) {
        for (Pokemon<T>* p2 = p1->next; p2 != nullptr; p2 = p2->next) {
            if (p1->tipo1 > p2->tipo1) {
                // Intercambiar los Pokémon
								swaps(p1,p2);
            }
        }
    }
}

template <class T>
void Equipo<T>::sort_tipo2() {
    for (Pokemon<T>* p1 = head; p1 != nullptr; p1 = p1->next) {
        for (Pokemon<T>* p2 = p1->next; p2 != nullptr; p2 = p2->next) {
            if (p1->tipo2 > p2->tipo2) {
                // Intercambiar los Pokémon
								swaps(p1,p2);
            }
        }
    }
}

template <class T>
void Equipo<T>::sort_vida() {
    for (Pokemon<T>* p1 = head; p1 != nullptr; p1 = p1->next) {
        for (Pokemon<T>* p2 = p1->next; p2 != nullptr; p2 = p2->next) {
            if (p1->vida < p2->vida) {
                // Intercambiar los Pokémon
								swaps(p1,p2);
            }
        }
    }
}

template <class T>
void Equipo<T>::sort_ataque() {
    for (Pokemon<T>* p1 = head; p1 != nullptr; p1 = p1->next) {
        for (Pokemon<T>* p2 = p1->next; p2 != nullptr; p2 = p2->next) {
            if (p1->ataque < p2->ataque) {
                // Intercambiar los Pokémon
								swaps(p1,p2);
            }
        }
    }
}

template <class T>
void Equipo<T>::sort_defensa() {
    for (Pokemon<T>* p1 = head; p1 != nullptr; p1 = p1->next) {
        for (Pokemon<T>* p2 = p1->next; p2 != nullptr; p2 = p2->next) {
            if (p1->defensa < p2->defensa) {
                // Intercambiar los Pokémon
								swaps(p1,p2);
            }
        }
    }
}

template <class T>
void Equipo<T>::sort_velocidad() {
    for (Pokemon<T>* p1 = head; p1 != nullptr; p1 = p1->next) {
        for (Pokemon<T>* p2 = p1->next; p2 != nullptr; p2 = p2->next) {
            if (p1->velocidad < p2->velocidad) {
                // Intercambiar los Pokémon
								swaps(p1,p2);
            }
        }
    }
}

#endif /* DLIST_H_ */
