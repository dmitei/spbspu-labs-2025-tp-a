#ifndef GEOMETRIC_SHAPES_HPP
#define GEOMETRIC_SHAPES_HPP

#include <vector>

namespace shabalin
{
  struct Point
  {
    int x, y;
  };

  struct Polygon
  {
    std::vector< Point > points;
  };
}

#endif
