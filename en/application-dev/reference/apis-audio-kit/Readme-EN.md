# Audio Kit
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

- ArkTS APIs<!--audio-arkts-->
  - @ohos.multimedia.audio (Audio Management)<!--js-apis-audio-->
    - [Module Description](arkts-apis-audio.md)
    - [Functions](arkts-apis-audio-f.md)
    - [Interface (AudioCapturer)](arkts-apis-audio-AudioCapturer.md)
    - [Interface (AudioDebuggingManager)](arkts-apis-audio-AudioDebuggingManager.md)
    - [Interface (AudioDeviceEnhanceManager)](arkts-apis-audio-AudioDeviceEnhanceManager.md)
    - [Interface (AudioManager)](arkts-apis-audio-AudioManager.md)
    - [Interface (AudioRecordingManager)](arkts-apis-audio-AudioRecordingManager.md)
    - [Interface (AudioRenderer)](arkts-apis-audio-AudioRenderer.md)
    - [Interface (AudioRoutingManager)](arkts-apis-audio-AudioRoutingManager.md)
    - [Interface (AudioSessionManager)](arkts-apis-audio-AudioSessionManager.md)
    - [Interface (AudioSpatializationManager)](arkts-apis-audio-AudioSpatializationManager.md)
    - [Interface (AudioStreamManager)](arkts-apis-audio-AudioStreamManager.md)
    - [Interface (AudioVolumeGroupManager)](arkts-apis-audio-AudioVolumeGroupManager.md)
    - [Interface (AudioVolumeManager)](arkts-apis-audio-AudioVolumeManager.md)
    - [Interface (AudioLoopback)](arkts-apis-audio-AudioLoopback.md)
    - [Interfaces (Others)](arkts-apis-audio-i.md)
    - [Enums](arkts-apis-audio-e.md)
    - [Constants](arkts-apis-audio-c.md)
    - [Types](arkts-apis-audio-t.md)
  - [@ohos.multimedia.audioHaptic (Audio-Haptic)](js-apis-audioHaptic.md)
  - [@ohos.multimedia.systemSoundManager (System Sound Management)](js-apis-systemSoundManager.md)
  <!--Del-->
  - [@ohos.multimedia.audio (Audio Management) (System API)](js-apis-audio-sys.md)
  - [@ohos.multimedia.audioHaptic (Audio-Haptic) (System API)](js-apis-audioHaptic-sys.md)
  - [@ohos.multimedia.systemSoundManager (System Sound Management) (System API)](js-apis-systemSoundManager-sys.md)
  <!--DelEnd-->
  - multimedia<!--audio-multimedia-->
    - [SystemSoundPlayer (Sound Effect Player)](js-apis-inner-multimedia-systemSoundPlayer.md)
    <!--Del-->
    - [ringtonePlayer (Ringtone Player) (System API)](js-apis-inner-multimedia-ringtonePlayer-sys.md)
    - [systemTonePlayer (System Tone Player) (System API)](js-apis-inner-multimedia-systemTonePlayer-sys.md)
    <!--DelEnd-->
- ArkTS Components<!--audio-comp-->
  - [@ohos.multimedia.avVolumePanel (Volume Panel)](ohos-multimedia-avvolumepanel.md)
- C APIs<!--audio-c-->
  - Modules<!--audio-module-->
    - [OHAudio](capi-ohaudio.md)
    - [OHAudioSuite](capi-ohaudiosuite.md)
    - [OHMIDI](capi-ohmidi.md)
  - Header Files<!--audio-headerfile-->
    - [native_audiocapturer.h](capi-native-audiocapturer-h.md)
    - [native_audio_manager.h](capi-native-audio-manager-h.md)
    - [native_audio_routing_manager.h](capi-native-audio-routing-manager-h.md)
    - [native_audio_session_manager.h](capi-native-audio-session-manager-h.md)
    - [native_audio_stream_manager.h](capi-native-audio-stream-manager-h.md)
    - [native_audio_volume_manager.h](capi-native-audio-volume-manager-h.md)
    - [native_audiorenderer.h](capi-native-audiorenderer-h.md)
    - [native_audio_common.h](capi-native-audio-common-h.md)
    - [native_audio_converter.h](capi-native-audio-converter-h.md)
    - [native_audio_device_base.h](capi-native-audio-device-base-h.md)
    - [native_audio_debugging_manager.h](capi-native-audio-debugging-manager-h.md)
    - [native_audio_device_enhance_manager.h](capi-native-audio-device-enhance-manager-h.md)
    - [native_audio_resource_manager.h](capi-native-audio-resource-manager-h.md)
    - [native_audiostream_base.h](capi-native-audiostream-base-h.md)
    - [native_audiostreambuilder.h](capi-native-audiostreambuilder-h.md)
    - [native_audio_suite_base.h](capi-native-audio-suite-base-h.md)
    <!--Del-->
    - [native_audio_suite_download_manager.h](capi-native-audio-suite-download-manager-h.md)
    <!--DelEnd-->
    - [native_audio_suite_engine.h](capi-native-audio-suite-engine-h.md)
    - [native_audio_session_base.h](capi-native-audio-session-base-h.md)
    - [native_midi_base.h](capi-native-midi-base-h.md)
    - [native_midi.h](capi-native-midi-h.md)
  - Structs<!--audio-struct-->
    - [OH_AudioManager](capi-ohaudio-oh-audiomanager.md)
    - [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md)
    - [OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md)
    - [OH_AudioSession_DeactivatedEvent](capi-ohaudio-oh-audiosession-deactivatedevent.md)
    - [OH_AudioSession_StateChangedEvent](capi-ohaudio-oh-audiosession-statechangedevent.md)
    - [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md)
    - [OH_AudioStreamManager](capi-ohaudio-oh-audiostreammanager.md)
    - [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md)
    - [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md)
    - [OH_AudioDeviceDescriptor](capi-ohaudio-oh-audiodevicedescriptor.md)
    - [OH_AudioDebuggingManager](capi-ohaudio-oh-audiodebuggingmanager.md)
    - [OH_AudioDeviceEnhanceManager](capi-ohaudio-oh-audiodeviceenhancemanager.md)
    - [OH_AudioResourceManager](capi-ohaudio-oh-audioresourcemanager.md)
    - [OH_AudioWorkgroup](capi-ohaudio-oh-audioworkgroup.md)
    - [OH_AudioStreamInfo](capi-ohaudio-oh-audiostreaminfo.md)
    - [OH_AudioRenderer_Callbacks_Struct](capi-ohaudio-oh-audiorenderer-callbacks-struct.md)
    - [OH_AudioCapturer_Callbacks_Struct](capi-ohaudio-oh-audiocapturer-callbacks-struct.md)
    - [OH_AudioStreamBuilderStruct](capi-ohaudio-oh-audiostreambuilderstruct.md)
    - [OH_AudioRendererStruct](capi-ohaudio-oh-audiorendererstruct.md)
    - [OH_AudioCapturerStruct](capi-ohaudio-oh-audiocapturerstruct.md)
    - [OH_AudioFormat](capi-ohaudiosuite-oh-audioformat.md)
    - [OH_AudioDataArray](capi-ohaudiosuite-oh-audiodataarray.md)
    - [OH_EqualizerFrequencyBandGains](capi-ohaudiosuite-oh-equalizerfrequencybandgains.md)
    - [OH_AudioSuiteEngineStruct](capi-ohaudiosuite-oh-audiosuiteenginestruct.md)
    - [OH_AudioSuitePipelineStruct](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)
    - [OH_AudioNodeStruct](capi-ohaudiosuite-oh-audionodestruct.md)
    - [OH_AudioNodeBuilderStruct](capi-ohaudiosuite-oh-audionodebuilderstruct.md)
    <!--Del-->
    - [OH_AudioSuite_DownloadStatusInfo](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfo.md)
    - [OH_AudioSuite_DownloadStatusInfoArray](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfoarray.md)
    - [OH_AudioSuite_DownloadManagerStruct](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md)
    <!--DelEnd-->
    - [OH_AudioSuite_SpaceRenderPositionParams](capi-ohaudiosuite-oh-audiosuite-spacerenderpositionparams.md)
    - [OH_AudioSuite_PureVoiceChangeOption](capi-ohaudiosuite-oh-audiosuite-purevoicechangeoption.md)
    - [OH_AudioSuite_SpaceRenderExtensionParams](capi-ohaudiosuite-oh-audiosuite-spacerenderextensionparams.md)
    - [OH_AudioSuite_SpaceRenderRotationParams](capi-ohaudiosuite-oh-audiosuite-spacerenderrotationparams.md)
    - [OH_AudioConverter_Format](capi-audioconverter-oh-audioconverter-format.md)
    - [OH_AudioConverterStruct](capi-audioconverter-oh-audioconverterstruct.md)
    - [OH_MIDIEvent](capi-ohmidi-oh-midievent.md)
    - [OH_MIDIDeviceInformation](capi-ohmidi-oh-midideviceinformation.md)
    - [OH_MIDIPortInformation](capi-ohmidi-oh-midiportinformation.md)
    - [OH_MIDIPortDescriptor](capi-ohmidi-oh-midiportdescriptor.md)
    - [OH_MIDICallbacks](capi-ohmidi-oh-midicallbacks.md)
    - [OH_MIDIClientStruct](capi-ohmidi-oh-midiclientstruct.md)
    - [OH_MIDIDeviceStruct](capi-ohmidi-oh-mididevicestruct.md)
- Error Codes<!--audio-arkts-errcode-->
  - [Audio Error Codes](errorcode-audio.md)
  <!--Del-->
  - [Ringtone Error Codes](errorcode-audio-ringtone-sys.md)
  <!--DelEnd-->
