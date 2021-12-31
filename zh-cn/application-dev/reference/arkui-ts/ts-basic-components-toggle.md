# Toggle<a name="ZH-CN_TOPIC_0000001193075090"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section1562254617330"></a>

无

## 子组件<a name="section53281531154915"></a>

无

## 接口<a name="section1383178131719"></a>

Toggle\(options: \{ type: ToggleType, isOn?: boolean \}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.110000000000003%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.770000000000003%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.22%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.89%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.010000000000005%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.110000000000003%" headers="mcps1.1.6.1.1 "><p>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.770000000000003%" headers="mcps1.1.6.1.2 "><p><a href="#li544003914117">ToggleType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.22%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.89%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.010000000000005%" headers="mcps1.1.6.1.5 "><p>创建相应的开关状态组件。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.110000000000003%" headers="mcps1.1.6.1.1 "><p>isOn</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.770000000000003%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.22%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.89%" headers="mcps1.1.6.1.4 "><p>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.010000000000005%" headers="mcps1.1.6.1.5 "><p>设置开关状态组件初始化状态。</p>
    <div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>在创建组件时不设置isOn，组件复用时可保持选中状态；如设置isOn初始值，则需要在通过事件方法记录选中状态已达到组件复用时保持选中状态。</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li544003914117"></a>ToggleType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Checkbox</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>提供单选框样式，子组件设置文本不生效，如需文本设置，可将Text和当前组件放入布局组件中。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Button</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>提供状态按钮样式，如果有文本设置，则相应的文本内容会显示在按钮内部。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Switch</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>提供开关样式，子组件设置文本不生效，如需文本设置，可将Text和当前组件放入布局组件中。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section1071518220395"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.669999999999998%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.61%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="49.71%" id="mcps1.1.5.1.4"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.669999999999998%" headers="mcps1.1.5.1.1 "><p>selectedColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.61%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.71%" headers="mcps1.1.5.1.4 "><p>设置组件打开状态的背景颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.669999999999998%" headers="mcps1.1.5.1.1 "><p>switchPointColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.61%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.71%" headers="mcps1.1.5.1.4 "><p>设置Switch类型的圆形滑块颜色。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅对type为ToggleType.Switch生效。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section449664852016"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onChange(callback: (isOn: boolean) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>开关状态切换时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section215304717201"></a>

```
@Entry
@Component
struct ToggleExample {
  build() {
    Column({ space: 10 }) {
      Text('type: Switch').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Switch, isOn: false })
          .selectedColor(0xed6f21)
          .switchPointColor(0xe5ffffff)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Switch, isOn: true })
          .selectedColor(0x39a2db)
          .switchPointColor(0xe5ffffff)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Checkbox').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Checkbox, isOn: false })
          .size({ width: 28, height: 28 })
          .selectedColor(0xed6f21)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .size({ width: 28, height: 28 })
          .selectedColor(0x39a2db)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Button').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Button, isOn: false }) {
          Text('status button').padding({ left: 12, right: 12 })
        }
        .selectedColor(0xed6f21)
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })

        Toggle({ type: ToggleType.Button, isOn: true }) {
          Text('status button').padding({ left: 12, right: 12 })
        }
        .selectedColor(0x39a2db)
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })
      }
    }.width('100%').padding(24)
  }
}
```

![](figures/toggle.gif)

