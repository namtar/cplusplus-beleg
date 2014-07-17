#include "plugin.h"
#include <iostream>

using namespace std;

namespace HTW {
    namespace AI {
        namespace Beleg {
            namespace Plugin {

                plugin_info_struct infoStruct;
                plugin_f_info infoArray[1];
                bool called = false;

                /**
                 * Function to generate a bunch of test data person. The user is asked for the amount to create.
                 * 
                 * @param list the pointer to the start of the list
                 */
                extern "C" void testDataGenerate(ListPerson* list);

                /**
                 * {@inheritDoc}
                 */
                plugin_info_struct plugin_info() {

                    if (!called) {
                        infoArray[0].description = "Generates a bunch of test data persons.";
                        infoArray[0].name = "testDataGenerate";
                        infoStruct.num = 1;
                        infoStruct.info = infoArray;
                    }

                    return infoStruct;
                }

                void testDataGenerate(ListPerson* list) {

                    int amount(-1);
                    bool done = false;

                    while (!done) {
                        cout << "Wie viele Testdatensätze sollen generiert werden? Drücke 0 zum abbrechen: ";
                        cin >> amount;
                        if (cin.fail()) {
                            cout << "Bitte eine Zahl eingeben." << endl << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                        } else {
                            // check domain of values
                            if (amount < 0) {
                                cout << "Es muss entweder 0 zum abbrechen oder ein Wert größer 0 eingegeben werden." << endl << endl;
                                cin.clear();
                            } else {
                                done = true;
                            }
                        }
                    }
                    if (amount == 0) {
                        // do nothing. Return to menu
                        return;
                    }

                    for (int i = 0; i < amount; i++) {

                        Person* newPerson = new Person();
                        string name = "name_" + to_string(i);
                        string firstName = "firstName_" + to_string(i);

                        char* nameWritable = new char[name.size() + 1];
                        std::copy(name.begin(), name.end(), nameWritable);
                        nameWritable[name.size()] = '\0';
                        newPerson->name = nameWritable;

                        char* firstNameWritable = new char[firstName.size() + 1];
                        std::copy(firstName.begin(), firstName.end(), firstNameWritable);
                        firstNameWritable[firstName.size()] = '\0';
                        newPerson->firstname = firstNameWritable;

                        newPerson->dept = Department::Management; // all time mgmt
                        newPerson->sex = Sex::male; // blame gender fanatics. Harr harr ;)                        

                        Date date;
                        date.day = 18;
                        date.month = 7;
                        date.year = 2014;

                        newPerson->birth = date;

                        add(newPerson);
                    }

                    cout << amount << " Persons generated. " << endl;
                }
            }
        }
    }
}

