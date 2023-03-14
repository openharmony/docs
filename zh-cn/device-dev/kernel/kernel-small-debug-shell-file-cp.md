# cp


## 命令功能

拷贝文件，创建一份副本。


## 命令格式

cp [_SOURCEFILE_] [_DESTFILE_]


## 参数说明

  **表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| --help | 使用帮助。 | N/A | 
| SOURCEFILE | 源文件路径。 | 目前只支持文件,不支持目录；支持多文件同时拷贝。 | 
| DESTFILE | 目的文件路径。 | 支持目录以及文件。 | 


## 使用指南

- 同一路径下，源文件与目的文件不能重名。

- 源文件必须存在，且不为目录。

- 源文件路径支持“\*”和“？”通配符，“\*”代表任意多个字符，“？”代表任意单个字符。目的路径不支持通配符。当源路径可匹配多个文件时，目的路径必须为目录。

- 目的路径为目录时，该目录必须存在。此时目的文件以源文件命名。

- 目的路径为文件时，所在目录必须存在。此时拷贝文件的同时为副本重命名。

- 目的文件不存在时创建新文件，已存在则覆盖。

> ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
> 拷贝系统重要资源时，会对系统造成死机等重大未知影响，如用于拷贝/dev/uartdev-1 文件时，会产生系统卡死现象。


## 使用实例

举例：cp hello-OHOS.txt hello-openharmony.txt ./tmp/


## 输出说明

**示例** 同时拷贝两个文件至指定目录

```
OHOS:/$ ls
bin  hello-OHOS.txt     proc     system    vendor
dev  hello-openharmony.txt  sdcard   userdata
etc  lib                storage  usr
OHOS:/$ mkdir tmp
OHOS:/$ cp hello-OHOS.txt hello-openharmony.txt tmp/
OHOS:/$ ll tmp
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 hello-OHOS.txt*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 hello-openharmony.txt*
```
