//
// Created by twome on 10/05/2020.
//

#include "IDialog.h"
#include "../../render/GameWindow.h"

IDialog::IDialog(const std::string &id) : IScreen(id) {}

void IDialog::close() {
    GameWindow::get_instance()->get_gui_renderer()->show_dialog(nullptr);
}
