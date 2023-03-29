# statfs


## 命令功能

statfs命令用来打印文件系统的信息，如该文件系统类型、总大小、可用大小等信息。


## 命令格式

statfs [_directory_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| directory | 文件系统的路径。 | 必须是存在的文件系统，并且其支持statfs命令，当前支持的文件系统有：JFFS2，FAT，NFS。 | 


## 使用指南

打印信息因文件系统而异。


## 使用实例

以nfs文件系统为例：

statfs /nfs

**示例** statfs输出说明

```
OHOS # statfs ./nfs
statfs got:
 f_type     = 26985
 cluster_size   = 512
 total_clusters = 1579575176
 free_clusters  = 499254808
 avail_clusters = 499254808
 f_namelen    = 255
./nfs
 total size: 808742490112 Bytes
 free  size: 255618461696 Bytes
```
