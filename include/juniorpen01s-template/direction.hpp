#pragma once

#include <raylib.h>

namespace juniorpen01s_template {
namespace direction {
enum class Dir { Up, Right, Down, Left };

class Direction {
public:
  Direction(const Dir value);
  operator Vector2() const;

private:
  const Dir value_;
};
} // namespace direction
} // namespace juniorpen01s_template
