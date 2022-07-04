# 用户界面外观

用户界面外观提供管理系统外观的一些基础能力，目前仅包括深浅色模式配置。

> **说明：**
> 从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> 本模块接口为系统接口。


## 导入模块

```ts
import uiAppearance from '@ohos.uiAppearance'
```


## DarkMode

深色模式枚举。


| 名称 | 值 | 说明 |
| -- | -- | -- |
| ALWAYS_DARK | 0 | 系统始终为深色。  |
| ALWAYS_LIGHT | 1 | 系统始终为浅色。 |


## uiAppearance.setDarkMode

setDarkMode(mode: DarkMode, callback: AsyncCallback\<void>): void

设置系统深色模式。

**需要权限：** ohos.permission.UPDATE_CONFIGRATION

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 
| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| mode | [DarkMode](#darkmode) | 是 | 指定系统的深色模式配置 |
| callback | AsyncCallback\<void>| 是 | 配置深色模式的异步回调 |

**示例：** 
  ```ts
uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK, (err) => {
  console.info(`${err}`);
})
  ```


## uiAppearance.setDarkMode

setDarkMode(mode: DarkMode): Promise\<void>;

设置系统深色模式。

**需要权限：** ohos.permission.UPDATE_CONFIGRATION

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 
| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| mode | [DarkMode](#darkmode) | 是 | 指定系统深色模式配置 |

**示例：** 
  ```ts
uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK).then(() => {
    console.log('Set dark-mode successfully.');
}).catch((err) => {
    console.log(`Set dark-mode failed, ${err}`);
});
  ```


## uiAppearance.getDarkMode

getDarkMode(): DarkMode;

获取当前的深色模式配置。

**需要权限：** ohos.permission.UPDATE_CONFIGRATION

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：** 
| 类型 | 说明 |
| -- | -- |
|[DarkMode](#darkmode) | 系统当前的深色模式配置 |

**示例：** 
  ```ts
let darkMode = uiAppearance.getDarkMode();
console.log(`Get dark-mode ${darkMode}`);
  ```