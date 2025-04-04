#ifndef STUDENT_EVALUATION_HPP
#define STUDENT_EVALUATION_HPP

#include <stdexcept>
#include <string>

class StudentEvaluation {
public:
    // Calcule et renvoie l'évaluation ('A', 'B', 'C' ou 'D')
    // course : note de cours (0 à 25)
    // exam   : note d'examen (0 à 75)
    static char evaluate(int course, int exam);
};

#endif // STUDENT_EVALUATION_HPP

