# @ohos.i18n (国际化-I18n)

 本模块提供系统相关的或者增强的国际化能力，包括区域管理、电话号码处理、日历等，相关接口为ECMA 402标准中未定义的补充接口。
[Intl模块](js-apis-intl.md)提供了ECMA 402标准定义的基础国际化接口，与本模块共同使用可提供完整地国际化支持能力。

>  **说明：**
>  - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - I18N模块包含国际化能力增强接口（未在ECMA 402中定义），包括区域管理、电话号码处理、日历等，国际化基础能力请参考[Intl模块](js-apis-intl.md)。


## 导入模块

```ts
import I18n from '@ohos.i18n';
```


## System<sup>9+</sup>

### getDisplayCountry<sup>9+</sup>

static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

获取指定国家的本地化显示文本。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | 是    | 指定国家。            |
| locale       | string  | 是    | 显示指定国家的区域ID。     |
| sentenceCase | boolean | 否    | 本地化显示文本是否要首字母大写。默认值：true。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 指定国家的本地化显示文本。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
      let displayCountry: string = I18n.System.getDisplayCountry("zh-CN", "en-GB"); // displayCountry = "China"
  } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call System.getDisplayCountry failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

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

### getSystemLanguages<sup>9+</sup>

static getSystemLanguages(): Array&lt;string&gt;

获取系统支持的语言列表。语言的详细说明参见[实例化Locale对象](../../internationalization/intl-guidelines.md#开发步骤)。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明           |
| ------------------- | ------------ |
| Array&lt;string&gt; | 系统支持的语言ID列表。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemLanguages: Array<string> = I18n.System.getSystemLanguages(); // [ "en-Latn-US", "zh-Hans" ]
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemLanguages failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemCountries<sup>9+</sup>

static getSystemCountries(language: string): Array&lt;string&gt;

获取针对输入语言系统支持的国家或地区列表。国家或地区的详细说明参见[实例化Locale对象](../../internationalization/intl-guidelines.md#开发步骤)。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明    |
| -------- | ------ | ---- | ----- |
| language | string | 是    | 语言ID。 |

**返回值：**

| 类型                  | 说明           |
| ------------------- | ------------ |
| Array&lt;string&gt; | 系统支持的区域ID列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemCountries: Array<string> = I18n.System.getSystemCountries('zh'); // systemCountries = [ "ZW", "YT", "YE", ..., "ER", "CN", "DE" ]，共计240个国家或地区
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemCountries failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### isSuggested<sup>9+</sup>

static isSuggested(language: string, region?: string): boolean

判断当前语言和地区是否匹配。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明            |
| -------- | ------ | ---- | ------------- |
| language | string | 是    | 合法的语言ID，例如zh。 |
| region   | string | 否    | 合法的地区ID，例如CN。默认值：使用SIM卡国家或地区。  |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true，表示当前语言和地区匹配；返回false，表示当前语言和地区不匹配。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let res: boolean = I18n.System.isSuggested('zh', 'CN');  // res = true
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.isSuggested failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLanguage<sup>9+</sup>

static getSystemLanguage(): string

获取系统语言。语言的详细说明参见[实例化Locale对象](../../internationalization/intl-guidelines.md#开发步骤)。

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

### setSystemLanguage<sup>9+</sup>

static setSystemLanguage(language: string): void

设置系统语言。当前调用该接口不支持系统界面语言的实时刷新。

若设置系统语言后，需要[监听事件](./commonEventManager-definitions.md#common_event_locale_changed)OHOS::EventFwk::CommonEventSupport::COMMON_EVENT_LOCALE_CHANGED，可以[订阅](./js-apis-commonEventManager.md#commoneventmanagercreatesubscriber-1)该事件。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明    |
| -------- | ------ | ---- | ----- |
| language | string | 是    | 语言ID。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';
  import CommonEventManager from '@ohos.commonEventManager';

  // 设置系统语言
  try {
    I18n.System.setSystemLanguage('zh'); // 设置系统当前语言为 "zh"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
 
  // 订阅公共事件
  let subscriber: CommonEventManager.CommonEventSubscriber; // 用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
  let subscribeInfo: CommonEventManager.CommonEventSubscribeInfo = { // 订阅者信息
    events: [CommonEventManager.Support.COMMON_EVENT_LOCALE_CHANGED]
  };
  CommonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber:CommonEventManager.CommonEventSubscriber) => { // 创建订阅者
      console.info("createSubscriber");
      subscriber = commonEventSubscriber;
      CommonEventManager.subscribe(subscriber, (err, data) => {
        if (err) {
          console.error(`Failed to subscribe common event. error code: ${err.code}, message: ${err.message}.`);
          return;
        }
        console.info("the subscribed event has occurred."); // 订阅的事件发生时执行
      })
  }).catch((err: BusinessError) => {
      console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  });  
  ```

### getSystemRegion<sup>9+</sup>

static getSystemRegion(): string

获取系统地区。地区的详细说明参见[实例化Locale对象](../../internationalization/intl-guidelines.md#开发步骤)。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统地区ID。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemRegion: string = I18n.System.getSystemRegion(); // 获取系统当前地区设置
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setSystemRegion<sup>9+</sup>

static setSystemRegion(region: string): void

设置系统区域。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| region | string | 是    | 地区ID。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    I18n.System.setSystemRegion('CN');  // 设置系统当前地区为 "CN"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLocale<sup>9+</sup>

static getSystemLocale(): string

获取系统区域。区域的详细说明参见[实例化Locale对象](../../internationalization/intl-guidelines.md#开发步骤)。

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

### setSystemLocale<sup>9+</sup>

static setSystemLocale(locale: string): void

设置系统Locale。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明              |
| ------ | ------ | ---- | --------------- |
| locale | string | 是    | 指定区域ID，例如zh-CN。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    I18n.System.setSystemLocale('zh-CN');  // 设置系统当前Locale为 "zh-CN"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### is24HourClock<sup>9+</sup>

static is24HourClock(): boolean

判断系统时间是否为24小时制。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true，表示系统24小时开关开启；返回false，表示系统24小时开关关闭。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let is24HourClock: boolean = I18n.System.is24HourClock();  // 系统24小时开关是否开启
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.is24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### set24HourClock<sup>9+</sup>

static set24HourClock(option: boolean): void

设置系统时间为24小时。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型      | 必填   | 说明                                       |
| ------ | ------- | ---- | ---------------------------------------- |
| option | boolean | 是    | option为true，表示开启系统24小时制开关；返回false，表示关闭系统24小时开关。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  // 将系统时间设置为24小时制
  try {
    I18n.System.set24HourClock(true);
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### addPreferredLanguage<sup>9+</sup>

static addPreferredLanguage(language: string, index?: number): void

在系统偏好语言列表中的指定位置添加偏好语言。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明         |
| -------- | ------ | ---- | ---------- |
| language | string | 是    | 待添加的偏好语言。  |
| index    | number | 否    | 偏好语言的添加位置。默认值：系统偏好语言列表长度。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  // 将语言zh-CN添加到系统偏好语言列表中
  let language = 'zh-CN';
  let index = 0;
  try {
    I18n.System.addPreferredLanguage(language, index); // 将zh-CN添加到系统偏好语言列表的第1位
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.addPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### removePreferredLanguage<sup>9+</sup>

static removePreferredLanguage(index: number): void

删除系统偏好语言列表中指定位置的偏好语言。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                    |
| ----- | ------ | ---- | --------------------- |
| index | number | 是    | 待删除偏好语言在系统偏好语言列表中的位置。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  // 删除系统偏好语言列表中的第一个偏好语言
  let index: number = 0;
  try {
    I18n.System.removePreferredLanguage(index);
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.removePreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getPreferredLanguageList<sup>9+</sup>

static getPreferredLanguageList(): Array&lt;string&gt;

获取系统偏好语言列表。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明        |
| ------------------- | --------- |
| Array&lt;string&gt; | 系统偏好语言列表。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let preferredLanguageList: Array<string> = I18n.System.getPreferredLanguageList(); // 获取系统当前偏好语言列表
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getPreferredLanguageList failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getFirstPreferredLanguage<sup>9+</sup>

static getFirstPreferredLanguage(): string

获取系统偏好语言列表中的第一个偏好语言。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明             |
| ------ | -------------- |
| string | 偏好语言列表中的第一个语言。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let firstPreferredLanguage: string = I18n.System.getFirstPreferredLanguage();  // 获取系统当前偏好语言列表中的第一个偏好语言
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getFirstPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setAppPreferredLanguage<sup>11+</sup>

static setAppPreferredLanguage(language: string): void

设置应用的偏好语言。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明    |
| -------- | ------ | ---- | ----- |
| language | string | 是    | 语言ID。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    I18n.System.setAppPreferredLanguage('zh'); // 设置应用当前语言为 "zh"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getAppPreferredLanguage<sup>9+</sup>

static getAppPreferredLanguage(): string

获取应用的偏好语言。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明       |
| ------ | -------- |
| string | 应用的偏好语言。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let appPreferredLanguage: string = I18n.System.getAppPreferredLanguage(); // 获取应用偏好语言
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
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

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    I18n.System.setUsingLocalDigit(true); // 打开本地化数字开关
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getUsingLocalDigit<sup>9+</sup>

static getUsingLocalDigit(): boolean

判断系统是否使用本地数字。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | true表示系统当前已打开本地数字开关，false表示系统当前未打开本地数字开关。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let status: boolean = I18n.System.getUsingLocalDigit();  // 判断本地化数字开关是否打开
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


## I18n.isRTL<sup>7+</sup>

isRTL(locale: string): boolean

获取该区域是否为从右至左显示语言。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| locale | string | 是    | 指定区域ID。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | true表示该locale从右至左显示语言；false表示该locale从左至右显示语言。 |

**示例：**
  ```ts
  I18n.isRTL("zh-CN");// 中文不是RTL语言，返回false
  I18n.isRTL("ar-EG");// 阿语是RTL语言，返回true
  ```


## I18n.getCalendar<sup>8+</sup>

getCalendar(locale: string, type? : string): Calendar

获取日历对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | 是    | 合法的locale值，例如zh-Hans-CN。                 |
| type   | string | 否    | 合法的日历类型，目前合法的类型有buddhist,&nbsp;chinese,&nbsp;coptic,&nbsp;ethiopic,&nbsp;hebrew,&nbsp;gregory,&nbsp;indian,&nbsp;islamic_civil,&nbsp;islamic_tbla,&nbsp;islamic_umalqura,&nbsp;japanese,&nbsp;persian。默认值：区域默认的日历类型。 |

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| [Calendar](#calendar8) | 日历对象。 |

**示例：**
  ```ts
  I18n.getCalendar("zh-Hans", "chinese"); // 获取中国农历日历对象
  ```

## EntityRecognizer<sup>11+</sup>

### constructor<sup>11+</sup>

constructor(locale?: string)

创建实体识别对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                |
| ---- | ---- | ---- | ----------------- |
| locale | string | 否    | 区域ID。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  let entityRecognizer: I18n.EntityRecognizer = new I18n.EntityRecognizer("zh-CN");
  ```

### findEntityInfo<sup>11+</sup>

findEntityInfo(text: string): Array&lt;EntityInfoItem&gt;

识别文本中的实体信息。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                |
| ---- | ---- | ---- | ----------------- |
| text | string | 是    | 用于识别实体的文本。 |

**返回值：**

| 类型   | 说明                |
| ---- | ----------------- |
| Array&lt;[EntityInfoItem](#entityinfoitem11)&gt; | 识别的实体对象列表。 |

**示例：**
  ```ts
  let entityRecognizer: I18n.EntityRecognizer = new I18n.EntityRecognizer("zh-CN");
  let text1: string = "如有疑问，请联系158****2312";
  let result1: Array<I18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text1); // result[0].type = "phone_number", result[0].begin = 8, result[0].end = 19
  let text2: string = "我们2023年12月1日一起吃饭吧。";
  let result2: Array<I18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text2); // result[0].type = "date", result[0].begin = 2, result[0].end = 12
  ```

## EntityInfoItem<sup>11+</sup>

实体信息对象。

**系统能力**：SystemCapability.Global.I18n

| 名称  | 类型   | 可读   | 可写   | 说明                |
| ---- | ---- | ---- | ---- | ----------------- |
| type | string | 是    | 是    | 实体的类型，当前支持"phone_number"和"date"。 |
| begin | number | 是    | 是    | 实体的起始位置。 |
| end | number | 是    | 是    | 实体的终止位置。 |

## Calendar<sup>8+</sup>


### setTime<sup>8+</sup>

setTime(date: Date): void

设置日历对象内部的时间日期。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                |
| ---- | ---- | ---- | ----------------- |
| date | Date | 是    | 将要设置的日历对象的内部时间日期。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("en-US", "gregory");
  let date: Date = new Date(2021, 10, 7, 8, 0, 0, 0);
  calendar.setTime(date);
  ```


### setTime<sup>8+</sup>

setTime(time: number): void

设置日历对象内部的时间日期, time为从1970.1.1 00:00:00 GMT逝去的毫秒数。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| time | number | 是    | time为从1970.1.1&nbsp;00:00:00&nbsp;GMT逝去的毫秒数。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("en-US", "gregory");
  calendar.setTime(10540800000);
  ```


### set<sup>8+</sup>

set(year: number, month: number, date:number, hour?: number, minute?: number, second?: number): void

设置日历对象的年、月、日、时、分、秒。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明     |
| ------ | ------ | ---- | ------ |
| year   | number | 是    | 设置的年。  |
| month  | number | 是    | 设置的月。  |
| date   | number | 是    | 设置的日。  |
| hour   | number | 否    | 设置的小时。默认值：系统小时。 |
| minute | number | 否    | 设置的分钟。默认值：系统分钟。 |
| second | number | 否    | 设置的秒。默认值：系统秒。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00
  ```


### setTimeZone<sup>8+</sup>

setTimeZone(timezone: string): void

设置日历对象的时区。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明                        |
| -------- | ------ | ---- | ------------------------- |
| timezone | string | 是    | 设置的时区id，如“Asia/Shanghai”。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  ```


### getTimeZone<sup>8+</sup>

getTimeZone(): string

获取日历对象的时区。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 日历对象的时区id。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  let timezone: string = calendar.getTimeZone(); // timezone = "Asia/Shanghai"
  ```


### getFirstDayOfWeek<sup>8+</sup>

getFirstDayOfWeek(): number

获取日历对象的一周起始日。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                    |
| ------ | --------------------- |
| number | 获取一周的起始日，1代表周日，7代表周六。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("en-US", "gregory");
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1
  ```


### setFirstDayOfWeek<sup>8+</sup>

setFirstDayOfWeek(value: number): void

设置每一周的起始日。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                    |
| ----- | ------ | ---- | --------------------- |
| value | number | 是    | 设置一周的起始日，1代表周日，7代表周六。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.setFirstDayOfWeek(3);
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 3
  ```


### getMinimalDaysInFirstWeek<sup>8+</sup>

getMinimalDaysInFirstWeek(): number

获取一年中第一周的最小天数。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| number | 一年中第一周的最小天数。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 1
  ```


### setMinimalDaysInFirstWeek<sup>8+</sup>

setMinimalDaysInFirstWeek(value: number): void

设置一年中第一周的最小天数。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明           |
| ----- | ------ | ---- | ------------ |
| value | number | 是    | 一年中第一周的最小天数。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.setMinimalDaysInFirstWeek(3);
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 3
  ```


### get<sup>8+</sup>

get(field: string): number

获取日历对象中与field相关联的值。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| field | string | 是    | 通过field来获取日历对象相应的值。目前支持的field值有&nbsp;era,&nbsp;year,&nbsp;month,&nbsp;week_of_year,&nbsp;week_of_month,&nbsp;date,&nbsp;day_of_year,&nbsp;day_of_week,&nbsp;day_of_week_in_month,&nbsp;hour,&nbsp;hour_of_day,&nbsp;minute,&nbsp;second,&nbsp;millisecond,&nbsp;zone_offset,&nbsp;dst_offset,&nbsp;year_woy,&nbsp;dow_local,&nbsp;extended_year,&nbsp;julian_day,&nbsp;milliseconds_in_day,&nbsp;is_leap_month。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 与field相关联的值，如当前Calendar对象的内部日期的年份为1990，get("year")返回1990。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00
  let hourOfDay: number = calendar.get("hour_of_day"); // hourOfDay = 8
  ```


### getDisplayName<sup>8+</sup>

getDisplayName(locale: string): string

获取日历对象在该区域的名字。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | 是    | locale用于指定区域，如buddhist在en-US上显示的名称为“Buddhist&nbsp;Calendar”。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| string | 日历在locale所指示的区域的名字。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("en-US", "buddhist");
  let calendarName: string = calendar.getDisplayName("zh"); // calendarName = "佛历"
  ```


### isWeekend<sup>8+</sup>

isWeekend(date?: Date): boolean

判断指定的日期在日历中是否为周末。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                                       |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | 否    | 指定的日期。若不填，则判断当前日期是否为周末。默认值：系统日期。 |

**返回值：**

| 类型      | 说明                                  |
| ------- | ----------------------------------- |
| boolean | 若判断指定日期为周末时，返回true，否则返回false。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.11.11 08:00:00
  calendar.isWeekend(); // false
  let date: Date = new Date(2011, 11, 6, 9, 0, 0);
  calendar.isWeekend(date); // true
  ```


### add<sup>11+</sup>

add(field: string, amount: number): void

在日历的给定字段进行加减操作。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                                       |
| ---- | ---- | ---- | ---------------------------------------- |
| field | string | 是    | 指定进行操作的日历字段，目前支持的field值有&nbsp;year,&nbsp;month,&nbsp;week_of_year,&nbsp;week_of_month,&nbsp;date,&nbsp;day_of_year,&nbsp;day_of_week,&nbsp;day_of_week_in_month,&nbsp;hour,&nbsp;hour_of_day,&nbsp;minute,&nbsp;second,&nbsp;millisecond。 |
| amount | number | 是    | 进行加减操作的具体数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
    calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.11.11 08:00:00
    calendar.add("year", 8); // 2021 + 8
    let year: number = calendar.get("year"); // year = 2029
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call Calendar.add failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getTimeInMillis<sup>11+</sup>

getTimeInMillis(): number

获取当前日历的UTC毫秒数。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型      | 说明                                  |
| ------- | ----------------------------------- |
| number | 当前日历的UTC毫秒数。 |

**示例：**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.setTime(5000);
  let millisecond: number = calendar.getTimeInMillis(); // millisecond = 5000
  ```


### compareDays<sup>11+</sup>

compareDays(date: Date): number

比较日历和指定日期相差的天数（按毫秒级的精度，不足一天将按一天进行计算）。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                                       |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | 是    | 指定的日期。 |

**返回值：**

| 类型      | 说明                                  |
| ------- | ----------------------------------- |
| number | 相差的天数，正数代表日历时间更早，负数代表日历时间更晚。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
    calendar.setTime(5000);
    let date: Date = new Date(6000);
    let diff: number = calendar.compareDays(date); // diff = 1
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call Calendar.compareDays failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


## PhoneNumberFormat<sup>8+</sup>


### constructor<sup>8+</sup>

constructor(country: string, options?: PhoneNumberFormatOptions)

创建电话号码格式化对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名     | 类型                                       | 必填   | 说明               |
| ------- | ---------------------------------------- | ---- | ---------------- |
| country | string                                   | 是    | 表示电话号码所属国家或地区代码。 |
| options | [PhoneNumberFormatOptions](#phonenumberformatoptions8) | 否    | 电话号码格式化对象的相关选项。默认值：NATIONAL。  |

**示例：**
  ```ts
  let option: I18n.PhoneNumberFormatOptions = {type: "E164"};
  let phoneNumberFormat: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN", option);
  ```


### isValidNumber<sup>8+</sup>

isValidNumber(number: string): boolean

判断传入的电话号码格式是否正确。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明        |
| ------ | ------ | ---- | --------- |
| number | string | 是    | 待判断的电话号码。 |

**返回值：**

| 类型      | 说明                                    |
| ------- | ------------------------------------- |
| boolean | 返回true表示电话号码的格式正确，返回false表示电话号码的格式错误。 |

**示例：**
  ```ts
  let phonenumberfmt: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN");
  let isValidNumber: boolean = phonenumberfmt.isValidNumber("158****2312"); // isValidNumber = true
  ```


### format<sup>8+</sup>

format(number: string): string

对电话号码进行格式化。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明         |
| ------ | ------ | ---- | ---------- |
| number | string | 是    | 待格式化的电话号码。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 格式化后的电话号码。 |

**示例：**
  ```ts
  let phonenumberfmt: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN");
  let formattedPhoneNumber: string = phonenumberfmt.format("158****2312"); // formattedPhoneNumber = "158 **** 2312"
  ```


### getLocationName<sup>9+</sup>

getLocationName(number: string, locale: string): string

获取电话号码归属地。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明   |
| ------ | ------ | ---- | ---- |
| number | string | 是    | 电话号码 |
| locale | string | 是    | 区域ID |

**返回值：**

| 类型     | 说明       |
| ------ | -------- |
| string | 电话号码归属地。 |

**示例：**
  ```ts
  let phonenumberfmt: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN");
  let locationName: string = phonenumberfmt.getLocationName("158****2345", "zh-CN"); // locationName = "广东省湛江市"
  ```


## PhoneNumberFormatOptions<sup>8+</sup>

表示电话号码格式化对象可设置的属性。

**系统能力**：SystemCapability.Global.I18n

| 名称   | 类型     | 可读   | 可写   | 说明                                       |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | 是    | 是    | 表示对电话号码格式化的类型，取值范围："E164",&nbsp;"INTERNATIONAL",&nbsp;"NATIONAL",&nbsp;"RFC3966"。<br>-在API version 8版本，type为必填项。 <br>-API version 9版本开始，type为选填项。|


## UnitInfo<sup>8+</sup>

度量衡单位信息。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型     | 可读   | 可写   | 说明                                       |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| unit          | string | 是    | 是    | 单位的名称，如："meter",&nbsp;"inch",&nbsp;"cup"等。 |
| measureSystem | string | 是    | 是    | 单位的度量体系，取值包括："SI",&nbsp;"US",&nbsp;"UK"。 |


## getInstance<sup>8+</sup>

getInstance(locale?:string): IndexUtil

创建并返回IndexUtil对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                           |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | 否    | 区域设置信息字符串，包括语言以及可选的脚本和区域。默认值：系统Locale。 |

**返回值：**

| 类型                       | 说明                    |
| ------------------------ | --------------------- |
| [IndexUtil](#indexutil8) | locale对应的IndexUtil对象。 |

**示例：**
  ```ts
  let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");
  ```


## IndexUtil<sup>8+</sup>


### getIndexList<sup>8+</sup>

getIndexList(): Array&lt;string&gt;

获取当前区域对应的索引列表。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明                 |
| ------------------- | ------------------ |
| Array&lt;string&gt; | 返回当前locale对应的索引列表。 |

**示例：**
  ```ts
  let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");
  // indexList = [ "...", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
  //              "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "..." ]
  let indexList: Array<string> = indexUtil.getIndexList();
  ```


### addLocale<sup>8+</sup>

addLocale(locale: string): void

在当前索引列表中添加新的区域。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                           |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | 是    | 区域设置信息的字符串，包括语言以及可选的脚本和区域。 |

**示例：**
  ```ts
  let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");
  indexUtil.addLocale("en-US");
  ```


### getIndex<sup>8+</sup>

getIndex(text: string): string

获取text对应的索引。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明           |
| ---- | ------ | ---- | ------------ |
| text | string | 是    | 待计算索引值的输入文本。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| string | 输入文本对应的索引值。 |

**示例：**
  ```ts
  let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");
  let index: string = indexUtil.getIndex("hi");  // index = "H"
  ```


## I18n.getLineInstance<sup>8+</sup>

getLineInstance(locale: string): BreakIterator

获取一个用于断句的[BreakIterator](#breakiterator8)对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | 是    | 合法的locale值，例如zh-Hans-CN。生成的[BreakIterator](#breakiterator8)将按照locale所指定的区域的规则来进行断句。 |

**返回值：**

| 类型                               | 说明          |
| -------------------------------- | ----------- |
| [BreakIterator](#breakiterator8) | 用于进行断句的处理器。 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  ```


## BreakIterator<sup>8+</sup>


### setLineBreakText<sup>8+</sup>

setLineBreakText(text: string): void

设置BreakIterator要处理的文本。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明                      |
| ---- | ------ | ---- | ----------------------- |
| text | string | 是    | 指定BreakIterator进行断句的文本。 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit."); // 设置短句文本
  ```


### getLineBreakText<sup>8+</sup>

getLineBreakText(): string

获取BreakIterator当前处理的文本。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                     |
| ------ | ---------------------- |
| string | BreakIterator对象正在处理的文本 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let breakText: string = iterator.getLineBreakText(); // breakText = "Apple is my favorite fruit."
  ```


### current<sup>8+</sup>

current(): number

获取BreakIterator对象在当前处理的文本中的位置。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                          |
| ------ | --------------------------- |
| number | BreakIterator在当前所处理的文本中的位置。 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let currentPos: number = iterator.current(); // currentPos = 0
  ```


### first<sup>8+</sup>

first(): number

将BreakIterator对象设置到第一个可断句的分割点。第一个分割点总是被处理的文本的起始位置。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                |
| ------ | ----------------- |
| number | 被处理文本的第一个分割点的偏移量。 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let firstPos: number = iterator.first(); // firstPos = 0
  ```


### last<sup>8+</sup>

last(): number

将BreakIterator对象的位置设置到最后一个可断句的分割点。最后一个分割点总是被处理文本末尾的下一个位置。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| number | 被处理的文本的最后一个分割点的偏移量 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let lastPos: number = iterator.last(); // lastPos = 27
  ```


### next<sup>8+</sup>

next(index?: number): number

将BreakIterator向后移动相应个分割点。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| index | number | 否    | BreakIterator将要移动的分割点数。正数代表向后移动，即将BreakIterator向后移动number个可断句的分割点；负数代表向前移动，即向前移动相应个分割点。默认值：1。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 返回移动了index个分割点后，当前BreakIterator在文本中的位置。若移动index个分割点后超出了所处理的文本的长度范围，返回-1。 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(); // pos = 6
  pos = iterator.next(10); // pos = -1
  ```


### previous<sup>8+</sup>

previous(): number

将BreakIterator向前移动一个分割点。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 返回移动到前一个分割点后，当前BreakIterator在文本中的位置。若移动index个分割点后超出了所处理的文本的长度范围，返回-1。 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(3); // pos = 12
  pos = iterator.previous(); // pos = 9
  ```


### following<sup>8+</sup>

following(offset: number): number

将BreakIterator设置到指定位置的后面一个分割点。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| offset | number | 是    | 将BreakIterator设置到指定位置的后面一个分割点。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 返回BreakIterator移动后的位置，如果由offset所指定的位置的下一个分割点超出了文本的范围则返回-1。 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.following(0); // pos = 6
  pos = iterator.following(100); // pos = -1
  pos = iterator.current(); // pos = 27
  ```


### isBoundary<sup>8+</sup>

isBoundary(offset: number): boolean

判断文本指定位置是否为分割点。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明          |
| ------ | ------ | ---- | ----------- |
| offset | number | 是    | 若offset指定的文本位置是一个分割点，则返回true，否则返回false。返回true时，将BreakIterator对象移动到offset指定的位置，否则相当于调用following。 |

**返回值：**

| 类型      | 说明                              |
| ------- | ------------------------------- |
| boolean | 如果是一个分割点返回true,&nbsp;否则返回false。 |

**示例：**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let isBoundary: boolean = iterator.isBoundary(0); // isBoundary = true;
  isBoundary = iterator.isBoundary(5); // isBoundary = false;
  ```


## I18n.getTimeZone<sup>7+</sup>

getTimeZone(zoneID?: string): TimeZone

获取时区ID对应的时区对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| zondID | string | 否    | 时区ID。默认值：系统时区。 |

**返回值：**

| 类型       | 说明           |
| -------- | ------------ |
| [TimeZone](#timezone) | 时区ID对应的时区对象。 |

**示例：**
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
  ```


## TimeZone


### getID

getID(): string

获取时区对象的ID。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 时区对象对应的时区ID。 |

**示例：**
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
  let timezoneID: string = timezone.getID(); // timezoneID = "Asia/Shanghai"
  ```


### getDisplayName

getDisplayName(locale?: string, isDST?: boolean): string

获取时区对象的本地化表示。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型      | 必填   | 说明                   |
| ------ | ------- | ---- | -------------------- |
| locale | string  | 否    | 区域ID。默认值：系统Locale。                |
| isDST  | boolean | 否    | 时区对象本地化表示时是否考虑夏令时。默认值：false。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 时区对象在指定区域的表示。 |

**示例：**
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
  let timezoneName: string = timezone.getDisplayName("zh-CN", false); // timezoneName = "中国标准时间"
  ```


### getRawOffset

getRawOffset(): number

获取时区对象表示的时区与UTC时区的偏差。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| number | 时区对象表示的时区与UTC时区的偏差。 |

**示例：**
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
  let offset: number = timezone.getRawOffset(); // offset = 28800000
  ```


### getOffset

getOffset(date?: number): number

获取某一时刻时区对象表示的时区与UTC时区的偏差。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明     |
| ------ | ------ | ---- | ------ |
| date | number | 否    | 待计算偏差的时刻 |

**返回值：**

| 类型     | 说明                      |
| ------ | ----------------------- |
| number | 某一时刻时区对象表示的时区与UTC时区的偏差。默认值：系统时间。 |

**示例：**
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
  let offset: number = timezone.getOffset(1234567890); // offset = 28800000
  ```


### getAvailableIDs<sup>9+</sup>

static getAvailableIDs(): Array&lt;string&gt;

获取系统支持的时区ID。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明          |
| ------------------- | ----------- |
| Array&lt;string&gt; | 系统支持的时区ID列表 |

**示例：**
  ```ts
  // ids = ["America/Adak", "America/Anchorage", "America/Bogota", "America/Denver", "America/Los_Angeles", "America/Montevideo", "America/Santiago", "America/Sao_Paulo", "Asia/Ashgabat", "Asia/Hovd", "Asia/Jerusalem", "Asia/Magadan", "Asia/Omsk", "Asia/Shanghai", "Asia/Tokyo", "Asia/Yerevan", "Atlantic/Cape_Verde", "Australia/Lord_Howe", "Europe/Dublin", "Europe/London", "Europe/Moscow", "Pacific/Auckland", "Pacific/Easter", "Pacific/Pago-Pago"], 当前共支持24个时区
  let ids: Array<string> = I18n.TimeZone.getAvailableIDs();
  ```


### getAvailableZoneCityIDs<sup>9+</sup>

static getAvailableZoneCityIDs(): Array&lt;string&gt;

获取系统支持的时区城市ID。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Array&lt;string&gt; | 系统支持的时区城市ID列表 |

**示例：**
  ```ts
  // cityIDs = ["Auckland", "Magadan", "Lord Howe Island", "Tokyo", "Shanghai", "Hovd", "Omsk", "Ashgabat", "Yerevan", "Moscow", "Tel Aviv", "Dublin", "London", "Praia", "Montevideo", "Brasília", "Santiago", "Bogotá", "Easter Island", "Salt Lake City", "Los Angeles", "Anchorage", "Adak", "Pago Pago"]，当前共支持24个时区城市
  let cityIDs: Array<string> = I18n.TimeZone.getAvailableZoneCityIDs();
  ```


### getCityDisplayName<sup>9+</sup>

static getCityDisplayName(cityID: string, locale: string): string

获取某时区城市在该区域的本地化显示。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明     |
| ------ | ------ | ---- | ------ |
| cityID | string | 是    | 时区城市ID |
| locale | string | 是    | 区域ID   |

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| string | 时区城市在locale下的本地化显示 |

**示例：**
  ```ts
  let displayName: string = I18n.TimeZone.getCityDisplayName("Shanghai", "zh-CN"); // displayName = "上海(中国)"
  ```


### getTimezoneFromCity<sup>9+</sup>

static getTimezoneFromCity(cityID: string): TimeZone

创建某时区城市对应的时区对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明     |
| ------ | ------ | ---- | ------ |
| cityID | string | 是    | 时区城市ID |

**返回值：**

| 类型       | 说明          |
| -------- | ----------- |
| TimeZone | 时区城市对应的时区对象 |

**示例：**
  ```ts
  let timezone: I18n.TimeZone = I18n.TimeZone.getTimezoneFromCity("Shanghai");
  ```

### getTimezonesByLocation<sup>10+</sup>

static getTimezonesByLocation(longitude: number, latitude: number): Array&lt;TimeZone&gt;

创建某经纬度对应的时区对象数组。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名     | 类型     | 必填   | 说明     |
| --------- | ------ | ---- | ------ |
| longitude | number | 是    | 经度, 范围[-180, 179.9), 东经取正值, 西经取负值 |
| latitude  | number | 是    | 纬度, 范围[-90, 89.9), 北纬取正值, 南纬取负值 |

**返回值：**

| 类型       | 说明          |
| -------- | ----------- |
| Array&lt;[TimeZone](#timezone)&gt; | 时区对象的数组 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  let timezoneArray: Array<I18n.TimeZone> = I18n.TimeZone.getTimezonesByLocation(-118.1, 34.0);
  for (let i = 0; i < timezoneArray.length; i++) {
      let tzId: string = timezoneArray[i].getID();
  }
  ```


## Transliterator<sup>9+</sup>


### getAvailableIDs<sup>9+</sup>

static getAvailableIDs(): string[]

获取音译支持的ID列表。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型       | 说明         |
| -------- | ---------- |
| string[] | 音译支持的ID列表。 |

**示例：**
  ```ts
  // ids共支持671个。每一个id由使用中划线分割的两部分组成，格式为 source-destination。例如ids = ["Han-Latin","Latin-ASCII", "Amharic-Latin/BGN","Accents-Any", ...]，Han-Latin表示汉语转为译拉丁文，Amharic-Latin表示阿姆哈拉语转为拉丁文。
  // 更多使用信息可以参考ISO-15924。
  let ids: string[] = I18n.Transliterator.getAvailableIDs();
  ```


### getInstance<sup>9+</sup>

static getInstance(id: string): Transliterator

创建音译对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明       |
| ---- | ------ | ---- | -------- |
| id   | string | 是    | 音译支持的ID。 |

**返回值：**

| 类型                                 | 说明    |
| ---------------------------------- | ----- |
| [Transliterator](#transliterator9) | 音译对象。 |

**示例：**
  ```ts
  let transliterator: I18n.Transliterator = I18n.Transliterator.getInstance("Any-Latn");
  ```


### transform<sup>9+</sup>

transform(text: string): string

将输入字符串从源格式转换为目标格式。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明     |
| ---- | ------ | ---- | ------ |
| text | string | 是    | 输入字符串。 |

**返回值：**

| 类型     | 说明       |
| ------ | -------- |
| string | 转换后的字符串。 |

**示例：**
  ```ts
  let transliterator: I18n.Transliterator = I18n.Transliterator.getInstance("Any-Latn");
  let res: string = transliterator.transform("中国"); // res = "zhōng guó"
  ```


## Unicode<sup>9+</sup>


### isDigit<sup>9+</sup>

static isDigit(char: string): boolean

判断字符串char是否是数字。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                   |
| ------- | ------------------------------------ |
| boolean | 返回true表示输入的字符是数字，返回false表示输入的字符不是数字。 |

**示例：**
  ```ts
  let isdigit: boolean = I18n.Unicode.isDigit("1");  // isdigit = true
  ```


### isSpaceChar<sup>9+</sup>

static isSpaceChar(char: string): boolean

判断字符串char是否是空格符。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空格符，返回false表示输入的字符不是空格符。 |

**示例：**
  ```ts
  let isspacechar: boolean = I18n.Unicode.isSpaceChar("a");  // isspacechar = false
  ```


### isWhitespace<sup>9+</sup>

static isWhitespace(char: string): boolean

判断字符串char是否是空白符。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空白符，返回false表示输入的字符不是空白符。 |

**示例：**
  ```ts
  let iswhitespace: boolean = I18n.Unicode.isWhitespace("a");  // iswhitespace = false
  ```


### isRTL<sup>9+</sup>

static isRTL(char: string): boolean

判断字符串char是否是从右到左语言的字符。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是从右到左语言的字符，返回false表示输入的字符不是从右到左语言的字符。 |

**示例：**
  ```ts
  let isrtl: boolean = I18n.Unicode.isRTL("a");  // isrtl = false
  ```


### isIdeograph<sup>9+</sup>

static isIdeograph(char: string): boolean

判断字符串char是否是表意文字。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是表意文字，返回false表示输入的字符不是表意文字。 |

**示例：**
  ```ts
  let isideograph: boolean = I18n.Unicode.isIdeograph("a");  // isideograph = false
  ```


### isLetter<sup>9+</sup>

static isLetter(char: string): boolean

判断字符串char是否是字母。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                   |
| ------- | ------------------------------------ |
| boolean | 返回true表示输入的字符是字母，返回false表示输入的字符不是字母。 |

**示例：**
  ```ts
  let isletter: boolean = I18n.Unicode.isLetter("a");  // isletter = true
  ```


### isLowerCase<sup>9+</sup>

static isLowerCase(char: string): boolean

判断字符串char是否是小写字母。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是小写字母，返回false表示输入的字符不是小写字母。 |

**示例：**
  ```ts
  let islowercase: boolean = I18n.Unicode.isLowerCase("a");  // islowercase = true
  ```


### isUpperCase<sup>9+</sup>

static isUpperCase(char: string): boolean

判断字符串char是否是大写字母。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是大写字母，返回false表示输入的字符不是大写字母。 |

**示例：**
  ```ts
  let isuppercase: boolean = I18n.Unicode.isUpperCase("a");  // isuppercase = false
  ```


### getType<sup>9+</sup>

static getType(char: string): string

获取输入字符串的一般类别值。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| string | 输入字符的一般类别值。|

一般类别值如下，更详细的介绍可以参考Unicode标准。

| 名称 | 值 | 说明 |
| ---- | -------- | ---------- |
| U_UNASSIGNED | U_UNASSIGNED | 表示未分配和非字符代码点对应类别。 |
| U_GENERAL_OTHER_TYPES | U_GENERAL_OTHER_TYPES | 与 U_UNASSIGNED 相同。 |
| U_UPPERCASE_LETTER | U_UPPERCASE_LETTER | 表示大写字母。 |
| U_LOWERCASE_LETTER | U_LOWERCASE_LETTER | 表示小写字母。  |
| U_TITLECASE_LETTER | U_TITLECASE_LETTER | 表示首字母大写。 |
| U_MODIFIER_LETTER | U_MODIFIER_LETTER | 表示字母修饰符。 |
| U_OTHER_LETTER | U_OTHER_LETTER | 表示其它字母，不属于大写字母、小写字母、首字母大写或修饰符字母的字母。 |
| U_NON_SPACING_MARK | U_NON_SPACING_MARK | 表示非间距标记，如重音符号'，变音符号#。 |
| U_ENCLOSING_MARK | U_ENCLOSING_MARK | 表示封闭标记和能围住其它字符的标记，如圆圈、方框等。 |
| U_COMBINING_SPACING_MARK | U_COMBINING_SPACING_MARK | 表示间距标记，如元音符号[ ]。 |
| U_DECIMAL_DIGIT_NUMBER | U_DECIMAL_DIGIT_NUMBER | 表示十进制数字。 |
| U_LETTER_NUMBER | U_LETTER_NUMBER | 表示字母数字，罗马数字。 |
| U_OTHER_NUMBER | U_OTHER_NUMBER | 表示其它作为加密符号和记号的数字，非阿拉伯数字的数字表示符，如@、#、（1）、①等。 |
| U_SPACE_SEPARATOR | U_SPACE_SEPARATOR | 表示空白分隔符，如空格符、不间断空格、固定宽度的空白符。 |
| U_LINE_SEPARATOR | U_LINE_SEPARATOR | 表示行分隔符。|
| U_PARAGRAPH_SEPARATOR | U_PARAGRAPH_SEPARATOR | 表示段落分割符。 |
| U_CONTROL_CHAR | U_CONTROL_CHAR | 表示控制字符。 |
| U_FORMAT_CHAR | U_FORMAT_CHAR | 表示格式字符。 |
| U_PRIVATE_USE_CHAR | U_PRIVATE_USE_CHAR | 表示私人使用区代码点类别，例如公司 logo。 |
| U_SURROGATE | U_SURROGATE | 表示代理项，在UTF-16中用来表示补充字符的方法。 |
| U_DASH_PUNCTUATION | U_DASH_PUNCTUATION | 表示短划线标点。 |
| U_START_PUNCTUATION | U_START_PUNCTUATION | 表示开始标点，如左括号。 |
| U_END_PUNCTUATION | U_END_PUNCTUATION | 表示结束标点，如右括号。 |
| U_INITIAL_PUNCTUATION | U_INITIAL_PUNCTUATION | 表示前引号，如左双引号、左单引号。 |
| U_FINAL_PUNCTUATION | U_FINAL_PUNCTUATION | 表示后引号，如右双引号、右单引号。 |
| U_CONNECTOR_PUNCTUATION | U_CONNECTOR_PUNCTUATION | 表示连接符标点。 |
| U_OTHER_PUNCTUATION | U_OTHER_PUNCTUATION | 表示其他标点。 |
| U_MATH_SYMBOL | U_MATH_SYMBOL | 表示数学符号。 |
| U_CURRENCY_SYMBOL | U_CURRENCY_SYMBOL | 表示货币符号。 |
| U_MODIFIER_SYMBOL | U_MODIFIER_SYMBOL | 表示修饰符号。 |
| U_OTHER_SYMBOL | U_OTHER_SYMBOL | 表示其它符号。 |

**示例：**
  ```ts
  let type: string = I18n.Unicode.getType("a"); // type = "U_LOWERCASE_LETTER"
  ```

## I18NUtil<sup>9+</sup>


### unitConvert<sup>9+</sup>

static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

将fromUnit的单位转换为toUnit的单位，并根据区域与风格进行格式化。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型                     | 必填   | 说明                                       |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| fromUnit | [UnitInfo](#unitinfo8) | 是    | 需要转换的单位。                                 |
| toUnit   | [UnitInfo](#unitinfo8) | 是    | 转换成的目标单位。                                 |
| value    | number                 | 是    | 需要转换的单位的数量值。                             |
| locale   | string                 | 是    | 格式化时使用的区域参数，如：zh-Hans-CN。                |
| style    | string                 | 否    | 格式化使用的风格，取值包括："long",&nbsp;"short",&nbsp;"narrow"。默认值：short。 |

**返回值：**

| 类型     | 说明                      |
| ------ | ----------------------- |
| string | 按照toUnit的单位格式化后，得到的字符串。 |

**示例：**
  ```ts
  let fromUnit: I18n.UnitInfo = {unit: "cup", measureSystem: "US"};
  let toUnit: I18n.UnitInfo = {unit: "liter", measureSystem: "SI"};
  let res: string = I18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, "en-US", "long"); // res = 236.588 liters
  ```


### getDateOrder<sup>9+</sup>

static getDateOrder(locale: string): string

获取该区域日期中年、月、日的排列顺序。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                        |
| ------ | ------ | ---- | ------------------------- |
| locale | string | 是    | 格式化时使用的区域参数，如：zh-Hans-CN。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| string | 返回该区域年、月、日的排列顺序。 |

**示例：**
  ```ts
  let order: string = I18n.I18NUtil.getDateOrder("zh-CN");  // order = "y-L-d"
  ```


### getTimePeriodName<sup>11+</sup>

static getTimePeriodName(hour:number, locale?: string): string

获取该区域指定时间的本地化表达。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                        |
| ------ | ------ | ---- | ------------------------- |
| hour | number | 是    | 指定的时间，如：16。 |
| locale | string | 否    | 指定区域的参数，默认采用当前APP的区域，如：zh-Hans-CN。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| string | 返回该区域指定时间的本地化表达。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let name: string = I18n.I18NUtil.getTimePeriodName(2, "zh-CN");  // name = "凌晨"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call I18NUtil.getTimePeriodName failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


## Normalizer<sup>10+</sup>

### getInstance<sup>10+</sup>

static getInstance(mode: NormalizerMode): Normalizer

获取文本正则化对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                        |
| ------ | ------ | ---- | ------------------------- |
| mode | [NormalizerMode](#normalizermode10) | 是    | 文本正则化范式。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| [Normalizer](#normalizer10) | 返回指定范式的文本正则化对象。 |

**示例：**
  ```ts
  let normalizer: I18n.Normalizer = I18n.Normalizer.getInstance(I18n.NormalizerMode.NFC);
  ```


### normalize<sup>10+</sup>

normalize(text: string): string

对字符串进行正则化。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                        |
| ------ | ------ | ---- | ------------------------- |
| text | string | 是    | 待正则化的字符串。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| string | 正则化后的字符串。 |

**示例：**
  ```ts
  let normalizer: I18n.Normalizer = I18n.Normalizer.getInstance(I18n.NormalizerMode.NFC);
  let normalizedText: string = normalizer.normalize('\u1E9B\u0323'); // normalizedText = \u1E9B\u0323
  ```


## NormalizerMode<sup>10+</sup>

表示文本正则化范式的枚举。

**系统能力：** ：SystemCapability.Global.I18n

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NFC | 1 | NFC范式。 |
| NFD | 2 | NFD范式。 |
| NFKC | 3 | NFKC范式。 |
| NFKD | 4 | NFKD范式。 |


## SystemLocaleManager<sup>10+</sup>


### constructor<sup>10+</sup>

constructor()

创建SystemLocaleManager对象。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**示例：**
  ```ts
  let systemLocaleManager: I18n.SystemLocaleManager = new I18n.SystemLocaleManager();
  ```


### getLanguageInfoArray<sup>10+</sup>

getLanguageInfoArray(languages: Array&lt;string&gt;, options?: SortOptions): Array&lt;LocaleItem&gt;

获取语言排序数组。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ------------- | ---- | ------------- |
| languages | Array&lt;string&gt; | 是   | 待排序语言列表。|
| options   | [SortOptions](#sortoptions10)   | 否   | 语言排序选项。 |

**返回值：**

|       类型        |         说明          |
| ----------------- | -------------------- |
| Array&lt;[LocaleItem](#localeitem10)&gt; | 排序后的语言列表信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid  |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  // 当系统语言为zh-Hans，系统地区为CN，系统Locale为zh-Hans-CN时
  let systemLocaleManager: I18n.SystemLocaleManager = new I18n.SystemLocaleManager();
  let languages: string[] = ["zh-Hans", "en-US", "pt", "ar"];
  let sortOptions: I18n.SortOptions = {locale: "zh-Hans-CN", isUseLocalName: true, isSuggestedFirst: true};
  try {
      // 排序后的语言顺序为: [zh-Hans, en-US, pt, ar]
      let sortedLanguages: Array<I18n.LocaleItem> = systemLocaleManager.getLanguageInfoArray(languages, sortOptions);
  } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call systemLocaleManager.getLanguageInfoArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getRegionInfoArray<sup>10+</sup>

getRegionInfoArray(regions: Array&lt;string&gt;, options?: SortOptions): Array&lt;LocaleItem&gt;

获取国家或地区排序数组。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ------------- | ---- | ------------- |
| regions   | Array&lt;string&gt; | 是   | 待排序的国家或地区列表。|
| options   | [SortOptions](#sortoptions10)   | 否   | 国家或地区排序选项。默认值：locale的默认值为系统Locale，isUseLocalName的默认值为false，isSuggestedFirst的默认值为true。 |

**返回值：**

|       类型        |         说明          |
| ----------------- | -------------------- |
| Array&lt;[LocaleItem](#localeitem10)&gt; | 排序后的国家或地区列表信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid  |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  // 当系统语言为zh-Hans，系统地区为CN，系统Locale为zh-Hans-CN时
  let systemLocaleManager: I18n.SystemLocaleManager = new I18n.SystemLocaleManager();
  let regions: string[] = ["CN", "US", "PT", "EG"];
  let sortOptions: I18n.SortOptions = {locale: "zh-Hans-CN", isUseLocalName: false, isSuggestedFirst: true};
  try {
      // 排序后的地区顺序为: [CN, EG, US, PT]
      let sortedRegions: Array<I18n.LocaleItem> = systemLocaleManager.getRegionInfoArray(regions, sortOptions);
  } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call systemLocaleManager.getRegionInfoArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getTimeZoneCityItemArray<sup>10+</sup>

static getTimeZoneCityItemArray(): Array&lt;TimeZoneCityItem&gt;

获取时区城市组合信息的数组。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

|       类型        |         说明          |
| ----------------- | -------------------- |
| Array&lt;[TimeZoneCityItem](#timezonecityitem10)&gt; | 排序后的时区城市组合信息数组。 |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let timeZoneCityItemArray: Array<I18n.TimeZoneCityItem> = I18n.SystemLocaleManager.getTimeZoneCityItemArray();
    for (let i = 0; i < timeZoneCityItemArray.length; i++) {
        console.log(timeZoneCityItemArray[i].zoneId + ", " + timeZoneCityItemArray[i].cityId + ", " + timeZoneCityItemArray[i].cityDisplayName +
            ", " + timeZoneCityItemArray[i].offset + "\r\n");
    }
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call SystemLocaleManager.getTimeZoneCityItemArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## LocaleItem<sup>10+</sup>

SystemLocaleManager对语言或国家地区列表的排序结果信息项。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型            |  必填   |  说明                                   |
| --------------- | --------------- | ------ | --------------------------------------- |
| id              | string          |   是   | 语言代码或国家地区代码，如"zh"、"CN"。    |
| suggestionType  | [SuggestionType](#suggestiontype10)  |   是  | 语言或国家地区推荐类型。                  |
| displayName     | string          |  是   | id在SystemLocaleManager的Locale下的表示。|
| localName       | string          |  否   | id的本地名称。                           |

## TimeZoneCityItem<sup>10+</sup>

时区城市组合信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型             |  必填   |  说明                                   |
| --------------- | --------------- | ------  | --------------------------------------- |
| zoneId          | string          |   是    | 时区Id，例如Asia/Shanghai。              |
| cityId          | string          |   是    | 城市Id，例如Shanghai。                   |
| cityDisplayName | string          |   是    | 城市Id在系统Locale下显示的名称。          |
| offset          | int             |   是    | 时区Id的偏移量。                         |
| zoneDisplayName | string          |   是    | 时区Id在系统Locale下显示的名称。          |
| rawOffset       | int             |   否    | 时区Id的固定偏移量。                       |


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

| 名称            | 类型            |  必填 |   说明                                 |
| --------------- | --------------- | ---- | --------------------------------------- |
| locale          | string          |  否  | 区域代码，如"zh-Hans-CN"。locale属性默认值为系统Locale。    |
| isUseLocalName  | boolean         |  否  | 表示是否使用本地名称进行排序。若调用方法为getLanguageInfoArray，isUseLocalName属性默认值为true。若调用方法为getRegionInfoArray，isUseLocalName属性默认值为false。                |
| isSuggestedFirst | boolean        |  否  | 表示是否将推荐语言或国家地区在排序结果中置顶。isSuggestedFirst属性默认值为true。  |


## HolidayManager<sup>11+</sup>

### constructor<sup>11+</sup>

constructor(icsPath: String)

创建HolidayManager对象。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ------------- | ---- | ------------- |
| icsPath   | String | 是   | 在设备上有应用读取权限的iCalendar格式的ics文件路径。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid  |

**示例：**
  ```ts
  let holidayManager= new I18n.HolidayManager("/system/lib/US.ics");
  ```

### isHoliday<sup>11+</sup>

isHoliday(date?: Date): boolean;

判断指定的日期是否是节假日。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ---------------| ---- | ------------- |
| date      | Date           | 否   | JavaScript的Date对象。<br>如果没有指定日期，默认为当天。|

**返回值：**

|       类型        |         说明          |
| ----------------- | ----------------------|
| boolean           | 返回true是节假日，返回false不是节假日。 |

**示例：**
  ```ts
  try {
    let holidayManager= new I18n.HolidayManager("/system/lib/US.ics");
    let isHoliday = holidayManager.isHoliday();
    console.log(isHoliday);
    let isHoliday2 = holidayManager.isHoliday(new Date(2023,5,25));
    console.log(isHoliday2);
  } catch(error) {
    console.error(`call holidayManager.isHoliday failed, error code: ${error.code}, message: ${error.message}.`);
  }
  ```


### getHolidayInfoItemArray<sup>11+</sup>

getHolidayInfoItemArray(year?: number): Array&lt;[HolidayInfoItem](#holidayinfoitem11)&gt;

获取指定某年的节假日信息列表。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | -------------  | ---- | ------------- |
| year      | number         | 否   | 年，例如2023。<br>如果没有指定年，默认为当年。|

**返回值：**

|       类型        |         说明          |
| ----------------- | -------------------- |
| Array&lt;[HolidayInfoItem](#holidayinfoitem11)&gt; | 返回节假日信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](../errorcodes/errorcode-i18n.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 890001 | param value not valid  |

**示例：**
  ```ts
  try {
    let holidayManager= new I18n.HolidayManager("/system/lib/US.ics");
    let holidayInfoItemArray = holidayManager.getHolidayInfoItemArray(2023);
    for (let i =0 ;i < holidayInfoItemArray.length; i++) {
        console.log(JSON.stringify(holidayInfoItemArray[i]));
    }
  } catch(error) {
    console.error(`call holidayManager.getHolidayInfoItemArray failed, error code: ${error.code}, message: ${error.message}.`);
  }
  ```

## HolidayInfoItem<sup>11+</sup>

节假日信息。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型             |  必填   |  说明                                   |
| --------------- | --------------- | ------  | --------------------------------------- |
| baseName        | string          |   是    | 节假日的英文名称。              |
| year            | number          |   是    | 节假日所在年。                   |
| month           | number          |   是    | 节假日所在月。          |
| day             | number          |   是    | 节假日所在日。                         |
| localNames      | Array&lt;[HolidayLocalName](#holidaylocalname11)&gt;          |   否    | 节假日的本地名称列表。          |

## HolidayLocalName<sup>11+</sup>

节假日本地名称。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型             |  必填   |  说明                                   |
| --------------- | -----------------| ------  | --------------------------------------- |
| language        | string           |   是    | 节假日的本地语言，例如ar,en,tr。          |
| name            | string           |   是    | 节假日的本地名称，例如Sacrifice Feast(宰牲节)的土耳其语名称为Kurban Bayrami。      |


## I18n.getDisplayCountry<sup>(deprecated)</sup>

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

获取指定国家的本地化显示文本。

从API version 9开始不再维护，建议使用[System.getDisplayCountry](#getdisplaycountry9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | 是    | 指定国家。            |
| locale       | string  | 是    | 显示指定国家的区域ID。     |
| sentenceCase | boolean | 否    | 本地化显示文本是否要首字母大写。默认值：true。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 指定国家的本地化显示文本。 |

**示例：**
  ```ts
  let countryName: string = I18n.getDisplayCountry("zh-CN", "en-GB", true); // countryName = true
  countryName = I18n.getDisplayCountry("zh-CN", "en-GB"); // countryName = true
  ```


## I18n.getDisplayLanguage<sup>(deprecated)</sup>

getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

获取指定语言的本地化显示文本。

从API version 9开始不再维护，建议使用[System.getDisplayLanguage](#getdisplaylanguage9)代替。

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

**示例：**
  ```ts
  let languageName: string = I18n.getDisplayLanguage("zh", "en-GB", true); // languageName = "Chinese"
  languageName = I18n.getDisplayLanguage("zh", "en-GB"); // languageName = "Chinese"
  ```


## I18n.getSystemLanguage<sup>(deprecated)</sup>

getSystemLanguage(): string

获取系统语言。

从API version 9开始不再维护，建议使用[System.getSystemLanguage](#getsystemlanguage9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统语言ID。 |

**示例：**
  ```ts
  let systemLanguage: string = I18n.getSystemLanguage(); // 返回当前系统语言
  ```


## I18n.getSystemRegion<sup>(deprecated)</sup>

getSystemRegion(): string

获取系统地区。

从API version 9开始不再维护，建议使用[System.getSystemRegion](#getsystemregion9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统地区ID。 |

**示例：**
  ```ts
  let region: string = I18n.getSystemRegion(); // 返回当前系统地区
  ```


## I18n.getSystemLocale<sup>(deprecated)</sup>

getSystemLocale(): string

获取系统区域。

从API version 9开始不再维护，建议使用[System.getSystemLocale](#getsystemlocale9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统区域ID。 |

**示例：**
  ```ts
  let locale: string = I18n.getSystemLocale(); // 返回系统Locale
  ```


## I18n.is24HourClock<sup>(deprecated)</sup>

is24HourClock(): boolean

判断系统时间是否为24小时制。

从API version 9开始不再维护，建议使用[System.is24HourClock](#is24hourclock9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true，表示系统24小时开关开启；返回false，表示系统24小时开关关闭。 |

**示例：**
  ```ts
  let is24HourClock: boolean = I18n.is24HourClock();
  ```


## I18n.set24HourClock<sup>(deprecated)</sup>

set24HourClock(option: boolean): boolean

修改系统时间的24小时制设置。

从API version 9开始不再维护，建议使用[System.set24HourClock](#set24hourclock9)代替。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型      | 必填   | 说明                                       |
| ------ | ------- | ---- | ---------------------------------------- |
| option | boolean | 是    | option为true，表示开启系统24小时制开关；返回false，表示关闭系统24小时开关。 |

**返回值：**

| 类型      | 说明                            |
| ------- | ----------------------------- |
| boolean | 返回true，表示修改成功；返回false，表示修改失败。 |

**示例：**
  ```ts
  // 将系统时间设置为24小时制
  let success: boolean = I18n.set24HourClock(true);
  ```


## I18n.addPreferredLanguage<sup>(deprecated)</sup>

addPreferredLanguage(language: string, index?: number): boolean

在系统偏好语言列表中的指定位置添加偏好语言。

从API version 8开始支持，从API version 9开始不再维护，建议使用[System.addPreferredLanguage](#addpreferredlanguage9)代替。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明         |
| -------- | ------ | ---- | ---------- |
| language | string | 是    | 待添加的偏好语言。  |
| index    | number | 否    | 偏好语言的添加位置。默认值：系统偏好语言列表长度。 |

**返回值：**

| 类型      | 说明                            |
| ------- | ----------------------------- |
| boolean | 返回true，表示添加成功；返回false，表示添加失败。 |

**示例：**
  ```ts
  // 将语言zh-CN添加到系统偏好语言列表中
  let language: string = 'zh-CN';
  let index: number = 0;
  let success: boolean = I18n.addPreferredLanguage(language, index);
  ```


## I18n.removePreferredLanguage<sup>(deprecated)</sup>

removePreferredLanguage(index: number): boolean

删除系统偏好语言列表中指定位置的偏好语言。

从API version 8开始支持，从API version 9开始不再维护，建议使用[System.removePreferredLanguage](#removepreferredlanguage9)代替。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                    |
| ----- | ------ | ---- | --------------------- |
| index | number | 是    | 待删除偏好语言在系统偏好语言列表中的位置。 |

**返回值：**

| 类型      | 说明                            |
| ------- | ----------------------------- |
| boolean | 返回true，表示删除成功；返回false，表示删除失败。 |

**示例：**
  ```ts
  // 删除系统偏好语言列表中的第一个偏好语言
  let index: number = 0;
  let success: boolean = I18n.removePreferredLanguage(index);
  ```


## I18n.getPreferredLanguageList<sup>(deprecated)</sup>

getPreferredLanguageList(): Array&lt;string&gt;

获取系统偏好语言列表。

从API version 8开始支持，从API version 9开始不再维护，建议使用[System.getPreferredLanguageList](#getpreferredlanguagelist9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明        |
| ------------------- | --------- |
| Array&lt;string&gt; | 系统偏好语言列表。 |

**示例：**
  ```ts
  let preferredLanguageList: Array<string> = I18n.getPreferredLanguageList(); // 获取系统偏好语言列表
  ```


## I18n.getFirstPreferredLanguage<sup>(deprecated)</sup>

getFirstPreferredLanguage(): string

获取偏好语言列表中的第一个偏好语言。

从API version 8开始支持，从API version 9开始不再维护，建议使用[System.getFirstPreferredLanguage](#getfirstpreferredlanguage9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明             |
| ------ | -------------- |
| string | 偏好语言列表中的第一个语言。 |

**示例：**
  ```ts
  let firstPreferredLanguage: string = I18n.getFirstPreferredLanguage();
  ```


## Util<sup>(deprecated)</sup>


### unitConvert<sup>(deprecated)</sup>

static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

将fromUnit的单位转换为toUnit的单位，并根据区域与风格进行格式化。

从API version 8开始支持，从API version 9开始不再维护，建议使用[unitConvert](#unitconvert9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型                     | 必填   | 说明                                       |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| fromUnit | [UnitInfo](#unitinfo8) | 是    | 要被转换的单位。                                 |
| toUnit   | [UnitInfo](#unitinfo8) | 是    | 要转换为的单位。                                 |
| value    | number                 | 是    | 要被转换的单位的数量值。                             |
| locale   | string                 | 是    | 格式化时使用的区域参数，如：zh-Hans-CN。                |
| style    | string                 | 否    | 格式化使用的风格，取值包括："long",&nbsp;"short",&nbsp;"narrow"。默认值：short。 |

**返回值：**

| 类型     | 说明                      |
| ------ | ----------------------- |
| string | 按照toUnit的单位格式化后，得到的字符串。 |


## Character<sup>(deprecated)</sup>


### isDigit<sup>(deprecated)</sup>

static isDigit(char: string): boolean

判断字符串char是否是数字。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isDigit](#isdigit9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                   |
| ------- | ------------------------------------ |
| boolean | 返回true表示输入的字符是数字，返回false表示输入的字符不是数字。 |


### isSpaceChar<sup>(deprecated)</sup>

static isSpaceChar(char: string): boolean

判断字符串char是否是空格符。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isSpaceChar](#isspacechar9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空格符，返回false表示输入的字符不是空格符。 |


### isWhitespace<sup>(deprecated)</sup>

static isWhitespace(char: string): boolean

判断字符串char是否是空白符。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isWhitespace](#iswhitespace9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空白符，返回false表示输入的字符不是空白符。 |


### isRTL<sup>(deprecated)</sup>

static isRTL(char: string): boolean

判断字符串char是否是从右到左语言的字符。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isRTL](#isrtl9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是从右到左语言的字符，返回false表示输入的字符不是从右到左语言的字符。 |


### isIdeograph<sup>(deprecated)</sup>

static isIdeograph(char: string): boolean

判断字符串char是否是表意文字。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isIdeograph](#isideograph9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是表意文字，返回false表示输入的字符不是表意文字。 |


### isLetter<sup>(deprecated)</sup>

static isLetter(char: string): boolean

判断字符串char是否是字母。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isLetter](#isletter9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                   |
| ------- | ------------------------------------ |
| boolean | 返回true表示输入的字符是字母，返回false表示输入的字符不是字母。 |


### isLowerCase<sup>(deprecated)</sup>

static isLowerCase(char: string): boolean

判断字符串char是否是小写字母。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isLowerCase](#islowercase9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是小写字母，返回false表示输入的字符不是小写字母。 |


### isUpperCase<sup>(deprecated)</sup>

static isUpperCase(char: string): boolean

判断字符串char是否是大写字母。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isUpperCase](#isuppercase9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是大写字母，返回false表示输入的字符不是大写字母。 |


### getType<sup>(deprecated)</sup>

static getType(char: string): string

获取输入字符串的一般类别值。

从API version 8开始支持，从API version 9开始不再维护，建议使用[getType](#gettype9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| string | 输入字符的一般类别值。 |
