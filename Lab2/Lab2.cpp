#include "ScientificLibraryHall.h";
#include <iostream>

int main()
{
    setlocale(0, "");

    ScientificLibraryHall1* hall = new ScientificLibraryHall1("ЗАЛ 2-ОЙ ЛАБЫ", 5);
    ScientificBook* a = new ScientificBook();
    ScientificBook* b = new ScientificBook("Пушкин", "Евгений Онегин", 99, 2002, 18.8);
    ScientificBook* c = new ScientificBook("Оксимирон", "ГОРГОРОД", 9999, 2002, 18.8);
    ScientificBook* d = new ScientificBook("ИЛЮХА ТЫГАНОВ", "Записки сумасшедшего", 299, 2002, 18.8);

    hall->addBook(b, 1);
    hall->addBook(c, 2);
    hall->addBook(d, 7);

    hall->printBooks();
    std::cout << "\n" << "\n" << "Добавление книги в начало списка";
    hall->addBook(a, 0);
    hall->printBooks();

    std::cout << "\n" << "\n" << "Добавление книги в конец списка";
    hall->addBook(d, 8);
    hall->printBooks();

    std::cout << "\n" << "\n" << "Удаление последней книги";
    hall->deleteBook(8);
    hall->printBooks();

    std::cout << "\n" << "\n" << "Удаление первой книги";
    hall->deleteBook(0);
    hall->printBooks();

    std::cout << "\n" << "\n" << "Автор самой лучшей книги: ";
    std::cout << hall->getBestBook().getAuthor();

    std::cout << "\n" << "Сумма всех книг :";
    hall->deleteBook(5);
    std::cout << hall->getSumAllBooks();
    std::cout << "\n" << "\n";
    return 0;
}


