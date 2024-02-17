#ifndef FILM_H
#define FILM_H
#include <string>
#include <iostream>
#include <memory>
#include "video.h"
using namespace std;
class Film : public Video {
public:
    Film();
    Film(string name,string pathname,int duration,int numberOfChapters,shared_ptr<int> durationOfChapters);
    ~Film();
    shared_ptr<int> getDurationOfChapters() const;
    int getNumberOfChapters() const;
    void setDurationOfChapters(int numberOfChapters,shared_ptr<int> durationOfChapters);
    Film& operator=(const Film& film);
    void display(ostream& stream) const override;
    virtual string getInfo() const override;
private:
    shared_ptr<int> durationOfChapters;
    int numberOfChapters;
};
#endif