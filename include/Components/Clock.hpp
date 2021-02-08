/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_CLOCK_HPP
#define OOP_NANOTEKSPICE_2019_CLOCK_HPP

#include "Component.hpp"

namespace nts {

class Clock : public Component
{
  public:
    Clock(std::string name);
    ~Clock() = default;
    std::string getType() const override { return "clock";}
    nts::Tristate compute(size_t pin = 1)  override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_CLOCK_HPP
