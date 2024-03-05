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
        esptool --chip esp32s3 merge_bin -o monica-firmware-0x0.bin 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0xe000 build/ota_data_initial.bin 0x10000 build/monica.bin 
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
