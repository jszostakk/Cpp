#include "../include/Student.h"

void Student::setName ( string name )
{
    this->name = name;
}

string Student::getName ()
{
    return name;
}

void Student::setSurname ( string surname )
{
    this->name = name;
}

string Student::getSurname ()
{
    return surname;
}

void Student::setAlbum ( int album )
{
    this->album = album;
}

int Student::getAlbum ()
{
    return album;
}

void Student::setQuestions( int questions )
{
    this->questions = questions;
}

int Student::getQuestions()
{
    return questions;
}

void Student::setAnswers( int answers )
{
    this->answers = answers;
}

int Student::getAnswers()
{
    return answers;
}

void Student::percentage(int questions, int answers)
{
    cout << "Result: " << questions * answers << "%" << endl;
}