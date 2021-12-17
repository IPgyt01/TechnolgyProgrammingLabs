#pragma once
#include <string>;
#include "IBook.h"
#include <fstream>
#include <iostream>

class ScientificBook : public IBook {
private:
	std::string author;
	std::string title;
	double price;
	int year;
	double citationRating;
public:
	void setAuthor(std::string author) override { this->author = author; }

	void setTitle(std::string title) override { this->title = title; }
	void setPrice(double  price) override { this->price = price; }

	void setYear(int year) override { this->year = year; }

	void setCitationRating(double age) { this->citationRating = age; }

	std::string getAuthor() const override { return this->author; }

	std::string getTitle() const override { return this->title; }

	double getPrice() const override { return this->price; }

	int getYear() const override { return this->year; }

	double getCitationRating() { return this->citationRating; }

	ScientificBook() : author("Не определено"), title("Не определено"), price(0.0), year(0), citationRating(0) {}

	ScientificBook(std::string author, std::string title, double  price, int year, double citationRating)
		: author(author), title(title), price(price), year(year), citationRating(citationRating) {}

	ScientificBook(std::string author, int year) : ScientificBook()
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
		f.write((char*)&citationRating, sizeof citationRating);
	}
	void read(std::ifstream& f) override
	{
		f.read((char*)&author, sizeof author);
		f.read((char*)&title, sizeof title);
		f.read((char*)&price, sizeof price);
		f.read((char*)&year, sizeof year);
		f.read((char*)&citationRating, sizeof citationRating);
	}
	friend std::ostream& operator<< (std::ostream& stream, ScientificBook obj);
	friend std::istream& operator>> (std::istream& stream, ScientificBook& obj);
};
std::ostream& operator<< (std::ostream& stream, ScientificBook obj)
{
	stream << obj.author << ", ";
	stream << obj.title << ", ";
	stream << obj.price << ", ";
	stream << obj.year << ", ";
	stream << obj.citationRating << "\n";
	return stream;
}
std::istream& operator>> (std::istream& stream, ScientificBook& obj)
{
	std::cout << "Enter author,title,price,year,citationRating values: ";
	stream >> obj.author;
	stream >> obj.title;
	stream >> obj.price;
	stream >> obj.year;
	stream >> obj.citationRating;

	return stream;
}
