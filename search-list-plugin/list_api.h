/*********************************************************************************
 * Belegarbeit Programmierung 3
 *
 * Datei: list_api.h
 * Zweck: Diese Header-Datei enthält die Deklaration der Strukturen eines
 *        Listen-Elements der Personenliste. Die Strukturdefintion dürfen
 *        ergänzt werden um weitere Strukturen, jedoch nicht verändert, um
 *        die Interoperabilität von Plugins zu erhalten.
 *
 *        Außerdem werden hier die API (Application Programming Interface)
 *        Funktionen deklariert, die die Listenverwaltung den Plugins zur
 *        Verfügung stellen muss. Dabei handelt es sich um grundlegende
 *        Funktionen zum Anfügen, Löschen und Einfügen eines Elements.
 *        Plugins können diese Funktionen benutzen, um wiederkehrende
 *        Aufgaben durch die Listenverwaltung erledigen zu lassen.
 *
 * History: 
 *
 *********************************************************************************/

namespace HTW {
    namespace AI {
        namespace Beleg {

            /**
             * Abteilungen
             */
            enum Department {
                Controlling, Management, Production1, Production2
            };

            /**
             * Geschlecht
             */
            enum Sex {
                female, male
            };

            /**
             * Struktur eines Datums
             */
            struct Date {
                short year;
                short month;
                short day;
            };

            /**
             * Personen-Struktur mit Daten einer Person
             */
            struct Person {
                char *name;
                char *firstname;
                Department dept;
                Date birth;
                Sex sex;
            };

            /**
             * Struktur eines Listenelements der Personen-Liste
             */
            struct ListPerson {
                struct ListPerson* next; // Zeiger auf das nächste Element
                struct Person* data; // Zeiger auf die Personen-Daten
            };

            /***************************************************************
             * API-Funktionen
             ***************************************************************/
            /**
             * Funktion: getList
             * Zweck:    Rückgabe des ersten Listen-Elements 
             * return:   erstes Listen-Element (Beginn der Liste)
             */
            ListPerson* getList();

            /**
             * Funktion: add
             * Zweck:    Hinzufügen des übergebenen Listen-Elements zum
             *           Ende der Liste
             * return:   Erfolg (true) oder Fehler (false)
             */
            bool add(Person* data);

            /**
             * Funktion: remove
             * Zweck:    Löscht das über den Zeiger 'element' referenzierte Element aus
             *           der Liste
             * return:   nichts
             */
            void remove(ListPerson* element);

            /**
             * Funktion: insertBefore
             * Zweck:    Fügt das mittels 'data' übergebene neue Element vor dem über den
             *           Zeiger 'element' referenzierten Element ein
             *           der Liste
             * return:   Erfolg (true) oder Fehler (false)
             */
            bool insertBefore(ListPerson* element, Person* data);

            /**
             * Funktion: insertAfter
             * Zweck:    Fügt das mittels 'data' übergebene neue Element hinter dem über den
             *           Zeiger 'element' referenzierten Element ein
             *           der Liste
             * return:   Erfolg (true) oder Fehler (false)
             */
            bool insertAfter(ListPerson* element, Person* data);

        }
    }
}