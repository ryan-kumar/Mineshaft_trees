#ifndef MINESHAFT_TREE_HPP
#define MINESHAFT_TREE_HPP
#include <map>
#include <string>
#include <vector>

#include "subsurface_map.hpp"

enum Direction { kDOWN, kLEFT, kRIGHT };

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
  // returns root if node is not found
  MineshaftNode*& FindNode(int x, int y);
  bool MineWall(int x, int y, Direction dir);
  std::pair<int, int> GetDim() const;
  // delete the copy stuff probably
  friend std::ostream& operator<<(std::ostream& os, const MineshaftTree& map);

private:
  void Build(MineshaftNode*& node, int x, int y);
  SubsurfaceMap subsurface_map_;
  MineshaftNode* entrance_ = nullptr;
  std::map<std::pair<int, int>, std::vector<int>> mineshaftnodes_;
};

#endif
