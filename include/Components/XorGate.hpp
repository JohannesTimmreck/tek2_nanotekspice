/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_XORGATE_HPP
#define OOP_NANOTEKSPICE_2019_XORGATE_HPP

#include "Component.hpp"
namespace nts {

class XorGate : public Component
{
  public:
    XorGate(std::string name);
    ~XorGate() = default;
    std::string getType() const override { return "xor";}
    nts::Tristate compute(size_t pin = 1) override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_XORGATE_HPP
