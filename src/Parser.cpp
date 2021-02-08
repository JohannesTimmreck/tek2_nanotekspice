/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../include/Parser.hpp"
#include "../include/Exception.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <memory>

namespace nts {

void Parser::setChipset(std::string input, Circuit *board)
{
    std::string type;
    std::string name;
    std::string value("");
    size_t state = 0;

    for (auto i = input.begin(); i != input.end(); ++i) {
        if (*i == ' ' || *i == '\t') {
            state++;
            while (*i == ' ' || *i == '\t')
                i++;
        }
        switch (state) {
            case 0:
                type += *i;
                break;
            case 1:
                name += *i;
                break;
            default:
                break;
        }
    }
    board->addComponent(createComponent(type, value), name);
}

void Parser::linking(std::tuple<std::string, size_t> first, std::tuple<std::string, size_t> second, Circuit *board)
{
    std::shared_ptr<IComponent> firstC;
    std::shared_ptr<IComponent> secondC;
    for (size_t i = 0; i != board->getComponentsAmount(); ++i) {
        if (board->get(i)->getName() == std::get<0>(first))
            firstC = board->get(i);
        if (board->get(i)->getName() == std::get<0>(second))
            secondC = board->get(i);
    }
    if (!firstC || !secondC)
        throw Exception("Component name is unknown");
    if (!firstC->checkForInput(std::get<1>(first)))
        firstC->setLink(std::get<1>(first), secondC, std::get<1>(second));
    else if (!secondC->checkForInput(std::get<1>(second)))
        secondC->setLink(std::get<1>(second), firstC, std::get<1>(first));
}

void Parser::setLinks(std::string input, Circuit *board)
{
    std::string firstName;
    std::string firstPin;
    std::string secondName;
    std::string secondPin;
    size_t state = 0;

    for (auto i = input.begin(); i != input.end(); ++i) {
        if (*i == ' ' || *i == '\t' || *i == ':') {
            state++;
            i++;
            while (*i == ' ' || *i == '\t')
                i++;
        }
        switch (state) {
            case 0:
                firstName += *i;
                break;
            case 1:
                firstPin += *i;
                break;
            case 2:
                secondName += *i;
                break;
            case 3:
                secondPin += *i;
                break;
            default:
                break;
        }
    }
    if (firstName == secondName && firstPin == secondPin)
        throw Exception("Connecting pin to itself");
    linking(make_tuple(firstName, std::stoul(firstPin)), make_tuple(secondName, std::stoul(secondPin)), board);
}

void Parser::parse(std::string filePath, Circuit *board)
{
    std::ifstream stream(filePath);
    std::string str;
    ReadState state = UNDEFINED;
    bool chipSection = false;
    bool linkSection = false;

    if (!stream.is_open())
        throw Exception("could not open given file");
    do {
        getline(stream, str);
        if (str == ".chipsets:") {
            chipSection = true;
            state = CHIPSET;
            continue;
        } else if (str == ".links:" && state == CHIPSET) {
            for (size_t i = 0; i != board->get().size(); ++i) {
                for (size_t j = i + 1; j != board->get().size(); ++j) {
                    if (board->get()[j]->getName() == board->get()[i]->getName())
                        throw Exception("2 Components with same name");
                }
            }
            linkSection = true;
            state = LINKS;
            continue;
        }
        if (str[0] == '#' || str[0] == '\0')
            continue;
        switch (state) {
            case CHIPSET:
                setChipset(str, board);
                break;
            case LINKS:
                setLinks(str, board);
                break;
            default:
                throw Exception("has instructions before entering .chipset section");
        }
    } while (!stream.eof());
    if (!chipSection)
        throw Exception("no Setting chipset section");
    if (!linkSection)
        throw Exception("no Linking section");
}

} // namespace nts
