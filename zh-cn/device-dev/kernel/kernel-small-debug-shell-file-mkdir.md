# mkdir


## 命令功能

mkdir命令用来创建一个目录。


## 命令格式

mkdir [_-vp_] [_-m mode_] [_dirname..._]


## 参数说明

**表1** 参数说明

| 参数      | 参数说明                       |
| --------- | ------------------------------ |
| --help    | 查看mkdir命令支持的参数列表。    |
| -m        | 设置即将创建目录的权限。       |
| -p        | 递归逐级创建父子目录。         |
| -v        | 打印创建目录过程中的详细信息。 |
| directory | 需要创建的目录。               |


## 使用指南

> **须知：**
> fatfs文件系统所有创建的文件和其挂载节点的权限属性保持一致，目前节点的权限只有用户读写权限，group和others权限不生效，
>
> 且只有读写位可设置，有rw和ro两种，因此mkdir在附加-m参数时，创建的目录权限仅有777和555两种，可执行权限也不生效。

## 特殊说明

shell端暂不支持。切换mksh版本可全支持，方法：cd bin; ./mksh。

## 使用实例

举例：

- mkdir testpath

- mkdir -m 777 testpath

- mkdir -pv testpath01/testpath02/testpath03


## 输出说明


```
OHOS:/tmp$ mkdir testpath
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath/
```

**示例2** 创建指定mode的目录


```
OHOS:/tmp$ mkdir -m 777 testpath
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath/
```

**示例3** 逐级创建目录


```
OHOS:/tmp$ mkdir -pv testpath01/testpath02/testpath03
mkdir: created directory 'testpath01'
mkdir: created directory 'testpath01/testpath02'
mkdir: created directory 'testpath01/testpath02/testpath03'
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath01/
OHOS:/tmp$ ll testpath01/
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath02/
OHOS:/tmp$ ll testpath01/testpath02/
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath03/
```