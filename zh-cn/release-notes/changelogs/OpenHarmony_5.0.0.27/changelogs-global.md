# 全球化变更说明

## cl.global.1 系统字体变更

**访问级别**

其他

**变更原因**

为保证用户体验，支持系统设置字体粗细调节能力，部分字体进行了更换。

**变更影响**

该变更为非兼容性变更。使用硬编码通过路径访问字体的应用受影响。

字体对照表：

|| 变更前          | 变更后   | 
|-------| -------- | --------------- | 
|默认字体|  HarmonyOS_Sans_Regular.ttf    |  HarmonyOS_Sans.ttf   |
|简体中文字体|  HarmonyOS_Sans_SC_Regular.ttf    |  HarmonyOS_Sans_SC.ttf  | 
|繁体中文字体|  HarmonyOS_Sans_TC_Regular.ttf    |  HarmonyOS_Sans_TC.ttf | 
|阿拉伯文字体|  HarmonyOS_Sans_Naskh_Arabic_UI_Regular.ttf    |  HarmonyOS_Sans_Naskh_Arabic_UI.ttf   | 
||  HarmonyOS_Sans_Naskh_Arabic_Regular.ttf    |  HarmonyOS_Sans_Naskh_Arabic.ttf   | 
|日文字体|  NotoSans_JP_Regular.otf   |  NotoSansCJK-Regular.ttc   | 
|韩文字体|  NotoSans_KR_Regular.otf  |  NotoSansCJK-Regular.ttc   | 
||  HarmonyOS_Sans_Condensed_Regular.ttf  |  HarmonyOS_Sans_Condensed.ttf   | 

如应用单独使用了上述类型字体，需适配新字体文件。

**起始 API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.27 版本开始。

**适配指导**

使用变更后的字体文件名。