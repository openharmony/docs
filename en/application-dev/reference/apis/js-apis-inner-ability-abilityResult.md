# AbilityResult

The **AbilityResult** module defines the result code and data returned when an ability is started or destroyed.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Readable   | Writable    | Type                | Mandatory| Description                                                        |
| ----------- | -------- |-------- | -------------------- | ---- | ------------------------------------------------------------ |
| resultCode    | Yes   | No     | number               | No  | Result code returned when the ability is started or destroyed.                               |
| want   | Yes   | No     | [Want](./js-apis-app-ability-want.md)               | No  | Data returned when the ability is destroyed.|

**Example**
  ```ts
  let want = {
    bundleName: 'com.example.mydocapplication',
    abilityName: 'MainAbility',
  };
  this.context.startAbilityForResult(want, (error, data) => {
      let resultCode = data.resultCode;
      let want = data.want;
  });
  ```
