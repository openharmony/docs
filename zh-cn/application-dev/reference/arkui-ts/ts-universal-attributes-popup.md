# Popup控制<a name="ZH-CN_TOPIC_0000001192755120"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 属性<a name="section6820191711316"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="12.088791120887912%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="42.165783421657835%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.459254074592541%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="38.28617138286172%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="12.088791120887912%" headers="mcps1.1.5.1.1 "><p>bindPopup</p>
</td>
<td class="cellrowborder" valign="top" width="42.165783421657835%" headers="mcps1.1.5.1.2 "><p>show: boolean,</p>
<p>popup: <a href="#table1488313583914">PopupOption</a> | <a href="#table192660141468">CustomPopupOption</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.459254074592541%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="38.28617138286172%" headers="mcps1.1.5.1.4 "><p>给组件绑定Popup，点击弹出弹窗。</p>
<p>show: 创建页面弹窗提示是否默认显示，默认值为false。</p>
<p>popup: 配置当前弹窗提示的参数。</p>
</td>
</tr>
</tbody>
</table>

-   PopupOption类型接口说明

    <a name="table1488313583914"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.723624975533372%" id="mcps1.1.6.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.82599334507731%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.426306517909572%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.94950088079859%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.074574280681155%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p>弹窗信息内容。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p>placementOnTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p>是否在组件上方显示，默认值为false。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p>primaryButton</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>value: string,</p>
    <p>action: () =&gt; void</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p>第一个按钮。</p>
    <p>value: 弹窗里主按钮的文本。</p>
    <p>action: 点击主按钮的回调函数。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p>secondaryButton</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>value: string,</p>
    <p>action: () =&gt; void</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p>第二个按钮。</p>
    <p>value: 弹窗里辅助按钮的文本。</p>
    <p>action: 点击辅助按钮的回调函数。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p>onStateChange</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p>(isVisible: boolean) =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p>弹窗状态变化事件回调，参数isVisible为弹窗当前的显示状态。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   CustomPopupOption类型接口说明<sup>8+</sup>

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.542963397925234%" id="mcps1.1.6.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.69074182814641%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.605989430416913%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.080250538265807%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.08005480524565%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>builder</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>() =&gt; any</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>提示气泡内容的构造器。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>placement</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p><a href="#li1521155325910">Placement</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>Placement.Bottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>气泡组件优先显示的位置，当前位置显示不下时，会自动调整位置。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>maskColor</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p><a href="../../toctopics/zh-cn_topic_0000001237475069.md#section1326744510818">Color</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>提示气泡遮障层的颜色。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>popupColor</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p><a href="../../toctopics/zh-cn_topic_0000001237475069.md#section1326744510818">Color</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>提示气泡的颜色。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>enableArrow</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>是否显示箭头，只有上、下方向的气泡会显示箭头。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>autoCancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>页面有操作时，是否自动关闭气泡</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>onStateChange</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>(isVisible: boolean) =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>弹窗状态变化事件回调，参数为弹窗当前的显示状态。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Placement枚举说明<sup>8+</sup>

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.180000000000003%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.82%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p>Left</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p>气泡提示位于组件左侧。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p>Right</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p>气泡提示位于组件右侧。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p>Top</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p>气泡提示位于组件上侧。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p>Bottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p>气泡提示位于组件下侧。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p>TopLeft</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p>气泡提示位于组件左上角。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p>TopRight</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p>气泡提示位于组件右上角。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p>BottomLeft</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p>气泡提示位于组件左下角。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p>BottomRight</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p>气泡提示位于组件右下角。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section0760145054817"></a>

```
@Entry
@Component
struct PopupExample {
  @State noHandlePopup: boolean = false
  @State handlePopup: boolean = false
  @State customPopup: boolean = false

  @Builder popupBuilder() {
    Row({ space: 2 }) {
      Image('/resource/ic_public_thumbsup.svg').width(24).height(24).margin({ left: -5 })
      Text('Custom Popup').fontSize(12)
    }.width(100).height(50).backgroundColor(Color.White)
  }

  build() {
    Flex({ direction: FlexDirection.Column }) {
      Button('no handle popup')
        .onClick(() => {
          this.noHandlePopup = !this.noHandlePopup
        })
        .bindPopup(this.noHandlePopup, {
          message: 'content1 content1',
          placementOnTop: false,
          onStateChange: (e) => {
            console.info(e.isVisible.toString())
            if (!e.isVisible) {
              this.noHandlePopup = false
            }
          }
        })
        .position({ x: 100, y: 50 })

      Button('with handle popup')
        .onClick(() => {
          this.handlePopup = !this.handlePopup
        })
        .bindPopup(this.handlePopup, {
          message: 'content2 content2',
          placementOnTop: true,
          primaryButton: {
            value: 'ok',
            action: () => {
              this.handlePopup = !this.handlePopup
              console.info('secondaryButton click')
            }
          },
          onStateChange: (e) => {
            console.info(e.isVisible.toString())
          }
        })
        .position({ x: 100, y: 200 })

      Button('custom popup')
        .onClick(() => {
          this.customPopup = !this.customPopup
        })
        .bindPopup(this.customPopup, {
          builder: this.popupBuilder,
          placement: Placement.Bottom,
          maskColor: 0x33000000,
          popupColor: Color.White,
          enableArrow: true,
          onStateChange: (e) => {
            if (!e.isVisible) {
              this.customPopup = false
            }
          }
        })
        .position({ x: 100, y: 350 })
    }.width('100%').padding({ top: 5 })
  }
}
```

![](figures/popup.gif)

