/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../../include/Components/Clock.hpp"

namespace nts {

Clock::Clock(std::string name) : Component(name)
{
    for (int i = 0; i <= 1; ++i)
        _pins.push_back(UNDEFINED);
    _outputs.push_back(1);
}

nts::Tristate Clock::compute(size_t pin)
{
    switch (pin) {
        case 1:
            applyOutputChange(pin);
            break;
        default:
            std::string error = getType() + ":" + std::to_string(pin) + " ERROR tries to compute input pin";
            throw (Exception(error.c_str()));
    }
    return _pins[pin];
}

} // namespace nts
