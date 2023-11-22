# refresh    
可以进行页面下拉操作并显示刷新动效的容器组件。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## RefreshStatus    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Inactive | 0 | 默认未下拉状态。 |  
| Drag | 1 | 下拉中，下拉距离小于刷新距离。 |  
| OverDrag | 2 | 下拉中，下拉距离超过刷新距离。 |  
| Refresh | 3 | 下拉结束，回弹至刷新距离，进入刷新状态。 |  
| Done | 4 | 刷新结束，返回初始状态（顶部）。 |  
    
## RefreshOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| refreshing | boolean | false | true |  |  
| offset | number \| string | false | false |  |  
| friction | number \| string | false | false |  |  
| builder<sup>(10+)</sup> | CustomBuilder | false | false |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Refresh(value: RefreshOptions)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | RefreshOptions | true |  |  
    
### onStateChange<sup>(deprecated)</sup>    
onStateChange(callback: (state: RefreshStatus) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onRefreshing<sup>(deprecated)</sup>    
onRefreshing(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码1：**   
刷新组件使用默认样式：  
```ts    
// xxx.ets  
@Entry  
@Component  
struct RefreshExample {  
  @State isRefreshing: boolean = false  
  @State arr: String[] = ['0', '1', '2', '3', '4','5','6','7','8','9','10']  
  
  build() {  
    Column() {  
      Refresh({ refreshing: $$this.isRefreshing}) {  
        List() {  
          ForEach(this.arr, (item: string) => {  
            ListItem() {  
              Text('' + item)  
                .width('100%').height(100).fontSize(16)  
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)  
            }  
          }, (item: string) => item)  
        }  
        .onScrollIndex((first: number) => {  
          console.info(first.toString())  
        })  
        .width('100%')  
        .height('100%')  
        .divider({strokeWidth:1,color:Color.Yellow,startMargin:10,endMargin:10})  
        .scrollBar(BarState.Off)  
      }  
      .onStateChange((refreshStatus: RefreshStatus) => {  
        console.info('Refresh onStatueChange state is ' + refreshStatus)  
      })  
      .onRefreshing(() => {  
        setTimeout(() => {  
          this.isRefreshing = false  
        }, 2000)  
        console.log('onRefreshing test')  
      })  
      .backgroundColor(0x89CFF0)  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
自定义刷新组件：  
```ts    
// xxx.ets  
@Entry  
@Component  
struct RefreshExample {  
  @State isRefreshing: boolean = false  
  @State arr: String[] = ['0', '1', '2', '3', '4','5','6','7','8','9','10']  
  @Builder  
  customRefreshComponent()  
  {  
    Stack()  
    {  
      Row()  
      {  
        LoadingProgress().height(32)  
        Text("正在刷新...").fontSize(16).margin({left:20})  
      }  
      .alignItems(VerticalAlign.Center)  
    }.width("100%").align(Alignment.Center)  
  }  
  
  build() {  
    Column() {  
      Refresh({ refreshing: $$this.isRefreshing,builder:this.customRefreshComponent()}) {  
        List() {  
          ForEach(this.arr, (item: string) => {  
            ListItem() {  
              Text('' + item)  
                .width('100%').height(100).fontSize(16)  
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)  
            }  
          }, (item: string) => item)  
        }  
        .onScrollIndex((first: number) => {  
          console.info(first.toString())  
        })  
        .width('100%')  
        .height('100%')  
        .divider({strokeWidth:1,color:Color.Yellow,startMargin:10,endMargin:10})  
        .scrollBar(BarState.Off)  
      }  
      .onStateChange((refreshStatus: RefreshStatus) => {  
        console.info('Refresh onStatueChange state is ' + refreshStatus)  
      })  
      .onRefreshing(() => {  
        setTimeout(() => {  
          this.isRefreshing = false  
        }, 2000)  
        console.log('onRefreshing test')  
      })  
      .backgroundColor(0x89CFF0)  
    }  
  }  
}  
    
```    
  
