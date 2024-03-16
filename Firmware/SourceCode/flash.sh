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
    
    if [[ "$1" == "--only-build" ]]; then
        idf.py build
        cd build
        # DATE=`date +%Y%m%d%H%M%S`
        DATE=`date +%Y%m%d`
        esptool --chip esp32s3 merge_bin -o ../monica_firmware_0x0_$DATE.bin @flash_args
        cd -
        zip monica_firmware_0x0_$DATE.zip monica_firmware_0x0_$DATE.bin
    else
        SERIAL_PORT=`ls /dev/cu.usbmodem* 2>/dev/null`
        if [[ -z "$SERIAL_PORT" ]]; then
            echo "No esp32 serial port detected, exit.";
            return;
        else
            echo "Detected serial port : $SERIAL_PORT"
        fi
        if [[ "$1" == "--only-monitor" ]]; then
            # Build, flash, and monitor
            idf.py -p ${SERIAL_PORT} monitor --no-reset
        else
            # Build, flash, and monitor
            idf.py -p ${SERIAL_PORT} flash monitor
        fi
    fi
}

do_work "$@"
