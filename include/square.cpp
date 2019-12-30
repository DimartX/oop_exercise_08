#include <square.hpp>

void Square::printPoints(std::ostream& out) const {
    out << "Square: " << std::endl;
    for (Point const& pt : pts) {
        out << pt << std::endl;
    }
}
