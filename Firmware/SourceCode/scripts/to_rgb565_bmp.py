from PIL import Image

# 打开JPEG图像文件
img = Image.open('../tfcard_files/winxp.jpg')

# 将图像转换为16比特RGB565格式
img = img.convert('RGB;16')

# 保存为BMP文件
img.save('winxp.bmp')
