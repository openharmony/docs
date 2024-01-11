# @ohos.i18n (国际化-I18n)

本模块提供系统配置相关国际化能力，包括获取系统语言、系统区域以及语言名称的相关接口。


## 导入模块

```ts
import I18n from '@ohos.i18n';
```


## System<sup>9+</sup>

### getDisplayLanguage<sup>9+</sup>

static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

获取指定语言的本地化显示文本。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| language     | string  | 是    | 指定语言。            |
| locale       | string  | 是    | 显示指定语言的区域ID。     |
| sentenceCase | boolean | 否    | 本地化显示文本是否要首字母大写。默认值：true。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 指定语言的本地化显示文本。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let displayLanguage: string = I18n.System.getDisplayLanguage("zh", "en-GB"); // displayLanguage = Chinese
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getDisplayLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLanguage<sup>9+</sup>

static getSystemLanguage(): string

获取系统语言。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统语言ID。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemLanguage: string = I18n.System.getSystemLanguage();  // systemLanguage为当前系统语言
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLocale<sup>9+</sup>

static getSystemLocale(): string

获取系统区域。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统区域ID。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemLocale: string = I18n.System.getSystemLocale();  // 获取系统当前Locale
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```