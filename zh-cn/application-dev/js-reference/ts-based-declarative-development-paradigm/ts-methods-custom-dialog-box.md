# 自定义弹窗<a name="ZH-CN_TOPIC_0000001192158175"></a>

通过CustomDialogController类显示自定义弹窗。

## 接口<a name="section14945157165212"></a>

CustomDialogController\(value:\{builder: CustomDialog, cancel?: \(\) =\> void, autoCancel?: boolean\}\)

-   参数

    <a name="table816913216616"></a>
    <table><thead align="left"><tr id="row016972667"><th class="cellrowborder" valign="top" width="13.16%" id="mcps1.1.6.1.1"><p id="p101691221267"><a name="p101691221267"></a><a name="p101691221267"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.75%" id="mcps1.1.6.1.2"><p id="p616916211613"><a name="p616916211613"></a><a name="p616916211613"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.680000000000001%" id="mcps1.1.6.1.3"><p id="p21691725613"><a name="p21691725613"></a><a name="p21691725613"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.14%" id="mcps1.1.6.1.4"><p id="p4169221969"><a name="p4169221969"></a><a name="p4169221969"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.27%" id="mcps1.1.6.1.5"><p id="p616922465"><a name="p616922465"></a><a name="p616922465"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row617013216610"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.6.1.1 "><p id="p11170822063"><a name="p11170822063"></a><a name="p11170822063"></a>builder</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p151701826617"><a name="p151701826617"></a><a name="p151701826617"></a><a href="ts-component-based-customdialog.md">CustomDialog</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="5.680000000000001%" headers="mcps1.1.6.1.3 "><p id="p151705218616"><a name="p151705218616"></a><a name="p151705218616"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.6.1.4 "><p id="p51702216617"><a name="p51702216617"></a><a name="p51702216617"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.1.6.1.5 "><p id="p1017062765"><a name="p1017062765"></a><a name="p1017062765"></a>自定义弹窗内容构造器。</p>
    </td>
    </tr>
    <tr id="row4170723612"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.6.1.1 "><p id="p171709214610"><a name="p171709214610"></a><a name="p171709214610"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p1517018210613"><a name="p1517018210613"></a><a name="p1517018210613"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.680000000000001%" headers="mcps1.1.6.1.3 "><p id="p141701022068"><a name="p141701022068"></a><a name="p141701022068"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.6.1.4 "><p id="p20170429614"><a name="p20170429614"></a><a name="p20170429614"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.1.6.1.5 "><p id="p0170321361"><a name="p0170321361"></a><a name="p0170321361"></a>点击遮障层退出时的回调。</p>
    </td>
    </tr>
    <tr id="row7170625613"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.6.1.1 "><p id="p11170627619"><a name="p11170627619"></a><a name="p11170627619"></a>autoCancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p71701121661"><a name="p71701121661"></a><a name="p71701121661"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.680000000000001%" headers="mcps1.1.6.1.3 "><p id="p8170192564"><a name="p8170192564"></a><a name="p8170192564"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.6.1.4 "><p id="p161701822061"><a name="p161701822061"></a><a name="p161701822061"></a>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.1.6.1.5 "><p id="p111700219615"><a name="p111700219615"></a><a name="p111700219615"></a>是否允许点击遮障层退出。</p>
    </td>
    </tr>
    <tr id="row4619154917209"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.6.1.1 "><p id="p26193491206"><a name="p26193491206"></a><a name="p26193491206"></a>alignment</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p1461914912207"><a name="p1461914912207"></a><a name="p1461914912207"></a><a href="#li46304184186">DialogAlignment</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="5.680000000000001%" headers="mcps1.1.6.1.3 "><p id="p1161910499207"><a name="p1161910499207"></a><a name="p1161910499207"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.6.1.4 "><p id="p1695856057"><a name="p1695856057"></a><a name="p1695856057"></a><a href="#li46304184186">DialogAlignment</a>.Default</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.1.6.1.5 "><p id="p5620144910200"><a name="p5620144910200"></a><a name="p5620144910200"></a>弹窗在竖直方向上的对齐方式。</p>
    </td>
    </tr>
    <tr id="row1212812822210"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.6.1.1 "><p id="p11128181222"><a name="p11128181222"></a><a name="p11128181222"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p15886722116"><a name="p15886722116"></a><a name="p15886722116"></a>{</p>
    <p id="p450717617111"><a name="p450717617111"></a><a name="p450717617111"></a>dx: Length | Resource,</p>
    <p id="p383151220115"><a name="p383151220115"></a><a name="p383151220115"></a>dy: Length  | Resource</p>
    <p id="p41289862216"><a name="p41289862216"></a><a name="p41289862216"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.680000000000001%" headers="mcps1.1.6.1.3 "><p id="p312819882214"><a name="p312819882214"></a><a name="p312819882214"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.6.1.4 "><p id="p1128158112211"><a name="p1128158112211"></a><a name="p1128158112211"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.1.6.1.5 "><p id="p161281684222"><a name="p161281684222"></a><a name="p161281684222"></a>弹窗相对alignment所在位置的偏移量。</p>
    </td>
    </tr>
    <tr id="row16766162117114"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.6.1.1 "><p id="p117671621201112"><a name="p117671621201112"></a><a name="p117671621201112"></a>customStyle</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p15767021161117"><a name="p15767021161117"></a><a name="p15767021161117"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.680000000000001%" headers="mcps1.1.6.1.3 "><p id="p18767202113110"><a name="p18767202113110"></a><a name="p18767202113110"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.6.1.4 "><p id="p1376710215114"><a name="p1376710215114"></a><a name="p1376710215114"></a>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.1.6.1.5 "><p id="p7767821131117"><a name="p7767821131117"></a><a name="p7767821131117"></a>弹窗容器样式是否自定义。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li46304184186"></a>DialogAlignment枚举说明

    <a name="table1964810186187"></a>
    <table><thead align="left"><tr id="row66471818181813"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p2064711183189"><a name="p2064711183189"></a><a name="p2064711183189"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1764718186187"><a name="p1764718186187"></a><a name="p1764718186187"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9647161818185"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p14647181821813"><a name="p14647181821813"></a><a name="p14647181821813"></a>Top</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p10647131817182"><a name="p10647131817182"></a><a name="p10647131817182"></a>垂直顶部对齐。</p>
    </td>
    </tr>
    <tr id="row164731891816"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p116472181182"><a name="p116472181182"></a><a name="p116472181182"></a>Center</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1464710180184"><a name="p1464710180184"></a><a name="p1464710180184"></a>垂直居中对齐。</p>
    </td>
    </tr>
    <tr id="row76479180187"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p2647131841811"><a name="p2647131841811"></a><a name="p2647131841811"></a>Bottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p7647141812185"><a name="p7647141812185"></a><a name="p7647141812185"></a>垂直底部对齐。</p>
    </td>
    </tr>
    <tr id="row86481518121817"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1464714189186"><a name="p1464714189186"></a><a name="p1464714189186"></a>Default</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p10647191811189"><a name="p10647191811189"></a><a name="p10647191811189"></a>默认对齐。</p>
    </td>
    </tr>
    </tbody>
    </table>


### CustomDialogController<a name="section8664549161612"></a>

创建对象

```
dialogController : CustomDialogController = new CustomDialogController(value:{builder: CustomDialog, cancel?: () => void, autoCancel?: boolean})
```

open\(\)

显示自定义弹窗内容，若已显示，则不生效。

close\(\)

关闭显示的自定义弹窗，若已关闭，则不生效。

## 示例<a name="section1033712576815"></a>

```
@CustomDialog
struct CustomDialogExample {
  controller: CustomDialogController
  cancel: () => void
  confirm: () => void

  build() {
    Column() {
      Text('Software uninstall').width('70%').fontSize(20).margin({ top: 10, bottom: 10 })
      Image($r('app.media.icon')).width(80).height(80)
      Text('Whether to uninstall a software?').fontSize(16).margin({ bottom: 10 })
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        Button('cancel')
          .onClick(() => {
            this.controller.close()
            this.cancel()
          }).backgroundColor(0xffffff).fontColor(Color.Black)
        Button('confirm')
          .onClick(() => {
            this.controller.close()
            this.confirm()
          }).backgroundColor(0xffffff).fontColor(Color.Red)
      }.margin({ bottom: 10 })
    }
  }
}

@Entry
@Component
struct CustomDialogUser {
  dialogController: CustomDialogController = new CustomDialogController({
    builder: CustomDialogExample({ cancel: this.onCancel, confirm: this.onAccept }),
    cancel: this.existApp,
    autoCancel: true
  })

  onCancel() {
    console.info('Callback when the first button is clicked')
  }
  onAccept() {
    console.info('Callback when the second button is clicked')
  }
  existApp() {
    console.info('Click the callback in the blank area')
  }

  build() {
    Column() {
      Button('click me')
        .onClick(() => {
          this.dialogController.open()
        }).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/customdialog.gif)

