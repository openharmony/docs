# Globalization Changelog

## cl.global.1 System Font Change

**Access Level**

Other

**Reason for Change**

To ensure user experience, the system supports adjustment of font widths and has changed some fonts.

**Change Impact**

This change is a non-compatible change. Applications that access fonts through hard coding are affected.

Font mapping table:

|Font| Before Change         | After Change  | 
|-------| -------- | --------------- | 
|Default|  HarmonyOS_Sans_Regular.ttf    |  HarmonyOS_Sans.ttf   |
|Simplified Chinese |  HarmonyOS_Sans_SC_Regular.ttf    |  HarmonyOS_Sans_SC.ttf  | 
|Traditional Chinese |  HarmonyOS_Sans_TC_Regular.ttf    |  HarmonyOS_Sans_TC.ttf | 
|Arabic |  HarmonyOS_Sans_Naskh_Arabic_UI_Regular.ttf    |  HarmonyOS_Sans_Naskh_Arabic_UI.ttf   | 
||  HarmonyOS_Sans_Naskh_Arabic_Regular.ttf    |  HarmonyOS_Sans_Naskh_Arabic.ttf   | 
|Japanese|  NotoSans_JP_Regular.otf   |  NotoSansCJK-Regular.ttc   | 
|Korean|  NotoSans_KR_Regular.otf  |  NotoSansCJK-Regular.ttc   | 
||  HarmonyOS_Sans_Condensed_Regular.ttf  |  HarmonyOS_Sans_Condensed.ttf   | 

If your application uses the preceding fonts independently, you need to adapt the new font file.

**Start API Level**

No API change is involved.

**Change Since**

OpenHarmony SDK 5.0.0.27

**Adaptation Guide**

Use the new font file name.
