#include "mineshaft_tree.hpp"

#include <fstream>
#include <iostream>
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
  Build(entrance_, subsurface_map_.GetStartX(), 0);
}
void MineshaftTree::Build(MineshaftNode*& node, int x, int y) {
  if (mineshaftnodes_.contains({x, y})) return;
  const Location& current = subsurface_map_.GetMap()[y][x];
  node = new MineshaftNode(current, x, y);
  mineshaftnodes_[{x, y}] = {};
  if (!current.left) Build(node->branches[0], x - 1, y);
  if (!current.right) Build(node->branches[1], x + 1, y);
  if (!current.down) Build(node->branches[2], x, y + 1);
}

// MineshaftNode* MineshaftTree::Build(
//     const std::vector<std::vector<Location>>& map, int x, int y) {
//   const Location& current = map[x][y];
//   MineshaftNode* node = new MineshaftNode(current, x, y);
//   node->branches[0] = (current.left) ? nullptr : Build(map, x - 1, y);
//   node->branches[1] = (current.right) ? nullptr : Build(map, x + 1, y);
//   node->branches[2] = (current.down) ? nullptr : Build(map, x, y + 1);
//   return node;
// }

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
      if (child && !visited.contains({child->x, child->y})) {
        to_visit.push(child);
      }
    }
    to_visit.pop();
  }
  return found;
}
// do some sort of bfs
std::ostream& operator<<(std::ostream& os, const MineshaftTree& map) {
  std::queue<MineshaftNode*> to_visit;
  std::set<std::pair<int, int>> visited;

  to_visit.push(map.entrance_);

  while (!to_visit.empty()) {
    auto const* current_node = to_visit.front();
    // process happens here
    os << "{" << current_node->x << ", " << current_node->y << "}" << std::endl;
    visited.insert({current_node->x, current_node->y});
    for (auto* child : current_node->branches) {
      // os << "in" << std::endl;
      if (child && !visited.contains({child->x, child->y})) {
        to_visit.push(child);
      }
    }
    to_visit.pop();
  }

  return os;
}