#ifndef ZESTAW2_STUDENT_H
#define ZESTAW2_STUDENT_H

#include <iostream>
using namespace std;

class Student
{
private:
    string name, surname;
    int album, questions, answers;

public:
    void setName ( string name );
    string getName ();

    void setSurname ( string surname );
    string getSurname ();

    void setAlbum ( int album );
    int getAlbum ();

    void setQuestions ( int questions );
    int getQuestions ();

    void setAnswers ( int answers );
    int getAnswers ();

    void percentage( int questions, int answers );
};


#endif //ZESTAW2_STUDENT_H
