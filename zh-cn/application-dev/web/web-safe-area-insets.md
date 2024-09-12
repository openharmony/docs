# 网页中安全区域计算和避让适配

Web组件提供了利用W3C CSS进行安全区域计算并避让适配的能力，用来支持异形屏幕设备在沉浸式效果下页面的正常显示。

## 实现原理

ArkWeb内核会监听Web组件及系统安全区域的位置和尺寸，根据两者的重叠区域计算当前Web组件的安全区域以及各个方向上需要避让的距离。

## 使用场景

安全区域是指页面的显示区域，默认不与系统设置的非安全区域比如状态栏、导航栏区域重叠，开发者开发的界面都被布局在安全区域内。当Web组件应用了沉浸式效果时，网页内元素就可能会出现与状态栏或导航栏区域重叠的体验问题。

此时，网页开发者想对重叠元素进行避让，就可以使用该功能。

### Web组件开启沉浸式效果

开发者可以通过[expandSafeArea](../reference/apis-arkui/arkui-ts/ts-universal-attributes-expand-safe-area.md#expandsafearea)来开启沉浸式效果。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .width('100%').height('100%')
          .expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM])
      }
    }
  }
  ```

### 设置网页在可视窗口中的布局方式
`viewport-fit`用于限制网页在安全区域内的展示形态。默认为`auto`，与`contain`表现一致，表示可视窗口完全包含网页内容，即网页全部内容展示于安全区域内。而`cover`则表示网页内容完全覆盖可视窗口，即网页内容不仅展示于安全区域，还包含非安全区域，即可能与状态栏和导航栏发生重叠，只有这种场景下网页需要进行避让适配，设置方式如下：
```
<meta name='viewport' content='viewport-fit=cover'>
```
### 网页元素进行避让适配

网页元素进行避让适配，主要利用`env()` CSS函数，用于向CSS插入用户代码定义的变量，允许开发人员将其内容放置在视口的安全区域中，该规范中定义的`safe-area-inset-*`值可用于确保内容即使在非矩形的视区中也可以完全显示，语法如下：
```
/* 直接使用四个safe-area-inset-*环境变量值 */
env(safe-area-inset-top);
env(safe-area-inset-right);
env(safe-area-inset-bottom);
env(safe-area-inset-left);

/* 基于fallback使用四个safe-area-inset-*环境变量值 */
/* 下述长度单位参见：https://developer.mozilla.org/zh-CN/docs/Web/CSS/length */
env(safe-area-inset-top, 20px);
env(safe-area-inset-right, 1em);
env(safe-area-inset-bottom, 0.5vh);
env(safe-area-inset-left, 1.4rem);
```
`safe-area-inset-top`, `safe-area-inset-right`, `safe-area-inset-bottom`, `safe-area-inset-left`
> `safe-area-inset-*`由四个定义了视口边缘内矩形的 top, right, bottom 和 left 的环境变量组成，这样可以安全地放入内容，而不会有被非矩形的显示切断的风险。对于矩形视口，例如普通的2in1设备显示器，其值等于零。对于非矩形显示器（如圆形表盘，移动设备屏幕等），在用户代理设置的四个值形成的矩形内，所有内容均可见。

不同于其他的 CSS 属性，用户代理定义的属性名字对大小写敏感。同时，需要注意`env()`必须配合`viewport-fit=cover`使用。

对于一些购物网站，首页网页底部为tab形式的fix元素，在沉浸式状态下这些fix元素就需要进行底部避让，以防止fix元素与系统导航条发生重叠遮挡，举例如下：
```
.tab-bottom {
    padding-bottom: env(safe-area-inset-bottom);
}
```
同时，上述`env()`使用还能基于部分数学计算函数`calc()`,`min()`,`max()`组合计算，如：
```
.tab-bottom {
    padding-bottom: max(env(safe-area-inset-bottom), 30px);
}
```
