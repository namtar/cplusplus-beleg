#include "plugin.h"
#include <cstdlib>
#include <iostream>

namespace HTW {
    namespace AI {
        namespace Beleg {
            namespace Plugin {

                ListPerson* personList = NULL; // init with null. This pointer shall point to the root item of the list.

                plugin_info_struct pInfo;
                plugin_f_info infoArr[5];
                bool called = false;

                /**
                 * {@inheritDoc}
                 */
                plugin_info_struct plugin_info() {
                    if (!called) {
                        pInfo.num = 5;

                        pInfo.info = infoArr;

                        infoArr[0].description = "Get the Person list";
                        infoArr[0].name = "getList";
                        infoArr[1].description = "Adds a Person to the list";
                        infoArr[1].name = "add";
                        infoArr[2].description = "Inserts a Person after the given ListPerson element";
                        infoArr[2].name = "insertAfter";
                        infoArr[3].description = "Inserts a Person before the given ListPerson element";
                        infoArr[3].name = "insertBefore";
                        infoArr[4].description = "Removes a Person";
                        infoArr[4].name = "remove";

                        called = true;
                    }
                    std::cout << "Ping" << std::endl;
                    return pInfo;
                }

                /**
                 * {@inheritDoc}
                 */
                ListPerson* getList() {
                    return personList;
                }

                /**
                 * {@inheritDoc}
                 */
                bool add(Person* data) {
                    // TODO: testme
                    bool returnVal = false;

                    ListPerson *actual = personList; // get first element
                    if (actual == NULL) {
                        // there is no lists. create one
                        actual = new ListPerson();
                        actual->data = data;
                    } else {
                        // search end of list
                        bool done = false;
                        while (!done) {

                            if (actual->next == NULL) {
                                // reached end of the list.
                                // append here
                                ListPerson* newListPersion = new ListPerson();
                                newListPersion->data = data;
                                actual->next = newListPersion;
                                done = true;
                                returnVal = true;
                            } else {
                                actual = actual->next;
                            }
                        }
                    }

                    return returnVal;
                }

                /**
                 * {@inheritDoc}
                 */
                bool insertAfter(ListPerson* element, Person* data) {
                    // TODO: testme

                    ListPerson* nextElem = new ListPerson();
                    nextElem->data = data;

                    if (element->next != NULL) {
                        ListPerson* afterElem = element->next;
                        element->next = nextElem;
                        nextElem->next = afterElem;
                    } else {
                        element->next = nextElem;
                    }

                }

                /**
                 * {@inheritDoc}
                 */
                bool insertBefore(ListPerson* element, Person* data) {
                    // TODO: testme
                    ListPerson* actualElem = personList;
                    ListPerson* newElem = new ListPerson();
                    newElem->data = data;

                    bool returnVal = false;

                    // get the element before
                    bool done = false;
                    while (!done) {
                        if (actualElem->next == element) {

                            actualElem->next = newElem;
                            newElem->next = element;
                            done = true;
                            returnVal = true;
                        } else {
                            actualElem = actualElem->next;
                        }
                    }
                    return returnVal;
                }

                /**
                 * {@inheritDoc}
                 */
                void remove(ListPerson* element) {

                    // TODO: testme
                    ListPerson *actual = personList; // get first element

                    // get the right position of the element
                    // get also the elements position after the element which has to be removed
                    bool done = false;
                    while (!done) {

                        if (actual->next == element) {
                            ListPerson *before = actual;
                            // lets see if there is an following object
                            ListPerson *after = NULL;
                            if (actual->next->next != NULL) {
                                after = actual->next->next;
                            }
                            // so now do the removing
                            before->next = after;
                            // free memory of the removed element
                            delete element;
                            done = true;
                        } else {
                            actual = actual->next;
                        }
                    }

                }

            }
        }
    }
}