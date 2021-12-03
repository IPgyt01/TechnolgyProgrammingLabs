#pragma once
#include <string>;
class ScientificBook {
private:
	std::string author;
	std::string title;
	double price;
	int year;
	double citationRating;
public:
	void setAuthor(std::string author) { this->author = author; }
	void setTitle(std::string title) { this->title = title; }
	void setPrice(double  price) { this->price = price; }
	void setYear(int year) { this->year = year; }
	void setCitationRating(double age) { this->citationRating = age; }
	std::string getAuthor() { return this->author; }
	std::string getTitle() { return this->title; }
	double getPrice() { return this->price; }
	int getYear() { return this->year; }
	double getCitationRating() { return this->citationRating; }
	ScientificBook() : author("Не определено"), title("Не определено"), price(0.0), year(0), citationRating(0) {}
	ScientificBook(std::string author, std::string title, double  price, int year, double citationRating)
		: author(author), title(title), price(price), year(year), citationRating(citationRating) {}
	ScientificBook(std::string author, int year) : ScientificBook()
	{
		this->author = author;
		this->year = year;
	}
};
