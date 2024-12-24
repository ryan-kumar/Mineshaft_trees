#ifndef SUBSURFACE_MAP_HPP
#define SUBSURFACE_MAP_HPP
#include <string>
#include <vector>


struct Location {
    bool up = true; bool down = true;
    bool left = true; bool right = true;
    std::string item;
    // Location(bool u, bool d, bool l, bool r, const std::string& it) 
    //     : up(u), down(d), left(l), right(r), item(it) {};
};
 
class SubsurfaceMap {
    public:
    SubsurfaceMap() = default;
    SubsurfaceMap(const std::vector<std::vector<Location>>& map) : map_(map){};
    SubsurfaceMap(const std::string& file_path);
    // need to make interface 
    friend std::ostream& operator<<(std::ostream& os, const SubsurfaceMap& map);

    private:
     std::vector<std::vector<Location>> map_;
};

#endif