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
#include <dlfcn.h>
#include <string>
#include <map>
#include <vector>

using namespace std;
using namespace HTW::AI::Beleg;
using namespace HTW::AI::Beleg::Plugin;

vector<void*> handles;

struct MenueEntry {
    void* handle;
    struct plugin_f_info* info;
};

map<int, MenueEntry*> menueItems;

/**
 * Prints the common menu which contains the basic functionality which is provided by the list api
 */
void printMenu();

/**
 * Generates a menu depending on the loaded modules.
 */
void generateMenue();

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

void testSo() {
    char* error;

    void* handle = dlopen("plugins/libinteractive-add-plugin.so", RTLD_LAZY);
    error = dlerror();
    if (error) {
        cout << "Error when loading the lib" << endl;
        exit(1);
    }

    plugin_info_f_t fuPointer = (plugin_info_f_t) dlsym(handle, PLUGIN_INFO_F_NAME);
    plugin_info_struct infoStruct = fuPointer();

    cout << "P: " << infoStruct.info[0].name << endl;
    //    plugin_f_t functionP = (plugin_f_t) dlsym(handle, infoStruct.info[0].name);    
    ListPerson* list;
}

/*
 * @See: http://stackoverflow.com/questions/1142103/how-do-i-load-a-shared-object-in-c
 * @See: http://www.willemer.de/informatik/cpp/stl.htm
 * @See: http://www.infernodevelopment.com/how-create-dll-c-using-run-time-dynamic-linking
 * @See: http://www.learncpp.com/cpp-tutorial/a1-static-and-dynamic-libraries/
 * @See: http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html
 * @See: http://stackoverflow.com/questions/496664/c-dynamic-shared-library-on-linux
 * @See: http://www.faqs.org/docs/Linux-mini/C++-dlopen.html
 * @See: http://bartgrantham.com/articles/dynamic-libraries-in-c-and-c/
 */
int main(int argc, char** argv) {
    
    //    char* error;
    //
    //    // initial load liblibapi.so
    //    void* handle = dlopen("./liblibapi.so", RTLD_LAZY);
    //    // check for error opening the lib
    //    error = dlerror();
    //    if (error) {
    //        cout << error << endl;
    //        return 1;
    //    }
    //
    //    //    f_point getList = (f_point) dlsym(handle, "_Z7getListv");    
    //    f_point getList = (f_point) dlsym(handle, "_Z7getListv");
    //    error = dlerror();
    //    if (error) {
    //        cout << error << endl;
    //        return 1;
    //    }
    //
    //    bool done = false;
    //
    //    loadModules();
    //
    //    while (!done) {
    //        printCommonMenu();
    //        int input = getMenuInput();
    //        switch (input) {
    //            case 0:
    //                done = true;
    //                break;
    //            case 1:
    //                ListPerson* list = getList();
    //                cout << list << endl;
    //                break;
    //        }
    //    }
    //
    //    dlclose(handle);
    //
    //    cout << "handles size" << handles.size() << endl;

    plugin_info_struct result;
    result = plugin_info();
    loadModules();
    generateMenue();
    printMenu();

    return 0;
}

void printMenu() {

    cout << "Menü" << endl;
    cout << endl;
    
    
//    cout << "1: add Element" << endl;
//    cout << "2: remove Element" << endl;
//    cout << "3: insert Element before" << endl;
//    cout << "4: insert Element after" << endl;
    
    map<int, MenueEntry*>::iterator iter;
    for (iter = menueItems.begin(); iter != menueItems.end(); ++iter) {
        cout << iter->first << ":" << iter->second->info->description << endl;
    }
    
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
    char* error;

    while (pdir = readdir(dir)) {
        //        cout << pdir->d_name << endl; // working..... load only special files
        string fileName = pdir->d_name;
        // analyze if the first three chars are lib
        // see if the name contains .so
        // if this is the case load lib
        if ((fileName.compare(0, 3, "lib") == 0) && (fileName.find(".so", 0))) {
            string openFileWithDirectory = "plugins/" + fileName;

            void* handle = dlopen(openFileWithDirectory.c_str(), RTLD_LAZY);
            error = dlerror();
            if (error) {
                cout << "An error occured when opening a shared library: " << error << endl;
                // print error and continue. If lib can not be loaded then it is gods will ;)
                continue;
            }

            handles.push_back(handle);
        }
    }

    closedir(dir);
}

void generateMenue() {

    cout << "Enter generate Menu" << endl;
    
    menueItems.clear(); // perhaps a bad idea. Free memory????
    int menueCount(1);

    for (vector<void*>::iterator it = handles.begin(); it != handles.end(); ++it) {
        cout << "Loop" << endl;
        // so for each handle get plugin_information and create menue items
        plugin_info_f_t pluginInfoPointer = (plugin_info_f_t) dlsym(*it, PLUGIN_INFO_F_NAME);
        plugin_info_struct infoStruct = pluginInfoPointer();
        for (int i = 0; i < infoStruct.num; i++) {
            MenueEntry* entry = new MenueEntry();
            entry->handle = *it;
            entry->info = &infoStruct.info[i];
//            menueItems[menueCount] = entry;
            menueItems.insert(pair<int, MenueEntry*>(menueCount, entry));
            menueCount++;
        }
    }
}

