# Tabs<a name="ZH-CN_TOPIC_0000001237475055"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

一种可以通过页签进行内容视图切换的容器组件，每个页签对应一个内容视图。

## 支持设备<a name="section322851519172"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.66106080206986%" id="mcps1.1.5.1.1"><p>手机</p>
</th>
<th class="cellrowborder" valign="top" width="26.3130659767141%" id="mcps1.1.5.1.2"><p>平板</p>
</th>
<th class="cellrowborder" valign="top" width="24.63130659767141%" id="mcps1.1.5.1.3"><p>智慧屏</p>
</th>
<th class="cellrowborder" valign="top" width="25.39456662354463%" id="mcps1.1.5.1.4"><p>智能穿戴</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.66106080206986%" headers="mcps1.1.5.1.1 "><p>支持</p>
</td>
<td class="cellrowborder" valign="top" width="26.3130659767141%" headers="mcps1.1.5.1.2 "><p>支持</p>
</td>
<td class="cellrowborder" valign="top" width="24.63130659767141%" headers="mcps1.1.5.1.3 "><p>不支持</p>
</td>
<td class="cellrowborder" valign="top" width="25.39456662354463%" headers="mcps1.1.5.1.4 "><p>不支持</p>
</td>
</tr>
</tbody>
</table>

## 权限列表<a name="section988262631714"></a>

无

## 子组件<a name="section5989144051714"></a>

包含子组件[TabContent](ts-container-tabcontent.md)。

## 接口说明<a name="section97451749121712"></a>

Tabs\(value: \{barPosition?: BarPosition, index?: number, controller?:  [TabsController](#section104288910399)\}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.3%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.77%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.6%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>barPosition</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.1.6.1.2 "><p><a href="#li15340346135115">BarPosition</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p>Start</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p>指定页签位置来创建Tabs容器组件。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>index</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p>指定初次初始页签索引。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>controller</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.1.6.1.2 "><p><a href="#section104288910399">TabsController</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 ">&nbsp;&nbsp;</td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p>设置Tabs控制器。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li15340346135115"></a>BarPosition枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="28.360000000000003%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="71.64%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p>Start</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p>vertical属性方法设置为true时，页签位于容器左侧；vertical属性方法设置为false时，页签位于容器顶部。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p>End</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p>vertical属性方法设置为true时，页签位于容器右侧；vertical属性方法设置为false时，页签位于容器底部。</p>
    </td>
    </tr>
    </tbody>
    </table>


### TabsController<a name="section104288910399"></a>

Tabs组件的控制器，用于控制Tabs组件进行页签切换。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="26.99%" id="mcps1.1.3.1.1"><p>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="73.00999999999999%" id="mcps1.1.3.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="26.99%" headers="mcps1.1.3.1.1 "><p>changeIndex(value: number): void</p>
</td>
<td class="cellrowborder" valign="top" width="73.00999999999999%" headers="mcps1.1.3.1.2 "><p>控制Tabs切换到指定页签，index: 页签在Tabs里的索引值，索引值从0开始。</p>
</td>
</tr>
</tbody>
</table>

## 属性<a name="section1738516911810"></a>

不支持触摸热区设置。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.82%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.840000000000002%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="19.75%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="46.589999999999996%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p>vertical</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p>是否为纵向Tab，默认为false。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p>是否为纵向Tab，默认为false。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p>scrollable</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p>是否可以通过左右滑动进行页面切换，默认为true。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p>是否可以通过左右滑动进行页面切换，默认为true。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p>barMode</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p><a href="#li386615395316">BarMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p>TabBar布局模式。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p>TabBar布局模式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p>barWidth</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p>TabBar的宽度值，不设置时使用系统主题中的默认值。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p>TabBar的宽度值，不设置时使用系统主题中的默认值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p>barHeight</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p>TabBar的高度值，不设置时使用系统主题中的默认值。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p>TabBar的高度值，不设置时使用系统主题中的默认值<strong>。</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p>animationDuration</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p>200</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p>TabContent滑动动画时长。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li386615395316"></a>BarMode枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Scrollable</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>TabBar使用实际布局宽度, 超过总长度后可滑动。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Fixed</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>所有TabBar平均分配宽度。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section6741113101919"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onChange(callback: (index: number) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Tab页签切换后触发的事件。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section1131255321814"></a>

```
@Entry
@Component
struct TabsExample {
  private controller: TabsController = new TabsController()

  build() {
    Column() {
      Tabs({ barPosition: BarPosition.Start, index: 1, controller: this.controller }) {
        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Pink)
        }.tabBar('pink')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Yellow)
        }.tabBar('yellow')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Blue)
        }.tabBar('blue')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Green)
        }.tabBar('green')
      }
      .vertical(true).scrollable(true).barMode(BarMode.Fixed)
      .barWidth(70).barHeight(150).animationDuration(400)
      .onChange((index: number) => {
        console.info(index.toString())
      })
      .width('90%').backgroundColor(0xF5F5F5)
    }.width('100%').height(150).margin({ top: 5 })
  }
}
```

![](figures/Tabs.gif)

