#pragma once

#include <iostream>
// #include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
    const std::string name;
    bool sign;
    const int min_sign;
    const int min_exec;

    public:
    // Constructors, Destructors
    Form(std::string name, int min_sign, int min_exec);
    Form(const Form &other);
    ~Form();

    //Overload
    Form& operator=(const Form &other);

    //Getters
    std::string getName() const;
    bool isSigned() const;
    int getSignReq() const;
    int getExecReq() const;

    //Exceptions
    void GradeTooHighException() const;
    void GradeTooLowException() const;
    void FormAlreadySigned() const;

    //Signing
    void beSigned(const Bureaucrat &b);


};

std::ostream& operator<<(std::ostream &os, const Form &f);