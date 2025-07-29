# SoundPool (Sound Pool) (System API)

The module provides APIs for loading, unloading, playing, and stopping playing system sounds, setting the volume, and setting the number of loops.

Before using these APIs, you must call [media.createSoundPool](arkts-apis-media-f.md#mediacreatesoundpool10) to create a SoundPool instance.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [SoundPool (Sound Pool)](js-apis-inner-multimedia-soundPool.md).

## PlayParameters

Describes the playback parameters of the sound pool.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

| Name           | Type                                    | Mandatory| Description                                                        |
| --------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| parallelPlayFlag | boolean | No  | Whether the sound can be played in parallel with other active audio streams. The value **true** means that the sound can be played in parallel with other active audio streams, without preempting the audio focus, and **false** means the opposite. The default value is **false**.<br>This is a system API.|
