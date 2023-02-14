# chmod


## 命令功能

chmod用于修改文件操作权限。


## 命令格式

chmod [_mode_] [_filename_]


## 参数说明

**表1** 参数说明

| 参数     | 参数说明                                                     | 取值范围       |
| -------- | ------------------------------------------------------------ | -------------- |
| mode     | 文件或文件夹权限，用8进制表示对应User、Group、及Others（拥有者、群组、其他组）的权限。 | [0, 777]        |
| filename | 文件路径。                                                   | 已存在的文件。 |


## 使用指南

- 在需要修改的文件名前加上文件权限值就可以修改该文件的权限值。

- fatfs文件系统所有创建的文件和挂载节点的权限属性保持一致，目前节点的权限只有用户读写权限，group和others权限不生效；且只允许修改用户读写权限，读写权限只有rw和ro两种。其他文件系统无限制。

## 特殊说明

shell端暂不支持。

## 使用实例

举例：修改hello-openharmony.txt 文件权限为644和777。


## 输出说明

**示例** 修改/dev目录下 hello-openharmony.txt 文件的权限

```
OHOS:/dev$ chmod 644 hello-openharmony.txt
OHOS:/dev$ ll hello-openharmony.txt
-rw-r--r-- 0 0 0 0 1970-01-01 00:00 hello-openharmony.txt
OHOS:/dev$ chmod 777 hello-openharmony.txt
OHOS:/dev$ ll hello-openharmony.txt
-rwxrwxrwx 0 0 0 0 1970-01-01 00:00 hello-openharmony.txt
```