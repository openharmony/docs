# alert_dialog    
显示警告弹窗组件，可设置文本内容与响应回调。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## DialogAlignment    
DialogAlignment枚举说明。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Top | 0 | 垂直顶部对齐。 |  
| Center | 1 | 垂直居中对齐。 |  
| Bottom | 2 | 垂直底部对齐。 |  
| Default | 3 | 默认对齐。 |  
| TopStart<sup>(8+)</sup> | 4 | 左上对齐。 |  
| TopEnd<sup>(8+)</sup> | 5 | 右上对齐。 |  
| CenterStart<sup>(8+)</sup> | 6 | 左中对齐。 |  
| CenterEnd<sup>(8+)</sup> | 7 | 右中对齐。 |  
| BottomStart<sup>(8+)</sup> | 8 | 左下对齐。 |  
| BottomEnd<sup>(8+)</sup> | 9 | 右下对齐。 |  
    
## DialogButtonDirection<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| AUTO | 0 | 两个及以下按钮水平排布，两个以上为竖直排布。 |  
| HORIZONTAL | 1 | 按钮水平布局。 |  
| VERTICAL | 2 | 按钮竖直布局。 |  
    
## AlertDialogButtonOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| enabled<sup>(10+)</sup> | boolean | false | false | 点击button是否响应，默认值true。 |  
| defaultFocus<sup>(10+)</sup> | boolean | false | false | 设置button是否是默认焦点，默认值false。 |  
| style<sup>(10+)</sup> | DialogButtonStyle | false | false | 设置button的风格样式，默认值DialogButtonStyle.DEFAULT。 |  
| value<sup>(10+)</sup> | ResourceStr | false | true | 按钮的文本内容，若值为null，则该按钮不显示。 |  
| fontColor<sup>(10+)</sup> | ResourceColor | false | false | 按钮的文本颜色。 |  
| backgroundColor<sup>(10+)</sup> | ResourceColor | false | false | 按钮背景颜色。 |  
| action<sup>(10+)</sup> | function | false | true | 按钮选中时的回调。 |  
    
## AlertDialogParam  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title | ResourceStr | false | false | 弹窗标题。 |  
| subtitle<sup>(10+)</sup> | ResourceStr | false | false | 弹窗子标题。 |  
| message | ResourceStr | false | true | 弹窗内容。 |  
| autoCancel | boolean | false | false | 点击遮障层时，是否关闭弹窗。<br>默认值：true |  
| cancel | function | false | false | 点击遮障层关闭dialog时的回调。 |  
| alignment | DialogAlignment | false | false | 弹窗在竖直方向上的对齐方式。<br>默认值：DialogAlignment.Default |  
| offset | Offset | false | false | 弹窗相对alignment所在位置的偏移量。 |  
| gridCount | number | false | false | 弹窗容器宽度所占用栅格数。 |  
| maskRect<sup>(10+)</sup> | Rectangle | false | false | 弹窗遮蔽层区域，在遮蔽层区域内的事件不透传，在遮蔽层区域外的事件透传。<br/>默认值：{ x: 0, y: 0, width: '100%', height: '100%' } |  
    
## AlertDialogParamWithConfirm  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| confirm | object | false | false | 确认按钮的使能状态、默认焦点、按钮风格、文本内容、文本色、按钮背景色和点击回调。<br />enabled：点击button是否响应。<br />默认值：true。<br />defaultFocus：设置button是否是默认焦点。<br />默认值：false。<br />style：设置button的风格样式。<br />默认值：DialogButtonStyle.DEFAULT。<br />value：按钮文本内容。<br />fontColor：按钮文本颜色。<br />backgroundColor：按钮背景颜色。<br />action：按钮选中时的回调。 |  
    
## AlertDialogParamWithButtons  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| primaryButton | object | false | true | 确认按钮的使能状态、默认焦点、按钮风格、文本内容、文本色、按钮背景色和点击回调。<br />enabled：点击button是否响应。<br />默认值：true。<br />defaultFocus：设置button是否是默认焦点。<br />默认值：false。<br />style：设置button的风格样式。<br />默认值：DialogButtonStyle.DEFAULT。<br />value：按钮文本内容。<br />fontColor：按钮文本颜色。<br />backgroundColor：按钮背景颜色。<br />action：按钮选中时的回调。 |  
| secondaryButton | object | false | true | 确认按钮的使能状态、默认焦点、按钮风格、文本内容、文本色、按钮背景色和点击回调。<br />enabled：点击button是否响应。<br />默认值：true。<br />defaultFocus：设置button是否是默认焦点。<br />默认值：false。<br />style：设置button的风格样式。<br />默认值：DialogButtonStyle.DEFAULT。<br />value：按钮文本内容。<br />fontColor：按钮文本颜色。<br />backgroundColor：按钮背景颜色。<br />action：按钮选中时的回调。 |  
    
## AlertDialogParamWithOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| buttons<sup>(10+)</sup> | Array<AlertDialogButtonOptions> | false | true | 弹窗容器中的多个按钮。 |  
| buttonDirection<sup>(10+)</sup> | DialogButtonDirection | false | false | 按钮排布方向默认值为DialogButtonDirection.AUTO，建议3个以上按钮使用Auto模式（两个以上按钮会切换为纵向模式，通常能显示更多按钮），非Auto模式下，3个以上按钮可能会显示不全，超出显示范围的按钮会被截断。 |  
    
## AlertDialog  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### show    
定义并显示AlertDialog组件。  
 **调用形式：**     
- static show(value: AlertDialogParamWithConfirm | AlertDialogParamWithButtons | AlertDialogParamWithOptions)  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
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
              autoCancel: true,  
              alignment: DialogAlignment.Bottom,  
              offset: { dx: 0, dy: -20 },  
              gridCount: 3,  
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
              subtitle: 'subtitle',  
              message: 'text',  
              autoCancel: true,  
              alignment: DialogAlignment.Bottom,  
              gridCount: 4,  
              offset: { dx: 0, dy: -20 },  
              primaryButton: {  
                value: 'cancel',  
                action: () => {  
                  console.info('Callback when the first button is clicked')  
                }  
              },  
              secondaryButton: {  
                enabled: true,  
                defaultFocus: true,  
                style: DialogButtonStyle.HIGHLIGHT,  
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
        Button('three button dialog')  
        .onClick(() => {  
          AlertDialog.show(  
            {  
              title: 'title',  
              subtitle: 'subtitle',  
              message: 'text',  
              autoCancel: true,  
              alignment: DialogAlignment.Bottom,  
              gridCount: 4,  
              offset: { dx: 0, dy: -20 },  
              buttonDirection: DialogButtonDirection.HORIZONTAL,  
              buttons: [  
                {  
                  value: '按钮',  
                  action: () => {  
                    console.info('Callback when button1 is clicked')  
                  }  
                },  
                {  
                  value: '按钮',  
                  action: () => {  
                    console.info('Callback when button2 is clicked')  
                  }  
                },  
                {  
                  value: '按钮',  
                  enabled: true,  
                  defaultFocus: true,  
                  style: DialogButtonStyle.HIGHLIGHT,  
                  action: () => {  
                    console.info('Callback when button3 is clicked')  
                  }  
                },  
              ],  
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
  
![zh-cn_image_alert](figures/zh-cn_image_alert.gif)  
