//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_LOGGER_H
#define GAMEOFLIFE_3D_LOGGER_H

#include <string>

class Logger {
private:
    static void Print(const std::string &prefix, const std::string &message);

public:
    static void Error(const std::string &message);

    static void Warning(const std::string &message);

    static void Info(const std::string &message);
};

#endif //GAMEOFLIFE_3D_LOGGER_H
