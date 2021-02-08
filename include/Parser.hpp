/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_PARSER_HPP
#define OOP_NANOTEKSPICE_2019_PARSER_HPP

#include "../include/Circuits/C4081.hpp"
#include "../include/Circuits/C4071.hpp"
#include "../include/Circuits/C4069.hpp"
#include "../include/Circuits/C4011.hpp"
#include "../include/Circuits/C4030.hpp"

#include <tuple>

namespace nts {

class Parser
{
  public:
    enum ReadState {
        UNDEFINED,
        CHIPSET,
        LINKS
    };
    static void setChipset(std::string input, nts::Circuit *board);
    static void linking(std::tuple<std::string, size_t> first, std::tuple<std::string, size_t> second, Circuit *board);
    static void setLinks(std::string input, Circuit *board);
    static void parse(std::string filePath, Circuit *board);
};

} // namespace nts

#endif //OOP_NANOTEKSPICE_2019_PARSER_HPP
