#ifndef MINESHAFT_TREE_HPP
#define MINESHAFT_TREE_HPP
#include "subsurface_map.hpp"
#include <string>
#include <vector>

    struct MineshaftNode{
       int x = 0; int y = 0;
       std::string item;
       std::vector<MineshaftNode*> branches;
       MineshaftNode(const Location& location, int x_coor , int y_coor);
    };

    class MineshaftTree {
        public :
         MineshaftTree() = default; 
         MineshaftTree(SubsurfaceMap location_map);

        private :
            MineshaftNode* entrance;

    };

#endif
