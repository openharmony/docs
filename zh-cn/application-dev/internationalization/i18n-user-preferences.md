# 设置用户偏好（仅对系统应用开放）

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--SE: @sunyaozu-->
<!--TSE: @lpw_work-->

## 使用场景

除区域设置和应用偏好语言设置外，系统还可以设置用户偏好，当前支持是否使用本地数字、是否使用12/24小时制两种偏好。用户偏好设置会保存到系统区域及应用偏好语言中，最终体现在用户界面的国际化特性上。

## 开发步骤

接口具体使用方法和说明请参考[setUsingLocalDigit](../reference/apis-localization-kit/js-apis-i18n-sys.md#setusinglocaldigit9)和[set24HourClock](../reference/apis-localization-kit/js-apis-i18n-sys.md#set24hourclock9)的API文档。


1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 获取应用偏好语言。
   ```ts
   // 获取应用偏好语言
   let appPreferredLanguage: string = i18n.System.getAppPreferredLanguage();
   ```

3. 设置应用界面数字。
   ```ts
   try {
     i18n.System.setUsingLocalDigit(true); // 使用本地数字
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let date: Date = new Date(2023, 9, 25); // 时间日期为2023.10.25
   let appPreferredLanguage: string = 'ar';
   let dateTimeFmt: Intl.DateTimeFormat = new Intl.DateTimeFormat(appPreferredLanguage);
   let formattedTime: string = dateTimeFmt.format(date); // formattedTime = '٢٠٢٣/١٠/٢٥'（使用阿拉伯语本地数字表示）
   ```

4. 设置格式化的24小时制。
   ```ts
   try {
     i18n.System.set24HourClock(true); // 设置系统时制为24小时制
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let date: Date = new Date(2023, 9, 25, 16, 48, 0); // 时间日期为2023.10.25 16:48:00
   let appPreferredLanguage: string = 'zh';
   let dateTimeFmt: Intl.DateTimeFormat = new Intl.DateTimeFormat(appPreferredLanguage, { timeStyle: 'medium' });
   let formattedTime: string = dateTimeFmt.format(date); // formattedTime = '16:48:00'
   ```
