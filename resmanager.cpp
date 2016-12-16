#include "resmanager.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <dirent.h>

namespace jqh {
using namespace std;
using namespace cv;
ResManager::ResManager() {

}

ResManager::~ResManager() {
    // destructor
}

ResManager* ResManager::getInstance() {
    static ResManager instance;
    return &instance;
}

bool ResManager::loadLayers(string path) {
    // read the contents in path
    vector<string> contents;
    readDirs(path, contents);
    if (contents.empty()) {
        return false;
    }
    // else read the data in it
    _layer_imgs.clear();
    _layer_path = path;
    for (auto name: contents) {
        string full_name = path + "/" + name;
        Mat img = imread(full_name);
        _layer_imgs.push_back(img);
    }
    return true;
}

int ResManager::getLayerCount() {
    return _layer_imgs.size();
}


void ResManager::readDirs(string path,
                          vector<string>& contents) {
    DIR *dir = opendir(path.c_str());
    struct dirent *entry = readdir(dir);
    // note we only read the img in the folder
    while (entry != NULL) {
        string name = string(entry->d_name);
        if (name.size() < 3) {
            entry = readdir(dir);
            continue;
        }
        if (name.substr(name.size()-3) == "png") {
            contents.push_back(name);
        }
        entry = readdir(dir);
    }
    closedir(dir);
}


}

