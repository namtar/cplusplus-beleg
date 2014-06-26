#include "plugin.h"
#include "deleteListelements.h"

#include <stdlib.h>

namespace HTW {
    namespace AI {
        namespace Beleg {
            namespace Plugin {

                /* *************** Prototypes *************** */

                /**
                 * Deletes the given item and frees all memory.
                 * 
                 * @param currentItem the ListPerson to be deleted
                 * @return true if deletion was successful
                 */
                bool deleteCurrentItem(ListPerson* currentItem);

                /* *************** Globals ***************** */
                bool called = false;
                plugin_info_struct pInfo;
                plugin_f_info infoArr[1];

                /* *************** Functions *************** */

                plugin_info_struct plugin_info() {
                    if (!called) {
                        pInfo.num = 1;

                        pInfo.info = infoArr;

                        infoArr[0].description = "Delete all list elements";
                        infoArr[0].name = "deleteAllListelements";
                        called = true;
                    }

                    return pInfo;
                }

                /**
                 * {@inheritDoc}
                 */
                void deleteAllListelements(ListPerson* list) {
                    ListPerson* currentItemToDelete = list;
                    ListPerson* nextItemToDelete = NULL;
                    if (currentItemToDelete != NULL) {
                        if (currentItemToDelete->next != NULL) {
                            nextItemToDelete = currentItemToDelete->next;
                        }

                        remove(currentItemToDelete);
                        while (nextItemToDelete != NULL) {
                            currentItemToDelete = nextItemToDelete;
                            nextItemToDelete = currentItemToDelete->next;
                            remove(currentItemToDelete);
                            // delete current item
                        }
                    }
                }
            }
        }
    }
}