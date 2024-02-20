from PIL import Image

def bgr565_alpha_to_rgba8888(bgr565_alpha_data, width, height):
    rgba8888_data = bytearray()  # 用于存储RGBA8888格式的数据
    for i in range(0, len(bgr565_alpha_data), 3):
        bgr565 = bgr565_alpha_data[i] + (bgr565_alpha_data[i+1] << 8)  # 提取BGR565数据
        alpha = bgr565_alpha_data[i+2]  # 提取8位alpha数据

        blue = (bgr565 & 0x1F) << 3
        green = ((bgr565 >> 5) & 0x3F) << 2
        red = ((bgr565 >> 11) & 0x1F) << 3

        rgba8888_data.extend([red, green, blue, alpha])  # 添加RGBA8888数据

    return rgba8888_data

width = 102
height = 147

for i in range(27):
    # 读取BGR565和8位alpha数据
    with open('walking_%d.bin' % i, 'rb') as file:
        bgr565_alpha_data = file.read(width * height * 3)  # 3字节表示一个像素的BGR565和8位alpha数据

    # 转换为RGBA8888格式
    rgba8888_data = bgr565_alpha_to_rgba8888(bgr565_alpha_data, width, height)

    # 创建PIL Image对象
    image = Image.frombytes('RGBA', (width, height), bytes(rgba8888_data))

    # 保存为PNG文件
    image.save('walking_%d.png' % i)