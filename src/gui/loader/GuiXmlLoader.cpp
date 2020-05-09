//
// Created by twome on 09/05/2020.
//

#include "../../util/Logger.h"
#include "GuiXmlLoader.h"
#include "../components/Panel.h"
#include "../components/Label.h"
#include "../components/Button.h"

using namespace tinyxml2;

void GuiXmlLoader::load(IScreen *screen, const std::string &name) {
    std::string path = "assets/screens/" + name;

    XMLDocument doc;
    doc.LoadFile(path.c_str());

    XMLElement *root = doc.FirstChildElement("Screen");
    if (root == nullptr) {
        Logger::error("Cannot load screen: Root node not found");
        return;
    }

    apply_properties(screen, root);
    scan(screen, root);
}

IComponent *GuiXmlLoader::instantiate(const char *name, const char *idPtr) {
    std::string id = std::string(idPtr);
    if (strcmp(name, "Panel") == 0)
        return new Panel(id);
    if (strcmp(name, "Label") == 0)
        return new Label(id);
    if (strcmp(name, "Button") == 0)
        return new Button(id);
    return nullptr;
}

void GuiXmlLoader::scan(IContainer *parent, tinyxml2::XMLElement *xml) {
    for (XMLElement *child = xml->FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
        IComponent *uiChild = instantiate(child->Name(), child->Attribute("Id"));

        if (uiChild == nullptr) {
            Logger::error("Invalid component: " + std::string(child->Name()));
            continue;
        }

        if (!child->NoChildren()) {
            auto *container = dynamic_cast<IContainer *>(uiChild);
            if (!container) {
                Logger::error(
                        "Tried to add components to a non-container object of type " + std::string(child->Name()));
                continue;
            }

            scan(container, child);
        }
        apply_properties(uiChild, child);
        parent->add_component(uiChild);
    }
}

void GuiXmlLoader::apply_properties(IComponent *component, tinyxml2::XMLElement *xml) {
    component->set_row(xml->IntAttribute("Row", 0));
    component->set_row_span(xml->IntAttribute("RowSpan", 1));
    component->set_col(xml->IntAttribute("Col", 0));
    component->set_col_span(xml->IntAttribute("ColSpan", 1));
    component->set_margin(parse_vec(xml->Attribute("Margin")));
    component->set_padding(parse_vec(xml->Attribute("Padding")));
    component->set_horizontal_alignment(parse_alignment(xml->Attribute("HorizontalAlignment")));
    component->set_vertical_alignment(parse_alignment(xml->Attribute("VerticalAlignment")));

    if (auto container = dynamic_cast<IContainer *>(component)) {
        container->set_rows(xml->IntAttribute("Rows", 1));
        container->set_cols(xml->IntAttribute("Cols", 1));
    } else if (auto label = dynamic_cast<Label *>(component)) {
        label->set_text(xml->Attribute("Text"));
        label->set_font_size(xml->FloatAttribute("FontSize", 1.0f));
    } else if (auto button = dynamic_cast<Button *>(component)) {
        button->set_text(xml->Attribute("Text"));
        button->set_font_size(xml->FloatAttribute("FontSize", 1.0f));
    }
}

glm::vec2 GuiXmlLoader::parse_vec(const char *srcPtr) {
    if (srcPtr == nullptr)
        return {0, 0};

    std::string src = std::string(srcPtr);
    size_t separatorPos = src.find(',');
    if (separatorPos == std::string::npos) {
        Logger::error("Cannot parse " + src + " as a 2D vector");
        return {0, 0};
    }
    float x = std::stof(src.substr(0, separatorPos));
    float y = std::stof(src.substr(separatorPos + 1));
    return glm::vec2(x, y);
}

Alignment GuiXmlLoader::parse_alignment(const char *src) {
    if (src == nullptr)
        return Alignment::START;

    if (strcmp(src, "START") == 0)
        return Alignment::START;
    if (strcmp(src, "CENTER") == 0)
        return Alignment::CENTER;
    if (strcmp(src, "END") == 0)
        return Alignment::END;
    if (strcmp(src, "STRETCH") == 0)
        return Alignment::STRETCH;
    return Alignment::START;
}
