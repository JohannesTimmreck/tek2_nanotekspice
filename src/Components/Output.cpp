/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../../include/Components/Output.hpp"

namespace nts {

Output::Output(std::string name) : Component(name)
{
    for (int i = 0; i <= 1; ++i)
        _pins.push_back(UNDEFINED);
}

nts::Tristate Output::compute(size_t pin)
{
    switch (pin) {
        case 1:
            break;
        default:
            std::string error = getType() + ":" + std::to_string(pin) + " ERROR tries to compute input pin";
            throw (Exception(error.c_str()));
    }
    return _pins[pin];
}

} // namespace nts
