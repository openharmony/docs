# 媒体子系统音频接口变更说明

## cl.multimedia.1 ohos.multimedia.audio AudioRenderer接口setRenderRate/getRenderRate废弃

**访问级别**

公开接口

**废弃原因**

被功能更全面的新接口SetSpeed/GetSpeed替代，故废弃原接口

**废弃影响**

非兼容性变更，需要开发者进行适配。

**API Level**

setRenderRate(): 8

getRenderRate(): 8

getRenderRateSync(): 10

**废弃发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**废弃的接口**

接口属于AudioRenderer

setRenderRate(rate: AudioRendererRate, callback: AsyncCallback<void>): void;

setRenderRate(rate: AudioRendererRate): Promise<void>;

getRenderRate(callback: AsyncCallback<AudioRendererRate>): void;

getRenderRate(): Promise<AudioRendererRate>;

getRenderRateSync(): AudioRendererRate;

**适配指导**

根据废弃接口提示，使用AudioRenderer内的新接口即可，新接口支持通过浮点数调节播放速度，而非固定倍数。

setSpeed(speed: number): void;

getSpeed(): number;

废弃接口会在至少5个SDK版本内保持兼容，请应用按需规划适配计划