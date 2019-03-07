#include <iostream>
using namespace std;
#include "SimplePhoneBook.h"

int main(){
    PhoneBook book;
    book.displayPeople();
    book.addPerson("Munib");
    book.displayPeople();
    if (book.addPerson("Emre"))
        cout << "Successful insertion of Emre" << endl;
    else
        cout << "Unsuccessful insertion of Emre" << endl;
    book.displayPeople();

    if (book.addPerson("eMrE"))
        cout << "Successful insertion of eMrE" << endl;
    else
        cout << "Unsuccessful insertion of eMrE" << endl;
    book.displayPeople();

    if(book.removePerson("EmRe"))
        cout << "Successful deletion of EmRe" << endl;
    else
        cout << "Unsuccessful deletion of EmRe" << endl;
    book.displayPeople();

    if (book.addPerson("EMre"))
        cout << "Successful insertion of EMre" << endl;
    else
        cout << "Unsuccessful insertion of EMre" << endl;
    book.displayPeople();
    book.addPerson("Sevilgen");
    if (book.addPerson("Emre"))
        cout << "Successful insertion of Emre" << endl;
    else
        cout << "Unsuccessful insertion of Emre" << endl;
    book.addPerson("Fatih");
    book.addPerson("Erdogan");
    book.displayPeople();

    if(book.removePerson("Erdogan"))
        cout << "Successful deletion of Erdogan" << endl;
    else
        cout << "Unsuccessful deletion of Erdogan" << endl;
    book.displayPeople();
    PhoneBook test;

    test.addPerson("Rukiye");
    test.displayPeople();

    if(test.removePerson("Rukiye"))
        cout << "Successful deletion of Rukiye" << endl;
    else
        cout << "Unsuccessful deletion of Rukiye" << endl;
    test.displayPeople();

    test.addPerson("Muhammed");
    test.addPerson("Akif");
    test.displayPeople();

    test = book;
    test.displayPeople();

    PhoneBook* test2 = new PhoneBook(book);
    (*test2).displayPeople();
    delete test2;

    PhoneBook test3;
    test3.addPerson("Sevgen");
    test3.addPerson("Emre");
    test3.addPerson("Fatih");
    test3.addPerson("Erdogan");
    test3.addPerson("Rukiye");
    test3.addPerson("Akif");

    cout << "test3:" << endl;
    test3.displayPeople();
    cout << "test:" << endl;
    test.displayPeople();
    test3 = test;
    cout << "test3:" << endl;
    test3.displayPeople();


    return 0;
}
