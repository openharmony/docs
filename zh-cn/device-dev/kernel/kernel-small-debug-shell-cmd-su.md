# su


## 命令功能

su用于变更为其他使用者的身份。


## 命令格式

su [_uid_] [_gid_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| uid | 目标用户的用户id值。 | -&nbsp;为空。<br/>-&nbsp;[0, 60000] | 
| gid | 目标用户的群组id值。 | -&nbsp;为空。<br/>-&nbsp;[0, 60000] | 


## 使用指南

- su命令缺省切换到root用户，uid默认为0，gid为0。

- 在su命令后的输入参数uid和gid就可以切换到该uid和gid的用户。

- 输入参数超出范围时，会打印提醒输入正确范围参数。


## 使用实例

举例：su 1000 1000


## 输出说明

**示例** 切换到为uid为1000，gid为1000的用户

```
OHOS # ls
Directory /data/system/param:
-rw-r--r-- 0 u:0 g:0 hello_1.txt
OHOS # su 1000 1000
OHOS # touch hello 2.txt
OHOS # ls
Directory /data/system/param:
-rw-r--r-- O u:1000 g:1000 hello 2.txt
-гw-r--r-- 0 u:0 g:0 hello_1.txt
```
