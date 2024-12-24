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

  SubsurfaceMap test("sample/input.txt");
  system("clear");
  std::cout << test << std::endl;
  return 0;
}
