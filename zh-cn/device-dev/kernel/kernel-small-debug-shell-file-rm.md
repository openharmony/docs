# rm


## 命令功能

rm命令用来删除文件或文件夹。


## 命令格式

rm [_-fv_] _FILE or rm_ [_-rv_] [_PATH_ | _filename_]...


## 参数说明

**表1** 参数说明

| 参数          | 参数说明                                         |
| ------------- | ------------------------------------------------ |
| -r            | 删除空目录或非空目录。                           |
| -f            | 强制删除：不需要确认，删除不存的文件在也不报错。 |
| -v            | 显示删除的过程。                                 |
| PATH/filename | 要删除文件或文件夹的名称，支持输入路径。         |


## 使用指南

- rm命令能同时删除多个文件或文件夹。

- rm -r命令可以删除非空目录。

- 删除不存在的文件会报错。

## 特殊说明

-f -v 参数shell端暂不支持。切换mksh版本可全支持，方法：cd bin; ./mksh。

## 使用实例

举例：

- 输入rm testfile

- 输入rm -r testpath/


## 输出说明

**示例1** 用 rm 命令删除文件 testfile


```
OHOS:/$ ls
bin  etc  proc    storage  testfile  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ rm testfile
OHOS:/$ ls
bin  etc  proc    storage  userdata  vendor
dev  lib  sdcard  system   usr
```

**示例2** 用 rm -r 删除非空目录 testpath


```
OHOS:/$ ls
bin  etc  proc    storage  testpath  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ rm -r testpath/
OHOS:/$ ls
bin  etc  proc    storage  userdata  vendor
dev  lib  sdcard  system   usr
```