# ls


## 命令功能

ls命令用来显示当前目录的内容。


## 命令格式

ls [_-ACHLSZacdfhiklmnopqrstux1_] [_--color_[_=auto_]] [_directory..._]

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>  系统启动过程中已经通过 alias 为 ls=toybox ls --color=auto 、ll = ls -alF 、 la=ls -A 和 l=ls -CF 赋能，使这几个命令的初始行为就和linux相同（详细效果见输出说明）。所以若要查看help列表，请输入'toybox ls --help'。


## 参数说明

**表1** 展示功能参数说明

| 参数   | 参数说明                                                     | 取值范围                      |
| ------ | ------------------------------------------------------------ | ----------------------------- |
| --help | 查看ls命令支持的参数列表，使用方式。                         | N/A                           |
| -a     | 显示所有文件包括.hidden隐藏类型的文件。                      | N/A                           |
| -b     | 转义非图形字符。                                             | N/A                           |
| -c     | 使用ctime作为文件的时间戳，必须和-l参数一块使用。            | N/A                           |
| -d     | 只显示path名称不显示path所包含的内容。                       | N/A                           |
| -i     | 显示文件的节点号。                                           | N/A                           |
| -p     | 在path名称后放一个"/"。                                      | N/A                           |
| -q     | 显示不可打印字符比如'?'。                                    | N/A                           |
| -s     | 统计目录和其成员所占用的内存大小，单位为1024字节。           | N/A                           |
| -u     | 以文件的最后访问时间为时间戳，配合&nbsp;-l&nbsp;一起使用。   | N/A                           |
| -A     | 列出所有文件除了.和..                                        | N/A                           |
| -H     | 跟随命令行符号链接。                                         | N/A                           |
| -L     | 跟随符号链接。                                               | N/A                           |
| -Z     | 安全上下文。                                                 | N/A                           |
| path   | path为空时，显示当前目录的内容。<br/>path为无效文件名时，显示失败，提示：<br/>ls&nbsp;error:&nbsp;No&nbsp;such&nbsp;directory。<br/>path为有效目录路径时，会显示对应目录下的内容。 | 1.为空。<br/>2.有效的目录路径 |

**表2** 输出格式参数说明

| 参数    | 参数说明                                |
| ------- | --------------------------------------- |
| -1      | 每行列出一个文件。                      |
| -c      | 列，垂直排序。                          |
| -g      | 类似于&nbsp;-l&nbsp;但没有所有者。      |
| -h      | 统计path目录下文件的总大小，单位为KiB。 |
| -l      | 详细的显示path目录下文件的信息。        |
| -m      | 文件之间添加逗号。                      |
| -n      | 类似&nbsp;-l&nbsp;数字格式显示uid/gid。 |
| -o      | 类似&nbsp;-l&nbsp;但显示列表不包括组。  |
| -x      | 列，水平排序。                          |
| -ll     | 文件的时间属性显示纳秒。                |

**表3** 排序参数说明（默认为按首字母排序）

| 参数 | 参数说明                                   |
| ---- | ------------------------------------------ |
| -f   | 不排序。                                   |
| -r   | 按首字母反向排序。                         |
| -t   | 按文件的最后修改时间排序，最近时间为排头。 |
| -S   | 按文件大小来排序，大文件为排头。           |

**表4** 彩色打印

| 参数 | 默认配置                                   |
| ---- | ------------------------------------------ |
| --color  | device=yellow symlink=turquoise/red dir=blue socket=purple files: exe=green suid=red suidfile=redback stickydir=greenback=auto means detect if output is a tty. |

## 使用指南

  无

> **须知：**
> fatfs的文件节点信息继承其父节点，父节点号为0。故在hi3516dv300开发板上ls -i显示的文件节点号全为0。

## 特殊说明

ls中参数shell端暂不支持。切换mksh版本可全支持，方法：cd bin; ./mksh。

## 使用实例

举例：

- ls

- ll


## 输出说明

**示例1** ls命令查看当前路径下的内容

```
OHOS:/$ ls
bin  etc  nfs   sdcard   system    usr
dev  lib  proc  storage  userdata  vendor
```

**示例2** ll命令查看当前路径下的内容

```
OHOS:/$ ll
total 20
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 bin/
drwxr-xr-x 0 0 0    0 1970-01-01 00:00 dev/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 etc/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 lib/
drwxrwxrwx 0 0 0 4096 2021-10-25 02:17 nfs/
dr-xr-xr-x 0 0 0    0 1970-01-01 00:00 proc/
drwxrwxrwx 1 0 0 4096 1979-12-31 00:00 sdcard/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 storage/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 system/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 userdata/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 usr/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 vendor/
```