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

## cl.arkui.5 菜单避让手机挖孔变更

**访问级别**

公开接口

**变更原因**

开发者在应用侧的module.json5中配置开启避让手机挖孔时，菜单未避让挖孔。

``` json
{
    "module": {
        "metadata": [
            {
                "name" : "avoid_cutout",
                "value": "true",
            }
        ]
    }
}
```

**变更影响**

该变更为不兼容性变更。

变更前：竖屏时菜单默认避让挖孔；横屏时，应用配置开启避让手机挖孔，菜单不会避让挖孔。

变更后：竖屏时菜单默认避让挖孔；横屏时，应用配置开启避让手机挖孔，菜单会避让挖孔。

**起始API Level**

Menu组件的BindMenu接口 API 7

Menu组件的BindContextMenu接口 API 8

**变更发生版本**

从OpenHarmony SDK 5.0.0.35开始。

**变更的接口/组件**

Menu组件的BindMenu接口

Menu组件的BindContextMenu接口

**适配指导**

默认行为变更，无需适配。

## cl.arkui.6 Repeat设置totalCount属性行为变更

**访问级别**

公开接口

**变更原因**

totoalCount表示UI显示的数据个数。Repeat设置totalCount属性时，如果totalCount小于数据长度，显示的数据个数为数据的长度，与totalCount定义不符。

**变更影响**

该变更为不兼容性变更。

变更前：Repeat设置totalCount属性时，如果totalCount小于数据长度，显示的数据个数为数据的长度

变更后：Repeat设置totalCount属性时，如果totalCount小于数据长度，显示的数据个数为totalCount值

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.35开始。

**变更的接口/组件**

Repeat组件。

**适配指导**

如果开发者想要显示的数据个数为数据长度时，需要将totalCount值设置为数组长度。示例代码如下：

```ts
@Entry
@ComponentV2
struct TestPage {
  @Local simpleList: Array<string> = [];
  private totalCount: number = 50;

  aboutToAppear(): void {
    for (let i = 0; i < 50; i++) {
      this.simpleList.push('Hello ' + i);
    }
  }

  build() {
    Column({ space: 10 }) {
      List() {
        Repeat<string>(this.simpleList)
          .each((obj: RepeatItem<string>) => {
            ListItem() {
              Text('[each] ' + obj.item)
                .fontSize(30)
                .margin({ top: 10 })
            }
          })
          .key((item: string, index: number) => item)
          .virtualScroll({ totalCount: this.totalCount })
          .templateId((item: string, index: number) => "default")
          .template('default', (ri) => {
            Text('[template] ' + ri.item)
              .fontSize(30)
              .margin({ top: 10 })
          }, { cachedCount: 3 })
      }
      .cachedCount(1)
      .border({ width: 1 })
      .height('50%')
    }
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

## cl.arkui.7 TimePickerDialog标题高度变更

**访问级别**

公开接口

**变更原因**

修正视觉效果以获得更好的用户体验。

**变更影响**

该变更为不兼容变更。

变更前：标题高度为46vp。

变更后：标题高度为56vp。

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/TimePickerDialog_Before.png) | ![](figures/TimePickerDialog_After.png) |

**起始API Level**

8

**变更发生版本**

从OpenHarmony SDK 5.0.0.35开始。

**变更的接口/组件**

TimePickerDialog组件。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.8 AlertDialog、promptAction.showDialog中Button间距变更

**访问级别**

公开接口

**变更原因**

修正视觉效果以获得更好的用户体验。

**变更影响**

该变更为不兼容变更。

变更前：Button间距为8vp。

变更后：Button间距为16vp。

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/AlertDialog_Before.png) | ![](figures/AlertDialog_After.png) |

**起始API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.0.0.35开始。

**变更的接口/组件**

AlertDialog、promptAction.showDialog。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.9 SubMenu避让底部导航条距离变更

**访问级别**

公开接口

**变更原因**

Menu避让能贴近底部导航条，而SubMenu避让位置无法贴近底部导航条，视觉效果不好

**变更影响**

该变更为不兼容性变更。

| 变更前：SubMenu避让底部导航条之后避让了一个固定高度的padding | 变更后：SubMenu仅避让底部导航条，不额外添加固定高度的padding |
|---------|---------|
|  ![变更前有间距](figures/submenu-padding-bottom-before.jpg)       |  ![变更后删除间距](figures/submenu-padding-bottom-after.jpg)    

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.35开始。

**变更的接口/组件**

Menu组件。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.7 menu、toast修改阴影参数
**访问级别**

公开接口

**变更原因**

当前阴影不明显，区分度不高。

**变更影响**

该变更为不兼容性变更。

| 变更前阴影 | 变更后阴影|
|---------|---------|
|  ![Menu_before](figures/Menu_before.jpeg)       |  ![Menu_before](figures/Menu_after.jpeg)       |
|  ![Toast_before](figures/Toast_before.jpeg)       |  ![Toast_before](figures/Toast_after.jpeg)       |

**起始API Level**

Menu组件的BindMenu接口 API 7

Menu组件的BindContextMenu接口 API 8

Toast组件的ShowToast接口 API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.35开始。

**变更的接口/组件**

Menu组件的BindMenu接口

Menu组件的BindContextMenu接口

Toast组件ShowToast接口

**适配指导**

默认行为变更，无需适配。

## @ohos.deviceStatus.dragInteraction.d.ts 文件接口权限变更

**访问级别**

系统接口。

**变更原因**

根据安全要求规范，将该文件的所有系统接口函数添加接口权限校验。

**变更影响**

该变更为不兼容性变更，非系统应用调用接口会抛出202错误码。

**起始API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口**

| 接口声明 | 变更前 | 变更后 |
| ------------------------------------------------------------ | --------- | ------ |
| on(type: 'drag', callback: Callback\<DragState>): void       | 不抛出202错误码 | 抛出202错误码 |
| off(type: 'drag', callback?: Callback\<DragState>): void     | 不抛出202错误码 | 抛出202错误码 |

**适配指导**

默认行为变更，无需适配。