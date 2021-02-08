/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_CIRCUIT_HPP
#define OOP_NANOTEKSPICE_2019_CIRCUIT_HPP

#include "../Components/Component.hpp"
#include <memory>
#include <iostream>

namespace nts {

class Circuit : public Component
{
  protected:

    // list of components inside of a circuit
    std::vector<std::shared_ptr<IComponent>> _components;
    std::size_t _componentsAmount;
    // amount of internal links
    std::size_t _iLinks;

  public:
    void dump();
    void display();
    void change_input(std::string name, nts::Tristate value);
    Circuit (std::string name) : Component(name), _componentsAmount(0), _iLinks(0) {}
    virtual ~Circuit() {destruct();}
    std::string getType() const override { return "circuit";}
    nts::Tristate compute(size_t pin = 1) override;
    void setLink(size_t pin, std::shared_ptr<IComponent> other, size_t otherPin) override;
    void setInput(size_t pin = 1, Tristate newState = UNDEFINED) override;
    void addComponent(std::shared_ptr<IComponent> newC, std::string name) {newC->setName(name);_components.push_back(newC);_componentsAmount++;}
    std::shared_ptr<IComponent> get(size_t pos) override { return _components[pos];}
    std::vector<std::shared_ptr<IComponent>> get() { return _components;}
    size_t getComponentsAmount() {return _componentsAmount;}
    void destruct() override;
    };

} // namespace Circuit

#endif //OOP_NANOTEKSPICE_2019_CIRCUIT_HPP
