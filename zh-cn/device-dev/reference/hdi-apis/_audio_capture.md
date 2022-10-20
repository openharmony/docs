# AudioCapture


## **概述**

AudioCapture录音接口。

**相关模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| control | 音频控制能力接口，详情参考[AudioControl](_audio_control.md)。 | 
| attr | 音频属性能力接口，详情参考[AudioAttribute](_audio_attribute.md)。 | 
| scene | 音频场景能力接口，详情参考[AudioScene](_audio_scene.md)。 | 
| volume | 音频音量能力接口，详情参考[AudioVolume](_audio_volume.md)。 | 
| ([CaptureFrame](#captureframe))(struct&nbsp;AudioCapture&nbsp;\*capture,&nbsp;void&nbsp;\*frame,&nbsp;uint64_t&nbsp;requestBytes,&nbsp;uint64_t&nbsp;\*replyBytes) | 从音频驱动中录制（Capture）一帧输入数据（录音，音频上行数据）。 | 
| ([GetCapturePosition](#getcaptureposition))(struct&nbsp;AudioCapture&nbsp;\*capture,&nbsp;uint64_t&nbsp;\*frames,&nbsp;struct&nbsp;AudioTimeStamp&nbsp;\*time) | 获取音频输入帧数的上一次计数。 | 


## **类成员变量说明**


### CaptureFrame

  
```
int32_t(* AudioCapture::CaptureFrame) (struct AudioCapture *capture, void *frame, uint64_t requestBytes, uint64_t *replyBytes)
```

**描述：**

从音频驱动中录制（Capture）一帧输入数据（录音，音频上行数据）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| capture | 输入参数，待操作的音频录音接口对象。 | 
| frame | 输入参数，待存放输入数据的音频frame。 | 
| requestBytes | 输入参数，待存放输入数据的音频frame大小（字节数）。 | 
| replyBytes | 输出参数，实际读取到的音频数据长度（字节数），获取后保存到replyBytes中。 | 

**返回:**

成功返回值0，失败返回负值。


### GetCapturePosition

  
```
int32_t(* AudioCapture::GetCapturePosition) (struct AudioCapture *capture, uint64_t *frames, struct AudioTimeStamp *time)
```

**描述：**

获取音频输入帧数的上一次计数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| capture | 输入参数，待操作的音频录音接口对象。| 
| frames | 输出参数，获取的音频帧计数保存到frames中。 | 
| time | 输出参数，获取的关联时间戳保存到time中。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[CaptureFrame](#captureframe)
