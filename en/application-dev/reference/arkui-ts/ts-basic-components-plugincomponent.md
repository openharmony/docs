# PluginComponent


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | {<br/>template:&nbsp;PluginComponentTemplate,<br/>data:&nbsp;KVObject<br/>} | Yes | - | **template**:&nbsp;template&nbsp;of&nbsp;the&nbsp;**PluginComponent**,&nbsp;which&nbsp;is&nbsp;bound&nbsp;to&nbsp;the&nbsp;component&nbsp;defined&nbsp;by&nbsp;the&nbsp;provider.<br/>**data**:&nbsp;data&nbsp;passed&nbsp;to&nbsp;the&nbsp;**PluginComponent**&nbsp;provider. |

- PluginComponentTemplate parameters
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | source | string | Component&nbsp;template&nbsp;name. | 
  | ability | string | Name&nbsp;of&nbsp;the&nbsp;provider&nbsp;ability. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onComplete(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;component&nbsp;loading&nbsp;is&nbsp;complete. | 
| onError(callback:&nbsp;(info:&nbsp;{&nbsp;errcode:&nbsp;number,&nbsp;msg:&nbsp;string&nbsp;})&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;an&nbsp;error&nbsp;occurs&nbsp;during&nbsp;component&nbsp;loading.<br/>**errcode**:&nbsp;error&nbsp;code.<br/>**msg**:&nbsp;error&nbsp;information. | 


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
  | param | PushParameters | Yes | Information&nbsp;about&nbsp;the&nbsp;component&nbsp;consumer.&nbsp;For&nbsp;details,&nbsp;see description of PushParameters. |
  | callback | AsyncCallback&lt;void&gt; | Yes | Asynchronous&nbsp;callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Description of PushParameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | want | Want | Yes | Ability&nbsp;information&nbsp;of&nbsp;the&nbsp;component&nbsp;consumer. |
  | name | string | Yes | Component&nbsp;name. |
  | data | KVObject | No | Component&nbsp;data&nbsp;value. |
  | extraData | KVObject | No | Additional&nbsp;data&nbsp;value. |

- Example
  For details, see [APIs Called by Component Consumers](#apis-called-by-component-consumers).


## request

request(param: RequestParameters, callback: AsyncCallback&lt;RequestCallbackParameters&gt;): void

Used by the component consumer to request the component from the component provider.

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | param | RequestParameters | Yes | Information&nbsp;about&nbsp;the&nbsp;component&nbsp;request.&nbsp;For&nbsp;details,&nbsp;see&nbsp; description of RequestParameters. |
  | callback | AsyncCallback<RequestCallbackParameters&nbsp;\|&nbsp;void&gt; |  | Asynchronous&nbsp;callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;requested&nbsp;data. |

- Description of RequestParameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | want | Want     | Yes | Ability&nbsp;information&nbsp;of&nbsp;the&nbsp;component&nbsp;provider. |
  | name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;requested&nbsp;component. |
  | data | KVObject | Yes | Additional&nbsp;data. |

- Description of RequestCallbackParameters
    | Name | Type | Description |
  | -------- | -------- | -------- |
  | componentTemplate | PluginComponentTemplate | Component&nbsp;template. |
  | data | KVObject | Component&nbsp;data. |
  | extraData | KVObject | Additional&nbsp;data. |

- Description of KVObject
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | key | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;boolean&nbsp;\|&nbsp;Array&nbsp;\|&nbsp;KVObject | **KVObject**&nbsp;uses&nbsp;**key**&nbsp;and&nbsp;**value**&nbsp;to&nbsp;store&nbsp;data.&nbsp;**key**&nbsp;is&nbsp;of&nbsp;the&nbsp;string&nbsp;type,&nbsp;and&nbsp;**value**&nbsp;can&nbsp;be&nbsp;of&nbsp;the&nbsp;number,&nbsp;string,&nbsp;boolean,&nbsp;array&nbsp;type&nbsp;or&nbsp;another&nbsp;**KVObject**. | 


- Example
  For details, see [APIs Called by Component Consumers](#apis-called-by-component-consumers).


## on

on(eventType: string, callback: OnPushEventCallback | OnRequestEventCallback): void

Listens for events of the request type and returns the requested data, or listens for events of the push type and receives the data pushed by the provider.

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | eventType | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;listen&nbsp;for.&nbsp;The&nbsp;options&nbsp;are&nbsp;**"push"**&nbsp;and&nbsp;**"request"**.<br/>**"push"**:&nbsp;The&nbsp;component&nbsp;provider&nbsp;pushes&nbsp;data&nbsp;to&nbsp;the&nbsp;component&nbsp;consumer.<br/>**"request"**:&nbsp;The&nbsp;component&nbsp;consumer&nbsp;proactively&nbsp;requests&nbsp;data&nbsp;from&nbsp;the&nbsp;component&nbsp;provider. |
  | callback | OnPushEventCallback&nbsp;\|&nbsp;OnRequestEventCallback | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;For&nbsp;details,&nbsp;see&nbsp;description of callback. |

- Description of callback
    | Name | Type | Description |
  | -------- | -------- | -------- |
  | OnRequestEventCallback | (source:&nbsp;Want,<br/>name:&nbsp;string,<br/>data:&nbsp;KVObject&nbsp;)&nbsp;=>RequestEventResult | Callback&nbsp;for&nbsp;the&nbsp;data&nbsp;request&nbsp;event.<br/>**source**:&nbsp;ability&nbsp;information&nbsp;of&nbsp;the&nbsp;component&nbsp;requester.<br/>**name**:&nbsp;name&nbsp;of&nbsp;the&nbsp;requested&nbsp;component.<br/>**data**:&nbsp;additional&nbsp;data.<br/>Return&nbsp;value:&nbsp;request&nbsp;data&nbsp;and&nbsp;result. |
  | OnPushEventCallback | (source:&nbsp;Want,<br/>template:&nbsp;PluginComponentTemplate,<br/>data:&nbsp;KVObject,<br/>extraData:&nbsp;KVObject<br/>)&nbsp;=&gt;&nbsp;void | Callback&nbsp;used&nbsp;to&nbsp;receive&nbsp;the&nbsp;data&nbsp;pushed&nbsp;by&nbsp;the&nbsp;component&nbsp;provider.<br/>**source**:&nbsp;ability&nbsp;information&nbsp;of&nbsp;the&nbsp;component&nbsp;provider.<br/>**template**:&nbsp;component&nbsp;template.<br/>**data**:&nbsp;component&nbsp;update&nbsp;data.<br/>**extraData**:&nbsp;additional&nbsp;data. |

- Description of RequestEventResult
    | Name | Type | Description |
  | -------- | -------- | -------- |
  | template | string | Component&nbsp;name. |
  | data | KVObject | Component&nbsp;data. |
  | extraData | KVObject | Additional&nbsp;data. |

- Example
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
