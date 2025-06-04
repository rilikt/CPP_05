# 🗂️ C++ Module 05 – Repetition and Exceptions

This module focuses on **exception handling**, **class hierarchies**, and the power of **polymorphism** in C++. You’ll build a bureaucratic system full of forms, rules, and exception-ridden paper trails—introducing abstract classes and dynamic form generation.

---

## 📁 Exercises Overview

### 🧾 ex00 – Bureaucrat

- Create a `Bureaucrat` class with:
  - A constant `name`
  - A modifiable `grade` (1 to 150)
- Exceptions:
  - `GradeTooHighException`
  - `GradeTooLowException`
- Methods:
  - `incrementGrade()`, `decrementGrade()`
  - `operator<<` to display: `<name>, bureaucrat grade <grade>`

---

### 📄 ex01 – Form

- Add a `Form` class with:
  - `name`, `isSigned`, `gradeToSign`, `gradeToExecute`
- Methods:
  - `beSigned(Bureaucrat)`
  - `operator<<` to display form status
- Modify `Bureaucrat` with a `signForm()` function

---

### 🌲 ex02 – AForm + Concrete Forms

- Make `Form` abstract → rename to `AForm`
- Implement:
  - `ShrubberyCreationForm` → Creates ASCII tree file
  - `RobotomyRequestForm` → 50% robotomy success
  - `PresidentialPardonForm` → Pardon announcement
- Add `execute(Bureaucrat const &)` method
- Add `Bureaucrat::executeForm()` method

---

### 🧑‍💼 ex03 – Intern

- Create an `Intern` class
- Method: `makeForm(string formName, string target)`
- Dynamically creates correct form instance
- Clean implementation required (no long if/else chains)

---

## 🛠️ Build Instructions

```bash
make
```

Each exercise is inside its own folder: `ex00/`, `ex01/`, etc.

---
