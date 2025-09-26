# @ohos.fontManager (字体管理)

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

字体管理模块，提供给系统应用安装和卸载三方字体的能力。

>  **说明：**
>  
>  - 本模块首批接口从API version 19开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 当前页面仅包含本模块的系统接口。

## 导入模块

```js
import { fontManager } from '@kit.LocalizationKit';
```

### installFont<sup>19+</sup>

installFont(path: string): Promise&lt;number&gt;

安装指定路径下的字体，使用promise异步回调。

**需要权限:** ohos.permission.UPDATE_FONT

**系统能力:** SystemCapability.Global.FontManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| path | string | 是    | 安装字体文件路径。 |

**返回值：**

| 类型                    | 说明                     |
| --------------------- | ---------------------- |
| Promise&lt;number&gt; | 返回安装结果。返回为0表示安装成功，否则安装失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission denied.                 |
| 202 | Non-system application.            |
| 31100101 | Font does not exist.          |
| 31100102 | Font is not supported.        |
| 31100103 | Font file copy failed.        |
| 31100104 | Font file installed.          |
| 31100105 | Exceeded maximum number of installed files.     |
| 31100106 | Other error.     |

**示例：**
  ```ts
  import { fontManager } from '@kit.LocalizationKit';

  async installFont() {
    try {
      let res = await fontManager.installFont('fontPath');
      console.info('installFont suc. res is ' + res);
    } catch (error) {
      console.error('installFont err.' + error.code);
    }
    return;
  }
  ```

### uninstallFont<sup>19+</sup>

uninstallFont(fullName: string): Promise&lt;number&gt;

卸载指定名称的字体，使用promise异步回调。

**需要权限:** ohos.permission.UPDATE_FONT

**系统能力:** SystemCapability.Global.FontManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| fullName | string | 是    | 需要卸载的字体名称，字体名称可通过打开.ttf或.ttc字体文件获取。 |

**返回值：**

| 类型                    | 说明                     |
| --------------------- | ---------------------- |
| Promise&lt;number&gt; | 返回卸载结果。返回为0表示卸载成功，否则卸载失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission denied.                |
| 202 | Non-system application.           |
| 31100107 | Font file does not exist.    |
| 31100108 | Font file delete error.      |
| 31100109 | Other error.                 |

**示例：**
  ```ts
  import { fontManager } from '@kit.LocalizationKit';

  async uninstallFont() {
    try {
      let res = await fontManager.uninstallFont('fontName');
      console.info('uninstallFont suc. res is ' + res);
    } catch (error) {
      console.error('uninstallFont err.' + error.code);
    }
    return;
  }
  ```
