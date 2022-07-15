# Ramfs


## 基本概念

RAMFS是一个可动态调整大小的基于RAM的文件系统。RAMFS没有后备存储源。向RAMFS中进行的文件写操作也会分配目录项和页缓存，但是数据并不写回到任何其他存储介质上，掉电后数据丢失。
## 运行机制
RAMFS文件系统把所有的文件都放在 RAM 中，所以读/写操作发生在RAM中，可以用RAMFS来存储一些临时性或经常要修改的数据，例如/tmp和/var目录，这样既避免了对存储器的读写损耗，也提高了数据读写速度。
## 开发指导
挂载：  
```
mount(NULL, "/dev/shm", "ramfs", 0, NULL)
```
创建目录：  
```
mkdir(pathname, mode)
```
创建文件： 
```
open(pathname, O_NONBLOCK | O_CREAT | O_RDWR, mode)
```
读取目录：  
```
dir = opendir(pathname) 
ptr = readdir(dir)
closedir(dir)
```
删除文件：  
```
unlink(pathname)
```
删除目录： 
```
rmdir(pathname)
```
去挂载：  
```
umount("/dev/shm")
```
> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
> - RAMFS只能挂载一次，一次挂载成功后，后面不能继续挂载到其他目录。
> 
> - RAMFS属于调测功能，默认配置为关闭，正式产品中不要使用该功能。
