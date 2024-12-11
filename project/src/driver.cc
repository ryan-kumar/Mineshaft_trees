
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

int main(int argc, char* argv[]) {
  // std::ofstream ofs{"sample_out/output.txt"};
  (void)argc;
  //(void)argv;
  //   system("clear");
  //     system("mkdir async");
  //     system("touch async/hello_world.txt");
  std::vector<std::string> loading = {"0 0\n v \n", "* 0\n v \n"};
  system("clear");
  for (int i = 1; i < std::stoi(argv[1]) + 1; ++i) {
    for (int j = 0; j < 2; j++) {
      std::cout << loading[j];
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      system("clear");
    }
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // system("clear");
  }
  return 0;
}
