/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_NORGATE_HPP
#define OOP_NANOTEKSPICE_2019_NORGATE_HPP

#include "Component.hpp"
namespace nts {

class NorGate : public Component
{
  public:
    NorGate (std::string name);

    ~NorGate () = default;

    std::string getType () const override { return "nor"; }

    nts::Tristate compute (size_t pin = 1) override;
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_NORGATE_HPP
