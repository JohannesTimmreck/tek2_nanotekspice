/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_NOTGATE_HPP
#define OOP_NANOTEKSPICE_2019_NOTGATE_HPP

#include "Component.hpp"
namespace nts {

class NotGate : public Component
{
  public:
    NotGate(std::string name);
    ~NotGate() = default;
    std::string getType() const override { return "not";}
    nts::Tristate compute(size_t pin = 1) override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_NOTGATE_HPP
