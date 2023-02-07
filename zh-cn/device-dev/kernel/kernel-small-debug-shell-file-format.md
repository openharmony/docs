# format


## 命令功能

format指令用于格式化磁盘。


## 命令格式

format &lt;_dev_inodename_&gt; &lt;_sectors_&gt; &lt;_option_&gt; [_label_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 
| -------- | -------- |
| dev_inodename | 设备名。 | 
| sectors | 分配的单元内存或扇区大小，如果输入0表示参数为空。（取值必须为0或2的幂，fat32下最大值为128，取值0表示自动选择合适的簇大小，不同size的分区，可用的簇大小范围不同，错误的簇大小指定可能导致格式化失败）。 | 
| option | &nbsp;&nbsp;格式化选项，用来选择文件系统的类型，有如下几种参数选择：<br/>-&nbsp;0x01：FMT_FAT<br/>-&nbsp;0x02：FMT_FAT32<br/>-&nbsp;0x07：FMT_ANY<br/>-&nbsp;0x08：FMT_ERASE&nbsp;（USB不支持该选项）<br/>传入其他值皆为非法值，将由系统自动选择格式化方式。若格式化U盘时低格位为&nbsp;1，会出现错误打印。 | 
| label | 该参数为可选参数，输入值应为字符串，用来指定卷标名。当输入字符串"null"时，则把之前设置的卷标名清空。 | 


## 使用指南

- format指令用于格式化磁盘，设备名可以在dev目录下查找。format时必须安装存储卡。

- format只能格式化U盘、sd和mmc卡，对Nand flash和Nor flash格式化不起作用。

- sectors参数必须传入合法值，传入非法参数可能引发异常。


## 使用实例

举例：输入format /dev/mmcblk0 128 2


## 输出说明

**示例** 格式化mmc卡

```
OHOS # format /dev/mmcblk1 128 2
Format to FAT32, 128 sectors per cluster.
format /dev/mmcblk1 Success 
```
