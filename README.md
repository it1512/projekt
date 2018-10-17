# projekt
Projekt Alarm:

Budu dělat laserovou závoru, která v případě narušení začne zvonit. Na desce vysílače bude laser, který jsem vytáhl s chytré propisky a je připraven k použití. Ne sice na moc velkou vzdálenost, ale pro projekt, jehož výsledkem bude zmenšenina garáže, to bude stačit. Na desce přijímače bude fototranzistor, který bude přijímat data a vyhodnocovat je. Rovněž bude ošetřeno zneužití tím, že budu posílat impulsy z laseru. Tím zamezím možnému zneužití. Hlavní program budu psát v ESP8266 LoLin McNode.

Součástky, které potřebuji k funkčnosti programu jsou: Relátka na 5V, tranzistory, odpory a tak dále.

Původně jsem chtěl dělat v Arduinu, ale díky tomu, že budu muset dělat odesílání dat na MQTT, budu muset použít právě MQTT. Moje první pokusy začaly, když jsem doma stáhl a nainstaloval VirtualBox a na něm spustil Ubuntu 16.04. Avšak zde byl problém s právy a po následných konzultacích na fórech a také s panem učitelem jsem přišel se závěrem, že bude problém s tím, že Ubuntu spouštím ve VirtualBoxu. Takže jsem se rozhlodl, že to zkusím ještě ve Windowsu i přes to, že mi to pan učitel zavrhl. Vyjímečně měl pravdu, jelikož tam jsem měl chyb ještě víc a nedokázal jsem si s nimi poradit. Pan učitel mě zaúkoloval tím, že si mám stáhnout VSCode, v něm nainstalovat Platformio a rozběhat MQTT s pomocí homie. Tak jsem nakonec sprovoznil čistý linux na notebooku a chtěl jsem v aplikacích najít a nainstalovat Visual Studio Code. Ten tam však nebyl, tak momentálně pracuji na tom, jak jej v Linuxu správně stáhnout.

sudo usermod -a -G dialout student -> problém s dev/tty/USB0

sudo pip install --upgrade pip

sudo pio upgrade  

pio run

pio run -t upload -> upload na esp

pio run -t uploadfs -> upload na mqtt

pio device monitor -b 115200 -> monitoruje ve VS code terminálu

mosquitto_pub -t homie/6001940b518f/switch/on/set -m "false" -> vypne ledku (true zapne)

mosquitto_sub -t "#" -v -> vypíše mqtt

sudo apt install mosquitto

sudo apt install mosquitto clients -> sub a pub

