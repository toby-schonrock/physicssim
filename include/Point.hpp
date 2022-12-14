#pragma once

#include "SFML/Graphics.hpp"
#include "Vector2.hpp"

sf::Vector2f visualize(const Vec2& v);

struct Point {
  public:
    sf::Color color;
    Vec2      pos;
    Vec2      vel{};
    Vec2      f;
    double    mass = 1.0;

    Point() = default;

    Point(const Vec2& pos_, double mass_, const sf::Color& color_)
        : color(color_), pos(pos_), mass(mass_) {}

    void update(double deltaTime, double gravity) {
        vel += (f / mass + Vec2(0, 1) * gravity) *
               deltaTime; // TODO euler integration could be improved
        pos += vel * deltaTime;
        f = Vec2();
    }
};