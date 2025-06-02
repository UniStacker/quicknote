#include "../include/utils.hpp"
#include <cstdlib>
#include <ctime>


std::string expand_path(const std::string& path) {
  if (!path.empty() && path[0] == '~')
    return std::string(std::getenv("HOME")) + path.substr(1);
  return path;
}

std::string getCurrentTimestamp(const char* format) {
    time_t now = time(nullptr);
    tm* local = localtime(&now);  // use gmtime(&now) for UTC

    char buffer[80];
    strftime(buffer, sizeof(buffer), format, local);

    return std::string(buffer);
}
