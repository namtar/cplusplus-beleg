cplusplus-beleg
===============

C plus plus Beleg des dritten Semesters

Kommandos für die Console:

* git clone <Url zum Repo>
* git pull
* git add .
* git commit -a
* git push origin master

Wichtig, wenn IDE´s verwendet werden. Man muss immer einen commit aller files in das lokale Repository gemacht haben bevor man einen git pull ausführt. Tut man das nicht kommt es zu Konflikten mit denen z.B. Eclipse nicht richtig klar kommt.

Es soll hier auch nur Quellcode eingecheckt werden und keine IDE spezifischen Files.

Das Repository besteht aus mehreren separaten C++ Projekten.

* main-program (Das Hauptprogramm, welches die Shared Libraries einbindet und verwendet)
* libapi (Eine Shared Library welche Basisfunktionalität bereitstellt, die durch das Hauptprogramm als auch durch die jeweiligen Plugin Module benutzt werden)
* interactive-add-plugin (Eine Shared Library, welche als Plugin die Funktionalität bereitstellt interaktiv ein neues Listenelement einzugeben)
* search-list-plugin (Eine Shared Library, welche als Plugin die Funktionalität bereitstellt anhand des Nachnames ein Listenelement zu suchen)
* output-list-plugin (Eine Shared Library, welche als Plugin die Funktionalität bereitstellt alle Listenelemente auf dem Bildschirm auszugeben)
* delete-listelements-plugin (Eine Shared Library, welche als Plugin die Funktionalität bereitstellt alle Listenelemente aus der Liste zu löschen)
 

