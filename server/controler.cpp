
#include "controler.h"
using namespace std;

Controler::Controler ( ) {
}
/**
 * @brief Destructor of the Manager class.
*/
Controler::~Controler ( ) {
}

shared_ptr<Photo> Controler::createPhoto (const string& name,const string& pathname,int latitude,int longitude) {
    shared_ptr<Photo> photo(new Photo(name,pathname,latitude,longitude));
    tableMultimedia[name]=photo;
    return photo;
}

shared_ptr<Video> Controler::createVideo (const string& name,const string& pathname,int duration) {
    shared_ptr<Video> video(new Video(name,pathname,duration));
    tableMultimedia[name]=video;
    return video;
}

shared_ptr<Film> Controler::createFilm (const string& name,const string& pathname,int duration,int numberOfChapters,shared_ptr<int> durationOfChapters) {
    shared_ptr<Film> film(new Film(name,pathname,duration,numberOfChapters,durationOfChapters));
    tableMultimedia[name]=film;
    return film;
}

shared_ptr<Group> Controler::createGroup (const string& name) {
    shared_ptr<Group> group(new Group(name));
    tableGroup[name]=group;
    return group;
}

string Controler::search (const string& name) {
    auto it_multimedia=tableMultimedia.find(name);
    auto it_group=tableGroup.find(name);
    cout<<"-------------"<<endl;
    if (it_multimedia!=tableMultimedia.end()) {
        cout<<"Found multimedia:"<<endl;
        it_multimedia->second->display(cout);
        return it_multimedia->second->getInfo();
    }
    else if (it_group!=tableGroup.end()) {
        cout<<"Found group: "<<endl;
        it_group->second->print(cout);
        return it_group->second->getInfo();
    }
    else {
        cout<<"No multimedia or group with name: "<<name<<endl;
        return "No multimedia or group with name: "+name;
    }
}

string Controler::play (const string& name) {
    auto it_multimedia=tableMultimedia.find(name);
    if (it_multimedia!=tableMultimedia.end()) {
        it_multimedia->second->play();
        return it_multimedia->second->getInfo();
    }
    else {
        cout<<"No multimedia with name "<<name<<endl;
        return "No multimedia with name "+name;
    }
}

int Controler::remove (const string& name) {
    auto it_multimedia=tableMultimedia.find(name);
    if (it_multimedia!=tableMultimedia.end()) {
        tableMultimedia.erase(it_multimedia);
        // Remove multimedia from all groups
        for (auto it_group=tableGroup.begin();it_group!=tableGroup.end();it_group++) {
            it_group->second->remove(it_multimedia->second);
        }
        return 1;
    }
    else return 0;
}