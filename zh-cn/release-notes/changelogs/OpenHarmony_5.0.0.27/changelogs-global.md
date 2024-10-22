# 全球化变更说明

## cl.global.1 系统字体变更

**访问级别**

其他

**变更原因**

为保证用户体验，支持系统设置字体粗细调节能力，部分字体进行了更换。

**变更影响**

该变更为不兼容变更。

使用硬编码通过路径访问字体的应用受影响。

如果应用通过硬编码的方式使用了变更前的字体，现在需将字体文件改成新的字体文件。

常用字体对照表：

下表列举了变更前后常用字体文件，在实际的开发过程中，开发者可以通过API接口获取当前系统支持的字体文件，详细内容可以参考[API接口文档](../../../application-dev/reference/apis-arkui/js-apis-font.md)。

| 变更前                                      | 变更后                              |
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

**起始 API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.27 版本开始。

**适配指导**

参照常用字体对照表修改字体文件名。

