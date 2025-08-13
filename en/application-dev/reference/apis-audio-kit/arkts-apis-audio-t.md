# Types

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AudioRendererChangeInfoArray<sup>9+</sup>

type AudioRendererChangeInfoArray = Array&lt;Readonly&lt;AudioRendererChangeInfo&gt;&gt;

Defines an AudioRenderChangeInfo array, which is read-only.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Type     | Description                                                           |
|---------|---------------------------------------------------------------|
| Array&lt;Readonly&lt;AudioRendererChangeInfo&gt;&gt; | An [AudioRendererChangeInfo](arkts-apis-audio-i.md#audiorendererchangeinfo9) array, which is read-only.|


## AudioCapturerChangeInfoArray<sup>9+</sup>

type AudioCapturerChangeInfoArray = Array&lt;Readonly&lt;AudioCapturerChangeInfo&gt;&gt;

Defines an AudioCapturerChangeInfo array, which is read-only.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Type     | Description                                                             |
|---------|-----------------------------------------------------------------|
| Array&lt;Readonly&lt;AudioCapturerChangeInfo&gt;&gt; | An [AudioCapturerChangeInfo](arkts-apis-audio-i.md#audiocapturerchangeinfo9) array, which is read-only.|


## AudioEffectInfoArray<sup>10+</sup>

type AudioEffectInfoArray = Array&lt;Readonly&lt;AudioEffectMode&gt;&gt;

Defines an array that contains the audio effect mode corresponding to a specific audio content type (specified by **ContentType**) and audio stream usage (specified by **StreamUsage**). The [AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10) array is read-only.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Type     | Description                                                           |
|---------|---------------------------------------------------------------|
| Array&lt;Readonly&lt;AudioEffectMode&gt;&gt; | Defines an array that contains the audio effect mode corresponding to a specific audio content type (specified by **ContentType**) and audio stream usage (specified by **StreamUsage**). The [AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10) array is read-only.|

## AudioDeviceDescriptors

type AudioDeviceDescriptors = Array&lt;Readonly&lt;AudioDeviceDescriptor&gt;&gt;

Defines an [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) array, which is read-only.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Type     | Description                                                           |
|---------|---------------------------------------------------------------|
| Array&lt;Readonly&lt;AudioDeviceDescriptor&gt;&gt; | Defines an [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) array, which is read-only.|


## AudioRendererWriteDataCallback<sup>12+</sup>

type AudioRendererWriteDataCallback = (data: ArrayBuffer) => AudioDataCallbackResult | void

Defines the callback function used to write data to the audio renderer. Once the callback function finishes its execution, the audio service queues the data pointed to by **data** for playback. Therefore, do not change the data outside the callback. It is crucial to fill **data** with the exact length of data designated for playback; otherwise, noises may occur during playback.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name         | Type     |Mandatory  | Description        |
| :--------------| :--------| :----- | :------------ |
| data           | ArrayBuffer  | Yes| Data to be written to the buffer.|

**Return value**

| Type                                                          | Description                                                                                                         |
|--------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------|
| [AudioDataCallbackResult](arkts-apis-audio-e.md#audiodatacallbackresult12) \| void | If **void** or **AudioDataCallbackResult.VALID** is returned, the data is valid and the audio data is played. If **AudioDataCallbackResult.INVALID** is returned, the data is invalid and the audio data is not played.|
