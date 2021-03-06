#ifndef RES_MANAGER_H
#define RES_MANAGER_H
#include <vector>
#include <string>
#include <set>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
namespace jqh {
enum Option {
    add,
    sub
};

class ResManager
{
public:
    ~ResManager();
    static ResManager* getInstance();
    bool loadLayers(std::string);
    int getLayerCount() const {
        return _layer_imgs.size();
    }
    void updateCurrentImg(int id, Option op);
    const cv::Mat& getCurrentImg() const;
    std::string saveCurrentImg();
    void resetAll();
private:
    ResManager(); // make it not possible to access through declare
    std::vector<cv::Mat> _layer_imgs;
    std::string _layer_path;
    cv::Mat _current_img;
    std::set<int> _merge_id;
    int _saved_count;
    void mergeImg();
    void readDirs(std::string, std::vector<std::string>&);
    bool exist(std::string filename);
};// end of class
}// end of namespace
#endif // RES_MANAGER_H
