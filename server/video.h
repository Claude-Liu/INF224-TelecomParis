#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "multiMedia.h"
using namespace std;

class Video: public MultiMedia{
    protected:
        int duration;
    public:
        Video(string name, string pathName, double duration): MultiMedia(name, pathName){
            this->duration = duration;
        };
        Video(): MultiMedia(){
            this->duration = 0;
        };
        virtual ~Video(){
            cout << "Video destructor called" << endl;
        };
        int getDuration() const{
            return this->duration;
        };
        void setDuration(int duration){
            this->duration = duration;
        };

        virtual void display(ostream &os) const override{
            MultiMedia::display(os);
            os << "Duration: " << this->duration << endl;
        };
        virtual string getInfo() const override{
            string info="";
            info+=MultiMedia::getInfo();
            info+="Duration: "+to_string(duration) + " ; ";
            return info;
        };
        virtual void play() const{
            string command = "mpv " + this->getPathName() + " &";
            system(command.data());
        };
};

#endif // VIDEO_H