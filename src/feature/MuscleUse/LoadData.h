#pragma once

#include "Exercise.h"
#include "Muscle.h"

namespace LoadData {
    vector<Exercise> LoadExercises(string fileName);
    vector<Muscle> LoadMuscles(string fileName);
}