# 元能力子系统变更说明

## cl.ability.1 autoStartupManager自启动管理接口权限变更
**访问级别**

系统接口

**变更原因**

此前版本注册监听应用组件开机自启动状态变化、注销监听应用组件开机自启动状态变化、设置应用组件开机自启动、取消应用组件开机自启动及查询自启动应用组件信息接口对调用方只进行系统应用校验，未进行权限校验，存在安全风险，不符合OpenHarmony的API接口规范。

**变更影响**

影响接口调用权限，接口调用权限发生变更。
应用需要配置相应的权限，才可以正常使用。

**API Level**

11

**变更发生版本**

从Openharmony SDK OpenHarmony_4.1.5.5 开始

**变更的接口**
| 接口声明 | 变更前 | 变更后 |
| ------- | ----- | ------ |
| on(type: 'systemAutoStartup', callback: AutoStartupCallback)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| off(type: 'systemAutoStartup', callback: AutoStartupCallback)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| setApplicationAutoStartup(info: AutoStartupInfo)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| cancelApplicationAutoStartup(info: AutoStartupInfo)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| queryAllAutoStartupApplications(info: AutoStartupInfo, callback: AsyncCallback<void>)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| queryAllAutoStartupApplications(info: AutoStartupInfo)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |

**适配指导**

调用on、off、setApplicationAutoStartup方法(callback方式)、setApplicationAutoStartup方法(promise方式)、cancelApplicationAutoStartup方法(callback方式)、cancelApplicationAutoStartup方法(promise方式)、queryAllAutoStartupApplications方法(callback方式)、queryAllAutoStartupApplications方法(promise方式)接口时，需申请相应的权限才可正常使用。
