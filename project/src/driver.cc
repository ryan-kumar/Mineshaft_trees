#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "mineshaft_tree.hpp"
#include "subsurface_map.hpp"

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  SubsurfaceMap test(1, "sample/input.txt");
  system("clear");
  std::cout << test << std::endl;
  MineshaftTree tree_test(test);
  std::cout << tree_test << std::endl;
  std::cout << "breaking" << std::endl;
  tree_test.MineWall(0, 1, Direction::kLEFT);
  std::cout << test << tree_test << std::endl;
  return 0;
}
