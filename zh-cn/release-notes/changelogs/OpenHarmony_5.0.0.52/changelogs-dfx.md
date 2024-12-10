# DFX子系统Changelog

## cl.dfx.1 hdc命令file recv命令不支持操作媒体库目录

**访问级别**

公开接口

**变更原因**

由于业务演进方向不同，媒体和文档目录需要不同的权限策略，变更后禁止通过hdc命令file recv命令将媒体库目录内文件从远端设备接收至本地。

**变更影响**

该变更为不兼容变更。

变更前：hdc命令中file recv（接收）命令可以操作媒体库目录内文件从远端设备接收至本地。

变更后：hdc命令中file recv（接收）命令无法操作媒体库目录内文件从远端设备接收至本地。

**起始API Level**

不涉及

**变更发生版本**

从OpenHarmony 5.0.0.52 版本开始。

**变更的接口/组件**

hdc命令行工具

**适配指导**

媒体库目录包含</br>
/storage/cloud/\<USERID\>/files/Photo</br>
/storage/media/\<USERID\>/local/files/Photo</br>

通过mediatool recv命令将指定uri对应的媒体库资源的源文件内容导出到定的设备路径下，具体操作说明可阅读[mediatool参考文档](../../../application-dev/tools/mediatool.md#mediatool-recv)。

```shell
> mediatool recv file://media/Photo/3 /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg
```

通过hdc file recv命令将媒体文件从远端设备接收文件至本地。

```bash
> hdc file recv /data/local/tmp/out.jpg ./out.jpg
```
