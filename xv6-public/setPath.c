#include "types.h"
#include "stat.h"
#include "user.h"

void setDirectoriesToPath (char *newPaths) {
    int pathIndex = 0, stringIndex = 0;
    char path[128] = {};
    while (newPaths[stringIndex] != '\0') {
        if (newPaths[stringIndex] == ':' && pathIndex > 0) {
            path[pathIndex] = '\0';
            if (setPath (path) != 0)
                exit();
            pathIndex = 0;
        }
        else {
            path[pathIndex] = newPaths[stringIndex];
            pathIndex++;
        }
        stringIndex++;
    }
    if (pathIndex != 0) {
        path[pathIndex] = '\0';
        if (setPath (path) != 0)
            exit();
    }
}

int main (int argc, char **argv) {
    if (argc != 2) {
        printf(1, "wrong command, use below command to add your paths to exec repositories:\nsetPath path1:path2:path3:...\n");
        exit();
    }
    setDirectoriesToPath (argv[1]);
    exit();
}