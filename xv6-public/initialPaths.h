// #include "execPath.h"
// #include "user.h"
// #include "types.h"
// #include "fcntl.h"


// void
// loadPaths () {
//     int pathIndex = 0, arrayIndex = 0, stringIndex = 0;
//     char str[1280];
//     int fileDescriptor = open(PATHFILE, O_RDONLY);

//     if (fileDescriptor < 0) {
//         char defaultPath[20] = "/\n";
//         fileDescriptor = open(PATHFILE, O_CREATE | O_WRONLY);
//         write (fileDescriptor, defaultPath, sizeof(defaultPath));
//         close (fileDescriptor);
//         fileDescriptor = open(PATHFILE, O_RDONLY);
//     }
//     read (fileDescriptor, str, sizeof(str));
//     close (fileDescriptor);
//     while (str[stringIndex] != '\0') {
//         if (str[stringIndex] == '\n') {
//             execPath.paths[arrayIndex][pathIndex] = '\0';
//             pathIndex = 0;
//             execPath.pathDefinedNumbers++;
//         }
//         else 
//             execPath.paths[arrayIndex][pathIndex] = str[stringIndex];
//         arrayIndex++;
//         stringIndex++;
//     }
// }


// void
// initalExecPath () {
//     execPath.pathDefinedNumbers = 0;
//     loadPaths();
// }


