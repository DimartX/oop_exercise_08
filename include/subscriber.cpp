#include "subscriber.hpp"

void subscriber::operator()() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "SUBSCRIBER IS WORKING" << std::endl;
        cv.wait(lock, [&] { return (buffer != nullptr || end); });
        if (end) {
            break;
        }
        for (const auto& processor_elem : processors) {
            processor_elem->process(buffer);
        }
        buffer = nullptr;
        cv.notify_all();
    }
}
