#include "stdafx.h"
#include "Book.h"
Book::Book()
{
	_nom = "";
	_autor = "";
	_vendes = 0;
	_countador = 0;
	_visitat = false;
	_iniciV = NULL;
}

bool Book::readBook() {
	//_countador = 0;
	cout << "NOM:" << endl;
	getline(cin, _nom);
	 if (_nom != "#") {
		cout << "AUTOR:" << endl;
		getline(cin, _autor);
		cout << "VENDES SETMANALS:" << endl;
		cin >> _vendes;
		unsigned vendes = _vendes;
		vendes_cua(vendes);
	}
	return _nom != "#";
}
void Book::vendes_cua(unsigned vendes) {
	if (!_iniciV) {
		Node *p = new Node;
		p->vendes = vendes;
		p->_next = NULL;
		_iniciV = p;
		
		_countador++;
		cout << "vendes guardats a la llista primera" << endl;
	}
	else {
		if (_countador < 4) {
			addFirst(vendes);
			cout << "vendes guardats a la llista" << endl;
		}
		else {
			deleteLast();
			addFirst(vendes);
		}
	}
}
void Book::showHistorial()const {
	cout << "countador---> " << _countador << endl;
	Node *t = _iniciV;
	while (t) {
		cout << t->vendes << " ";
		t = t->_next;
	}
	cout << endl;
	//cout << "done" << endl;
}
unsigned Book::sum()const {
	Node *t = _iniciV;
	unsigned suma = 0;
	while (t) {
		suma += t->vendes;
		t = t->_next;
	}
	return suma;
}
void Book::addFirst(unsigned vendes) {

	Node *t = new Node;
	t->vendes = vendes;
	t->_next = _iniciV;
	_iniciV = t;
	_countador++;
}
void Book::deleteLast() {
	Node *ant = NULL;
	Node *t = _iniciV;
	bool trobat = false;
	while (t && !trobat) {
		if (t->_next != NULL) {
			ant = t;
			t = t->_next;
		}
		else {
			trobat = true;
		}
	}
	ant->_next = NULL;
	delete t;
	_countador--;
}
void Book::showBook()const {
	cout << _nom <<","<< _autor  <<" : "<<sum()<< endl;
}

double Book::getPrice()const {
	return _vendes;
}
void Book::updatepreu(unsigned vendes = 0) {

	_vendes += vendes;
}

bool Book::is_equal(Book &book)const {
	return book._nom == _nom;
}

bool Book::is_less( Book &book)const {
	return _nom < book._nom;
}
///////MUST METHODS////////////////////
Book&  Book::operator=(const Book& o) {
	//cout << "assignacio operator called" << endl;
	if (this != &o) {
		allibera();
		copia(o);
	}
	return *this;
}
Book::~Book() {
	allibera();
}

Book::Book(const Book& o) {
	//cout << "contructor copia llamado" << endl;
	copia(o);
}

void Book::copia(const Book &o) {
	Node *p;
	Node *ant;
	Node *t ;
	if (o._iniciV) {
		//cout << "one" << endl;
		p = new Node;
		t = o._iniciV;
		p->vendes = t->vendes;
		p->_next = NULL;
		_iniciV = ant = p;
		t = t->_next;
		while (t) {
			//cout << "two" << endl;
			p = new Node;
			p->vendes = t->vendes; p->_next = NULL;
			ant->_next = p; ant = p;
			t = t->_next;
		}
	}
	//_iniciV = o._iniciV;
	_nom = o._nom;
	_countador = o._countador;
	_visitat = o._visitat;
	_autor = o._autor;
	_vendes = o._vendes;
}

void Book::allibera() {
	while (_iniciV) {
		Node *t = _iniciV;
		_iniciV = _iniciV->_next;
		delete t;
	}
}

bool Book::estate()const {
	return sum() != 0;
}

bool Book::visitat()const {
	return _visitat;
}
void Book::setvisitat(bool var) {
	_visitat = var;
}

void Book::showllcontent()const {
	cout <<"nom: "<< _nom << " autor: " << _autor << " vistat: " << _visitat << " count: " << _countador <<" vendes: "<<_vendes<<" inici: "<<_iniciV<< endl;
}

