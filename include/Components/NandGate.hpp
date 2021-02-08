/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_NANDGATE_HPP
#define OOP_NANOTEKSPICE_2019_NANDGATE_HPP

#include "Component.hpp"

namespace nts {

class NandGate : public Component
{
  public:
    NandGate(std::string name);
    ~NandGate() = default;
    std::string getType() const override { return "nand";}
    nts::Tristate compute(size_t pin = 1) override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_NANDGATE_HPP
