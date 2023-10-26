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
