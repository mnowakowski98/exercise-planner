#pragma once

#include "Exercise.h"
#include "Muscle.h"

namespace MuscleUse {
    namespace LoadData {
        vector<Exercise> LoadExercises(string fileName);
        vector<Muscle> LoadMuscles(string fileName);
    }
}