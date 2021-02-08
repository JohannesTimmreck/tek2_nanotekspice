/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../../include/Components/NandGate.hpp"

namespace nts {

NandGate::NandGate(std::string name) : Component(name)
{
    for (int i = 0; i <= 3; ++i)
        _pins.push_back(UNDEFINED);
    _outputs.push_back(3);
}

nts::Tristate NandGate::compute(size_t pin)
{
    switch (pin) {
        case 3:
            if (_pins[1] == FALSE || _pins[2] == FALSE)
                _pins[3] = TRUE;
            else if (_pins[1] == UNDEFINED || _pins[2] == UNDEFINED)
                _pins[3] = UNDEFINED;
            else
                _pins[3] = FALSE;
            applyOutputChange(3);
            break;
        default:
            std::string error = getType() + ":" + std::to_string(pin) + " ERROR tries to compute input pin";
            throw (Exception(error.c_str()));
    }
    return _pins[pin];
}

} // namespace nts
