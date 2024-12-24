#include "subsurface_map.hpp"
#include <fstream>

SubsurfaceMap::SubsurfaceMap(const std::string& file_path) {
    std::ifstream ifs{file_path};
    int height = 0; int width = 0;
    ifs >> height >> width;
    map_.resize(height, std::vector<Location>(width));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Location l;
            ifs >> l.up >> l.down >> l.left >> l.right >> l.item;
            map_[i][j] = l;
        }
    }
}