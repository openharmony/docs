# free


## 命令功能

free命令可显示系统内存的使用情况。


## 命令格式

free [_-b | -k | -m | -g | -t_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 |
| -------- | -------- |
| 无参数 | 以Byte为单位显示。 |
| --help/-h | 查看free命令支持的参数列表。 |
| -b | 以Byte为单位显示。 |
| -k | 以KiB为单位显示。 |
| -m | 以MiB为单位显示。 |
| -g | 以GiB为单位显示。 |
| -t | 以TiB为单位显示。 |


## 使用指南

无。


## 使用实例

举例：分别输入free、free -k、free -m.


## 输出说明

  
```
OHOS:/$ free
                total        used        free      shared     buffers
Mem:          2819652     2754468       65184           0           0
-/+ buffers/cache:        2754468       65184
Swap:               0           0           0
OHOS:/$ free -k
                total        used        free      shared     buffers
Mem:             2753        2692          60           0           0
-/+ buffers/cache:           2692          60
Swap:               0           0           0
OHOS:/$ free -m
                total        used        free      shared     buffers
Mem:                2           2           0           0           0
-/+ buffers/cache:              2           0
Swap:               0           0           0
```

**表2** 输出说明

| 输出 | 说明 | 
| -------- | -------- |
| total | 表示系统动态内存池总量。 | 
| used | 表示已使用内存总量。 | 
| free | 表示未被分配的内存大小。 | 
| shared | 表示共享内存大小。 | 
| buffers | 表示缓冲区内存大小。 | 
