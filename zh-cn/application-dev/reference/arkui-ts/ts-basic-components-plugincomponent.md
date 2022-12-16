# PluginComponent

提供外部应用组件嵌入式显示功能，即外部应用提供的UI可在本应用内显示。


>  **说明：**
>
> - 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本组件为系统接口。


## 子组件

无


## 接口

PluginComponent(value: { template: PluginComponentTemplate, data: KVObject})

创建插件组件，用于显示外部应用提供的UI。

**参数：**

| 参数名 | 参数类型                                                     | 必填 | 参数描述                                                     |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | {<br/>template:&nbsp;PluginComponentTemplate,<br/>data:&nbsp;KVObject<br/>} | 是   | template:&nbsp;&nbsp;组件模板，用于跟提供者定义的组件绑定。<br/>data:&nbsp;传给插件组件提供者使用的数据。 |

## PluginComponentTemplate类型说明

| 参数      | 类型     | 描述                      |
| ------- | ------ | ----------------------- |
| source  | string | 组件模板名。                  |
| ability | string | 提供者Ability的abilityname。 |


## 事件

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onComplete(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | 组件加载完成回调。                                |
| onError(callback:&nbsp;(info:&nbsp;{&nbsp;errcode:&nbsp;number,&nbsp;msg:&nbsp;string&nbsp;})&nbsp;=&gt;&nbsp;void) | 组件加载错误回调。<br/>errcode:&nbsp;错误码。<br/>msg:&nbsp;错误信息。 |


## PluginComponentManager

提供配套插件组件使用的相关接口，用于给插件组件的使用者请求组件与数据，使用者发送组件模板和数据。


## 导入模块


```
import pluginComponentManager from '@ohos.plugincomponent'
```


## push

push(param: PushParameters, callback: AsyncCallback&lt;void&gt;): void

组件提供者向组件使用者主动发送组件与数据。

**参数**

| 参数名      | 类型                        | 必填   | 说明                               |
| -------- | ------------------------- | ---- | -------------------------------- |
| param    | PushParameters            | 是    | 组件使用者的详细信息，详见PushParameters参数说明。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 此次接口调用的异步回调。                     |

**PushParameters参数说明**

| 参数名       | 类型       | 必填   | 说明              |
| --------- | -------- | ---- | --------------- |
| want      | Want     | 是    | 组件使用者Ability信息。 |
| name      | string   | 是    | 组件名称。           |
| data      | KVObject | 否    | 组件数据值。          |
| extraData | KVObject | 否    | 附加数据值。          |
| jsonPath | string | 否    |  存放模板路径的external.json文件的路径。       |

**示例**

见[Plugin组件提供方](#组件提供方)示例。


## request

request(param: RequestParameters, callback: AsyncCallback&lt;RequestCallbackParameters&gt;): void

组件使用者向组件提供者主动请求组件。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| param    | RequestParameters                        | 是    | 组件模板的详细请求信息，详见RequestParameters参数说明。 |
| callback | AsyncCallback<RequestCallbackParameters&nbsp;\|&nbsp;void&gt; | 是    | 此次请求的异步回调，&nbsp;通过回调接口的参数返回接受请求的数据。  |

**RequestParameters参数说明**

| 参数名  | 类型       | 必填   | 说明              |
| ---- | -------- | ---- | --------------- |
| want | Want     | 是    | 组件提供者Ability信息。 |
| name | string   | 是    | 请求组件名称。         |
| data | KVObject | 是    | 附加数据。           |
| jsonPath | string | 否    |  存放模板路径的external.json文件的路径。jsonPath字段不为空或者未设置的时候不触发Request通信。       |

**RequestCallbackParameters说明**

| 名称                | 类型                      | 说明    |
| ----------------- | ----------------------- | ----- |
| componentTemplate | PluginComponentTemplate | 组件模板。 |
| data              | KVObject                | 组件数据。 |
| extraData         | KVObject                | 附加数据。 |

**示例**

见[Plugin组件使用方](#组件使用方)示例。


## on

on(eventType: string, callback: OnPushEventCallback | OnRequestEventCallback): void

提供者监听"request"类型的事件，给使用者返回通过request接口主动请求的数据；使用者监听"push"类型的事件，接收提供者通过push接口主动推送的数据。

**参数**

| 参数名       | 类型                                       | 必填   | 说明                                       |
| --------- | ---------------------------------------- | ---- | ---------------------------------------- |
| eventType | string                                   | 是    | 监听的事件类型，&nbsp;可选值为："push"&nbsp;、"request"。<br/>"push”：指组件提供者向使用者主动推送数据。<br/>"request”：指组件使用者向提供者主动请求数据。 |
| callback  | OnPushEventCallback&nbsp;\|&nbsp;OnRequestEventCallback | 是    | 见callback事件说明。                           |

**callback事件说明**

| 参数名                    | 类型                                       | 说明                                       |
| ---------------------- | ---------------------------------------- | ---------------------------------------- |
| OnRequestEventCallback | (source:&nbsp;Want,<br/>name:&nbsp;string,<br/>data:&nbsp;KVObject&nbsp;)&nbsp;=>RequestEventResult | 数据请求事件的回调。<br/>source:&nbsp;组件请求方Ability信息。<br/>name:&nbsp;请求组件名称。<br/>data:&nbsp;附加数据。<br/>返回值：&nbsp;请求数据结果。 |
| OnPushEventCallback    | (source:&nbsp;Want,<br/>template:&nbsp;PluginComponentTemplate,<br/>data:&nbsp;KVObject,<br/>extraData:&nbsp;KVObject<br/>)&nbsp;=&gt;&nbsp;void | 接收提供者主动推送的数据。<br/>source:&nbsp;组件提供者Ability信息。<br/>template:&nbsp;组件模板。<br/>data:&nbsp;组件更新数据。<br/>extraData:&nbsp;附加数据。 |

**RequestEventResult类型说明**

| 参数      | 类型     | 说明       |
| --------- | -------- | ---------- |
| template  | string   | 组件名称。 |
| data      | KVObject | 组件数据。 |
| extraData | KVObject | 附加数据。 |

**示例**

见[Plugin组件工具](#plugin组件工具)示例。

**KVObject类型说明**

| 参数   | 类型                                       | 说明                                       |
| ---- | ---------------------------------------- | ---------------------------------------- |
| key  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;boolean&nbsp;\|&nbsp;Array&nbsp;\|&nbsp;KVObject | KVObject用[key，value]来存储数据，key是string类型的，value可以是number，string，boolean，数组或者另外的一个KVObject。 |


**external.json文件说明**

external.json文件由开发者创建。external.json中以键值对形式存放组件名称以及对应模板路径。以组件名称name作为关键字，对应模板路径作为值。

**示例**

见[external.json](#externaljson)示例。

## 示例


### 组件使用方


```ts
//PluginUserExample.ets
import plugin from "plugin_component.js"

@Entry
@Component
struct PluginUserExample {
  @StorageLink("plugincount") plugincount: Object[] = [
    { source: 'plugincomponent1', ability: 'com.example.plugin' },
    { source: 'plugintemplate', ability: 'com.example.myapplication' },
    { source: 'plugintemplate', ability: 'com.example.myapplication' }]

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
          template: { source: 'plugincomponent1', ability: 'com.example.plugin' },
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
import plugin from "plugin_component.js"

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
          bundleName: "com.example.myapplication",
          abilityName: "com.example.myapplication.MainAbility",
        },
        name: "plugintemplate",
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
          bundleName: "com.example.myapplication",
          abilityName: "com.example.myapplication.MainAbility",
        },
        name: "plugintemplate",
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


### external.json
```json
{
  "plugintemplate": "ets/pages/plugintemplate.js",
  "plugintemplate2": "ets/pages/plugintemplate2.js"
}
