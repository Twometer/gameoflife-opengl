//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_LOGGER_H
#define GAMEOFLIFE_OPENGL_LOGGER_H

#include <string>

class Logger {
private:
    static void print(const std::string &prefix, const std::string &message);

public:
    static void error(const std::string &message);

    static void warn(const std::string &message);

    static void info(const std::string &message);
};

#endif //GAMEOFLIFE_OPENGL_LOGGER_H
