# @ohos.hichecker (HiChecker)

The HiChecker module allows you to check issues that may be easily ignored during development of applications (including system-built and third-party applications). Such issues include calling of time-consuming functions by key application threads, event distribution and execution timeout in application processes, and ability resource leakage in application processes. The issues are recorded in logs or lead to process crashes explicitly so that you can find and rectify them.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { hichecker } from '@kit.PerformanceAnalysisKit';
```


## Constants

Provides the constants of all rule types.

**System capability**: SystemCapability.HiviewDFX.HiChecker

| Name                              | Type | Description                                                  |
| ---------------------------------- | -------- | ------------------------------------------------------ |
| RULE_CAUTION_PRINT_LOG             | bigint   | Alarm rule, which is programmed to print a log when an alarm is generated.                        |
| RULE_CAUTION_TRIGGER_CRASH         | bigint   | Alarm rule, which is programmed to force the application to exit when an alarm is generated.                      |
| RULE_THREAD_CHECK_SLOW_PROCESS     | bigint   | Caution rule, which is programmed to detect whether any time-consuming function is invoked.                  |
| RULE_CHECK_ABILITY_CONNECTION_LEAK | bigint   | Caution rule, which is programmed to detect whether ability leakage has occurred.                   |

## hichecker.addCheckRule<sup>9+</sup>

addCheckRule(rule: bigint): void

Adds one or more check rules. HiChecker detects unexpected operations or gives feedback based on the added rules. You can use **grep HiChecker** to check for the application running information in the hilog.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name | Type  | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| rule   | bigint | Yes  | Rule to be added. |

**Error codes**

| ID | Error Message |
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed, only one bigint type parameter is needed  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // Add a rule.
    hichecker.addCheckRule(hichecker.RULE_CAUTION_PRINT_LOG);
    // Add multiple rules.
    // hichecker.addCheckRule(
    //     hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);
} catch (err) {
    console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);
}
```

## hichecker.removeCheckRule<sup>9+</sup>

removeCheckRule(rule: bigint): void

Removes one or more rules. The removed rules will become ineffective.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name | Type  | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| rule   | bigint | Yes  | Rule to be removed. |

**Error codes**

| ID | Error Message |
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed, only one bigint type parameter is needed  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // Remove a rule.
    hichecker.removeCheckRule(hichecker.RULE_CAUTION_PRINT_LOG);
    // Remove multiple rules.
    // hichecker.removeCheckRule(
    //     hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);
} catch (err) {
    console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);
}
```

## hichecker.containsCheckRule<sup>9+</sup>

containsCheckRule(rule: bigint): boolean

Checks whether the specified rule exists in the collection of added rules. If the rule is of the thread level, this operation is performed only on the current thread.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name | Type  | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| rule   | bigint | Yes  | Rule to be checked. |

**Return value**

| Type   | Description                                                      |
| ------- | ---------------------------------------------------------- |
| boolean | Returns **true** if the rule exists in the collection of added rules; returns **false** otherwise. |

**Error codes**

| ID | Error Message |
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed, only one bigint type parameter is needed  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // Add a rule.
    hichecker.addCheckRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);

    // Check whether the added rule exists in the collection of added rules.
    hichecker.containsCheckRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS); // return true;
    hichecker.containsCheckRule(hichecker.RULE_CAUTION_PRINT_LOG); // return false;
} catch (err) {
    console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);
}
```

## hichecker.addRule<sup>(deprecated)</sup>

addRule(rule: bigint): void

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [hichecker.addCheckRule](#hicheckeraddcheckrule9).

Adds one or more rules. HiChecker detects unexpected operations or gives feedback based on the added rules.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name | Type  | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| rule   | bigint | Yes  | Rule to be added. |

**Example**

```ts
// Add a rule.
hichecker.addRule(hichecker.RULE_CAUTION_PRINT_LOG);

// Add multiple rules.
hichecker.addRule(
          hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);
```

## hichecker.removeRule<sup>(deprecated)</sup>

removeRule(rule: bigint): void

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [hichecker.removeCheckRule](#hicheckerremovecheckrule9).

Removes one or more rules. The removed rules will become ineffective.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name | Type  | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| rule   | bigint | Yes  | Rule to be removed. |

**Example**

```ts
// Remove a rule.
hichecker.removeRule(hichecker.RULE_CAUTION_PRINT_LOG);

// Remove multiple rules.
hichecker.removeRule(
          hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);
```

## hichecker.getRule

getRule(): bigint 

Obtains a collection of thread, process, and alarm rules that have been added.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| bigint | Collection of added rules. |

**Example**

```ts
// Add a rule.
hichecker.addRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);

// Obtain the collection of added rules.
hichecker.getRule();   // return 1n;
```

## hichecker.contains<sup>(deprecated)</sup>

contains(rule: bigint): boolean

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [hichecker.containsCheckRule](#hicheckercontainscheckrule9).

Checks whether the specified rule exists in the collection of added rules. If the rule is of the thread level, this operation is performed only on the current thread.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name | Type  | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| rule   | bigint | Yes  | Rule to be checked. |

**Return value**

| Type   | Description                                                      |
| ------- | ---------------------------------------------------------- |
| boolean | Returns **true** if the rule exists in the collection of added rules; returns **false** otherwise. |

**Example**

```ts
// Add a rule.
hichecker.addRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);

// Check whether the added rule exists in the collection of added rules.
hichecker.contains(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS); // return true;
hichecker.contains(hichecker.RULE_CAUTION_PRINT_LOG); // return false;
```
