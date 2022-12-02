# touch


## 命令功能

- touch命令用来在指定的目录下创建一个不存在的空文件。

- touch命令操作已存在的文件会成功，不会更新时间戳。


## 命令格式

touch [_filename_]


## 参数说明

  **表1** 参数说明

| 参数     | 参数说明                    | 取值范围 |
| -------- | --------------------------- | -------- |
| --help   | 查看touch命令支持的参数列表 | N/A      |
| filename | 需要创建文件的名称。        | N/A      |


## 使用指南

- touch命令用来创建一个空文件，该文件可读写。

- 使用touch命令允许一次创建多个文件。

  > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
  > 在系统重要资源路径下使用touch命令创建文件，会对系统造成死机等未知影响，如在/dev路径下执行touch uartdev-0，会产生系统卡死现象。

## 特殊说明

--help参数以及同时创建多个文件，shell端暂不支持。切换mksh版本可全支持，方法：cd bin; ./mksh。

## 使用实例

举例：

- touch file.c

- touch testfile1 testfile2 testfile3


## 输出说明

**示例 1** 创建一个名为 file.c 的文件


```
OHOS:/tmp$ ls
OHOS:/tmp$ touch file.c
OHOS:/tmp$ ls
file.c
OHOS:/tmp$ ll
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 file.c*
```

**示例 2** 同时创建三个文件


```
*OHOS:/tmp$
OHOS:/tmp$ touch testfile1 testfile2 testfile3
OHOS:/tmp$ ll
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile1*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile2*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile3*
OHOS:/tmp$
```