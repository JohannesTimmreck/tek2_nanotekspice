/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../../include/Circuits/C4011.hpp"
#include "../../include/Components/NandGate.hpp"

namespace nts {

C4011::C4011(std::string name) : Circuit(name)
{
    // set pins
    for (int i = 0; i <= 13; ++i)
        _pins.push_back(UNDEFINED);
    _outputs.push_back(3);
    _outputs.push_back(4);
    _outputs.push_back(10);
    _outputs.push_back(11);

    // set components
    _components.push_back(createComponent("nand", ""));
    _components.push_back(createComponent("nand", ""));
    _components.push_back(createComponent("nand", ""));
    _components.push_back(createComponent("nand", ""));

    // internal linking
    setLink(1, _components[0], 1);
    setLink(2, _components[0], 2);
    setLink(5, _components[1], 1);
    setLink(6, _components[1], 2);
    setLink(8, _components[2], 1);
    setLink(9, _components[2], 2);
    setLink(12, _components[3], 1);
    setLink(13, _components[3], 2);
    _iLinks += 8;
}

nts::Tristate C4011::compute(size_t pin)
{
    switch (pin) {
        case 1:
        case 2:
            _components[0]->compute(3);
            applyOutputChange(3);
            break;
        case 5:
        case 6:
            _components[1]->compute(3);
            applyOutputChange(4);
            break;
        case 8:
        case 9:
            _components[2]->compute(3);
            applyOutputChange(10);
            break;
        case 12:
        case 13:
            _components[3]->compute(3);
            applyOutputChange(11);
            break;
        default:
            std::string error = getType() + ":" + std::to_string(pin) + " ERROR tries to compute output pin";
            throw (Exception(error.c_str()));
    }
    return _pins[pin];
}

std::shared_ptr<IComponent> create4011(const std::string &value)
{
    (void)value;
    std::shared_ptr<IComponent> comp = std::make_shared<C4011>("");
    comp->get(0)->setLink(3, comp, 3);
    comp->get(1)->setLink(3, comp, 4);
    comp->get(2)->setLink(3, comp, 10);
    comp->get(3)->setLink(3, comp, 11);
    return comp;
}

} // namespace nts
