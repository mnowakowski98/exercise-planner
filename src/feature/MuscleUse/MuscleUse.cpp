#include "MuscleUse.h"

bool MuscleUse::IsMuscleUsed(Exercise& exercise, Muscle& muscle) {
    bool isMuscleUsed = false;

    vector<Muscle> muscles = exercise.exercisedMuscles;
    for(vector<Muscle>::iterator it = muscles.begin(); it != muscles.end(); ++it)
        if(it->name == muscle.name) isMuscleUsed = true;

    return isMuscleUsed;
}

vector<Muscle> MuscleUse::GetUnusedMuscles(vector<Exercise>& exercises, vector<Muscle>& muscles) {
    vector<Muscle> unusedMuscles = vector<Muscle>();
    for(vector<Muscle>::iterator muscleIt = muscles.begin(); muscleIt != muscles.end(); ++muscleIt) {
        bool isMuscleUsed = false;
        for(vector<Exercise>::iterator exerciseIt = exercises.begin(); exerciseIt != exercises.end(); ++exerciseIt)
            if(IsMuscleUsed(*exerciseIt, *muscleIt)) isMuscleUsed = true;

        if(!isMuscleUsed) unusedMuscles.push_back(*muscleIt);
    }

    return unusedMuscles;
}