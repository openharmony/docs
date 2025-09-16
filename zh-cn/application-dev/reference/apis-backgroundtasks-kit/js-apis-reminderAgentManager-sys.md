# @ohos.reminderAgentManager (后台代理提醒)(系统接口)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @cheng-shichang-->
<!--Designer: @zhouben25-->
<!--Tester: @fenglili18-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供后台代理提醒的能力，即当应用被冻结或应用退出时，计时和提醒的功能将被系统服务代理。在开发过程中，开发者可以调用本模块接口创建定时提醒，提醒类型支持倒计时、日历、闹钟三种。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口请参见[@ohos.reminderAgentManager (后台代理提醒)](js-apis-reminderAgentManager.md)。


## 导入模块

```ts
import reminderAgentManager from '@ohos.reminderAgentManager';
```

## ActionButtonType

按钮的类型。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CUSTOM<sup>10+</sup>  | 2 | 表示自定义的按钮。 |

## ActionButton

弹出的提醒通知中按钮的类型和标题。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| wantAgent<sup>10+</sup> | [WantAgent](./js-apis-reminderAgentManager.md#wantagent) | 否 | 是 | 点击按钮跳转的ability信息。 |
| dataShareUpdate<sup>11+</sup> | [DataShareUpdate](#datashareupdate11) | 否 | 是 | 点击按钮将更新应用数据库。 |

## DataShareUpdate<sup>11+</sup>

更新数据库需要的参数信息。<br/>
数据提供方需要在module.json5中的proxyDatas节点定义要共享的表的标识，读写权限和基本信息。配置方式请见[数据代理](../../database/share-data-by-silent-access.md)。

**系统能力**：SystemCapability.Notification.ReminderAgent


| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| uri | string | 否 | 否 | 数据使用的URI，是跨应用数据访问的唯一标识。 |
| equalTo | Record<string, number \| string \| boolean> | 否 | 否 | 指示筛选条件，当前仅支持通过等于筛选。|
| value | [ValueBucket](../apis-arkdata/js-apis-data-valuesBucket.md#valuesbucket) | 否 | 否 | 指示要更新的数据。 |

## ReminderRequestCalendar

日历实例对象，用于设置提醒的时间。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| rruleWantAgent<sup>12+</sup> | [WantAgent](./js-apis-reminderAgentManager.md#wantagent) | 否 | 是 | 自定义重复日程，指明需要拉起的 Service Extension。 |