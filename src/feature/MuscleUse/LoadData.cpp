#include "LoadData.h"

#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using std::ifstream;

vector<Exercise> LoadData::LoadExercises(string fileName) {
    vector<Exercise> exercises = vector<Exercise>();

    ifstream exercisesFile(fileName);

    json exercisesJson;
    exercisesFile >> exercisesJson;
    for(auto& exerciseNode : exercisesJson["exercises"]) {
        auto exercise = Exercise();
        exercise.name = exerciseNode["name"].get<string>();
        exercises.push_back(exercise);
    }

    exercisesFile.close();

    return exercises;
}