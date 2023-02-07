# rmdir


## 命令功能

rmdir命令用来删除一个目录。


## 命令格式

rmdir [_-p_] [_dirname..._]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| --help | 查看rmdir命令支持的参数列表。 | N/A | 
| -p | 删除路径。 | N/A | 
| --ignore-fail-on-non-empty | 忽略删除非空目录导致的故障。 | N/A | 
| dir | 需要删除目录的名称，删除目录必须为空，支持输入路径。 | N/A | 


## 使用指南

- rmdir命令只能用来删除目录。

- rmdir一次只能删除一个目录。

- rmdir只能删除空目录。


## 使用实例

举例：输入rmdir dir


## 输出说明

**示例** 删除一个名为 dir 的目录


```
OHOS:/test$ mkdir dir
OHOS:/test$ ls
dir
OHOS:/test$ rmdir dir/
OHOS:/test$ ls
```
