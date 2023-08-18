# Readme


| Subsystem| Change Type| Change Description|
| -------- | -------- | -------- |
| Bundle management subsystem| Bottom-layer implementation changed| [1. The bottom layer implementation of getAllBundleInfo in ohos.bundle.d.ts is changed.](changelogs-bundlemanager.md#clbundlemanager1-bottom-layer-implementation-of-getallbundleinfo-in-ohosbundledts-changed)<br>[2. The bottom layer implementation of getAllApplicationInfo in ohos.bundle.d.ts is changed.](changelogs-bundlemanager.md#clbundlemanager2-bottom-layer-implementation-of-getallapplicationinfo-in-ohosbundledts-changed) |
| Bundle management subsystem| API permission changed| [1. The permission on getAllBundleInfo in ohos.bundle.bundleManager.d.ts is changed.](changelogs-bundlemanager.md#clbundlemanager3-permission-on-getallbundleinfo-in-ohosbundlebundlemanagerdts-changed)<br>[2. The permission on getAllApplicationInfo in ohos.bundle.bundleManager.d.ts is changed.](changelogs-bundlemanager.md#clbundlemanager4-permission-on-getallapplicationinfo-in-ohosbundlebundlemanagerdts-changed) |
| Bundle management subsystem| API/Component changed| [1. The getSpecifiedDistributionType API is moved from ohos.bundle.installer.d.ts to ohos.bundle.bundleManager.d.ts.](changelogs-bundlemanager.md#clbundlemanager5-getspecifieddistributiontype-moved-from-ohosbundleinstallerdts-to-ohosbundlebundlemanagerdts)<br>[2. The getAdditionalInfo API is moved from ohos.bundle.installer.d.ts to ohos.bundle.bundleManager.d.ts.](changelogs-bundlemanager.md#clbundlemanager6-getadditionalinfo-moved-from-ohosbundleinstallerdts-to-ohosbundlebundlemanagerdts) |
| Bundle management subsystem| API/Component changed| [proxyDatas is renamed proxyData.](changelogs-bundlemanager.md#clbundlemanager7-proxydatas-renamed-proxydata-in-the-modulejson5-file) |
| Bundle management subsystem| Configuration file changed| [schema in the module.json file is changed.](https://gitee.com/openharmony/docs/blob/master/en/release-notes/changelogs/OpenHarmony_4.0.9.3/changelogs-bundlemanager.md) |
| OS multimedia subsystem| Enumeration declaration changed| [The audio output stream type is changed from AUDIOSTREAM_TYPE_RERNDERER to AUDIOSTREAM_TYPE_RENDERER.](changelogs-multimedia.md#clmultimedia1-stream-type-enum-declaration-in-audio-c-apis-changed)|
| OS multimedia subsystem| Enumerated value changed| [1. For the OH_AudioStream_Usage enum, the enumerated value AUDIOSTREAM_USAGE_MEDIA is deleted, and AUDIOSTREAM_USAGE_COMMUNICATION is changed to AUDIOSTREAM_USAGE_VOICE_COMMUNICATION and AUDIOSTREAM_USAGE_VOICE_ASSISTANT.](changelogs-multimedia.md#clmultimedia2-oh_audiostream_usage-changed)<br>[2. The enumerated value AUDIOSTREAM_SAMPLE_F32LE is deleted for the OH_AudioStream_SampleFormat enum.](changelogs-multimedia.md#clmultimedia3-audiostream_sample_f32le-deleted-for-oh_audiostream_sampleformat) |
| OS multimedia subsystem| Input parameter changed| [The input parameter content is deleted from getAudioEffectInfoArray.](changelogs-multimedia.md#clmultimedia4-deleted-content-from-getaudioeffectinfoarray) |
| Multimedia subsystem| Input parameter changed| [The input parameter content is deleted from getAudioEffectInfoArray.](changelogs-multimedia.md#clmultimedia4-deleted-content-from-getaudioeffectinfoarray) |
| Multimedia subsystem| API changed| [The APIs related to audio track switching are deleted.](changelogs-multimedia.md#clmultimedia5-playback-apis-changed) |
| Ability - widget framework| API permission changed| [Some APIs are moved from ohos.app.form.formHost.d.ts and their permission is changed.](changelogs-formfwk.md#clformfwk1-some-apis-moved-from-ohosappformformhostdts-and-their-permission-changed) |
| Ability - widget framework| API parameter changed| [The callback parameter is moved as the last parameter in the event subscription and unsubscription APIs (on/off).](changelogs-formfwk.md#clformfwk2-adjusted-the-parameter-sequence-of-event-subscription-and-unsubscription-apis -onoff) |
| Pan-sensor subsystem| API/Component changed| [The attributes VibrateFromFile (custom vibration effect) and HapticFileDescriptor (file descriptor of the custom vibration configuration file) are added. The vibration effect supported by startVibration is extended from VibrateEffect = VibrateTime \| VibratePreset to VibrateEffect = VibrateTime \| VibratePreset \| VibrateFromFile.](changelogs-miscdevice.md) |


> **NOTE**
> 
> Unless otherwise specified, the changes described in this topic are ArkTS API changes.

<!--no_check-->