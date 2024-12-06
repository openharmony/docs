# Globalization Subsystem Changelog

## cl.global.1 Change in the Localized Names of Countries/Regions

**Access Level**

Public API

**Reason for Change**

 1. The current localized names for the Hong Kong, Macao, and Taiwan regions of China use commas or spaces as separators, which can lead to ambiguity when multiple countries/regions are listed together.
 2. The country name of the State of Palestine has been changed internationally from Palestinian Territories to Palestine.

**Change Impact**

This change is a non-compatible change.

Before change: A comma or space is used as the separator between the localized names of the region and home country.

After change: The localized name of the home country is placed in the parentheses after the region, for example, Hong Kong (China).

Before change: The localized name of the State of Palestine is Palestinian Territories.

After change: The localized name of the State of Palestine is Palestine.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.51

**Key API/Component Changes**

i18n.system.getDisplayCountry

**Adaptation Guide**

Do not perform special judgment on the return values of the API. The values are used only for display on the UI.


## cl.global.2 Change in the Localized Names of Countries/Regions

**Access Level**

System API

**Reason for Change**

 1. The current localized names for the Hong Kong, Macao, and Taiwan regions of China use commas or spaces as separators, which can lead to ambiguity when multiple countries/regions are listed together.
 2. The country name of the State of Palestine has been changed internationally from Palestinian Territories to Palestine.

**Change Impact**

This change is a non-compatible change.

Before change: A comma or space is used as the separator between the localized names of the region and home country.

After change: The localized name of the home country is placed in the parentheses after the region, for example, Hong Kong (China).

Before change: The name of the State of Palestine is Palestinian Territories.

After change: The localized name of the State of Palestine is Palestine.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.51

**Key API/Component Changes**

i18n.system.getRegionInfoArray

**Adaptation Guide**

Do not perform special judgment on the return values of the API. The values are used only for display on the UI.


## cl.global.3 Modification of the Incorrect Date and Time Formatting Result for November

**Access Level**

Public API

**Reason for Change**

In accordance with industry standards, the eleventh month in the lunar calendar should be displayed as Winter Month.

**Change Impact**

This change is a non-compatible change.

Before change: The eleventh month is treated as November in the date and time formatting result.

After change: The eleventh month is treated as Winter Month in the date and time formatting result.

**Start API Level**

API 6

**Change Since**

OpenHarmony SDK 5.0.0.51

**Key API/Component Changes**

intl.DateTimeFormat.format

**Adaptation Guide**

Do not perform special judgment on the return values of the API. The values are used only for display on the UI.


## cl.global.4 Modification of the Incorrect Date and Time Formatting Result in zh-Hant-HK

**Access Level**

Public API

**Reason for Change**

When the locale is **zh-Hant-HK**, the date and time formatting result is empty.

**Change Impact**

This change is a non-compatible change.

Before change: When the locale is **zh-Hant-HK**, the date and time formatting result is empty.

After change: When the locale is **zh-Hant-HK**, the correct date and time formatting result is returned.

**Start API Level**

6

**Change Since**

OpenHarmony SDK 5.0.0.51

**Key API/Component Changes**

intl.DateTimeFormat.formatRange

**Adaptation Guide**

Do not perform special judgment on the return values of the API. The values are used only for display on the UI.


## cl.global.5 Modification of the Incorrect Home Location Calculation for Invalid Numbers

**Access Level**

Public API

**Reason for Change**

When an invalid number is passed to **getLocationName**, the locale passed to the **PhoneNumberFormat** object is returned as the home location of the number.

**Change Impact**

This change is a non-compatible change.

Before change: When an invalid number is passed to **getLocationName**, the locale passed to the **PhoneNumberFormat** object is returned as the home location of the number.

After change: When an invalid number is passed to **getLocationName**, an empty string is returned.

**Start API Level**

API 9

**Change Since**

OpenHarmony SDK 5.0.0.51

**Key API/Component Changes**

intl.PhoneNumberFormat.getLocationName

**Adaptation Guide**

Do not perform special judgment on the return values of the API. The values are used only for display on the UI.

## cl.global.6 Change in the List of Supported Countries/Regions

**Access Level**

Public API

**Reason for Change**

Bhutan is not in the list of countries/regions supported by the system.

**Change Impact**

This change is a non-compatible change.

Before change: Bhutan is not in the list of countries/regions supported by the system.

After change: Bhutan is in the list of countries/regions supported by the system.

**Start API Level**

API 9

**Change Since**

OpenHarmony SDK 5.0.0.51

**Key API/Component Changes**

i18n.system.getSystemCountries

**Adaptation Guide**

Do not forcibly check the array size in the return value.
