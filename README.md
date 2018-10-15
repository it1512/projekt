# projekt
projekt Alarm

Postup práce:
1. Sehnání všech potřebných součástek
2. Instalace virtuálního linuxu na Virtualboxu
3. Fungování homie na mqtt (nedokončeno)

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
