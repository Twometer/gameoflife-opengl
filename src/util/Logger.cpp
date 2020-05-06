//
// Created by twome on 06/05/2020.
//

#include <iostream>
#include "Logger.h"

void Logger::print(const std::string &prefix, const std::string &message) {
    std::cout << prefix << ": " << message << std::endl;
}

void Logger::error(const std::string &message) {
    print("ERROR", message);
}

void Logger::warn(const std::string &message) {
    print("WARN", message);
}

void Logger::info(const std::string &message) {
    print("INFO", message);
}