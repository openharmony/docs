# Pseudo-Localization Testing for UI Mirroring

## Application scenario

The pseudo-localization testing for UI mirroring aims to check whether the text reading direction is correct. In some languages, the text is not read from left to right. For example, in Arabic, text is read from right to left.

## Test Process

1. Switch to the target locale for pseudo-localization testing, for example, **ar-XB**.

   You can switch the locale through the code (system permission required):
   ```ts
   import I18n from '@ohos.i18n'
   I18n.System.setSystemLanguage('ar-XB')
   ```

2. Traverse the applications to be tested.

## **Test Item**

1. Check whether the UI layout, text direction, and UI control logic comply with the reading habit of the target locale. For details, see [UI Mirroring](i18n-ui-design.md).

2. Check whether related functions are normal.
