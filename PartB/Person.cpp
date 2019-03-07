#include "Person.h"

Person::Person( const string name){
    head = NULL;
    this->name = name;
    numberOfPhones = 0;
}

Person::~Person(){
    while(head != NULL)
        removePhone(head->p.getAreaCode(), head->p.getNumber());
    numberOfPhones = 0;
}

Person::Person( const Person& personToCopy ){
    this->name = personToCopy.name;
    this->numberOfPhones = personToCopy.numberOfPhones;
    if(personToCopy.head == NULL)
        head = NULL;
    else {
        head = new PhoneNode;
        head->p = personToCopy.head->p;
        PhoneNode *newPtr = head;
        for (PhoneNode *origPtr = personToCopy.head->next;
                        origPtr != NULL;
                        origPtr = origPtr->next){
            newPtr->next = new PhoneNode;
            newPtr = newPtr->next;
            newPtr->p = origPtr->p;
        }
        newPtr->next = NULL;
    }
}

void Person::operator=( const Person &right ){
    if(&right != this){
        if( right.numberOfPhones < numberOfPhones){
            PhoneNode *deletePtr;
            for(int i = right.numberOfPhones; i < numberOfPhones; i++ ){
                deletePtr = head;
                head = head->next;
                deletePtr->next = NULL;
                delete deletePtr;
            }
        }
        if (right.head == NULL){
            numberOfPhones = right.numberOfPhones;
            head = NULL;
            name = right.name;
            return;
        }

        PhoneNode *newPtr = head;
        PhoneNode *origPtr = right.head;
        PhoneNode *left = head;
        if(right.numberOfPhones > numberOfPhones){
            newPtr = new PhoneNode;
            newPtr->p = origPtr->p;
            newPtr->next = head;
            head = newPtr;

            for(int i = numberOfPhones + 1; i < right.numberOfPhones; i++ ){
                newPtr->next = new PhoneNode;
                newPtr = newPtr->next;
                origPtr = origPtr->next;
                newPtr->p = origPtr->p;
                newPtr->next = left;
            }
        }

        if (origPtr == right.head){
            newPtr->p = origPtr->p;
        }

        while (origPtr->next != NULL){
            newPtr = newPtr->next;
            origPtr = origPtr->next;
            newPtr->p = origPtr->p;
        }
        numberOfPhones = right.numberOfPhones;
        name = right.name;
    }
}

string Person::getName(){
    return name;
}

int Person::getNumberOfPhones(){
    return numberOfPhones;
}

bool Person::addPhone( const int areaCode, const int number ){
    if(head != NULL) {
        if(findPhone(areaCode, number) != NULL)
            return false;

        PhoneNode *newPtr = new PhoneNode;
        Phone *newPhone= new Phone(areaCode, number);
        newPtr->p = *newPhone;
        newPtr->next = head;
        head = newPtr;
        numberOfPhones++;
        delete newPhone;
        return true;
    }
    else {
        Phone *newPhone = new Phone(areaCode, number);
        head = new PhoneNode;
        head->p = *newPhone;
        head->next = NULL;
        numberOfPhones++;
        delete newPhone;
        return true;
    }
    return false;
}

bool Person::removePhone( const int areaCode, const int number ){
    if (head == NULL)
        return false;

    PhoneNode *cur = head;
    if (cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number) {
        head = head->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
        numberOfPhones--;
        return true;
    }

    PhoneNode *prev;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
        if (cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number) {
            prev->next = cur->next;
            cur->next = NULL;
            delete cur;
            cur = NULL;
            numberOfPhones--;
            return true;
        }
    }
    return false;
}

void Person::displayPhoneNumbers(){
    if(head == NULL)
        cout << "--EMPTY--" << endl;
    else{
        PhoneNode *cur = head;
        cout << "Phone number: " << cur->p.getAreaCode() << ", " << cur->p.getNumber() << endl;
        while( cur->next != NULL) {
            cur = cur->next;
            cout << "Phone number: " << cur->p.getAreaCode() << ", " << cur->p.getNumber() << endl;
        }
    }
}

void Person::displayPhoneNumbersWithAreaCode( const int areaCode){
    if(head != NULL){
        PhoneNode *cur = head;
        if (cur->p.getAreaCode() == areaCode)
            cout << "Phone number: " << cur->p.getAreaCode() << ", " << cur->p.getNumber() << endl;
        while( cur->next != NULL) {
            cur = cur->next;
            if (cur->p.getAreaCode() == areaCode)
                cout << "Phone number: " << cur->p.getAreaCode() << ", " << cur->p.getNumber() << endl;
        }
    }
}

bool Person::isPersonHavePhoneNumberWithAreaCode( const int areaCode){
    if (head == NULL)
        return false;

    PhoneNode *cur = head;
    if (cur->p.getAreaCode() == areaCode)
        return true;

    while (cur->next != NULL){
        cur = cur->next;
        if (cur->p.getAreaCode() == areaCode)
            return true;
    }
    return false;
}

Person::PhoneNode* Person::findPhone( const int areaCode, const int number ){
    if (head == NULL)
        return NULL;

    PhoneNode *cur = head;
    if (cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number)
        return cur;

    while (cur->next != NULL){
        cur = cur->next;
        if (cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number)
            return cur;
    }
    return NULL;
}

