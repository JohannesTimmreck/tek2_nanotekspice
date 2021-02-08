/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP

#include <string>
#include <memory>
#include "Exception.hpp"

namespace nts {

enum Tristate {
    UNDEFINED = (-true),
    TRUE = true,
    FALSE = false
};

class IComponent{
  public:
    virtual ~IComponent() = default;
    virtual nts::Tristate compute(size_t pin = 1) = 0;
    virtual std::string getName() const = 0;
    virtual void setName(std::string) = 0;
    virtual std::string getType() const = 0;
    virtual nts::Tristate getPin(size_t pos) const = 0;
    virtual void setInput(size_t pin = 1, Tristate newState = UNDEFINED) = 0;
    virtual bool checkForInput(size_t pin = 1) = 0;
    virtual void setLink(size_t pin, std::shared_ptr<IComponent> other, size_t otherPin) = 0;
    virtual void dump() const = 0;
    virtual std::shared_ptr<IComponent> get(size_t pos) = 0;
    virtual void destruct() = 0;
}; // class IComponent

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
