#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include "processor.hpp"
#include "subscriber.hpp"
#include "figure.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "rectangle.hpp"

std::shared_ptr<Figure> getFigure(std::istream& is) {
    Figure* fig;
    is >> fig;
    return std::shared_ptr<Figure>(fig);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <buffer size>\n";
        return 1;
    }
    const int buf_size = std::stoi(argv[1]);

    std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer =
        std::make_shared<std::vector<std::shared_ptr<Figure>>>();
    buffer->reserve(buf_size);

    subscriber sub;
    sub.processors.push_back(std::make_shared<stream_processor>());
    sub.processors.push_back(std::make_shared<file_processor>());
    std::thread sub_thread(std::ref(sub));
    
    while(true) {
        std::unique_lock<std::mutex> guard(sub.mtx);
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "add") {
            try {
                buffer->push_back(getFigure(std::cin));
            }
            catch (std::logic_error& e) {
                std::cout << e.what() << "\n";
                continue;
            }
            if (buffer->size() == buf_size) {
                sub.buffer = buffer;
                sub.cv.notify_all();
                sub.cv.wait(guard, [&]() { return sub.buffer == nullptr; });
                buffer->clear();
            }
        }
        else if (cmd == "exit"){
            break;
        }
        else {
            std::cout << "Wrong command!\n";
        }
    }
    sub.end = true;
    sub.cv.notify_all();
    sub_thread.join();
    
    return 0;
}
