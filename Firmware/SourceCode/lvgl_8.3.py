import display_driver
import lvgl as lv
import gc
import random
import time

scr = lv.obj()
c = lv.canvas(scr)
width, height = 320, 320
array_buffer = bytearray(width*height*4)
for i in dir(lv):
    if 'timer' in i: print(i)
c.set_buffer(array_buffer, width, height, 0x4)
c.center()
c.fill_bg(lv.color_hex(0xEEEEEE), lv.OPA._10)
pen = lv.color_hex(0xFF0000)

btn = lv.btn(scr)
# btn.align(lv.ALIGN.CENTER, 0, 0)
label = lv.label(btn)
label.set_text('Monte Carlo')

def timer_cb(obj):
    x = int(random.random() * width)
    y = int(random.random() * height)
    c.set_px(x,y, pen)

lv.timer_create(timer_cb, 1, None)
lv.scr_load(scr)
print(gc.mem_free())
