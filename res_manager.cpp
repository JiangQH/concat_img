#include "res_manager.h"
#include <stdio.h>
#include <dirent.h>
#include <vector>
#include <string>
#include <iostream>
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
        resetAll();
        // read the contents in path
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
        if (_current_img.empty()) {
            _current_img = (_layer_imgs[id]).clone();
        }
        else {
            _current_img += _layer_imgs[id];
        }
        break;
    case sub:
        _current_img -= _layer_imgs[id];
        break;
    default:
        break;
    }
}

const cv::Mat& ResManager::getCurrentImg() const{
    return _current_img;
}

std::string ResManager::saveCurrentImg(int saveid) {
    string save_name = _layer_path + "/cut_" +
            std::to_string(saveid) + ".jpg";
   // cout << save_name << endl;
    imwrite(save_name, _current_img);
    string msg = "saved as cut_";
    return msg + std::to_string(saveid)+".jpg";
}

void ResManager::resetAll() {
    _layer_imgs.clear();
    _current_img.release();
}



}


