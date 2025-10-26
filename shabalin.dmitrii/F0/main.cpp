#include <functional>
#include <limits>
#include "commands.hpp"
#include "dictionary.hpp"

int main(int argc, char* argv[])
{
  using namespace shabalin;
  printHelp(std::cout);
  Dicts dicts;
  if (argc == 2)
  {
    std::string arg = argv[1];
    try
    {
      importDictfromFile(dicts, arg);
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 1;
    }
  }

  std::unordered_map< std::string, std::function< void(std::istream &) > > commands;
  using namespace std::placeholders;
  commands["create"] = std::bind(createDict, std::ref(dicts), _1, std::ref(std::cout));
  commands["add"] = std::bind(addWord, std::ref(dicts), _1, std::ref(std::cout));
  commands["translate"] = std::bind(translateWord, std::ref(dicts), _1, std::ref(std::cout));
  commands["remove"] = std::bind(removeWord, std::ref(dicts), _1, std::ref(std::cout));
  commands["print"] = std::bind(printDict, std::ref(dicts), _1, std::ref(std::cout));
  commands["save"] = std::bind(saveToFile, std::ref(dicts), _1, std::ref(std::cout));
  commands["combine"] = std::bind(combineDicts, std::ref(dicts), _1, std::ref(std::cout));
  commands["delete"] = std::bind(deleteWord, std::ref(dicts), _1, std::ref(std::cout));
  commands["edit"] = std::bind(editTranslation, std::ref(dicts), _1, std::ref(std::cout));
  commands["rename"] = std::bind(renameDict, std::ref(dicts), _1, std::ref(std::cout));
  commands["move"] = std::bind(moveCommand, std::ref(dicts), _1, std::ref(std::cout));
  commands["copy"] = std::bind(copyCommand, std::ref(dicts), _1, std::ref(std::cout));
  commands["common"] = std::bind(common, std::ref(dicts), _1, std::ref(std::cout));
  commands["list"] = std::bind(listDicts, std::ref(dicts), _1, std::ref(std::cout));

  std::string command;
  while (std::cin >> command)
  {
    try
    {
      commands.at(command)(std::cin);
    }
    catch (const std::out_of_range &)
    {
      std::cout << "<INVALID COMMAND>\n";
    }
    catch (const std::exception &)
    {
      std::cout << "<INVALID COMMAND>\n";
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
  }
}
