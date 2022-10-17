# 系统电源管理错误码

## 201 权限校验失败

### 错误信息

Permission denied. The operation is forbidden by permission: `{$permission}`.

### 错误描述

权限校验失败，接口调用要求`{$permission}`权限。

### 可能原因

调用者未申请`{$permission}`权限。

### 处理步骤

申请`{$permission}`权限，具体申请方式请参考[访问控制授权申请指导](../../security/accesstoken-guidelines.md)。

## 401 参数检查失败

### 错误信息

Parameter error. The incoming parameter `{$parameter}` is invalid.

### 错误描述

参数检查失败，调用者传入的参数`{$parameter}`无效。

### 可能原因

1. 调用者传入的参数`{$parameter}`类型无效。

2. 调用者传入的参数`{$parameter}`值无效。

### 处理步骤

1. 检查传入的参数`{$parameter}`类型是否正确。

2. 检查传入的参数`{$parameter}`值是否正确。

## 4900101 连接服务失败

### 错误信息

Operation failed. Cannot connect to service.

### 错误描述

操作失败，连接系统服务发生异常。

### 可能原因

1. 系统服务停止运行。

2. 系统服务内部通讯发生异常。

### 处理步骤

检查系统服务是否正常运行。

1. 在控制台中输入如下命令，查看当前的系统服务列表。

```bash
> hdc shell hidumper -ls
```

2. 查看系统服务列表中是否包含xx系统服务。

PowerManagerService              BatteryService
ThermalService                   BatteryStatisticsService         DisplayPowerManagerService

## 4900102 正在关机中

### 错误信息

Operation failed. System is shutting down.

### 错误描述

操作失败，系统正在关机。

### 可能原因

系统正在处于关机过程中。

### 处理步骤

在系统正常运行的状态下进行操作。