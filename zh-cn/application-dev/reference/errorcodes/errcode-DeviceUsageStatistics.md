# DeviceUsageStatistics错误码

## 201 权限校验失败

### 错误信息
Permission denied.

### 可能原因
该错误码表示权限校验失败，可能原因是未配置对应权限或者是不能修改自身应用信息。

### 处理步骤
配置权限ohos.permission.BUNDLE_ACTIVE_INFO。

## 401 参数检查错误

### 错误信息
The parameter check failed.

### 可能原因
该错误码表示入参检查错误，可能原因调用接口的时候输入参数有误（类型或者数值）。

### 处理步骤
调用接口时先检查入参类型和数值是否为合法。

## 10000001 内存操作失败

### 错误信息
Memory operation failed.

### 可能原因
该错误码表示系统服务工作异常，可能原因如下。
内存不足导致创建对象失败。

### 处理步骤
请检查内存是否泄漏。

## 10000002 IPC parcel write failed

### 错误信息
Parcel operation failed. Failed to write the parcel.

### 可能原因
写入对象失败。

### 处理步骤
请检查对象值是否正常。

## 10000003 系统服务操作失败

### 错误信息
System service operation failed.

### 可能原因
依赖的服务进程出现问题。

### 处理步骤
系统服务内部工作异常，请稍后重试，或者重启设备尝试。

## 10000004 IPC通信失败

### 错误信息
IPC communication failed.

### 可能原因
系统服务异常或者IPC通信数据异常。

### 处理步骤
系统服务内部工作异常，请稍后重试，或者重启设备尝试。

## 10000005 应用未安装

### 错误信息
The application is not installed.

### 可能原因
应用未安装或者已经卸载

### 处理步骤
操作应用信息时请先检查应用是否已安装且并未卸载。

## 10000006 获取应用信息失败

### 错误信息
Get application info failed.

### 可能原因
1. beginTime或者endTime输入不合法。
2. 应用未安装或者已经被卸载了。
2. intervalType输入不合法。

### 处理步骤
请检查入参合法性以及应用是否安装且并未卸载。

## 10000007 时间操作失败

### 错误信息
Get system or actual time operation failed.

### 可能原因
系统异常。

### 处理步骤
系统服务内部工作异常，请稍后重试，或者重启设备尝试。

## 10100001 应用分组信息操作重复

### 错误信息
Application group operation failed. The application group are the the same and do not need te be updated.

### 可能原因
重复设置应用分组或者重复注册分组变化监听和重复取消分组变化监听。

### 处理步骤
请勿重复设置应用分组、注册监听和取消监听。

## 10100002 获取应用分组信息失败

### 错误信息
Get application group info failed. The application group infomation cannot be found.

### 可能原因
1、应用输入bundleName错误。
2、应用可能没有安装或者已经卸载

### 处理步骤
请检查入参bundleName的正确性。

