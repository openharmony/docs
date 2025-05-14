# @ohos.app.ability.InsightIntentEntryExecutor.d.ts (意图执行基类)

InsightIntentEntryExecutor是用于实现​智能意图[@InsightIntentEntry](./js-apis-app-ability-InsightIntentDecorator.md#insightintententry)执行逻辑​​的基类，开发者可通过继承此类定义意图执行的行为和返回结果。
本模块提供@InsightIntentEntry装饰器（加链接加链接加链接）意图调用执行基类，开发者通过意图调用执行基类对接端侧意图框架，实现响应意图调用的业务逻辑。
该意图执行基类提供了与系统能力（例如窗口管理）交互的功能，支持异步返回意图执行结果。适用于需要指定Ability组件，并在Ability组件生命周期调度中完成意图调用的场景。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { InsightIntentEntryExecutor } from '@kit.AbilityKit';
```

## InsightIntentEntryExecutor

InsightIntentEntryExecutor是用于实现意图执行逻辑的基类,可以通过继承该类，实现意图执行入口，返回意图调用结果。

该意图执行基类提供了与系统能力（例如窗口管理）交互的功能，支持异步返回意图执行结果。适用于需要指定Ability组件，并在Ability组件生命周期调度中完成意图调用的场景。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**属性：**

| 名称               | 类型            | 只读         | 可选 | 说明                                                         |
| ------------------ | ----------------| ---------- | ---- | ------------------------------------------------------------ |
| executeMode        | [insightIntent.ExecuteMode](./js-apis-app-ability-insightIntent.md#executemode) | 否       | 否   | 表示意图调用执行模式。|
| context            | [InsightIntentContext](./js-apis-app-ability-insightIntentContext.md)          | 否       | 否  | 表示意图调用执行上下文。 |
| windowStage        | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9)       | 否       | 是   | 表示展示意图的窗口管理器。仅意图执行模式是uiability前台（加链接加链接加链接）时，该属性会被赋值。    |
| uiExtensionSession     | [UIExtensionContentSession](./js-apis-app-ability-uiExtensionContentSession.md)       | 否       | 是   | 表示[UIExtensionAbility](./js-apis-app-ability-uiExtensionAbility.md)加载界面内容时创建的实例对象。仅意图执行模式是UIExtensionAbility（加链接加链接加链接）时，该属性会被赋值。    |
| onExecute()        | Promise<[insightIntent.IntentResult<T>>](./js-apis-app-ability-insightIntent.md#intentresult20)       | 否       | 是   | 表示意图执行回调，支持Promise返回意图执行结果。     |
