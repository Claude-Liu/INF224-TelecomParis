#include <iostream>
#include <string>
#include "multiMedia.h"
using namespace std;

string MultiMedia::getName() const{
    return this->name;
}
string MultiMedia::getPathName() const{
    return this->pathName;
}
void MultiMedia::setName(string name){
    this->name = name;
}
void MultiMedia::setPathName(string pathName){
    this->pathName = pathName;
}

string MultiMedia::getInfo() const{
    return "Name: " + this->name + "\nPath: " + this->pathName;
}

MultiMedia::~MultiMedia(){
    cout << "MultiMedia destructor called" << endl;
}

void MultiMedia::display(ostream &os) const{
    os << "Name: " << this->name << endl;
    os << "Path: " << this->pathName << endl;
}