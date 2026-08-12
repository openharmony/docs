# 升级错误码
<!--Kit: Basic Services Kit-->
<!--Subsystem: Update-->
<!--Owner: @RainyDay_005; @huangsiping3-->
<!--Designer: @zhangzhengxue; @jackd320-->
<!--Tester: @mamba-ting-->
<!--Adviser: @fang-jinxu-->

> **说明：**
>
> 本模块定义了升级服务（Update Service）可能返回的错误码及其处理建议，
> 主要涵盖调用升级服务接口时出现的 IPC 通信错误等，帮助开发者快速定位和解决系统升级失败、固件更新异常、应用版本管理错误等升级问题。
>
> 适用场景：系统升级、固件更新、应用版本管理等，帮助开发者集成升级能力、监控升级状态、处理升级错误，提升系统的可维护性和用户体验。
>
> 本文仅介绍升级模块相关的错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 错误码列表

| 错误码 ID | 错误信息 | 说明 | 可能原因 | 处理建议 |
| --- | --- | --- | --- | --- |
| 11500104 | IPC error | 在系统升级、固件更新等场景下调用升级服务接口时出现的 IPC 通信错误。 | 1. 升级服务启动失败或异常退出。<br>2. 服务进程异常崩溃且重新拉起失败。 | 1. 执行 `hidumper -s 3006` 确认升级服务是否在运行。<br>2. 若未启动，重启设备或通过 **设置 > 系统和更新 > 软件更新** 拉起服务。<br>3. 检查 hilog 日志，搜索 `SA:3006` 关键字，分析服务运行状态。<br>4. 若服务正常运行，搜索 `C02E00` 关键字，分析 IPC 通信错误的具体原因。<br>5. 根据分析结果，释放系统资源、检查权限配置、重启相关服务或升级服务进程。 |

## 相关接口

调用以下接口时，若升级服务未启动或异常退出，可能返回错误码11500104（IPC error）：

- `checkNewVersion`
- `getNewVersionInfo`
- `getNewVersionDescription`
- `getCurrentVersionInfo`
- `getCurrentVersionDescription`
- `getTaskInfo`
- `download`
- `pauseDownload`
- `resumeDownload`
- `upgrade`
- `clearError`
- `getUpgradePolicy`
- `setUpgradePolicy`
- `terminateUpgrade`
- `factoryReset`
- `forceFactoryReset`
- `deepFactoryReset`
- `getDeepFactoryResetInfo`
- `verifyUpgradePackage`
- `applyNewVersion`

详细信息可参考[@ohos.update (升级)(系统接口)](../apis-basic-services-kit/js-apis-update-sys.md)。