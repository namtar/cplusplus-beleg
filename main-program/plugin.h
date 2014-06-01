/*********************************************************************************
 *  Belegarbeit Programmierung 3
 *
 * Datei: plugin.h
 * Zweck: Diese Header-Datei enthält alle Deklarationen, die ein Plugin benötigt
 *        einschliesslich der Funktionen und der Typdeklaration der Funktionen,
 *        die ein Plugin zur Verfügung stellen muss
 *********************************************************************************/

#include "list_api.h"

namespace HTW {
  namespace AI {
    namespace Beleg {
      namespace Plugin {

        /**
         * Name und Beschreibung einer durch das Plugin bereitgestellten
         * Funktion. Wird ein Funktionsname in dieser Struktur aufgelistet,
         * so muss eine entsprechende Funktion in diesem Plugin
         * implementiert werden. Die Beschreibung (description) dient
         * der Beschreibung dieser Funktion zur Auflistung in einem Menü.
         */
        struct plugin_f_info {
          const char* name;
          const char* description;
        };

        /**
         * Struktur, die ein Array mit den Namen und Beschreibungen der im
         * Plugin zur Verfügung gestellten Funktionen sowie deren Anzahl
         * im Array enthält
         */
        struct plugin_info_struct {
          int num;
          struct plugin_f_info* info;
        };

        /**
         * Deklaration einer Info-Funktion und eines Zeigers auf, diese,
         * die vom Plugin implementiert werden muss, um eine Struktur
         * zurückzugeben, die alle bereitgestellten Listen-Funktionen
         * auflistet.
         * Die durch diesen Zeiger referenzierte Funktion gibt die Information
         * zu weiteren Plugin-Funktionen zurueck.
         *
         * @return - die zurueckgegebene Struktur listet die Namen aller 
         *           aufrufbaren Plugin-Funktionen und deren Menue-
         *           Beschreibung auf
         */
        typedef plugin_info_struct (*plugin_info_f_t) ();
        extern "C" plugin_info_struct plugin_info();

        /**
         * Zeigerdeklaration eines Zeigers auf eine bereitgestellte 
         * Funktion eines Plugins. Der Name einer solchen Plugin-Funktion 
         * muss zur Bekanntgabe in info[i].name von plugin_info_struct 
         * abgelegt sein. Die Signatur muss dieser Zeigerdeklaration 
         * entsprechen.
         * @param list - Das das Plugin aufrufende Programm übergibt 
         *               hierin das Wurzel-Element der verketteten Liste
         */
        typedef void (*plugin_f_t) (HTW::AI::Beleg::ListPerson* list);

        /**
         * Name der Info-Funktion, welche jedes Plugin bereitstellen muss,
         * um die Anzahl und Namen der Listen-Funktionen zurückzugeben
         */
        const char* PLUGIN_INFO_F_NAME = "plugin_info";
      }
    }
  }
}