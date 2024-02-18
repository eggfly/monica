import pygame
import math

# 初始化pygame
pygame.init()

# 设置窗口尺寸和标题
width, height = 800, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Double Pendulum Simulation")

# 定义参数
g = 9.81  # 重力加速度
length1 = 200  # 第一个摆杆长度
length2 = 200  # 第二个摆杆长度
mass1 = 20  # 第一个球的质量
mass2 = 20  # 第二个球的质量

# 初始条件
theta1 = math.pi / 2  # 第一个摆杆初始角度
theta2 = math.pi / 2  # 第二个摆杆初始角度
omega1 = 0  # 第一个摆杆初始角速度
omega2 = 0  # 第二个摆杆初始角速度

# 定义更新函数
def update():
    global theta1, theta2, omega1, omega2
    delta = theta2 - theta1
    den1 = (mass1 + mass2) * length1 - mass2 * length1 * math.cos(delta) * math.cos(delta)
    
    # 计算角加速度
    alpha1 = (mass2 * length2 * omega2 * omega2 * math.sin(delta) * math.cos(delta)
              + mass2 * g * math.sin(theta2) * math.cos(delta)
              + mass2 * length1 * omega1 * omega1 * math.sin(delta)
              - (mass1 + mass2) * g * math.sin(theta1)) / den1
    
    alpha2 = ((mass1 + mass2) * (length1 * omega1 * omega1 * math.sin(delta)
              - g * math.sin(theta2)
              + g * math.sin(theta1) * math.cos(delta)) / length2) / den1
    
    # 更新角度和角速度
    theta1 += omega1
    theta2 += omega2
    omega1 += alpha1
    omega2 += alpha2

# 主循环
clock = pygame.time.Clock()
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    update()
    
    # 绘制双摆
    x1 = width // 2 + length1 * math.sin(theta1)
    y1 = height // 2 + length1 * math.cos(theta1)
    x2 = x1 + length2 * math.sin(theta2)
    y2 = y1 + length2 * math.cos(theta2)
    
    screen.fill((255, 255, 255))
    pygame.draw.line(screen, (0, 0, 0), (width // 2, height // 2), (x1, y1), 2)
    pygame.draw.circle(screen, (0, 0, 0), (int(x1), int(y1)), mass1 // 2)
    pygame.draw.line(screen, (0, 0, 0), (x1, y1), (x2, y2), 2)
    pygame.draw.circle(screen, (0, 0, 0), (int(x2), int(y2)), mass2 // 2)
    
    pygame.display.flip()
    clock.tick(60)

pygame.quit()
