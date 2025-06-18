# postCardAction

用于卡片内部和提供方应用间的交互，当前支持router、message和call三种类型的事件，仅在卡片中可以调用。

> **说明：** 
>
> 本接口从API version 9开始支持。

## postCardAction

postCardAction(component: Object, action: Object): void

执行函数内部的交互，处理component和action对象的相关操作,不返回任何内容。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**


| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| component | Object | 是 | 当前自定义组件的实例，通常传入this。 |
| action | Object | 是 | action的具体描述，详情见下表。 |


action参数说明：


| **参数名** | **类型** |  **必填** | **取值说明** |
| -------- | -------- | -------- | -------- |
| action | string | 是 |action的类型，支持三种预定义的类型：<br/>-&nbsp;router：跳转到提供方应用的指定UIAbility，只允许在点击事件中触发。<br/>-&nbsp;message：自定义消息，触发后会调用提供方FormExtensionAbility的[onFormEvent()](../apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonformevent)生命周期回调。<br/>-&nbsp;call：后台启动提供方应用。触发后会拉起提供方应用的指定UIAbility（仅支持launchType为singleton的[UIAbility](../../application-models/uiability-launch-type.md)，即启动模式为单实例的UIAbility），但不会调度到前台。提供方应用需要具备后台运行权限([ohos.permission.KEEP_BACKGROUND_RUNNING](../../security/AccessToken/permissions-for-all.md#ohospermissionkeep_background_running))。 |
| bundleName | string | 否 | action为router&nbsp;/&nbsp;call&nbsp;类型时跳转的包名。 |
| moduleName | string | 否 | action为router&nbsp;/&nbsp;call&nbsp;类型时跳转的模块名。 |
| abilityName | string | 否 | action为router&nbsp;/&nbsp;call&nbsp;类型时跳转的UIAbility名。 |
| uri<sup>11+</sup> | string   | 否   | action为router&nbsp;类型时跳转的UIAbility的统一资源标识符。uri和abilityName同时存在时，abilityName优先。 |
| params | Object | 否 | 当前action携带的额外参数，内容使用JSON格式的键值对形式。 |

>**说明：**
>
>"action"为"call"&nbsp;类型时，"params"需填入参数'method'，且类型需为string类型，用于触发UIAbility中对应的方法。

**示例：** 

<!--code_no_check-->

```ts
Button('跳转')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      action: 'router',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility',
      params: {
        message: 'testForRouter' // 自定义要发送的message
      }
    });
  })

Button('拉至后台')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      action: 'call',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility',
      params: {
        method: 'fun', // 自定义调用的方法名，必填
        message: 'testForCall' // 自定义要发送的message
      }
    });
  })

Button('URI跳转')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      action: 'router',
      uri: 'example://uri.ohos.com/link_page',
      params: {
        message: 'router msg for dynamic uri deeplink' // 自定义要发送的message
      }
    });
  })

```

**待跳转应用 [module.json5](../../quick-start/module-configuration-file.md#skills标签) uris 配置示例：**

```json
"abilities": [
  {
    "skills": [
      {
        "uris": [
          {
            "scheme": "example",
            "host": "uri.ohos.com",
            "path": "link_page"
          },
        ]
      }
    ],
  }
]
```
