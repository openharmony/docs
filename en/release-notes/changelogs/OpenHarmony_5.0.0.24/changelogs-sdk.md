# SDK Subsystem Changelog

## cl.sdk.1 Severity Increased for an Alarm Generated When an API Available Only for the FA Model Is Used in a Stage Model Application or Vice Versa

**Change Reason**

An API available only for the FA model should not be used in an application developed in the stage model, and an API available only for the stage model should be used in an application developed in the FA model. The build process should be interrupted if this requirement is not met.

**Change Impact**

The application build behavior is affected.

***Before change:***

When an FA model application uses an API available only in the stage model, a WARN alarm is generated, with the message content as follows:

"This API is used only in Stage Mode, but the current Mode is FA."

When a stage model application uses an API available only in the FA model, a WARN alarm is generated, with the message content as follows:

"This API is used only in FA Mode, but the current Mode is Stage."

***After change:***

When an FA model application uses an API available only in the stage model, an ERROR alarm is generated, with the message content as follows:

"This API is used only in Stage Mode, but the current Mode is FA."

When a stage model application uses an API available only in the FA model, an ERROR alarm is generated, with the message content as follows:

"This API is used only in FA Mode, but the current Mode is Stage."

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.24

**Key API/Component Changes**

This change affects only the build. For details about the involved APIs and their substitutes, see [API Model Conversion List](./api-model-switch.md).

**Adaptation Guide**

If such an alarm is generated during application build, search for the corresponding API in [API Model Conversion List](./api-model-switch.md) based on the alarm information and find its substitute in the stage model. Then proceed as follows by scenario.

Scenario 1: A substitute exists.

Replace the API with the substitute in your code.

Negative example:
```ts
// The current project is in the stage model.
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext().getApplicationContext();
```

Positive example:
```ts
// The current project is in the stage model.
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let applicationContext: common.Context;
    try {
      applicationContext = this.context.getApplicationContext();
    } catch (error) {
      console.error(`getApplicationContext failed, error.code: ${error.code}, error.message: ${error.message}`);
    }
  }
}
```

Scenario 2: No substitute is available.

Delete the code of the incorrect API call.


## cl.sdk.2 Severity Increased for an Alarm Generated When an ArkTS Global Declarative API Is Used in TS Files

**Change Reason**

ArkTS global declarative APIs should not be used in TS files. The build process should be interrupted if this requirement is not met.

**Change Impact**

The application build behavior is affected.

***Before change:***

If an ArkTS global declarative API is used in a TS file, a WARN alarm is generated, with the message content as follows:

"Cannot find name 'xxx'."

***After change:***

If an ArkTS global declarative API is used in a TS file, an ERROR alarm is generated, with the message content as follows:

"Cannot find name 'xxx'."

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.24

**Key API/Component Changes**

This change only affects the build behavior.

**Adaptation Guide**

If such an alarm is generated during application build, proceed as follows by scenario:

Negative example:
```ts
// The current file is a TS file.
let pictureSource: Resource;
```

Scenario 1: The TS file can be changed to an ETS file.

Change the file name extension from .ts to .ets.

Scenario 2: The TS file cannot be changed to an ETS file.

1. Delete unnecessary ArkTS global declarative API calls.

2. Migrate common global APIs to the **component/common_ts_ets_api.d.ts** file.

## cl.sdk.3 Security Increased for an Alarm Generated When an API File in the Level-2 Directory Is Referenced

**Change Reason**

API files in the level-2 directory of the SDK cannot be referenced. The build process should be interrupted if this requirement is not met.

**Change Impact**

The application build behavior is affected.

***Before change:***

If an API file in the level-2 directory of the SDK is referenced, a WARN alarm is generated, with the message content as follows:

"Cannot find module 'xxx' or its corresponding type declarations."

***After change:***

If an API file in the level-2 directory of the SDK is referenced, an ERROR alarm is generated, with the message content as follows:

"Cannot find module 'xxx' or its corresponding type declarations."

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.24

**Key API/Component Changes**

This change only affects the build behavior.

**Adaptation Guide**

If such an alarm is generated during application build, perform the following steps:

1. Search for related API names in the API file of the SDK level-1 directory.

2. Replace the API call mode with a correct one.

Negative example:
```ts
import Context from 'application/Context';
let currentContext: Context;
```

Positive example:
```ts
import common from '@ohos.app.ability.common';
let currentContext: common.Context;
```
