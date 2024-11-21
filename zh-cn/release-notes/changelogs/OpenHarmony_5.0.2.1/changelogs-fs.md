# 文件子系统变更说明

## cl.CoreFileKit.stat, lstat, fstat返回值变更。

**访问级别**

公开接口

**变更原因**

/proc目录下节点的st_blksize返回值当前为4096，可能存在兼容性问题，应当修改为1024。

**变更影响**

该变更为不兼容变更。

变更前：通过stat获取/proc下的节点的st_blocksize为4096。

变更后：通过stat获取/proc下的节点的st_blocksize为1024。

**起始 API Level**

14

**变更发生版本**

从OpenHarmony SDK 5.0.2 Beta1开始。

**变更的接口/组件**

<从变更前和变更后两个维度来描述涉及的接口/组件>

| 接口声明                                                     | 变更前                                 | 变更后                                 |
| ------------------------------------------------------------ | -------------------------------------- | -------------------------------------- |
| `int fstat(int, struct stat *)`                              | fstat(/proc下节点)返回st_blksize为4096 | fstat(/proc下节点)返回st_blksize为1024 |
| `int lstat(const char *__restrict, struct stat *__restrict)` | lstat(/proc下节点)返回st_blksize为4096 | lstat(/proc下节点)返回st_blksize为1024 |
| `int stat(const char *__restrict, struct stat *__restrict)`  | stat(/proc下节点)返回st_blksize为4096  | stat(/proc下节点)返回st_blksize为1024  |

**适配指导**

排查应用实现中是否存在依赖interface/sdk_c/third_party/musl/ndk_musl_include/sys/stat.h中的fstat、lstat、stat接口获取proc下节点的blocksize的场景。若涉及，需要适配该值为1024并处理。