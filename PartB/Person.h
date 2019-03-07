#ifndef __PERSON_H
#define __PERSON_H
#include <string>
#include <iostream>
using namespace std;
#include "Phone.h"

class Person{
public:
    Person( const string name = "" );
    ~Person();
    Person( const Person& personToCopy );
    void operator=( const Person &right );
    string getName();
    int getNumberOfPhones();
    bool addPhone( const int areaCode, const int number );
    bool removePhone( const int areaCode, const int number );
    void displayPhoneNumbers();
    void displayPhoneNumbersWithAreaCode( const int areaCode );
    bool isPersonHavePhoneNumberWithAreaCode( const int areaCode );

private:
    struct PhoneNode {
        Phone p;
        PhoneNode* next;
    };
    PhoneNode *head;
    string name;
    int numberOfPhones;
    PhoneNode* findPhone( const int areaCode, const int number );
};
#endif
