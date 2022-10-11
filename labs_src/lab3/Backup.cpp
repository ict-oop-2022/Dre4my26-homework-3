#include "lab3.h"

Backup::Backup() {
    VirtualRepository _rep = VirtualRepository();
}

Backup::Backup(Repository rep) {
    _rep = rep;
}

BackupJob Backup::createBackupJob(vector<string> &files, string dir) {
    return BackupJob(files, dir);
}

void Backup::saveBackup(BackupJob backupJob) {
    vector<RestorePoint> points = backupJob.getRestorePoints();
    for(auto& point : points) {
        _rep.create(point);
    }
}

void Backup::update() {
    _rep.save();
}