# nav_router    
导航组件，默认提供点击响应处理，不需要开发者自定义点击事件逻辑。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## RouteInfo<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(10+)</sup> | string | false | true | 点击NavRouter跳转到的NavDestination页面的名称。<br/> |  
| param<sup>(10+)</sup> | unknown | false | false | 点击NavRouter跳转到NavDestination页面时，传递的参数<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- NavRouter()    
起始版本： 9    
## NavRouteMode<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PUSH_WITH_RECREATE | 0 | 跳转到新的NavDestination页面时，替换当前显示的NavDestination页面，页面销毁，但该页面信息仍保留在路由栈中。<br/> |  
| PUSH | 1 | 跳转到新的NavDestination页面时，覆盖当前显示的NavDestination页面，该页面不销毁，且页面信息保留在路由栈中。<br/> |  
| REPLACE | 2 | 跳转到新的NavDestination页面时，替换当前显示的NavDestination页面，页面销毁，且该页面信息从路由栈中清除。<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| mode<sup>10+</sup> | null |  |  
    
### onStateChange<sup>(deprecated)</sup>    
onStateChange(callback: (isActivated: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct NavRouterExample {  
  private arr: number[] = [0, 1, 2, 3]  
  @State isActive: boolean = false  
  @State dex: number = -1  
  
  build() {  
    Column() {  
      Navigation() {  
        List({ space: 12, initialIndex: 0 }) {  
          ForEach(this.arr, (item: number, index: number = 0) => {  
            ListItem() {  
              NavRouter() {  
                Row() {  
                  Image($r('app.media.icon')).width(30).height(30).borderRadius(30).margin({ left: 3, right: 10 })  
                  Text(`NavRouter${item + 1}`)  
                    .fontSize(22)  
                    .fontWeight(500)  
                    .textAlign(TextAlign.Center)  
                }  
                .width(180)  
                .height(72)  
                .backgroundColor(this.dex === index ? '#ccc' : '#fff')  
                .borderRadius(24)  
  
                NavDestination() {  
                  Text(`我是NavDestination第${item + 1}页内容`).fontSize(50)  
                  Flex({ direction: FlexDirection.Row }) {  
                    Row() {  
                      Image($r('app.media.icon')).width(40).height(40).borderRadius(40).margin({ right: 15 })  
                      Text('今天共有七节课').fontSize(30)  
                    }.padding({ left: 15 })  
                  }  
                }.backgroundColor('#ccc')  
                .title(`NavDestination${item + 1}`)  
              }.onStateChange((isActivated: boolean) => {  
                if(isActivated) {  
                  this.dex = index;  
                }  
              })  
            }  
          }, (item:number) => item.toString())  
        }  
        .height('100%')  
        .margin({ top: 12, left: 12 })  
      }  
      .mode(NavigationMode.Split)  
      .hideTitleBar(true)  
      .hideToolBar(true)  
    }.height('100%')  
  }  
}  
    
```    
  
