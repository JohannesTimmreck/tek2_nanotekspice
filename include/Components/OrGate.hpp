/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_ORGATE_HPP
#define OOP_NANOTEKSPICE_2019_ORGATE_HPP

#include "Component.hpp"

namespace nts {

class OrGate : public Component
{
  public:
    OrGate(std::string name);
    ~OrGate() = default;
    std::string getType() const override { return "or";}
    nts::Tristate compute(size_t pin = 1) override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_ORGATE_HPP
