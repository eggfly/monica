#!/bin/bash
### This is for lazzy shit like me to build -> flash - > monitor project
### Use < usbipd wsl attach -a -b [BUSID] > on PowerShell to auto attach the board


# Configs
IDF_PATH=$HOME/esp-idf-v5.1.2

# esptool.py  -p /dev/cu.usbmodem1101 write_flash 0x620000 ./spiffs_res_1/spring_wreath.bin 
# esptool.py  -p /dev/cu.usbmodem1101 write_flash 0x104e000 ./spiffs_res_1/walking.bin 

function do_work() {
    unsetopt nomatch
    # Get idf
    . ${IDF_PATH}/export.sh
    SERIAL_PORT=`ls /dev/cu.usbmodem* 2>/dev/null`
    if [[ -z "$SERIAL_PORT" ]]; then
        echo "No esp32 serial port detected, exit.";
        return;
    else
        echo "Detected serial port : $SERIAL_PORT"
    fi

    # Build and flash and monitor
    idf.py -p ${SERIAL_PORT} flash monitor
}

do_work
