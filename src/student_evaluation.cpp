#include "student_evaluation.hpp"

char StudentEvaluation::evaluate(int course, int exam) {
    // Vérification des préconditions
    if (course < 0 || course > 25) {
        throw std::out_of_range("La note de cours doit être comprise entre 0 et 25.");
    }
    if (exam < 0 || exam > 75) {
        throw std::out_of_range("La note d'examen doit être comprise entre 0 et 75.");
    }
    
    int total = course + exam;
    // Détermination de l'évaluation selon la somme des notes
    if (total < 30) {
        return 'D';
    } else if (total < 50) {
        return 'C';
    } else if (total < 70) {
        return 'B';
    } else { // total entre 70 et 100
        return 'A';
    }
}

static int triggerWarning() {
    int uninitializedVariable;  // Variable déclarée sans initialisation
    return uninitializedVariable; // Utilisation d'une variable non initialisée
}