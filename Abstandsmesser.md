MBot-Studio:

Der Abstandsmesser gibt den aktuellen (vermuteten) Abstand in Centimeter zurück.
Wird kein Abstand ermittelt (d.h. der Gegenstand ist zu weit weg, oder _reflektiert falsch_) wird ein Fehlerwert zurückgegeben. <mark>Der Fehlerwert ist hierfür 400 cm.</mark>

Der ("zuverlässige") Messbereich des Sensors ist hier _zwischen 4 cm und 30 cm_ 

 - [Einfaches Programm zum Anzeigen des aktuellen Abstands auf Display](mBlockStudio/Abstandsmesser/Abstandsmesser_einmalig.sb3.mblock)

 - [Einfaches Programm mit Abstandswerten in Tabelle](mBlockStudio/Abstandsmesser/Abstandsmesser_Tabelle.mblock)

Programmlimits:

Es können nur maximal 200 Messpunkte gespeichert werden.

Wie könnte ich das umgehen?

In MBot-Studio?

 - ich entferne alte Messdaten, die ich nicht mehr brauche
 - [ich speichere nur "geänderte" Messdaten (d.h. wenn X-Mal aufeinander folgend 5cm gemessen werden, speichere ich es nur einmal)](mBlockStudio/Abstandsmesser/Abstandsmesser_Tabelle_nurAenderungen.mblock)

In Arduino C++?

 - [einfache Ausgabe des aktuellen Abstands via Serial](arduinoCode/abstandsSensor/abstandsSensorEinfacheAusgabe/abstandsSensorEinfacheAusgabe.ino)
