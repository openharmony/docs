# 简介


本章介绍如何使用方舟开发框架“一多”能力，开发出在多设备上正常显示的页面。方舟开发框架推荐开发者使用声明式开发范式开发应用，故本章的内容和示例都主要基于声明式开发范式。本章主要包含如下内容：


- [布局能力](adaptive-layout.md)
  
  布局决定了页面中的元素按照何种方式排布及显示，是页面设计及开发过程中首先需要考虑的问题。一般情况下，可以通过页面（或自定义组件）内的组件结构（组件个数、组件的父子/兄弟关系、组件类型、组件的相对位置）来判断使用何种布局能力。
  
  - 对于随尺寸变化组件结构相同的场景，可以在开发过程中灵活使用[自适应布局能力](adaptive-layout.md)来达到目标效果。
  - 对于随尺寸变化组件结构不同的场景，更适合使用[响应式布局能力](responsive-layout.md)来实现不同尺寸下的不同显示的效果。
  
- [交互归一](interaction-event-normalization.md)

- [多态组件](polymorphic-controls.md)

- [资源使用](resource-usage.md)


> **说明：**
>
> 开发多设备上同一页面时，建议开发者多使用自定义组件，既可以增加代码的可读性和可维护性，同时也可以尽可能的实现代码复用。



## 相关实例

[OpenHarmony应用示例](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev)中提供了如下一多示例，感兴趣的开发者可以自行下载、运行及查看效果。

| 示例名称                                                     | 开发范式       | 简介                                                         |
| ------------------------------------------------------------ | -------------- | ------------------------------------------------------------ |
| [页面开发一多能力](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev/AdaptiveCapabilities) | 声明式开发范式 | 本章配套的示例代码，包括自适应布局、响应式布局、典型布局场景以及资源文件使用等。 |
| [页面开发一多能力](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev/JsAdaptiveCapabilities) | 类Web开发范式  | 本章配套的示例代码，包括自适应布局、响应式布局及资源文件使用等。 |
| [天气](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev/Weather) | 声明式开发范式 | 一多示例应用，以天气应用为例，演示如何使用一多能力实现包含多个页面的应用。 |
| [应用市场首页](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev/AppMarket) | 声明式开发范式 | 本章配套的示例代码，以应用市场首页为例，演示如何使用一多能力适配多设备（或多窗口尺寸）。 |
| [音乐专辑页](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev/MusicAlbum) | 声明式开发范式 | 本章配套的示例代码，以音乐专辑页为例，演示如何使用一多能力适配多设备（或多窗口尺寸）。 |
| [设置应用页面](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev/Settings) | 声明式开发范式 | 本章配套的示例代码，以设置应用页面为例，演示如何使用一多能力适配多设备（或多窗口尺寸）。 |
| [分栏控件](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev/MultiColumns) | 声明式开发范式 | 本示例分别展示了多场景下，一多分栏控件的响应式变化效果。 |
| [音乐专辑页](https://gitee.com/openharmony/codelabs/tree/master/ExcellentCase/MultiDeviceMusic) | 声明式开发范式 | 基于自适应和响应式布局，实现一次开发、多端部署音乐专辑页面。 |
| [视频应用](https://gitee.com/openharmony/codelabs/tree/master/ExcellentCase/Multi_device_V2) | 声明式开发范式 | 基于自适应布局和响应式布局能力，实现了常见的视频播放应用的主界面。 |
| [一多导航栏](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev/MultiNavBar) | 声明式开发范式 | 基于自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，主要通过组件提供窗口断点事件，保证应用在不同设备或不同窗口尺寸下可以正常显示。 |

