# Button<a name="ZH-CN_TOPIC_0000001192755124"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供按钮组件。

## 权限列表<a name="section173151571452"></a>

无

## 子组件<a name="section13412913174619"></a>

可以包含子组件。

## 接口<a name="section124082310463"></a>

-   Button\(options?: \{type?: ButtonType, stateEffect?: boolean\}\)

    **表 1**  options参数说明

    <a name="table712610266288"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.2.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.47%" id="mcps1.2.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.03%" id="mcps1.2.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.18%" id="mcps1.2.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.2.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.47%" headers="mcps1.2.6.1.2 "><p>ButtonType</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.03%" headers="mcps1.2.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.2.6.1.4 "><p>Capsule</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p>描述按钮风格。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p>stateEffect</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.47%" headers="mcps1.2.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.03%" headers="mcps1.2.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.2.6.1.4 "><p>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p>按钮按下时是否开启切换效果，当状态置为false时，点击效果关闭。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Button\(label?: string, options?: \{ type?: ButtonType, stateEffect?: boolean \}\)

    使用文本内容创建相应的按钮组件，此时Button无法包含子组件。

    **表 2**  value参数说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.2.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.2.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.49%" id="mcps1.2.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.18%" id="mcps1.2.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.2.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p>label</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.2.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.2.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.2.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p>按钮文本内容。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.2.6.1.2 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.2.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.2.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p>见<a href="#table712610266288">options参数说明</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section94181084473"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.389999999999999%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.430000000000001%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.87%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="60.309999999999995%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="14.430000000000001%" headers="mcps1.1.5.1.2 "><p><a href="#li93236107910">ButtonType</a></p>
</td>
<td class="cellrowborder" valign="top" width="11.87%" headers="mcps1.1.5.1.3 "><p>Capsule</p>
</td>
<td class="cellrowborder" valign="top" width="60.309999999999995%" headers="mcps1.1.5.1.4 "><p>设置Button样式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.1 "><p>stateEffect</p>
</td>
<td class="cellrowborder" valign="top" width="14.430000000000001%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.87%" headers="mcps1.1.5.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="60.309999999999995%" headers="mcps1.1.5.1.4 "><p>状态切换时是否开启切换效果，当状态置为false时，点击效果关闭。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li93236107910"></a>ButtonType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.3%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.7%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.3%" headers="mcps1.1.3.1.1 "><p>Capsule</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.7%" headers="mcps1.1.3.1.2 "><p>胶囊型按钮（圆角默认为高度的一半）。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.3%" headers="mcps1.1.3.1.1 "><p>Circle</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.7%" headers="mcps1.1.3.1.2 "><p>圆形按钮。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.3%" headers="mcps1.1.3.1.1 "><p>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.7%" headers="mcps1.1.3.1.2 "><p>普通按钮（默认不带圆角）。</p>
    </td>
    </tr>
    </tbody>
    </table>


>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   按钮圆角通过[通用属性borderRadius设置](ts-universal-attributes-border.md)（不支持通过border接口设置圆角）。
>-   按钮文本通过[通用文本样式](ts-universal-attributes-text-style.md)进行设置。

## 示例<a name="section449999124812"></a>

```
@Entry
@Component
struct ButtonExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Common button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Ok', { type: ButtonType.Normal, stateEffect: true }).borderRadius(8).backgroundColor(0x317aff).width(90)
        Button({ type: ButtonType.Normal, stateEffect: true }) {
          Row() {
            Image($r('app.media.loading')).width(20).height(20).margin({ left: 12 })
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })
          }.alignItems(VerticalAlign.Center)
        }.borderRadius(8).backgroundColor(0x317aff).width(90)
        Button('Disable', { type: ButtonType.Normal, stateEffect: false }).opacity(0.5)
          .borderRadius(8).backgroundColor(0x317aff).width(90)
      }

      Text('Capsule button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Ok', { type: ButtonType.Capsule, stateEffect: true }).backgroundColor(0x317aff).width(90)
        Button({ type: ButtonType.Capsule, stateEffect: true }) {
          Row() {
            Image($r('app.media.loading')).width(20).height(20).margin({ left: 12 })
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })
          }.alignItems(VerticalAlign.Center).width(90)
        }.backgroundColor(0x317aff)
        .onClick((event: ClickEvent) => {
          AlertDialog.show({ message: 'The login is successful' })
        })
        Button('Disable', { type: ButtonType.Capsule, stateEffect: false }).opacity(0.5)
          .backgroundColor(0x317aff).width(90)
      }

      Text('Circle button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, wrap: FlexWrap.Wrap }) {
        Button({ type: ButtonType.Circle, stateEffect: true }) {
          Image($r('app.media.ic_public_app_filled')).width(20).height(20)
        }.width(55).height(55).backgroundColor(0x317aff)
        Button({ type: ButtonType.Circle, stateEffect: true }) {
          Image($r('app.media.ic_public_delete_filled')).width(30).height(30)
        }.width(55).height(55).margin({ left: 20 }).backgroundColor(0xF55A42)
      }
    }.height(400).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/Button.gif)

