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
                    short year;
                    short month;
                    short day;
                    int departmentInput;
                    int sexInput;

                    cout << "Gib eine neue Person ein" << endl;
                    // TODO: Eingabe aller Daten und Fehlerüberprüfung
                    cout << "Gib den Vornamen ein: " << endl;
                    cin >> firstName;
                    cout << "Gib den Nachnamen ein: " << endl;
                    cin >> name;
                    cout << "Gib das Department ein: " << endl;
                    printAllDeparments();
                    cin >> departmentInput;
                    department = mapIntToDepartment(departmentInput);

                    cout << "Gib das Geschlecht ein: " << endl;
                    cout << "1: weiblich" << endl;
                    cout << "2: männlich" << endl;
                    cin >> sexInput;
                    sex = mapIntToSex(sexInput);

                    cout << "Gib das Geburtsjahr ein: [z.B. 1979]" << endl;
                    cin >> year;
                    cout << "Gib den Geburtsmonat ein: " << endl;
                    cin >> month;
                    cout << "Gib den Geburtstag ein: " << endl;
                    cin >> day;

                    Date birth;
                    birth.year = year;
                    birth.month = month;
                    birth.day = day;

                    Person* newPerson = new Person();

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

                    bool finished = false;
                    //                    do {
                    //                        // eingaben hier
                    //                        // wenn die eingabe korrekt ist, dann finished = true
                    //                    } while (!finished);

                    if (HTW::AI::Beleg::add(newPerson)) {
                        cout << "Person erfolgreich gespeichert." << endl;
                    } else {
                        cout << "Fehler beim anlegen" << endl;
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

            }
        }
    }
}
