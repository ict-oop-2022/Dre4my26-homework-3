#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <iterator>
#include <filesystem>
#include <algorithm>

using namespace std::chrono;
using std::vector, std::string, std::remove;

class Storage {
private:
    vector<string> _dirs;
    string _name;

public:
    Storage(const vector<string> &dirs, const string &name);
    Storage() = default;
    Storage(const Storage &tmp) = default;
    friend bool operator==(const Storage &a, const Storage &b) {
        return a._dirs == b._dirs;
    }

    vector<string> getDirs() const;
    string getName() const;
};

class RestorePoint {
private:
    vector<Storage> _zipfiles;
    time_t _time;
public:
    RestorePoint();
    friend bool operator==(const RestorePoint &a, const RestorePoint &b) {
        return a._zipfiles == b._zipfiles;
    }
    RestorePoint(vector<Storage> &point);
    vector<Storage> getRestorePoint() const;
    void setRestorePoint(vector<Storage> &point);
};

class JobObject {
private:
    vector<string> _dirs;
public:
    JobObject() = default;
    JobObject(const vector<string> &dirs);

    vector<string> getDirs();
    void setDirs(vector<string> &dirs);
};

class CreateStorage {
public:
    virtual RestorePoint addRestorePoint(vector<string> files, string name);
};

class SingleStorage : public CreateStorage {
public:
    RestorePoint addRestorePoint(vector<string> files, string name) override;
};

class SplitStorage : public CreateStorage {
public:
    RestorePoint addRestorePoint(vector<string> files, string name) override;
};

class BackupJob {
private:
    string _name;
    vector<RestorePoint> _restorePoints;
    JobObject _jo;
public:
    BackupJob(string& name, vector<RestorePoint>& points, JobObject& jo);
    BackupJob(vector<string>& files, string& name);
    string getName();
    vector<RestorePoint> getRestorePoints();
    JobObject getJO();

    void createRestorePoint(SingleStorage algo);
    void createRestorePoint(SplitStorage algo);
    void addJobObject(vector<string> files);
    void removeJobObject(string file);
};

class Repository {
public:
    virtual void create(RestorePoint point);
    virtual void remove(RestorePoint point);
    virtual void save();
    virtual vector<RestorePoint> getRestorePoints();
};

class VirtualRepository : public Repository  {
private:
    vector<RestorePoint> _context;
    string _dir;
public:
    VirtualRepository(string dir = "/");

    void create(RestorePoint point) override;
    void remove(RestorePoint point) override;
    void save() override;
    vector<RestorePoint> getRestorePoints() override;
};

class LocalRepository : public Repository {
private:
    vector<RestorePoint> _context;
    string _dir;
    string _name;
public:
    LocalRepository(string dir, string name = "RestorePoint");
    LocalRepository(vector<RestorePoint> context);
    vector<RestorePoint> getRestorePoints() override;
    void create(RestorePoint point) override;
    void remove(RestorePoint point) override;
    void save() override;
};

class Backup {
private:
    Repository _rep;
public:
    Backup();
    Backup(Repository rep);

    BackupJob createBackupJob(vector<string> &files, string dir = "Resource");
    void saveBackup(BackupJob backupJob);
    void update();
};