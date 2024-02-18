
# Initialize 

import display_driver
import lvgl as lv

import gc
import random
import time

scr = lv.obj()
canvas = lv.canvas(scr)
width, height = 420, 200
array_buffer = bytearray(width*height*4)
for i in dir(lv):
    pass
    if 'timer' in i: print(i)
canvas.set_buffer(array_buffer, width, height, 0x4)
canvas.center()
canvas.fill_bg(lv.color_hex(0xEEEEEE), lv.OPA._10)
pen = lv.color_hex(0xFF0000)

btn = lv.btn(scr)
# btn.align(lv.ALIGN.CENTER, 0, 0)
label = lv.label(btn)
label.set_text('Monte Carlo')

def logistic_map(r, x):
    return r * x * (1 - x)

# v is value. Maps a-b range to c-d range
def map_range(v, a, b, c, d):
    return (v-a) / (b-a) * (d-c) + c

def bifurcation_diagram(canvas, r_min, r_max, x_count, num_iterations):
    r_values = []
    x_values = []

    for r in range(x_count):
        miu = map_range(r, 0, x_count, r_min, r_max)
        x = 0.5
        for i in range(num_iterations):
            x = logistic_map(miu, x)
            if i > num_iterations * 0.7:
                r_value = miu
                x_value = x
                point_x = int(map_range(r_value, r_min, r_max, 0, width))
                point_y = int(x_value * height)
                #if 0 <= point_x < width and 0 <= point_y < height:
                canvas.set_px(point_x, point_y, pen)
    print(r_values)
    print(x_values)
    for i in range(len(r_values)):
        pass
x_count = width
bifurcation_diagram(canvas, 2.8, 4.0, x_count, 1000)


def timer_cb(obj):
    x = int(random.random() * width)
    y = int(random.random() * height)
    canvas.set_px(x,y, pen)

# lv.timer_create(timer_cb, 1, None)
lv.scr_load(scr)
print(gc.mem_free())


