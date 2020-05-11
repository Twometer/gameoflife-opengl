//
// Created by twome on 10/05/2020.
//

#include "Dialog.h"
#include "../../render/GameWindow.h"

Dialog::Dialog(const std::string &id) : Screen(id) {}

void Dialog::close() {
    GameWindow::get_instance()->get_gui_renderer()->show_dialog(nullptr);
}
