# Class (BackForwardCacheOptions)

前进后退缓存相关设置对象，用来控制Web组件前进后退缓存相关选项。

> **说明：**
>
> - 本模块接口从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

**系统能力：** SystemCapability.Web.Webview.Core

## 属性

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
| size<sup>12+</sup> | number | 是 | 设置每个Web组件允许缓存的最大页面个数。<br>默认为1，最大可设置为50。<br>设置为0或负数时，前进后退缓存功能不生效。<br>Web会根据内存压力对缓存进行回收。 |
| timeToLive<sup>12+</sup> | number | 是 | 设置每个Web组件允许页面在前进后退缓存中停留的时间。<br>设置为0或负数时，前进后退缓存功能不生效。<br>默认值：600。<br>单位：秒。 |

## constructor<sup>12+</sup>

constructor()

BackForwardCacheOptions的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core