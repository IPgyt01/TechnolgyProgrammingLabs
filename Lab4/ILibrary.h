#pragma once
#include <string>;
#include <fstream>
#include "IBook.h"
#include "IHall.h"
class ILibrary
{
public:
    virtual int getCountHalls() const;
    virtual int getCountBooks() const;
    virtual IHall& getHall(int ind) const;
    virtual IBook& getBook(int ind) const;
    virtual void write(std::ofstream& f) const;
    virtual void read(std::ifstream& f);
};
