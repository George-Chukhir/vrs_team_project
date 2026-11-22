Téma projektu:: NFC skrinka na výdaj tovaru s detekciou obsadenosti<br> 
Spoluautori: Heorhii Chukhir, Danylo Milkevych<br>
Potrebné vybavenie na vykonanie úlohy (tento zoznam slúži na realizáciu dvoch NFC buniek):<br>
1. Naša bežná STM32F303K6C8.<br>
2. Breadboard.<br>
3. Rozširujúca doska ST MB1161-A (SHIELD-M24SR-ADV) s dynamickým NFC tagom M24SR <br> 
4. 4 ks infračervené senzory na detekciu prítomnosti predmetu v bunke (2 senzory na každú bunku pre spoľahlivejšie pokrytie celej plochy).<br> 
5. <del> 2 ks tlačidiel – simulácia stavu dverí. Napríklad keď je tlačidlo stlačené, dvere sú otvorené, keď je uvoľnené, sú zatvorené.</del><br> (deprecated, nahradené jazýčkovými spínačmi – pozri UPD nižšie)
6. Bolo by vhodné mať 4 alebo aspoň 2 LED diódy na indikáciu stavu bunky. Ak sú k dispozícii len dve LED diódy, svietiaca dióda znamená, že bunka je voľná, a nesvietiaca, že je obsadená. Ak sú k dispozícii 4 LED diódy, na každú z dvoch buniek pripadajú 2 LED diódy rôznych farieb, ktoré indikujú stav bunky.<br>
7. Odporové hodnoty by mali byť v rozmedzí 150–510 Ω, a to v rovnakom počte ako je počet LED diód. <br>

### Rozdelenie úloh

**Heorhii Chukhir:**
* **NFC a I2C komunikácia:** Implementácia komunikácie s doskou ST MB1161-A (čip M24SR) prostredníctvom zbernice I2C (vrátane spracovania prerušenia z pinu GPO) a vyčítavanie textových NDEF záznamov zapísaných smartfónom.
* **Spracovanie dát a prenos do PC:** Odosielanie načítaných identifikátorov používateľov z STM32 cez rozhranie UART do PC aplikácie (kde prebieha ich overenie oproti databáze).
* **Logika zámkov:** Prijímanie príkazov z PC cez UART a ovládanie výstupných pinov pre simuláciu odomknutia príslušnej bunky po úspešnej identifikácii. *(plánované rozšírenie o fyzické zámky so servopohonmi – pozri UPD nižšie)*
* **PC klient, logovanie a správa zásielok (C++):** Vytvorenie konzolovej aplikácie na obojsmernú komunikáciu cez UART, priradenie časových pečiatok, logovanie prístupov do JSON súboru a riadenie logiky zásielok (priraďovanie voľných buniek kuriérom, evidencia príjemcov a spracovanie stavu obsadenosti).

**Danylo Milkevych:**
* **Detekcia obsadenosti:** Integrácia a spracovanie signálov zo štyroch infračervených senzorov (2 pre každú bunku). Implementácia logiky pre presnejšie vyhodnotenie prítomnosti predmetu (vyhodnotenie stavu obsadenosti na základe kombinácie signálov z viacerých senzorov v jednej bunke).
* **Sledovanie stavu dverí:** Implementácia čítania stavu tlačidiel (simulácia otvorených/zatvorených dverí) vrátane ošetrenia zákmytov (debouncing) a odosielanie správ o týchto udalostiach cez rozhranie UART do PC. (deprecated, nahradené jazýčkovými spínačmi – pozri UPD nižšie)
* **Vizuálna indikácia a hardvér:** Riadenie LED diód na základe aktuálneho stavu bunky (voľná/obsadená) a celkové zapojenie komponentov na breadboarde.


  ---
### UPD. (Návrh zmeny hardvéru pre dvierka a zámky – čaká na schválenie)
* **Zmena hardvéru (detekcia dvierok):** Namiesto klasických tlačidiel (ktoré vyžadujú manuálne držanie počas simulácie) plánujeme použiť **2 ks jazýčkových spínačov (gerkonov) s magnetmi**. Magnet bude umiestnený na dvierkach bunky a jazýčkový spínač na ráme. Po zatvorení dvierok sa obvod automaticky zopne, čo spoľahlivejšie simuluje stav zatvorených/otvorených dverí.
* **Doplnenie hardvéru (zámky buniek):** Pre reálnu realizáciu uzamykania a odomykania buniek plánujeme doplniť **2 ks mikro-servopohonov (napr. SG90)**, ktoré budú mechanicky blokovať alebo uvoľňovať dvierka.
* **Úprava úloh (Danylo Milkevych):** Nahradenie logiky čítania tlačidiel za spracovanie signálov z jazýčkových spínačov (gerkonov) pre detekciu stavu dvierok jednotlivých buniek.
* **Úprava úloh (Heorhii Chukhir):** Implementácia riadenia mikro-servopohonov (pomocou PWM signálu z STM32) na fyzické odomknutie a uzamknutie príslušnej bunky po prijatí príkazu z PC aplikácie.
