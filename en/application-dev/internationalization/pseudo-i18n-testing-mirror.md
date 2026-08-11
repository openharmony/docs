# Pseudo-Localization Testing for UI Mirroring

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=9d4329aa9b07ce81fc1a2c848fb4cea93e274a8e translatedAt=2026-08-04T12:27:06.542Z pushedAt=2026-08-04T13:22:50.705Z -->

## Application Scenario

The pseudo-localization testing for UI mirroring aims to check whether the text reading direction is correct. In some languages, the text is not read from left to right. For example, in Arabic, text is read from right to left.

## Test Process

1. Switch to the target locale for pseudo-localization testing, for example, **ar-XB**.

   >  **NOTE**
   >
   >  The **setSystemLanguage** API is a system API and needs to be called by the system applications. Once the target locale is successfully set, non-system applications can then perform pseudo-localization testing.

   <!--Del-->

   ```ts
   import { i18n } from '@kit.LocalizationKit';

   i18n.System.setSystemLanguage('ar-XB');
   ```

   <!--DelEnd-->

2. Traverse the applications to be tested.

## **Test Item**

1. Check whether the UI layout, text direction, and control logic comply with the reading habit of the target locale. For details, see [UI Mirroring](i18n-ui-design.md#ui-mirroring).

2. Check whether related functions are normal.