# native_audio_manager.h


## Overview

The **native_audio_manager.h** file declares the functions related to an audio manager.

**Library**: libohaudio.so

**File to include**: &lt;ohaudio/native_audio_manager.h&gt;

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AudioManager](_o_h_audio.md#oh_audiomanager) [OH_AudioManager](_o_h_audio.md#oh_audiomanager) | Defines a struct for the audio manager. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_GetAudioManager](_o_h_audio.md#oh_getaudiomanager)([OH_AudioManager](_o_h_audio.md#oh_audiomanager) \*\*audioManager) | Obtains an **OH_AudioManager** instance. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_GetAudioScene](_o_h_audio.md#oh_getaudioscene)([OH_AudioManager](_o_h_audio.md#oh_audiomanager) \*manager, [OH_AudioScene](_o_h_audio.md#oh_audioscene) \*scene) | Obtains the audio scene. | 
