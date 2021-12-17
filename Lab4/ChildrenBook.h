#pragma once
#include <string>;
#include "IBook.h"
#include <fstream>
#include <iostream>
class ChildrenBook : public IBook {
private:
	std::string author;
	std::string title;
	double price;
	int year;
	int age;

public:
	void setAuthor(std::string author) override { this->author = author; }

	void setTitle(std::string title) override { this->title = title; }

	void setPrice(double  price) override { this->price = price; }

	void setYear(int year) override { this->year = year; }

	void setAge(int age) { this->age = age; }

	std::string getAuthor() const override { return this->author; }

	std::string getTitle() const override { return this->title; }

	double getPrice() const override { return this->price; }

	int getYear() const override { return this->year; }

	int getAge() { return this->age; }

	ChildrenBook() : author("Не определено"), title("Не определено"), price(0.0), year(0), age(0) {}

	ChildrenBook(std::string author, std::string title, double  price, int year, int age)
		: author(author), title(title), price(price), year(year), age(age) {}



	ChildrenBook(std::string author, int year) : ChildrenBook()
	{
		this->author = author;
		this->year = year;
	}
	void write(std::ofstream& f) const override
	{
		f.write((char*)&author, sizeof author);
		f.write((char*)&title, sizeof title);
		f.write((char*)&price, sizeof price);
		f.write((char*)&year, sizeof year);
		f.write((char*)&age, sizeof age);
	}
	void read(std::ifstream& f) override
	{
		f.read((char*)&author, sizeof author);
		f.read((char*)&title, sizeof title);
		f.read((char*)&price, sizeof price);
		f.read((char*)&year, sizeof year);
		f.read((char*)&age, sizeof age);
	}
	friend std::ostream& operator<< (std::ostream& stream, ChildrenBook obj);
	friend std::istream& operator>> (std::istream& stream, ChildrenBook& obj);
};
std::ostream& operator<< (std::ostream& stream, ChildrenBook obj)
{
	stream << obj.author << ", ";
	stream << obj.title << ", ";
	stream << obj.price << ", ";
	stream << obj.year << ", ";
	stream << obj.age << "\n";
	return stream;
}
std::istream& operator>> (std::istream& stream, ChildrenBook& obj)
{
	std::cout << "Enter author,title,price,year,age values: ";
	stream >> obj.author;
	stream >> obj.title;
	stream >> obj.price;
	stream >> obj.year;
	stream >> obj.age;

	return stream;
}
