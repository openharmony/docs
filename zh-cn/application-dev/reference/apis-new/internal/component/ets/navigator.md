# navigator    
路由容器组件，提供路由跳转能力。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## NavigationType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Push | 0 | 跳转到应用内的指定页面。<br/> |  
| Back | 1 | 返回到指定的页面。指定的页面不存在栈中时不响应。未传入指定的页面时返回上一页。<br/> |  
| Replace | 2 | 用应用内的某个页面替换当前页面，并销毁被替换的页面。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Navigator(value?: { target: string; type?: NavigationType })    
起始版本： 7    
    
- Navigator()    
起始版本： 7    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| active |  boolean |  |  
| type |  NavigationType |  |  
| target |  string |  |  
| params |  object |  |  
    
 **示例代码1：**   
```ts    
// Navigator.ets  
@Entry  
@Component  
struct NavigatorExample {  
  @State active: boolean = false  
  @State name: NameObject = { name: 'news' }  
  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {  
      Navigator({ target: 'pages/container/navigator/Detail', type: NavigationType.Push }) {  
        Text('Go to ' + this.name.name + ' page')  
          .width('100%').textAlign(TextAlign.Center)  
      }.params(new TextObject(this.name)) // 传参数到Detail页面  
  
      Navigator() {  
        Text('Back to previous page').width('100%').textAlign(TextAlign.Center)  
      }.active(this.active)  
      .onClick(() => {  
        this.active = true  
      })  
    }.height(150).width(350).padding(35)  
  }  
}  
  
interface NameObject {  
  name: string;  
}  
  
class TextObject {  
  text: NameObject;  
  
  constructor(text: NameObject) {  
    this.text = text;  
  }  
}  
    
```    
  
    
 **示例代码2：**   
```ts    
// Detail.ets  
import router from '@ohos.router'  
  
@Entry  
@Component  
struct DetailExample {  
  // 接收Navigator.ets的传参  
  params: Record<string, NameObject> = router.getParams() as Record<string, NameObject>  
  @State name: NameObject = this.params.text  
  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {  
      Navigator({ target: 'pages/container/navigator/Back', type: NavigationType.Push }) {  
        Text('Go to back page').width('100%').height(20)  
      }  
  
      Text('This is ' + this.name.name + ' page')  
        .width('100%').textAlign(TextAlign.Center)  
    }  
    .width('100%').height(200).padding({ left: 35, right: 35, top: 35 })  
  }  
}  
  
interface NameObject {  
  name: string;  
}  
    
```    
  
![zh-cn_image_0000001219864145](figures/zh-cn_image_0000001219864145.gif)  
    
 **示例代码3：**   
```ts    
// Back.ets  
@Entry  
@Component  
struct BackExample {  
  build() {  
    Column() {  
      Navigator({ target: 'pages/container/navigator/Navigator', type: NavigationType.Back }) {  
        Text('Return to Navigator Page').width('100%').textAlign(TextAlign.Center)  
      }  
    }.width('100%').height(200).padding({ left: 35, right: 35, top: 35 })  
  }  
}  
    
```    
  
