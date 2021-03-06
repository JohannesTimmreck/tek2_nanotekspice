/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_OUTPUT_HPP
#define OOP_NANOTEKSPICE_2019_OUTPUT_HPP

#include "Component.hpp"
#include <iostream>
namespace nts {

class Output : public Component
{
  public:
    Output(std::string name);
    ~Output() {};
    std::string getType() const override { return "output";}
    nts::Tristate compute(size_t pin = 1) override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_OUTPUT_HPP
