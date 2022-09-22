# 布局能力简介


开发多设备上同一页面时，建议开发者优先使用一套布局，尽可能的实现代码复用。


一般情况下，可以通过页面的组件结构（组件个数、组件的父子/兄弟关系、组件类型）来判断是否可以使用一套布局：


- 对于页面组件结构相同的场景，在开发过程中可以灵活使用[自适应布局](adaptive-layout-intro.md)和[栅格布局](grid-breakpoint.md)能力来达到预期效果。

- 对于页面组件结构不同的场景，可以借助[媒体查询](media-query.md)能力动态加载多套布局。


下面将详细介绍这些布局能力。
## 相关实例

针对一次开发，多端部署，有以下相关实例可供参考：

- [`MusicAlbum`：一多音乐专辑主页（eTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/MultiDeviceAppDev/MusicAlbum)
- [`AppMarket`：一多应用市场首页（eTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/MultiDeviceAppDev/AppMarket)
- [`AdaptiveCapabilities`：多设备自适应能力（eTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/MultiDeviceAppDev/AdaptiveCapabilities)
- [`JsAdaptiveCapabilities`：多设备自适应能力（JS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/MultiDeviceAppDev/JsAdaptiveCapabilities)
- [一次开发多端部署（eTS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/MultiDeploymentEts)
