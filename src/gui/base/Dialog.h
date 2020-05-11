//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_DIALOG_H
#define GAMEOFLIFE_OPENGL_DIALOG_H


#include "Screen.h"

class Dialog : public Screen {
public:
    Dialog(const std::string &id);

    void close();
};


#endif //GAMEOFLIFE_OPENGL_DIALOG_H
