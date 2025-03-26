# @ohos.identifier.oaid (广告标识服务)(系统接口)

本模块提供开放匿名设备标识符（Open Anonymous Device Identifier, OAID，以下简称OAID）的获取和重置能力。

> **说明：**<br/>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。<br/>
> 使用获取开放匿名设备标识符接口，需[向用户申请授权](../../security/AccessToken/request-user-authorization.md)：ohos.permission.APP_TRACKING_CONSENT。<br/>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.identifier.oaid (广告标识服务)](js-apis-oaid.md)。

## 导入模块

```ts
import { identifier } from '@kit.AdsKit';
```

## identifier.resetOAID

resetOAID(): void

重置开放匿名设备标识符（Open Anonymous Device Identifier, OAID）。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Advertising.OAID

**错误码：**

以下错误码的详细介绍请参见[广告标识服务错误码参考](errorcode-oaid.md)。

| 错误码ID    | 错误信息                                                                         | 
|----------|------------------------------------------------------------------------------|
| 202      | Permission verification failed. A non-system application calls a system API. |
| 17300001 | System internal error.                                                       |
| 17300002 | Not in the trust list.                                                       | 

**示例：**

```ts
import { identifier } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  identifier.resetOAID();
} catch (err) {
  hilog.error(0x0000, 'testTag', `Fail to reset OAID. Code is ${err.code}, message is ${err.message}`);
}
```