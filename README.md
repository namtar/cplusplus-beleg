cplusplus-beleg
===============

C plus plus Beleg des dritten Semesters

Kommandos für die Console:

* git clone <Url zum Repo> (Cloned das Projekt aus dem Remote Repository in ein lokales)
* git pull (Zieht aus dem Remote Repository zwischenzeitlich seit dem letzten pull erfolgte Änderungen)
* git add . (Fügt neue und geänderte Files ab der Position an der man sich im Verzeichnisbaum befindet hinzu)
* git commit -a (Commited Änderungen in das lokale Repository)
* git push origin master (Transferiert den Stand des lokalen Repos in das Remote Repo)
* git status (Zeigt den aktuellen lokalen Git Status an)

Ein sinniger Ablauf nachdem man entwickelt hat ist:
* git status
* git add . bzw git add <bestimmte Dateien>
* git commit -a
* git pull (sollte man machen da git verhindert dass man pushed wenn nicht sichergestellt ist dass keine Konflikte auftreten)
* git push origin master

Man sollte einen pull auch nur dann ausführen, wenn man alle Änderungen in das lokale Repo eingecheckt hat.

Wichtig, wenn IDE´s verwendet werden. Man muss immer einen commit aller files in das lokale Repository gemacht haben bevor man einen git pull ausführt. Tut man das nicht kommt es zu Konflikten mit denen z.B. Eclipse nicht richtig klar kommt.

Es soll hier auch nur Quellcode eingecheckt werden und keine IDE spezifischen Files.

Das Repository besteht aus mehreren separaten C++ Projekten.

* main-program (Das Hauptprogramm, welches die Shared Libraries einbindet und verwendet)
* libapi (Eine Shared Library welche Basisfunktionalität bereitstellt, die durch das Hauptprogramm als auch durch die jeweiligen Plugin Module benutzt werden)
* interactive-add-plugin (Eine Shared Library, welche als Plugin die Funktionalität bereitstellt interaktiv ein neues Listenelement einzugeben)
* search-list-plugin (Eine Shared Library, welche als Plugin die Funktionalität bereitstellt anhand des Nachnames ein Listenelement zu suchen)
* output-list-plugin (Eine Shared Library, welche als Plugin die Funktionalität bereitstellt alle Listenelemente auf dem Bildschirm auszugeben)
* delete-listelements-plugin (Eine Shared Library, welche als Plugin die Funktionalität bereitstellt alle Listenelemente aus der Liste zu löschen)

###### Plugins und ListApi
* Funktionen, die in den Plugins implementiert werden müssen ebenfalls mit dem Schlüsselwort extern "C" versehen werden.
* Die ListApi braucht nur den Header list_api.h implementieren. Keine der Funktionen benötigt das Schlüsselwort extern. Diese Funktionen können auch von den Plugins ohne Probleme aufgerufen werden.
 

###### Kompilerbefehle:


Erzeugen von shared libraries:
* g++ -shared -m64 -fPIC -o plugin1.so plugin1.cc
* g++ -shared -m64 -fPIC -o libapi.so api.cc

Linken zur Kompilezeit:
* g++ -o listmanager listmanager.cc -L <pathToLib> -l api

Kann auch in Netbeans direkt eingestellt werden als zusätzliche Kompileroptionen:
* -L ~/NetBeansProjects/cplusplus-beleg/runFolder -l libapi
* g++ -Wall -o test main.cpp -L . -l libapi -v -Wl,--no-as-needed -ldl -std=c++11
* g++ -Wall -o main-program main.cpp -L <path to lib> -l libapi -v -ldl -Wl,-rpath=. -Wl,--verbose --std=c++11

Program ausführen und auf Memory Leaks prüfen:
* valgrind --tool=memcheck --leak-check=full ./main-program
