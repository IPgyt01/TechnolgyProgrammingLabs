#pragma once
#include <string>;
#include <fstream>
#include "IBook.h"

class IHall
{
public:
    virtual int getCountBook() const;
    virtual void printBooks();
    virtual IBook& getBook(int ind) const;
    virtual void replacementBook(int ind, IBook newBook);
    virtual void addBook(int ind, IBook newBook);
    virtual void deleteBook(int ind);
    virtual void write(std::ofstream& f);
    virtual void read(std::ifstream& f);
};
