#pragma once

#include <memory>
#include <iostream>
#include <condition_variable>
#include <thread>
#include <vector>
#include <mutex>
#include "figure.hpp"
#include "processor.hpp"


class subscriber {
public:
    void operator()();
    std::vector<std::shared_ptr<processor>> processors;
    std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer;
    std::mutex mtx;
    std::condition_variable cv;
    bool end = false;
};
