//
// Created by twome on 09/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_XMLGUILOADER_H
#define GAMEOFLIFE_OPENGL_XMLGUILOADER_H

#include <string>
#include <tinyxml2.h>

#include "../gui/base/Screen.h"

class XmlGuiLoader {
public:
    static void load(Screen *screen, const std::string &path);

private:
    static void scan(Container *parent, tinyxml2::XMLElement *xml);

    static Component *instantiate(const char *name, const char *id);

    static void apply_properties(Component *component, tinyxml2::XMLElement *xml);

    static glm::vec2 parse_vec(const char *src);

    static Alignment parse_alignment(const char *src);
};


#endif //GAMEOFLIFE_OPENGL_XMLGUILOADER_H
