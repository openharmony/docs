# 向应用沙箱推送文件

开发者在应用开发调试时，可能需要向应用沙箱下推送一些文件以期望在应用内访问或测试，此时有两种方式：

1. 可以通过DevEco Studio向应用安装路径中放入目标文件，详见[应用安装资源访问](../quick-start/resource-categories-and-access.md#资源访问)。

2. 在具备设备环境时，可以使用另一种更为灵活的方式，通过hdc工具来向设备中应用沙箱路径推送文件。即本文介绍的内容。

但是hdc shell看到的调试进程下的文件路径与应用视角的应用沙箱路径不同，开发者需要先了解如下路径映射关系。

## 应用沙箱路径和调试进程视角下的真实物理路径

在应用沙箱路径下读写文件，经过映射转换，实际读写的是在hdc进程视角下看到真实物理路径中的应用文件，其对应关系如下表所示。

**表1** 应用沙箱路径与真实物理路径对应关系

| 应用沙箱路径 | 调试进程（hdc）视角下的实际路径 | 说明 |
| -------- | -------- | -------- |
| /data/storage/el1/bundle | /data/app/el1/bundle/public/&lt;PACKAGENAME&gt; | 应用安装包目录 |
| /data/storage/el1/base | /data/app/el1/&lt;USERID&gt;/base/&lt;PACKAGENAME&gt; | 应用el1级别加密数据目录 |
| /data/storage/el2/base | /data/app/el2/&lt;USERID&gt;/base/&lt;PACKAGENAME&gt; | 应用el2级别加密数据目录 |
| /data/storage/el1/database | /data/app/el1/&lt;USERID&gt;/database/&lt;PACKAGENAME&gt; | 应用el1级别加密数据库目录 |
| /data/storage/el2/database | /data/app/el2/&lt;USERID&gt;/database/&lt;PACKAGENAME&gt; | 应用el2级别加密数据库目录 |
| /data/storage/el2/distributedfiles | /mnt/hmdfs/&lt;USERID&gt;/account/merge_view/data/&lt;PACKAGENAME&gt; | 应用el2加密级别有帐号分布式数据融合目录 |

## 开发示例

以应用包com.ohos.example为例，如果是在example的应用沙箱路径“/data/storage/el1/bundle”下读写文件，从上表可知，对应的真实物理路径为“/data/app/el1/bundle/public/&lt;PACKAGENAME&gt;”，即“/data/app/el1/bundle/public/com.ohos.example”。

推送命令示例如下：

```
hdc file send ${待推送文件的本地路径} /data/app/el1/bundle/public/com.ohos.example/
```

## 切换应用沙箱视角

在调试过程中，如果权限不对或文件不存在，开发者需要从调试进程视角切换为应用视角，以便直观分析权限及文件目录问题。视角切换命令如下：

```
hdc shell                         // 进入shell
ps -ef|grep [hapName]             // 通过ps命令找到对应应用的pid
nsenter -t [hapPid] -m /bin/sh    // 通过上一步找到的应用pid进入对应应用的沙箱环境中
```

执行完成后，即切换到了应用视角，该视角下的目录路径为应用沙箱路径，可以去排查沙箱路径相关问题。
