
#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <string>
#include <list>
#include <memory>
#include "multiMedia.h"
#include "photo.h"
#include "video.h"

typedef std::shared_ptr<MultiMedia> MultiMediaPtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;

class Group : public list<MultiMediaPtr>{
public:
    Group();
    Group(const string& name);
    Group(const string& name, const list<MultiMediaPtr> &list);
    virtual ~Group();
    string getName() const;
    void setName(const string& name);
    void print(ostream& stream) const;
    string getInfo() const;
private:
    string name;
};
#endif