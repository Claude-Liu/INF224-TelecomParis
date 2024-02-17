#include <iostream>
#include <string>
#include <cstdlib>
#include "photo.h"
using namespace std;

Photo::~Photo(){
    cout << "Photo destructor called" << endl;
}

double Photo::getLatitude() const{
    return this->latitude;
}
double Photo::getLongitude() const{
    return this->longitude;
}
void Photo::setLatitude(double latitude){
    this->latitude = latitude;
}
void Photo::setLongitude(double longitude){
    this->longitude = longitude;
}
void Photo::display(ostream &os) const{
    MultiMedia::display(os);
    os << "Latitude: " << this->latitude << endl;
    os << "Longitude: " << this->longitude << endl;
}

void Photo::play() const{
    string command = "imagej " + this->getPathName() + " &";
    system(command.data());
}

string Photo::getInfo() const{
    string info="";
    info+=MultiMedia::getInfo();
    info+="Latitude: "+to_string(latitude)+"\n";
    info+="Longitude: "+to_string(longitude);
    return info;
}