#!/bin/bash

# 设置要转换的图片文件名前缀和数量
prefix="ui_img_anim_spring_wreath_"
total=27

# 循环执行转换命令
for ((i=0; i<total; i++))
do
    input="./${prefix}$(printf "%02d" $i).png"
    ~/github/monica/Firmware/SourceCode/components/lvgl/scripts/LVGLImage.py --ofmt C --cf I8 -v $input
done
