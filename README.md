Téma projektu:: NFC skrinka na výdaj tovaru s detekciou obsadenosti<br> 
Spoluautori: Heorhii Chukhir, Danylo Milkevych<br>
Potrebné vybavenie na vykonanie úlohy (tento zoznam slúži na realizáciu dvoch NFC buniek):<br>
1. Naša bežná STM32F303K6C8.<br>
2. Breadboard.<br>
3. Modul RFID-RC522 + 2 NFC štítky.<br> 
Doska stm bude uchovávať zoznam UID kariet. Modul FRID-RC522 slúži ako čítačka UID z každej karty. Karty a modul FRID musia pracovať na rovnakej frekvencii. Následne cez SPI protokol získame UID z modulu a porovnáme ho so zoznamom v STM. V prípade úspešnej identifikácie privedieme napätie na príslušný pin, čím sa údajne otvorí bunka. 
(Každá karta, kľúčenka alebo náramok má priradený unikátny kód a podľa toho sa dá zistiť ktorý modul je priložený k čítačke).<br>
4. 2 ks infračervené senzory na detekciu prítomnosti predmetu v bunke.<br> 
5. 2 ks tlačidiel – simulácia stavu dverí. Napríklad keď je tlačidlo stlačené, dvere sú otvorené, keď je uvoľnené, sú zatvorené.<br>
6. Bolo by vhodné mať 4 alebo aspoň 2 LED diódy na indikáciu stavu bunky. Ak sú k dispozícii len dve LED diódy, svietiaca dióda znamená, že bunka je voľná, a nesvietiaca, že je obsadená. Ak sú k dispozícii 4 LED diódy, na každú z dvoch buniek pripadajú 2 LED diódy rôznych farieb, ktoré indikujú stav bunky.<br>
7. Odporové hodnoty by mali byť v rozmedzí 150–510 Ω, a to v rovnakom počte ako je počet LED diód. <br>

### Rozdelenie úloh

**Heorhii Chukhir:**
* **RFID a autorizácia:** Implementácia komunikácie s modulom RFID-RC522 prostredníctvom zbernice SPI.
* **Spracovanie dát:** Načítavanie UID z kariet a ich porovnávanie s uloženým zoznamom v STM32.
* **Logika zámkov:** Nastavenie a ovládanie výstupných pinov pre simuláciu odomknutia príslušnej bunky po úspešnej identifikácii.

**Danylo Milkevych:**
* **Detekcia obsadenosti:** Integrácia a spracovanie signálov z dvoch infračervených senzorov.
* **Sledovanie stavu dverí:** Implementácia čítania stavu tlačidiel (simulácia otvorených/zatvorených dverí) vrátane ošetrenia zákmytov (debouncing).
* **Vizuálna indikácia a hardvér:** Riadenie LED diód na základe aktuálneho stavu bunky (voľná/obsadená) a celkové zapojenie komponentov na breadboarde.
