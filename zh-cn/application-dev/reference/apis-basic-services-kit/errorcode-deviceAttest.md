# 设备证明错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 20000001 系统服务异常

**错误信息**

System service exception, please try again or reboot your device.

**错误描述**

系统服务异常，请重试或重启设备。

**可能原因**

1. 系统服务停止运行。

2. 系统服务内部通讯发生异常。

**处理步骤**

检查系统服务是否正常运行。

1. 在控制台中输入如下命令，查看当前的系统服务列表。

    ```bash
    > hdc shell hidumper -ls
    ```

2. 查看系统服务列表中是否包含devattest_service系统服务。
