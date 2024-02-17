#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "MultiMedia.h"
using namespace std;

class Photo: public MultiMedia{
    private:
        double latitude;
        double longitude;
    public:
        Photo(string name, string pathName, double latitude, double longitude): MultiMedia(name, pathName){
            this->latitude = latitude;
            this->longitude = longitude;
        };
        Photo(): MultiMedia(){
            this->latitude = 0;
            this->longitude = 0;
        };
        virtual string getInfo() const override;
        virtual ~Photo();
        double getLatitude() const;
        double getLongitude() const;
        void setLatitude(double latitude);
        void setLongitude(double longitude);

        void display(ostream &os) const override;
        void play() const override;
};

#endif // PHOTO_H