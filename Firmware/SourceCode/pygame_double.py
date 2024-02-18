import sys
import pygame
import math

# 初始化pygame
pygame.init()

# 设置窗口大小
width, height = 800, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Double Pendulum Simulation")

# 定义双摆参数
length1 = 200
length2 = 50
mass1 = 40
mass2 = 20
angle1 = math.pi / 2
angle2 = math.pi / 2
angle1_v = 0
angle2_v = 0
g = 9.81

# 定义画布中心点
center_x = width // 2
center_y = height // 2

# 主循环
running = True
clock = pygame.time.Clock()

while running:
    screen.fill((255, 255, 255))
    if math.isnan(angle1) or math.isinf(angle1):
        # 处理NaN的情况，比如重新初始化角度为合法值
        angle1 = 0  # 重新初始化为0度
    if math.isnan(angle2) or math.isinf(angle2):
        # 处理NaN的情况，比如重新初始化角度为合法值
        angle2 = 0  # 重新初始化为0度
    # 计算双摆的位置
    x1 = center_x + length1 * math.sin(angle1)
    y1 = center_y + length1 * math.cos(angle1)
    x2 = x1 + length2 * math.sin(angle2)
    y2 = y1 + length2 * math.cos(angle2)

    # 画出双摆
    pygame.draw.line(screen, (0, 0, 0), (center_x, center_y), (x1, y1), 2)
    if not math.isnan(x1) and not math.isnan(y1):
        pygame.draw.circle(screen, (0xFF, 0, 0), (int(x1), int(y1)), mass1 // 2)
    pygame.draw.line(screen, (0, 0, 0), (x1, y1), (x2, y2), 2)
    if not math.isnan(x2) and not math.isnan(y2):
        pygame.draw.circle(screen, (0, 0xFF, 0), (int(x2), int(y2)), mass2 // 2)

    # 更新角度
    num1 = -g * (2 * mass1 + mass2) * math.sin(angle1)
    num2 = -mass2 * g * math.sin(angle1 - 2 * angle2)
    num3 = -2 * math.sin(angle1 - angle2) * mass2
    num4 = angle2_v * angle2_v * length2 + angle1_v * angle1_v * length1 * math.cos(angle1 - angle2)
    den = length1 * (2 * mass1 + mass2 - mass2 * math.cos(2 * angle1 - 2 * angle2))
    angle1_a = (num1 + num2 + num3 * num4) / den

    num1 = 2 * math.sin(angle1 - angle2)
    num2 = (angle1_v * angle1_v * length1 * (mass1 + mass2))
    num3 = g * (mass1 + mass2) * math.cos(angle1)
    num4 = angle2_v * angle2_v * length2 * mass2 * math.cos(angle1 - angle2)
    den = length2 * (2 * mass1 + mass2 - mass2 * math.cos(2 * angle1 - 2 * angle2))
    angle2_a = (num1 * (num2 + num3 + num4)) / den

    angle1_v += angle1_a
    angle2_v += angle2_a
    angle1 += angle1_v
    angle2 += angle2_v

    # 限制角度范围
    if angle1 > math.pi:
        angle1 -= 2 * math.pi
    if angle1 < -math.pi:
        angle1 += 2 * math.pi
    if angle2 > math.pi:
        angle2 -= 2 * math.pi
    if angle2 < -math.pi:
        angle2 += 2 * math.pi

    pygame.display.flip()
    clock.tick(20)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
