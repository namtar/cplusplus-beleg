#include "list_api.h"
#include <cstdlib>

using namespace HTW::AI::Beleg;

ListPerson* personList = NULL; // init with null. This pointer shall point to the root item of the list.

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
            }
        }
    }

    return returnVal;
}

/**
 * {@inheritDoc}
 */
bool insertAfter(ListPerson* element, Person* data) {


}

/**
 * {@inheritDoc}
 */
bool insertBefore(ListPerson* element, Person* data) {
    // TODO: implement
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
        }
    }

}
