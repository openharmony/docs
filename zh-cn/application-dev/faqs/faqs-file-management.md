# 文件管理开发常见问题

## 如何获取系统截屏图片的保存路径

适用于OpenHarmony 3.2 Beta5  API 9

**解决措施**

截图图片保存路径：/storage/media/100/local/files/Pictures/Screenshots/

## 如何修改设备中文件目录为可读写权限

适用于OpenHarmony 3.2 Beta5  API 9

**问题现象**

使用hdc命令向设备上发送文件时，报错：权限不足。

**解决措施**

输入命令 hdc shell mount -o remount,rw /，正确执行无提示信息。


