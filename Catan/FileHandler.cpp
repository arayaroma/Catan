#include "FileHandler.hpp"

FileHandler::FileHandler() {}

void FileHandler::saveFile(const string &fileName, Game &obj) {
  try {
    std::ofstream file(fileName, std::ios::binary);
    if (file.is_open()) {
      char *data = reinterpret_cast<char *>(&obj);
      std::size_t size = sizeof(Game);
      if (file.write(data, size)) {
        log("File saved successfully.");
      } else {
        throw std::runtime_error("Unable to write to file: " + fileName);
      }
      file.close();
    } else {
      throw std::runtime_error("Unable to open file: " + fileName);
    }
  } catch (const std::exception &e) {
    log("Error: " << e.what());
  }
}

void FileHandler::loadFile(const string &fileName, Game &obj) {
  try {
    std::ifstream file(fileName, std::ios::binary);
    if (file.is_open()) {
      file.seekg(0, std::ios::end);
      std::streamsize size = file.tellg();
      file.seekg(0, std::ios::beg);

      std::vector<char> buffer(size);
      if (file.read(buffer.data(), size)) {
        obj = *reinterpret_cast<Game *>(buffer.data());
        log("File loaded successfully.");
      } else {
        throw std::runtime_error("Unable to read file: " + fileName);
      }
      file.close();
    } else {
      throw std::runtime_error("Unable to open file: " + fileName);
    }
  } catch (const std::exception &e) {
    log("Error: " << e.what());
  }
}