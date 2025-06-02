#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

std::string expand_path(const std::string& path);
std::string getCurrentTimestamp(const char* format = "[%Y-%m-%d %H:%M:%S]");


#endif //!UTILS_HPP
