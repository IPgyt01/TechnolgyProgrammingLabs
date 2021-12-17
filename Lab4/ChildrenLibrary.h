#pragma once
#include "ChildrenLibraryHall.h";
#include "ILibrary.h"

class ChildrenLibrary : public ILibrary {
private:
	int countHall = 0;
	ChildrenLibraryHall* arrayHalls = nullptr;
public:
	ChildrenLibrary(int countHall, int* bookArray)
	{
		this->countHall = countHall;
		this->arrayHalls = new ChildrenLibraryHall[countHall];
		for (int i = 0; i < countHall; i++)
		{
			std::string text = "Hall #";
			arrayHalls[i] = ChildrenLibraryHall(text += std::to_string(i), bookArray[i]);
		}
	}

	ChildrenLibrary(ChildrenLibraryHall* arrayHalls, int countHall)
	{
		this->countHall = countHall;
		this->arrayHalls = arrayHalls;
	}

	ChildrenLibrary(const ChildrenLibrary& obj) : countHall(obj.countHall), arrayHalls(obj.arrayHalls)
	{
		this->arrayHalls = new ChildrenLibraryHall[obj.countHall];
		this->countHall = obj.countHall;
		for (int i = 0; i < obj.countHall; i++)
		{
			this->arrayHalls[i] = obj.arrayHalls[i];
		}
	}

	~ChildrenLibrary() { delete[] arrayHalls; }

	int getCountHalls() const override { return countHall; };

	int getCountBooks() const override
	{
		int countBooks = 0;
		for (int i = 0; i < countHall; i++)
		{
			countBooks += arrayHalls[i].getCountBook();
		}
		return countBooks;
	}

	double getSumAllBooks()
	{
		int sumBooks = 0;
		for (int i = 0; i < countHall; i++)
		{
			sumBooks += arrayHalls[i].getSumAllBooks();
		}
		return sumBooks;
	}

	ChildrenLibraryHall* getArrayLibraryHall() { return arrayHalls; }

	ChildrenLibraryHall& getHall(int numberHall) const override { return arrayHalls[numberHall]; }

	ChildrenBook& getBook(int numberBook) const override
	{
		int k = 0;
		for (int i = 0; i < countHall; i++) {
			ChildrenLibraryHall hall = getHall(i);
			for (int j = 0; j < hall.getCountBook(); j++) {
				ChildrenBook book = hall.getBook(j);
				if (k == numberBook) {
					return book;
				}
				k++;
			}
		}
	}

	void print()
	{
		for (int i = 0; i < countHall; i++) {
			std::cout << arrayHalls[i].getNameHall() << ":" << arrayHalls[i].getCountBook() << "\n";

		}

	}
	void replacementHall(int number, ChildrenLibraryHall& newHall)
	{
		this->arrayHalls[number].setNameHall(newHall.getNameHall());
		this->arrayHalls[number].setArrayBooks(new ChildrenBook[newHall.getCountBook()], newHall.getCountBook());
		for (int i = 0; i < newHall.getCountBook(); i++)
		{
			arrayHalls[number].getArrayBooks()[i] = newHall.getArrayBooks()[i];
		}
	}

	void replacementBook(int number, ChildrenBook& newBook)
	{
		ChildrenBook& Book = getBook(number);
		Book.setAuthor(newBook.getAuthor());
		Book.setTitle(newBook.getTitle());
		Book.setPrice(newBook.getPrice());
		Book.setYear(newBook.getYear());
		Book.setAge(newBook.getAge());
	}
	void addBook(int number, ChildrenBook book)
	{
		int k = 0;
		for (int i = 0; i < countHall; i++) {
			if (arrayHalls[i].getCountBook() + k >= number) {
				arrayHalls[i].addBook(number - k, book);
				return;
			}
			else {
				k += arrayHalls[i].getCountBook();
			}
		}
	}

	void deleteBook(int number)
	{
		int k = 0;
		for (int i = 0; i < countHall; i++) {
			if (arrayHalls[i].getCountBook() + k >= number) {
				arrayHalls[i].deleteBook(number - k);
				return;
			}
			else {
				k += arrayHalls[i].getCountBook();
			}
		}
	}
	ChildrenBook getBestBook() {
		ChildrenBook best = arrayHalls[0].getBestBook();
		for (int i = 1; i < countHall; i++) {
			if (best.getPrice() < arrayHalls[i].getBestBook().getPrice()) {
				best = arrayHalls[i].getBestBook();
			}
		}
		return best;
	}

	void write(std::ofstream& f) const override
	{
		f.write((char*)&countHall, sizeof countHall);
		for (int i = 0; i < getCountHalls(); i++) {
			f.write((char*)&arrayHalls[i], sizeof arrayHalls[i]);
		}
	}

	void read(std::ifstream& f) override
	{
		f.read((char*)&countHall, sizeof countHall);
		for (int i = 0; i < getCountHalls(); i++) {
			f.read((char*)&arrayHalls[i], sizeof arrayHalls[i]);
		}
	}

	friend std::ostream& operator<< (std::ostream& stream, ChildrenLibrary obj);
	friend std::istream& operator>> (std::istream& stream, ChildrenLibrary& obj);
};

std::ostream& operator<< (std::ostream& stream, ChildrenLibrary obj)
{
	for (int i = 0; i < obj.getCountHalls(); i++) {
		stream << obj.arrayHalls[i];
	}
	stream << obj.countHall << "\n";

	return stream;
}
std::istream& operator>> (std::istream& stream, ChildrenLibrary& obj)
{
	std::cout << "Enter countBooks,arrayHalls values: ";
	stream >> obj.countHall;
	for (int i = 0; i < obj.getCountHalls(); i++) {
		stream >> obj.arrayHalls[i];
	}

	return stream;
}
