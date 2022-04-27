# 检测模式

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import hichecker from '@ohos.hichecker';
```


## 常量

提供了所有规则类型的常量。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiChecker。

| 名称                               | 参数类型 | 说明                                                   |
| ---------------------------------- | -------- | ------------------------------------------------------ |
| RULE_CAUTION_PRINT_LOG             | BigInt   | 告警规则，当有告警时记录日志。                         |
| RULE_CAUTION_TRIGGER_CRASH         | BigInt   | 告警规则，当有告警时让应用推出。                       |
| RULE_THREAD_CHECK_SLOW_PROCESS     | BigInt   | 检测规则，检测是否有耗时函数被调用。                   |
| RULE_CHECK_SLOW_EVENT              | BigInt   | 检测规则，检测是否有事件分发或处理超过规定的时间阈值。 |
| RULE_CHECK_ABILITY_CONNECTION_LEAK | BigInt   | 检测规则，检测是否发生ability泄露。                    |


## hichecker.addRule

addRule(rule: BigInt): void

添加一条或多条规则到系统，系统根据添加的规则进行检测或反馈。

**系统能力：** SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| rule   | BigInt | 是   | 需要添加的规则。 |

**示例：**

```js
// 添加一条规则
hichecker.addRule(hichecker.RULE_CAUTION_PRINT_LOG);

// 添加多条规则
hichecker.addRule(
          hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);
```

## hichecker.removeRule

removeRule(rule: BigInt): void

删除一条或多条规则，删除的规则后续将不再生效。

**系统能力：** SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| rule   | BigInt | 是   | 需要删除的规则。 |

**示例：**

```js
// 删除一条规则
hichecker.removeRule(hichecker.RULE_CAUTION_PRINT_LOG);

// 删除多条规则
hichecker.removeRule(
          hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);
```

## hichecker.getRule

getRule(): BigInt 

获取当前线程规则、进程规则、告警规则的合集。

**系统能力：** SystemCapability.HiviewDFX.HiChecker

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| BigInt | 当前系统中添加的规则。 |

**示例：**

```js
// 添加一条规则
hichecker.addRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);

// 获取已添加的规则
hichecker.getRule();   // return 1n;
```

## hichecker.contains

contains(rule: BigInt): boolean

当前已添加的规则集中是否包含了某一个特定的规则，如果传入的规则级别为线程级别，则仅在当前线程中进行查询。

**系统能力：** SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| rule   | BigInt | 是   | 需要查询的规则。 |

**返回值：**

| 类型    | 说明                                                       |
| ------- | ---------------------------------------------------------- |
| boolean | 查询结果，true&nbsp;表示规则已添加，false 表示规则未添加。 |

**示例：**

```js
// 添加一条规则
hichecker.addRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);

// 查询是否包含
hichecker.contains(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS); // return true;
hichecker.contains(hichecker.RULE_CAUTION_PRINT_LOG); // return false;
```