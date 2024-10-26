# Ability Subsystem Changelog

## cl.ability.1 API restartApp Changed

**Access Level**

Public API

**Reason for Change**

The change is made to prevent malicious applications from restarting themselves when they do not gain focus.

**Change Impact**

This change is a non-compatible change. An application should call the **restartApp** API when it is in the focus state. Otherwise, functions will be affected.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.31

**Adaptation Guide**

Call the **restartApp** API when the application is in the focus state.

**Example**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onForeground() {
    let applicationContext = this.context.getApplicationContext();
    let want: Want = {
      bundleName: 'com.example.myapp',
      abilityName: 'EntryAbility'
    };
    try {
      applicationContext.restartApp(want);
    } catch (error) {
      console.error(`restartApp fail, error: ${JSON.stringify(error)}`);
    }
  }
}
```
