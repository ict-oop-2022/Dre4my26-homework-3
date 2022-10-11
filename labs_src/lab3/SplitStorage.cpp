#include "lab3.h"

RestorePoint SplitStorage::addRestorePoint(vector<string> files, string name) {
    vector<Storage> point;
    int count = 0;
    for (const string& file : files) {
        count++;
        vector<string> storage;
        storage.emplace_back(file);
        point.emplace_back(storage, name+std::to_string(count));
    }
    return RestorePoint(point);
}