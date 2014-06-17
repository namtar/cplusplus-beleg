#include "plugin.h"
#include "searchList.h"
#include <string>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <ctime>

using namespace std;

namespace HTW {
    namespace AI {
        namespace Beleg {
            namespace Plugin {

                /* *************** Prototypes *************** */

                /**
                 * Outputs a person.
                 * 
                 * @param person
                 */
                void outputPerson(Person* person);

                /**
                 * Maps a given Sex enum to string.
                 * 
                 * @param sex the sex enum to be mapped
                 * @return the mapped string
                 */
                string mapSexToString(Sex sex);

                /**
                 * Maps a given department enum to string
                 * 
                 * @param department the department enum to be mapped
                 * @return the mapped string
                 */
                string mapDepartmentToString(Department department);

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

                void outputPerson(Person* person) {

                    string birth("");
                    birth.append(to_string(person->birth.day));
                    birth.append("-");
                    birth.append(to_string(person->birth.month));
                    birth.append("-");
                    birth.append(to_string(person->birth.year));

                    string sex = mapSexToString(person->sex);
                    string department = mapDepartmentToString(person->dept);
                    // TODO: call map method for department and sex
                    cout << "###################################" << endl;
                    cout << "Die gefundene Person ist: " << endl;
                    cout << endl;
                    cout << setw(10) << "Name" << setw(5) << "|" << setw(10) << "Firstname" << setw(5) << "|" << setw(15) << "Department";
                    cout << setw(5) << "|" << setw(10) << "Birth" << setw(5) << "|" << setw(10) << "Sex" << endl;
                    cout << setw(10) << person->name << setw(5) << "|" << setw(10) << person->firstname << setw(5) << "|" << setw(15) << department;
                    cout << setw(5) << "|" << setw(10) << birth << setw(5) << "|" << setw(10) << sex << endl;

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
                        case male:
                            return "Male";
                        case female:
                            return "Female";
                    }
                }
            }
        }
    }
}
