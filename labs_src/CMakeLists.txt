add_library(labs lab3/Storage.cpp lab3/RestorePoint.cpp lab3/Backup.cpp lab3/BackupJob.cpp lab3/JobObject.cpp lab3/CreateStorage.cpp lab3/Repository.cpp lab3/SingleStorage.cpp lab3/SplitStorage.cpp lab3/VirtualRepository.cpp lab3/LocalRepository.cpp lab3/lab3.h)

target_sources(labs
        PRIVATE
        lab3/Storage.cpp
        lab3/RestorePoint.cpp
        lab3/Backup.cpp
        lab3/Repository.cpp
        lab3/JobObject.cpp
        lab3/BackupJob.cpp
        lab3/LocalRepository.cpp
        lab3/VirtualRepository.cpp
        lab3/CreateStorage.cpp
        lab3/SingleStorage.cpp
        lab3/SplitStorage.cpp
        PUBLIC
        lab3/lab3.h
        )

target_include_directories(labs
        PUBLIC
        .
        )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(labs
          PUBLIC
          "--coverage"
          )
  target_link_options(labs
          INTERFACE
          "--coverage"
          )
endif()
