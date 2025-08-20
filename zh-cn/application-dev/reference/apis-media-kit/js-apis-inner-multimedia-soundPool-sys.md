# SoundPool (音频池)(系统接口)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

音频池加载播放实例，音频池提供了系统声音的加载、播放、音量设置、循环设置、停止播放、资源卸载等功能。

SoundPool需要和@ohos.multimedia.media配合使用，需要先通过[media.createSoundPool](arkts-apis-media-f.md#mediacreatesoundpool10)完成音频池实例的创建。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参考[SoundPool (音频池)](js-apis-inner-multimedia-soundPool.md)。

## PlayParameters

表示音频池播放参数设置。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

| 名称            | 类型                                     | 必填 | 说明                                                         |
| --------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| parallelPlayFlag | boolean | 否   | 是否和其它正在播放的音频并行播放的标识，true:不抢占音频焦点和其它正在播放的音频并行播放，false:抢占焦点打断其它正在播放的音频。默认值：false。<br/>此接口为系统接口。|
