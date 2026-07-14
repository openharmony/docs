# Types
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @kurli1-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

ArkWeb Types模块是ArkWeb框架中的类型别名和回调函数类型定义集合，为WebView组件的消息通信、代理配置和媒体播放控制等能力提供统一的数据类型约束和回调签名规范，是WebView组件相关核心类接口声明中的类型支撑层。

开发者在使用WebView组件相关核心类时，需依赖本模块中的类型定义来约束数据格式、声明回调签名以及实现各类回调接入。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准。

## WebMessage

type WebMessage = ArrayBuffer | string

用于描述[WebMessagePort](./arkts-apis-webview-WebMessagePort.md)所支持的数据类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 类型       | 说明                                     |
| -------- | -------------------------------------- |
| string   | 字符串类型数据。 |
| ArrayBuffer   | 二进制类型数据。 |

## OnProxyConfigChangeCallback<sup>15+</sup>

type OnProxyConfigChangeCallback = () => void

回调函数，回调成功表示代理设置成功。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## CreateNativeMediaPlayerCallback<sup>12+</sup>

type CreateNativeMediaPlayerCallback = (handler: NativeMediaPlayerHandler, mediaInfo: MediaInfo) => NativeMediaPlayerBridge

[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)方法的参数。一个回调函数，创建播放器实例，用于接管网页中的媒体播放。通过接管机制，应用可以使用自定义播放器实现特殊功能或优化性能。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| handler | [NativeMediaPlayerHandler](./arkts-apis-webview-NativeMediaPlayerHandler.md) | 是 | 通过该对象，将播放器的状态报告给 ArkWeb 内核。应用通过该对象上报播放、暂停、错误等状态事件，使ArkWeb内核能够同步网页中的媒体播放状态。应用需要实现该接口定义的必要方法和属性。 |
| mediaInfo | [MediaInfo](./arkts-apis-webview-i.md#mediainfo12) | 是 | 网页媒体的信息。 |

**返回值：**

| 类型 | 说明 |
|------|------|
| [NativeMediaPlayerBridge](./arkts-apis-webview-NativeMediaPlayerBridge.md) | 接管网页媒体播放器和 ArkWeb 内核之间的一个接口类。<br/>应用需要实现该接口类。<br/> ArkWeb 内核通过该接口对象控制应用创建的媒体播放器。<br/>如果应用返回了 null，则表示应用不接管这个媒体的播放，由 ArkWeb 内核来播放该媒体。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。