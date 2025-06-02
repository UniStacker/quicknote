#include "../../include/core/cli.hpp"
#include <iostream>


std::string get_arg_val(int argc, char* argv[], int& idx, std::string arg, std::string _default = "") {
  if (idx+1 < argc) return argv[++idx];
  if (_default.empty()) {
    std::cout << "Error: Please provide an input to the "
              << arg << "argument.\n";
    exit(1);
  }
  return _default;
}

void print_usage(std::string exec) {
  std::cout << "Usage: " << exec << " \"<note>\" [args...]\n";
  exit(1);
}

Args parse_args(int& argc, char* argv[]) {
  if (argc == 1) print_usage(argv[0]);

  Args args {};
  for (int idx=1; idx<argc; idx++) {
    std::string arg = argv[idx];

    if (arg == "--tag" || arg == "-t")
      args.tag = get_arg_val(argc, argv, idx, arg);
    else if (arg == "--project" || arg == "-p")
      args.project = get_arg_val(argc, argv, idx, arg);
    else if (arg == "--list" || arg == "-l")
      args.list = get_arg_val(argc, argv, idx, arg, "today");
    else if (arg == "--search" || arg == "-s")
      args.search = get_arg_val(argc, argv, idx, arg);
    else if(arg[0] != '-')
      args.note = arg;
    else {
      std::cout << "Invalid argument: " << arg << "\n";
      exit(1);
    }
  }
  if (args.note.empty() && args.list.empty() && args.search.empty())
    print_usage(argv[0]);
  if (!args.tag.empty() && args.tag[0] == '@') // Remove @ sign from tag
    args.tag = args.tag.substr(1);

  return args;
}
