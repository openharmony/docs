# statfs


## Command Function

This command is used to print information about a file system, such as the type, total size, and available size.


## Syntax

statfs [_directory_]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| directory | Specifies the file system directory.| The file system must exist and support the **statfs** command. The supported file systems include JFFS2, FAT, and NFS.|


## Usage Guidelines

The printed information varies depending on the file system.


## Example

The following uses the NFS as an example:

Run **statfs /nfs**.

**statfs** command output

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
