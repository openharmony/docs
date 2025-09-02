# @ohos.uiAppearance (用户界面外观)(系统接口)

用户界面外观提供管理系统外观的一些基础能力，目前仅包括深浅色模式配置。

> **说明：**
>
> 从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.uiAppearance (用户界面外观)](js-apis-uiappearance.md)。


## 导入模块

```ts
import { uiAppearance } from '@kit.ArkUI';
```


## uiAppearance.setDarkMode

setDarkMode(mode: DarkMode, callback: AsyncCallback\<void>): void

设置系统深色模式。

**需要权限：** ohos.permission.UPDATE_CONFIGURATION

**系统能力：** SystemCapability.ArkUI.UiAppearance

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| mode | [DarkMode](js-apis-uiappearance.md#darkmode) | 是 | 指定系统的深色模式配置。 |
| callback | AsyncCallback\<void>| 是 | 配置深色模式的异步回调。 |

**错误码：**

错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[errcode-uiappearance](errorcode-uiappearance.md)。

| 错误码ID | 错误信息 |
| -- | -- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameters types. 3. Parameter verification failed. |
| 500001 | Internal error. |

**示例：** 

  ```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
try {
    uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK, (error) => {
      if (error) {
        console.error('Set dark-mode failed, ' + error.message);
      } else {
        console.info('Set dark-mode successfully.');
      }
    })
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Set dark-mode failed, ' + message);
}
  ```


## uiAppearance.setDarkMode

setDarkMode(mode: DarkMode): Promise\<void>;

设置系统深色模式。

**需要权限：** ohos.permission.UPDATE_CONFIGURATION

**系统能力：** SystemCapability.ArkUI.UiAppearance

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| mode | [DarkMode](js-apis-uiappearance.md#darkmode) | 是 | 指定系统深色模式配置。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。|

**错误码：**

错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[errcode-uiappearance](errorcode-uiappearance.md)。

| 错误码ID | 错误信息 |
| -- | -- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameters types. 3. Parameter verification failed. |
| 500001 | Internal error. |

**示例：** 

  ```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
try {
    uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK).then(() => {
      console.info('Set dark-mode successfully.');
    }).catch((error:Error) => {
      console.error('Set dark-mode failed, ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Set dark-mode failed, ' + message);
}
  ```


## uiAppearance.setFontScale<sup>12+<sup>

setFontScale(fontScale: number): Promise\<void>

设置系统字体大小。

**需要权限：** ohos.permission.UPDATE_CONFIGURATION

**系统能力：** SystemCapability.ArkUI.UiAppearance

**系统接口：** 此接口为系统接口。

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| fontScale | number | 是 | 需要设置的字体大小。 |

**返回值：** 

| 类型 | 说明 |
| -- | -- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。|

**错误码：**

错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[errcode-uiappearance](errorcode-uiappearance.md)。

| 错误码ID | 错误信息 |
| -- | -- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameters types. 3. Parameter verification failed. |
| 500001 | Internal error. |

**示例：** 

  ```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let fontScale = 10;

try {
    uiAppearance.setFontScale(fontScale).then(() => {
      console.info('Set fontScale successfully.');
    }).catch((error:Error) => {
      console.error('Set fontScale failed, ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Set fontScale failed, ' + message);
}
  ```


## uiAppearance.setFontWeightScale<sup>12+<sup>

setFontWeightScale(fontWeightScale: number): Promise\<void>

设置系统字体粗细。

**需要权限：** ohos.permission.UPDATE_CONFIGURATION

**系统能力：** SystemCapability.ArkUI.UiAppearance

**系统接口：** 此接口为系统接口。

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| fontWeightScale | number | 是 | 需要设置的字体粗细。 |

**返回值：** 

| 类型 | 说明 |
| -- | -- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。|

**错误码：**

错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[errcode-uiappearance](errorcode-uiappearance.md)。

| 错误码ID | 错误信息 |
| -- | -- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameters types. 3. Parameter verification failed.  |
| 500001 | Internal error. |

**示例：** 

  ```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let fontWeightScale = 1;

try {
    uiAppearance.setFontWeightScale(fontWeightScale).then(() => {
      console.info('Set fontWeightScale successfully.');
    }).catch((error:Error) => {
      console.error('Set fontWeightScale failed, ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Set fontWeightScale failed, ' + message);
}
 ```