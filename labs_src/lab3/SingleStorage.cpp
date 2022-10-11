#include "lab3.h"

RestorePoint SingleStorage::addRestorePoint(vector<string> files, string name) {
    vector<Storage> point;
    point.emplace_back(files, name);
    return RestorePoint(point);
}