# RunningLock锁错误码

## 4900101 连接服务失败

**错误信息**

Operation failed. Cannot connect to service.

**错误描述**

操作失败，连接系统服务发生异常。

**可能原因**

1. 系统服务停止运行。

2. 系统服务内部通讯发生异常。

**处理步骤**

检查系统服务是否正常运行。

1. 在控制台中输入如下命令，查看当前的系统服务列表。

    ```bash
    > hdc shell hidumper -ls
    ```

2. 查看系统服务列表中是否包含PowerManagerService系统服务。
