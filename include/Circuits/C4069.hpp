/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_C4069_HPP
#define OOP_NANOTEKSPICE_2019_C4069_HPP

#include "Circuit.hpp"

namespace nts {

class C4069 : public Circuit
{
  public:
    C4069(std::string name);
    ~C4069() = default;
    std::string getType() const override { return "4069";}
    nts::Tristate compute(size_t pin = 1) override;
};

std::shared_ptr<IComponent> create4069(const std::string &value);

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_C4069_HPP
