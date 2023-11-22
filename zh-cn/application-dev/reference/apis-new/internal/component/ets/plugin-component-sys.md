# plugin_component    
提供外部应用组件嵌入式显示功能，即外部应用提供的UI可在本应用内显示。如需通过跨进程通信实现更新，请参考[t](../apis/js-apis-plugincomponent.md)。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## PluginComponentTemplate  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| source | string | false | true | 组件模板名。 |  
| bundleName | string | false | true | 提供者Ability的bundleName。 |  
    
## 接口  
  
  
  
<pre>创建插件组件，用于显示外部应用提供的UI。</pre>  
    
 **调用形式**     
    
- PluginComponent(value: { template: PluginComponentTemplate; data: any })    
起始版本： 9    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| template | PluginComponentTemplate | true | template:  组件模板，用于跟提供者定义的组件绑定。 |  
| data | any | true | data:  传给插件组件提供者使用的数据。 |  
    
### onComplete<sup>(deprecated)</sup>    
onComplete(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onError<sup>(deprecated)</sup>    
onError(callback: (info: { errcode: number; msg: string }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码1：**   
组件使用方  
```ts    
//PluginUserExample.ets  
import plugin from "./plugin_component"  
class source2BundleName {  
  source: string = ""  
  bundleName: string = ""  
}  
interface Info{  
  errcode:number,  
  msg:string  
}  
@Entry  
@Component  
struct PluginUserExample {  
  @StorageLink("plugincount") plugincount: Object[] = [  
    { source: 'plugincomponent1', bundleName: 'com.example.plugin' } as source2BundleName,  
    { source: 'plugintemplate', bundleName: 'com.example.myapplication' } as source2BundleName,  
    { source: 'plugintemplate', bundleName: 'com.example.myapplication' } as source2BundleName]  
  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {  
      Text('Hello World')  
        .fontSize(50)  
        .fontWeight(FontWeight.Bold)  
      Button('Register Request Listener')  
        .fontSize(30)  
        .width(400)  
        .height(100)  
        .margin({top:20})  
        .onClick(()=>{  
          plugin.onListener()  
          console.log("Button('Register Request Listener')")  
        })  
      Button('Request')  
        .fontSize(50)  
        .width(400)  
        .height(100)  
        .margin({ top: 20 })  
        .onClick(() => {  
          plugin.Request()  
          console.log("Button('Request')")  
        })  
      ForEach(this.plugincount, (item: source2BundleName) => {  
        PluginComponent({  
          template: { source: 'PluginProviderExample', bundleName: 'com.example.plugin' },  
          data: { 'countDownStartValue': 'new countDownStartValue' }  
        }).size({ width: 500, height: 100 })  
          .onComplete(() => {  
            console.log("onComplete")  
          })  
          .onError((info:Info) => {  
            console.log("onComplete" + info.errcode + ":" + info.msg)  
          })  
      })  
    }  
    .width('100%')  
    .height('100%')  
  }  
}  
    
```    
  
    
 **示例代码2：**   
组件提供方  
```ts    
//PluginProviderExample.ets  
import plugin from "./plugin_component"  
  
@Entry  
@Component  
struct PluginProviderExample {  
  @State message: string = 'no click!'  
  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {  
      Button('Register Push Listener')  
        .fontSize(30)  
        .width(400)  
        .height(100)  
        .margin({top:20})  
        .onClick(()=>{  
          plugin.onListener()  
          console.log("Button('Register Push Listener')")  
        })  
      Button('Push')  
        .fontSize(30)  
        .width(400)  
        .height(100)  
        .margin({top:20})  
        .onClick(()=>{  
          plugin.Push()  
          this.message = "Button('Push')"  
          console.log("Button('Push')")  
        })  
      Text(this.message)  
        .height(150)  
        .fontSize(30)  
        .padding(5)  
        .margin(5)  
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })  
  }  
}  
    
```    
  
    
 **示例代码3：**   
Plugin组件工具  
```js    
//当前示例代码仅适用于js源文件  
//plugin_component.js  
import pluginComponentManager from '@ohos.pluginComponent'  
  
function onPushListener(source, template, data, extraData) {  
  console.log("onPushListener template.source=" + template.source)  
  var jsonObject = JSON.parse(data.componentTemplate.source)  
  console.log("request_callback1:source json object" + jsonObject)  
  var jsonArry = jsonObject.ExternalComponent  
  for (var i in jsonArry) {  
    console.log(jsonArry[i])  
  }  
  console.log("onPushListener:source json object" + jsonObject)  
  console.log("onPushListener:source json string" + JSON.stringify(jsonObject))  
  console.log("onPushListener template.ability=" + template.ability)  
  console.log("onPushListener data=" + JSON.stringify(data))  
  console.log("onPushListener extraData=" + JSON.stringify(extraData))  
}  
  
function onRequestListener(source, name, data)  
{  
    console.log("onRequestListener name=" + name);  
    console.log("onRequestListener data=" + JSON.stringify(data));  
    return {template:"plugintemplate", data:data};  
}  
  
export default {  
  //register listener  
  onListener() {  
    pluginComponentManager.on("push", onPushListener)  
    pluginComponentManager.on("request", onRequestListener)  
  },  
  Push() {  
    // 组件提供方主动发送事件  
    pluginComponentManager.push(  
      {  
        owner: {  
          bundleName: "com.example.myapplication",  
          abilityName: "com.example.myapplication.MainAbility",  
        },  
        target: {  
          bundleName: "com.example.plugin",  
          abilityName: "com.example.myapplication.PluginProviderExample",  
        },  
        name: "PluginProviderExample",  
        data: {  
          "key_1": "plugin component test",  
          "key_2": 34234  
        },  
        extraData: {  
          "extra_str": "this is push event"  
        },  
        jsonPath: "",  
      },  
      (err, data) => {  
        console.log("push_callback: push ok!");  
      }  
    )  
  },  
  Request() {  
    // 组件使用方主动发送事件  
    pluginComponentManager.request({  
        owner: {  
          bundleName: "com.example.myapplication",  
          abilityName: "com.example.myapplication.MainAbility",  
        },  
        target: {  
          bundleName: "com.example.plugin",  
          abilityName: "com.example.myapplication.PluginProviderExample",  
        },  
        name: "PluginProviderExample",  
        data: {  
          "key_1": "plugin component test",  
          "key_2": 34234  
        },  
        jsonPath: "",  
      },  
      (err, data) => {  
        console.log("request_callback: componentTemplate.ability=" + data.componentTemplate.ability)  
        console.log("request_callback: componentTemplate.source=" + data.componentTemplate.source)  
        var jsonObject = JSON.parse(data.componentTemplate.source)  
        console.log("request_callback:source json object" + jsonObject)  
        var jsonArry = jsonObject.ExternalComponent  
        for (var i in jsonArry) {  
          console.log(jsonArry[i])  
        }  
        console.log("request_callback:source json string" + JSON.stringify(jsonObject))  
        console.log("request_callback: data=" + JSON.stringify(data.data))  
        console.log("request_callback: extraData=" + JSON.stringify(data.extraData))  
      }  
    )  
  }  
}  
    
```    
  
