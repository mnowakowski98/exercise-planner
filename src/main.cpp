#include <cstdlib>
#include <iostream>
#include <vector>

#include "feature/MuscleUse/MuscleUse.h"

using std::cout;
using std::endl;

int main(int, char**) {
    vector<Muscle> muscles = vector<Muscle>({
        {"Muscle1"},
        {"Muscle2"},
        {"Muscle3"}
    });

    vector<Exercise> exercises = vector<Exercise>({
        {"Exercise1", vector<Muscle>({muscles[0], muscles[2]})},
        {"Exercise2", vector<Muscle>({muscles[0]})}
    });

    vector<Muscle> unusedMuscles = MuscleUse::GetUnusedMuscles(exercises, muscles);
    for(vector<Muscle>::iterator it = unusedMuscles.begin(); it != unusedMuscles.end(); ++it)
        cout << it->name << endl;

    return EXIT_SUCCESS;
}
