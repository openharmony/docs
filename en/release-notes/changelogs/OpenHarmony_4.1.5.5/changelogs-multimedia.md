# Multimedia Subsystem Changelog

## cl.multimedia.1 APIs setRenderRate and getRenderRate of the AudioRenderer Class in ohos.multimedia.audio Are Deprecated

**Access Level**

Public API

**Reason for Change**

The **setRenderRate** and **getRenderRate** APIs are deprecated and replaced by **setSpeed** and **getSpeed**, which provide more comprehensive functions.

**Change Impact**

The change is not compatible with earlier versions. You are advised to use new APIs.

**API Level**

setRenderRate(): 8

getRenderRate(): 8

getRenderRateSync(): 10

**Deprecated Since**

OpenHarmony SDK 4.1.5.5

**Deprecated APIs**

In the **AudioRenderer** class:

setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void;

setRenderRate(rate: AudioRendererRate): Promise\<void>;

getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void;

getRenderRate(): Promise\<AudioRendererRate>;

getRenderRateSync(): AudioRendererRate;

**Adaptation Guide**

Use the new APIs in **AudioRenderer**. The new APIs support the adjustment of the playback speed through a floating point number instead of a fixed multiple.

setSpeed(speed: number): void;

getSpeed(): number;

The deprecated APIs will be retained for five more SDK versions. Make your adaptation plan as required.
