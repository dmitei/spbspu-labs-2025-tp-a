#ifndef DELIMETR_HPP
#define DELIMETR_HPP
#include <iostream>

namespace shabalin
{
  struct Delimiter
  {
    char exp;
  };
  std::istream & operator>>(std::istream & in, DelimiterI && dest);
}
#endif

