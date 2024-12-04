# SensorService Kit Changelog

## cl.sensors.1 Change of the count Attribute of VibratePreset from Mandatory to Optional

**Access Level**

Public API

**Reason for Change**

The **count** parameter of **VibratePreset** is mandatory even if the number of vibrations is **1**.

**Change Impact**

This change is a non-compatible change.

Before change: The **count** attribute of **VibratePreset** is mandatory.

```ts
interface VibratePreset {
    type: 'preset';
    effectId: string;
    count: number;
}
```

After change: The **count** attribute of **VibratePreset** is optional, and the default value is **1**.

```ts
interface VibratePreset {
    type: 'preset';
    effectId: string;
    count?: number;
}
```

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.27

**Key API/Component Changes**

count of VibratePreset in @ohos.vibrator.d.ts.

**Adaptation Guide**

The **count** attribute of **VibratePreset** is optional. If your app has a dependency on the type of this attribute, adaptation is required. For example, if the type of **count** is a number before change, you need to set the type of **count** to **number | undefined** after change.

```ts
let effect: VibratePreset = {
    type: 'preset',
    effectId: 'xxx',
    count: 2
};

let count: number | undefined = effect.count;
```
