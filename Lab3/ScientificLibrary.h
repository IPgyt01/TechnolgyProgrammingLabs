#pragma once
#include "List2.h"
#include "../Lab2/ScientificLibraryHall.h"

class ScientificLibrary {
private:
	int countHall = 0;
	ListTest2<ScientificLibraryHall1> listScientificHalls;
public:
	ScientificLibrary(int countHall, int* bookArray)
	{
		this->countHall = countHall;
		for (int i = 0; i < countHall; i++)
		{
			std::string text = "Hall#";
			this->listScientificHalls.add_node(new ScientificLibraryHall1(text += std::to_string(i), bookArray[i]), i);
		}
	}

	ScientificLibrary(ScientificLibraryHall1* arrayHalls[], int countHall)
	{
		for (int i = 0; i < countHall; i++) {
			this->listScientificHalls.add_node(arrayHalls[i], this->countHall);
			this->countHall++;
		}
	}

	ScientificLibrary(const ScientificLibrary& obj)
	{
		this->listScientificHalls = ListTest2<ScientificLibraryHall1>();
		Node2<ScientificLibraryHall1>* t = obj.listScientificHalls.head->next;
		for (int i = 0; i < obj.countHall; i++) {
			this->listScientificHalls.add_node(t->val, i);
			t = t->next;
		}
	}

	int getCountHalls() { return countHall; };

	int getCountBooks()
	{
		int countBooks = 0;
		for (int i = 0; i < countHall; i++)
		{
			countBooks += listScientificHalls.get_addres_Node(i)->getCountBook();
		}
		return countBooks;
	}

	double getSumAllBooks()
	{
		double sumBooks = 0;
		for (int i = 0; i < countHall; i++)
		{
			sumBooks += listScientificHalls.get_addres_Node(i)->getSumAllBooks();
		}
		return sumBooks;
	}

	ScientificLibraryHall1& getHall(int numberHall) { return *this->listScientificHalls.get_addres_Node(numberHall); }


	ScientificBook& getBook(int numberBook)
	{
		int k = 0;
		for (int i = 0; i < countHall; i++) {
			ScientificLibraryHall1 hall = getHall(i);
			for (int j = 0; j < hall.getCountBook(); j++) {
				ScientificBook book = hall[j];
				if (k == numberBook) {
					return book;
				}
				k++;
			}
		}
	}

	void print()
	{
		for (int i = 0; i < getCountHalls(); i++) {
			std::cout << getHall(i).getNameHall() << " :" << getHall(i).getCountBook() << "\n";

		}
	}

	void replacementBook(int number, ScientificBook* newBook)
	{
		ScientificBook& Book = getBook(number);
		Book.setAuthor(newBook->getAuthor());
		Book.setTitle(newBook->getTitle());
		Book.setPrice(newBook->getPrice());
		Book.setYear(newBook->getYear());
		Book.setCitationRating(newBook->getCitationRating());
	}

	void addBook(int number, ScientificBook* book)
	{
		int k = 0;
		for (int i = 0; i < countHall; i++) {
			if (getHall(i).getCountBook() + k >= number) {
				getHall(i).addBook(book, number - k);
				return;
			}
			else {
				k += getHall(i).getCountBook();
			}
		}
	}

	void deleteBook(int number)
	{
		int k = 0;
		for (int i = 0; i < countHall; i++) {
			if (getHall(i).getCountBook() + k >= number) {
				getHall(i).deleteBook(number - k);
				return;
			}
			else {
				k += getHall(i).getCountBook();
			}
		}
	}

	ScientificLibraryHall1& operator[] (const int index);



	ScientificLibrary& operator= (const ScientificLibrary& drob)
	{
		this->countHall = drob.countHall;
		this->listScientificHalls = ListTest2<ScientificLibraryHall1>();
		Node2<ScientificLibraryHall1>* t = drob.listScientificHalls.head->next;
		for (int i = 0; i < drob.countHall; i++) {
			this->listScientificHalls.add_node(t->val, i);
			t = t->next;
		}
		return *this;
	}
};

//ScientificLibraryHall1& ScientificLibrary::operator[] (const int i) {
//	if (i<0 || i>  getCountHalls() - 1) {
//		std::cout << "\nIndex out-of-bounds.\n";  exit(1);
//	}
//	return  *this->listScientificHalls.get_addres_Node(i);
//}
