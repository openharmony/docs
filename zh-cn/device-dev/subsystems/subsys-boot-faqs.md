# 常见问题


## 系统启动过程中打印“parse failed!”错误后停止启动

**现象描述**

系统启动过程中，打印“[Init] InitReadCfg, parse failed! please check file /etc/init.cfg format.”错误，启动过程停止，如下图所示：

  **图1** 运行报错图

  ![zh-cn_image_0000001200053087](figures/zh-cn_image_0000001200053087.png)

**可能原因**

修改init.cfg文件时，漏掉或多加了逗号或括号等，导致init.cfg文件的json格式被破坏。

**解决办法**

仔细检查init.cfg文件，确保其格式符合json格式要求。


## 系统启动过程未结束就自动重启，如此反复持续

**现象描述**

镜像烧写完成后系统启动，启动过程未完成即自动重新启动，如此反复持续。

**可能原因**

被init启动的服务都有一个叫做“importance”的属性（详见[第2章表3](../subsystems/subsys-boot-init-jobs.md)描述）。

- 当该属性为0时，表示若当前服务进程退出，init不需要重启单板。

- 当该属性为1时，表示若当前服务进程退出，init需要重启单板。

因此出现上述现象的可能原因：有“importance”属性为1的服务在每次启动的过程中都会退出（可能是进程崩溃或出错自动退出），导致init进程自动重启单板。

**解决办法**

1. 通过日志确认崩溃或报错退出的服务，并解决其崩溃/报错的问题，然后重新烧写镜像即可。

2. 也可以将崩溃或报错退出的服务的“importance”属性改为0，然后重新烧写镜像，这样即使其退出，init也不会重启单板。


## 参数正确的情况下调用SetParameter/GetParameter返回失败

**现象描述**

在各参数正确的情况下调用SetParameter/GetParameter返回失败。

**可能原因**

程序对SetParameter/GetParameter这两个接口做了权限校验，在各参数正确的情况下调用SetParameter/GetParameter返回操作失败，很有可能是调用者的uid大于1000，没有调用权限。

**解决办法**

无需处理
