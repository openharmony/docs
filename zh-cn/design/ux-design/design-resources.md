# 资源

为方便UX设计师以及开发者参考使用，本文特提供：


- [分层参数](visual-basis.md)的场景、id、参数详细对照表，[OpenHarmony系统资源分层设计表V1.0.xlsm](https://gitee.com/openharmony/docs/blob/master/zh-cn/design/ux-design/figures/OpenHarmony_%E7%B3%BB%E7%BB%9F%E8%B5%84%E6%BA%90%E5%88%86%E5%B1%82%E8%AE%BE%E8%AE%A1%E8%A1%A8_V1.0.xlsm)

- 符合规范的[设计交付件](design-deliverable-overview.md)样例，[OpenHarmony天气应用UX设计交付件V1.0.zip](https://gitee.com/openharmony/docs/blob/master/zh-cn/design/ux-design/figures/OpenHarmony_%E5%A4%A9%E6%B0%94%E5%BA%94%E7%94%A8UX%E8%AE%BE%E8%AE%A1%E4%BA%A4%E4%BB%98%E4%BB%B6_V1.0.zip)

- OpenHarmony[图标](visual-icons.md)资源，[OpenHarmony_Icons.zip](https://gitee.com/openharmony/docs/blob/master/zh-cn/design/ux-design/figures/OpenHarmony_Icons.zip)

- OpenHarmony[应用图标](visual-app-icons.md)设计模板，[OpenHarmony应用图标模版.zip](https://gitee.com/openharmony/docs/blob/master/zh-cn/design/ux-design/figures/OpenHarmony%E5%BA%94%E7%94%A8%E5%9B%BE%E6%A0%87%E6%A8%A1%E7%89%88.zip)


系统资源分层设计表列出了当前OpenHarmony中可用系统资源id及其在不同类型设备上的取值，它由六张子表组成，各个子表的含义如下所示。


  | 表格 | 简介 | 
| -------- | -------- |
| 应用色彩参数 | 在**应用开发**过程中可以使用的**色彩**相关的系统资源。 | 
| 应用圆角参数 | 在**应用开发**过程中可以使用的**圆角**相关的系统资源。 | 
| 应用字体参数 | 在**应用开发**过程中可以使用的**字体**相关的系统资源。 | 
| 应用间距参数 | 在**应用开发**过程中可以使用的**间距**相关的系统资源。 | 
| 服务卡片参数 | 在**服务卡片开发**过程中可以使用的系统资源。 | 
| 不透明度数值速查表 | 用于将不透明度在**百分比表示形式**和**十六进制表示形式**之间快速转换的速查表。 | 


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 推荐应用相关系统参数仅在应用开发场景中使用，卡片相关系统参数仅在卡片开发场景中使用。
> 
> - 同一系统参数在不同类型的设备上有不同的取值，当前仅提供了系统参数在默认设备上的取值，后续会针对不同设备类型做补充。
> 
> - 颜色可以用“RGB”或“ARGB”形式表示，采用“RGB”表示的颜色，完全不透明；采用“ARGB”表示的颜色，其不透明度由“A”（Alpha通道）确定。如“\#7FFF0000”代表不透明度为50%的红色，“\#FFFF0000”和“\#FF0000”都表示不透明度为100%（即完全不透明）的红色。
