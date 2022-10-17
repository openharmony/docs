# 热管理错误码

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

## 4800101 连接服务失败

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

2. 查看系统服务列表中是否包含ThermalService系统服务。