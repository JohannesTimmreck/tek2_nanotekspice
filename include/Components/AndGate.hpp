/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_ANDGATE_HPP
#define OOP_NANOTEKSPICE_2019_ANDGATE_HPP

#include "Component.hpp"
#include <iostream>

namespace nts {

class AndGate : public Component
{
  public:
    AndGate(std::string name);
    ~AndGate() {}
    std::string getType() const override { return "and";}
    nts::Tristate compute(size_t pin = 1) override;
}; // class AndGate

}; // namespace nts

#endif //OOP_NANOTEKSPICE_2019_ANDGATE_HPP
