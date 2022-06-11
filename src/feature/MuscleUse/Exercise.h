#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Muscle;

struct Exercise {
    string name;
    vector<string> exercisedMuscleNames;
};