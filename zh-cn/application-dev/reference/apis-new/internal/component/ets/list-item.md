# list_item    
用来展示列表具体item，必须配合List来使用。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## Sticky<sup>(deprecated)</sup>    
从API version9开始废弃，推荐使用<a href="https://gitee.com/openharmony/docs/blob/weekly_20231010/zh-cn/application-dev/reference/arkui-ts/ts-container-list.md#stickystyle9%E6%9E%9A%E4%B8%BE%E8%AF%B4%E6%98%8E">List组件stickyStyle枚举</a>。  
    
从API version 7 开始支持，从API version 9 开始废弃。建议使用list/StickyStyle替代。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>无吸顶效果。 |  
| Normal<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>当前item吸顶。 |  
| Opacity<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>当前item吸顶显示透明度变化效果。 |  
    
## EditMode<sup>(deprecated)</sup>    
从API version9开始废弃。  
    
从API version 7 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>编辑操作不限制。 |  
| Deletable<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>可删除。 |  
| Movable<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br><span style="letter-spacing: 0px;">可移动。</span> |  
    
## SwipeEdgeEffect<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Spring | 0 | ListItem划动距离超过划出组件大小后可以继续划动。如果设置了删除区域，ListItem划动距离超过删除阈值后可以继续划动，松手后按照弹簧阻尼曲线回弹。 |  
| None | 1 | ListItem划动距离不能超过划出组件大小。如果设置了删除区域，ListItem划动距离不能超过删除阈值，并且在设置删除回调的情况下，达到删除阈值后松手触发删除回调。 |  
    
## SwipeActionItem<sup>(10+)</sup>    
List垂直布局，ListItem向右滑动，item左边的长距离滑动删除选项或向左滑动时，item右边的长距离滑动删除选项。 List水平布局，ListItem向上滑动，item下边的长距离滑动删除选项或向下滑动时，item上边的长距离滑动删除选项。  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| builder<sup>(10+)</sup> | CustomBuilder | false | false | 当列表项向右或向右滑动（当列表方向为“垂直”时），向下或向下滑动（当列方向为“水平”时）时显示的操作项。<br/> |  
| actionAreaDistance<sup>(10+)</sup> | Length | false | false | 设置组件长距离滑动删除距离阈值。<br/>默认值：56vp<br/><strong>说明：</strong><br/>不支持设置百分比。<br/>删除距离阈值大于item宽度减去划出组件宽度，或删除距离阈值小于等于0就不会设置删除区域。<br/> |  
| onAction<sup>(10+)</sup> | function | false | false | 组件进入长距删除区后删除ListItem时调用，进入长距删除区后抬手时触发。<br/><strong>说明：</strong><br/>滑动后松手的位置超过或等于设置的距离阈值，并且设置的距离阈值有效时才会触发。<br/> |  
| onEnterActionArea<sup>(10+)</sup> | function | false | false | 在滑动条目进入删除区域时调用，只触发一次，当再次进入时仍触发。<br/> |  
| onExitActionArea<sup>(10+)</sup> | function | false | false | 当滑动条目退出删除区域时调用，只触发一次，当再次退出时仍触发。<br/> |  
    
## SwipeActionOptions<sup>(9+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| start<sup>(9+)</sup> | CustomBuilder \| SwipeActionItem | false | false | ListItem向右划动时item左边的组件（List垂直布局时）或ListItem向下划动时item上方的组件（List水平布局时）。<br/> |  
| end<sup>(9+)</sup> | CustomBuilder \| SwipeActionItem | false | false | ListItem向左划动时item右边的组件（List垂直布局时）或ListItem向上划动时item下方的组件（List水平布局时） |  
| edgeEffect<sup>(9+)</sup> | SwipeEdgeEffect | false | false | 滑动效果。<br/> |  
    
## ListItemStyle<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 无样式。 |  
| CARD | 1 | 显示默认卡片样式。 |  
    
## ListItemOptions<sup>(10+)</sup>    
设置List组件卡片样式。  
默认值: ListItemStyle.NONE  
设置为ListItemStyle.NONE时无样式。  
设置为ListItemStyle.CARD时，必须配合<a href="https://gitee.com/openharmony/docs/blob/weekly_20231010/zh-cn/application-dev/reference/arkui-ts/ts-container-listitemgroup.md">ListItemGroup</a>的ListItemGroupStyle.CARD同时使用，显示默认卡片样式。  
卡片样式下，ListItem默认规格：高度48vp，宽度100%。  
卡片样式下, 为卡片内的列表选项提供了默认的focus、hover、press、selected和disable样式。  
<strong>说明：</strong>  
当前卡片模式下，不支持listDirection属性设置，使用默认Axis.Vertical排列方向。  
当前卡片模式下，List属性alignListItem默认为ListItemAlign.Center，居中对齐显示。  
若仅设置ListItemStyle.CARD，未设置ListItemGroupStyle.CARD时，只显示部分卡片样式及功能。  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| style<sup>(10+)</sup> | ListItemStyle | false | false |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- ListItem(value?: string)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(7+)</sup> | string | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| sticky<sup>(deprecated)</sup> |  Sticky |  |  
| editable<sup>(deprecated)</sup> |  boolean \| EditMode |  |  
| selectable<sup>8+</sup> |  boolean |  |  
| selected<sup>10+</sup> |  boolean |     
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
| swipeAction<sup>9+</sup> |  SwipeActionOptions |  |  
    
### onSelect<sup>(deprecated)</sup>    
onSelect(event: (isSelected: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(8+)</sup> | (isSelected: boolean) => void | true | isSelected：进入鼠标框选范围即被选中返回true，移出鼠标框选范围即未被选中返回false。<br/> |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ListItemExample3 {  
  build() {  
    Column() {  
      List({ space: "4vp", initialIndex: 0 }) {  
        ListItemGroup({ style: ListItemGroupStyle.CARD }) {  
          ForEach([ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.NONE], (itemStyle: number, index?: number) => {  
            ListItem({ style: itemStyle }) {  
              Text("" + index)  
                .width("100%")  
                .textAlign(TextAlign.Center)  
            }  
          })  
        }  
        ForEach([ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.NONE], (itemStyle: number, index?: number) => {  
          ListItem({ style: itemStyle }) {  
            Text("" + index)  
              .width("100%")  
              .textAlign(TextAlign.Center)  
          }  
        })  
      }  
      .width('100%')  
      .multiSelectable(true)  
      .backgroundColor(0xDCDCDC) // 浅蓝色的List  
    }  
    .width('100%')  
    .padding({ top: 5 })  
  }  
}  
    
```    
  
![ListItemStyle](figures/listItem3.jpeg)  
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ListItemExample2 {  
  @State message: string = 'Hello World'  
  @State arr: number[] = [0, 1, 2, 3, 4]  
  @State enterEndDeleteAreaString: string = "not enterEndDeleteArea"  
  @State exitEndDeleteAreaString: string = "not exitEndDeleteArea"  
  
  @Builder itemEnd() {  
    Row() {  
      Button("Delete").margin("4vp")  
      Button("Set").margin("4vp")  
    }.padding("4vp").justifyContent(FlexAlign.SpaceEvenly)  
  }  
  
  build() {  
    Column() {  
      List({ space: 10 }) {  
        ForEach(this.arr, (item: number) => {  
          ListItem() {  
            Text("item" + item)  
              .width('100%')  
              .height(100)  
              .fontSize(16)  
              .textAlign(TextAlign.Center)  
              .borderRadius(10)  
              .backgroundColor(0xFFFFFF)  
          }  
          .transition({ type: TransitionType.Delete, opacity: 0 })  
          .swipeAction({  
            end: {  
              builder: () => { this.itemEnd() },  
              onAction: () => {  
                animateTo({ duration: 1000 }, () => {  
                  let index = this.arr.indexOf(item)  
                  this.arr.splice(index, 1)  
                })  
              },  
              actionAreaDistance: 56,  
              onEnterActionArea: () => {  
                this.enterEndDeleteAreaString = "enterEndDeleteArea"  
                this.exitEndDeleteAreaString = "not exitEndDeleteArea"  
              },  
              onExitActionArea: () => {  
                this.enterEndDeleteAreaString = "not enterEndDeleteArea"  
                this.exitEndDeleteAreaString = "exitEndDeleteArea"  
              }  
            }  
          })  
        }, (item: string) => item)  
      }  
      Text(this.enterEndDeleteAreaString).fontSize(20)  
      Text(this.exitEndDeleteAreaString).fontSize(20)  
    }  
    .padding(10)  
    .backgroundColor(0xDCDCDC)  
    .width('100%')  
    .height('100%')  
  }  
}  
    
```    
  
    
 **示例代码3：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ListItemExample3 {  
  build() {  
    Column() {  
      List({ space: "4vp", initialIndex: 0 }) {  
        ListItemGroup({ style: ListItemGroupStyle.CARD }) {  
          ForEach([ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.NONE], (itemStyle: number, index?: number) => {  
            ListItem({ style: itemStyle }) {  
              Text("" + index)  
                .width("100%")  
                .textAlign(TextAlign.Center)  
            }  
          })  
        }  
        ForEach([ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.NONE], (itemStyle: number, index?: number) => {  
          ListItem({ style: itemStyle }) {  
            Text("" + index)  
              .width("100%")  
              .textAlign(TextAlign.Center)  
          }  
        })  
      }  
      .width('100%')  
      .multiSelectable(true)  
      .backgroundColor(0xDCDCDC) // 浅蓝色的List  
    }  
    .width('100%')  
    .padding({ top: 5 })  
  }  
}  
    
```    
  
