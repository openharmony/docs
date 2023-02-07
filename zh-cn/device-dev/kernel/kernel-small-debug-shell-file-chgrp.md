# chgrp


## 命令功能

chgrp用于修改文件的群组。


## 命令格式

chgrp [_group_] [_pathname_]


## 参数说明

**表1** 参数说明

| 参数     | 参数说明   | 取值范围       |
| -------- | ---------- | -------------- |
| group    | 文件群组。 | [0, 0xFFFFFFFF] |
| pathname | 文件路径。 | 已存在的文件。 |


## 使用指南

- 在需要修改的文件名前加上文件群组值就可以修改该文件的所属组。
- fatfs文件系统不支持修改用户组id。

## 特殊说明

shell端暂不支持。

## 使用实例

举例：chgrp 100 testfile


## 输出说明

**示例** 修改 dev/目录下testfile 文件的群组为100

```
OHOS:/dev$ ll testfile
-rw-r--r-- 0 0 0 0 1970-01-01 00:00 testfile
OHOS:/dev$ chgrp 100 testfile                                           
OHOS:/dev$ ll testfile                                                   
-rw-r--r-- 0 0 100 0 1970-01-01 00:00 testfile
OHOS:/dev$
```