# @ohos.arkui.inspector    
提供注册组件布局和绘制完成回调通知的能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inspector from '@ohos.arkui.inspector'    
```  
    
## ComponentObserver    
组件布局绘制完成回调的句柄，包含了申请句柄时的首次查询结果。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### on('layout')    
通过句柄向对应的查询条件注册回调，当组件布局完成时会触发该回调。  
 **调用形式：**     
    
- on(type: 'layout', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 必须填写字符串'layout'或'draw'。<br>layout: 组件布局完成。<br>draw: 组件绘制完成。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 监听layout或draw的回调。 |  
    
### off('layout')    
通过句柄向对应的查询条件取消注册回调，当组件布局完成时不再触发指定的回调。  
 **调用形式：**     
    
- off(type: 'layout', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 必须填写字符串'layout'或'draw'。<br>layout: 组件布局完成。<br>draw: 组件绘制完成。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。 |  
    
### on('draw')  
 **调用形式：**     
    
- on(type: 'draw', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 必须填写字符串'layout'或'draw'。<br>layout: 组件布局完成。<br>draw: 组件绘制完成。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 监听layout或draw的回调。 |  
    
### off('draw')    
通过句柄向对应的查询条件取消注册回调，当组件绘制完成时不再触发指定的回调。  
 **调用形式：**     
    
- off(type: 'draw', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 必须填写字符串'layout'或'draw'。<br>layout: 组件布局完成。<br>draw: 组件绘制完成。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。 |  
    
 **示例代码：**   
```ts    
import inspector from '@ohos.arkui.inspector'  
  
  @Entry  
  @Component  
  struct ImageExample {  
    build() {  
      Column() {  
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {  
          Row({ space: 5 }) {  
            Image($r('app.media.app_icon'))  
              .width(110)  
              .height(110)  
              .border({ width: 1 })  
              .id('IMAGE_ID')  
          }  
        }  
      }.height(320).width(360).padding({ right: 10, top: 10 })  
    }  
  
    listener:inspector.ComponentObserver = inspector.createComponentObserver('IMAGE_ID')  
  
    aboutToAppear() {  
      let onLayoutComplete:()=>void=():void=>{  
          // do something here  
      }  
      let onDrawComplete:()=>void=():void=>{  
          // do something here  
      }  
      let FuncLayout = onLayoutComplete // bind current js instance  
      let FuncDraw = onDrawComplete // bind current js instance  
  
      this.listener.on('layout', FuncLayout)  
      this.listener.on('draw', FuncDraw)  
    }  
  }  
    
```    
  
    
## createComponentObserver    
绑定指定组件，返回对应的监听句柄。  
 **调用形式：**     
- createComponentObserver(id: string): ComponentObserver  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | string | true | 指定组件id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ComponentObserver | 组件回调事件监听句柄，用于注册和取消注册监听回调。 |  
    
 **示例代码：**   
```ts    
import inspector from '@ohos.arkui.inspector'    
```    
  
