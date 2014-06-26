#include "list_api_extended.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

/**
 * Stupid ugly style to add extern "C" to the function implementations which prototypes are defined in the header.
 * This is done here because the header files may not be modified.
 */

using namespace std;

namespace HTW {
    namespace AI {
        namespace Beleg {

            /* *************** Prototypes *************** */

            /* *************** Globals ***************** */

            ListPerson* personList = NULL; // init with null. This pointer shall point to the root item of the list.

            /* *************** Functions *************** */

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
                bool returnVal = false;

                ListPerson *actual = personList; // get first element
                if (actual == NULL) {
                    // there is no lists. create one
                    actual = new ListPerson();
                    actual->data = data;
                    personList = actual;
                    returnVal = true;
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

                ListPerson* rootElement = getList();
                // if element is the first one of the list check for follower.
                // if it has a follower delete element and set pointer to follower, otherwise set pointer = NULL
                if (element == rootElement) {
                    ListPerson* nextOne = NULL;
                    if (element->next != NULL) {
                        nextOne = element->next;
                    }
                    Person* personToDelete = element->data;
                    delete[] personToDelete->firstname;
                    delete[] personToDelete->name;
                    delete personToDelete;
                    personToDelete = NULL;
                    element->next = NULL;
                    delete element;
                    // There is no need and no chance to delete sex, deparment and birth because there is no extra memory allocated for.
                    // These elements just exist whithin the person struct and should be freed automatically when deleting the person.

                    if (nextOne != NULL) {
                        rootElement = nextOne;
                    } else {
                        rootElement = NULL;
                        personList = NULL; // important, if the list is empty set the base pointer to null.
                    }
                } else {
                    // if it is not the first element, search in the list for matches.
                    // Remember the predecessor
                    bool done = false;
                    ListPerson* currentElement = rootElement;
                    while (!done) {
                        ListPerson* predecessor = currentElement;
                        currentElement = currentElement->next;

                        if (element == currentElement) {

                            // delete element and attach follwing element to predecessor.
                            predecessor->next = currentElement->next;
                            Person* personToDelete = currentElement->data;
                            delete[] personToDelete->firstname;
                            delete[] personToDelete->name;
                            delete personToDelete;
                            personToDelete = NULL;
                            currentElement->next = NULL;
                            delete element;
                            delete currentElement;
                            currentElement = NULL; // link current element pointer to null

                            done = true;
                        } else {
                            if (currentElement->next == NULL) {
                                // end when the end of the list has been reached.
                                done = true;
                            }
                        }

                    }
                }




            }

            void outputPerson(Person* person) {

                if (person == NULL) {
                    cout << "Given person is null" << endl;
                    return;
                }

                string birth("");
                birth.append(to_string(person->birth.day));
                birth.append("-");
                birth.append(to_string(person->birth.month));
                birth.append("-");
                birth.append(to_string(person->birth.year));

                string sex = mapSexToString(person->sex);

                string department = mapDepartmentToString(person->dept);

                cout << setw(10) << person->name << setw(5) << "|" << setw(10) << person->firstname << setw(5) << "|" << setw(15) << department;
                cout << setw(5) << "|" << setw(10) << birth << setw(5) << "|" << setw(10) << sex << endl;
            }

            void outputPersonTableHeader() {
                cout << setw(10) << "Name" << setw(5) << "|" << setw(10) << "Firstname" << setw(5) << "|" << setw(15) << "Department";
                cout << setw(5) << "|" << setw(10) << "Birth" << setw(5) << "|" << setw(10) << "Sex" << endl;
            }

            /**
             * {@inheritDoc}
             */
            string mapDepartmentToString(Department department) {

                switch (department) {
                    case Controlling:
                        return "Controlling";
                    case Management:
                        return "Management";
                    case Production1:
                        return "Production1";
                    case Production2:
                        return "Production2";
                }

            }

            /**
             * {@inheritDoc}
             */
            string mapSexToString(Sex sex) {
                switch (sex) {
                    case female:
                        return "Female";
                    case male:
                        return "Male";
                }
            }
        }
    }
}