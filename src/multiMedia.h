#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>
using namespace std;

class MultiMedia
{
    protected:
        string name;
        string pathName;

    public:
        MultiMedia(string name, string pathName){
            this->name = name;
            this->pathName = pathName;
        };
        MultiMedia(){
            this->name = "";
            this->pathName = "";
        };

        virtual ~MultiMedia();
        virtual string getInfo() const;
        string getName() const;
        string getPathName() const;
        void setName(string name);
        void setPathName(string pathName);

        virtual void display(ostream &os) const;
        virtual void play() const = 0;

};

#endif // MULTIMEDIA_H