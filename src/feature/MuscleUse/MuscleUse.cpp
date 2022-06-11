#include "MuscleUse.h"

bool MuscleUse::IsMuscleUsed(Exercise& exercise, Muscle& muscle) {
    auto isMuscleUsed = false;

    auto muscleNames = exercise.exercisedMuscleNames;
    for(auto it = muscleNames.begin(); it != muscleNames.end(); ++it)
        if(*it == muscle.name) isMuscleUsed = true;

    return isMuscleUsed;
}

vector<Muscle> MuscleUse::GetUnusedMuscles(vector<Exercise>& exercises, vector<Muscle>& muscles) {
    auto unusedMuscles = vector<Muscle>();
    for(auto muscleIt = muscles.begin(); muscleIt != muscles.end(); ++muscleIt) {
        auto isMuscleUsed = false;
        for(auto exerciseIt = exercises.begin(); exerciseIt != exercises.end(); ++exerciseIt)
            if(IsMuscleUsed(*exerciseIt, *muscleIt)) isMuscleUsed = true;

        if(!isMuscleUsed) unusedMuscles.push_back(*muscleIt);
    }

    return unusedMuscles;
}

vector<Muscle> MuscleUse::GetUsedMuscles(vector<Exercise>& exercises, vector<Muscle>& muscles) {
    auto usedMuscles = vector<Muscle>();
    for(vector<Muscle>::iterator muscleIt = muscles.begin(); muscleIt != muscles.end(); ++muscleIt) {
        auto isMuscleUsed = false;
        for(auto exerciseIt = exercises.begin(); exerciseIt != exercises.end(); ++exerciseIt)
            if(IsMuscleUsed(*exerciseIt, *muscleIt)) isMuscleUsed = true;

        if(isMuscleUsed) usedMuscles.push_back(*muscleIt);
    }

    return usedMuscles;
}