#include "SimplePhoneBook.h"

PhoneBook::PhoneBook(){
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook(){
    while(head != NULL)
        removePerson(head->t.getName());
}

PhoneBook::PhoneBook(const PhoneBook& phoneBookToCopy){
    numberOfPeople = phoneBookToCopy.numberOfPeople;
    if(phoneBookToCopy.head == NULL)
        head = NULL;
    else {
        head = new PersonNode;
        head->t = phoneBookToCopy.head->t;
        PersonNode *newPtr = head;
        for (PersonNode *origPtr = phoneBookToCopy.head->next;
                        origPtr != NULL;
                        origPtr = origPtr->next){
            newPtr->next = new PersonNode;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
    }
}

void PhoneBook::operator=(const PhoneBook& right){
    if(&right != this){
        if( right.numberOfPeople < numberOfPeople){
            PersonNode *deletePtr;
            for(int i = right.numberOfPeople; i < numberOfPeople; i++ ){
                deletePtr = head;
                head = head->next;
                deletePtr->next = NULL;
                delete deletePtr;
            }
        }
        if (right.head == NULL){
            numberOfPeople = right.numberOfPeople;
            head = NULL;
            return;
        }

        PersonNode *newPtr = head;
        PersonNode *origPtr = right.head;
        PersonNode *left = head;
        if(right.numberOfPeople > numberOfPeople){
            newPtr = new PersonNode;
            newPtr->t = origPtr->t;
            newPtr->next = head;
            head = newPtr;

            for(int i = numberOfPeople + 1; i < right.numberOfPeople; i++ ){
                newPtr->next = new PersonNode;
                newPtr = newPtr->next;
                origPtr = origPtr->next;
                newPtr->t = origPtr->t;
                newPtr->next = left;
            }
        }

        if (origPtr == right.head){
            newPtr->t = origPtr->t;
        }

        while (origPtr->next != NULL){
            newPtr = newPtr->next;
            origPtr = origPtr->next;
            newPtr->t = origPtr->t;
        }
        numberOfPeople = right.numberOfPeople;
    }
}

bool PhoneBook::addPerson(const string name){
    if(numberOfPeople > 0) {
        if(findPerson(name) != NULL)
            return false;

        numberOfPeople++;
        PersonNode *newPtr = new PersonNode;
        Person *newPerson = new Person(name);
        newPtr->t = *newPerson;
        newPtr->next = head;
        head = newPtr;
        delete newPerson;
        return true;
    }
    else {
        Person *newPerson = new Person(name);
        head = new PersonNode;
        numberOfPeople++;
        head->t = *newPerson;
        head->next = NULL;
        delete newPerson;
        return true;
    }
    return false;
}

bool PhoneBook::removePerson(const string name){
    if (name == "" || head == NULL)
        return false;

    PersonNode *cur = head;
    bool check = true;
    if (name.length() != cur->t.getName().length())
        check = false;
    else {
        int length = name.length();
        string first = name;
        string second = cur->t.getName();
        char firstChar;
        char secondChar;
        for(int i = 0; i < length; i++){
            firstChar = first[i];
            secondChar = second[i];
            firstChar = toupper(firstChar);
            secondChar = toupper(secondChar);
            if (firstChar != secondChar)
                check = false;
        }
    }

    if (check) {
        head = head->next;
        numberOfPeople--;
        cur->next = NULL;
        delete cur;
        cur = NULL;
        return true;
    }

    PersonNode *prev;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
        bool check = true;
        if (name.length() != cur->t.getName().length())
            check = false;
        else {
            int length = name.length();
            string first = name;
            string second = cur->t.getName();
            char firstChar;
            char secondChar;
            for(int i = 0; i < length; i++){
                firstChar = first[i];
                secondChar = second[i];
                firstChar = toupper(firstChar);
                secondChar = toupper(secondChar);
                if (firstChar != secondChar)
                    check = false;
            }
        }
        if (check) {
            prev->next = cur->next;
            numberOfPeople--;
            cur->next = NULL;
            delete cur;
            cur = NULL;
            return true;
        }
    }
    return false;
}

void PhoneBook::displayPeople(){
    if(numberOfPeople < 1)
        cout << "--EMPTY--" << endl;
    else{
        PersonNode *cur = head;
        cout << cur->t.getName() << endl;
        while( cur->next != NULL) {
            cur = cur->next;
            cout << cur->t.getName() << endl;
        }
    }
}

PhoneBook::PersonNode* PhoneBook::findPerson(string name){
    if (name == "" || head == NULL)
        return NULL;

    PersonNode *cur = head;
    bool check = true;
    if (name.length() != cur->t.getName().length())
        check = false;
    else {
        int length = name.length();
        string first = name;
        string second = cur->t.getName();
        char firstChar;
        char secondChar;
        for(int i = 0; i < length; i++){
            firstChar = first[i];
            secondChar = second[i];
            firstChar = toupper(firstChar);
            secondChar = toupper(secondChar);
            if (firstChar != secondChar)
                check = false;
        }
    }
    if (check)
        return cur;

    while (cur->next != NULL){
        cur = cur->next;
        bool check = true;
        if (name.length() != cur->t.getName().length())
            check = false;
        else {
            int length = name.length();
            string first = name;
            string second = cur->t.getName();
            char firstChar;
            char secondChar;
            for(int i = 0; i < length; i++){
                firstChar = first[i];
                secondChar = second[i];
                firstChar = toupper(firstChar);
                secondChar = toupper(secondChar);
                if (firstChar != secondChar)
                    check = false;
            }
        }
        if (check)
            return cur;
    }
    return NULL;
}


