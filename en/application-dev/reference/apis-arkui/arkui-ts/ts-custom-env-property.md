# \@CustomEnv: Custom Environment Variable

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @songyanhong-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=242f30791e1ff3fd9b4fa28a30d0fce83326a219 translatedAt=2026-08-11T01:46:24.837Z pushedAt=2026-08-13T07:04:37.438Z -->

This component is used to obtain custom environment variables.

See the developer guide: [\@CustomEnv: Custom Environment Variable](../../../ui/arkts-custom-env-property.md).

**Since:** 26.0.0

## @CustomEnv

CustomEnv\<T\>(key: CustomEnvKey\<T\>): PropertyDecorator

Obtains custom environment variables. A custom environment variable key is created through [CustomEnvKey.create()](#createt) and passed as a parameter to the **\@CustomEnv** decorator.

A variable decorated by **\@CustomEnv** reads the environment variable value corresponding to the key. If the environment variable is not set, the locally declared default value is used.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name|Type|Mandatory|Description|
| ----- | ----- | ------ |------ |
|key|CustomEnvKey\<T\>|Yes|Key of the custom environment variable, used to identify the custom environment variable to obtain.|

**Return value** 

|Type|Description| 
| ----- | ----- | 
|PropertyDecorator|Property decorator. You do not need to care about this return value.|

**Example**

``` TypeScript
const custom = CustomEnvKey.create<string>();

@Entry
@Component
struct Index {
  // Set the local default value for the variable decorated by @CustomEnv.
  @CustomEnv(custom) customVarName: string = 'hello world';

  build() {
    Column() {
      Text(`${this.customVarName}`)
    }
  }
}
```

## CustomEnvKey\<S\>

Defines the type of the key for a custom environment variable.

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- |-------------------------------------------------------------------------------------------------|
| type | S | No | Yes | Type of the key for a custom environment variable.|

### create\<T\>

static create\<T\>(): CustomEnvKey\<T\>

Creates a custom environment variable key, which serves as a parameter of the **\@CustomEnv** decorator.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Return value** 

| Type | Description |
| ----- | ----- |
| [CustomEnvKey\<T\>](#customenvkeys) | Custom environment variable key, used to identify the custom environment variable to obtain. |

**Example**

``` TypeScript
const customKey = CustomEnvKey.create<string>();
```

### constructor

protected constructor()

Creates an instance of this class.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full