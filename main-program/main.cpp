/* 
 * File:   main.cpp
 * Author: drummer
 *
 * Created on 31. Mai 2014, 14:56
 */

#include <cstdlib>
#include <iostream>
#include "plugin.h"

using namespace std;

/**
 * Prints the common menu which contains the basic functionality which is provided by the list api
 */
void printCommonMenu();

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

    printCommonMenu();
    return 0;
}

void printCommonMenu() {

    cout << "Menü" << endl;
    cout << endl;
    cout << "1: add Element" << endl;
    cout << "2: remove Element" << endl;
    cout << "3: insert Element before" << endl;
    cout << "4: insert Element after" << endl;
}

