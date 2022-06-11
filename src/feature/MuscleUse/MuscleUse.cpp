#include "MuscleUse.h"

bool MuscleUse::IsMuscleUsed(Exercise& exercise, Muscle& muscle) {
    bool isMuscleUsed = false;

    vector<string> muscleNames = exercise.exercisedMuscleNames;
    for(vector<string>::iterator it = muscleNames.begin(); it != muscleNames.end(); ++it)
        if(*it == muscle.name) isMuscleUsed = true;

    return isMuscleUsed;
}

vector<Muscle> MuscleUse::GetUnusedMuscles(vector<Exercise>& exercises, vector<Muscle>& muscles) {
    auto unusedMuscles = vector<Muscle>();
    for(auto muscleIt = muscles.begin(); muscleIt != muscles.end(); ++muscleIt) {
        bool isMuscleUsed = false;
        for(vector<Exercise>::iterator exerciseIt = exercises.begin(); exerciseIt != exercises.end(); ++exerciseIt)
            if(IsMuscleUsed(*exerciseIt, *muscleIt)) isMuscleUsed = true;

        if(!isMuscleUsed) unusedMuscles.push_back(*muscleIt);
    }

    return unusedMuscles;
}

vector<Muscle> MuscleUse::GetUsedMuscles(vector<Exercise>& exercises, vector<Muscle>& muscles) {
    vector<Muscle> usedMuscles = vector<Muscle>();
    for(vector<Muscle>::iterator muscleIt = muscles.begin(); muscleIt != muscles.end(); ++muscleIt) {
        bool isMuscleUsed = false;
        for(vector<Exercise>::iterator exerciseIt = exercises.begin(); exerciseIt != exercises.end(); ++exerciseIt)
            if(IsMuscleUsed(*exerciseIt, *muscleIt)) isMuscleUsed = true;

        if(isMuscleUsed) usedMuscles.push_back(*muscleIt);
    }

    return usedMuscles;
}