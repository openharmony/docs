# 元能力子系统ChangeLog

## cl.ability.1 应用开机启动管理接口新增权限校验

此前版本注册监听应用组件开机自启动状态变化、注销监听应用组件开机自启动状态变化、设置应用组件开机自启动、取消应用组件开机自启动及查询自启动应用组件信息接口对调用方只进行系统应用校验，未进行权限校验，存在安全风险，不符合OpenHarmony的API接口规范。
现做出如下变更：
  - 使用on方法前需提前申请"ohos.permission.MANAGE_APP_BOOT"权限。
  - 使用off方法前需提前申请"ohos.permission.MANAGE_APP_BOOT"权限。
  - 使用setApplicationAutoStartup方法(callback方式)前需提前申请"ohos.permission.MANAGE_APP_BOOT"权限。
  - 使用setApplicationAutoStartup方法(promise方式)前需提前申请"ohos.permission.MANAGE_APP_BOOT"权限。
  - 使用cancelApplicationAutoStartup方法(callback方式)前需提前申请"ohos.permission.MANAGE_APP_BOOT"权限。
  - 使用cancelApplicationAutoStartup方法(promise方式)前需提前申请"ohos.permission.MANAGE_APP_BOOT"权限。
  - 使用queryAllAutoStartupApplications方法(callback方式)前需提前申请"ohos.permission.MANAGE_APP_BOOT"权限。
  - 使用queryAllAutoStartupApplications方法(promise方式)前需提前申请"ohos.permission.MANAGE_APP_BOOT"权限。

**关键的接口/组件变更**

涉及接口

  - autoStartupManager.on(type: 'systemAutoStartup', callback: AutoStartupCallback);
  - autoStartupManager.off(type: 'systemAutoStartup', callback: AutoStartupCallback);
  - autoStartupManager.setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>);
  - autoStartupManager.setApplicationAutoStartup(info: AutoStartupInfo);
  - autoStartupManager.cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>);
  - autoStartupManager.cancelApplicationAutoStartup(info: AutoStartupInfo);
  - autoStartupManager.queryAllAutoStartupApplications(info: AutoStartupInfo, callback: AsyncCallback<void>);
  - autoStartupManager.queryAllAutoStartupApplications(info: AutoStartupInfo);

变更前：
  - 系统应用无需任何权限限制可正常调用。

变更后：
  - 系统应用需要申请相应权限才可正常调用，若权限申请错误或未申请相应权限，将返回201表示权限校验失败。

**适配指导**

调用on、off、setApplicationAutoStartup方法(callback方式)、setApplicationAutoStartup方法(promise方式)、cancelApplicationAutoStartup方法(callback方式)、cancelApplicationAutoStartup方法(promise方式)、queryAllAutoStartupApplications方法(callback方式)、queryAllAutoStartupApplications方法(promise方式)接口时，需申请相应的权限才可正常使用。
