#include "lab3.h"

VirtualRepository::VirtualRepository(string dir) {
    _context = {};
    _dir = dir;
}

vector<RestorePoint> VirtualRepository::getRestorePoints() {
    return _context;
}

void VirtualRepository::create(RestorePoint point) {
    _context.emplace_back(point);
}

void VirtualRepository::remove(RestorePoint point) {
    vector<RestorePoint>::iterator it;
    it = std::remove(_context.begin(), _context.end(), point);
}

void VirtualRepository::save() {
    _context.clear();
}