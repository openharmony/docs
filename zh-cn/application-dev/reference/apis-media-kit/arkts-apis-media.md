# 模块描述

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

媒体子系统为开发者提供一套简单且易于理解的接口，使得开发者能够方便接入系统并使用系统的媒体资源。

媒体子系统包含了音视频相关媒体业务，提供以下常用功能：

- 音视频播放（[AVPlayer](arkts-apis-media-AVPlayer.md)<sup>9+</sup>）

- 音视频录制（[AVRecorder](arkts-apis-media-AVRecorder.md)<sup>9+</sup>）

- 视频转码（[AVTranscoder](arkts-apis-media-AVTranscoder.md)<sup>12+</sup>）

- 获取音视频元数据（[AVMetadataExtractor](arkts-apis-media-AVMetadataExtractor.md)<sup>11+</sup>）

- 获取视频缩略图（[AVImageGenerator](arkts-apis-media-AVImageGenerator.md)<sup>12+</sup>）

- 屏幕录制（[AVScreenCaptureRecorder](arkts-apis-media-AVScreenCaptureRecorder.md)<sup>12+</sup>）

## 导入模块

```ts
import { media } from '@kit.MediaKit';
```