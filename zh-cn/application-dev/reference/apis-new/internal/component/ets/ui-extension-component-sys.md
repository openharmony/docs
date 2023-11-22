# ui_extension_component    
UIExtensionComponent用于支持在本页面内嵌入其他应用提供的UI。展示的内容在另外一个进程中运行，本应用并不参与其中的布局和渲染。通常用于有进程隔离诉求的模块化开发场景。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## UIExtensionProxy    
用于在双方建立连接成功后，组件使用方向被拉起的Ability发送数据的场景，提供send方法。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### send    
发送给被拉起的扩展Ability的数据。  
 **调用形式：**     
- send(data: { [key: string]: Object }): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | { [key: string]: Object } | true |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- UIExtensionComponent(     want: import('../api/@ohos.app.ability.Want').default   )    
起始版本： 10    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | import('../api/nt').default | true | 要加载的Ability。 |  
    
### onRemoteReady<sup>(deprecated)</sup>    
onRemoteReady(     callback: import('../api/@ohos.base').Callback<UIExtensionProxy>   )    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onReceive<sup>(deprecated)</sup>    
onReceive(     callback: import('../api/@ohos.base').Callback<{ [key: string]: Object }>   )    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onResult<sup>(deprecated)</sup>    
onResult(     callback: import('../api/@ohos.base').Callback<{       code: number;       want?: import('../api/@ohos.app.ability.Want').default;     }>   )    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onRelease<sup>(deprecated)</sup>    
onRelease(     callback: import('../api/@ohos.base').Callback<number>   )    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onError<sup>(deprecated)</sup>    
onError(     callback: import('../api/@ohos.base').ErrorCallback   )    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
本示例仅展示组件使用的方法和扩展的Ability，实际运行需在设备中安装bundleName为"com.example.uiextensionprovider"，abilityName为"UIExtensionProvider"的Ability扩展。  
```ts    
// 组件使用示例：  
import Want from '@ohos.app.ability.Want';  
  
@Entry  
@Component  
struct Index {  
  @State message: string = 'Hello World'  
  private myProxy: UIExtensionProxy | null = null;  
  want: Want = {  
    bundleName: "com.example.uiextensionprovider",  
    abilityName: "UIExtensionProvider",  
    parameters: { "x": 12345, "y": "data" }  
  }  
  
  build() {  
    Row() {  
      Column() {  
        Text(this.message).fontColor(Color.Red)  
        UIExtensionComponent(this.want)  
          .size({ width: "100%", height: "100%" })  
          .onRemoteReady((proxy: UIExtensionProxy) => {  
            this.message = "remote ready"  
            this.myProxy = proxy  
          })  
          .onReceive((data: Object) => {  
            this.message = JSON.stringify(data)  
          })  
          .onRelease((releaseCode: number) => {  
            this.message = "Release: " + releaseCode  
          })  
          .onResult((data: Object) => {  
            this.message = JSON.stringify(data)  
          })  
          .onError((error: ErrorObject) => {  
            this.message = "onError: " + error.code + ", name: " + error.name + ", message: " + error.message  
          })  
        Button("sendData").onClick(() => {  
          if (this.myProxy != null) {  
            let a: Record<string, number> = { "x": 5678910 };  
            this.myProxy.send(a)  
          }  
        })  
      }  
      .width("100%")  
    }  
    .height('100%')  
  }  
}  
  
interface ErrorObject {  
  code: number;  
  name: string;  
  message: string;  
}  
    
```    
  
