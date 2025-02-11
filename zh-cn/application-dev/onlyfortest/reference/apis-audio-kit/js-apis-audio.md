# @ohos.multimedia.audio (音频管理)

## 概述

音频管理提供管理音频的一些基础能力，包括对音频音量、音频设备的管理，以及对音频数据的采集和渲染等。

该模块提供以下音频相关的常用功能：

```
- [AudioManager](#audiomanager)：音频管理。
- [AudioRenderer](#audiorenderer8)：音频渲染，用于播放PCM（Pulse Code Modulation）音频数据。
- [AudioCapturer](#audiocapturer8)：音频采集，用于录制PCM音频数据。
```

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**起始版本：** 7

## 导入模块

```ts
import audio from '@ohos.multimedia.audio';
```

## 常量

| 名称                                    | 类型      | 可读  | 可写 | 说明               |
| --------------------------------------- | ----------| ---- | ---- | ------------------ |
| DEFAULT_VOLUME_GROUP_ID<sup>9+</sup>    | number    | 是   | 否   | 默认音量组id。<br> **系统能力：** SystemCapability.Multimedia.Audio.Volume       |
| DEFAULT_INTERRUPT_GROUP_ID<sup>9+</sup> | number    | 是   | 否   | 默认音频中断组id。<br> **系统能力：** SystemCapability.Multimedia.Audio.Interrupt       |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';

const defaultVolumeGroupId = audio.DEFAULT_VOLUME_GROUP_ID;
const defaultInterruptGroupId = audio.DEFAULT_INTERRUPT_GROUP_ID;
```

## audio.getAudioManager

getAudioManager(): AudioManager

获取音频管理器。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                          | 说明         |
| ----------------------------- | ------------ |
| `[AudioManager](#audiomanager)` | 音频管理对象。 |