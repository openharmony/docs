# @ohos.i18n (国际化-I18n)(系统接口)

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

### setSystemLanguage<sup>9+</sup>

static setSystemLanguage(language: string): void

设置系统语言。

若要监听系统语言变化，可以监听[事件](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_locale_changed)OHOS::EventFwk::CommonEventSupport::COMMON_EVENT_LOCALE_CHANGED。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明    |
| -------- | ------ | ---- | ----- |
| language | string | 是    | 合法的语言ID。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError, commonEventManager } from '@kit.BasicServicesKit';

  // 设置系统语言
  try {
    i18n.System.setSystemLanguage('zh'); // 设置系统当前语言为 "zh"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
 
  // 订阅公共事件
  let subscriber: commonEventManager.CommonEventSubscriber; // 用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
  let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = { // 订阅者信息
    events: [commonEventManager.Support.COMMON_EVENT_LOCALE_CHANGED]
  };
  commonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber:commonEventManager.CommonEventSubscriber) => { // 创建订阅者
      console.info("createSubscriber");
      subscriber = commonEventSubscriber;
      commonEventManager.subscribe(subscriber, (err, data) => {
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



### setSystemLocale<sup>9+</sup>

static setSystemLocale(locale: string): void

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
| language | string | 是    | 待添加的偏好语言，要求是合法的语言ID。  |
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


## SystemLocaleManager<sup>10+</sup>

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
| languages | Array&lt;string&gt; | 是   | 待排序的语言列表，要求是合法的语言ID。|
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
        console.log(timeZoneCityItemArray[i].zoneId + ", " + timeZoneCityItemArray[i].cityId + ", " + timeZoneCityItemArray[i].cityDisplayName +
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

| 名称            | 类型            |  必填   |  说明                                   |
| --------------- | --------------- | ------ | --------------------------------------- |
| id              | string          |   是   | 语言代码或国家地区代码，如"zh"、"CN"。    |
| suggestionType  | [SuggestionType](#suggestiontype10)  |   是  | 语言或国家地区推荐类型。                  |
| displayName     | string          |  是   | id在SystemLocaleManager的指定区域下的表示。|
| localName       | string          |  否   | id的本地名称。                           |

## TimeZoneCityItem<sup>10+</sup>

时区城市的组合信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型             |  必填   |  说明                                   |
| --------------- | --------------- | ------  | --------------------------------------- |
| zoneId          | string          |   是    | 时区ID，例如Asia/Shanghai。              |
| cityId          | string          |   是    | 城市ID，例如Shanghai。                   |
| cityDisplayName | string          |   是    | 城市ID在系统区域下显示的名称。          |
| offset          | int             |   是    | 时区ID的偏移量。                         |
| zoneDisplayName | string          |   是    | 时区ID在系统区域下显示的名称。          |
| rawOffset       | int             |   否    | 时区ID的固定偏移量。                       |


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
| locale          | string          |  否  | [表示区域ID的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成，如"zh-Hans-CN"。<br>默认值：系统当前区域ID。    |
| isUseLocalName  | boolean         |  否  | true表示使用本地名称进行排序，false表示不使用本地名称进行排序。<br>若调用方法为getLanguageInfoArray，isUseLocalName属性默认值为true。<br>若调用方法为getRegionInfoArray，isUseLocalName属性默认值为false。                |
| isSuggestedFirst | boolean        |  否  | true表示将推荐语言或国家地区在排序结果中置顶，false表示不将推荐语言或国家地区在排序结果中置顶。<br>默认值：true。  |
