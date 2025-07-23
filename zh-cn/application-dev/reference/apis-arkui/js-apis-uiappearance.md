# @ohos.uiAppearance (用户界面外观)

用户界面外观提供获取系统外观的一些基础能力，包括获取深浅色模式、字体大小缩放比例、字体粗细缩放比例。

> **说明：**
>
> 从API version 20开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```ts
import { uiAppearance } from '@kit.ArkUI';
```


## DarkMode

深色模式枚举。


**系统能力：** SystemCapability.ArkUI.UiAppearance

| 名称 | 值 | 说明 |
| -- | -- | -- |
| ALWAYS_DARK | 0 | 系统始终为深色。  |
| ALWAYS_LIGHT | 1 | 系统始终为浅色。 |

## uiAppearance.getDarkMode

getDarkMode(): DarkMode

获取系统当前的深色模式配置。

<!--Del-->
> **说明：**
>
> 在API version 19及之前版本中，该接口为系统接口。开发者使用该接口时需要申请ohos.permission.UPDATE_CONFIGURATION权限。
<!--DelEnd-->

**系统能力**：SystemCapability.ArkUI.UiAppearance

**返回值：** 

| 类型 | 说明 |
| -- | -- |
|[DarkMode](#darkmode) | 系统当前的深色模式配置。 |

**错误码：**

错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[errcode-uiappearance](errorcode-uiappearance.md)。

| 错误码ID | 错误信息 |
| -- | -- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 500001 | Internal error. |

**示例：** 

```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let darkMode = uiAppearance.getDarkMode();
    console.info('Get dark-mode ' + darkMode);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Get dark-mode failed, ' + message);
}
```


## uiAppearance.getFontScale

getFontScale(): number

获取系统当前的字体大小缩放比例。

<!--Del-->
> **说明：**
>
> 在API version 19及之前版本中，该接口为系统接口。开发者使用该接口时需要申请ohos.permission.UPDATE_CONFIGURATION权限。
<!--DelEnd-->

**系统能力**：SystemCapability.ArkUI.UiAppearance

**返回值：** 

| 类型 | 说明 |
| -- | -- |
| number | 系统当前的字体大小缩放比例。 |

**错误码：**

错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[errcode-uiappearance](errorcode-uiappearance.md)。

| 错误码ID | 错误信息 |
| -- | -- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 500001 | Internal error. |

**示例：** 

```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let fontScale = uiAppearance.getFontScale();
    console.info('Get fontScale ' + fontScale);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Get fontScale failed, ' + message);
}
```


## uiAppearance.getFontWeightScale

getFontWeightScale(): number

获取系统当前的字体粗细缩放比例。

<!--Del-->
> **说明：**
>
> 在API version 19及之前版本中，该接口为系统接口。开发者使用该接口时需要申请ohos.permission.UPDATE_CONFIGURATION权限。
<!--DelEnd-->

**系统能力**：SystemCapability.ArkUI.UiAppearance

**返回值：** 

| 类型 | 说明 |
| -- | -- |
| number | 系统当前的字体粗细缩放比例。 |

**错误码：**

错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[errcode-uiappearance](errorcode-uiappearance.md)。

| 错误码ID | 错误信息 |
| -- | -- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 500001 | Internal error. |

**示例：** 

```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let fontWeightScale = uiAppearance.getFontWeightScale();
    console.info('Get fontScale ' + fontWeightScale);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Get fontWeightScale failed, ' + message);
}
```