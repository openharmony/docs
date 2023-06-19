# PluginComponent

The **\<PluginComponent>** allows the UI provided by an external application to be displayed in the application. To implement the update through inter-process communication (IPC), see [@ohos.pluginComponent](../apis/js-apis-plugincomponent.md).


>  **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported


## APIs

PluginComponent(value: { template: PluginComponentTemplate, data: KVObject})

Creates a **PluginComponent** to display the UI provided by an external application.

**Parameters**

| Name| Type                                                                                                                                                       | Mandatory| Description                                                                                                 |
| ------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---- | --------------------------------------------------------------------------------------------------------- |
| value  | {<br>template:  [PluginComponentTemplate](#plugincomponenttemplate),<br>data: [KVObject](../apis/js-apis-plugincomponent.md#kvobject)<br>} | Yes  | **template**: template of the **PluginComponent**, which is bound to the component defined by the provider.<br>**data**: data passed to the **PluginComponent** provider.|

## PluginComponentTemplate

| Name      | Type  | Description                       |
| ---------- | ------ | --------------------------- |
| source     | string | Component template name.               |
| bundleName | string | Bundle name of the provider ability.|
## Attributes
The [universal attributes](ts-universal-attributes-size.md) are supported, and **size** must be set.

**NOTE**

  The template can be provided in either of the following modes:
* Use an absolute path. In this case, set **source** to the absolute path of the template and leave **bundleName** blank. This mode is not recommende as it is applicable only to standalone templates that do not need to load resources.
* Use an application package. In this case, set **bundleName** to the application bundle name and **source** to the relative path of the HAP file template.

  Example: **{source: 'ets/pages/plugin.js', bundleName: 'com.example.provider'}**

  The template is provided only when **source** can be set to an ability name in the FA model.

  Example: **{source: 'plugin', bundleName: 'com.example.provider'}**


## Events

Only the [gesture event](ts-gesture-settings.md) can be distributed to the provider page and processed inside the provider page.

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name                                                                                                               | Description                                                              |
| ------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| onComplete(callback: () =&gt; void)                                                                  | Triggered when the component loading is complete.                                                    |
| onError(callback: (info: { errcode: number, msg: string }) =&gt; void) | Triggered when an error occurs during component loading.<br>**errcode**: error code.<br>**msg**: error information.|

## Example


### PluginComponent User

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

### PluginComponent Provider

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

### PluginComponent Tools

#### FA Model
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

#### Stage Model
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
