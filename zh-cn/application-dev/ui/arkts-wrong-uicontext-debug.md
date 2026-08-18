# UI上下文异常调试
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

本指导主要介绍如何解决因使用无效的[UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md)导致文本显示异常的问题。当开发者使用了已失效的UIContext对象（通常是因为对应的UI实例已被销毁），可能导致后续UI操作无效。此类问题常见于多窗口场景。从API version 12开始，该问题也见于调用[setSupportedProcessCache](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetsupportedprocesscache12)打开进程缓存后快速启动的情形。

## 定位UIContext错误问题

出现以下异常或系统日志时，可能存在UIContext无效的问题：

- 存在JS异常："Node Constructor error, param uiContext error"。

  产生该异常的原因通常是在[自定义节点](./arkts-user-defined-node.md)中使用了无效的UIContext，这可能导致后续UI操作被错误关联到该无效UIContext。

- 存在实例状态更新时，上下文实例ID大于等于100000且小于1000000的日志：

  实例状态更新的日志格式为：

  `({currentId}:{trackedId}:{trackedReason})][{bundleName}][{moduleName}][{thisInstanceId}]: window {status}`

  各字段含义为：

  **表1** 实例状态更新日志字段含义

  | 字段名 | 类型 | 典型值 | 说明 |
  | ---- | ---- | ---- | ---- |
  |{currentId}| 整数 | -1 | 上下文实例ID，应用正常的情况下，该字段应该为负数。 |
  |{trackedId}| 整数 | 100000  | 当前可间接跟踪的实例ID，通常为正数，开发者可忽略。 |
  |{trackedReason}| 字符串 | singleton | 间接跟踪的原因，开发者可不关注该字段。 |
  |{bundleName}| 字符串 | com.example.helloworld| 应用的bundleName。 |
  |{moduleName}| 字符串 | entry| 当前模块的moduleName。 |
  |{thisInstanceId}| 正数 | 100000 | 被通知UI实例的ID。 |
  |{status}| 实例被通知的状态 | focus | 可选值为：<br> - focus：获焦<br> - unfocus：失焦<br> - foreground：前台<br> - background：后台<br> - destroy：销毁 |

  可使用如下正则表达式匹配相关日志：

  `\(-?\d+:-?\d+:(scope|active|default|singleton|foreground|undefined)\)\] \[[a-z0-9.]+\]\[[a-zA-Z][0-9a-zA-Z_.]*\]\[\d+\]: window (focus|unfocus|foreground|background|destroy)`

  **示例说明**

  - 正确日志示例：

    `(-2:100000:singleton)] [com.example.helloworld][entry][100000]: window foreground`

  - 异常日志示例：

    `(100000:100000:scoped)] [com.example.helloworld][entry][100001]: window background`

    该异常日志说明存在错误跟踪ID为100000的UI实例。

  - 若前文出现以下特定格式的日志：

    `(-2:100000:singleton)] [com.example.helloworld][entry][100000]: window destroy`

    表示ID为100000的UI实例已销毁，后续UI操作可能受其上下文影响。

## 实例详细信息

某些实例相关接口的报错信息会包含对应实例的信息，仅有缓存列表中的实例会输出详细信息。缓存列表仅保存被销毁的实例的信息。

> **说明：**
>
> - 当前缓存列表大小为10，采用LRU（最近最少使用）机制进行淘汰。

### 缓存命中

异常实例命中缓存时，详细信息的输出格式如下：

`DestroyedUIContextCacheInfo: instanceInfo: [instanceId:<instanceId_>, createTime:<createTime_>, destroyTime:<destroyTime_>], windowInfo: [windowId: <windowId_>, windowName: <windowName_>]`

### 缓存未命中

当请求的实例在缓存中不存在（从未被缓存、或已因超出缓存大小被移除）时，详细信息的输出格式如下：

`InstanceId not found in destroyed cache.`

### 完整消息示例

被缓存的已销毁的实例详细信息按照如下格式进行输出，包括实例ID、创建时间、销毁时间、窗口ID、窗口名称字段：

`UI execution context not found.InstanceId: 100001,`

`Reason to get the instance: The instance is determined by the caller,`

`DestroyedUIContextCacheInfo: instanceInfo: [instanceId:100001, createTime:2026-04-14 10:30:00.123, destroyTime:2026-04-14 10:35:22.456], windowInfo: [windowId: 1001, windowName: EntryAbility]`

消息中各字段含义如下：

- `instanceId:100001`：表示请求的是100001号实例。
- `Reason to get the instance: The instance is determined by the caller`：表示由调用方显式指定了实例ID。
- `createTime:2026-04-14 10:30:00.123`：表示该实例创建时间为2026-04-14 10:30。
- `destroyTime:2026-04-14 10:35:22.456`：表示该实例销毁时间为2026-04-14 10:35，存活了约5分22秒。
- `windowId: 1001`：表示该实例关联窗口ID为1001。
- `windowName: EntryAbility`：表示该实例关联窗口名为EntryAbility。

**表2** 完整消息字段含义说明

| 属性                       | 说明                                          |
| -------------------------- | --------------------------------------------- |
| instanceId                 | 实例ID。由系统在创建实例时分配。              |
| Reason to get the instance | 获得对应实例的原因，详见表3实例指定原因说明。 |
| createTime                 | 实例创建的时刻。                              |
| destroyTime                | 实例销毁的时刻。                              |
| windowId                   | 实例对应的窗口的ID。                          |
| windowName                 | 实例对应的窗口的名称。                        |

**表3** 实例指定原因说明

| 描述                                                                                    | 说明                                                                                                                     |
| --------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| The instance is determined by the caller.                                               | 在调用过程中显式指定了实例ID。应用侧通常是通过[UIContext](../reference/apis-arkui/arkts-apis-uicontext.md)接口进行指定。 |
| No specific instance was specified, so the most recently active instance was retrieved. | 未显式指定实例ID，系统返回最近活跃的实例。                                                                               |
| No specific instance was specified, return the foreground instance.                     | 未显式指定实例ID，系统返回前台实例。                                                                                     |
| No specific instance was specified, return the only remaining instance.                 | 未显式指定实例ID，系统返回唯一的实例（仅存在一个UI实例时）。                                                             |
| No specific instance was specified, using default.                                      | 未显式指定实例ID，使用默认实例（最后创建的实例）。                                                                       |
| No valid instance exists.                                                               | 不存在有效的UI实例。                                                                                                     |

## 解决UIContext错误导致的显示异常问题

**问题现象**

当发生以下问题时，可根据上文的关键日志或异常进行判断：
1. 使用[setStyledString](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md#setstyledstring12)方法设置字体大小时，字体大小未发生预期变化。
2. 使用UIContext成员方法时，界面没有响应或显示异常。

**解决措施**

重新获取有效的UIContext对象。可通过以下方式获取：
- 使用自定义组件的[getUIContext](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#getuicontext)方法获取。
- 通过窗口的[getUIContext](../reference/apis-arkui/arkts-apis-window-Window.md#getuicontext10)方法获取。
