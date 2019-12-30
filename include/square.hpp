#pragma once

#include <figure.hpp>
#include <rectangle.hpp>

class Square : public Rectangle {
public:
    Square(std::vector<Point> const& fig) : Rectangle(fig) {};
    void printPoints(std::ostream& out) const override;
    ~Square() = default;
};
