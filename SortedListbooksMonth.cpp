// SortedListbooksMonth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Book.h"
#include"List.h"
void booki(Book book) {
	cout << "price bellow within functio ###" << endl;
	book.vendes_cua();
	book.vendes_cua();
	book.vendes_cua(25);
	book.vendes_cua(2);
	book.showllcontent();
	book.showHistorial();
	cout<<book.getPrice()<<endl;
}

int main()
{
	
	Book book;
	List list;

	/*
	Book new2;
	book.readBook();
	book.showllcontent();
	book.showHistorial();
	new2 = book;
	cout << "after assignation" << endl;
	new2.showllcontent();
	new2.showHistorial();
	booki(new2);

	*/
	cout << "--- SETMANA 1 ---" << endl;
	cout << "ENTRA LES VENDES SETMANALS:" << endl;
	char s = 's';
	unsigned countador = 1;
	while (s != 'n') {
		countador++;
		while (book.readBook()) {
			Book newb = book;
			cout << "content before submitting book" << endl;
			book.showllcontent();
			cout << "content before submitting newb" << endl;
			newb.showllcontent();
			list.Manager(newb);
			Book book;
			cin.ignore();
		}
		//list.updateNotVisitedNodes();
		//list.inicialisetofalseallnodes();
		//list.eliminaNodesvells();
		list.displayContent();
		cout << "VOLS INTRODUIR UNA NOVA SETMANA? (S/N)" << endl;
		cin >> s;
		if (s != 'n') {
			cout << " --- SETMANA " << countador << " ---" << endl;
			cin.ignore();
		}
	}
	list.displayContent();
	
    return 0;
}

