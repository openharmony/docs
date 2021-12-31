# 警告弹窗<a name="ZH-CN_TOPIC_0000001237555093"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

显示警告弹窗组件，可设置文本内容与响应回调。

## 属性<a name="section04482591607"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.59%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.15%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="17.89%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="35.370000000000005%" id="mcps1.1.5.1.4"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.59%" headers="mcps1.1.5.1.1 "><p>show</p>
</td>
<td class="cellrowborder" valign="top" width="30.15%" headers="mcps1.1.5.1.2 "><p>options: { <a href="#li132561452141616">paramObject1</a>| <a href="#li45381332179">paramObject2</a>}</p>
</td>
<td class="cellrowborder" valign="top" width="17.89%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="35.370000000000005%" headers="mcps1.1.5.1.4 "><p>定义并显示AlertDialog组件。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li132561452141616"></a>paramObject1参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.96%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.18%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.14%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.329999999999998%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.389999999999997%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.1 "><p>title</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.18%" headers="mcps1.1.6.1.2 "><p>string | Resource</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p>弹窗标题。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.1 "><p>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.18%" headers="mcps1.1.6.1.2 "><p>string | Resource</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p>弹窗内容。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.1 "><p>autoCancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.18%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.6.1.4 "><p>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p>点击遮障层时，是否关闭弹窗。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.1 "><p>confirm</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.18%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>value: string | Resource,</p>
    <p>fontColor?: Color | number | string | Resource,</p>
    <p>backgroundColor?: Color | number | string | Resource,</p>
    <p>action: () =&gt; void</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p>确认按钮的文本内容、文本色、按钮背景色和点击回调。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.1 "><p>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.18%" headers="mcps1.1.6.1.2 "><p>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p>点击遮障层关闭dialog时的回调。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.1 "><p>alignment</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.18%" headers="mcps1.1.6.1.2 "><p><a href="ts-methods-custom-dialog-box.md#li46304184186">DialogAlignment</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.6.1.4 "><p><a href="ts-methods-custom-dialog-box.md#li46304184186">DialogAlignment</a>.Default</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p>弹窗在竖直方向上的对齐方式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.1 "><p>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.18%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>dx: Length | Resource,</p>
    <p>dy: Length  | Resource</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p>弹窗相对alignment所在位置的偏移量。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.1 "><p>gridCount</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.18%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p>弹窗容器宽度所占用栅格数。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li45381332179"></a>paramObject2参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.76%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.53%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.25%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.32%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.14%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.1 "><p>title</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.53%" headers="mcps1.1.6.1.2 "><p>string | Resource</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.6.1.5 "><p>弹窗标题。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.1 "><p>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.53%" headers="mcps1.1.6.1.2 "><p>string | Resource</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.6.1.5 "><p>弹窗内容。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.1 "><p>autoCancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.53%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.6.1.4 "><p>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.6.1.5 "><p>点击遮障层时，是否关闭弹窗。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.1 "><p>primaryButton</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.53%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>value: string | Resource,</p>
    <p>fontColor?: Color | number | string | Resource,</p>
    <p>backgroundColor?: Color | number | string | Resource,</p>
    <p>action: () =&gt; void;</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.6.1.5 "><p>按钮的文本内容、文本色、按钮背景色和点击回调。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.1 "><p>secondaryButton</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.53%" headers="mcps1.1.6.1.2 "><p></p>
    <p>{</p>
    <p>value: string | Resource,</p>
    <p>fontColor?: Color | number | string | Resource,</p>
    <p>backgroundColor?: Color | number | string | Resource,</p>
    <p>action: () =&gt; void;</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.6.1.5 "><p>按钮的文本内容、文本色、按钮背景色和点击回调。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.1 "><p>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.53%" headers="mcps1.1.6.1.2 "><p>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.6.1.5 "><p>点击遮障层关闭dialog时的回调。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.1 "><p>alignment</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.53%" headers="mcps1.1.6.1.2 "><p><a href="ts-methods-custom-dialog-box.md#li46304184186">DialogAlignment</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.6.1.4 "><p><a href="ts-methods-custom-dialog-box.md#li46304184186">DialogAlignment</a>.Default</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.6.1.5 "><p>弹窗在竖直方向上的对齐方式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.1 "><p>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.53%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>dx: Length | Resource,</p>
    <p>dy: Length  | Resource</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.6.1.5 "><p>弹窗相对alignment所在位置的偏移量。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.1 "><p>gridCount</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.53%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.6.1.5 "><p>弹窗容器宽度所占用栅格数。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section1110113275912"></a>

```
@Entry
@Component
struct AlertDialogExample {
  build() {
    Column({ space: 5 }) {
      Button('one button dialog')
        .onClick(() => {
          AlertDialog.show(
            {
              title: 'title',
              message: 'text',
              confirm: {
                value: 'button',
                action: () => {
                  console.info('Button-clicking callback')
                }
              },
              cancel: () => {
                console.info('Closed callbacks')
              }
            }
          )
      })
        .backgroundColor(0x317aff)
      Button('two button dialog')
        .onClick(() => {
          AlertDialog.show(
            {
              title: 'title',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  console.info('Callback when the first button is clicked')
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  console.info('Callback when the second button is clicked')
                }
              },
              cancel: () => {
                console.info('Closed callbacks')
              }
            }
          )
      }).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/AlertDialog.gif)

