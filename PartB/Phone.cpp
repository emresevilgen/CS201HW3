#include "Phone.h"

Phone::Phone(){
    areaCode = 0;
    number = 0;
}

Phone::Phone( const int areaCode, const int number ){
    this->areaCode = areaCode;
    this->number = number;
}

void Phone::operator=( const Phone &right ){
    this->areaCode = right.areaCode;
    this->number = right.number;
}

int Phone::getAreaCode() {
    return areaCode;
}

int Phone::getNumber(){
    return number;
}
