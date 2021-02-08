/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_C4030_HPP
#define OOP_NANOTEKSPICE_2019_C4030_HPP

#include "Circuit.hpp"

namespace nts {

class C4030 : public Circuit
{
  public:
    C4030(std::string name);
    ~C4030() = default;
    std::string getType() const override { return "4030";}
    nts::Tristate compute(size_t pin = 1) override;
};

std::shared_ptr<IComponent> create4030(const std::string &value);

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_C4030_HPP
