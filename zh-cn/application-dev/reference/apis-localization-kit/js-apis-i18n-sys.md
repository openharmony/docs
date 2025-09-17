# @ohos.i18n (国际化-I18n)(系统接口)

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

 本模块提供系统相关的或者增强的国际化能力，包括区域管理、电话号码处理、日历等，相关接口为ECMA 402标准中未定义的补充接口。[Intl模块](js-apis-intl.md)提供了ECMA 402标准定义的基础国际化接口，与本模块共同使用可提供完整地国际化支持能力。

>  **说明：**
>  - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 从API version 11开始，本模块部分接口支持在ArkTS卡片中使用。
>
>  - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.i18n (国际化-I18n)](js-apis-intl.md)。


## 导入模块

```ts
import { i18n } from '@kit.LocalizationKit';
```

## System<sup>9+</sup>

提供系统属性获取或设置的能力。

### setSystemLanguage<sup>9+</sup>

static setSystemLanguage(language: string): void

设置系统语言。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明    |
| -------- | ------ | ---- | ----- |
| language | string | 是    | [合法的语言ID](../../internationalization/i18n-locale-culture.md#实现原理)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 设置系统语言
  try {
    i18n.System.setSystemLanguage('zh'); // 设置系统当前语言为 "zh"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setSystemRegion<sup>9+</sup>

static setSystemRegion(region: string): void

设置系统地区。

若要监听系统地区变化，可以监听[事件](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_locale_changed)OHOS::EventFwk::CommonEventSupport::COMMON_EVENT_LOCALE_CHANGED。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| region | string | 是    | 合法的地区ID。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setSystemRegion('CN');  // 设置系统当前地区为 "CN"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```



### setSystemLocale<sup>(deprecated)</sup>

static setSystemLocale(locale: string): void

> 从API version 9开始支持，从API version 20开始废弃。

设置系统区域。

若要监听系统区域变化，可以监听[事件](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_locale_changed)OHOS::EventFwk::CommonEventSupport::COMMON_EVENT_LOCALE_CHANGED。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明              |
| ------ | ------ | ---- | --------------- |
| locale | string | 是    | [表示区域ID的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setSystemLocale('zh-CN');  // 设置系统当前区域ID为 "zh-CN"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### set24HourClock<sup>9+</sup>

static set24HourClock(option: boolean): void

设置系统时制是否为24小时制。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型      | 必填   | 说明                                       |
| ------ | ------- | ---- | ---------------------------------------- |
| option | boolean | 是    | true表示设置系统时制为24小时制，false表示设置系统时制为12小时制。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 将系统时制设置为24小时制
  try {
    i18n.System.set24HourClock(true);
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### addPreferredLanguage<sup>9+</sup>

static addPreferredLanguage(language: string, index?: number): void

在系统偏好语言列表的指定位置添加偏好语言。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明         |
| -------- | ------ | ---- | ---------- |
| language | string | 是    | 待添加的偏好语言，要求是[合法的语言ID](../../internationalization/i18n-locale-culture.md#实现原理)。  |
| index    | number | 否    | 偏好语言的添加位置。默认值：系统偏好语言列表长度。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 将语言zh-CN添加到系统偏好语言列表中
  let language = 'zh-CN';
  let index = 0;
  try {
    i18n.System.addPreferredLanguage(language, index); // 将zh-CN添加到系统偏好语言列表的第1位
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.addPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### removePreferredLanguage<sup>9+</sup>

static removePreferredLanguage(index: number): void

从系统偏好语言列表中移除指定位置的偏好语言。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                    |
| ----- | ------ | ---- | --------------------- |
| index | number | 是    | 待删除偏好语言在系统偏好语言列表中的位置。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 删除系统偏好语言列表中的第一个偏好语言
  let index: number = 0;
  try {
    i18n.System.removePreferredLanguage(index);
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.removePreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setUsingLocalDigit<sup>9+</sup>

static setUsingLocalDigit(flag: boolean): void

设置系统是否使用本地数字。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型      | 必填   | 说明                              |
| ---- | ------- | ---- | ------------------------------- |
| flag | boolean | 是    | true表示打开本地数字开关，false表示关闭本地数字开关。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setUsingLocalDigit(true); // 打开本地化数字开关
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### setTemperatureType<sup>18+</sup>

static setTemperatureType(type: TemperatureType): void

设置系统的温度单位。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型      | 必填   | 说明                              |
| ---- | ------- | ---- | ------------------------------- |
| type | [TemperatureType](./js-apis-i18n.md#temperaturetype18) | 是 | 温度单位。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

> **说明**
>
> 890001的报错信息请以接口的实际报错为准。

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setTemperatureType(i18n.TemperatureType.CELSIUS); // 设置温度单位为摄氏度
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setTemperatureType failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setFirstDayOfWeek<sup>18+</sup>

static setFirstDayOfWeek(type: WeekDay): void

设置系统的周起始日。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型      | 必填   | 说明                              |
| ---- | ------- | ---- | ------------------------------- |
| type | [WeekDay](./js-apis-i18n.md#weekday18) | 是 | 周期起始日。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

> **说明**
>
> 890001的报错信息请以接口的实际报错为准。

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setFirstDayOfWeek(i18n.WeekDay.MON); // 设置用户偏好的周起始日为周一
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setFirstDayOfWeek failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemCollations<sup>20+</sup>

static getSystemCollations(): Map&lt;string, string&gt;

获取系统支持的排序方式及名称。如系统语言为英文时，可以支持大写在前或小写在前的排序方式。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | 系统支持的排序方式及名称。其中Map的key为表示排序方式的字符串，value为表示排序方式对应名称的字符串。支持的范围和系统语言相关。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let systemCollations: Map<string, string> = i18n.System.getSystemCollations();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemCollations failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getUsingCollation<sup>20+</sup>

static getUsingCollation(): string

获取系统当前使用的排序方式。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| string | 系统当前使用的排序方式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let usingCollation: string = i18n.System.getUsingCollation();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getUsingCollation failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemCollation<sup>20+</sup>

static setSystemCollation(identifier: string): void

设置系统的排序方式。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型      | 必填   | 说明                              |
| ---- | ------- | ---- | ------------------------------- |
| identifier | string | 是 | 系统支持的排序方式。支持的范围可以通过[getSystemCollations](#getsystemcollations20)获取。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemCollation("zhuyin"); // 如果设置当前系统不支持的排序方式会报错
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemCollation failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getSystemNumberingSystems<sup>20+</sup>

static getSystemNumberingSystems(): Map&lt;string, string&gt;

获取系统支持的数字系统及示例。示例为数字0~9在对应数字系统下的显示。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | 系统支持的数字系统及示例。其中Map的key为表示数字系统的字符串，value为表示数字系统对应的示例。支持的范围和系统语言相关。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let systemNumberingSystems: Map<string, string> = i18n.System.getSystemNumberingSystems();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemNumberingSystems failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemNumberingSystem<sup>20+</sup>

static setSystemNumberingSystem(identifier: string):void

设置系统的数字系统。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型      | 必填   | 说明                              |
| ---- | ------- | ---- | ------------------------------- |
| identifier | string | 是 | 系统支持的数字系统。支持的范围可以通过[getSystemNumberingSystems](#getsystemnumberingsystems20)获取。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemNumberingSystem("arab"); // 如果设置当前系统不支持的数字系统会报错
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemNumberingSystem failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getSystemNumberPatterns<sup>20+</sup>

static getSystemNumberPatterns(): Map&lt;string, string&gt;

获取系统支持的数字格式及示例。数字格式指数字中的千分符和小数分隔符的格式。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | 系统支持的数字格式及示例。其中Map的key表示数字格式，是千分符和小数分隔符的unicode编码，value表示数字格式对应的示例。支持的范围和系统语言地区相关。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let systemNumberPatterns: Map<string, string> = i18n.System.getSystemNumberPatterns();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemNumberPatterns failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getUsingNumberPattern<sup>20+</sup>

static getUsingNumberPattern(): string

获取系统当前使用的数字格式。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| string | 系统当前使用的数字格式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let usingNumberPattern: string = i18n.System.getUsingNumberPattern();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getUsingNumberPattern failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemNumberPattern<sup>20+</sup>

static setSystemNumberPattern(pattern: string): void

设置系统的数字格式。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型      | 必填   | 说明                              |
| ---- | ------- | ---- | ------------------------------- |
| pattern | string | 是 | 系统支持的数字格式。支持的范围可以通过[getSystemNumberPatterns](#getsystemnumberpatterns20)获取。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemNumberPattern("002e002c"); // 如果设置当前系统不支持的数字格式会报错
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemNumberPattern failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getSystemMeasurements<sup>20+</sup>

static getSystemMeasurements(): Map&lt;string, string&gt;

获取系统支持的度量衡及其名称。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | 系统支持的度量衡及其名称。其中Map的key表示度量衡的标识，value表示度量衡的名称。支持的度量衡如下：<br>- metric：公制。<br>- uksystem：英制。<br>- ussystem：美制。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let systemMeasurements: Map<string, string> = i18n.System.getSystemMeasurements();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemMeasurements failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getUsingMeasurement<sup>20+</sup>

static getUsingMeasurement(): string

获取系统当前使用的度量衡。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| string | 系统当前使用的度量衡，取值及对应含义如下：<br>- metric：公制。<br>- uksystem：英制。<br>- ussystem：美制。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let usingMeasurement: string = i18n.System.getUsingMeasurement();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getUsingMeasurement failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemMeasurement<sup>20+</sup>

static setSystemMeasurement(identifier: string): void

设置系统的度量衡。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型      | 必填   | 说明                              |
| ---- | ------- | ---- | ------------------------------- |
| identifier | string | 是 | 系统支持的度量衡。支持的范围可以通过[getSystemMeasurements](#getsystemmeasurements20)获取。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemMeasurement("uksystem"); // 如果设置当前系统不支持的度量衡会抛8900001错误码
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemMeasurement failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getSystemNumericalDatePatterns<sup>20+</sup>

static getSystemNumericalDatePatterns(): Map&lt;string, string&gt;

获取系统支持的数字日期格式及其示例。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | 获取系统支持的数字日期格式及其示例。其中Map的key表示数字日期格式，形如`dd/MM/y`；value表示数字日期示例，形如`18/07/2025`。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let datePatterns: Map<string, string> = i18n.System.getSystemNumericalDatePatterns();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemNumericalDatePatterns failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getUsingNumericalDatePattern<sup>20+</sup>

static getUsingNumericalDatePattern(): string

获取系统当前使用的数字日期格式。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| string | 系统当前使用的数字日期格式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let datePattern: string = i18n.System.getUsingNumericalDatePattern();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getUsingNumericalDatePattern failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemNumericalDatePattern<sup>20+</sup>

static setSystemNumericalDatePattern(identifier: string): void

设置系统的数字日期格式。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型      | 必填   | 说明                              |
| ---- | ------- | ---- | ------------------------------- |
| identifier | string | 是 | 系统支持的数字日期格式。支持的范围可以通过[getSystemNumericalDatePatterns](#getsystemnumericaldatepatterns20)获取。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemNumericalDatePattern("dd/MM/y"); // 如果设置当前系统不支持的数字日期格式，系统会抛出8900001错误码
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemNumericalDatePattern failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## SystemLocaleManager<sup>10+</sup>

提供语言、地区和时区信息排序的能力。

### constructor<sup>10+</sup>

constructor()

创建SystemLocaleManager对象。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**示例：**
  ```ts
  let systemLocaleManager: i18n.SystemLocaleManager = new i18n.SystemLocaleManager();
  ```


### getLanguageInfoArray<sup>10+</sup>

getLanguageInfoArray(languages: Array&lt;string&gt;, options?: SortOptions): Array&lt;LocaleItem&gt;

获取排序后的语言信息列表。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ------------- | ---- | ------------- |
| languages | Array&lt;string&gt; | 是   | 待排序的语言列表，要求是[合法的语言ID](../../internationalization/i18n-locale-culture.md#实现原理)。|
| options   | [SortOptions](#sortoptions10)   | 否   | 语言排序选项。 |

**返回值：**

|       类型        |         说明          |
| ----------------- | -------------------- |
| Array&lt;[LocaleItem](#localeitem10)&gt; | 排序后的语言信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 当系统语言为zh-Hans，系统地区为CN，系统区域为zh-Hans-CN时
  let systemLocaleManager: i18n.SystemLocaleManager = new i18n.SystemLocaleManager();
  let languages: string[] = ["zh-Hans", "en-US", "pt", "ar"];
  let sortOptions: i18n.SortOptions = {locale: "zh-Hans-CN", isUseLocalName: true, isSuggestedFirst: true};
  try {
      // 排序后的语言顺序为: [zh-Hans, en-US, pt, ar]
      let sortedLanguages: Array<i18n.LocaleItem> = systemLocaleManager.getLanguageInfoArray(languages, sortOptions);
  } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call systemLocaleManager.getLanguageInfoArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getRegionInfoArray<sup>10+</sup>

getRegionInfoArray(regions: Array&lt;string&gt;, options?: SortOptions): Array&lt;LocaleItem&gt;

获取排序后的国家或地区信息列表。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ------------- | ---- | ------------- |
| regions   | Array&lt;string&gt; | 是   | 待排序的国家或地区列表，要求是合法的国家或地区ID。|
| options   | [SortOptions](#sortoptions10)   | 否   | 国家或地区排序选项。<br>区域ID的默认值为系统当前区域ID，isUseLocalName的默认值为false，isSuggestedFirst的默认值为true。 |

**返回值：**

|       类型        |         说明          |
| ----------------- | -------------------- |
| Array&lt;[LocaleItem](#localeitem10)&gt; | 排序后的国家或地区信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 当系统语言为zh-Hans，系统地区为CN，系统区域为zh-Hans-CN时
  let systemLocaleManager: i18n.SystemLocaleManager = new i18n.SystemLocaleManager();
  let regions: string[] = ["CN", "US", "PT", "EG"];
  let sortOptions: i18n.SortOptions = {locale: "zh-Hans-CN", isUseLocalName: false, isSuggestedFirst: true};
  try {
      // 排序后的地区顺序为: [CN, EG, US, PT]
      let sortedRegions: Array<i18n.LocaleItem> = systemLocaleManager.getRegionInfoArray(regions, sortOptions);
  } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call systemLocaleManager.getRegionInfoArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getTimeZoneCityItemArray<sup>10+</sup>

static getTimeZoneCityItemArray(): Array&lt;TimeZoneCityItem&gt;

获取排序后的时区城市组合信息列表。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

|       类型        |         说明          |
| ----------------- | -------------------- |
| Array&lt;[TimeZoneCityItem](#timezonecityitem10)&gt; | 排序后的时区城市组合信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let timeZoneCityItemArray: Array<i18n.TimeZoneCityItem> = i18n.SystemLocaleManager.getTimeZoneCityItemArray();
    for (let i = 0; i < timeZoneCityItemArray.length; i++) {
        console.info(timeZoneCityItemArray[i].zoneId + ", " + timeZoneCityItemArray[i].cityId + ", " + timeZoneCityItemArray[i].cityDisplayName +
            ", " + timeZoneCityItemArray[i].offset + "\r\n");
    }
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call SystemLocaleManager.getTimeZoneCityItemArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## LocaleItem<sup>10+</sup>

语言或国家地区的组合信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型            | 只读 | 可选   |  说明                                   |
| --------------- | --------------- | ------ | ------ | --------------------------------------- |
| id              | string          |   否   |   否   | 语言代码或国家地区代码，如"zh"、"CN"。    |
| suggestionType  | [SuggestionType](#suggestiontype10)  |   否   |   否  | 语言或国家地区推荐类型。                  |
| displayName     | string          |   否   |  否   | id在SystemLocaleManager的指定区域下的表示。|
| localName       | string          |   否   |  是   | id的本地名称。只有在表示语言相关信息时才存在该选项。      |

## TimeZoneCityItem<sup>10+</sup>

时区城市的组合信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型             |  只读   |  可选   |  说明                                   |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| zoneId          | string          |   否    |   否    | 时区ID，例如Asia/Shanghai。              |
| cityId          | string          |   否    |   否    | 城市ID，例如Shanghai。                   |
| cityDisplayName | string          |   否    |   否    | 城市ID在系统区域下显示的名称。          |
| offset          | number             |   否    |   否    | 时区ID的偏移量。                         |
| zoneDisplayName | string          |   否    |   否    | 时区ID在系统区域下显示的名称。          |
| rawOffset       | number             |   否    |   是    | 时区ID的固定偏移量。                       |


## SuggestionType<sup>10+</sup>

语言或国家地区的推荐类型。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

| 名称                   | 值  | 说明   |
| ---------------------- | ---- | ---- |
| SUGGESTION_TYPE_NONE   | 0x00 | 非推荐语言或国家地区。 |
| SUGGESTION_TYPE_RELATED| 0x01 | 系统语言推荐的国家地区或系统国家地区推荐的语言。 |
| SUGGESTION_TYPE_SIM    | 0x02 | Sim卡国家地区推荐的语言。 |


## SortOptions<sup>10+<sup>

语言或国家地区排序选项。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型            |  只读 |  可选 |   说明                                 |
| --------------- | --------------- | ---- | ---- | --------------------------------------- |
| locale          | string          |  否  |  是  | [表示区域ID的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成，如"zh-Hans-CN"。<br>默认值：系统当前区域ID。    |
| isUseLocalName  | boolean         |  否  |  是  | true表示使用本地名称进行排序，false表示不使用本地名称进行排序。<br>若调用方法为getLanguageInfoArray，isUseLocalName属性默认值为true。<br>若调用方法为getRegionInfoArray，isUseLocalName属性默认值为false。                |
| isSuggestedFirst | boolean        |  否  |  是  | true表示将推荐语言或国家地区在排序结果中置顶，false表示不将推荐语言或国家地区在排序结果中置顶。<br>默认值：true。  |
