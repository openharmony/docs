# 电话号码格式化

## 使用场景

不同国家和地区的电话号码在号码位数、组合方式、呈现方式等都存在差异。同时，在不同环境和条件下，电话号码可能存在不同的拨打方式和号码格式。例如，在中国境内跨地区打电话，通常需要先输入“0”，再拨打区号和八位电话号码，而在香港或澳门拨打电话时，需要不同的拨号方式。

通过号码格式化，可以根据需要给用户展示特定格式的电话号码。

## 开发步骤

电话号码格式化通过[PhoneNumberFormat](../reference/apis-localization-kit/js-apis-i18n.md#phonenumberformat8)的[format](../reference/apis-localization-kit/js-apis-i18n.md#format8)接口实现，具体开发步骤如下。

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 创建PhoneNumberFormat对象。

   构造函数支通过PhoneNumberFormatOptions设置不同的电话号码格式，具体请参考表1。

   ```ts
   let phoneNumberFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat(country: string, options?: PhoneNumberFormatOptions);
   ```

3. 电话号码格式化。
   ```ts
   let formattedPhoneNumber: string = phoneNumberFormat.format(phoneNumber: string);
   ```

4. 判断电话号码正确性和号码归属地。
   ```ts
   let isValidNumber: boolean = phoneNumberFormat.isValidNumber(phoneNumber: string); // 判断电话号码正确性
   let locationName: string = phoneNumberFormat.getLocationName(number: string, locale: string); // 获取号码归属地
   ```

**电话号码格式化选项**

以电话号码158\*\*\*\*2312，所属国家代码CN为例，说明PhoneNumberFormatOptions不同取值和显示效果。

**表1** 电话号码格式化的类型(type)

| 取值 | 显示效果 | 
| -------- | -------- |
| E164 | +86 158\*\*\*\*2312 | 
| INTERNATIONAL | +86 158 \*\*\*\* 2312 | 
| NATIONAL | 158 \*\*\*\* 2312 | 
| RFC3966 | tel:+86-158-\*\*\*\*-2312 |
| TYPING | 158 \*\*\* |


**开发实例**

```ts
// 导入模块
import { i18n } from '@kit.LocalizationKit';

// 格式化电话号码
let phoneNumberFormat1 = new i18n.PhoneNumberFormat('CN');
let formattedPhoneNumber1 = phoneNumberFormat1.format('158****2312'); // formattedPhoneNumber1: 158 **** 2312

// RFC3966类型的电话号码
let phoneNumberFormat2 = new i18n.PhoneNumberFormat('CN', {type: 'RFC3966'});
let formattedPhoneNumber2 = phoneNumberFormat2.format('158****2312'); // formattedPhoneNumber2: tel:+86-158-****-2312

// 判断电话号码是否有效
let phoneNumberFormat3 = new i18n.PhoneNumberFormat('CN');
let isValid = phoneNumberFormat3.isValidNumber('158****2312'); // isValid: true

// 以某种语言显示号码归属地
let phoneNumberFormat4 = new i18n.PhoneNumberFormat("CN");
let locationName4 = phoneNumberFormat4.getLocationName('158****2312', 'en-GB') // locationName4: XiAn, Shanxi

// 拨号中的电话号码格式化
let phoneNumberFmt = new i18n.PhoneNumberFormat('CN', {type: 'TYPING'});
let phoneNumber : string = "0755453";
let formatResult : string = "";
for (let i = 0; i < phoneNumber.length; i++) {
  formatResult += phoneNumber.charAt(i);
  formatResult = phoneNumberFmt.format(formatResult);
}
console.log(formatResult); // formatResult: 0755 453
```
