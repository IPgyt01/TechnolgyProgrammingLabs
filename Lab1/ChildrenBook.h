#pragma once
#include <string>;
#include <iostream>
class ChildrenBook {
private:
	std::string author;
	std::string title;
	double price;
	int year;
	int age;
public:
	void setAuthor(std::string author) { this->author = author; }
	void setTitle(std::string title) { this->title = title; }
	void setPrice(double price) { this->price = price; }
	void setYear(int year) { this->year = year; }
	void setAge(int age) { this->age = age; }
	std::string getAuthor() { return this->author; }
	std::string getTitle() { return this->title; }
	double getPrice() { return this->price; }
	int getYear() { return this->year; }
	int getAge() { return this->age; }
	ChildrenBook() : author("Не определено"), title("Не определено"), price(0.0), year(0), age(0) {}
	ChildrenBook(std::string author, std::string title, double price, int year, int age)
		: author(author), title(title), price(price), year(year), age(age) {}
	ChildrenBook(std::string author, int year) : ChildrenBook()
	{
		this->author = author;
		this->year = year;
	}
};
