# @ohos.i18n    
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import i18n from '@ohos.i18n'    
```  
    
## System<sup>(9+)</sup>    
获取指定国家的本地化显示文本  
  
 **系统能力:**  SystemCapability.Global.I18n    
### setSystemLanguage<sup>(9+)</sup>    
设置系统语言。当前调用该接口不支持系统界面语言的实时刷新。  
 **调用形式：**     
- static setSystemLanguage(language: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| language | string | true | 语言ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
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
  
    
### setSystemRegion<sup>(9+)</sup>    
设置系统区域。  
 **调用形式：**     
- static setSystemRegion(region: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| region | string | true | 地区ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  I18n.System.setSystemRegion('CN');  // 设置系统当前地区为 "CN"  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.setSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### setSystemLocale<sup>(9+)</sup>    
设置系统Locale。  
 **调用形式：**     
- static setSystemLocale(locale: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locale | string | true | 指定区域ID，例如zh-CN。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  I18n.System.setSystemLocale('zh-CN');  // 设置系统当前Locale为 "zh-CN"  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.setSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### set24HourClock<sup>(9+)</sup>    
设置系统时间为24小时。  
 **调用形式：**     
- static set24HourClock(option: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | boolean | true | option为true，表示开启系统24小时制开关；返回false，表示关闭系统24小时开关。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
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
  
    
### addPreferredLanguage<sup>(9+)</sup>    
在系统偏好语言列表中的指定位置添加偏好语言。  
 **调用形式：**     
- static addPreferredLanguage(language: string, index?: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| language | string | true | 待添加的偏好语言。 |  
| index | number | false | 偏好语言的添加位置。默认值：系统偏好语言列表长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
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
  
    
### removePreferredLanguage<sup>(9+)</sup>    
删除系统偏好语言列表中指定位置的偏好语言。  
 **调用形式：**     
- static removePreferredLanguage(index: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 待删除偏好语言在系统偏好语言列表中的位置。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
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
  
    
### setUsingLocalDigit<sup>(9+)</sup>    
设置系统是否使用本地数字。  
 **调用形式：**     
- static setUsingLocalDigit(flag: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| flag | boolean | true | true表示打开本地数字开关，false表示关闭本地数字开关。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  I18n.System.setUsingLocalDigit(true); // 打开本地化数字开关  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
## SuggestionType<sup>(10+)</sup>    
语言或国家地区的推荐类型。    
    
 **系统能力:**  SystemCapability.Global.I18n    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUGGESTION_TYPE_NONE | 0 | 非推荐语言或国家地区。 |  
| SUGGESTION_TYPE_RELATED | 1 | 系统语言推荐的国家地区或系统国家地区推荐的语言。 |  
| SUGGESTION_TYPE_SIM | 2 | Sim卡国家地区推荐的语言。 |  
    
## SortOptions<sup>(10+)</sup>    
语言或国家地区排序选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| locale<sup>(10+)</sup> | string | false | false | 区域代码，如"zh-Hans-CN"。locale属性默认值为系统Locale。  |  
| isUseLocalName<sup>(10+)</sup> | boolean | false | false | 表示是否使用本地名称进行排序。若调用方法为getLanguageInfoArray，isUseLocalName属性默认值为true。若调用方法为getRegionInfoArray，isUseLocalName属性默认值为false。 |  
| isSuggestedFirst<sup>(10+)</sup> | boolean | false | false | 表示是否将推荐语言或国家地区在排序结果中置顶。isSuggestedFirst属性默认值为true。 |  
    
## LocaleItem<sup>(10+)</sup>    
SystemLocaleManager对语言或国家地区列表的排序结果信息项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id<sup>(10+)</sup> | string | false | true | 语言代码或国家地区代码，如"zh"、"CN"。  |  
| suggestionType<sup>(10+)</sup> | SuggestionType | false | true | 语言或国家地区推荐类型。   |  
| displayName<sup>(10+)</sup> | string | false | true | id在SystemLocaleManager的Locale下的表示。 |  
| localName<sup>(10+)</sup> | string | false | false | id的本地名称。  |  
    
## TimeZoneCityItem<sup>(10+)</sup>    
时区城市组合信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| zoneId<sup>(10+)</sup> | string | false | true | 时区Id，例如Asia/Shanghai。 |  
| cityId<sup>(10+)</sup> | string | false | true | 城市Id，例如Shanghai。 |  
| cityDisplayName<sup>(10+)</sup> | string | false | true | 城市Id在系统Locale下显示的名称。 |  
| offset<sup>(10+)</sup> | number | false | true | 时区Id的偏移量。 |  
| zoneDisplayName<sup>(10+)</sup> | string | false | true | 时区Id在系统Locale下显示的名称。 |  
| rawOffset<sup>(10+)</sup> | number | false | false | 时区Id的固定偏移量。 |  
    
## SystemLocaleManager<sup>(10+)</sup>  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n    
### getLanguageInfoArray<sup>(10+)</sup>    
获取语言排序数组。  
 **调用形式：**     
- getLanguageInfoArray(languages: Array\<string>, options?: SortOptions): Array\<LocaleItem>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| languages | Array<string> | true | 待排序语言列表 |  
| options | SortOptions | false | 语言排序选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<LocaleItem> | 排序后的语言列表信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 |  |  
    
 **示例代码：**   
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
  
    
### getRegionInfoArray<sup>(10+)</sup>    
获取国家或地区排序数组。  
 **调用形式：**     
- getRegionInfoArray(regions: Array\<string>, options?: SortOptions): Array\<LocaleItem>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| regions | Array<string> | true | 待排序的国家或地区列表。 |  
| options | SortOptions | false | 国家或地区排序选项。默认值：locale的默认值为系统Locale，isUseLocalName的默认值为false，isSuggestedFirst的默认值为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<LocaleItem> | 排序后的国家或地区列表信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
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
  
    
### getTimeZoneCityItemArray<sup>(10+)</sup>    
获取时区城市组合信息的数组。  
 **调用形式：**     
- static getTimeZoneCityItemArray(): Array\<TimeZoneCityItem>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<TimeZoneCityItem> | 排序后的时区城市组合信息数组。 |  
    
 **示例代码：**   
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
  
