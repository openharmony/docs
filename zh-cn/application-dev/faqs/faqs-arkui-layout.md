# ArkUI布局开发常见问题(ArkTS)


## 使用position之后height不生效(API 9)

**解决措施**

容器组件在使用position之后会脱离文本流，导致容器脱离外层容器束缚，导致height不生效，可以将外层容器换成Stack可以解决这个问题。


## Grid组件如何实现横向滚动(API 9)

将Grid组件设置当前网格布局行数rowsTemplate且不设置列数，当内容超出Grid组件宽度时，Grid可横向滚动进行内容展示。


## List组件与其他组件并列使用时，若未设置List滚动方向上的尺寸，无法拖动到底部(API 9)

给List加上layoutWeight属性，设置列表自适应占满剩余高度。原理：List属于可滚动容器组件，默认高度是占满全屏幕高度，当出现其他固定高度的组件占领了屏幕的部分高度时，需要开发人员显性的指定List组件占满剩余高度，而不是全屏幕高度。


## Tabs组件在点击Tab项时是否支持禁止切换(API 9)

不支持。


## 如何拦截住onBackPress事件，不触发页面返回(API 9)

在onBackPress中返回true表示页面自己处理返回逻辑，不会执行默认的返回逻辑。

**参考链接**

[自定义组件的生命周期-onBackPress](../reference/arkui-ts/ts-custom-component-lifecycle.md#onbackpress)


## List组件怎么实现分组列表的粘性标题效果(API 9)

可以通过List组件的sticky属性配合ListItemGroup组件来实现。通过给List组件设置sticky属性为StickyStyle.Header，设置ListItemGroup中header参数对应的头部组件呈现粘性标题效果

**参考链接**

[创建列表-添加粘性标题](../ui/arkts-layout-development-create-list.md#添加粘性标题)

## 键盘弹出时如何只让指定UI组件进行上移，而不是整体布局(API 10)

**解决措施**

 利用安全区域接口进行避让逻辑控制。

**参考链接**

[安全区域](../reference/arkui-ts/ts-universal-attributes-expand-safe-area.md)

## 有哪些实现图文混排的方式，每种方式的优劣点是什么，推荐场景是什么(API 10)

**解决措施**

1、如果做页面展示，可通过Text嵌套ImageSpan或者容器下嵌套Text&Image组件，前者更轻量级，后者实现功能更多。

2、如果要进行编辑，可使用RichEditor控件。

**参考链接**

[图文混排](../reference/arkui-ts/ts-basic-components-richeditor.md)

## 如何实现类似安卓协调布局CoordinateLayout的效果(API 10)

**解决措施**

可滚动类组件可以使用nestedScroll属性设置嵌套滚动。

**参考链接**

[Scroll](../reference/arkui-ts/ts-container-scroll.md)

## 如何解决sidebar侧边栏出现时，遮挡住下方的导航栏的问题(API 10)

**解决措施**

将被遮挡的导航栏作为SideBarContainer组件的第二个子组件使用，使其成为内容区的一部分，SideBarContainer的侧边栏只会遮挡内容区自身宽度的部分，其余部分可以正常看到。

**参考链接**

[SideBarContainer](../reference/arkui-ts/ts-container-sidebarcontainer.md)

## 如何解决使用foreach&lazyforeach循环渲染时，会出现更改数据源时，界面不刷新的问题(API 10)

**解决措施**

如果缺省keyGenerator，框架会自动基于item和index生成key， 如果函数缺省，框架默认的键值生成函数为(item: T, index: number) => { return index + '__' + JSON.stringify(item); }， 修改状态变量数据源时，要ForEach或LazyForEach会捕捉到key的变化，从而通过重建组件节点来刷新。

**参考链接**

[ForEach：循环渲染](../quick-start/arkts-rendering-control-foreach.md)