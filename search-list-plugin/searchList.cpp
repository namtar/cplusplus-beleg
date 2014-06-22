#include "plugin.h"
#include "searchList.h"
#include <string>
#include <iostream>
#include <string.h>
#include <iomanip>
#include "list_api_extended.h"

using namespace std;

namespace HTW {
    namespace AI {
        namespace Beleg {
            namespace Plugin {

                /* *************** Prototypes *************** */

                /* *************** Globals ***************** */
                bool called = false;
                plugin_info_struct pInfo;
                plugin_f_info infoArr[1];

                /* *************** Functions *************** */

                /**
                 * {@inheritDoc}
                 */
                plugin_info_struct plugin_info() {

                    if (!called) {
                        pInfo.num = 1;

                        pInfo.info = infoArr;

                        infoArr[0].description = "Search Person by Name.";
                        infoArr[0].name = "searchList";
                        called = true;
                    }

                    return pInfo;
                }

                /**
                 * {@inheritDoc}
                 */
                void searchList(ListPerson* list) {

                    string name;
                    cout << "Gib den zu suchenden Nachnamen ein: " << endl;
                    // TODO: validate input. Make it strong to resist the users inputs....
                    cin >> name;
                    Person* foundPerson = NULL;
                    ListPerson* currentEntry = list;
                    if (currentEntry != NULL) {
                        if (strcmp(currentEntry->data->name, name.c_str()) == 0) {
                            foundPerson = currentEntry->data;
                        } else {
                            while (currentEntry->next != NULL) {

                                if (strcmp(currentEntry->data->name, name.c_str()) == 0) {
                                    foundPerson = currentEntry->data;
                                    break;
                                } else {
                                    currentEntry = currentEntry->next;
                                }
                            }
                        }
                    }

                    if (foundPerson == NULL) {
                        cout << "Es konnte keine Person mit dem Namen " << name << " gefunden werden." << endl;
                    } else {
                        // output
                        outputPerson(foundPerson);
                    }
                }

            }
        }
    }
}
