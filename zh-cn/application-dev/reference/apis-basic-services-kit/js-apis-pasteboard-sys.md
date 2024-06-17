# @ohos.pasteboard (剪贴板)(系统接口)

本模块主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。系统剪贴板支持对文本、HTML、URI、Want、PixelMap等内容的操作。

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.pasteboard(剪贴板)](js-apis-pasteboard.md)。

## 导入模块

```ts
import pasteboard from '@ohos.pasteboard';
```

### setAppShareOptions<sup>12+</sup>

setShareOptions(shareOptions: ShareOption): void

设置应用全局的可粘贴的范围。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| shareOptions | [ShareOption](js-apis-pasteboard.md#shareoption9) | 是 | 可粘贴的范围。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 12900006 | Settings already exist. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.setAppShareOptions(pasteboard.ShareOption.INAPP);
  console.info('Set app share options success.');
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error(`Set app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```

### removeAppShareOptions<sup>12+</sup>

removeShareOptions(): void

删除应用全局的可粘贴的范围。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.removeAppShareOptions();
  console.info('Remove app share options success.');
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error(`Remove app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```
