#include <vector>
#include <algorithm>

#include <figure.hpp>
#include <triangle.hpp>
#include <rectangle.hpp>
#include <square.hpp>

std::ostream& operator<< (std::ostream& out, Figure const& fig) {
    fig.printPoints(out);
    return out;
}

void orderPoints(std::vector<Point>& pts);
Figure* whatFigure(std::vector<Point>& pts);

std::istream& operator>> (std::istream& in, Figure*& fig) {
    std::vector<Point> pts;
    
    while (true) {
        char c = in.get();
        while (c == ' ' || c == '\t' || c == '\n')
            c = in.get();
        in.unget();
        
        if (((c < '0') || (c > '9')) && c != '-') {
            break;
        }
        else {
            Point pt;
            in >> pt;
            pts.push_back(pt);
        }
    }
    
    fig = whatFigure(pts);
    return in;
}

Figure* whatFigure(std::vector<Point>& pts) {
    Figure* ptr = nullptr;
    if (pts.size() == 3) {
        ptr = new Triangle(pts);
    }
    else if (pts.size() == 4) {
        if (dist(pts[0], pts[2]) == dist(pts[1], pts[3]) &&
            dist(pts[0], pts[1]) == dist(pts[2], pts[3]) &&
            dist(pts[1], pts[2]) == dist(pts[0], pts[3])) {
            if (dist(pts[0], pts[1]) == dist(pts[1], pts[2])) {
                ptr = new Square(pts);
            }
            else {
                ptr = new Rectangle(pts);
            }
        }
    }
    
    return ptr;
}
