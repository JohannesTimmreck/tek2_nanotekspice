/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_INPUT_HPP
#define OOP_NANOTEKSPICE_2019_INPUT_HPP

#include "Component.hpp"
#include <iostream>
namespace nts {

class Input : public Component
{
  public:
    Input(std::string name);
    ~Input() {};
    std::string getType() const override { return "input";}
    nts::Tristate compute(size_t pin = 1) override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_INPUT_HPP
