# projekt
Projekt Alarm:

Budu dělat laserovou závoru, která v případě narušení začne zvonit. Na desce vysílače bude laser, který jsem vytáhl s chytré propisky a je připraven k použití. Ne sice na moc velkou vzdálenost, ale pro projekt, jehož výsledkem bude zmenšenina garáže, to bude stačit. Na desce přijímače bude fototranzistor, který bude přijímat data a vyhodnocovat je. Rovněž bude ošetřeno zneužití tím, že budu posílat impulsy z laseru. Tím zamezím možnému zneužití. Hlavní program budu psát v ESP8266 LoLin McNode.

Součástky, které potřebuji k funkčnosti programu jsou: Relátka na 5V, tranzistory, odpory a tak dále.

Původně jsem chtěl dělat v Arduinu, ale díky tomu, že budu muset dělat odesílání dat na MQTT, budu muset použít právě MQTT. Moje první pokusy začaly, když jsem doma stáhl a nainstaloval VirtualBox a na něm spustil Ubuntu 16.04. Poté jsem stáhl kód ze stránky:

https://github.com/petrgru/homie-dual-relay -> abych podrobněji zjistil, jak homie funguje. Ve škole jsem ho zprovoznil bez větších problémů a s pomocí pana učitele jsem pochopil, co jak funguje.

Avšak zde byl problém s právy, s kterým jsem myslel, že si poradím, protože ten stejný problém jsem řešil ve škole na PC a úspěšně jej vyřešil. Jenomže doma tento postup nefungoval a po následných konzultacích na fórech a také s panem učitelem jsem přišel se závěrem, že bude problém s tím, že Ubuntu 16.04. spouštím ve VirtualBoxu. Takže jsem se rozhlodl, že to zkusím ještě ve Windowsu i přes to, že mi to pan učitel zavrhl. Vyjímečně měl pravdu, jelikož tam jsem měl chyb ještě víc a nedokázal jsem si s nimi poradit a nechtělo se mi s tím piplat, protože je jednodušší si doma vytvořit stejné podmínky jako ve škole tím, že doma nainstaluju do jednoho ze svých notebooků Ubuntu. Pan učitel mě zaúkoloval tím, že si v něm mám stáhnout VSCode, v něm nainstalovat Platformio a rozběhat MQTT s pomocí Homie. Tak jsem nakonec zprovoznil čistý linux na notebooku a chtěl jsem v aplikacích najít a nainstalovat Visual Studio Code tak, jak jsem to dělal i ve VirtualBoxu. Ten tam však nebyl, tak momentálně pracuji na tom, jak jej v Linuxu správně stáhnout, rozbalit a hlavně nainstalovat.

Takový byl postup zprovoznění homie v učebně ve škole někdy v první polovině října:
Kód funguje tak, že se rozsvítí ledka a data se odešlou na server. Po stisknutí tlačítka se ledka vypne a změněné údaje se zaktualizují a odešlou na MQTT server.

sudo usermod -a -G dialout student -> problém s dev/tty/USB0 

sudo pip install --upgrade pip -> v případě nefunkčnosti příkazu o jeden řádek výše použijete právě toto

sudo pio upgrade -> upgrade pio 

pio run

pio run -t upload -> upload kódu na vaše zařízení

pio run -t uploadfs -> upload na MQTT server

pio device monitor -b 115200 -> monitoruje stav zařízení a jak kód funguje ve Visual Studio Code v terminálu

mosquitto_pub -t homie/6001940b518f/switch/on/set -m "false" -> vypne ledku - příkaz true ji zapne

mosquitto_sub -t "#" -v -> vypíše MQTT

sudo apt install mosquitto -> install mosquitta, je nezbytné k funkčnosti programu

sudo apt install mosquitto clients -> sub a pub

