# AutoFillType (System API)

AutoFillType enumerates the types of elements to be automatically filled in.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## AutoFillType

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name          | Value | Description                              |
| -------------- | --- | --------------------------------- |
| UNSPECIFIED      | 0   | Undefined type.                        |
| PASSWORD      | 1   | Password.                    |
| USER_NAME     | 2   | Username.                    |
| NEW_PASSWORD     | 3   | New password.                    |
| FULL_STREET_ADDRESS<sup>12+</sup>        | 4    | Detailed address with street information.|
| HOUSE_NUMBER<sup>12+</sup>               | 5    | House number.|
| DISTRICT_ADDRESS<sup>12+</sup>           | 6    | District.|
| CITY_ADDRESS<sup>12+</sup>               | 7    | City.|
| PROVINCE_ADDRESS<sup>12+</sup>           | 8    | Province.|
| COUNTRY_ADDRESS<sup>12+</sup>            | 9    | Country/Region.|
| PERSON_FULL_NAME<sup>12+</sup>           | 10   | Full name.|
| PERSON_LAST_NAME<sup>12+</sup>           | 11   | Last name.|
| PERSON_FIRST_NAME<sup>12+</sup>          | 12   | First name.|
| PHONE_NUMBER<sup>12+</sup>               | 13   | Mobile number.|
| PHONE_COUNTRY_CODE<sup>12+</sup>         | 14   | Country/Region code.|
| FULL_PHONE_NUMBER<sup>12+</sup>          | 15   | Mobile number with the country/region code.|
| EMAIL_ADDRESS<sup>12+</sup>              | 16   | Email address.|
| BANK_CARD_NUMBER<sup>12+</sup>           | 17   | Bank card number.|
| ID_CARD_NUMBER<sup>12+</sup>             | 18   | ID card number.|
| NICKNAME<sup>12+</sup>                   | 24   | Nickname.|
| DETAIL_INFO_WITHOUT_STREET<sup>12+</sup> | 25   | Detailed address without street information.|
| FORMAT_ADDRESS<sup>12+</sup>             | 26   | Standard address.|
| PASSPORT_NUMBER<sup>18+</sup>            | 27   | Passport number.|
| VALIDITY<sup>18+</sup>                   | 28   | Validity period of the passport.|
| ISSUE_AT<sup>18+</sup>                   | 29   | Location where the passport was issued.|
| ORGANIZATION<sup>18+</sup>               | 30   | Invoice title.|
| TAX_ID<sup>18+</sup>                     | 31   | Tax ID.|
| ADDRESS_CITY_AND_STATE<sup>18+</sup>     | 32   | Location (city and state).|
| FLIGHT_NUMBER<sup>18+</sup>              | 33   | Flight number.|
| LICENSE_NUMBER<sup>18+</sup>             | 34   | Driver's license number.|
| LICENSE_FILE_NUMBER<sup>18+</sup>        | 35   | Driver's license file number.|
| LICENSE_PLATE<sup>18+</sup>              | 36   | License plate.|
| ENGINE_NUMBER<sup>18+</sup>              | 37   | Vehicle engine number.|
| LICENSE_CHASSIS_NUMBER<sup>18+</sup>     | 38   | Chassis number (VIN) of a vehicle.|
