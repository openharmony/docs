# @ohos.userIAM.faceAuth (人脸认证)(系统接口)

提供人脸录入相关接口。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块为系统接口。

## 导入模块

```ts
import { faceAuth } from '@kit.UserAuthenticationKit';
```

## FaceAuthManager

人脸认证管理器对象。

### constructor

constructor()

表示获取人脸认证管理器对象。

**系统能力：** SystemCapability.UserIAM.UserAuth.FaceAuth

**系统接口：** 此接口为系统接口。

**返回值：**

| 类型                   | 说明                 |
| ---------------------- | -------------------- |
| [FaceAuthManager](#faceauthmanager) | 人脸认证管理器对象。 |

**示例：**

```ts
import { faceAuth } from '@kit.UserAuthenticationKit';

let faceAuthManager = new faceAuth.FaceAuthManager();
```

### setSurfaceId

setSurfaceId(surfaceId: string): void;

该接口仅用于在录入人脸时，设置人脸预览界面 [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9) 持有 Surface 的 ID，需要配合[人脸录入接口](../apis-basic-services-kit/js-apis-osAccount-sys.md#addcredential8)来使用。

**系统能力：** SystemCapability.UserIAM.UserAuth.FaceAuth

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名         | 类型                               | 必填 | 说明                       |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| surfaceId       | string     | 是   | [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9) 持有 Surface 的 ID。 |

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 12700001 | The service is unavailable. |

**示例：**

```ts
import { faceAuth } from '@kit.UserAuthenticationKit';

// 该surfaceId应该从XComponent控件获取，此处仅用作示例。
let surfaceId = '123456';
let manager = new faceAuth.FaceAuthManager();
try {
  manager.setSurfaceId(surfaceId);
  console.info('set surface id success');
} catch (error) {
  console.error('set surface id failed, error = ' + error);
}
```
