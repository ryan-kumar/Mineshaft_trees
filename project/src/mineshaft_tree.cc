#include "mineshaft_tree.hpp"

#include <queue>
#include <set>

MineshaftNode::MineshaftNode(const Location& location, int x_coor, int y_coor):
    x(x_coor), y(y_coor), item(location.item) {
  branches.resize(3, nullptr);
}

MineshaftTree::~MineshaftTree() { Clear(entrance_); }

void MineshaftTree::Clear(MineshaftNode* node) {
  for (auto* child : node->branches) {
    if (child) Clear(child);
  }
  delete node;
  node = nullptr;
}

MineshaftTree::MineshaftTree(SubsurfaceMap& location_map):
    subsurface_map_(location_map) {
  entrance_ = Build(subsurface_map_.GetMap(), subsurface_map_.GetStartX(), 0);
}

MineshaftNode* MineshaftTree::Build(
    const std::vector<std::vector<Location>>& map, int x, int y) {
  const Location& current = map[x][y];
  MineshaftNode* node = new MineshaftNode(current, x, y);
  node->branches[0] = (current.left) ? nullptr : Build(map, x - 1, y);
  node->branches[1] = (current.right) ? nullptr : Build(map, x + 1, y);
  node->branches[2] = (current.down) ? nullptr : Build(map, x, y + 1);
  return node;
}

MineshaftNode*& MineshaftTree::FindNode(int x, int y) {
  std::queue<MineshaftNode*> to_visit;
  std::set<std::pair<int, int>> visited;
  MineshaftNode*& found = entrance_;
  to_visit.push(entrance_);

  while (!to_visit.empty()) {
    auto*& current_node = to_visit.front();
    if (current_node->x == x && current_node->y == y) {
      found = current_node;
      break;
    }
    if (visited.contains({current_node->x, current_node->y})) {
      to_visit.pop();
      continue;
    }
    visited.insert({current_node->x, current_node->y});
    for (auto* child : current_node->branches) {
      if (!visited.contains({child->x, child->y})) {
        to_visit.push(child);
      }
    }
    to_visit.pop();
  }
  return found;
}

std::ostream& operator<<(std::ostream& os, const MineshaftTree& map) {
  (void)map;
  return os;
}