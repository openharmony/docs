# Class (BackForwardCacheSupportedFeatures)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

BackForwardCacheSupportedFeatures是ArkWeb框架中用于选择性控制允许使用了特定Web特性的页面可以进入前进后退缓存（BFCache）的配置类。默认情况下，使用同层渲染或视频托管等特性的页面会被阻止进入BFCache，因为浏览器无法安全地保存和恢复这些与系统控件绑定的复杂状态。通过设置该类中的属性，开发者可以显式允许这些特性的页面进入BFCache，但需注意自行维护相关系统控件的生命周期，避免造成资源泄漏。完整示例代码参考[enableBackForwardCache](./arkts-apis-webview-WebviewController.md#enablebackforwardcache12)。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准。

## 属性

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------|------|------|------|------|
| nativeEmbed<sup>12+</sup> | boolean | 否 | 否 | 是否允许使用同层渲染的页面进入前进后退缓存。<br>如果设置为允许，需要维护为同层渲染元素创建的系统控件的生命周期，避免造成资源泄漏。<br>true：允许，false：不允许。<br>默认值：false。 |
| mediaTakeOver<sup>12+</sup> | boolean | 否 | 否 | 是否允许使用视频托管的页面进入前进后退缓存。<br>如果设置为允许，需要维护为视频元素创建的系统控件的生命周期，避免造成资源泄漏。<br>true：允许，false：不允许。<br>默认值：false。|

## constructor<sup>12+</sup>

constructor()

BackForwardCacheSupportedFeatures的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core