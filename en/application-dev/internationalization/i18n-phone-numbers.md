# Phone Number Formatting

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=1a7fdda7cb0bdacc6b1c367c8fd0def17530cd88 translatedAt=2026-08-15T01:53:22.793Z pushedAt=2026-08-15T08:42:11.963Z -->

## Function Description

The number of digits, combination mode, and display mode of phone numbers vary according to countries and regions. Besides, the dialing mode and number format may also differ under different situations. For example, to make a cross-area call in Chinese mainland, you usually need to type **0** and then dial the area code plus an 8-digit phone number. To make a call in Hong Kong or Macao, you need to dial the number in a different way.

Through phone number formatting, your application will be able to present phone numbers to users in their expected format.

## How to Develop

Phone number formatting is implemented through the [format](../reference/apis-localization-kit/js-apis-i18n.md#format8) API of the [PhoneNumberFormat](../reference/apis-localization-kit/js-apis-i18n.md#phonenumberformat8) class.

**Phone Number Formatting Options**

The following uses the phone number **158\*\*\*\*2312** and the country code **CN** as an example to show the values of **PhoneNumberFormatOptions** and corresponding display effects.

**Table 1** Phone number formatting type (type)

| Value| Display Effect| 
| -------- | -------- |
| E164 | +86 158\*\*\*\*2312 | 
| INTERNATIONAL | +86 158 \*\*\*\* 2312 | 
| NATIONAL | 158 \*\*\*\* 2312 | 
| RFC3966 | tel:+86-158-\*\*\*\*-2312 |
| TYPING | 158 \*\*\* |

**Development Example**

1. Import the required module.

   <!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/PhoneNumberFormatting.ets) -->

   ``` TypeScript
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Process the phone number.

   <!-- @[format_phone_numbers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/PhoneNumberFormatting.ets) -->

   ``` TypeScript
   // Format the phone number.
   let phoneNumberFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN');
   let formattedPhoneNumber = phoneNumberFormat.format('158****2312'); // formattedPhoneNumber = '158 **** 2312'

   // Phone number in RFC3966 format.
   let rfcFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN', { type: 'RFC3966' });
   let formattedRFCPhoneNumber = rfcFormat.format('158****2312'); // formattedRFCPhoneNumber = 'tel:+86-158-****-2312'

   // Check whether the phone number is valid.
   let isValid = phoneNumberFormat.isValidNumber('158****2312'); // isValid = true

   // Display the phone number location in a specific language.
   let locationName = phoneNumberFormat.getLocationName('158****2312', 'en-GB'); // locationName = 'XiAn, Shanxi'

   // Format the phone number during dialing.
   let typingFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN', { type: 'TYPING' });
   let phoneNumber = '0755453';
   let formatResult = ''; // After formatting the dialing number as follows, formatResult = '0755 453'
   for (let i = 0; i < phoneNumber.length; i++) {
     formatResult += phoneNumber.charAt(i);
     formatResult = typingFormat.format(formatResult);
   }
   ```