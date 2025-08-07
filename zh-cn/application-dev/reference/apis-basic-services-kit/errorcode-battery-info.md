# 电量信息错误码

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--SE: @wangyantian0-->
<!--TSE: @alien0208-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 5100101 连接服务失败

**错误信息**

Failed to connect to the service.

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

2. 查看系统服务列表中是否包含BatteryService系统服务。
