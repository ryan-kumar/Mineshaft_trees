#include "subsurface_map.hpp"

#include <fstream>

SubsurfaceMap::SubsurfaceMap(int startX, const std::string& file_path):
    startX_(startX) {
  std::ifstream ifs{file_path};
  int height = 0;
  int width = 0;
  ifs >> height >> width;
  map_.resize(height, std::vector<Location>(width));
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      Location l;
      ifs >> l.up >> l.down >> l.left >> l.right >> l.item;
      map_[i][j] = l;
    }
  }
}

std::vector<std::vector<std::string>> SubsurfaceMap::GetImage() const {
  std::vector<std::vector<std::string>> output;
  output.resize(map_.size() * 5,
                std::vector<std::string>(map_[0].size() * 5, " "));
  int img_row = 0;
  int img_col = 0;
  for (unsigned int row = 0; row < map_.size(); ++row) {
    for (unsigned int col = 0; col < map_[row].size(); ++col) {
      auto const& current = map_[row][col];
      for (unsigned int i = 0; i < 5; i++) {
        if (current.up) output[img_row][img_col + i] = "*";
        // if (current.down) output[img_row + 5][img_col + i] = "*";
        if (current.left) output[img_row + i][img_col] = "*";
        // if (current.right) output[img_row + i][img_col + 5] = "*";
      }
      img_col += 5;
    }
    img_row += 5;
    img_col = 0;
  }
  for (unsigned int i = 0; i < output.size(); ++i) {
    output[i][output[i].size() - 1] = "*";
  }
  for (unsigned int i = 0; i < output[0].size(); ++i) {
    output[output.size() - 1][i] = "*";
  }
  return output;
}

std::ostream& operator<<(std::ostream& os, const SubsurfaceMap& map) {
  auto image = map.GetImage();
  //   os << "image size: " << image.size() << " " << image.at(0).size()
  //      << " map size: " << map.map_.size() << " " << map.map_.at(0).size()
  //      << std::endl;
  os << "Subsurface Location Map\n";
  for (auto const& row : image) {
    for (auto const& col : row) {
      os << col;
    }
    os << std::endl;
  }
  return os;
}