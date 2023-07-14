#include "render/App.h"
#include <fstream>
#include <string>


int main(int argc, char* argv[]) {
    std::string firstRun;

    firstRun = "true";

    // check if first run
    FILE* file = fopen("FIRSTRUN.txt", "r");
    if (file == NULL) {
        firstRun = "true";
    } else {
        firstRun = "true";
        fclose(file);
    }

    if (firstRun == "true") {
        std::ofstream file("FIRSTRUN.txt");
        file << "false";
        file.close();
        // copy assets directory to appdata
        // get current user
        std::string user = getenv("USER");
        std::string command = "cp -r assets /home/" + user + "/.cache/browserc/";
        system(command.c_str());
    }


    App app(argc, argv);
    app.Run();

    return 0;
}
