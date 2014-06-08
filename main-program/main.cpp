/* 
 * File:   main.cpp
 * Author: drummer
 *
 * Created on 31. Mai 2014, 14:56
 */

#include <cstdlib>
#include <iostream>
#include <dirent.h>
#include "plugin.h"

using namespace std;

/**
 * Prints the common menu which contains the basic functionality which is provided by the list api
 */
void printCommonMenu();

/**
 * Gets the user input from the menue.
 * 
 * @return the chosen menu entry index
 */
int getMenuInput();

/**
 * Loads the modules from the pluginsfolder and adds the handles to a list.
 */
void loadModules();

/*
 * @See: http://stackoverflow.com/questions/1142103/how-do-i-load-a-shared-object-in-c
 * @See: http://www.willemer.de/informatik/cpp/stl.htm
 * @See: http://www.infernodevelopment.com/how-create-dll-c-using-run-time-dynamic-linking
 * @See: http://www.learncpp.com/cpp-tutorial/a1-static-and-dynamic-libraries/
 * @See: http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html
 * @See: http://stackoverflow.com/questions/496664/c-dynamic-shared-library-on-linux
 * @See: http://www.faqs.org/docs/Linux-mini/C++-dlopen.html
 */
int main(int argc, char** argv) {

    bool done = false;
    
    loadModules();

    while (!done) {
        printCommonMenu();
        int input = getMenuInput();
        switch (input) {
            case 0:
                done = true;
                break;
        }
    }

    return 0;
}

void printCommonMenu() {

    cout << "Menü" << endl;
    cout << endl;
    cout << "1: add Element" << endl;
    cout << "2: remove Element" << endl;
    cout << "3: insert Element before" << endl;
    cout << "4: insert Element after" << endl;
    cout << "0: End program" << endl;
}

int getMenuInput() {

    cout << "Choose: ";
    int input = -1;
    cin >> input;

    // TODO: do some validation here. perhaps put it all in a loop until a valid menu entry has been chosen
    return input;
}

void loadModules() {

    DIR* dir = opendir("plugins");
    dirent* pdir;

    while (pdir = readdir(dir)) {
        cout << pdir->d_name << endl; // working..... load only special files
    }

    closedir(dir);

    // open plugins folder
    // see what files are in it
    // try to load so
    // verify that it has the correct header

    // store it in a structure so that the menu can get generated dynamically
}

