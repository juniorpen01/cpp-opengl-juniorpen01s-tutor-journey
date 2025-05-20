#include <doctest/doctest.h>
#include <raylib.h>
#include <raymath.h>

#include <juniorpen01s-template/direction.hpp>

using namespace juniorpen01s_template::direction;

TEST_CASE("Up maps to (0, -1)") {
  const auto testDirection = Direction(Dir::Up);
  CHECK_EQ(static_cast<Vector2>(testDirection), Vector2{0, -1});
}

TEST_CASE("Right maps to (1, 0)") {
  const auto testDirection = Direction(Dir::Right);
  CHECK_EQ(static_cast<Vector2>(testDirection), Vector2{1, 0});
}

TEST_CASE("Down maps to (0, 1)") {
  const auto testDirection = Direction(Dir::Down);
  CHECK_EQ(static_cast<Vector2>(testDirection), Vector2{0, 1});
}

TEST_CASE("Left maps to (-1, 0)") {
  const auto testDirection = Direction(Dir::Left);
  CHECK_EQ(static_cast<Vector2>(testDirection), Vector2{-1, 0});
}
