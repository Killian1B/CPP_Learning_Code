#pragma once

#include <ostream>
#include <string>
#include <string_view>
#include <set>
#include <vector>

class Teacher
{
public:
    Teacher(std::string_view name)
        : _name { name }
    {
    }

    friend std::ostream& operator<<(std::ostream& stream, const Teacher& teacher)
    {
        return stream << teacher._name;
    }

    friend bool operator==(const Teacher* teacher, const std::string& name)
    {
        return teacher->_name == name;
    }

private:
    const std::string _name;
};

class Subject
{
public:
    Subject(std::string_view name)
        : _name { name }
    {
    }

    void add_teacher(const Teacher& teacher)
    {
        _teachers.insert(&teacher);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Subject& subject)
    {
        stream << "-> Subject " << subject._name << " teached by: ";

        for (const auto* teacher : subject._teachers)
        {
            stream << *teacher << ", ";
        }

        return stream;
    }

    void remove_teacher(const Teacher& teacher)
    {
        _teachers.erase(&teacher);
    }

private:
    const std::string _name;
    std::set<const Teacher*> _teachers;
};

class Curriculum
{
public:
    Curriculum(std::string_view name)
        : _name { name }
    {}

    void add_subject(const Subject& subject)
    {
        _subjects.insert(&subject);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Curriculum& curriculum)
    {
        stream << "Curriculum <" << curriculum._name << ">";

        for (const auto* subject : curriculum._subjects)
        {
            stream << *subject << std::endl;
        }

        return stream;
    }

    friend bool operator==(const Curriculum* curriculum, const std::string& name)
    {
        return curriculum->_name == name;
    }

private:
    const std::string _name;
    std::set<const Subject*> _subjects;
};
