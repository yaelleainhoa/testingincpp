#include <gtest/gtest.h>
#include "../src/student_evaluation.hpp"

// Structure pour les paramètres de test
struct EvaluationParam {
    int course;
    int exam;
    char expectedGrade;
};

// Test paramétré pour les évaluations valides
class StudentEvaluationTest : public ::testing::TestWithParam<EvaluationParam> {};

TEST_P(StudentEvaluationTest, ValidEvaluation) {
    EvaluationParam param = GetParam();
    EXPECT_EQ(StudentEvaluation::evaluate(param.course, param.exam), param.expectedGrade);
}

INSTANTIATE_TEST_SUITE_P(
    ValidGrades,
    StudentEvaluationTest,
    ::testing::Values(
        // Grade D (total < 30)
        EvaluationParam{0, 0, 'D'},
        EvaluationParam{0, 29, 'D'},
        EvaluationParam{10, 19, 'D'}, // 10 + 19 = 29
        // Grade C (30 <= total < 50)
        EvaluationParam{0, 30, 'C'},
        EvaluationParam{10, 39, 'C'}, // 10 + 39 = 49
        // Grade B (50 <= total < 70)
        EvaluationParam{25, 25, 'B'}, // 25 + 25 = 50
        EvaluationParam{20, 49, 'B'}, // 20 + 49 = 69
        // Grade A (70 <= total <= 100)
        EvaluationParam{25, 45, 'A'}, // 25 + 45 = 70
        EvaluationParam{25, 75, 'A'}  // 25 + 75 = 100
    )
);

// Tests négatifs : vérification que les valeurs hors bornes lèvent bien une exception
TEST(StudentEvaluationExceptionTest, CourseNoteOutOfRangeNegative) {
    EXPECT_THROW(StudentEvaluation::evaluate(-1, 50), std::out_of_range);
}

TEST(StudentEvaluationExceptionTest, CourseNoteOutOfRangeTooHigh) {
    EXPECT_THROW(StudentEvaluation::evaluate(26, 50), std::out_of_range);
}

TEST(StudentEvaluationExceptionTest, ExamNoteOutOfRangeNegative) {
    EXPECT_THROW(StudentEvaluation::evaluate(10, -1), std::out_of_range);
}

TEST(StudentEvaluationExceptionTest, ExamNoteOutOfRangeTooHigh) {
    EXPECT_THROW(StudentEvaluation::evaluate(10, 76), std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
