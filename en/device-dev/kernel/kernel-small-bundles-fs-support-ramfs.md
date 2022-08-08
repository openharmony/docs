# Ramfs


## Basic Concepts

Ramfs is a RAM-based file system whose size can be dynamically adjusted. Ramfs does not have a backing store. Directory entries and page caches are allocated when files are written into ramfs. However, data is not written back to any other storage medium. This means that data will be lost after a power outage.
## Working Principles
Ramfs stores all files in RAM, and read/write operations are performed in RAM. Ramfs is generally used to store temporary data or data that needs to be frequently modified, such as the **/tmp** and **/var** directories. Using ramfs reduces the read/write loss of the memory and improves the data read/write speed.
## Development Guidelines
Mount: 
```
mount(NULL, "/dev/shm", "ramfs", 0, NULL)
```
Create a directory: 
```
mkdir(pathname, mode)
```
Create a file:
```
open(pathname, O_NONBLOCK | O_CREAT | O_RDWR, mode)
```
Read a directory: 
```
dir = opendir(pathname) 
ptr = readdir(dir)
closedir(dir)
```
Delete a file: 
```
unlink(pathname)
```
Delete a directory:
```
rmdir(pathname)
```
Unmount: 
```
umount("/dev/shm")
```
> ![icon-caution.gif](../public_sys-resources/icon-caution.gif) **CAUTION**<br/>
> - A ramfs file system can be mounted only once. Once mounted to a directory, it cannot be mounted to other directories.
> 
> - Ramfs is under debugging and disabled by default. Do not use it in formal products.
