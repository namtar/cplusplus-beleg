#include "plugin.h"
#include <iostream>
#include <string.h>
#include "interactiveAdd.h"
#include "list_api_extended.h"

using namespace std;

namespace HTW {
    namespace AI {
        namespace Beleg {
            namespace Plugin {

                /* *************** Prototypes *************** */

                /**
                 * Print out all departments with index nr and human readable string to the console.
                 */
                void printAllDeparments();

                /**
                 * Maps a given integer to the department enum.
                 * 
                 * @param value the int value to be mapped
                 * @return the mapped deparment
                 */
                Department mapIntToDepartment(int value);

                /**
                 * Maps a given integer to the sex enum.
                 * 
                 * @param value the int value to be mapped
                 * @return the mapped sex
                 */
                Sex mapIntToSex(int value);

                //                string getFirstName();
                //                string getName();

                /**
                 * Returns the sex of a person.
                 * 
                 * @return the sex
                 */
                Sex getSex();

                /**
                 * Returns the deparment the person belongs to.
                 * 
                 * @return the deparment
                 */
                Department getDepartment();

                /**
                 * Returns the birthdate of a person.
                 * 
                 * @return the birthdate
                 */
                Date getBirthDate();

                /**
                 * Detemines wether the given year is a leap year or not.<br>
                 * The rule is:<br>
                 * If a year is divideable through 4 without rest than it is a leap year, but if it is divideable through 100 without rest<br>
                 * it is no leap year, but if it is divideable through 400 it is a leap year.
                 * 
                 * @param year the year to be checked
                 * @return true if the given year is a leap year otherwise false.
                 */
                bool determineLeapYear(short year);

                /**
                 * Does the handling to add a person to the end of the list.
                 * 
                 * @param person the person to add
                 */
                void handleAdd(Person* person);

                /**
                 * Does the handling to insert a person before or after a specific list entry.
                 * 
                 * @param person the person to insert
                 * @param before ture if before, false after
                 */
                void handleInsert(Person* person, bool before);


                /* *************** Globals ***************** */

                plugin_info_struct pInfo;
                plugin_f_info infoArr[1];
                bool called = false;

                /* *************** Functions *************** */

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

                /**
                 * {@inheritDoc}
                 */
                void interactiveAdd(ListPerson* list) {

                    string firstName;
                    string name;
                    Department department;
                    Sex sex;

                    cout << "Gib eine neue Person ein" << endl;
                    cout << "Gib den Vornamen ein: " << endl;
                    cin >> firstName;
                    cout << "Gib den Nachnamen ein: " << endl;
                    cin >> name;

                    department = getDepartment();
                    sex = getSex();
                    Date birth = getBirthDate();

                    Person* newPerson = new Person();

                    // check for memory left.
                    if (newPerson == NULL) {
                        cerr << "Not enough memory available." << endl;
                        exit(EXIT_FAILURE);
                    }

                    // finally after all input, combine all.
                    char * nameWritable = new char[name.size() + 1];
                    std::copy(name.begin(), name.end(), nameWritable);
                    nameWritable[name.size()] = '\0'; // don't forget the terminating 0

                    newPerson->name = nameWritable;

                    char * firstNameWritable = new char[firstName.size() + 1];
                    std::copy(firstName.begin(), firstName.end(), firstNameWritable);
                    firstNameWritable[firstName.size()] = '\0'; // don't forget the terminating 0
                    newPerson->firstname = firstNameWritable;
                    newPerson->dept = department;
                    newPerson->sex = sex;
                    newPerson->birth = birth;

                    // ask if the person has to be added to the end of the list or insertAfter or insertBefore a specific element
                    int storeTo(-1);
                    bool done = false;
                    do {
                        cout << "Chose how to store the new entry." << endl;
                        cout << "1: add to the end." << endl;
                        cout << "2: insert after a specific element." << endl;
                        cout << "3: insert before a specific element." << endl;
                        cin >> storeTo;
                        if (cin.fail()) {
                            cout << "Please enter a valid integer according to the menu." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n'); // ignore must be executed AFTER cin.clear to prevent a infinite loop.
                        } else {
                            done = true;
                            if (storeTo < 1 || storeTo > 3) {
                                cout << "The input does not match to the available options." << endl;
                                cout << endl;
                                cin.clear();
                                done = false;
                            }
                        }

                    } while (!done);

                    switch (storeTo) {
                        case 1: //add
                            handleAdd(newPerson);
                            break;
                        case 2: // insert after
                            handleInsert(newPerson, false);
                            break;
                        case 3: // insert before
                            handleInsert(newPerson, true);
                            break;
                    }
                }

                void printAllDeparments() {
                    // There is no proper way to iterate over an enum whithout modifying it. So hardcode it here.                                      

                    cout << "1: " << mapDepartmentToString(Department::Controlling) << endl;
                    cout << "2: " << mapDepartmentToString(Department::Management) << endl;
                    cout << "3: " << mapDepartmentToString(Department::Production1) << endl;
                    cout << "4: " << mapDepartmentToString(Department::Production2) << endl;
                }

                Department mapIntToDepartment(int value) {

                    switch (value) {
                        case 1: // Controlling
                            return Department::Controlling;
                        case 2: // Management
                            return Department::Management;
                        case 3: // Production1
                            return Department::Production1;
                        case 4: // Production2
                            return Department::Production2;
                    }
                }

                Sex mapIntToSex(int value) {
                    switch (value) {
                        case 1: // female
                            return Sex::female;
                        case 2: // male
                            return Sex::male;
                    }
                }

                Sex getSex() {
                    bool done = false;
                    int sexInput;
                    Sex sex;
                    do {

                        cout << "Gib das Geschlecht ein: " << endl;
                        cout << "1: weiblich" << endl;
                        cout << "2: männlich" << endl;
                        cin >> sexInput;

                        if (cin.fail()) {
                            // input of string or something else
                            cout << "Please enter a valid integer according to the menu." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n'); // ignore must be executed AFTER cin.clear to prevent a infinite loop.
                        } else {

                            if (sexInput == 1 || sexInput == 2) {
                                sex = mapIntToSex(sexInput);
                                done = true;
                            } else {
                                cout << "The input does not match to the available options." << endl;
                                cout << endl;
                                cin.clear();
                            }
                        }

                    } while (!done);
                    return sex;
                }

                Date getBirthDate() {
                    short year;
                    short month;
                    short day;

                    bool done = false;
                    do {
                        cout << "Gib das Geburtsjahr ein: [z.B. 1979]" << endl;
                        cin >> year;
                        if (cin.fail()) {
                            cout << "Please enter a valid integer which." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n'); // ignore must be executed AFTER cin.clear to prevent a infinite loop.
                        } else {
                            if (year < 1970 || year > 2100) {
                                cout << "Please enter the year in the valid ranges gt 1970 and lt 2100" << endl;
                                cout << endl;
                                cin.clear();
                            } else {
                                done = true;
                            }
                        }

                    } while (!done);

                    done = false;
                    do {
                        cout << "Gib den Geburtsmonat ein: " << endl;
                        cin >> month;
                        if (cin.fail()) {
                            cout << "Please enter a valid integer which." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n'); // ignore must be executed AFTER cin.clear to prevent a infinite loop.
                        } else {
                            if (month < 1 || month > 12) {
                                cout << "Please enter a month which is gt 0 and lt 13." << endl;
                                cout << endl;
                                cin.clear();
                            } else {
                                done = true;
                            }
                        }

                    } while (!done);

                    done = false;
                    do {
                        cout << "Gib den Geburtstag ein: " << endl;
                        cin >> day;

                        if (cin.fail()) {
                            cout << "Please enter a valid integer which." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n'); // ignore must be executed AFTER cin.clear to prevent a infinite loop.
                        } else {
                            // check months with 30 days
                            done = true;
                            if (month == 4 || month == 6 || month == 9 || month == 11) {
                                if (day < 1 || day > 30) {
                                    cout << "The day must be between 1 and 30" << endl;
                                    cout << endl;
                                    done = false;
                                    cin.clear();
                                }
                            } else if (month == 2) {
                                // Schaltjahr (Leap year) handling
                                if (determineLeapYear(year)) {
                                    // february must have 29 days
                                    if (day < 1 || day > 29) {
                                        cout << "The day must be between 1 and 29" << endl;
                                        cout << endl;
                                        done = false;
                                        cin.clear();
                                    }
                                } else {
                                    // february must have 28 days
                                    if (day < 1 || day > 28) {
                                        cout << "The day must be between 1 and 28" << endl;
                                        cout << endl;
                                        done = false;
                                        cin.clear();
                                    }
                                }
                            } else {
                                if (day < 1 || day > 31) {
                                    cout << "The day must be between 1 and 31" << endl;
                                    cout << endl;
                                    done = false;
                                    cin.clear();
                                }
                            }
                        }
                    } while (!done);

                    Date date;
                    date.year = year;
                    date.month = month;
                    date.day = day;


                    return date;
                }

                bool determineLeapYear(short year) {
                    if ((year % 400) == 0) {
                        return true;
                    } else if ((year % 100) == 0) {
                        return false;
                    } else if ((year % 4) == 0) {
                        return true;
                    }
                    return false; // default
                }

                Department getDepartment() {

                    int departmentInput;
                    bool done = false;
                    do {
                        cout << "Gib das Department ein: " << endl;
                        printAllDeparments();
                        cin >> departmentInput;
                        if (cin.fail()) {
                            cout << "Please enter a valid integer." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n'); // ignore must be executed AFTER cin.clear to prevent a infinite loop.
                        } else {
                            done = true;
                            if (departmentInput < 1 || departmentInput > 4) {
                                cout << "The input does not match to the available options." << endl;
                                cout << endl;
                                cin.clear();
                                done = false;
                            }
                        }

                    } while (!done);

                    return mapIntToDepartment(departmentInput);
                }

                void handleAdd(Person* person) {
                    if (add(person)) {
                        cout << "Person erfolgreich gespeichert." << endl;
                    } else {
                        cout << "Fehler beim anlegen" << endl;
                    }
                }

                void handleInsert(Person* person, bool before) {

                    // output the list with index values.
                    // user must chose a valid one to insert before.
                    // if there are no list entries, the add function is used.
                    ListPerson* list = getList();
                    if (list == NULL) {
                        cout << "The list is empty. The person will be added via add function." << endl;
                        handleAdd(person);
                        return;
                    }
                    if (list->data == NULL) {
                        // this may not happen. If this is the case our list is corrupt.
                        cerr << "We have a list entry, but the person is null. This may not happen. The list is corrupt." << endl;
                        exit(EXIT_FAILURE);
                    }

                    int cnt(0);
                    ListPerson* currentItem = list;
                    // we ensured that we have an entry.
                    cout << "Chose the index of the list item the new person shall be inserted before." << endl;
                    cout << endl;
                    do {
                        cnt++;
                        cout << cnt << ": " << currentItem->data->name << ", " << currentItem->data->firstname << endl;
                        currentItem = currentItem->next;
                    } while (currentItem != NULL);
                    int chosenItem(-1);
                    bool done = false;
                    do {
                        cin >> chosenItem;
                        if (cin.fail()) {
                            cout << "Please enter a valid integer." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n'); // ignore must be executed AFTER cin.clear to prevent a infinite loop.
                        } else {
                            done = true;
                            if (chosenItem < 0 || chosenItem > cnt) {
                                cout << "The input does not match to the available options." << endl;
                                cout << endl;
                                cin.clear();
                                done = false;
                            }
                        }
                    } while (!done);

                    // get the chosen list item and call the function to store the new person.
                    currentItem = list;
                    for (int i = 1; i <= cnt; i++) {
                        if (i == cnt) {
                            // we have our item
                            if (before) {
                                insertBefore(currentItem, person);
                            } else {
                                insertAfter(currentItem, person);
                            }
                            break;
                        }
                        currentItem = currentItem->next;
                    }
                }
            }
        }
    }
}
