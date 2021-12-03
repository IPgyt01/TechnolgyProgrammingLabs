#pragma once
#include "ScientificBook.h";
#include "LIst.h";
#include <iostream>
class ScientificLibraryHall1
{
private:
	std::string nameHall;
	int countBooks = 0;
	ListTest listScientificBooks;
public:
	void setNameHall(std::string nameHall) { this->nameHall = nameHall; };

	std::string getNameHall() { return this->nameHall; };

	ListTest getArrayBooks() { return this->listScientificBooks; };

	void setScientificBooks(ListTest listScientificBooks, int size)
	{
		this->countBooks = size;
		this->listScientificBooks = listScientificBooks;
	};

	ScientificLibraryHall1(std::string nameHall, int countBooks)
	{
		this->nameHall = nameHall;
		this->countBooks = countBooks;
		listScientificBooks = ListTest();
		for (int i = 0; i < countBooks; i++) {
			std::string text = "Автор #";
			this->listScientificBooks.add_node(
				new ScientificBook(text += std::to_string(i),
					1970 + i), i);
		}
	}
	ScientificLibraryHall1(std::string nameHall, ScientificBook* arrayBooks, int size)
	{
		this->nameHall = nameHall;
		for (int i = 0; i < size; i++) {
			this->listScientificBooks.add_node(&arrayBooks[i], this->countBooks + i);
		}
	}
	ScientificLibraryHall1(const ScientificLibraryHall1& obj)
	{
		this->nameHall = nameHall;
		listScientificBooks = ListTest();
		Node* t = obj.listScientificBooks.head->next;
		for (int i = 0; i < obj.countBooks; i++) {
			this->listScientificBooks.add_node(t->val, i);
			t = t->next;
		}
	}

	ScientificLibraryHall1() {}

	int getCountBook()
	{
		return this->countBooks;
	}

	void printBooks()
	{
		std::cout << "\n" << getNameHall() << +":";
		Node* t = listScientificBooks.head->next;
		for (int i = 0; i < this->countBooks; i++)
		{

			std::cout << "\n" << i << ":" << t->val->getAuthor();
			t = t->next;
		}
	}

	double getSumAllBooks()
	{
		double test = 0;
		for (int i = 0; i < countBooks; i++)
		{
			test += listScientificBooks.get_addres_Node(i)->val->getPrice();
		}
		return test;
	};

	void addBook(ScientificBook* book, int number)
	{
		this->countBooks++;
		listScientificBooks.add_node(book, number);
	};

	void deleteBook(int number)
	{
		this->countBooks--;
		listScientificBooks.delete_node(number);
	};

	ScientificBook getBestBook() {
		ScientificBook* best = listScientificBooks.get_addres_Node(0)->val;
		for (int i = 1; i < countBooks; i++) {
			if (listScientificBooks.get_addres_Node(i)->val->getPrice() > best->getPrice()) {
				best = listScientificBooks.get_addres_Node(i)->val;
			}
		}
		return *best;
	}

	ScientificBook& operator[] (const int index);

	ScientificLibraryHall1& operator= (const ScientificLibraryHall1& drob)
	{
		this->nameHall = drob.nameHall;
		this->countBooks = drob.countBooks;
		listScientificBooks = ListTest();
		Node* t = drob.listScientificBooks.head->next;
		for (int i = 0; i < drob.countBooks; i++) {
			this->listScientificBooks.add_node(t->val, i);
			t = t->next;
		}
		return *this;
	}
};

//ScientificBook& ScientificLibraryHall1::operator[] (const int i) {
//	if (i<0 || i>  getCountBook() - 1) {
//		std::cout << "\nIndex out-of-bounds.\n";  exit(1);
//	}
//	return *listScientificBooks.get_addres_Node(i)->val;
//}
