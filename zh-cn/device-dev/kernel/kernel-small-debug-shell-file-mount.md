# mount


## 命令功能

mount命令用来将设备挂载到指定目录。


## 命令格式

mount [_-f_] [_-t TYPE_] [_-o OPTION,_] [[_DEVICE_] _DIR_]


## 参数说明

**表1** 参数说明

| 参数   | 参数说明                                                    | 取值范围                                                     |
| ------ | ----------------------------------------------------------- | ------------------------------------------------------------ |
| --help | 查看mount命令支持的参数列表。                               | N/A                                                          |
| -f     | 佯装挂载动作（实际不做挂载）。                              | N/A                                                          |
| -t     | 文件系统的种类。                                            | TYPE：vfat,&nbsp;yaffs,&nbsp;jffs,&nbsp;ramfs,&nbsp;nfs，procfs,&nbsp;romfs. |
| -o     | 挂载选项。                                                  | N/A                                                          |
| DEVICE | 要挂载的设备（格式为设备所在路径）。                        | 系统拥有的设备。                                             |
| DIR    | 指定目录。<br/>用户必须具有指定目录中的执行（搜索）许可权。 | N/A                                                          |


## 使用指南

mount后加需要挂载的设备信息、指定目录以及设备文件格式，就能成功挂载文件系统到指定目录。

## 特殊说明

shell端暂不支持。切换mksh版本可全支持，方法：cd bin; ./mksh。

## 使用实例

举例：mount -t nfs 192.168.1.3:/nfs nfs


## 输出说明

**示例** 将服务器端nfs目录192.168.1.3:/nfs挂载到当前系统下新建的/nfs目录：


```
OHOS:/$ mkdir nfs
OHOS:/$ mount -t nfs 192.168.1.3:/nfs nfs
Mount nfs on 192.168.1.3:/nfs, uid:0, gid:0
Mount nfs finished.
OHOS:/$ ls nfs/
16d.xml         gpio_test             ohos_test.txt    userfs_vfat.img
OHOS_Image.bin  hello                 rootfs_vfat.img
dev_tools       mksh_rootfs_vfat.img  test_demo
```