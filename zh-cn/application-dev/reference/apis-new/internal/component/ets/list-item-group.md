# list_item_group    
该组件用来展示列表item分组，宽度默认充满<a href="https://gitee.com/openharmony/docs/blob/weekly_20231010/zh-cn/application-dev/reference/arkui-ts/ts-container-list.md">List</a>组件，必须配合List组件来使用。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## ListItemGroupStyle<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 无样式。<br/> |  
| CARD | 1 | 显示默认卡片样式。<br/> |  
    
## ListItemGroupOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| header | CustomBuilder | false | false | 设置ListItemGroup头部组件。<br/> |  
| footer | CustomBuilder | false | false | 设置ListItemGroup尾部组件。<br/> |  
| space | number \| string | false | false | 列表项间距。只作用于ListItem与ListItem之间，不作用于header与ListItem、footer与ListItem之间。<br/> |  
| style<sup>(10+)</sup> | ListItemGroupStyle | false | false | 设置List组件卡片样式。<br/>默认值: ListItemGroupStyle.NONE<br/>设置为ListItemGroupStyle.NONE时无样式。<br/>设置为ListItemStyle.CARD时，必须配合<a href="https://gitee.com/openharmony/docs/blob/weekly_20231010/zh-cn/application-dev/reference/arkui-ts/ts-container-listitem.md">ListItem</a>的ListItemStyle.CARD同时使用，显示默认卡片样式。<br/>卡片样式下, 为卡片内的列表选项提供了默认的focus、hover、press、selected和disable样式。<br/><strong>说明：</strong><br/>当前卡片模式下，不支持listDirection属性设置，使用默认Axis.Vertical排列方向。<br/>当前卡片模式下，List属性alignListItem默认为ListItemAlign.Center，居中对齐显示。<br/>当前卡片模式下，ListItemGroup不支持设置头部组件header和尾部组件footer。<br/>若仅设置ListItemGroupStyle.CARD，未设置ListItemStyle.CARD时，只显示部分卡片样式及功能。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- ListItemGroup(options?: ListItemGroupOptions)    
起始版本： 9    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(9+)</sup> | ListItemGroupOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| divider | null |  |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ListItemGroupExample {  
  private timetable: TimeTable[] = [  
    {  
      title: '星期一',  
      projects: ['语文', '数学', '英语']  
    },  
    {  
      title: '星期二',  
      projects: ['物理', '化学', '生物']  
    },  
    {  
      title: '星期三',  
      projects: ['历史', '地理', '政治']  
    },  
    {  
      title: '星期四',  
      projects: ['美术', '音乐', '体育']  
    }  
  ]  
  
  @Builder  
  itemHead(text: string) {  
    Text(text)  
      .fontSize(20)  
      .backgroundColor(0xAABBCC)  
      .width("100%")  
      .padding(10)  
  }  
  
  @Builder  
  itemFoot(num: number) {  
    Text('共' + num + "节课")  
      .fontSize(16)  
      .backgroundColor(0xAABBCC)  
      .width("100%")  
      .padding(5)  
  }  
  
  build() {  
    Column() {  
      List({ space: 20 }) {  
        ForEach(this.timetable, (item: TimeTable) => {  
          ListItemGroup({ header: this.itemHead(item.title), footer: this.itemFoot(item.projects.length) }) {  
            ForEach(item.projects, (project: string) => {  
              ListItem() {  
                Text(project)  
                  .width("100%")  
                  .height(100)  
                  .fontSize(20)  
                  .textAlign(TextAlign.Center)  
                  .backgroundColor(0xFFFFFF)  
              }  
            }, (item: string) => item)  
          }  
          .divider({ strokeWidth: 1, color: Color.Blue }) // 每行之间的分界线  
        })  
      }  
      .width('90%')  
      .sticky(StickyStyle.Header | StickyStyle.Footer)  
      .scrollBar(BarState.Off)  
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })  
  }  
}  
  
interface TimeTable {  
  title: string;  
  projects: string[];  
}  
    
```    
  
![zh-cn_image_0000001219864159](figures/zh-cn_image_listitemgroup.gif)  
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ListItemGroupExample2 {  
  private arr: ArrObject[] = [  
    {  
      style: ListItemGroupStyle.CARD,  
      itemStyles: [ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.CARD]  
    },  
    {  
      style: ListItemGroupStyle.CARD,  
      itemStyles: [ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.NONE]  
    },  
    {  
      style: ListItemGroupStyle.CARD,  
      itemStyles: [ListItemStyle.CARD, ListItemStyle.NONE, ListItemStyle.CARD]  
    },  
    {  
      style: ListItemGroupStyle.NONE,  
      itemStyles: [ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.NONE]  
    }  
  ]  
  
  build() {  
    Column() {  
      List({ space: "4vp", initialIndex: 0 }) {  
        ForEach(this.arr, (item: ArrObject, index?: number) => {  
          ListItemGroup({ style: item.style }) {  
            ForEach(item.itemStyles, (itemStyle: number, itemIndex?: number) => {  
              ListItem({ style: itemStyle }) {  
                if (index != undefined  itemIndex != undefined) {  
                  Text("第" + (index + 1) + "个Group中第" + (itemIndex + 1) + "个item")  
                    .width("100%")  
                    .textAlign(TextAlign.Center)  
                }  
              }  
            }, (item: string) => item)  
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
  
interface ArrObject {  
  style: number;  
  itemStyles: number[];  
}  
    
```    
  
![ListItemGroupStyle](figures/listItemGroup2.jpeg)  
