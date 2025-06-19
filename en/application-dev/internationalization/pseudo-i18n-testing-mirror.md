# Pseudo-Localization Testing for UI Mirroring

## When to Use

The pseudo-localization testing for UI mirroring aims to check whether the text reading direction is correct. In some languages, the text is not read from left to right. For example, in Arabic, text is read from right to left.

## How to Develop

1. When calling **setSystemLanguage**, pass in the target locale for pseudo-localization testing, for example, **ar-XB**.

   >  **NOTE**
   >
   >  The **setSystemLanguage** API is a system API and needs to be called by the system applications. Once the target locale is successfully set, non-system applications can then perform pseudo-localization testing.
   <!--RP1-->
   ```ts
   import { i18n } from '@kit.LocalizationKit';

   i18n.System.setSystemLanguage('ar-XB');
   ```
   <!--RP1End-->

2. Traverse the applications to be tested.

## **Test Procedure**

1. Check whether the UI layout, text direction, and control logic comply with the reading habit of the target locale. For details, see [UI Mirroring](i18n-ui-design.md#ui-mirroring).

2. Check whether related functions are normal.
