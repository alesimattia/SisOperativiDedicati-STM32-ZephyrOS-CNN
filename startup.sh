# Trova l'indirizzo della porta seriale assegnata dal S.O.
cd /dev
ls > ~/without.txt
# Connetti la board
ls > ~/connected.txt
diff ~/without.txt ~/connected.txt
# qualcosa come tty.usbserial-DN014TJU

readonly BOARD="stm32f429i_disc1"
readonly PORT="tty.usbmodem1103"
PROJECT="1_progetto"

# Attiva ambiente virtuale
source ~/zephyrproject/.venv/bin/activate
cd ~/zephyrproject/zephyr

#Build (auto pristine)
west build --pristine auto --board $BOARD $PROJECT
west flash

# Avvia monitor seriale
screen /dev/$PORT 115200
# Premi Reset sulla board!
# CTRL-A then CTRL-\  per uscire dal monitor