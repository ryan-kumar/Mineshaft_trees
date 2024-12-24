#include "mineshaft_tree.hpp"

MineshaftNode::MineshaftNode(const Location& location, int x_coor , int y_coor) 
    : x(x_coor), y(y_coor), item(location.item) {} 