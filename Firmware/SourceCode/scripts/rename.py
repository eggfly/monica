import os

# 设置文件夹路径
folder_path = "./"

# 遍历重命名文件
for i in range(0, 30):
    # 旧文件名
    old_name = f"spring_wreath_{i}.png"
    
    # 新文件名
    new_name = f"ui_img_anim_spring_wreath_{i:02}.png"
    
    # 旧文件路径
    old_path = os.path.join(folder_path, old_name)
    
    # 新文件路径
    new_path = os.path.join(folder_path, new_name)
    
    # 重命名文件
    os.rename(old_path, new_path)
    
    print(f"文件 {old_name} 重命名为 {new_name}")
    