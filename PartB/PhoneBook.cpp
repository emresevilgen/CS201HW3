#include "PhoneBook.h"

PhoneBook::PhoneBook(){
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook(){
    while(head != NULL)
        removePerson(head->t.getName());
}

PhoneBook::PhoneBook( const PhoneBook& systemToCopy ){
    numberOfPeople = systemToCopy.numberOfPeople;
    if(systemToCopy.head == NULL)
        head = NULL;
    else {
        head = new Node;
        head->t = systemToCopy.head->t;
        Node *newPtr = head;
        for (Node *origPtr = systemToCopy.head->next;
                        origPtr != NULL;
                        origPtr = origPtr->next){
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
    }
}

void PhoneBook::operator=( const PhoneBook &right ){
    if(&right != this){
        if( right.numberOfPeople < numberOfPeople){
            Node *deletePtr;
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

        Node *newPtr = head;
        Node *origPtr = right.head;
        Node *left = head;
        if(right.numberOfPeople > numberOfPeople){
            newPtr = new Node;
            newPtr->t = origPtr->t;
            newPtr->next = head;
            head = newPtr;

            for(int i = numberOfPeople + 1; i < right.numberOfPeople; i++ ){
                newPtr->next = new Node;
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

bool PhoneBook::addPerson( string name ){
    if(numberOfPeople > 0) {
        if(findPerson(name) != NULL)
            return false;

        numberOfPeople++;
        Node *newPtr = new Node;
        Person *newPerson = new Person(name);
        newPtr->t = *newPerson;
        newPtr->next = head;
        head = newPtr;
        delete newPerson;
        return true;
    }
    else {
        Person *newPerson = new Person(name);
        head = new Node;
        numberOfPeople++;
        head->t = *newPerson;
        head->next = NULL;
        delete newPerson;
        return true;
    }
    return false;
}

bool PhoneBook::removePerson( string name ){
    if (name == "" || head == NULL)
        return false;

    Node *cur = head;
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

    Node *prev;
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

bool PhoneBook::addPhone( string personName, int areaCode, int number ){
    Node *cur = findPerson(personName);
    if (cur == NULL)
        return false;

    return cur->t.addPhone( areaCode, number);
}

bool PhoneBook::removePhone( string personName, int areaCode, int number ){
    Node *cur = findPerson(personName);
    if (cur == NULL)
        return false;

    return cur->t.removePhone(areaCode, number);
}

void PhoneBook::displayPerson( string name ){
    Node *cur = findPerson(name);
    if (cur == NULL) {
        cout << name << endl;
        cout << "--EMPTY--" << endl;
    }
    else {
        cout << cur->t.getName() << endl;
        cur->t.displayPhoneNumbers();
    }
}

void PhoneBook::displayAreaCode( int areaCode ){
    cout << areaCode << endl;
    if(head == NULL)
        cout << "--EMPTY--" << endl;
    else{
        bool check = false;
        Node *cur = head;
        if (cur->t.isPersonHavePhoneNumberWithAreaCode(areaCode)) {
            cout << cur->t.getName() << endl;
            cur->t.displayPhoneNumbersWithAreaCode( areaCode);
            cout << endl;
            check = true;
        }
        while( cur->next != NULL) {
            cur = cur->next;
            if (cur->t.isPersonHavePhoneNumberWithAreaCode(areaCode)) {
                cout << cur->t.getName() << endl;
                cur->t.displayPhoneNumbersWithAreaCode( areaCode);
                cout << endl;
                check = true;
            }
        }
        if (!check)
            cout << "--EMPTY--" << endl;
    }
}

void PhoneBook::displayPeople(){
    if(numberOfPeople < 1)
        cout << "--EMPTY--" << endl;
    else{
        Node *cur = head;
        cout << cur->t.getName() << ", " << cur->t.getNumberOfPhones() << endl;
        while( cur->next != NULL) {
            cur = cur->next;
            cout << cur->t.getName() << ", " << cur->t.getNumberOfPhones() << endl;
        }
    }
}

PhoneBook::Node* PhoneBook::findPerson( string name ){
    if (name == "" || head == NULL)
        return NULL;

    Node *cur = head;
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

