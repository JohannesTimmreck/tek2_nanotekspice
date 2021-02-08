/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_C4011_HPP
#define OOP_NANOTEKSPICE_2019_C4011_HPP

#include "Circuit.hpp"

namespace nts {

class C4011 : public Circuit
{
  public:
    C4011(std::string name);
    ~C4011() = default;
    std::string getType() const override { return "4011";}
    nts::Tristate compute(size_t pin = 1) override;
};

std::shared_ptr<IComponent> create4011(const std::string &value);

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_C4011_HPP
