## postCardAction

postCardAction(component: Object, action: Object): void

用于卡片内部和提供方应用间的交互，当前支持router、message和call三种类型的事件，仅在卡片中可以调用

> **说明：** 
> 本接口从API version 11开始支持。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数说明：**


| **参数名** | **参数类型** | **必填** | **参数描述** |
| -------- | -------- | -------- | -------- |
| component | Object | 是 | 当前自定义组件的实例，通常传入this。 |
| action | Object | 是 | action的具体描述，详情见下表。 |


action参数说明：


| **Key** | **Value** | **样例描述** |
| -------- | -------- | -------- |
| "action" | string | action的类型，支持三种预定义的类型：<br/>-&nbsp;"router"：跳转到提供方应用的指定UIAbility。<br/>-&nbsp;"message"：自定义消息，触发后会调用提供方FormExtensionAbility的[onFormEvent()](../reference/apis/js-apis-app-form-formExtensionAbility.md#onformevent)生命周期回调。<br/>-&nbsp;"call"：后台启动提供方应用。触发后会拉起提供方应用的指定UIAbility（仅支持launchType为singleton的[UIAbility](uiability-launch-type.md)，即启动模式为单实例的UIAbility），但不会调度到前台。提供方应用需要具备后台运行权限([ohos.permission.KEEP_BACKGROUND_RUNNING](../security/AccessToken/permissions-for-all.md#ohospermissionkeep_background_running))。 |
| "bundleName" | string | "action"为"router"&nbsp;/&nbsp;"call"&nbsp;类型时跳转的包名，可选。 |
| "moduleName" | string | "action"为"router"&nbsp;/&nbsp;"call"&nbsp;类型时跳转的模块名，可选。 |
| "abilityName" | string | "action"为"router"&nbsp;/&nbsp;"call"&nbsp;类型时跳转的UIAbility名，必填。 |
| "params" | Object | 当前action携带的额外参数，内容使用JSON格式的键值对形式。必填。 |

>![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
>"action"为"call"&nbsp;类型时，"params"需填入参数'method'，且类型需为string类型，用于触发UIAbility中对应的方法。