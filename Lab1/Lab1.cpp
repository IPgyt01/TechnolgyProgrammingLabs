#include "ChildrenBook.h";
#include "ChildrenLibraryHall.h";
#include "ChildrenLibrary.h";
#include <clocale>
#include <iostream>
#include<locale>
#include<cstdlib>

int main()
{
	setlocale(0, "");
	ChildrenBook* a = new ChildrenBook();
	ChildrenBook* b = new ChildrenBook("author1", "title1", 2999, 2002, 18);
	ChildrenBook* c = new ChildrenBook("author2", "title2", 1999, 2001, 18);
	ChildrenBook* d = new ChildrenBook("author3", "title3", 999, 2000, 16);
	ChildrenLibraryHall* hall = new ChildrenLibraryHall("home1", 5);
	std::cout << "\n" << "Добавление книг";
	hall->addBook(1, *a);
	hall->addBook(2, *b);
	hall->addBook(3, *d);
	hall->printBooks();
	std::cout << "\n\n" << "Замена книги a на книгу c";
	hall->replacementBook(1, *c);
	hall->printBooks();
	std::cout << "\n\n" << "Удаление униги";
	hall->deleteBook(1);
	hall->printBooks();
	std::cout << "\n\n" << "SumAllBooks:" << hall->getSumAllBooks() << "\n\n";
	ChildrenLibraryHall* hall2 = new ChildrenLibraryHall("home2", 3);
	ChildrenLibraryHall* hall3 = new ChildrenLibraryHall("home3", 3);
	int massiwCountBook[3] = { 5,6,7 };
	ChildrenLibrary* library = new ChildrenLibrary(3, massiwCountBook);
	library->print();
	std::cout << "\n" << "Замена зала" << "\n";
	library->replacementHall(1, *hall);
	library->print();
	delete a;
	delete b;
	delete c;
	delete d;
	delete hall;
	delete hall3;
}