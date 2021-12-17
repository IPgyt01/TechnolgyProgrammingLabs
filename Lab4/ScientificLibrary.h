#pragma once
#include "ScientificLibraryHall.h";
#include "ILibrary.h"
#include "../Lab3/List2.h"

class ScientificLibrary : public ILibrary {
private:
	int countHall = 0;
	ListTest2<ScientificLibraryHall> listScientificHalls;
public:
	ScientificLibrary(int countHall, int* bookArray)
	{
		this->countHall = countHall;
		for (int i = 0; i < countHall; i++)
		{
			std::string text = "Hall#";
			this->listScientificHalls.add_node(new ScientificLibraryHall(text += std::to_string(i), bookArray[i]), i);
		}
	}

	ScientificLibrary(ScientificLibraryHall* arrayHalls[], int countHall)
	{
		for (int i = 0; i < countHall; i++) {
			this->listScientificHalls.add_node(arrayHalls[i], this->countHall);
			this->countHall++;
		}
	}

	ScientificLibrary(const ScientificLibrary& obj)
	{
		this->listScientificHalls = ListTest2<ScientificLibraryHall>();
		Node2<ScientificLibraryHall>* t = obj.listScientificHalls.head->next;
		for (int i = 0; i < obj.countHall; i++) {
			this->listScientificHalls.add_node(t->val, i);
			t = t->next;
		}
	}

	int getCountHalls() const override { return countHall; };

	int getCountBooks() const override
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

	ScientificLibraryHall& getHall(int numberHall) const override { return *this->listScientificHalls.get_addres_Node(numberHall); }

	ScientificBook& getBook(int numberBook) const override
	{
		int k = 0;
		for (int i = 0; i < countHall; i++) {
			ScientificLibraryHall hall = getHall(i);
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
				getHall(i).addBook(number - k, book);
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

	ScientificLibraryHall& operator[] (const int index);

	ScientificLibrary& operator= (const ScientificLibrary& drob)
	{
		this->countHall = drob.countHall;
		this->listScientificHalls = ListTest2<ScientificLibraryHall>();
		Node2<ScientificLibraryHall>* t = drob.listScientificHalls.head->next;
		for (int i = 0; i < drob.countHall; i++) {
			this->listScientificHalls.add_node(t->val, i);
			t = t->next;
		}
		return *this;
	}

	void write(std::ofstream& f) const override
	{
		f.write((char*)&countHall, sizeof countHall);
		for (int i = 0; i < getCountHalls(); i++) {
			f.write((char*)&listScientificHalls.get_addres_Node(i), sizeof * listScientificHalls.get_addres_Node(i));
		}
	}

	void read(std::ifstream& f) override
	{
		f.read((char*)&countHall, sizeof countHall);
		listScientificHalls = ListTest2<ScientificLibraryHall>();
		Node2<ScientificLibraryHall>* t = listScientificHalls.head->next;
		for (int i = 0; i < countHall; i++) {
			listScientificHalls.add_node(t->val, i);
			f.read((char*)&listScientificHalls, sizeof listScientificHalls.add_node(t->val, i));
			t = t->next;
		}
	}

	friend std::ostream& operator<< (std::ostream& stream, ScientificLibrary obj);
	friend std::istream& operator>> (std::istream& stream, ScientificLibrary& obj);
};

ScientificLibraryHall& ScientificLibrary::operator[] (const int i) {
	if (i<0 || i>  getCountHalls() - 1) {
		std::cout << "\nIndex out-of-bounds.\n";  exit(1);
	}
	return  *this->listScientificHalls.get_addres_Node(i);
}

std::ostream& operator<< (std::ostream& stream, ScientificLibrary obj)
{
	for (int i = 0; i < obj.getCountHalls(); i++) {
		stream << obj.listScientificHalls.get_addres_Node(i);
	}
	stream << obj.countHall << "\n";

	return stream;
}
std::istream& operator>> (std::istream& stream, ScientificLibrary& obj)
{
	std::cout << "Enter countBooks,listScientificHalls values: ";
	stream >> obj.countHall;
	obj.listScientificHalls = ListTest2<ScientificLibraryHall>();
	Node2<ScientificLibraryHall>* t = obj.listScientificHalls.head->next;
	for (int i = 0; i < obj.countHall; i++) {
		obj.listScientificHalls.add_node(t->val, i);
		t = t->next;
	}
	for (int i = 0; i < obj.getCountHalls(); i++) {
		stream >> *obj.listScientificHalls.get_addres_Node(i);
	}
	return stream;
}
