#include "plugin.h"
#include <iostream>

using namespace std;

namespace HTW {
    namespace AI {
        namespace Beleg {
            namespace Plugin {

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
                    cout << "Fecking Plugin called" << endl;
                    return pInfo;
                }

                void interactiveAdd() {
                    // TODO: implement

                    cout << "Gib eine neue Person ein" << endl;
                    // TODO: Eingabe aller Daten und Fehlerüberprüfung

                    Person* newPerson = new Person();
                    
                    bool finished = false;
                    do {
                        // eingaben hier
                        // wenn die eingabe korrekt ist, dann finished = true
                    } while(!finished);

                    if (HTW::AI::Beleg::add(newPerson)) {
                        cout << "Person erfolgreich gespeichert." << endl;
                    } else {
                        cout << "Fehler beim anlegen" << endl;
                    }
                }

            }
        }
    }
}
