
#ifndef CONTROLER_H
#define CONTROLER_H
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include "film.h"
#include "group.h"
using namespace std;

class Controler {
public:
    Controler();
    ~Controler();
    shared_ptr<Photo> createPhoto(const string& name,const string& pathname,int latitude,int longitude);
    shared_ptr<Video> createVideo(const string& name,const string& pathname,int duration);
    shared_ptr<Film> createFilm(const string& name,const string& pathname,int duration,int numberOfChapters,shared_ptr<int> durationOfChapters);
    shared_ptr<Group> createGroup(const string& name);
    string search(const string& name);
    string play(const string& name);
    int remove(const string& name);
private:
    map<string,shared_ptr<MultiMedia>> tableMultimedia;
    map<string,shared_ptr<Group>> tableGroup;
};
#endif