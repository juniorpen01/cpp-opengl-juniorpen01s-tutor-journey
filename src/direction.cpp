#include <cassert>

#include <juniorpen01s-template/direction.hpp>

using namespace juniorpen01s_template::direction;

Direction::Direction(const Dir value) : value_(value) {}
Direction::operator Vector2() const {
#pragma clang diagnostic push
#pragma clang diagnostic ignored                                               \
    "-Wswitch-default" // HACK: Avoid redundant default
  switch (value_) {
    using D = Dir;
  case D::Up:
    return {0, -1};
  case D::Right:
    return {1, 0};
  case D::Down:
    return {0, 1};
  case D::Left:
    return {-1, 0};
  }
#pragma clang diagnostic pop
}
