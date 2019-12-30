#include <fstream>
#include "processor.hpp"

void stream_processor::process(std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer) {
    std::cout << "PRINT CONSOLE" << std::endl;
    for (const auto& figure : *buffer) {
        std::cout << (*figure);
    }
}


void file_processor::process(std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer) {
    std::cout << "PRINT FILE" << std::endl;
    std::ofstream osf;
    osf.open(std::to_string(counter) + ".txt");
    ++counter;
    if (!osf.is_open()) {
        std::cout << "Error opening file\n";
        return;
    }
    for (const auto& figure : *buffer) {
        figure->printPoints(osf);
    }
}
