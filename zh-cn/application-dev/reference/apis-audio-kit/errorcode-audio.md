# Audio错误码
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 6800101 无效入参

**错误信息**

Invalid parameter.

**错误描述**

调用接口时，传入的参数无效。

**可能原因**

参数无效，比如值不在边界范围内，没有使用指定的枚举范围等。

**处理步骤**

根据接口文档，传入正确的入参。

## 6800102 分配内存失败

**错误信息**

Memory allocation failed.

**错误描述**

调用接口时，分配内存失败或者出现空指针。

**可能原因**

1. 系统内存压力大，没有足够的内存用来映射。
2. 对于失效的实例，没有及时销毁释放内存。

**处理步骤**

1. 销毁当前实例。
2. 重新创建实例，如果重新创建失败，则停止相关操作。

## 6800103 状态不支持

**错误信息**

Operation not permitted at current state.

**错误描述**

对象当前状态不支持此操作。

**可能原因**

对象当前状态不支持操作，比如未启动流就播放数据等。

**处理步骤**

1. 确认当前状态是否支持当前操作。
2. 把对象切换到正确的状态进行正确的操作。

## 6800104 参数选项不支持

**错误信息**

Unsupported option.

**错误描述**

参数选项不支持。

**可能原因**

入参选值不在系统支持规格范围内。

**处理步骤**

1. 确认当前api支持的枚举或其他入参。
2. 改用支持的参数选项。

## 6800105 处理超时

**错误信息**

Timeout.

**错误描述**

处理等待超时。

**可能原因**

1. 系统内部存在异常，触发了内部接口的超时检测。
2. 系统依赖应用及时处理回调函数，应用未及时返回导致系统上报超时。

**处理步骤**

1. 系统内部的超时，应用只能上报错误信息。
2. 部分接口实现会依赖应用及时处理回调函数，如存在此情况，应用需要检查回调函数执行情况，确保及时返回，避免影响系统后续处理流程。

## 6800201 音频流数量达到极限

**错误信息**

Too many audio streams.

**错误描述**

音频流达到系统可支持的最大数量。

**可能原因**

多余的音频流没有及时释放。

**处理步骤**

1. 释放不再使用的音频流资源后进行重试。
2. 如果由于其他应用导致已经达到系统总量上限，则直接上报错误提示，让用户关闭其他应用。

## 6800301 系统处理异常

**错误信息**

System error.

**错误描述**

系统处理异常导致的音频接口处理失败。不同接口返回该错误码的原因不同，需要结合失败接口和系统日志进行排查。

**可能原因**

1. 系统服务重启、跨进程调用异常等系统处理异常。
2. 接口参数、应用权限或对象状态校验异常。对于自API版本20起新增的音频API，6800301错误码不包含本语义的信息。接口是否可能涉及此问题，以接口文档声明的错误码说明为准。
3. 音频焦点抢占失败。仅有需要激活音频焦点的音频流启动类接口（如AudioRenderer的[start](arkts-apis-audio-AudioRenderer.md#start8)接口、AudioCapturer的[start](arkts-apis-audio-AudioCapturer.md#start8)接口），可能由于音频焦点抢占失败返回此错误码，其他不涉及焦点激活的接口不会因该原因返回此错误码。

**处理步骤**

1. 根据返回错误码`6800301`的接口约束和系统日志，参考下文的常见问题案例，检查调用参数、应用权限和业务状态，排除应用侧异常。
2. 排除应用侧异常后，再尝试恢复业务，避免在异常状态下反复重试。

以下为AudioCapturer业务返回错误码`6800301`时的常见问题案例。


### 调用createAudioCapturer创建AudioCapturer失败-音频流类型异常

调用[createAudioCapturer](arkts-apis-audio-f.md#audiocreateaudiocapturer8)返回错误码`6800301`时，根据系统日志按照以下场景进行排查。

**判断依据**

应用进程日志提示`Invalid sourceType`。

```text
<应用进程名>: [CheckAndReportErrorEvent]Invalid sourceType -1!
```

以上日志格式，从API版本20开始支持。

**可能原因**

`AudioCapturerInfo.source`不在接口支持的音频源类型范围内。

**处理步骤**

根据[SourceType](arkts-apis-audio-e.md#sourcetype8)检查`source`的取值。

### 调用createAudioCapturer创建AudioCapturer失败-音频流参数异常

**判断依据**

应用进程日志出现以下任一信息：

```text
<应用进程名>: [CheckCapturerAudioStreamInfo]Unsupported audio capturer parameter
<应用进程名>: [IsRecordChannelRelatedInfoValid]AudioStream: Invalid source channel 0
<应用进程名>: [IsRecordChannelRelatedInfoValid]AudioStream: Invalid source channel layout
<应用进程名>: [IsRecordChannelRelatedInfoValid]AudioStream: not matched source channel and channel layout
```
以上日志格式，从API版本23开始支持。

**可能原因**

1. `samplingRate`、`sampleFormat`或`encodingType`参数值非法。`Unsupported audio capturer parameter`日志不能单独区分具体字段，需要结合应用入参排查。
2. `channels`或`channelLayout`参数值非法。
3. `channels`与`channelLayout`不匹配。

**处理步骤**

1. 根据[AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8)检查采样率、采样格式、编码类型、声道数和声道布局。
2. 由于`channelLayout`参数中隐含了声道数信息，需要确保声道布局的声道数和`channels`的值匹配。当`channelLayout`为`CH_LAYOUT_UNKNOWN(0x0)`时，不参与匹配校验。如需明确的声道布局，请根据`channels`显式设置对应布局。

### 调用createAudioCapturer创建AudioCapturer失败-麦克风未授权

调用[createAudioCapturer](arkts-apis-audio-f.md#audiocreateaudiocapturer8)返回错误码`6800301`时，根据系统日志按照以下场景依次排查。

**判断依据**

使用Mic音频源（即[SourceType](arkts-apis-audio-e.md#sourcetype8)为`SOURCE_TYPE_MIC`、`SOURCE_TYPE_VOICE_RECOGNITION`、`SOURCE_TYPE_VOICE_COMMUNICATION`、`SOURCE_TYPE_VOICE_MESSAGE`或`SOURCE_TYPE_LIVE`）创建AudioCapturer失败，系统日志提示麦克风未授权。各音频源的权限要求请参考[使用AudioCapturer开发音频录制功能](../../media/audio/using-audiocapturer-for-recording.md)。

系统音频服务进程可能出现以下一条或多条日志：

```text
audio_server: [VerifyClientPermission]Permission denied [...], [ohos.permission.MICROPHONE]
audio_server: [CheckRecorderPermission]Check record permission failed: No permission.
audio_server: [CreateAudioProcessInner]Create audio process failed, no permission
```

`CheckRecorderPermission`和`CreateAudioProcessInner`日志从API版本11开始支持；`VerifyClientPermission`日志从API版本12开始支持。

**可能原因**

1. 应用未声明`ohos.permission.MICROPHONE`权限。
2. 应用未向用户申请麦克风授权，或用户拒绝授权。

**处理步骤**

1. 确认应用已在`module.json5`中声明[ohos.permission.MICROPHONE](../../security/AccessToken/permissions-for-all-user.md#ohospermissionmicrophone)权限。
2. 创建AudioCapturer前，检查应用是否已获得麦克风授权。未授权时，按照[向用户申请授权](../../security/AccessToken/request-user-authorization.md)完成授权申请。
3. 用户拒绝授权时，不再创建使用Mic音频源的AudioCapturer，并在应用界面提示用户授权或停止录音操作。

### 调用start启动AudioCapturer失败-AudioCapturer状态异常

AudioCapturer创建成功，但调用[start](arkts-apis-audio-AudioCapturer.md#start8)返回错误码`6800301`时，根据系统日志按照以下场景排查。

**判断依据**

系统日志提示当前状态不支持启动。

应用进程的典型日志如下：

```text
<应用进程名>: [CheckStateAndReportErrorEvent]Start failed. Illegal state 2.
<应用进程名>: [CheckStateAndReportErrorEvent]Start failed. Illegal state 4.
```

以上日志格式，从API版本18开始支持。

日志中的状态值为`2`时，表示AudioCapturer处于`STATE_RUNNING`状态，通常为重复调用`start()`；状态值为`4`时，表示AudioCapturer处于`STATE_RELEASED`状态，通常为实例释放后继续调用`start()`。

**可能原因**

应用可能存在重复启动、释放后继续调用、异步状态转换未完成等情况。

**处理步骤**

1. 调用`start()`前检查[AudioState](arkts-apis-audio-e.md#audiostate8)。只有AudioCapturer处于`STATE_PREPARED`、`STATE_PAUSED`或`STATE_STOPPED`状态时才启动采集。
2. 通过[on('stateChange')](arkts-apis-audio-AudioCapturer.md#onstatechange8)监听状态变化，避免重复启动，避免在实例释放后继续操作。
3. 按照“创建实例 -> 注册回调 -> 启动录制 -> 停止录制 -> 释放资源”的顺序调用。完整状态检查请参考使用AudioCapturer开发音频录制功能中的[完整示例](../../media/audio/using-audiocapturer-for-recording.md#完整示例)。

### 调用start启动AudioCapturer失败-激活音频焦点失败

**判断依据**

日志提示激活音频焦点失败。

应用进程的典型日志如下：

```text
<应用进程名>: [Start]ActivateAudioInterrupt Failed
```

以上日志格式，从API版本10开始支持。

**可能原因**

设备上同时存在其他录音、通话等音频业务，当前流启动被焦点策略拦截。

**处理步骤**

参考[录音并发策略说明](../../media/audio/audio-recording-concurrency.md)，确认当前录音场景是否允许与其他音频业务并发，并根据并发策略调整业务启动时机或录音流类型。

### 调用start启动AudioCapturer失败-底层录音流启动异常

**判断依据**

若根据6800301系统处理异常下的音频流类型异常、麦克风未授权、AudioCapturer状态异常、激活音频焦点失败等案例进行排查后，应用进程仍出现以下一条或多条日志，说明可能发生系统侧异常：

```text
<应用进程名>: [StartAudioStream]Start call server failed: ...
<应用进程名>: [StartImpl]Start audio stream failed
```

`StartAudioStream`日志从API版本11开始支持；`StartImpl`日志从API版本12开始支持。

**可能原因**

底层录音流、音频服务或输入设备在启动阶段发生系统异常。

**处理步骤**

1. 先根据前述案例排除对象状态、应用权限、音频焦点和录音并发问题。
2. 停止并释放当前AudioCapturer，重新创建后重试一次。避免无条件反复重试。

### 调用activateAudioSession激活音频会话失败-类型异常

调用[activateAudioSession](../apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12)返回错误码`6800301`，应用捕获到的错误信息为"System error. Activate audio session fail."时，根据系统日志按照以下场景进行排查。

**判断依据**

```text
<音频客户端进程>: ActivateAudioSession failed,...
```

**可能原因**

`concurrencyMode`取值不在接口支持的并发模式范围内。

**处理步骤**

根据[AudioConcurrencyMode](../apis-audio-kit/arkts-apis-audio-e.md#audioconcurrencymode12)检查`concurrencyMode`取值是否为DEFAULT（0）、MIX_WITH_OTHERS（1）、DUCK_OTHERS（2）或PAUSE_OTHERS（3），如果不是上述定义则不在支持的范围内。

### 调用activateAudioSession/deactivateAudioSession/clearSelectedMediaInputDevice音频会话接口失败-系统异常

**判断依据**

调用[activateAudioSession](../apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12)、[deactivateAudioSession](../apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#deactivateaudiosession12)、[clearSelectedMediaInputDevice](../apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#clearselectedmediainputdevice21)返回错误码`6800301`时，会出现以下内容。

- 对应接口应用捕获到的错误信息：
 "System error. Activate audio session fail."
 "System error. Deactivate audio session fail."
 "System error. Clear selected input device fail."
- 同时出现以下一条或多条日志：
 "<音频客户端进程>: audio policy manager proxy is NULL."
 "<音频客户端进程>: ActivateAudioSession failed,..."

**可能原因**

1. 策略客户端代理获取失败，gsp对象为null。
2. IPC传输失败。

**处理步骤**

收集完整日志由系统侧进行分析。
