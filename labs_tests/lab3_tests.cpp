#include <gtest/gtest.h>
#include "lab3/lab3.h"

Backup back = Backup();
vector<string> files1 = vector<string> {"FileA", "FileB"};
vector<string> files2 = vector<string> {"/home/fileABC", "/gr3gorie/file123"};
string dir = "/test/";
SingleStorage single = SingleStorage();
SplitStorage split = SplitStorage();

TEST(CreateBackups, TwoRestorePointsAndThreeStoragesCreated) {
    BackupJob backupJob = Backup().createBackupJob(files1, dir);
    backupJob.createRestorePoint(split);
    backupJob.removeJobObject("FileB");
    backupJob.createRestorePoint(split);
    vector<RestorePoint> points = backupJob.getRestorePoints();
    ASSERT_EQ(2, points.size());
    int storages = 0;
    for (auto& it : points)
        storages += it.getRestorePoint().size();
    ASSERT_EQ(3, storages);
}
