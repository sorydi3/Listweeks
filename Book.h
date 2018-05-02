#pragma once
#pragma once
#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<string>
using namespace std;
class Book
{

public:
	//CONSTRUCTOR
	Book();
	//CONSULTORS
	void showBook()const;
	double getPrice()const;
	//MODIFICADOR
	bool readBook();
	void updatepreu(unsigned vendes);
	bool is_equal(Book &book) const;
	bool is_less(Book &book)const;
	void vendes_cua(unsigned vendes=0);
	void showHistorial()const;
	bool estate()const;
	bool visitat()const;
	void  setvisitat(bool var=false);
	unsigned sum()const;
	void allibera();
	~Book();
	Book(const Book& o);
	Book& operator=(const Book& o);
	void showllcontent()const;
private:
	static const unsigned  MAX = 4;
	string _nom;
	string _autor;
	unsigned _vendes;
	unsigned _countador;
	bool _visitat;
	struct Node
	{
		unsigned vendes;
		Node *_next;
	};
	Node *_iniciV;

	void copia(const Book &book);
	void deleteLast();
	void addFirst(unsigned vendes);
};
#endif // !1