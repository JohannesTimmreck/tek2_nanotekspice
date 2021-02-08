/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_C4081_HPP
#define OOP_NANOTEKSPICE_2019_C4081_HPP

#include "Circuit.hpp"
#include <iostream>

namespace nts {

class C4081 : public Circuit
{
  public:
    C4081(std::string name);
    ~C4081() {};
    std::string getType() const override { return "4081";}
    nts::Tristate compute(size_t pin = 1) override;
};

std::shared_ptr<IComponent> create4081(const std::string &value);

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_C4081_HPP
