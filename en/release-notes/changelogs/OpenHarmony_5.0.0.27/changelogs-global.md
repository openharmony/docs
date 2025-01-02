# Globalization Changelog

## cl.global.1 System Font Change

**Access Level**

Other

**Reason for Change**

To ensure user experience, the system supports adjustment of font widths and has changed some fonts.

**Change Impact**

This change is a non-compatible change.

Applications that access fonts through hard coding are affected.

If the application is hard coded to use the original font, you need to change the font file to the new one.

The following table lists the common font files before and after the change. During actual development, you can obtain the supported font files by using APIs. For details, see [API Reference](../../../application-dev/reference/apis-arkui/js-apis-font.md).

| Before Change                                     | After Change                             |
| ------------------------------------------- | ----------------------------------- |
| HarmonyOS_Sans_Thin.ttf                     | HarmonyOS_Sans.ttf                  |
| HarmonyOS_Sans_Light.ttf                    | HarmonyOS_Sans.ttf                  |
| HarmonyOS_Sans_Regular.ttf                  | HarmonyOS_Sans.ttf                  |
| HarmonyOS_Sans_Medium.ttf                   | HarmonyOS_Sans.ttf                  |
| HarmonyOS_Sans_Bold.ttf                     | HarmonyOS_Sans.ttf                  |
| HarmonyOS_Sans_Black.ttf                    | HarmonyOS_Sans.ttf                  |
| HarmonyOS_Sans_Thin_Italic.ttf              | HarmonyOS_Sans_Italic.ttf           |
| HarmonyOS_Sans_Light_Italic.ttf             | HarmonyOS_Sans_Italic.ttf           |
| HarmonyOS_Sans_Regular_Italic.ttf           | HarmonyOS_Sans_Italic.ttf           |
| HarmonyOS_Sans_Medium_Italic.ttf            | HarmonyOS_Sans_Italic.ttf           |
| HarmonyOS_Sans_Bold_Italic.ttf              | HarmonyOS_Sans_Italic.ttf           |
| HarmonyOS_Sans_Black_Italic.ttf             | HarmonyOS_Sans_Italic.ttf           |
| HarmonyOS_Sans_SC_Thin.ttf                  | HarmonyOS_Sans_SC.ttf               |
| HarmonyOS_Sans_SC_Light.ttf                 | HarmonyOS_Sans_SC.ttf               |
| HarmonyOS_Sans_SC_Regular.ttf               | HarmonyOS_Sans_SC.ttf               |
| HarmonyOS_Sans_SC_Medium.ttf                | HarmonyOS_Sans_SC.ttf               |
| HarmonyOS_SansSC_Semibold.ttf               | HarmonyOS_Sans_SC.ttf               |
| HarmonyOS_Sans_SC_Bold.ttf                  | HarmonyOS_Sans_SC.ttf               |
| HarmonyOS_Sans_SC_Black.ttf                 | HarmonyOS_Sans_SC.ttf               |
| HarmonyOS_Sans_TC_Thin.ttf                  | HarmonyOS_Sans_TC.ttf               |
| HarmonyOS_Sans_TC_Light.ttf                 | HarmonyOS_Sans_TC.ttf               |
| HarmonyOS_Sans_TC_Regular.ttf               | HarmonyOS_Sans_TC.ttf               |
| HarmonyOS_Sans_TC_Medium.ttf                | HarmonyOS_Sans_TC.ttf               |
| HarmonyOS_Sans_TC_Bold.ttf                  | HarmonyOS_Sans_TC.ttf               |
| HarmonyOS_Sans_TC_Black.ttf                 | HarmonyOS_Sans_TC.ttf               |
| HarmonyOS_Sans_Naskh_Arabic_Thin.ttf        | HarmonyOS_Sans_Naskh_Arabic.ttf     |
| HarmonyOS_Sans_Naskh_Arabic_Light.ttf       | HarmonyOS_Sans_Naskh_Arabic.ttf     |
| HarmonyOS_Sans_Naskh_Arabic_Regular.ttf     | HarmonyOS_Sans_Naskh_Arabic.ttf     |
| HarmonyOS_Sans_Naskh_Arabic_Medium.ttf      | HarmonyOS_Sans_Naskh_Arabic.ttf     |
| HarmonyOS_Sans_Naskh_Arabic_Bold.ttf        | HarmonyOS_Sans_Naskh_Arabic.ttf     |
| HarmonyOS_Sans_Naskh_Arabic_Black.ttf       | HarmonyOS_Sans_Naskh_Arabic.ttf     |
| HarmonyOS_Sans_Naskh_Arabic_UI_Thin.ttf     | HarmonyOS_Sans_Naskh_Arabic_UI.ttf  |
| HarmonyOS_Sans_Naskh_Arabic_UI_Light.ttf    | HarmonyOS_Sans_Naskh_Arabic_UI.ttf  |
| HarmonyOS_Sans_Naskh_Arabic_UI_Regular.ttf  | HarmonyOS_Sans_Naskh_Arabic_UI.ttf  |
| HarmonyOS_Sans_Naskh_Arabic_UI_Medium.ttf   | HarmonyOS_Sans_Naskh_Arabic_UI.ttf  |
| HarmonyOS_Sans_Naskh_Arabic_UI_Bold.ttf     | HarmonyOS_Sans_Naskh_Arabic_UI.ttf  |
| HarmonyOS_Sans_Naskh_Arabic_UI_Black.ttf    | HarmonyOS_Sans_Naskh_Arabic_UI.ttf  |
| HarmonyOS_Sans_Condensed_Thin.ttf           | HarmonyOS_Sans_Condensed.ttf        |
| HarmonyOS_Sans_Condensed_Light.ttf          | HarmonyOS_Sans_Condensed.ttf        |
| HarmonyOS_Sans_Condensed_Regular.ttf        | HarmonyOS_Sans_Condensed.ttf        |
| HarmonyOS_Sans_Condensed_Medium.ttf         | HarmonyOS_Sans_Condensed.ttf        |
| HarmonyOS_Sans_Condensed_Bold.ttf           | HarmonyOS_Sans_Condensed.ttf        |
| HarmonyOS_Sans_Condensed_Black.ttf          | HarmonyOS_Sans_Condensed.ttf        |
| HarmonyOS_Sans_Condensed_Thin_Italic.ttf    | HarmonyOS_Sans_Condensed_Italic.ttf |
| HarmonyOS_Sans_Condensed_Light_Italic.ttf   | HarmonyOS_Sans_Condensed_Italic.ttf |
| HarmonyOS_Sans_Condensed_Regular_Italic.ttf | HarmonyOS_Sans_Condensed_Italic.ttf |
| HarmonyOS_Sans_Condensed_Medium_Italic.ttf  | HarmonyOS_Sans_Condensed_Italic.ttf |
| HarmonyOS_Sans_Condensed_Bold_Italic.ttf    | HarmonyOS_Sans_Condensed_Italic.ttf |
| HarmonyOS_Sans_Condensed_Black_Italic.ttf   | HarmonyOS_Sans_Condensed_Italic.ttf |
| NotoSans_JP_Light.otf                       | NotoSansCJK-Regular.ttc             |
| NotoSans_JP_Regular.otf                     | NotoSansCJK-Regular.ttc             |
| NotoSans_JP_Bold.otf                        | NotoSansCJK-Regular.ttc             |
| NotoSans_KR_Light.otf                       | NotoSansCJK-Regular.ttc             |
| NotoSans_KR_Regular.otf                     | NotoSansCJK-Regular.ttc             |
| NotoSans_KR_Bold.otf                        | NotoSansCJK-Regular.ttc             |

**Start API Level**

No API change is involved.

**Change Since**

OpenHarmony SDK 5.0.0.27

**Adaptation Guide**

Change the font file names according to the preceding font mapping table.
