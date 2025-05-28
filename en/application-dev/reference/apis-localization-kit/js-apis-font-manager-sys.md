# @ohos.fontManager (Font Management)

The **fontManager** module provides APIs for system applications to install and uninstall third-party fonts.

>  **NOTE**
>  
>  - The initial APIs of this module are supported since API version 19. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - This topic describes only the system APIs provided by the module.

## Modules to Import

```js
import { fontManager } from '@kit.LocalizationKit';
```

### installFont<sup>19+</sup>

installFont(path: string): Promise&lt;number&gt;

Installs a font in the specified path. This API uses a promise to return the result.

**Required permissions**: ohos.permission.UPDATE_FONT

**System capability**: SystemCapability.Global.FontManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| path | string | Yes   | Path of the font file to be installed.|

**Return value**

| Type                   | Description                    |
| --------------------- | ---------------------- |
| Promise&lt;number&gt; | Promise used to return the result. The value **0** indicates that the installation is successful, and any other value indicates that the installation has failed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied.                 |
| 202 | Non-system application.            |
| 31100101 | Font does not exist.          |
| 31100102 | Font is not supported.        |
| 31100103 | Font file copy failed.        |
| 31100104 | Font file installed.          |
| 31100105 | Exceeded maximum number of installed files.     |
| 31100106 | Other error.     |

**Example:**
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

Uninstalls a font by name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.UPDATE_FONT

**System capability**: SystemCapability.Global.FontManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| fullName | string | Yes   | Name of the font to be uninstalled. You can obtain the font name by opening the **.ttf** or **.ttc** font file.|

**Return value**

| Type                   | Description                    |
| --------------------- | ---------------------- |
| Promise&lt;number&gt; | Promise used to return the result. The value **0** indicates that the uninstallation is successful, and any other value indicates that the uninstallation has failed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied.                |
| 202 | Non-system application.           |
| 31100107 | Font file does not exist.    |
| 31100108 | Font file delete error.      |
| 31100109 | Other error.                 |

**Example:**
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
