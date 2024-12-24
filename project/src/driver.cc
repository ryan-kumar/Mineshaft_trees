#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "subsurface_map.hpp"
#include "mineshaft_tree.hpp"


int main(int argc, char* argv[]) {
  (void) argc;
  (void) argv;
  
  std::cout << "This is main" << std::endl;
  SubsurfaceMap test("sample/input.txt");

  return 0;
}
