#include "res_manager.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
namespace jqh {
using namespace std;
using namespace cv;
ResManager::ResManager()
{
    // currently nothing
}
ResManager::~ResManager() {
    // currently nothing
}

ResManager* ResManager::getInstance() {
    static ResManager instance;
    return &instance;
}

void ResManager::readDirs(string path, vector<string>& contents) {
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

bool ResManager::loadLayers(string path) {
        // read the contents in path
        string flag = path + "/flags";
        if (exist(flag)) {
            return false;
        }
        vector<string> contents;
        readDirs(path, contents);
        if (contents.empty()) {
            return false;
        }
        _layer_path = path;
        for (auto name: contents) {
            string full_name = path + "/" + name;
            cv::Mat img = cv::imread(full_name);
            _layer_imgs.push_back(img);
        }
        return true;
}

void ResManager::updateCurrentImg(int id, Option op) {
    switch (op) {
    case add:
        _merge_id.insert(id);
        mergeImg();
        break;
    case sub:
        _merge_id.erase(id);
        mergeImg();
        break;
    default:
        break;
    }
}

const cv::Mat& ResManager::getCurrentImg() const{
    return _current_img;
}

std::string ResManager::saveCurrentImg() {
   // cout << save_name << endl;
    // should we save?
    if (_current_img.empty()) {
        return "empty";
    }
    string save_name = _layer_path + "/cut_" +
            std::to_string(_saved_count) + ".jpg";
    imwrite(save_name, _current_img);
    string msg = "saved as cut_";
    // save a flag too
    string flag = _layer_path + "/flags";
    if (!exist(flag)) {
        std::ofstream a(flag);
        a << "flag";
        a.close();
    }
    return msg + std::to_string(_saved_count)+".jpg";
}

bool ResManager::exist(string filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

void ResManager::resetAll() {
    _layer_imgs.clear();
    _current_img.release();
    _merge_id.clear();
    _saved_count = 0;
}

void ResManager::mergeImg() {
    _current_img.release();
    for(auto it = _merge_id.begin(); it != _merge_id.end() ; ++it) {
        if (it == _merge_id.begin() &&_current_img.empty()) {
            _current_img = (_layer_imgs[*it]).clone();
        }
        else {
            _current_img += _layer_imgs[*it];
        }
    }
}



}


