# PluginComponent


> **NOTE**
> - This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
> 
> - The APIs of this module are system APIs and cannot be called by third-party applications.


**&lt;PluginComponent&gt;** allows the UI provided by an external application to be displayed in the application.


## Required Permissions

None


## Child Components

None


## APIs

PluginComponent(value: { template: PluginComponentTemplate, data: any })

Creates a **PluginComponent** to display the UI provided by an external application.

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | {<br/>template: PluginComponentTemplate,<br/>data: KVObject<br/>} | Yes | - | **template**: template of the **PluginComponent**, which is bound to the component defined by the provider.<br/>**data**: data passed to the **PluginComponent** provider. |

- PluginComponentTemplate parameters
  | Name | Type | Description | 
  | -------- | -------- | -------- |
  | source | string | Component template name. | 
  | ability | string | Name of the provider ability. | 


## Events

| Name | Description | 
| -------- | -------- |
| onComplete(callback: () =&gt; void) | Triggered when the component loading is complete. | 
| onError(callback: (info: { errcode: number, msg: string }) =&gt; void) | Triggered when an error occurs during component loading.<br/>**errcode**: error code.<br/>**msg**: error information. | 


## PluginComponentManager

Provides APIs for the **PluginComponent**. You can use these APIs to request components and data and send component templates and data.


## Modules to Import


```
import pluginComponentManager from '@ohos.plugincomponent'
```


## Required Permissions

None


## push

push(param: PushParameters, callback: AsyncCallback&lt;void&gt;): void

Used by the component provider to send the component and data to the component consumer.


- Parameters
  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | param | PushParameters | Yes | Information about the component consumer. For details, see description of PushParameters. |
  | callback | AsyncCallback&lt;void&gt; | Yes | Asynchronous callback used to return the result. |

- Description of PushParameters
  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | want | Want | Yes | Ability information of the component consumer. |
  | name | string | Yes | Component name. |
  | data | KVObject | No | Component data value. |
  | extraData | KVObject | No | Additional data value. |

- Example<br>
  For details, see [APIs Called by Component Consumers](#apis-called-by-component-consumers).


## request

request(param: RequestParameters, callback: AsyncCallback&lt;RequestCallbackParameters&gt;): void

Used by the component consumer to request the component from the component provider.

- Parameters
  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | param | RequestParameters | Yes | Information about the component request. For details, see  description of RequestParameters. |
  | callback | AsyncCallback<RequestCallbackParameters \| void&gt; |  | Asynchronous callback used to return the requested data. |

- Description of RequestParameters
  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | want | Want     | Yes | Ability information of the component provider. |
  | name | string | Yes | Name of the requested component. |
  | data | KVObject | Yes | Additional data. |

- Description of RequestCallbackParameters
  | Name | Type | Description |
  | -------- | -------- | -------- |
  | componentTemplate | PluginComponentTemplate | Component template. |
  | data | KVObject | Component data. |
  | extraData | KVObject | Additional data. |

- Description of KVObject
  | Name | Type | Description | 
  | -------- | -------- | -------- |
  | key | number \| string \| boolean \| Array \| KVObject | **KVObject** uses **key** and **value** to store data. **key** is of the string type, and **value** can be of the number, string, boolean, array type or another **KVObject**. | 


- Example<br>
  For details, see [APIs Called by Component Consumers](#apis-called-by-component-consumers).


## on

on(eventType: string, callback: OnPushEventCallback | OnRequestEventCallback): void

Listens for events of the request type and returns the requested data, or listens for events of the push type and receives the data pushed by the provider.

- Parameters
  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | eventType | string | Yes | Type of the event to listen for. The options are **"push"** and **"request"**.<br/>**"push"**: The component provider pushes data to the component consumer.<br/>**"request"**: The component consumer proactively requests data from the component provider. |
  | callback | OnPushEventCallback \| OnRequestEventCallback | Yes | Callback used to return the result. For details, see description of callback. |

- Description of callback
  | Name | Type | Description |
  | -------- | -------- | -------- |
  | OnRequestEventCallback | (source: Want,<br/>name: string,<br/>data: KVObject ) =>RequestEventResult | Callback for the data request event.<br/>**source**: ability information of the component requester.<br/>**name**: name of the requested component.<br/>**data**: additional data.<br/>Return value: request data and result. |
  | OnPushEventCallback | (source: Want,<br/>template: PluginComponentTemplate,<br/>data: KVObject,<br/>extraData: KVObject<br/>) =&gt; void | Callback used to receive the data pushed by the component provider.<br/>**source**: ability information of the component provider.<br/>**template**: component template.<br/>**data**: component update data.<br/>**extraData**: additional data. |

- Description of RequestEventResult
  | Name | Type | Description |
  | -------- | -------- | -------- |
  | template | string | Component name. |
  | data | KVObject | Component data. |
  | extraData | KVObject | Additional data. |

- Example<br>
  For details, see [APIs Called by Component Consumers](#apis-called-by-component-consumers).


## Example


### Using the PluginComponent


```
import plugin from "../../test/plugin_component.js"
import plugincomponent from '@ohos.plugincomponent'

@Entry
@Component
struct PluginComponentExample {
  @StorageLink("plugincount") plugincount: Object[] = [
    { source: 'plugincomponent1', ability: 'com.example.plugin' },
    { source: 'plugintemplate', ability: 'com.example.myapplication' },
    { source: 'plugintemplate', ability: 'com.example.myapplication' }]

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text('Hello World')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Button('Push')
        .fontSize(50)
        .width(400)
        .height(100)
        .onClick(() => {
          plugin.Push()
          console.log("Button('Push')")
        })
        .margin({ top: 20 })
      Button('Request1')
        .fontSize(50)
        .width(400)
        .height(100)
        .margin({ top: 20 })
        .onClick(() => {
          plugin.Request1()
          console.log("Button('Request1')")
        })
      Button('Request2')
        .fontSize(50)
        .width(400)
        .height(100)
        .margin({ top: 20 })
        .onClick(() => {
          plugin.Request2()
          console.log("Button('Request2')")
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
```


### APIs Called by Component Consumers


```
import pluginComponentManager from '@ohos.plugincomponent'

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

export default {
  //register listener
  onListener() {
    pluginComponentManager.on("push", onPushListener)
  },
  Request() {
 //The component consumer proactively sends data.
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
        jsonPath: "assets/js",
      },
      (err, data) => {
        console.log("request_callback1: componentTemplate.ability=" + data.componentTemplate.ability)
        console.log("request_callback1: componentTemplate.source=" + data.componentTemplate.source)
        var jsonObject = JSON.parse(data.componentTemplate.source)
        console.log("request_callback1:source json object" + jsonObject)
        var jsonArry = jsonObject.ExternalComponent
        for (var i in jsonArry) {
          console.log(jsonArry[i])
        }
        console.log("request_callback1:source json string" + JSON.stringify(jsonObject))
        console.log("request_callback1: data=" + JSON.stringify(data.data))
        console.log("request_callback1: extraData=" + JSON.stringify(data.extraData))
      }
    )
  }
}

// Example of the component provider using the API
import pluginComponentManager from '@ohos.plugincomponent'

function onRequestListener(source, name, data) {
  console.log("onRequestListener name=" + name)
  console.log("onRequestListener data=" + JSON.stringify(data))
  return { template: "plugintemplate", data: data }
}

export default {
  //register listener
  onListener() {
    pluginComponentManager.on("request", onRequestListener)
  },
  Push() {
    // The component provider proactively sends data.
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
        jsonPath: "assets/js",
      },
      (err, data) => {
        console.log("push_callback1: componentTemplate.ability=" + data.componentTemplate.ability)
        console.log("push_callback1: componentTemplate.source=" + data.componentTemplate.source)
        console.log("push ok!")
      }
    )
  },
}
```
