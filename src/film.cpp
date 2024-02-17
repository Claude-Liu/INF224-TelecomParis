
#include <iostream>
#include <string>
#include "film.h"
using namespace std;

Film::Film ( ) {
    durationOfChapters=nullptr;
    numberOfChapters=0;
}

Film::Film (string name,string pathname,int duration,int numberOfChapters,shared_ptr<int> durationOfChapters) : Video(name,pathname,duration) {
    this->numberOfChapters=numberOfChapters;
    this->durationOfChapters=shared_ptr<int>(new int[numberOfChapters]);
    
    int* durationOfChaptersPtr=durationOfChapters.get();
    int* thisDurationOfChaptersPtr=this->durationOfChapters.get();
    for (int i=0;i<numberOfChapters;i++) {
        thisDurationOfChaptersPtr[i]=durationOfChaptersPtr[i];
    }

}

Film::~Film ( ) {
    cout << this->name << ": Film destructor called " << endl;
}

shared_ptr<int> Film::getDurationOfChapters ( ) const {
    return durationOfChapters;
}

int Film::getNumberOfChapters ( ) const {
    return numberOfChapters;
}

void Film::setDurationOfChapters (int numberOfChapters,shared_ptr<int> durationOfChapters) {
    if (this->numberOfChapters!=numberOfChapters) {
        this->numberOfChapters=numberOfChapters;
        this->durationOfChapters=shared_ptr<int>(new int[numberOfChapters]);
    }
    int* durationOfChaptersPtr=durationOfChapters.get();
    int* thisDurationOfChaptersPtr=this->durationOfChapters.get();
    for (int i=0;i<numberOfChapters;i++) {
        thisDurationOfChaptersPtr[i]=durationOfChaptersPtr[i];
    }
}

Film& Film::operator= (const Film& film) {
    this->duration = film.duration;
    this->name = film.name;
    this->pathName = film.pathName;
    setDurationOfChapters(film.numberOfChapters,film.durationOfChapters);
    return *this;
}

void Film::display (ostream& out) const {
    Video::display(out);
    out<<"Number of chapters: "<<numberOfChapters<<endl;
    out<<"Duration of chapters: ";
    int* durationOfChaptersPtr=durationOfChapters.get();
    for (int i=0;i<numberOfChapters;i++) {
        out<<durationOfChaptersPtr[i]<<" ";
    }
    out<<endl;
}

string Film::getInfo () const {
    string info="";
    info+=Video::getInfo()+" ; ";
    info+="Number of chapters: "+to_string(numberOfChapters)+" ; ";
    info+="Duration of chapters: ";
    int* durationOfChaptersPtr=durationOfChapters.get();
    for (int i=0;i<numberOfChapters;i++) {
        info+=to_string(durationOfChaptersPtr[i])+" ";
    }
    return info;
}