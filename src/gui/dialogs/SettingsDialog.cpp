//
// Created by twome on 10/05/2020.
//

#include "SettingsDialog.h"
#include "../../io/XmlGuiLoader.h"
#include "../components/Button.h"

SettingsDialog::SettingsDialog() : IDialog("settingsDialog") {
    XmlGuiLoader::load(this, "settings_dialog.xml");

    auto exitButton = find_component<Button>("btnExit");
    exitButton->set_click_listener([this]() {
        this->close();
    });

}
