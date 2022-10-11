#include "lab3.h"

LocalRepository::LocalRepository(vector<RestorePoint> context) {
    _context = context;
}

LocalRepository::LocalRepository(string dir, string name) {
    _context = {};
    _dir = dir;
    _name = name;
}

vector<RestorePoint> LocalRepository::getRestorePoints() {
    return _context;
}

void LocalRepository::create(RestorePoint point) {
    _context.emplace_back(point);
}

void LocalRepository::remove(RestorePoint point) {
    vector<RestorePoint>::iterator it;
    it = std::remove(_context.begin(), _context.end(), point);
}

void LocalRepository::save() {

}