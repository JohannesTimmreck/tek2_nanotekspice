/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../../include/Circuits/Circuit.hpp"
#include <algorithm>

namespace nts {

void Circuit::setLink(size_t pin, std::shared_ptr<IComponent> other, size_t otherPin)
{
    size_t pos = 0;
    for (auto i = _pins.begin(); i != _pins.end(); ++i) {
        if (pos == pin) {
            _links.push_back(std::make_tuple(other, pin, otherPin));
            return;
        }
        pos++;
    }
}

void Circuit::setInput(size_t pin, Tristate newState)
{
    // set pin to new state
    _pins[pin] = newState;

    // apply oin change to all internal links
    for (size_t i = 0; i < _iLinks; i++) {
        if (std::get<1>(_links[i]) == pin)
            std::get<0>(_links[i])->setInput(std::get<2>(_links[i]), _pins[pin]);
    }
}

void Circuit::dump()
{
    size_t len = _components.size();
    for (size_t x = 0; x != len; x++) {
        _components.at(x)->dump();
    }
}

void Circuit::display()
{
    size_t len = _components.size();
    std::vector<std::tuple<std::string, Tristate>> test;

    //create list of outputs
    for (size_t x = 0; x != len; x++) {
        if (_components.at(x)->getType() == "output")
            test.push_back(std::make_tuple(_components.at(x)->getName(), _components.at(x)->getPin(1)));
    }

    //sort list by first tuple slot and display list
    std::sort(test.begin(), test.end());
    for (size_t x = 0; x != test.size(); x++) {
        std::cout << std::get<0>(test[x]) << "=";
        if (std::get<1>(test[x]) != -1)
            std::cout << std::get<1>(test[x]) << std::endl;
        else
            std::cout << "U" << std::endl;
    }
}

void Circuit::change_input(std::string name, nts::Tristate value)
{
    size_t len = _components.size();
    std::vector<std::tuple<std::string, Tristate>> test;

    //create list of outputs
    for (size_t x = 0; x != len; x++) {
        if (_components.at(x)->getType() == "input") {
            if (_components.at(x)->getName() == name) {
                _components.at(x)->setInput(1, value);
                break;
            }
        }
    }
}

nts::Tristate Circuit::compute(size_t pin)
{
    (void)pin;
    for (size_t i = 0; i != _components.size(); ++i) {
        if (_components[i]->getType() == "input"
            || _components[i]->getType() == "true"
            || _components[i]->getType() == "false"
            || _components[i]->getType() == "clock")
            _components[i]->compute();
    }
    return TRUE;
}

void Circuit::destruct() {
    for (auto i = _components.begin(); i != _components.end(); i++)
        i[0]->destruct();
    _links.clear();
}

} // namespace nts