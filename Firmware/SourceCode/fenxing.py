import pygame

# 初始化pygame
pygame.init()

# 设置窗口尺寸和标题
width, height = 800, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Fractal Animation")

# 定义颜色
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# 定义绘制分形的函数
def draw_fractal(x, y, size, limit):
    if size > limit:
        pygame.draw.rect(screen, BLACK, (x, y, size, size), 1)
        # 递归绘制四个子分形
        draw_fractal(x, y, size//2, limit)
        draw_fractal(x + size//2, y, size//2, limit)
        draw_fractal(x, y + size//2, size//2, limit)
        draw_fractal(x + size//2, y + size//2, size//2, limit)

# 主循环
clock = pygame.time.Clock()
running = True
limit = 8  # 控制绘制分形的深度
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    screen.fill(WHITE)
    
    # 绘制分形
    draw_fractal(0, 0, width, limit)
    
    pygame.display.flip()
    clock.tick(10)

pygame.quit()

