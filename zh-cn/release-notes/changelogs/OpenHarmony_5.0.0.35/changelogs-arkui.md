## cl.arkui.1 Menu组件箭头离宿主节点默认安全边距变更

**访问级别**

公开接口

**变更原因**

带箭头菜单离宿主节点过远，变更后效果更佳。

**变更影响**

| 变更前箭头离宿主节点16vp | 变更后箭头离宿主节点8vp |
|---------|---------|
|  ![变更前箭头离宿主节点16vp](figures/menu-with-arrow-16vp.png)       |  ![变更后箭头离宿主节点8vp](figures/menu-with-arrow-8vp.png)       |

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.35 版本开始。

**变更的接口/组件**

Menu组件。

**适配指导**

带箭头菜单离宿主节点的默认安全距离变小，若需要更大的间距，可设置菜单的offset进行调整。

## cl.arkui.2 MenuItemGroup嵌套MenuItem且MenuItem设置margin top或者bottom时，布局效果变更

**访问级别**

公开接口

**变更原因**

MenuItemGroup高度没有加上MenuItem的margin高度，布局错乱，变更后布局正常。

**变更影响**

| 变更前布局错乱 | 变更后布局正常 |
|---------|---------|
|  ![变更前布局错乱](figures/menuitemgroup-height-without-item-margin.jpg)       |  ![变更后布局正常](figures/menuitemgroup-height-with-item-margin.jpg)       |

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.35 版本开始。

**变更的接口/组件**

Menu组件。

**适配指导**

菜单布局效果变更，应用无需适配。

## cl.arkui.3 Menu中MenuItem全部设置margin后，左右边距布局效果变更

**访问级别**

公开接口

**变更原因**

Menu中MenuItem全部设置margin后，左右边距不对称，变更后左右对称。

**变更影响**

| 变更前边距不对称 | 变更后左右对称 |
|---------|---------|
|  ![变更前边距不对称](figures/menuitem-not-center-with-margin.jpg)       |  ![变更后左右对称](figures/menuitem-is-center-with-margin.jpg)       |

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.35 版本开始。

**变更的接口/组件**

Menu组件。

**适配指导**

菜单布局效果变更，应用无需适配。

## cl.arkui.4 点击Menu菜单区域外的空白区域，关闭菜单交互行为变更

**访问级别**

公开接口

**变更原因**

点击Menu菜单区域外的空白区域，当前为点击按下时菜单就关闭，变更为点击按下-抬手才关闭菜单。

**变更影响**

变更前：点击菜单以外的空白区域，按下时关闭菜单

变更后：点击菜单以外的空白区域，抬手时关闭菜单

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.35 版本开始。

**变更的接口/组件**

Menu组件。

**适配指导**

菜单关闭交互行为变更，应用无需适配。