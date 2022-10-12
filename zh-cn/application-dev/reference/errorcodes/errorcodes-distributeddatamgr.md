# 分布式数据管理子系统错误码

## 201 权限校验失败

### 错误信息

Permission denied.

### 错误描述

调用接口时，若没有配置对应权限，会报此错误码。

### 可能原因

1.

2.

### 处理步骤

查看权限是否已适配，具体配置方式请参考[权限申请声明](../../security/accesstoken-guidelines.md)。

## 401 参数检查错误

### 错误信息

Parameter error.  The type of ${参数名}$ must be ${正确的类型}$[or ${其他正确输入}$].

### 错误描述

若传入参数的类型或个数不匹配，会报此错误码。

### 可能原因

1. 入参类型错误不匹配。
2. 入参个数不匹配。

### 处理步骤

检查入参类型和个数是否匹配。

## 15700010 创建DataShareHelper异常

### 错误信息

The dataShareHelper is not initialized successfully.

### 错误描述

创建DataShareHelper工具类错误。

### 可能原因

AMS初始化失败。

### 处理步骤

检查 uri context。