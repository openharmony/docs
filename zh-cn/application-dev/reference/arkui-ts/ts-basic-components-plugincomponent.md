# PluginComponent

提供外部应用组件嵌入式显示功能，即外部应用提供的UI可在本应用内显示。如需通过跨进程通信实现更新，请参考[@ohos.pluginComponent](../apis/js-apis-plugincomponent.md)。


>  **说明：**
>
> - 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无


## 接口

PluginComponent(value: { template: PluginComponentTemplate, data: KVObject})

创建插件组件，用于显示外部应用提供的UI。

**参数：**

| 参数名 | 参数类型                                                                                                                                                        | 必填 | 参数描述                                                                                                  |
| ------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---- | --------------------------------------------------------------------------------------------------------- |
| value  | {<br/>template:&nbsp; [PluginComponentTemplate](#plugincomponenttemplate类型说明),<br/>data:&nbsp;[KVObject](../apis/js-apis-plugincomponent.md#kvobject)<br/>} | 是   | template:&nbsp;&nbsp;组件模板，用于跟提供者定义的组件绑定。<br/>data:&nbsp;传给插件组件提供者使用的数据。 |

## PluginComponentTemplate类型说明

| 参数       | 类型   | 描述                        |
| ---------- | ------ | --------------------------- |
| source     | string | 组件模板名。                |
| bundleName | string | 提供者Ability的bundleName。 |
## 属性
支持[通用属性size](ts-universal-attributes-size.md)，且必须设置size。

**说明：**

  模板支持两种提供方式：
* 1.使用绝对路径进行资源提供：source字段填写模板绝对路径，bundleName不需要填写。仅适用于不需要加载资源的单独模板页面，不建议使用。
* 2.通过应用包进行资源提供：bundleName字段需要填写应用包名；source字段填写相对hap包的模板相对路径。

  例如：{source：'ets/pages/plugin.js', bundleName:'com.example.provider'}

  仅对FA模型支持source字段填写AbilityName进行模板提供。

  例如：{source：'plugin', bundleName:'com.example.provider'}


## 事件

仅支持[手势事件](ts-gesture-settings.md)分发给提供方页面，并在提供方页面内部处理。

除支持[通用事件](ts-universal-events-click.md)，还支持以下事件：

| 名称                                                                                                                | 功能描述                                                               |
| ------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| onComplete(callback:&nbsp;()&nbsp;=&gt;&nbsp;void)                                                                  | 组件加载完成回调。                                                     |
| onError(callback:&nbsp;(info:&nbsp;{&nbsp;errcode:&nbsp;number,&nbsp;msg:&nbsp;string&nbsp;})&nbsp;=&gt;&nbsp;void) | 组件加载错误回调。<br/>errcode:&nbsp;错误码。<br/>msg:&nbsp;错误信息。 |

## 示例


### 组件使用方

```ts
//PluginUserExample.ets
import plugin from "./plugin_component.js"

@Entry
@Component
struct PluginUserExample {
  @StorageLink("plugincount") plugincount: Object[] = [
    { source: 'plugincomponent1', bundleName: 'com.example.plugin' },
    { source: 'plugintemplate', bundleName: 'com.example.myapplication' },
    { source: 'plugintemplate', bundleName: 'com.example.myapplication' }]

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
      ForEach(this.plugincount, item => {
        PluginComponent({
          template: { source: 'PluginProviderExample', bundleName: 'com.example.plugin' },
          data: { 'countDownStartValue': 'new countDownStartValue' }
        }).size({ width: 500, height: 100 })
          .onComplete(() => {
            console.log("onComplete")
          })
          .onError(({errcode, msg}) => {
            console.log("onComplete" + errcode + ":" + msg)
          })
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

### 组件提供方

```ts
//PluginProviderExample.ets
import plugin from "./plugin_component.js"

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

### Plugin组件工具

#### FA模型
```js
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
        want: {
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
        want: {
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

#### Stage模型
```js
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
