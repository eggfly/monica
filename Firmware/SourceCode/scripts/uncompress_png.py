from PIL import Image

for i in range(27):
    # 打开PNG图像文件
    img = Image.open(f'spring_wreath_{i}.png')

    # 保存为不压缩的PNG文件
    img.save(f'{i}.png', compress_level=0)

print("转换完成！")
