# action_sheet    
列表弹窗。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SheetInfo  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title | string \| Resource | false | true | 选项的文本内容。 |  
| icon | string \| Resource | false | false | 选项的图标，默认无图标显示。 |  
| action | function | false | true | 选项选中的回调。 |  
    
## ActionSheetOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title | string \| Resource | false | true | 弹窗标题。 |  
| subtitle<sup>(10+)</sup> | ResourceStr | false | false | 弹窗副标题。 |  
| message | string \| Resource | false | true | 弹窗内容。 |  
| confirm | object | false | false | 确认按钮的使能状态、默认焦点、按钮风格、文本内容和点击回调。<br>enabled：点击button是否响应。<br />默认值：true。<br />defaultFocus：设置button是否是默认焦点。<br />默认值：false。<br />style：设置button的风格样式。<br />默认值：DialogButtonStyle.DEFAULT。<br/>value：按钮文本内容。<br/>action:按钮选中时的回调。 |  
| cancel | function | false | false | 点击遮障层关闭dialog时的回调。 |  
| sheets | Array<SheetInfo> | false | true | 设置选项内容，每个选择项支持设置图片、文本和选中的回调。 |  
| autoCancel | boolean | false | false | 点击遮障层时，是否关闭弹窗。<br>默认值：true<br>值为true时，点击遮障层关闭弹窗，值为false时，点击遮障层不关闭弹窗。 |  
| alignment | DialogAlignment | false | false | 弹窗在竖直方向上的对齐方式。<br>默认值：DialogAlignment.Bottom |  
| offset | object | false | false | 弹窗相对alignment所在位置的偏移量。{<br/>dx:0,<br/>dy:0<br/>} |  
| maskRect<sup>(10+)</sup> | Rectangle | false | false | 弹窗遮蔽层区域，在遮蔽层区域内的事件不透传，在遮蔽层区域外的事件透传。<br/>默认值：{ x: 0, y: 0, width: '100%', height: '100%' } |  
    
## ActionSheet  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### show    
定义列表弹窗并弹出。  
  
 **调用形式：**     
- static show(value: ActionSheetOptions)  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ActionSheetOptions | true |  |  
    
 **示例代码：**   
```ts    
@Entry  
@Component  
struct ActionSheetExample {  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {  
      Button('Click to Show ActionSheet')  
        .onClick(() => {  
          ActionSheet.show({  
            title: 'ActionSheet title',  
            subtitle: 'ActionSheet subtitle',  
            message: 'message',  
            autoCancel: true,  
            confirm: {  
              defaultFocus: true,  
              value: 'Confirm button',  
              action: () => {  
                console.log('Get Alert Dialog handled')  
              }  
            },  
            cancel: () => {  
              console.log('actionSheet canceled')  
            },  
            alignment: DialogAlignment.Bottom,  
            offset: { dx: 0, dy: -10 },  
            sheets: [  
              {  
                title: 'apples',  
                action: () => {  
                  console.log('apples')  
                }  
              },  
              {  
                title: 'bananas',  
                action: () => {  
                  console.log('bananas')  
                }  
              },  
              {  
                title: 'pears',  
                action: () => {  
                  console.log('pears')  
                }  
              }  
            ]  
          })  
        })  
    }.width('100%')  
    .height('100%')  
  }  
}  
    
```    
  
![zh-cn_image_action](figures/zh-cn_image_action.gif)  
