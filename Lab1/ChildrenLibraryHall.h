#pragma once
#include "ChildrenBook.h";
#include <iostream>
class ChildrenLibraryHall {
private:
	std::string nameHall;
	int countBooks = 0;
	ChildrenBook* arrayBooks = nullptr;
public:
	void setNameHall(std::string nameHall) { this->nameHall = nameHall; };
	std::string getNameHall() { return this->nameHall; };
	ChildrenBook* getArrayBooks() { return this->arrayBooks; };
	void setArrayBooks(ChildrenBook* arrayBooks, int size)
	{
		this->countBooks = size;
		this->arrayBooks = arrayBooks;
	};
	ChildrenLibraryHall() {}
	ChildrenLibraryHall(std::string nameHall, int countBooks)
	{
		this->nameHall = nameHall;
		this->countBooks = countBooks;
		this->arrayBooks = new ChildrenBook[countBooks];
		for (int i = 0; i < countBooks; i++) {
			std::string text = "Author #";
			this->arrayBooks[i] = ChildrenBook(text += std::to_string(i), 1970 + i);
		}
	}
	~ChildrenLibraryHall()
	{
		delete[] arrayBooks;
	}
	ChildrenLibraryHall(std::string nameHall, ChildrenBook* arrayBooks)
	{
		this->nameHall = nameHall;
		this->arrayBooks = arrayBooks;
	}
	ChildrenLibraryHall(const ChildrenLibraryHall& obj)
	{
		this->arrayBooks = new ChildrenBook[obj.countBooks];
		this->nameHall = obj.nameHall;
		for (int i = 0; i < obj.countBooks; i++)
		{
			this->arrayBooks[i] = obj.arrayBooks[i];
		}
	}
	int getCountBook()
	{
		return this->countBooks;
	}
	void printBooks()
	{
		std::cout << "\n" << getNameHall() << +":";
		for (int i = 0; i < countBooks; i++)
		{
			std::cout << "\n" << i << ":" << arrayBooks[i].getAuthor();
		}
	}
	double getSumAllBooks()
	{
		double test = 0;
		for (int i = 0; i < countBooks; i++)
		{
			test += arrayBooks[i].getPrice();
		}
		return test;
	};
	ChildrenBook getBook(int numberBook)
	{
		return arrayBooks[numberBook];
	};
	void replacementBook(int numberBook, ChildrenBook childrenBook)
	{
		arrayBooks[numberBook] = childrenBook;
	};
	void addBook(int number, ChildrenBook childrenBook)
	{
		this->countBooks += 1;
		ChildrenBook* copy = new ChildrenBook[countBooks];
		for (int i = 0; i < number; i++) {
			copy[i] = arrayBooks[i];
		}
		copy[number] = childrenBook;
		for (int i = number + 1; i < countBooks; i++) {
			copy[i] = arrayBooks[i - 1];
		}
		delete[] arrayBooks;
		this->arrayBooks = copy;
	};
	void deleteBook(int numberBook)
	{
		ChildrenBook* copy = new ChildrenBook[countBooks - 1];
		for (int i = 0; i < numberBook; i++) {
			copy[i] = arrayBooks[i];
		}
		for (int i = numberBook; i < countBooks - 1; i++) {
			copy[i] = arrayBooks[i + 1];
		}
		countBooks--;
		delete[] arrayBooks;
		this->arrayBooks = copy;
	};
	ChildrenBook getBestBook() {
		ChildrenBook best = arrayBooks[0];
		for (int i = 1; i < countBooks; i++) {
			if (arrayBooks[i].getPrice() > best.getPrice()) {
				best = arrayBooks[i];
			}
		}
		return best;
	}
};
