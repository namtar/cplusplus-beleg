#include "plugin.h"
#include <iostream>

//using namespace std;
using namespace HTW::AI::Beleg::Plugin;

plugin_info_struct pInfo;
plugin_f_info infoArr[1];
bool called = false;

/**
 * Adds a new Person interactiveally to the list.
 */
void interactiveAdd();

/**
 * {@inheritDoc}
 */
plugin_info_struct plugin_info() {

    if (!called) {
        pInfo.num = 1;

        pInfo.info = infoArr;

        infoArr[0].description = "Interactive add of a person list entry.";
        infoArr[0].name = "interactiveAdd";
        called = true;
    }
    return pInfo;
}

void interactiveAdd() {

    // TODO: implement
    std::cout << "Test";
}
