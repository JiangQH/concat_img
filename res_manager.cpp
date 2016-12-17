#include "res_manager.h"
#include <stdio.h>
#include <dirent.h>
#include <vector>
#include <string>
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
            cv::Mat img = cv::imread(full_name);
            _layer_imgs.push_back(img);
        }
        return true;
}



}


