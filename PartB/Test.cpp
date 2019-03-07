#include <iostream>
using namespace std;
#include "PhoneBook.h"

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

    book.addPhone("emre", 10, 1);
    book.addPhone("emre", 10, 2);
    book.addPhone("emre", 20, 1);
    book.addPhone("emre", 20, 2);
    book.addPhone("emre", 20, 3);

    if(book.removePerson("Erdogan"))
        cout << "Successful deletion of Erdogan" << endl;
    else
        cout << "Unsuccessful deletion of Erdogan" << endl;
    book.displayPeople();

    book.addPhone("fatih", 10, 4);
    book.addPhone("fatih", 10, 5);
    book.addPhone("fatih", 20, 1);
    book.addPhone("fatih", 20, 2);
    book.addPhone("fatih", 20, 6);

    if(book.addPhone("Erdogan", 1, 1))
        cout << "Successful addition of 1 , 1 to Erdogan" << endl;
    else
        cout << "Unsuccessful addition of 1 , 1 to Erdogan" << endl;

    if(book.addPhone("emre", 10, 1))
        cout << "Successful addition of 10 , 1 to emre" << endl;
    else
        cout << "Unsuccessful addition of 1 , 1 to emre" << endl;

    if(book.removePhone("emre", 10, 1))
        cout << "Successful deletion of 10 , 1 to emre" << endl;
    else
        cout << "Unsuccessful deletion of 1 , 1 to emre" << endl;

    book.displayPeople();

    cout << endl;

    book.displayPerson("eMre");
    book.displayPerson("muNib");
    book.displayPerson("erdoGan");
    book.displayPerson("fAtih");

    book.displayAreaCode(10);
    book.displayAreaCode(20);

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

    test.displayPerson("munib");
    test.displayPerson("emrE");
    test.displayPerson("seVilgen");
    test.displayPerson("fAtih");

    test.displayAreaCode(10);
    test.displayAreaCode(20);

    PhoneBook* test2 = new PhoneBook(book);
    (*test2).displayPeople();

    (*test2).displayPerson("munib");
    (*test2).displayPerson("emrE");
    (*test2).displayPerson("seVilgen");
    (*test2).displayPerson("fAtih");

    (*test2).displayAreaCode(10);
    (*test2).displayAreaCode(20);
    (*test2).displayAreaCode(30);

    (*test2).removePerson("Munib");
    (*test2).removePerson("eMrE");
    (*test2).removePerson("SeviLgen");
    (*test2).removePerson("faTiH");
    (*test2).displayPeople();

    PhoneBook a;
    PhoneBook b;

    a = b;
    cout << "--------";
    a.displayPeople();
    cout << "--------";

    b.addPerson("hello");
    b.addPhone("HEllo", 1, 1);

    a = b;
    a.displayPeople();
    cout << "--------";
    b.removePerson("Hello");
    a = b;
    a.displayPeople();
    cout << "--------";

    a.addPerson("1");
    a.addPhone("1",1,1);
    a.addPerson("2");
    a.addPhone("2",2,2);
    a.addPhone("2",2,22);
    b.addPerson("3");
    b.addPhone("3",3,3);
    b.addPhone("3",3,33);
    b.addPhone("3",3,333);
    b.addPerson("4");
    b.addPhone("4",4,4);
    b.addPhone("4",4,44);
    b.addPhone("4",4,444);
    b.addPhone("4",4,4444);
    b.addPerson("5");
    b.addPhone("5",5,5);
    b.addPhone("5",5,55);
    b.addPhone("5",5,555);
    b.addPhone("5",5,5555);
    b.addPhone("5",5,55555);
    a = b;
    a.displayPeople();
    cout << "--------";

    a.addPerson("1");
    a.addPhone("1", 1, 1);
    a = b;
    a.displayPeople();
    cout << "-----aa---\n";
    a.displayAreaCode(5);
    cout << "--------";

    a.removePerson("1");
    a.removePerson("2");
    a.removePerson("3");
    a.removePerson("4");
    a.removePerson("5");

    a.addPerson("6");
    a.addPerson("7");
    a.addPerson("8");
    a.addPerson("9");
    a.addPerson("10");
    a.displayPeople();
    cout << "--------";
    a = b;
    a.displayPeople();




    delete test2;
    return 0;
}

