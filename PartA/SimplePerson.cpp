#include "SimplePerson.h"

Person::Person( const string name) {
    this->name = name;
}

Person::~Person(){}

Person::Person( const Person &personToCopy ) {
    name = personToCopy.name;
}

void Person::operator=( const Person &right ){
    name = right.name;
}

string Person::getName(){
    return name;
}

