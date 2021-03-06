/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_C4071_HPP
#define OOP_NANOTEKSPICE_2019_C4071_HPP

#include "Circuit.hpp"

namespace nts {

class C4071 : public Circuit
{
  public:
    C4071(std::string name);
    ~C4071() = default;
    std::string getType() const override { return "4071";}
    nts::Tristate compute(size_t pin = 1) override;
};

std::shared_ptr<IComponent> create4071(const std::string &value);

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_C4071_HPP
