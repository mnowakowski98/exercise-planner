#include "LoadData.h"

#include <fstream>
#include <foundation/nlohmann/json.hpp>

using json = nlohmann::json;
using std::ifstream;

vector<Exercise> MuscleUse::LoadData::LoadExercises(string fileName) {
    auto exercises = vector<Exercise>();

    ifstream exercisesFile(fileName);

    json exercisesJson;
    exercisesFile >> exercisesJson;
    for(auto& exerciseNode : exercisesJson["exercises"]) {
        auto exercise = Exercise();
        exercise.name = exerciseNode["name"].get<string>();
        for(auto muscleName : exerciseNode["exercisedMuscles"])
            exercise.exercisedMuscleNames.push_back(muscleName.get<string>());

        exercises.push_back(exercise);
    }

    exercisesFile.close();

    return exercises;
}

vector<Muscle> MuscleUse::LoadData::LoadMuscles(string fileName) {
    auto muscles = vector<Muscle>();

    ifstream musclesFile(fileName);

    json musclesJson;
    musclesFile >> musclesJson;
    for(auto& muscleNode : musclesJson["muscles"]) {
        auto muscle = Muscle();
        muscle.name = muscleNode["name"].get<string>();
        muscles.push_back(muscle);
    }

    musclesFile.close();

    return muscles;
}