/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../../include/Components/NotGate.hpp"

namespace nts {

NotGate::NotGate(std::string name) : Component(name)
{
    for (int i = 0; i <= 2; ++i)
        _pins.push_back(UNDEFINED);
    _outputs.push_back(2);
}

nts::Tristate NotGate::compute(size_t pin)
{
    switch (pin) {
        case 2:
            if (_pins[1] == FALSE)
                _pins[2] = TRUE;
            else if (_pins[1] == TRUE)
                _pins[2] = FALSE;
            else
                _pins[2] = UNDEFINED;
            applyOutputChange(2);
            break;
        default:
            std::string error = getType() + ":" + std::to_string(pin) + " ERROR tries to compute input pin";
            throw (Exception(error.c_str()));
    }
    return _pins[pin];
}

} // namespace nts