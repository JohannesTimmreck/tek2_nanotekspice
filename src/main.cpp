/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#include "../include/Parser.hpp"
#include "../include/IComponent.hpp"
#include "../include/Circuits/Circuit.hpp"
#include "../include/Exception.hpp"

#include <iostream>
#include <csignal>
#include <string>

bool LOOP;

void signalHandler( int signum ) {
   LOOP = false;
   (void) signum;
   signal(SIGINT, signalHandler);
}

void display(nts::Circuit *list)
{
    list->display();
}

void simulate(nts::Circuit *list)
{
    list->compute();
}

void dump(nts::Circuit *list)
{
    list->dump();
}

void loop(nts::Circuit *list)
{
    LOOP = true;
    signal(SIGINT, signalHandler);
    while (LOOP == true)
        simulate(list);
    signal(SIGINT, SIG_DFL);
}

void change_input(nts::Circuit *list, std::string line)
{
    std::string input = line.substr(0, line.find('='));
    std::string newvalue = line.substr(line.find('=')+1, line.size());
    for(size_t x = 0; x != newvalue.size(); x++) {
        if (newvalue[x] < 48 || newvalue[x] > 57)
            return;
    }
    if (std::stoi(newvalue) > 1 || std::stoi(newvalue) < 0)
        return;
    if (newvalue == "1")
        list->change_input(input, nts::Tristate::TRUE);
    else
        list->change_input(input, nts::Tristate::FALSE);
}

void compute_input(std::string line, nts::Circuit *list, bool *exit_condition)
{
    if (line.compare("exit") == false)
        *exit_condition = false;
    else if (line.compare("display") == false)
        display(list);
    else if (line.find("=") != std::string::npos)
        change_input(list, line);
    else if (line.compare("simulate") == false)
        simulate(list);
    else if (line.compare("loop") == false)
        loop(list);
    else if (line.compare("dump") == false)
        dump(list);
}

int test_command_line(int ac, char **argv, nts::Circuit *list)
{
    std::vector<std::shared_ptr<nts::IComponent>> components = list->get();
    std::string tmp;
    size_t counter = 0;

    //test if input value is known
    for (int x = 2; x != ac; x++) {
        tmp = argv[x];
        if (tmp.find("=") == std::string::npos) {
            std::cerr << "Error: Argument '" << tmp << "' has invalid syntax, please provide input as followed: input=value" << std::endl;
            return (-1);
        }
        tmp = tmp.substr(tmp.find('=')+1, tmp.size());
        if (tmp.compare("1") != 0 && tmp.compare("0") != 0) {
            std::cerr << "Error: Input value '" << tmp << "' not known, give '1' for true and '0' for false" << std::endl;
            return (-1);
        }
    }
    
    //test if all input is known
    for (int x = 2; x != ac; x++) {
        tmp = argv[x];
        tmp = tmp.substr(0, tmp.find('='));
        for (size_t i = 0; i != list->getComponentsAmount(); i++) {
            if ((components.at(i)->getType() == "input" && components.at(i)->getName() == tmp) ||
                (components.at(i)->getType() == "clock" && components.at(i)->getName() == tmp))
                counter++;
        }
        if (counter == 0) {
            std::cerr << "Error: Given input '" << tmp << "' is not known by the circuit" << std::endl;
            return (-1);
        }
        counter = 0;
    }

    //test if one input is not given
    for (size_t i = 0; i != list->getComponentsAmount(); i++) {
        if (components.at(i)->getType() == "input" ||
            components.at(i)->getType() == "clock") { 
            for (int x = 2; x != ac; x++) {
                tmp = argv[x];
                tmp = tmp.substr(0, tmp.find('='));
                if (tmp.compare(components.at(i)->getName()) == 0)
                    counter++;
            }
            if (counter == 0) {
                std::cerr << "Error: One or multiple inputs are not given" << std::endl;
                return -1;
            }
            counter = 0;
        }
    }
    return (0);
}

void apply_command_line(int ac, char **argv, nts::Circuit *list)
{
    std::vector<std::shared_ptr<nts::IComponent>> components = list->get();
    std::string tmp;
    std::string input;
    std::string newvalue;
    nts::Tristate value;

    for (int x = 2; x != ac; x++) {
        tmp = argv[x];
        input = tmp.substr(0, tmp.find('='));
        newvalue = tmp.substr(tmp.find('=')+1, tmp.size());
        if (newvalue == "1")
            value = nts::Tristate::TRUE;
        else
            value =  nts::Tristate::FALSE;

        for (size_t i = 0; i != list->getComponentsAmount(); i++) {
            if (components.at(i)->getType() == "input" || components.at(i)->getType() == "clock") {
                if (components.at(i)->getName() == input) {
                    components.at(i)->setInput(1, value);
                    break;
                }
            }
        }
    }
}

int main(int ac, char **argv)
{
    try {
        std::string line;
        if (ac < 2)
            throw nts::Exception("no file given");
        nts::Circuit list("board");
        bool exit_condition = true;
        nts::Parser::parse(argv[1], &list);
        if (test_command_line(ac, argv, &list) == -1)
            throw nts::Exception("wrong input on command line");
        apply_command_line(ac, argv, &list);
        simulate(&list);
        display(&list);
        while (exit_condition) {
            std::cout << "> ";
            std::getline(std::cin, line);
            std::cout << line << std::endl;
            if (std::cin.eof()) {
                std::cout << std::endl;
                break;
            }
            compute_input(line, &list, &exit_condition);
        }
    } catch (const nts::Exception &e) {
        std::cerr << "Catched Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}