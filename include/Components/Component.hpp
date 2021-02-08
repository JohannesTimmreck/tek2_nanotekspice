/*
** EPITECH PROJECT, 2019
** bootstrap_NanoTekSpice
** File description:
** description
*/


#ifndef BOOTSTRAP_NANOTEKSPICE_COMPONENT_HPP
#define BOOTSTRAP_NANOTEKSPICE_COMPONENT_HPP

#include <vector>
#include <tuple>
#include <string>
#include <iostream>

#include "../IComponent.hpp"
#include <memory>

namespace nts {
class Component : public IComponent
{
  protected:
    std::string _name;
    std::vector <Tristate> _pins;

    // pos of output links
    std::vector<size_t> _outputs;
    // links to external pins <other, internal, external>
    std::vector <std::tuple<std::shared_ptr<IComponent>, size_t, size_t>> _links;

  public:
    Component(std::string name) : _name(name) {};
    ~Component() = default;
    std::string getName() const override { return _name;}
    void setName(std::string name) override { _name = name;}
    virtual void setInput(size_t pin = 1, Tristate newState = UNDEFINED) {_pins[pin] = newState;}
    void applyOutputChange(size_t pin);
    bool checkForInput(size_t pin = 1) override;
    virtual void setLink(size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin);
    void dump() const override;
    nts::Tristate getPin(size_t pos) const override {return _pins[pos];}
    std::shared_ptr<IComponent> get(size_t pos) override {(void)pos;return nullptr;};
    void destruct() override {_links.clear();}
}; // class Component

std::shared_ptr<IComponent> createComponent(const std::string &type, const std::string &value);

} // namespace nts

#endif //BOOTSTRAP_NANOTEKSPICE_COMPONENT_HPP
