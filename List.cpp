#include "stdafx.h"
#include "List.h"


List::List()
{
	_inici = NULL;
}

////////////////////////////////////insert///////////
void List::Manager(Book book) {
	Node *ant = NULL;
	bool trobat = false;
	Node *t = _inici;
	book.showllcontent();
	while (t && !trobat) {
		//cout << "dintre del while" << endl;
		if (t->book.is_less(book)) {
			ant = t;
			t = t->_next;
			//cout << "incrementent el bucle" << endl;
		}
		else {
			trobat = true;
			cout << "trobat posicio " << t->book.getPrice() << endl;
		}
	}

	if (!t && !_inici) {
		Node *p = new Node;
		p->book = book;
		p->_next = NULL;
		_inici = p;
	}
	else if (!t && ant) {//add at rhe end of the list
		if (!(book.is_equal(ant->book))) {//integer != ant->enter
			cout << "added at las position" << endl;
			book.vendes_cua(book.getPrice());
			addLast(book);
		}
		else {
			ant->book.vendes_cua(book.getPrice());
			ant->book.setvisitat(true);
		}
	}
	else if (t && ant) {
		if (!(book.is_equal(t->book))) {//(integer != t->enter
			cout << "added beween " << t->book.getPrice() << ", " << book.getPrice() << endl;
			book.vendes_cua(book.getPrice());
			addBetween(book, ant, t);
		}
		else {
			cout << "actualitzan llibre" << endl;
			t->book.vendes_cua(book.getPrice());
			t->book.setvisitat(true);
		}
	}
	else {
		if (!(_inici->book.is_equal(book))) {
			cout << "addet at first position" << endl;
			book.vendes_cua(book.getPrice());
			addFirst(book);
		}
		else {
			cout << " exixteix actualitzan llibre" << endl;
			_inici->book.vendes_cua(book.getPrice());
			_inici->book.setvisitat(true);
		}
	}
}

void List::addLast(Book book) {
	Node *p = new Node;
	p->book = book;
	p->_next = NULL;
	Node *ant = NULL;
	Node *t = _inici;
	while (t) {
		ant = t;
		t = t->_next;
	}
	ant->_next = p;
}
////////////////////////////deletees////////////////////////
void List::deleteLast() {
	Node *ant = NULL;
	Node *t = _inici;
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
}

void List::deleteBetween(Node *ant, Node *cur) {
	ant->_next = cur->_next;
	delete cur;
}

void List::deleteFirst() {
	Node *aux = _inici;
	_inici = _inici->_next;
	delete aux;

}
///////////////////////////////////////////////////////////////////////

void List::addBetween(Book book, Node *ant, Node *cur) {
	Node *p = new Node;
	p->book = book;
	p->_next = cur;
	ant->_next = p;
}
void List::addFirst(Book book)
{
	Node *p = new Node;
	p->book = book;
	p->_next = _inici;
	_inici = p;
}
bool List::is_there(Book book)const {
	Node *t = _inici;
	bool trobat = false;
	while (t && !trobat) {
		if (t->book.is_equal(book)) trobat = true;
		t = t->_next;
	}
	return trobat;
}
///////////////////////////////////////////////////////////////////////
void List::displayContent() const {
	if (_inici) {
		Node *aux = _inici;
		while (aux) {
			aux->book.showBook();
			aux->book.showHistorial();
			cout << endl;
			cout << "la suma dels items " << aux->book.sum() << endl;
			aux->book.showllcontent();
			aux = aux->_next;
		}
		
		cout << endl;
	}
	else {
		cout << "la llista es vuit" << endl;
	}
}
//////////////////////////////////////////////////////////////////



List& List::operator=(const List& o) {
	if (this != &o) {
		allibera();
		copia(o);
	}
	return *this;
}

List::List(const List& o)
{
	//constructor copia
	cout << "constructor copia llamado" << endl;
	_inici = NULL;
	copia(o);
}
void List::copia(const List& o) {
	Node *p = NULL;
	Node *ant = NULL;
	Node *t = NULL;
	if (o._inici) {
		p = new Node;
		t = o._inici;
		p->book = t->book;
		p->_next = NULL;
		_inici = ant = p;
		t = t->_next;
		while (t) {
			p = new Node;
			p->book = t->book;
			p->_next = NULL;
			ant->_next = p;
			ant = p;
			t = t->_next;
		}
	}
}
List::~List()
{
	allibera();
}

void List::allibera() {
	while (_inici) {
		Node *t = _inici;
		_inici = _inici->_next;
		delete t;
	}
}

void List::updateNotVisitedNodes() {
	Node *t = _inici;
	while (t) {
		if (!t->book.visitat()) {
			t->book.vendes_cua();
		}
		t = t->_next;
	}
}

void List::inicialisetofalseallnodes() {
	Node *t = _inici;
	while (t) {
		t->book.setvisitat();
		t = t->_next;
	}
}

void List::eliminaNodesvells() {
	Node *t = _inici;
	while (t) {
		if (!t->book.estate()) {
			Manager(t->book);
			cout << "s'ha elinat un node" << endl;
			t->book.showBook();
			t->book.showHistorial();
		}
		t = t->_next;
	}

}