#ifndef CLI_HPP
#define CLI_HPP

#include <string>

struct Args {
  std::string note {};
  std::string tag {};
  std::string project {};
  std::string list {};
  std::string search {};
};


Args parse_args(int& argc, char* argv[]);


#endif //!CLI_HPP
