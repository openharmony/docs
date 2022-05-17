# HiChecker

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import hichecker from '@ohos.hichecker';
```


## Constants

Provides the constants of all rule types.

**System capability**: SystemCapability.HiviewDFX.HiChecker

| Name                              | Type| Description                                                  |
| ---------------------------------- | -------- | ------------------------------------------------------ |
| RULE\_CAUTION\_PRINT\_LOG            | BigInt   | Alarm rule, which is programmed to print a log when an alarm is generated.                        |
| RULE\_CAUTION\_TRIGGER\_CRASH        | BigInt   | Alarm rule, which is programmed to force the application to exit when an alarm is generated.                      |
| RULE\_THREAD\_CHECK\_SLOW\_PROCESS    | BigInt   | Caution rule, which is programmed to detect whether any time-consuming function is invoked.                  |
| RULE\_CHECK\_SLOW\_EVENT             | BigInt   | Caution rule, which is programmed to detect whether the event distribution or processing time has exceeded the specified time threshold. |
| RULE\_CHECK\_ABILITY\_CONNECTION\_LEAK| BigInt   | Caution rule, which is programmed to detect whether ability leakage has occurred.                   |


## hichecker.addRule

addRule(rule: BigInt): void

Adds one or more rules. HiChecker detects unexpected operations or gives feedback based on the added rules.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name | Type | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| rule   | BigInt | Yes  | Rule to be added. |

**Example**

```js
// Add a rule.
hichecker.addRule(hichecker.RULE_CAUTION_PRINT_LOG);

// Add multiple rules.
hichecker.addRule(
          hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);
```

## hichecker.removeRule

removeRule(rule: BigInt): void

Removes one or more rules. The removed rules will become ineffective.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name | Type | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| rule   | BigInt | Yes  | Rule to be removed. |

**Example**

```js
// Remove a rule.
hichecker.removeRule(hichecker.RULE_CAUTION_PRINT_LOG);

// Remove multiple rules.
hichecker.removeRule(
          hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);
```

## hichecker.getRule

getRule(): BigInt 

Obtains a collection of thread, process, and alarm rules that have been added.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| BigInt | Collection of added rules. |

**Example**

```js
// Add a rule.
hichecker.addRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);

// Obtain the collection of added rules.
hichecker.getRule();   // Return 1n.
```

## hichecker.contains

contains(rule: BigInt): boolean

Checks whether the specified rule exists in the collection of added rules. If the rule is of the thread level, this operation is performed only on the current thread.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name | Type | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| rule   | BigInt | Yes  | Rule to be checked. |

**Return value**

| Type   | Description                                                      |
| ------- | ---------------------------------------------------------- |
| boolean | Returns **true** if the rule exists in the collection of added rules; returns **false** otherwise. |

**Example**

```js
// Add a rule.
hichecker.addRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);

// Check whether the added rule exists in the collection of added rules.
hichecker.contains(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS); // Return true.
hichecker.contains(hichecker.RULE_CAUTION_PRINT_LOG); // Return false.
```