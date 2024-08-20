# Phone Number Formatting

## Use Cases

The number of digits, combination mode, and display mode of phone numbers vary according to countries and regions. Besides, the dialing mode and number format may also differ under different situations. For example, to make a cross-area call in Chinese mainland, you usually need to type **0** and then dial the area code plus an 8-digit phone number. To make a call in Hong Kong or Macao, you need to dial the number in a different way.

Through phone number formatting, your application will be able to present phone numbers to users in their expected format.

## How to Develop

Phone number formatting is implemented through the [format](../reference/apis-localization-kit/js-apis-i18n.md#format8) API of the [PhoneNumberFormat](../reference/apis-localization-kit/js-apis-i18n.md#phonenumberformat8) class. The development procedure is as follows:

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Create a **PhoneNumberFormat** object.

   You can set different phone number formats through **PhoneNumberFormatOptions**. For details, see Table 1.

   ```ts
   let phoneNumberFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat(country: string, options?: PhoneNumberFormatOptions);
   ```

3. Format a phone number.
   ```ts
   let formattedPhoneNumber: string = phoneNumberFormat.format(phoneNumber: string);
   ```

4. Check whether the phone number is correct and obtain its home area.
   ```ts
   The let isValidNumber: boolean = phoneNumberFormat.isValidNumber(phoneNumber: string); // Check whether the phone number is correct.
   let locationName: string = phoneNumberFormat.getLocationName(number: string, locale: string); // Obtain the home area of the phone number.
   ```

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

```ts
// Import the i18n module.
import { i18n } from '@kit.LocalizationKit';

// Format the phone number.
let phoneNumberFormat1 = new i18n.PhoneNumberFormat('CN');
let formattedPhoneNumber1 = phoneNumberFormat1.format('158****2312'); // formattedPhoneNumber1: 158 **** 2312

// Set the format type of the phone number to RFC3966.
let phoneNumberFormat2 = new i18n.PhoneNumberFormat('CN', {type: 'RFC3966'});
let formattedPhoneNumber2 = phoneNumberFormat2.format('158****2312'); // formattedPhoneNumber2: tel:+86-158-****-2312

// Check whether the phone number is valid.
let phoneNumberFormat3 = new i18n.PhoneNumberFormat('CN');
let isValid = phoneNumberFormat3.isValidNumber('158****2312'); // isValid: true

// Display the home area of the phone number in the specified language.
let phoneNumberFormat4 = new i18n.PhoneNumberFormat("CN");
let locationName4 = phoneNumberFormat4.getLocationName('158****2312', 'en-GB') // locationName4: XiAn, Shanxi

// Format the phone number being dialed.
let phoneNumberFmt = new i18n.PhoneNumberFormat('CN', {type: 'TYPING'});
let phoneNumber : string = "0755453";
let formatResult : string = "";
for (let i = 0; i < phoneNumber.length; i++) {
  formatResult += phoneNumber.charAt(i);
  formatResult = phoneNumberFmt.format(formatResult);
}
console.log(formatResult); // formatResult: 0755 453
```
