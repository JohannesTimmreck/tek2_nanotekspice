/*
** EPITECH PROJECT, 2019
** bootstrap_NanoTekSpice
** File description:
** description
*/

#include "../../include/Components/Component.hpp"
#include "../../include/Components/Input.hpp"
#include "../../include/Components/Output.hpp"
#include "../../include/Components/True.hpp"
#include "../../include/Components/False.hpp"
#include "../../include/Components/Clock.hpp"
#include "../../include/Components/AndGate.hpp"
#include "../../include/Components/NandGate.hpp"
#include "../../include/Components/NorGate.hpp"
#include "../../include/Components/NotGate.hpp"
#include "../../include/Components/OrGate.hpp"
#include "../../include/Components/XnorGate.hpp"
#include "../../include/Components/XorGate.hpp"
#include "../../include/Circuits/C4001.hpp"
#include "../../include/Circuits/C4011.hpp"
#include "../../include/Circuits/C4030.hpp"
#include "../../include/Circuits/C4069.hpp"
#include "../../include/Circuits/C4071.hpp"
#include "../../include/Circuits/C4081.hpp"

#include <iostream>

namespace nts {

bool Component::checkForInput(size_t pin)
{
    for (auto i = _outputs.begin(); i != _outputs.end(); ++i) {
        if (*i == pin)
            return false;
    }
    return true;
}

void Component::setLink(size_t pin, std::shared_ptr<IComponent> other, size_t otherPin)
{
    for (auto i = _outputs.begin(); i != _outputs.end(); ++i) {
        if (*i == pin) {
            _links.push_back(std::make_tuple(other, pin, otherPin));
            return;
        }
    }
    std::string error =  "Failed to link " + getType() + "-" + _name + ":" + std::to_string(pin) + " with " + other->getType() + "-" + other->getName() + ":" + std::to_string(otherPin);
    throw Exception(error.c_str());
}

void Component::dump() const
{
    int pin = 1;
    for (auto i = _pins.begin() + 1; i != _pins.end() ; ++i) {
        std::cout << _name << ":" << pin << "=";
        switch (*i) {
            case TRUE:
                std::cout << 1 << std::endl;
                break;
            case FALSE:
                std::cout << 0 << std::endl;
                break;
            case UNDEFINED:
                std::cout << "U" << std::endl;
                break;
        }
        pin++;
    }
}

void Component::applyOutputChange(size_t pin)
{
    for (auto i = _links.begin(); i != _links.end(); ++i) {
        if (std::get<1>(*i) == pin) {
            std::get<0>(*i)->setInput(std::get<2>(*i), _pins[pin]);
            if (std::get<0>(*i)->checkForInput(std::get<2>(*i)))
                std::get<0>(*i)->compute(std::get<2>(*i));
        }
    }
}

std::shared_ptr<IComponent> createComponent(const std::string &type, const std::string &value)
{
    std::shared_ptr<IComponent> comp;
    if (type == "input")
        comp = std::make_unique<Input>("");
    else if (type == "output")
        comp = std::make_unique<Output>("");
    else if (type == "true")
        comp = std::make_unique<True>("");
    else if (type == "false")
        comp = std::make_unique<False>("");
    else if (type == "clock")
        comp = std::make_unique<Clock>("");
    else if (type == "nand")
        comp = std::make_unique<NandGate>("");
    else if (type == "and")
        comp = std::make_unique<AndGate>("");
    else if (type == "not")
        comp = std::make_unique<NotGate>("");
    else if (type == "nor")
        comp = std::make_unique<NorGate>("");
    else if (type == "or")
        comp = std::make_unique<OrGate>("");
    else if (type == "xnor")
        comp = std::make_unique<XnorGate>("");
    else if (type == "xor")
        comp = std::make_unique<XorGate>("");
    else if (type == "4001")
        comp = create4001(value);
    else if (type == "4011")
        comp = create4011(value);
    else if (type == "4030")
        comp = create4030(value);
    else if (type == "4069")
        comp = create4069(value);
    else if (type == "4071")
        comp = create4071(value);
    else if (type == "4081")
        comp = create4081(value);
    else {
        std::string error("Component type '" + type + "' Unknown");
        throw Exception(error.c_str());
    }
    if (!comp)
        throw Exception("unable to create component");
    return comp;
}

} // namespace nts