#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <regex>
#include "../include/core/cli.hpp"
#include "../include/utils.hpp"

namespace fs = std::filesystem;


const std::string DATA_DIR = "~/.quicknote/";
const std::string FILE_NAME = "notes.txt";


std::string format_note(Args& args) {
  std::string note { getCurrentTimestamp() };
  if (!args.project.empty()) note += " [" + args.project + "]";
  if (!args.tag.empty()) note += " [@" + args.tag + "]";
  note += " " + args.note + "\n";
  
  return note;
}

void alert_no_note_file() {
  std::string path { expand_path(DATA_DIR + FILE_NAME) };
  if (!fs::exists(path)) {
    std::cout << "Notes File doesn't exist.\n";
    exit(1);
  }
}

int main(int argc, char* argv[]) {
  // Handling command line arguments
  Args args = parse_args(argc, argv);

  // Make sure the base data dir exists
  fs::create_directory(expand_path(DATA_DIR));
  std::string note_file_path = expand_path(DATA_DIR + FILE_NAME);

  // Add note
  if (args.note.length()) {
    std::ofstream noteFile(note_file_path, std::ios::app);
    std::string fmt_note { format_note(args) };
    
    // Append note to the file 
    noteFile << fmt_note;
    noteFile.close();

    std::cout << "Note: " << fmt_note
              << "Successfully saved at: " << note_file_path << "\n";
  }

  // List notes
  if (!args.list.empty()) {
    alert_no_note_file();
    std::ifstream noteFile(note_file_path);

    if (args.list == "all") {
      std::cout << "==== Listing All Notes ====\n";
      std::string note;
      while (std::getline(noteFile, note)) std::cout << note << "\n";
      std::cout << "==== Done ====\n";
    }
    else if (args.list == "today") {
      std::string datePattern = getCurrentTimestamp("%Y-%m-%d");
      std::regex dateMatch(R"(^\[)" + datePattern + R"(.*)");
      
      std::cout << "==== Listing Today's Notes ====\n";
      std::string note;
      while (std::getline(noteFile, note)) {
        if (std::regex_match(note, dateMatch))
          std::cout << note << "\n";
      }
      std::cout << "==== Done ====\n";
    }
    else {
      std::cout << "Error: Invalid input to --list: " << args.list << "\n";
    }

    noteFile.close();
  }

  return 0;
}
