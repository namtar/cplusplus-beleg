#include "list_api_extended.h"
#include "plugin.h"
#include "outputList.h"
#include <stdlib.h>
#include <iostream>

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

                plugin_info_struct plugin_info() {
                    if (!called) {
                        pInfo.num = 1;

                        pInfo.info = infoArr;

                        infoArr[0].description = "Output the whole list";
                        infoArr[0].name = "outputList";
                        called = true;
                    }

                    return pInfo;
                }

                /**
                 * {@inheritDoc}
                 */
                void outputList(ListPerson* list) {

                    if (list == NULL) {
                        std::cout << endl;
                        std::cout << "List is null" << endl;
                    }

                    ListPerson* currentPerson = list;

                    if (currentPerson != NULL) {
                        outputPersonTableHeader();
                        outputPerson(currentPerson->data);
                        while (currentPerson->next != NULL) {
                            currentPerson = currentPerson->next;
                            outputPerson(currentPerson->data);
                        }
                    }
                }
            }
        }
    }
}
