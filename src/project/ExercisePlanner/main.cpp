#include <cstdlib>
#include <iostream>
#include <vector>

#include "feature/MuscleUse/MuscleUse.h"
#include "feature/MuscleUse/LoadData.h"

using std::cin;
using std::cout;
using std::endl;

int main(int, char**) {
    // vector<Muscle> muscles = vector<Muscle>({
    //     {"Muscle1"},
    //     {"Muscle2"},
    //     {"Muscle3"}
    // });

    auto muscles = LoadData::LoadMuscles("muscles.json");

    auto exercises = LoadData::LoadExercises("exercises.json");

    string command;
    cin >> command;

    if(command == "unused") {
        cout << "Unused muscles: " << endl;
        vector<Muscle> unusedMuscles = MuscleUse::GetUnusedMuscles(exercises, muscles);
        for(vector<Muscle>::iterator it = unusedMuscles.begin(); it != unusedMuscles.end(); ++it)
            cout << it->name << endl;
    } else if (command == "used") {
        cout << "\nUsed muscles: " << endl;
        vector<Muscle> usedMuscles = MuscleUse::GetUsedMuscles(exercises, muscles);
        for(vector<Muscle>::iterator it = usedMuscles.begin(); it != usedMuscles.end(); ++it)
            cout << it->name << endl;
    } else cout << "Unknown" << endl;

    return EXIT_SUCCESS;
}
