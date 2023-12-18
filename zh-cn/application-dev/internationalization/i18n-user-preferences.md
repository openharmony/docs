# 设置用户偏好

## 使用场景

除区域设置和应用偏好语言设置外，系统还可以设置用户偏好，当前支持是否使用本地数字、是否使用12/24小时制两种偏好。用户偏好设置会保存到系统区域标识及应用偏好语言中，最终体现在用户界面的国际化特性上。

## 开发步骤

接口具体使用方法和说明请参考[setUsingLocalDigit](../reference/apis/js-apis-i18n.md#setusinglocaldigit9)和[set24HourClock](../reference/apis/js-apis-i18n.md#set24hourclock9)的API文档。


1. 导入模块。
   ```ts
   import Intl from '@ohos.intl';
   import I18n from '@ohos.i18n';
   import { BusinessError } from '@ohos.base';
   ```

2. 获取应用偏好语言。
   ```ts
   try {
     // 获取应用偏好语言，假设当前偏好语言为 ar
     let appPreferredLanguage: string = I18n.System.getAppPreferredLanguage();
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.getAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
   } 
   ```

3. 设置应用界面数字。
   ```ts
   try {  
     I18n.System.setUsingLocalDigit(true); // 打开本地化数字开关
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let date = new Date(2023, 9, 25);
   let dateTimeFmt = new Intl.DateTimeFormat(appPreferredLanguage);
   let result = dateTimeFmt.format(date); // result = "٢٠٢٣/١٠/٢٥"（采用阿语本地数字表示）
   ```

4. 设置格式化的24小时制。
   ```ts
   try {  
     I18n.System.set24HourClock(true); // true表示打开24小时制开关，false表示打开12小时制开关
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let date = new Date(2023, 9, 25, 16, 48, 0);
   let dateTimeFmt = new Intl.DateTimeFormat(appPreferredLanguage, { timeStyle: "medium" });
   let result = dateTimeFmt.format(date); // result = "16:48:00"
   ```
