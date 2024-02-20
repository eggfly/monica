import pygame

# 初始化pygame
pygame.init()

# 设置窗口尺寸和标题
width, height = 1024, 720
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Mandelbrot Fractal")

# 定义颜色
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# 定义绘制Mandelbrot分形的函数


def mandelbrot(c, max_iter):
    z = 0
    n = 0
    while abs(z) <= 2 and n < max_iter:
        z = z*z + c
        n += 1
    if n == max_iter:
        return 0
    return n / max_iter


# 主循环
clock = pygame.time.Clock()
running = True
max_iter = 100
scale = 0.004
offset = complex(-0.5, 0)
curr_iter = 1
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill(WHITE)

    curr_iter += 1
    if curr_iter > max_iter:
        curr_iter = max_iter
    for x in range(width):
        for y in range(height):
            re = scale * (x - width/2) + offset.real
            im = scale * (y - height/2) + offset.imag
            c = complex(re, im)
            color = mandelbrot(c, curr_iter)
            color = int(color * 255)
            screen.set_at((x, y), (color, color, color))

    pygame.display.flip()
    clock.tick(5)
    print("iter=", curr_iter)

pygame.quit()
