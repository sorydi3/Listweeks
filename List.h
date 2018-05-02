#pragma once
#include <iostream>
#include"Book.h"
using namespace std;

class List
{
public:
	//constructor
	List();
	//consultors
	void displayContent()const;
	bool is_there(Book book)const;
	//modificadors
	void Manager(Book book);
	void updateNotVisitedNodes();
	void inicialisetofalseallnodes();
	//void deleteNode();
	//constructor de copia
	List(const List& o);
	//operador d'assignacio
	List& operator=(const List& o);
	//destructor
	void eliminaNodesvells();
	~List();
private:
	struct Node
	{
		Book book;
		Node *_next;
	};
	Node *_inici;
	void allibera();
	void copia(const List& o);
	void addLast(Book book);
	void deleteLast();
	void addBetween(Book book, Node *ant, Node *cur);
	void deleteBetween(Node *ant, Node *cur);
	void addFirst(Book book);
	void deleteFirst();
};

