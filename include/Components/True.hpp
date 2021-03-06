/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_TRUE_HPP
#define OOP_NANOTEKSPICE_2019_TRUE_HPP

#include "Component.hpp"

namespace nts {

class True : public Component
{
  public:
    True(std::string name);
    ~True() = default;
    std::string getType() const override { return "true";}
    nts::Tristate compute(size_t pin = 1) override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_TRUE_HPP
