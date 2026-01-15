#define NOB_IMPLEMENTATION

#include "nob.h"

#define BUILD_FOLDER "build/"
#define SRC_FOLDER   "src/"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    if (!nob_mkdir_if_not_exists(BUILD_FOLDER)) return 1;

    Nob_Cmd cmd = {0};

    // nob_cmd_append(&cmd, "clang++", "-Wall", "-Wextra", "-o", BUILD_FOLDER"main", SRC_FOLDER"main.cpp");
    // nob_cmd_append(&cmd, "-I./raylib/include");
    // nob_cmd_append(&cmd, "./raylib/lib/libraylib.a");
    // // nob_cmd_append(&cmd, "-L./raylib/lib");
    // // nob_cmd_append(&cmd, "-lraylib");
    // nob_cmd_append(&cmd, "-framework", "OpenGL");
    // nob_cmd_append(&cmd, "-framework", "Cocoa");
    // nob_cmd_append(&cmd, "-framework", "IOKit");
    // nob_cmd_append(&cmd, "-framework", "CoreVideo");
    //

    nob_cmd_append(&cmd, "clang++", "-Wall", "-Wextra", "-o", BUILD_FOLDER"view", SRC_FOLDER"view.cpp");
    nob_cmd_append(&cmd, "-I./raylib/include");
    nob_cmd_append(&cmd, "./raylib/lib/libraylib.a");
    nob_cmd_append(&cmd, "-framework", "OpenGL");
    nob_cmd_append(&cmd, "-framework", "Cocoa");
    nob_cmd_append(&cmd, "-framework", "IOKit");
    nob_cmd_append(&cmd, "-framework", "CoreVideo");

    if (!nob_cmd_run(&cmd)) return 1;

    cmd.count = 0;

    nob_cmd_append(&cmd, "./build/view");
    if (!nob_cmd_run(&cmd)) return 1;

    cmd.count = 0;

    // nob_cmd_append(&cmd, "clear");
    // if (!nob_cmd_run(&cmd)) return 1;

    return 0;
}
