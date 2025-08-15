# 设置用户偏好（仅对系统应用开放）

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

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

3. 设置使用本地数字。
   ```ts
   try {
     i18n.System.setUsingLocalDigit(true); // 使用本地数字
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let usingLocalDigit: boolean = i18n.System.getUsingLocalDigit(); // usingLocalDigit = true
   ```

4. 设置时间显示格式为24小时制。
   ```ts
   try {
     i18n.System.set24HourClock(true); // 设置系统时制为24小时制
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let is24HourClock: boolean = i18n.System.is24HourClock(); // is24HourClock = true
   ```
