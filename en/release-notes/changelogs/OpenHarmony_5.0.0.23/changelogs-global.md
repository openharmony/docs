# Globalization Changelog

## cl.global.1 ohos.i18n Change in the Error Thrown When Parameter Type Verification Failed

**Reason for Change**

Error code 401 is a common error code for parameter type check. The original error code 890001 is no longer thrown in the parameter type check scenario.

**Change Impact**

This change is a non-compatible change.

Before change: If the parameter type is incorrect, the error code 890001 is thrown.

After change: If the parameter type is incorrect, the error code 401 is thrown.

After the change, you need to capture the new error code for error handling.
Currently, the IDE implements parameter type check in the compilation phase. If the IDE is used for compilation, there is no impact.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.23 

**Key API/Component Changes**

The following table lists the changed APIs of ohos.i18n.
| API | Access Level | **Start API Level** | **Change Since** |
|--------|--------|--------|--------|
| getSystemCountries | Public API | 9 | 12 |
| isSuggested | Public API | 9 | 12 |
| getHolidayInfoItemArray | Public API | 11 | 12 |
| isHoliday | Public API | 11 | 12 |
| getDisplayCountry | Public API | 9 | 12 |
| getDisplayLanguage | Public API | 11 | 12 |
| getLanguageInfoArray | System API | 11 | 12 |
| getRegionInfoArray | System API | 10 | 12 |
| setUsingLocalDigit | System API | 10 | 12 |
| removePreferredLanguage | System API | 9 | 12 |

**Adaptation Guide**

The error code for input parameter type mismatch is changed from 890001 to 401. Use the new error code for exception handling.
