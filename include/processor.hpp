#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include "figure.hpp"


class processor {
public:
    virtual void process(std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer) = 0;
};

class stream_processor : public processor {
public:
    void process(std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer) override;
};

class file_processor : public processor {
public:
    void process(std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer) override;
private:
    int counter = 0;
};
