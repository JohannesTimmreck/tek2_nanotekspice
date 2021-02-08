/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** description
*/

#ifndef OOP_NANOTEKSPICE_2019_EXEPTIONS_HPP
#define OOP_NANOTEKSPICE_2019_EXEPTIONS_HPP

#include <exception>
#include <string>

namespace nts {

class Exception : public std::exception
{
  protected:
    const char *_error;
  public:
    Exception(const char *str) : _error(str) {}
    ~Exception() = default;
    const char *what() const noexcept override {return _error;}
};

}

#endif //OOP_NANOTEKSPICE_2019_EXEPTIONS_HPP
