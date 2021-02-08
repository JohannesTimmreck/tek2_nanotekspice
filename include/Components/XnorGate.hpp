/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_XNOR_HPP
#define OOP_NANOTEKSPICE_2019_XNOR_HPP

#include "Component.hpp"
namespace nts {

class XnorGate : public Component
{
  public:
    XnorGate(std::string name);
    ~XnorGate() = default;
    std::string getType() const override { return "xnor";}
    nts::Tristate compute(size_t pin = 1) override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_XNOR_HPP
