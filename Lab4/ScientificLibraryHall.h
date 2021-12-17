#pragma once
#include "ScientificBook.h";
#include <iostream>
#include "IHall.h"
#include "../Lab2/LIst.h"

class ScientificLibraryHall : public IHall
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

	ScientificLibraryHall(std::string nameHall, int countBooks)
	{
		this->nameHall = nameHall;
		this->countBooks = countBooks;
		listScientificBooks = ListTest();
		for (int i = 0; i < countBooks; i++) {
			std::string text = "Author #";
			this->listScientificBooks.add_node(
				new ScientificBook(text += std::to_string(i),
					1970 + i), i);
		}
	}
	ScientificLibraryHall(std::string nameHall, ScientificBook* arrayBooks, int size)
	{
		this->nameHall = nameHall;
		for (int i = 0; i < size; i++) {
			this->listScientificBooks.add_node(&arrayBooks[i], this->countBooks + i);
		}
	}
	ScientificLibraryHall(const ScientificLibraryHall& obj)
	{
		this->nameHall = obj.nameHall;
		listScientificBooks = ListTest();
		Node* t = obj.listScientificBooks.head->next;
		for (int i = 0; i < obj.countBooks; i++) {
			this->listScientificBooks.add_node(t->val, i);
			t = t->next;
		}
	}
	ScientificLibraryHall() {}
	int getCountBook() const override
	{
		return this->countBooks;
	}

	void printBooks() override
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

	void addBook(int number, ScientificBook* book) override
	{
		this->countBooks++;
		listScientificBooks.add_node(book, number);
	};

	void deleteBook(int number) override
	{
		this->countBooks--;
		listScientificBooks.delete_node(number);
	};

	ScientificBook getBestBook() {
		ScientificBook* best = listScientificBooks.get_addres_Node(0)->val;
		for (int i = 1; i < countBooks; i++) {
			if (listScientificBooks.get_addres_Node(0)->val->getPrice() > best->getPrice()) {
				best = listScientificBooks.get_addres_Node(i)->val;
			}
		}
		return *best;
	}

	ScientificBook& operator[] (const int index);

	ScientificLibraryHall& operator= (const ScientificLibraryHall& drob)
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

	void write(std::ofstream& f) override
	{
		f.write((char*)&nameHall, sizeof nameHall);
		f.write((char*)&countBooks, sizeof countBooks);
		for (int i = 0; i < getCountBook(); i++) {
			f.write((char*)&listScientificBooks.get_addres_Node(i)->val, sizeof listScientificBooks.get_addres_Node(i)->val);
		}
	}

	void read(std::ifstream& f) override
	{
		f.read((char*)&nameHall, sizeof nameHall);
		f.read((char*)&countBooks, sizeof countBooks);
		listScientificBooks = ListTest();
		Node* t = listScientificBooks.head->next;
		for (int i = 0; i < getCountBook(); i++) {
			f.read((char*)&listScientificBooks, sizeof listScientificBooks.add_node(t->val, i);
			t = t->next;
		}
	}

	friend std::ostream& operator<< (std::ostream& stream, ScientificLibraryHall obj);
	friend std::istream& operator>> (std::istream& stream, ScientificLibraryHall& obj);
};

ScientificBook& ScientificLibraryHall::operator[] (const int i) {
	if (i<0 || i>  getCountBook() - 1) {
		std::cout << "\nIndex out-of-bounds.\n";  exit(1);
	}
	return *listScientificBooks.get_addres_Node(i)->val;
}

std::ostream& operator<< (std::ostream& stream, ScientificLibraryHall obj)
{
	stream << obj.nameHall << ", ";
	for (int i = 0; i < obj.getCountBook(); i++) {
		stream << obj.listScientificBooks.get_addres_Node(i)->val << ", ";
	}
	stream << obj.countBooks << "\n";

	return stream;
}

std::istream& operator>> (std::istream& stream, ScientificLibraryHall& obj)
{
	std::cout << "Enter nameHall,countBooks,listScientificBooks values: ";
	stream >> obj.nameHall;
	stream >> obj.countBooks;
	obj.listScientificBooks = ListTest();
	Node* t = obj.listScientificBooks.head->next;
	for (int i = 0; i < obj.getCountBook(); i++) {
		obj.listScientificBooks.add_node(t->val, i);
		t = t->next;
	}
	for (int i = 0; i < obj.getCountBook(); i++) {
		stream >> *obj.listScientificBooks.get_addres_Node(i)->val;
	}
	return stream;
}
