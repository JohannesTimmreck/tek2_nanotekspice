/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../../include/Components/OrGate.hpp"

namespace nts {

OrGate::OrGate(std::string name) : Component(name)
{
    for (int i = 0; i <= 3; ++i)
        _pins.push_back(UNDEFINED);
    _outputs.push_back(3);
}

nts::Tristate OrGate::compute(size_t pin)
{
    switch (pin) {
        case 3:
            if (_pins[1] == TRUE || _pins[2] == TRUE)
                _pins[3] = TRUE;
            else if (_pins[1] == UNDEFINED || _pins[2] == UNDEFINED)
                _pins[3] = UNDEFINED;
            else
                _pins[3] = FALSE;
            applyOutputChange(pin);
            break;
        default:
            std::string error = getType() + ":" + std::to_string(pin) + " ERROR tries to compute input pin";
            throw (Exception(error.c_str()));
    }
    return _pins[pin];
}


} // namespace nts
