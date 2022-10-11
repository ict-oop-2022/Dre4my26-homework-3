#include "lab3.h"

BackupJob::BackupJob(string& name, vector<RestorePoint>& points, JobObject& jo) {
    _name = name;
    _restorePoints = points;
    _jo = jo;
}

BackupJob::BackupJob(vector<string>& files, string& name) {
    _name = name;
    _jo = JobObject(files);
    _restorePoints = {};
}

string BackupJob::getName() {
    return _name;
}

vector<RestorePoint> BackupJob::getRestorePoints() {
    return _restorePoints;
}

JobObject BackupJob::getJO() {
    JobObject jo = JobObject(_jo.getDirs());
    return jo;
}

void BackupJob::createRestorePoint(SplitStorage algo) {
    _restorePoints.emplace_back(algo.addRestorePoint(_jo.getDirs(), _name));
}

void BackupJob::createRestorePoint(SingleStorage algo) {
    _restorePoints.emplace_back(algo.addRestorePoint(_jo.getDirs(), _name));
}

void BackupJob::addJobObject(vector<string> files) {
    vector<string> jobfiles = _jo.getDirs();
    std::move(files.begin(), files.end(), std::back_inserter(jobfiles));
    _jo.setDirs(jobfiles);
}

void BackupJob::removeJobObject(string file) {
    vector<string> jobfiles = _jo.getDirs();
    jobfiles.erase(std::remove(jobfiles.begin(), jobfiles.end(), file), jobfiles.end());
    _jo.setDirs(jobfiles);
}
