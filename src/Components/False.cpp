/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../../include/Components/False.hpp"

namespace nts {

False::False(std::string name) : Component(name)
{
    for (int i = 0; i <= 1; ++i)
        _pins.push_back(FALSE);
    _outputs.push_back(1);
}

nts::Tristate False::compute(size_t pin)
{
    switch (pin) {
        case 1:
            applyOutputChange(pin);
            break;
        default:
            std::string error = getType() + ":" + std::to_string(pin) + " ERROR tries to compute inoput pin";
            throw (Exception(error.c_str()));
    }
    return _pins[pin];
}

} // namespace nts
