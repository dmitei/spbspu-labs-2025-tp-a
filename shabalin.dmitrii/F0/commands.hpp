#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <iostream>
#include "dictionary.hpp"

namespace shabalin
{
  void addWord(Dicts & dicts, std::istream & in, std::ostream & out);
  void printDict(Dicts & dicts, std::istream & in, std::ostream & out);
  void translateWord(Dicts & dicts, std::istream & in, std::ostream & out);
  void removeWord(Dicts & dicts, std::istream & in, std::ostream & out);
  void createDict(Dicts & dicts, std::istream & in, std::ostream & out);
  void saveToFile(Dicts & dicts, std::istream & in, std::ostream & out);
  void combineDicts(Dicts & dicts, std::istream & in, std::ostream & out);
  void deleteWord(Dicts & dicts, std::istream & in, std::ostream & out);
  void editTranslation(Dicts & dicts, std::istream & in, std::ostream & out);
  void renameDict(Dicts & dicts, std::istream & in, std::ostream & out);
  void moveCommand(Dicts & dicts, std::istream & in, std::ostream & out);
  void copyCommand(Dicts & dicts, std::istream & in, std::ostream & out);
  void common(Dicts & dicts, std::istream & in, std::ostream & out);
  void importDictfromFile(Dicts & dicts, const std::string & file);
  void printHelp(std::ostream & out);
  void listDicts(Dicts & dicts, std::istream & in, std::ostream & out);
}

#endif
