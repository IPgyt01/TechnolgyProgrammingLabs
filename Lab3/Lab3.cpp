#include "ScientificLibrary.h";
#include <iostream>
#include "../Lab2/ScientificLibraryHall.h"
#include "../Lab1/ChildrenBook.h"
#include "../Lab1/ChildrenLibraryHall.h"

int main()
{
    setlocale(0, "");

    ScientificLibraryHall1* hall1 = new ScientificLibraryHall1("ЗАЛ 3-ЕЙ ЛАБЫ", 5);
    ScientificBook* a1 = new ScientificBook();
    ScientificBook* b1 = new ScientificBook("Пушкин", "Евгений Онегин", 99, 2002, 18.8);
    ScientificBook* c1 = new ScientificBook("Оксимирон", "ГОРГОРОД", 9999, 2002, 18.8);
    ScientificBook* d1 = new ScientificBook("ИЛЮХА ТЫГАНОВ", "Записки сумасшедшего", 299, 2002, 18.8);

    hall1->addBook(b1, 1);
    hall1->addBook(c1, 2);
    hall1->addBook(d1, 7);
    hall1->addBook(a1, 3);


    ScientificLibraryHall1* hall2 = new ScientificLibraryHall1("ЗАЛ 2-ОЙ ЛАБЫ", 5);
    ScientificBook* a = new ScientificBook();
    ScientificBook* b = new ScientificBook("Пушкин", "Евгений Онегин", 99, 2002, 18.8);
    ScientificBook* c = new ScientificBook("Оксимирон", "ГОРГОРОД", 9999, 2002, 18.8);
    ScientificBook* d = new ScientificBook("ИЛЮХА ТЫГАНОВ", "Записки сумасшедшего", 299, 2002, 18.8);

    hall2->addBook(b, 1);
    hall2->addBook(c, 2);
    hall2->addBook(d, 7);

    ScientificLibraryHall1* array[] = { hall1, hall2 };
    ScientificLibrary* sl = new ScientificLibrary(array, 2);
    sl->print();
    std::cout << "\n" << "количество залов в библиотеке:";
    std::cout << "\n" << sl->getCountHalls();
    std::cout << "\n" << "\n" << "количество книг в библиотеке:";
    std::cout << "\n" << sl->getCountBooks();
    std::cout << "\n" << "\n" << "сумма всех книг в библиотеке:";
    std::cout << "\n" << sl->getSumAllBooks();

}
