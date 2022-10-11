#include "lab3.h"

JobObject::JobObject(const vector<string> &dirs) {
    _dirs = dirs;
}

vector<string> JobObject::getDirs() {
    return _dirs;
}

void JobObject::setDirs(vector<string> &dirs) {
    _dirs = dirs;
}