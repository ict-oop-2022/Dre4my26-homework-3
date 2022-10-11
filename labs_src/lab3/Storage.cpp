#include "lab3.h"

Storage::Storage(const vector<string> &dirs, const string &name) {
    _dirs = dirs;
    _name = name;
}

vector<string> Storage::getDirs() const {
    return _dirs;
}

string Storage::getName() const {
    return _name;
}