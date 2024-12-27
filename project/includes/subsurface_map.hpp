#ifndef SUBSURFACE_MAP_HPP
#define SUBSURFACE_MAP_HPP
#include <string>
#include <vector>

struct Location {
  bool up = true;
  bool down = true;
  bool left = true;
  bool right = true;
  std::string item;
  // Location(bool u, bool d, bool l, bool r, const std::string& it)
  //     : up(u), down(d), left(l), right(r), item(it) {};
};

class SubsurfaceMap {
public:
  // SubsurfaceMap() = default;
  SubsurfaceMap(int startX, const std::vector<std::vector<Location>>& map):
      startX_(startX), map_(map){};
  SubsurfaceMap(int startX, const std::string& file_path);
  std::vector<std::vector<std::string>> GetImage() const;
  // need to make interface
  std::vector<std::vector<Location>>& GetMap() { return map_; }
  int GetStartX() const { return startX_; }
  friend std::ostream& operator<<(std::ostream& os, const SubsurfaceMap& map);

private:
  int startX_ = 0;
  std::vector<std::vector<Location>> map_;
};

#endif