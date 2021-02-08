/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../../include/Circuits/C4069.hpp"
#include "../../include/Components/NotGate.hpp"

namespace nts {

C4069::C4069(std::string name) : Circuit(name)
{
    // set pins
    for (int i = 0; i <= 13; ++i)
        _pins.push_back(UNDEFINED);
    _outputs.push_back(2);
    _outputs.push_back(4);
    _outputs.push_back(6);
    _outputs.push_back(8);
    _outputs.push_back(10);
    _outputs.push_back(12);

    // set components
    _components.push_back(createComponent("not", ""));
    _components.push_back(createComponent("not", ""));
    _components.push_back(createComponent("not", ""));
    _components.push_back(createComponent("not", ""));
    _components.push_back(createComponent("not", ""));
    _components.push_back(createComponent("not", ""));

    // internal linking
    setLink(1, _components[0], 1);
    setLink(3, _components[1], 1);
    setLink(5, _components[2], 1);
    setLink(9, _components[3], 1);
    setLink(11, _components[4], 1);
    setLink(13, _components[5], 1);
    _iLinks += 6;
}

nts::Tristate C4069::compute(size_t pin)
{
    switch (pin) {
        case 1:
            _components[0]->compute(2);
            applyOutputChange(2);
            break;
        case 3:
            _components[1]->compute(2);
            applyOutputChange(4);
            break;
        case 5:
            _components[2]->compute(2);
            applyOutputChange(6);
            break;
        case 9:
            _components[3]->compute(2);
            applyOutputChange(8);
            break;
        case 11:
            _components[4]->compute(2);
            applyOutputChange(10);
            break;
        case 13:
            _components[5]->compute(2);
            applyOutputChange(12);
            break;
        default:
            std::string error = getType() + ":" + std::to_string(pin) + " ERROR tries to compute output pin";
            throw (Exception(error.c_str()));
    }
    return _pins[pin];
}

std::shared_ptr<IComponent> create4069(const std::string &value)
{
    (void)value;
    std::shared_ptr<IComponent> comp = std::make_shared<C4069>("");
    comp->get(0)->setLink(2, comp, 2);
    comp->get(1)->setLink(2, comp, 4);
    comp->get(2)->setLink(2, comp, 6);
    comp->get(3)->setLink(2, comp, 8);
    comp->get(4)->setLink(2, comp, 10);
    comp->get(5)->setLink(2, comp, 12);
    return comp;
}

} // namespace nts
