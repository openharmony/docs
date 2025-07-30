# ArkWeb子系统Changelog

## cl.arkweb.1 ArkWeb基于上游社区的Chromium内核从114升级为132版本

**访问级别**

系统接口

**变更原因**

为了提升使用ArkWeb内核应用的安全性，开发者使用最新的W3C HTML5特性，以及获得Chromium上游社区最新的性能体验优化成果，故本次进行内核升级(114 -> 132)。

**变更影响**

从上游社区337项功能变更说明，以及社区200+问题单分析，WPT测试集结果分析，当前共发现50项需要开发者注意的变更点，请参考[ArkWeb版本的差异总结](https://gitcode.com/openharmony-tpc/chromium_src/blob/132_trunk/web/ReleaseNote/ArkWeb_114_132.md)。

**起始 API Level**

不涉及

**变更发生版本**

 从OpenHarmony SDK 6.0.0.32 开始。

**变更的接口/组件**

ArkWeb

**适配指导**

如果在应用中使用Web组件展示网页内容，则需要遵循[ArkWeb版本差异总结](https://gitcode.com/openharmony-tpc/chromium_src/blob/132_trunk/web/ReleaseNote/ArkWeb_114_132.md)中所涉及的最新W3C规格变更。