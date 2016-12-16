#ifndef RESMANAGER_H
#define RESMANAGER_H
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

#include <vector>
#include <string>

namespace jqh {
class ResManager {
private:
    std::string _layer_path;
    // store the img
    std::vector<cv::Mat> _layer_imgs;
    // read png data in the dir
    void readDirs(std::string path,
                  std::vector<std::string>&contents);


public:
    // there is only on res manager, the factory mode
    static ResManager *getInstance();
    ResManager();
    ~ResManager();


    // load the resource
    bool loadLayers(std::string path);
};// end of resmanager
}// end of namespace
#endif // RESMANAGER_H
