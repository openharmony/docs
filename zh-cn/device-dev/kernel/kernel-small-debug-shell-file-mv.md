# mv


## 命令功能

移动文件。


## 命令格式

mv [_-fivn_] _SOURCE... DEST_


## 参数说明

**表1** 参数说明

| 参数   | 参数说明                                                     | 取值范围                                        |
| ------ | ------------------------------------------------------------ | ----------------------------------------------- |
| -help  | 使用帮助。                                                   | N/A                                             |
| -f     | 通过删除目标文件强制复制。                                   | N/A                                             |
| -i     | 若指定移动的源目录或文件与目标中目录或文件同名，则会先询问是否覆盖旧文件，输入&nbsp;y&nbsp;直接覆盖，输入&nbsp;n&nbsp;取消该操作。 | N/A                                             |
| -n     | 不要覆盖任何已存在的文件或目录。                             | N/A                                             |
| -v     | 目前本参数toybox官方最新代码虽然支持，但同样也不生效。       | N/A                                             |
| SOURCE | 源文件路径。                                                 | 目前只支持文件,不支持目录；支持多文件同时移动。 |
| DEST   | 目的文件路径。                                               | 支持目录以及文件。                              |


## 使用指南

- 源文件路径支持“\*”和“?”通配符，“\*”代表任意多个字符，“?”代表任意单个字符。目的路径不支持通配符。当源路径可匹配多个文件时，目的路径必须为目录。

- 目的路径为目录时，该目录必须存在。此时目的文件以源文件命名。

- 目的路径为文件时，所在目录必须存在。

- 目的文件已存在则会覆盖。

## 特殊说明

shell端暂不支持。切换mksh版本可全支持，方法：cd bin; ./mksh。

## 使用实例

举例：

- mv -i test.txt testpath/

- mv test?.txt testpath/ （移动 test3.txt testA.txt test_.txt）


## 输出说明

**示例1** 显示结果如下


```
OHOS:/$ touch test.txt
OHOS:/$ mkdir testpath
OHOS:/$ touch testpath/test.txt
OHOS:/$ mv -i test.txt testpath/
mv: overwrite 'testpath//test.txt' (Y/n):y
OHOS:/$ ls
bin  etc  proc    storage  testpath  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ cp testpath/test.txt ./
OHOS:/$ ls
bin  etc  proc    storage  test.txt  userdata  vendor
dev  lib  sdcard  system   testpath  usr
OHOS:/$ mv -i test.txt testpath/
mv: overwrite 'testpath//test.txt' (Y/n):n
OHOS:/$ ls
bin  etc  proc    storage  test.txt  userdata  vendor
dev  lib  sdcard  system   testpath  usr
```

**示例2** 通配符使用


```
OHOS:/$ ls
bin  etc  proc    storage  test.txt   testA.txt  testpath  usr
dev  lib  sdcard  system   test3.txt  test_.txt  userdata  vendor
OHOS:/$ mv test?.txt testpath/
OHOS:/$ ls
bin  etc  proc    storage  test.txt  userdata  vendor
dev  lib  sdcard  system   testpath  usr
OHOS:/$ ls testpath/
test.txt  test3.txt  testA.txt  test_.txt
```