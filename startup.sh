# Discover board serial port assigned in your SO
cd /dev
ls > ~/disconnect.txt
# connect board
ls > ~/reconnect.txt
diff ~/disconnect.txt ~/reconnect.txt
# something like tty.usbserial-DN014TJU

readonly BOARD="stm32f429i_disc1"
readonly PORT="tty.usbmodem1103"
PROJECT="2_integrazione"

# Virtual environment
source ~/zephyrproject/.venv/bin/activate
cd ~/zephyrproject/zephyr

#Build (auto pristine)
west build --pristine auto --board $BOARD $PROJECT
west flash

# Start Serial communication
screen /dev/$PORT 115200
# Press Reset and look!
# CTRL-A then CTRL-\  to quit serial comm.



#Add tflite-micro module to the West manifest 
#(First time only)
#west config manifest.project-filter -- +tflite-micro
#west update