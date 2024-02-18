
# Initialize 

import display_driver
import lvgl as lv

import gc
import random
import time
import math



scr = lv.obj()
canvas = lv.canvas(scr)
width, height = 240, 240
array_buffer = bytearray(width*height*4)
for i in dir(lv):
    pass
    if 'timer' in i: print(i)
canvas.set_buffer(array_buffer, width, height, 0x4)
canvas.center()
canvas.fill_bg(lv.color_hex(0xEEEEEE), lv.OPA._50)
pen = lv.color_hex(0xFF0000)

btn = lv.btn(scr)
# btn.align(lv.ALIGN.CENTER, 0, 0)
label = lv.label(btn)
label.set_text('double_pendulum')

# v is value. Maps a-b range to c-d range
def map_range(v, a, b, c, d):
    return (v-a) / (b-a) * (d-c) + c




# 定义双摆混沌的微分方程
def double_pendulum(theta1, omega1, theta2, omega2, m1, m2, L1, L2, g):
    dtheta1 = omega1
    domega1 = (-g * (2 * m1 + m2) * math.sin(theta1) - m2 * g * math.sin(theta1 - 2 * theta2) - 2 * math.sin(theta1 - theta2) * m2 * (omega2**2 * L2 + omega1**2 * L1 * math.cos(theta1 - theta2))) / (L1 * (2 * m1 + m2 - m2 * math.cos(2 * theta1 - 2 * theta2)))
    dtheta2 = omega2
    domega2 = (2 * math.sin(theta1 - theta2) * (omega1**2 * L1 * (m1 + m2) + g * (m1 + m2) * math.cos(theta1) + omega2**2 * L2 * m2 * math.cos(theta1 - theta2))) / (L2 * (2 * m1 + m2 - m2 * math.cos(2 * theta1 - 2 * theta2)))

    return dtheta1, domega1, dtheta2, domega2

# 设置参数
m1 = 1.0
m2 = 1.0
L1 = 1.0
L2 = 1.0
g = 9.81

# 设置初始条件
theta1 = math.pi/2
omega1 = 0
theta2 = math.pi/2
omega2 = 0.1

# 求解微分方程
dt = 0.01
theta1_vals = []
theta2_vals = []


def timer_cb(obj):
    try:
        global theta1, theta2, omega1, omega2
        x = int(theta1 * width / 16 + width / 2)
        y = int(theta2 * height / 16 + height / 2)
        canvas.set_px(x, y, pen)
        dtheta1, domega1, dtheta2, domega2 = double_pendulum(theta1, omega1, theta2, omega2, m1, m2, L1, L2, g)
        theta1 += dtheta1 * dt
        omega1 += domega1 * dt
        theta2 += dtheta2 * dt
        omega2 += domega2 * dt
    except Exception as e:
        print(e)

lv.timer_create(timer_cb, 0, None)
lv.scr_load(scr)
print(gc.mem_free())



