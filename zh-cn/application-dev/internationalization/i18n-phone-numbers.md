# 电话号码格式化

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

## 功能介绍

不同国家和地区的电话号码在号码位数、组合方式、呈现方式等都存在差异。同时，在不同环境和条件下，电话号码可能存在不同的拨打方式和号码格式。例如，在中国境内跨地区打电话，通常需要先输入“0”，再拨打区号和八位电话号码，而在香港或澳门拨打电话时，需要不同的拨号方式。

通过号码格式化，可以根据需要给用户展示特定格式的电话号码。

## 开发步骤

电话号码格式化通过[PhoneNumberFormat](../reference/apis-localization-kit/js-apis-i18n.md#phonenumberformat8)的[format](../reference/apis-localization-kit/js-apis-i18n.md#format8)接口实现。

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

1. 导入模块。

   <!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/PhoneNumberFormatting.ets) -->
   
   ``` TypeScript
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 处理号码。

   <!-- @[format_phone_numbers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/PhoneNumberFormatting.ets) -->
   
   ``` TypeScript
   // 格式化电话号码
   let phoneNumberFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN');
   let formattedPhoneNumber = phoneNumberFormat.format('158****2312'); // formattedPhoneNumber = '158 **** 2312'
   
   // RFC3966类型的电话号码
   let rfcFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN', { type: 'RFC3966' });
   let formattedRFCPhoneNumber = rfcFormat.format('158****2312'); // formattedRFCPhoneNumber = 'tel:+86-158-****-2312'
   
   // 判断电话号码是否有效
   let isValid = phoneNumberFormat.isValidNumber('158****2312'); // isValid = true
   
   // 以某种语言显示号码归属地
   let locationName = phoneNumberFormat.getLocationName('158****2312', 'en-GB'); // locationName = 'XiAn, Shanxi'
   
   // 拨号中的电话号码格式化
   let typingFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN', { type: 'TYPING' });
   let phoneNumber = '0755453';
   let formatResult = ''; // 通过如下方式对拨号中的号码格式化后，formatResult = '0755 453'
   for (let i = 0; i < phoneNumber.length; i++) {
     formatResult += phoneNumber.charAt(i);
     formatResult = typingFormat.format(formatResult);
   }
   ```
