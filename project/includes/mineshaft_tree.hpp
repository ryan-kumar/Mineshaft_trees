#ifndef MINESHAFT_TREE_HPP
#define MINESHAFT_TREE_HPP
#include <string>
#include <vector>

#include "subsurface_map.hpp"

struct MineshaftNode {
  int x = 0;
  int y = 0;
  std::string item;
  std::vector<MineshaftNode*> branches;
  MineshaftNode(const Location& location, int x_coor, int y_coor);
};

class MineshaftTree {
public:
  MineshaftTree(SubsurfaceMap& location_map);
  MineshaftTree(const MineshaftTree& tree) = delete;
  ~MineshaftTree();
  void Clear(MineshaftNode* node);

  // needs destructor
  // delete the copy stuff probably
  friend std::ostream& operator<<(std::ostream& os, const MineshaftTree& map);

private:
  MineshaftNode* Build(const std::vector<std::vector<Location>>& map,
                       int x,
                       int y);
  SubsurfaceMap subsurface_map_;
  MineshaftNode* entrance_;
};

#endif
