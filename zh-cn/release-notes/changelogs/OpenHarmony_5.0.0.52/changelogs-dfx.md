# DFX子系统Changelog

## cl.dfx.1 hdc file recv命令不支持操作媒体库目录

**访问级别**

公开接口

**变更原因**

由于业务演进方向不同，媒体和文档目录需要不同的权限策略，变更后禁止通过hdc file recv命令直接将媒体库目录内文件从远端设备接收至本地。

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

通过如下两步操作可以将媒体库文件接收到本地：
1. 通过mediatool recv命令将指定uri对应的媒体库资源的源文件内容导出到设备临时路径下（/data/local/tmp），具体操作说明可阅读[mediatool参考文档](../../../application-dev/tools/mediatool.md#mediatool-recv)。

```shell
> mediatool recv file://media/Photo/3 /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg
```

2. 通过hdc file recv命令将媒体文件从远端设备接收至本地。

```bash
> hdc file recv /data/local/tmp/out.jpg ./out.jpg
```
## cl.dfx.2 hdc命令file recv命令及shell读取权限收紧

**访问级别**

公开接口

**变更原因**

为了更好的保护终端用户的隐私安全，加强hdc/shell对系统目录文件的权限管控。

**变更影响**

该变更为不兼容变更。

变更前：支持通过hdc/shell对系统目录文件访问，如调试应用数据沙箱等。

变更后：用户所在用户组必须具备访问调试应用沙箱目录的权限，方能通过hdc/shell访问该目录。

**起始API Level**

不涉及

**变更发生版本**

从OpenHarmony 5.0.0.52 版本开始。

**变更的接口/组件**

hdc命令行工具

**适配指导**

通过hdc访问调试签名的应用的数据沙箱目录文件，需要在目录、文件创建时指定用户组读取权限。

路径如：</br>
/data/app/el1/\<USERID\>/base/\<BUNDLENAME\></br>
/data/app/el1/\<USERID\>/database/\<BUNDLENAME\></br>
/data/app/el2/\<USERID\>/base/\<BUNDLENAME\></br>
/data/app/el2/\<USERID\>/database/\<BUNDLENAME\></br>