//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string>
#include "multiMedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "controler.h"
#include "tcpserver.h"
using namespace std;
const int PORT = 3331;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;
    int arg = stoi(argv[1]);

    /*
    question 4 and 5: treat the two objects as a list of multimedia pointers using polymorphism
    */
    if (arg==4){
        MultiMedia* multiMediaList[2];
        int count = 0;
        multiMediaList[count++] = new Photo("poster", "../figures/poster.jpg", 1.0, 10.0);
        multiMediaList[count++] = new Video("dolomites", "../figures/dolomites.mp4", 2.5);
        multiMediaList[0]->display(cout);
        multiMediaList[1]->display(cout);
        multiMediaList[0]->play();
        multiMediaList[1]->play();
        for (int i = 0; i < count; i++){
            delete multiMediaList[i];
        }
    }
    /*
    question 6 and 7: film object and smart pointer
    */
    if (arg==6){
        shared_ptr<int> durationOfChapters(new int[3]{1, 2, 3});
        Film *film1 = new Film("dolomites_film", "../figures/dolomites.mp4", 2.5, 3, durationOfChapters);
        film1->display(cout);
        Film film2 = *film1;
        film2.display(cout);
        // we destroy the film1 object, but the film2 object is still alive
        delete film1;
        film2.display(cout);
        cout << "film2 is still alive" << endl;
    }

    /*
    question 8 and 9: group object
    */
    if (arg==8){
        PhotoPtr poster (new Photo("poster", "../figures/poster.jpg", 1.0, 10.0));
        PhotoPtr dolomites_figure_1 (new Photo("dolomites_1", "../figures/dolomites_1.jpg", 1.0, 10.0));
        PhotoPtr dolomites_figure_2 (new Photo("dolomites_2", "../figures/dolomites_2.jpg", 1.0, 10.0));
        PhotoPtr dolomites_figure_3 (new Photo("dolomites_3", "../figures/dolomites_3.jpg", 1.0, 10.0));
        VideoPtr dolomites_0 (new Video("dolomites", "../figures/dolomites.mp4", 2.5));
        VideoPtr dolomites_1 (new Video("dolomites_1", "../figures/dolomites_1.mp4", 2.5));

        Group *all_figures = new Group("all_figures");
        all_figures->push_back(poster);
        all_figures->push_back(dolomites_figure_1);
        all_figures->push_back(dolomites_figure_2);
        all_figures->push_back(dolomites_figure_3);
        all_figures->print(cout);
        delete all_figures;
        Group *all_videos = new Group("all_videos");
        all_videos->push_back(dolomites_0);
        all_videos->push_back(dolomites_1);
        all_videos->print(cout);
        delete all_videos;
        poster.reset();
        Group *all_dolomites = new Group("all_dolomites");
        all_dolomites->push_back(dolomites_0);
        all_dolomites->push_back(dolomites_1);
        all_dolomites->push_back(dolomites_figure_1);
        all_dolomites->push_back(dolomites_figure_2);
        all_dolomites->push_back(dolomites_figure_3);
        string info = all_dolomites->getInfo();
        cout << info << endl;
        delete all_dolomites;

    }
    /*
    question 10: controler object
    */
    if (arg==10){
        shared_ptr<Controler> controler(new Controler());
        shared_ptr<Photo> poster = controler->createPhoto("poster", "../figures/poster.jpg", 1.0, 10.0);
        shared_ptr<Photo> dolomites_figure_1 = controler->createPhoto("dolomites_1", "../figures/dolomites_1.jpg", 1.0, 10.0);
        shared_ptr<Photo> dolomites_figure_2 = controler->createPhoto("dolomites_2", "../figures/dolomites_2.jpg", 1.0, 10.0);
        shared_ptr<Group> all_figures = controler->createGroup("all_figures");
        shared_ptr<Video> dolomites_0 = controler->createVideo("dolomites", "../figures/dolomites.mp4", 2.5);
        shared_ptr<Film> dolomites_film = controler->createFilm("dolomites_film", "../figures/dolomites.mp4", 2.5, 3, shared_ptr<int>(new int[3]{1, 2, 3}));
        controler->search("poster");
        controler->search("dolomites");
        controler->search("all_figures");
        controler->search("dolomites_film");
        controler->play("poster");
        controler->play("dolomites_film");
        controler->play("invalid_name");
    }

    /*
    question 11: server object
    */
    if (arg==11){
        shared_ptr<Controler> controler(new Controler());
        shared_ptr<Photo> poster = controler->createPhoto("poster", "../figures/poster.jpg", 1.0, 10.0);
        shared_ptr<Photo> dolomites_figure_1 = controler->createPhoto("dolomites_1", "../figures/dolomites_1.jpg", 1.0, 10.0);
        shared_ptr<Photo> dolomites_figure_2 = controler->createPhoto("dolomites_2", "../figures/dolomites_2.jpg", 1.0, 10.0);
        shared_ptr<Group> all_figures = controler->createGroup("all_figures");
        all_figures->push_back(poster);
        all_figures->push_back(dolomites_figure_1);
        all_figures->push_back(dolomites_figure_2);
        shared_ptr<Video> dolomites_0 = controler->createVideo("dolomites", "../figures/dolomites.mp4", 2.5);
        shared_ptr<Film> dolomites_film = controler->createFilm("dolomites_film", "../figures/dolomites.mp4", 2.5, 3, shared_ptr<int>(new int[3]{1, 2, 3}));
        auto* server=new TCPServer([&](string const& request,string& response) {
            response = "";
            cout << "Received request: " << request << endl;
            // Requests: SEARCH, PLAY, CREATE, DELETE
            size_t pos = request.find(' ');
            string command = request.substr(0, pos);
            if (command == "SEARCH") {
                string name=request.substr(7);
                cout<<name<<endl;
                response = controler->search(name);
            }
            else if (command == "PLAY") {
                string name=request.substr(5);
                response = controler->play(name);
            }
            else if (command == "CREATE") {
                // CREATE PHOTO name pathname latitude longitude
                if (request[7]=='P') {
                    int pos = 13, lstpos = 13;
                    while (request[pos] != ' ') pos++;
                    string name = request.substr(lstpos, pos-lstpos);
                    pos += 1; lstpos = pos;
                    while (request[pos] != ' ') pos++;
                    string pathname = request.substr(lstpos, pos-lstpos);
                    pos += 1; lstpos = pos;
                    while (request[pos] != ' ') pos++;
                    int latitude = stoi(request.substr(lstpos, pos-lstpos));
                    pos += 1; lstpos = pos;
                    int longitude = stoi(request.substr(lstpos));
                    controler->createPhoto(name, pathname, latitude, longitude);
                    response = "Photo created";
                }
                // create video name pathname duration
                else if (request[7]=='V') {
                    int pos = 13, lstpos = 13;
                    while (request[pos] != ' ') pos++;
                    string name = request.substr(lstpos, pos-lstpos);
                    pos += 1; lstpos = pos;
                    while (request[pos] != ' ') pos++;
                    string pathname = request.substr(lstpos, pos-lstpos);
                    pos += 1; lstpos = pos;
                    int duration = stoi(request.substr(lstpos));
                    controler->createVideo(name, pathname, duration);
                    response = "Video created";
                }
            }
            else if (request[0]=='D') {
                string name=request.substr(7);
                response = controler->remove(name);
            }
            return true;
        });
        cout << "Starting Server on port " << PORT << endl;

        int status = server->run(PORT);

        if (status < 0) {
            cerr << "Could not start Server on port " << PORT << endl;
            return 1;
        }
    }


return 0;
}
