/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_C4001_HPP
#define OOP_NANOTEKSPICE_2019_C4001_HPP

#include "Circuit.hpp"

namespace nts {

class C4001 : public Circuit
{
  public:
    C4001(std::string name);
    ~C4001() = default;
    std::string getType() const override { return "4001";}
    nts::Tristate compute(size_t pin = 1) override;
};

std::shared_ptr<IComponent> create4001(const std::string &value);

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_C4001_HPP
