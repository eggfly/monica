from PIL import Image
import struct

def convert_lvgl_to_png(bin_file, width, height, output_file):
    # 读取二进制数据文件
    with open(bin_file, 'rb') as f:
        lvgl_data = f.read()

    # 创建一个新的RGBA图像
    image = Image.new('RGBA', (width, height))

    # 转换LVGL数据为像素
    pixels = []
    for i in range(0, len(lvgl_data), 3):
        # 从LVGL数据中提取RGB565和alpha数据
        pixel = struct.unpack('<H', lvgl_data[i:i+2])[0]
        alpha = lvgl_data[i+2]

        # 提取RGB565数据
        r = ((pixel >> 11) & 0x1F) << 3
        g = ((pixel >> 5) & 0x3F) << 2
        b = (pixel & 0x1F) << 3

        # 将RGB和alpha组合成像素
        pixels.append((r, g, b, alpha))

    # 将像素数据放入图像
    image.putdata(pixels)

    # 保存图像到文件
    image.save(output_file, format='PNG', compress_level=0)

# 循环处理多个文件
for i in range(31):
    bin_file = f'walking_{i}.bin'
    output_file = f'walking_{i}.png'

    # 宽度和高度
    width = 102
    height = 147

    convert_lvgl_to_png(bin_file, width, height, output_file)
    