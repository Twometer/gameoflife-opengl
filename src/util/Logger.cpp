//
// Created by twome on 06/05/2020.
//

#include <iostream>
#include "Logger.h"

void Logger::Print(const std::string &prefix, const std::string &message) {
    std::cout << prefix << ": " << message << std::endl;
}

void Logger::Error(const std::string &message) {
    Print("ERROR", message);
}

void Logger::Warning(const std::string &message) {
    Print("WARN", message);
}

void Logger::Info(const std::string &message) {
    Print("INFO", message);
}