# @ohos.fontManager (字体管理)

字体管理模块，提供给系统应用安装和卸载三方字体文件的能力。

>  **说明：**
>  - 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 当前页面仅包含本模块的系统接口。

## 导入模块

```js
import fontManager from '@ohos.fontManager';
```

### installFont<sup>18+</sup>

installFont(path: string): Promise&lt;number&gt;

安装指定路径字体，并使用promise异步回调返回安装信息。

**说明**：需要权限: ohos.permission.UPDATE_FONT

**系统能力**：SystemCapability.Global.FontManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| path | string | 是    | 安装字体文件路径。 |

**返回值：**

| 类型                    | 说明                     |
| --------------------- | ---------------------- |
| Promise&lt;number&gt; | 返回安装信息：0 表示安装成功。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.            |
| 202 | Permission verification failed. A non-system application calls a system API.          |
| 31100101 | The font file does not exist.            |
| 31100102 | The font file is not supported.          |
| 31100103 | Failed to copy the font file.            |
| 31100104 | The font file is installed.              |
| 31100105 | The maximum number of installed font files is exceeded.      |
| 31100106 | Installation failed, other errors.       |

**示例：**
  ```ts
  import fontManager from '@kit.LocalizationKit'

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

### uninstallFont<sup>18+</sup>

uninstallFont(fullName: string): Promise&lt;number&gt;

卸载指定名称字体，并使用promise异步回调返回卸载信息。

**说明**：需要权限: ohos.permission.UPDATE_FONT

**系统能力**：SystemCapability.Global.FontManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| fullName | string | 是    | 需要卸载的字体名称。 |

**返回值：**

| 类型                    | 说明                     |
| --------------------- | ---------------------- |
| Promise&lt;number&gt; | 返回卸载信息：0 表示卸载成功。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.            |
| 202 | Permission verification failed. A non-system application calls a system API.          |
| 31100107 | The font file to be uninstalled does not exist.     |
| 31100108 | Font cannot be deleted                   |
| 31100109 | Uninstall failed, other errors.          |

**示例：**
  ```ts
  import fontManager from '@kit.LocalizationKit'

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
