#pragma once

#include <vector>

#include "Exercise.h"
#include "Muscle.h"

namespace MuscleUse {
    bool IsMuscleUsed(Exercise& exercise, Muscle& muscle);
    vector<Muscle> GetUnusedMuscles(vector<Exercise>& exercises, vector<Muscle>& muscles);
    vector<Muscle> GetUsedMuscles(vector<Exercise>& exercises, vector<Muscle>& muscles);
}