# chown


## 命令功能

chown用于修改指定文件的拥有者。


## 命令格式

chown [_owner_] [_pathname_]


## 参数说明

**表1** 参数说明

| 参数     | 参数说明     | 取值范围       |
| -------- | ------------ | -------------- |
| owner    | 文件拥有者。 | [0, 0xFFFFFFFF] |
| pathname | 文件路径。   | 已存在的文件。 |


## 使用指南

修改文件的所有者，目前fatfs不支持修改。

## 特殊说明

shell端暂不支持。

## 使用实例

举例：chown 100 testfile


## 输出说明

**示例1** 修改 /dev下的testfile 文件的uid为100

```
OHOS:/dev$ touch testfile
OHOS:/dev$ ll testfile
-rw-r--r-- 0 0 100 0 1970-01-01 00:00 testfile
OHOS:/dev$ chown 100 testfile
OHOS:/dev$ ll testfile
-rw-r--r-- 0 100 100 0 1970-01-01 00:00 testfile
```