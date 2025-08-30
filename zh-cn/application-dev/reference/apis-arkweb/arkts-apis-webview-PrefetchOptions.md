# Class (PrefetchOptions)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

用来自定义预取行为，包括是否忽略Cache-Control: no-store和设置最小时间间隔。

> **说明：**
>
> - 本模块接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 21开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

**系统能力：** SystemCapability.Web.Webview.Core

## 属性

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------|------|------|------|------|
| minTimeBetweenPrefetchesMs<sup>21+</sup> | number | 否 | 否 | 设置两次预取的最小时间间隔。<br>默认为500，最大值为500。<br>设置为负数时，默认为0。 |
| ignoreCacheControlNoStore<sup>21+</sup> | boolean | 否 | 否 | 设置是否忽略Cache-Control: no-store。<br>默认值：false。 |

## constructor<sup>21+</sup>

constructor()

PrefetchOptions的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core