# 布局简介


布局可以分为自适应布局和响应式布局，二者的介绍如下表所示。


| 名称 | 简介 |
| -------- | -------- |
| 自适应布局 | 当外部容器大小发生变化时，元素可以**根据相对关系自动变化**以适应外部容器变化的布局能力。相对关系如占比、固定宽高比、显示优先级等。当前自适应布局能力有7种：[拉伸能力](adaptive-layout.md#拉伸能力)、[均分能力](adaptive-layout.md#均分能力)、[占比能力](adaptive-layout.md#占比能力)、[缩放能力](adaptive-layout.md#缩放能力)、[延伸能力](adaptive-layout.md#延伸能力)、[隐藏能力](adaptive-layout.md#隐藏能力)、[折行能力](adaptive-layout.md#折行能力)。自适应布局能力可以实现界面显示随外部容器大小连续变化。 |
| 响应式布局 | 当外部容器大小发生变化时，元素可以**根据断点、栅格或特定的特征（如屏幕方向、窗口宽高等）自动变化**以适应外部容器变化的布局能力。当前响应式布局能力有3种：[断点](responsive-layout.md#断点)、[媒体查询](responsive-layout.md#媒体查询)、[栅格布局](responsive-layout.md#栅格布局)。响应式布局可以实现界面随外部容器大小有不连续变化，通常不同特征下的界面显示会有较大的差异。 |

> **说明：**
> 自适应布局多用于解决页面各区域内的布局差异，响应式布局多用于解决页面各区域间的布局差异。

自适应布局和响应式布局常常需要借助容器类组件实现，或与容器类组件搭配使用。


- 自适应布局常常需要借助[Row组件](../../reference/apis-arkui/arkui-ts/ts-container-row.md)、[Column组件](../../reference/apis-arkui/arkui-ts/ts-container-column.md)或[Flex组件](../../reference/apis-arkui/arkui-ts/ts-container-flex.md)实现。
  
  | 容器组件 | 组件说明                     | 拉伸能力                                              | 均分能力                                            | 占比能力                                               |
  | -------- | ---------------------------- | ----------------------------------------------------- | --------------------------------------------------- | ------------------------------------------------------ |
  | Row      | 沿水平方向布局子组件的容器   | 增加Blank子组件                                       | 将组件justifyContent属性设置为FlexAlign.SpaceEvenly | 通过百分比设置子组件宽高，或配置子组件layoutWeight属性 |
  | Column   | 沿垂直方向布局子组件的容器   | 增加Blank子组件                                       | 将组件justifyContent属性设置为FlexAlign.SpaceEvenly | 通过百分比设置子组件宽高，或配置子组件layoutWeight属性 |
  | Flex     | 使用弹性方式布局子组件的容器 | 增加Blank子组件，或配置子组件flexGrow和flexShrink属性 | 将组件justifyContent属性设置为FlexAlign.SpaceEvenly | 通过百分比设置子组件宽高，或配置子组件layoutWeight属性 |

  | 容器组件 | 组件说明                     | 缩放能力                | 延伸能力         | 隐藏能力                      | 折行能力                                |
  | -------- | ---------------------------- | ----------------------- | ---------------- | ----------------------------- | --------------------------------------- |
  | Row      | 沿水平方向布局子组件的容器   | 配置组件aspectRatio属性 | 增加Scroll父组件 | 配置子组件displayPriority属性 | —                                       |
  | Column   | 沿垂直方向布局子组件的容器   | 配置组件aspectRatio属性 | 增加Scroll父组件 | 配置子组件displayPriority属性 | —                                       |
  | Flex     | 使用弹性方式布局子组件的容器 | 配置组件aspectRatio属性 | —                | 配置子组件displayPriority属性 | 将组件wrap属性，<br>设置为FlexWrap.Wrap |
  
- 响应式布局常常与[GridRow组件](../../reference/apis-arkui/arkui-ts/ts-container-gridrow.md)、[Grid组件](../../reference/apis-arkui/arkui-ts/ts-container-grid.md)、[List组件](../../reference/apis-arkui/arkui-ts/ts-container-list.md)、[Swiper组件](../../reference/apis-arkui/arkui-ts/ts-container-swiper.md)或[Tabs组件](../../reference/apis-arkui/arkui-ts/ts-container-tabs.md)搭配使用。
  
  | 容器组件 | 组件说明                                                     | 响应式布局                                                   |
  | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | GridRow  | 使用断点和栅格方式布局子组件的容器。<br>需配合GridCol子组件使用。 | 栅格组件自身具有响应式布局能力。                             |
  | Grid     | 使用“行”和“列”分割的单元格方式布局子组件的网格容器。<br>需配合GridItem子组件使用。 | 需配合断点使用，通过改变不同断点下的rowsTemplate和columnsTemplate等属性，实现不同的布局效果。 |
  | List     | 包含一系列相同宽度列表项的容器。<br>需配合ListItem子组件使用。 | 需配合断点使用，通过改变不同断点下的lanes等属性，实现不同的布局效果。 |
  | Swiper   | 轮播展示子组件的容器。                                       | 需配合断点使用，通过改变不同断点下的displayCount和indicator等属性，实现不同的布局效果。 |
  | Tabs     | 使用页签控制内容切换的容器，每个页签对应一个内容视图。<br>需配合TabContent子组件使用。 | 需配合断点使用，通过改变不同断点下的vertical和barPosition等属性，实现不同的布局效果。 |
  
  

接下来将依次介绍自适应布局和响应式布局，同时结合实际，通过典型布局场景以及典型页面场景详细介绍两种布局能力的用法。

