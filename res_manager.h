#ifndef RES_MANAGER_H
#define RES_MANAGER_H
#include <vector>
#include <string>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
namespace jqh {


class ResManager
{
public:
    ~ResManager();
    static ResManager* getInstance();
    bool loadLayers(std::string);
    int getLayerCount() {
        return _layer_imgs.size();
    }
private:
    ResManager(); // make it not possible to access through declare
    std::vector<cv::Mat> _layer_imgs;
    std::string _layer_path;
    void readDirs(std::string, std::vector<std::string>&);
};// end of class
}// end of namespace
#endif // RES_MANAGER_H
