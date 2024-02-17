#include "group.h"
using namespace std;


Group::Group(){
    this->name = "";
}

Group::Group(const string& name){
    this->name = name;
}

Group::Group(const string& name, const list<shared_ptr<MultiMedia>>& list){
    this->name = name;
    for (auto it = list.begin(); it != list.end(); it++){
        this->push_back(*it);
    }
}

Group::~Group(){
    cout << "Group destructor called" << endl;
}

string Group::getName() const{
    return this->name;
}

void Group::setName(const string& name){
    this->name = name;
}

void Group::print(ostream& stream) const{
    stream << "Group name: " << this->name << endl;
    for (auto it = this->begin(); it != this->end(); it++){
        MultiMedia* multiMediaPtr = (*it).get();
        multiMediaPtr->display(stream);
    }
}

string Group::getInfo() const{
    string info = "";
    info += "Group name: " + this->name + "\n";
    for (auto it = this->begin(); it != this->end(); it++){
        MultiMedia* multiMediaPtr = (*it).get();
        info += multiMediaPtr->getInfo() + "\n";
    }
    return info;
}

