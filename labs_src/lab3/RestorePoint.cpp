#include "lab3.h"

RestorePoint::RestorePoint() {
    _zipfiles = vector<Storage>();
    _time = time(nullptr);
}

RestorePoint::RestorePoint(vector<Storage> &point) {
    _zipfiles = point;
    _time = time(nullptr);
}

vector<Storage> RestorePoint::getRestorePoint() const {
    return _zipfiles;
}

void RestorePoint::setRestorePoint(vector<Storage> &point) {
    _zipfiles = point;
    _time = time(nullptr);
}
