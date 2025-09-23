# 向应用沙箱推送文件

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangfenging -->
<!--Designer: @liveery; @zl_startup-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @foryourself-->


开发者在应用开发调试时，可能需要向应用沙箱下推送一些文件以期望在应用内访问或测试，此时有两种方式：

1. 可以通过DevEco Studio向应用安装路径中放入目标文件，详见[应用安装资源访问](../quick-start/resource-categories-and-access.md#资源访问)。

2. 在具备设备环境时，可以使用另一种更为灵活的方式，通过hdc工具来向设备中应用沙箱路径推送文件。即本文介绍的内容。

但是hdc shell看到的调试进程下的文件路径与应用视角的应用沙箱路径不同，开发者需要先了解[应用沙箱路径和真实物理路径的对应关系](./app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)。

## 开发示例

以应用包com.ohos.example为例，如果是在example的应用沙箱路径“/data/storage/el1/bundle”下读写文件，[应用沙箱路径和真实物理路径的对应关系](./app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)这个文档可知，对应的真实物理路径为“/data/app/el1/bundle/public/&lt;PACKAGENAME&gt;”，即“/data/app/el1/bundle/public/com.ohos.example”。

推送命令示例如下：

```
hdc file send ${待推送文件的本地路径} /data/app/el1/bundle/public/com.ohos.example/
```

推送文件完成后，需要将文件的user_id、group_id设置为应用的user_id。应用的user_id查询命令如下，其中所在进程行第一列为该应用进程user_id：

```
hdc shell ps -ef | grep com.ohos.example
```

使用应用进程的user_id设置文件的user_id和group_id，命令如下：
```
hdc shell chown ${user_id}:${user_id} ${文件路径}
```

## 切换应用沙箱视角

在调试过程中，如果权限不对或文件不存在，开发者需要从调试进程视角切换为应用视角，以便直观分析权限及文件目录问题。视角切换命令如下：

```
hdc shell                         // 进入shell
ps -ef|grep [hapName]             // 通过ps命令找到对应应用的pid
nsenter -t [hapPid] -m /bin/sh    // 通过上一步找到的应用pid进入对应应用的沙箱环境中
```

执行完成后，即切换到了应用视角，该视角下的目录路径为应用沙箱路径，可以去排查沙箱路径相关问题。
