//
// Created by twome on 10/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_IDIALOG_H
#define GAMEOFLIFE_OPENGL_IDIALOG_H


#include "IScreen.h"

class IDialog : public IScreen {
public:
    IDialog(const std::string &id);

    void close();
};


#endif //GAMEOFLIFE_OPENGL_IDIALOG_H
