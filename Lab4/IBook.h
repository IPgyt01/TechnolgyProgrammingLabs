#pragma once
#include <string>;
#include <fstream>
class IBook
{
public:
    virtual std::string getAuthor() const;
    virtual std::string getTitle() const;
    virtual double getPrice() const;
    virtual int getYear() const;

    virtual void setAuthor(std::string aut);
    virtual void setTitle(std::string nm);
    virtual void setPrice(double pr);
    virtual void setYear(int yy);

    virtual void write(std::ofstream& f) const;
    virtual void read(std::ifstream& f);
};
