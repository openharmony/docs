# PluginComponent (System API)

The **PluginComponent** allows an application to display external UI from another application. To implement update through inter-process communication (IPC), see [@ohos.pluginComponent](../js-apis-plugincomponent.md).


>  **NOTE**
>
>  - This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs provided by this module are system APIs.

## Child Components

Not supported


## APIs

PluginComponent(value: { template: PluginComponentTemplate, data: KVObject})

Creates a **PluginComponent** to display the UI provided by an external application.

**Parameters**

| Name| Type                                                    | Mandatory| Description                                                    |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | {<br>template:  [PluginComponentTemplate](#plugincomponenttemplate),<br>data: [KVObject](../js-apis-plugincomponent.md#kvobject)<br>} | Yes  | **template**: template of the **PluginComponent**, which is bound to the component defined by the provider.<br>**data**: data passed to the **PluginComponent** provider.|

## PluginComponentTemplate

| Name      | Type  | Description                       |
| ---------- | ------ | --------------------------- |
| source     | string | Component template name.               |
| bundleName | string | Bundle name of the provider ability.|
## Attributes
The width and height of the component must be explicitly set to non-zero valid values.

**NOTE**

  The template can be provided in either of the following modes:
* Use an absolute path. In this case, set **source** to the absolute path of the template and leave **bundleName** blank. This mode is not recommended as it is applicable only to standalone templates that do not need to load resources.

* Use an application package. In this case, set **bundleName** to the application bundle name and **source** to the relative path of the HAP file template. In the multi-HAP scenario, a HAP file is identified based on its relative path and name.

  Example: **{source: 'pages/PluginProviderExample.ets&entry', bundleName:'com.example.provider'}**

  The template is provided only when **source** can be set to an ability name in the FA model.

  Example: **{source:'plugin', bundleName:'com.example.provider'}**


## Events

Only the [gesture event](ts-gesture-settings.md) can be distributed to and processed inside the provider page.

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

### onComplete

onComplete(callback: () =&gt; void)

Triggered when the component loading is complete.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onError

onError(callback: (info: { errcode: number, msg: string }) =&gt; void)

Triggered when an error occurs during component loading.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                           |
| ------ | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| info   |  { errcode: number, msg: string } | Yes  | **errcode**: error code.<br>**msg**: error information.|

## Example


### PluginComponent User

```ts
//PluginUserExample.ets
import plugin from "./plugin_component"
interface Info{
  errcode:number,
  msg:string
}
@Entry
@Component
struct PluginUserExample {

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
      PluginComponent({
        template: { source: 'pages/PluginProviderExample.ets&entry', bundleName: 'com.example.plugin' },
        data: { 'countDownStartValue': 'new countDownStartValue' }
      }).size({ width: 500, height: 350 })
        .onComplete(() => {
          console.log("onComplete")
        })
        .onError((info:Info) => {
          console.log("onComplete" + info.errcode + ":" + info.msg)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### PluginComponent Provider

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

### PluginComponent Tools

#### FA Model
```js
// The sample code applies only to JS source files.
//plugin_component.js
import pluginComponentManager from '@ohos.pluginComponent'

function onPushListener(source, template, data, extraData) {
  console.log("onPushListener template.source=" + template.source)
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
    // The component provider proactively sends data.
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
    // The component user proactively sends data.
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
        console.log("request_callback: data=" + JSON.stringify(data.data))
        console.log("request_callback: extraData=" + JSON.stringify(data.extraData))
      }
    )
  }
}
```

#### Stage Model
```js
// The sample code applies only to JS source files.
//plugin_component.js
import pluginComponentManager from '@ohos.pluginComponent'

function onPushListener(source, template, data, extraData) {
  console.log("onPushListener template.source=" + template.source)
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
    // The component provider proactively sends data.
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
    // The component user proactively sends data.
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
        console.log("request_callback: data=" + JSON.stringify(data.data))
        console.log("request_callback: extraData=" + JSON.stringify(data.extraData))
      }
    )
  }
}
```
