# 数据共享错误码

## 15700010 创建DataShareHelper异常

### 错误信息

The dataShareHelper is not initialized successfully.

### 错误描述

创建DataShareHelper工具类异常时，系统会产生此错误码。

### 可能原因

1. AMS初始化失败，远程服务端未连接。
2. uri路径不正确。
3. context上下文环境不正确。

### 处理步骤

1. 咨询dataShare服务端提供者，并获取正确的uri路径。
2. 检查context，查看token是否正确。