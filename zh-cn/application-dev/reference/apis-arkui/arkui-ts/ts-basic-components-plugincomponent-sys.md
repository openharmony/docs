# PluginComponent (系统接口)

提供外部应用组件嵌入式显示功能，即外部应用提供的UI可在本应用内显示。如需通过跨进程通信实现更新，请参考[@ohos.pluginComponent](../js-apis-plugincomponent.md)。


>  **说明：**
>
>  - 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  - 本模块系统接口。

## 子组件

无


## 接口

PluginComponent(options: PluginComponentOptions)

创建插件组件，用于显示外部应用提供的UI。

**参数：**

| 参数名  | 参数类型                                                     | 必填 | 参数描述                                                     |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [PluginComponentOptions](#plugincomponentoptions14类型说明) | 是   | 定义用于构造插件组件的选项。 |

## PluginComponentOptions<sup>14+</sup>类型说明

定义用于构造插件组件的选项。

| 参数       | 类型   | 描述                        |
| ---------- | ------ | --------------------------- |
| template   | [PluginComponentTemplate](#plugincomponenttemplate9类型说明) | 组件模板，用于跟提供者定义的组件绑定。                |
| data       | any    | 传给插件组件提供者使用的数据。 |

## PluginComponentTemplate<sup>9+</sup>类型说明

| 参数       | 类型   | 描述                        |
| ---------- | ------ | --------------------------- |
| source     | string | 组件模板名。                |
| bundleName | string | 提供者Ability的bundleName。 |
## 属性
必须显式设置组件宽高为非0有效值。

**说明：**

  模板支持两种提供方式：
* 1.使用绝对路径进行资源提供：source字段填写模板绝对路径，bundleName不需要填写。仅适用于不需要加载资源的单独模板页面，不建议使用。
* 2.通过应用包进行资源提供：bundleName字段需要填写应用包名；source字段填写相对hap包的模板相对路径，对于多hap场景，通过相对路径&模块名称的方式进行hap包的确认。

  例如：{source：'pages/PluginProviderExample.ets&entry', bundleName:'com.example.provider'}

  仅对FA模型支持source字段填写AbilityName进行模板提供。

  例如：{source：'plugin', bundleName:'com.example.provider'}


## 事件

仅支持[绑定手势方法](ts-gesture-settings.md)，并分发给提供方页面，在提供方页面内部处理。

除支持[通用事件](ts-universal-events-click.md)，还支持以下事件：

### onComplete

onComplete(callback:&nbsp;VoidCallback)

组件加载完成回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onError

onError(callback:&nbsp;{info:&nbsp;PluginErrorCallback})

组件加载错误回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型                                                         | 必填 | 说明                                            |
| --------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| callback  | [PluginErrorCallback](#pluginerrorcallback14类型说明)          | 是   | 发生错误时调用回调。 |

## PluginErrorCallback<sup>14+</sup>类型说明

发生错误时调用回调。

| 参数     | 类型               | 描述                        |
| -------- | ------------------ | --------------------------- |
| info     | [PluginErrorData](#pluginerrordata14类型说明)  | 发生错误时提供的数据。 |

## PluginErrorData<sup>14+</sup>类型说明

发生错误时提供的数据。

| 参数       | 类型   | 描述                        |
| ---------- | ------ | -------------------------- |
| errcode    | number | 错误码。                    |
| msg        | string | 错误信息。                  |

## 示例


### 组件使用方

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

### 组件提供方

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

### Plugin组件工具

#### FA模型
```js
//当前示例代码仅适用于js源文件
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
        console.log("request_callback: data=" + JSON.stringify(data.data))
        console.log("request_callback: extraData=" + JSON.stringify(data.extraData))
      }
    )
  }
}
```

#### Stage模型
```js
//当前示例代码仅适用于js源文件
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
        console.log("request_callback: data=" + JSON.stringify(data.data))
        console.log("request_callback: extraData=" + JSON.stringify(data.extraData))
      }
    )
  }
}
```
