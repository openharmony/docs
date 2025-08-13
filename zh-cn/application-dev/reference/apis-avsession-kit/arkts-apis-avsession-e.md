# Enums
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--SE: @ccfriend-->
<!--TSE: @chenmingxi1_huawei-->

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ProtocolType<sup>11+</sup>

远端设备支持的协议类型的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| TYPE_LOCAL<sup>11+</sup>      | 0    | 本地设备，包括设备本身的内置扬声器或音频插孔、A2DP 设备。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| TYPE_CAST_PLUS_STREAM<sup>11+</sup>      | 2    | Cast+的Stream模式。表示媒体正在其他设备上展示。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| TYPE_DLNA<sup>12+</sup>      | 4    | DLNA协议。表示媒体正在其他设备上展示。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| TYPE_CAST_PLUS_AUDIO<sup>20+</sup>      | 8    | PCM模式。表示媒体正在其他设备上展示。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## CastDisplayState<sup>12+</sup>

投播显示设备状态的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| STATE_OFF      | 1    | 设备断开，扩展屏不再显示内容。    |
| STATE_ON      | 2    | 设备连接成功，扩展屏可用。 |

## ConnectionState<sup>10+</sup>

连接状态枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| STATE_CONNECTING      | 0    | 设备连接中。    |
| STATE_CONNECTED      | 1    | 设备连接成功。 |
| STATE_DISCONNECTED      | 6    | 设备断开连接。 |

## CallState<sup>11+</sup>

表示通话状态的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明      |
| --------------------------  | ---- | -------- |
| CALL_STATE_IDLE             | 0    | 空闲状态。   |
| CALL_STATE_INCOMING         | 1    | 来电。     |
| CALL_STATE_ACTIVE           | 2    | 接通。     |
| CALL_STATE_DIALING          | 3    | 响铃。     |
| CALL_STATE_WAITING          | 4    | 等待接通。  |
| CALL_STATE_HOLDING          | 5    | 保持。     |
| CALL_STATE_DISCONNECTING    | 6    | 挂断。     |

## DisplayTag<sup>11+</sup>

枚举，表示当前媒体资源的金标，即应用媒体音源的特殊类型标识。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明           |
| --------------------------  | ---- | ------------ |
| TAG_AUDIO_VIVID             | 1    | AUDIO VIVID  |

## DecoderType<sup>19+</sup>

枚举，设备所支持的解码格式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明           |
| --------------------------  | ---- | ------------ |
| OH_AVCODEC_MIMETYPE_VIDEO_AVC      | "video/avc"  | VIDEO AVC  |
| OH_AVCODEC_MIMETYPE_VIDEO_HEVC     | "video/hevc" | VIDEO HEVC  |
| OH_AVCODEC_MIMETYPE_AUDIO_VIVID    | "audio/av3a" | AUDIO AV3A  |

## ResolutionLevel<sup>19+</sup>

枚举，设备所支持的分辨率。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明           |
| --------------------------  | ---- | ------------ |
| RESOLUTION_480P             | 0    | 分辨率为480P(640*480 dpi)。     |
| RESOLUTION_720P             | 1    | 分辨率为720P(1280*720 dpi)。    |
| RESOLUTION_1080P            | 2    | 分辨率为1080P(1920*1080 dpi)。   |
| RESOLUTION_2K               | 3    | 分辨率为2k(2560*1440 dpi)。   |
| RESOLUTION_4K               | 4    | 分辨率为4k(4096*3840 dpi)。   |

## AVCastCategory<sup>10+</sup>

投播的类别枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| CATEGORY_LOCAL      | 0    | 本地播放，默认播放设备，声音从本机或者连接的蓝牙耳机设备出声。     |
| CATEGORY_REMOTE      | 1    | 远端播放，远端播放设备，声音从其他设备发出声音或者画面。  |

## DeviceType<sup>10+</sup>

播放设备的类型枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| DEVICE_TYPE_LOCAL      | 0    | 本地播放类型。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.Core|
| DEVICE_TYPE_BLUETOOTH      | 10   | 蓝牙设备。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.Core |
| DEVICE_TYPE_TV      | 2    | 电视。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast |
| DEVICE_TYPE_SMART_SPEAKER      | 3   | 音箱设备。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast |

## LoopMode<sup>10+</sup>

表示媒体播放循环模式的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称               | 值   | 说明     |
| ------------------ | ---- | -------- |
| LOOP_MODE_SEQUENCE | 0    | 顺序播放。 |
| LOOP_MODE_SINGLE   | 1    | 单曲循环。 |
| LOOP_MODE_LIST     | 2    | 表单循环。 |
| LOOP_MODE_SHUFFLE  | 3    | 随机播放。 |
| LOOP_MODE_CUSTOM<sup>11+</sup>   | 4    | 自定义播放。  |

## PlaybackState<sup>10+</sup>

表示媒体播放状态的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| PLAYBACK_STATE_INITIAL      | 0    | 初始状态。     |
| PLAYBACK_STATE_PREPARE      | 1    | 播放准备状态。  |
| PLAYBACK_STATE_PLAY         | 2    | 正在播放。     |
| PLAYBACK_STATE_PAUSE        | 3    | 暂停。         |
| PLAYBACK_STATE_FAST_FORWARD | 4    | 快进。         |
| PLAYBACK_STATE_REWIND       | 5    | 快退。         |
| PLAYBACK_STATE_STOP         | 6    | 停止。         |
| PLAYBACK_STATE_COMPLETED    | 7    | 播放完成。     |
| PLAYBACK_STATE_RELEASED     | 8    | 释放。         |
| PLAYBACK_STATE_ERROR        | 9    | 错误。         |
| PLAYBACK_STATE_IDLE<sup>11+</sup>        | 10    | 空闲。     |
| PLAYBACK_STATE_BUFFERING<sup>11+</sup>         | 11    | 缓冲。   |

## AVSessionErrorCode<sup>10+</sup>

会话发生错误时的错误码。

| 名称                                   | 值      | 说明                             |
| -------------------------------------- | ------- | ------------------------------- |
| ERR_CODE_SERVICE_EXCEPTION             | 6600101 | 会话服务端异常。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**系统能力：** SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_SESSION_NOT_EXIST             | 6600102 | 会话不存在。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_CONTROLLER_NOT_EXIST          | 6600103 | 会话控制器不存在。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_REMOTE_CONNECTION_ERR         | 6600104 | 远端会话连接失败。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_COMMAND_INVALID               | 6600105 | 无效会话命令。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**系统能力：** SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_SESSION_INACTIVE              | 6600106 | 会话未激活。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_MESSAGE_OVERLOAD              | 6600107 | 命令&消息过载。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_DEVICE_CONNECTION_FAILED      | 6600108 | 设备连接失败。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_REMOTE_CONNECTION_NOT_EXIST   | 6600109 | 远端会话不存在。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_CAST_CONTROL_UNSPECIFIED<sup>13+</sup>    | 6611000 | 未被定义的投播错误码。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_REMOTE_ERROR<sup>13+</sup>    | 6611001 | 远端播放器中发生不明错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_BEHIND_LIVE_WINDOW<sup>13+</sup>     | 6611002 | 播放出现延迟。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_TIMEOUT<sup>13+</sup>     | 6611003 | 投播控制进程超时。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_RUNTIME_CHECK_FAILED<sup>13+</sup>      | 6611004 | 运行时检查失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PLAYER_NOT_WORKING<sup>13+</sup>      | 6611100 | 跨设备数据传输被锁定。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_SEEK_MODE_UNSUPPORTED<sup>13+</sup>      | 6611101 | 不支持指定的查找模式。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_ILLEGAL_SEEK_TARGET<sup>13+</sup>      | 6611102 | 要搜索的位置超出媒体的范围，或者不支持当前搜索模式。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PLAY_MODE_UNSUPPORTED<sup>13+</sup>      | 6611103 |  不支持指定的播放模式。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PLAY_SPEED_UNSUPPORTED<sup>13+</sup>      | 6611104 | 不支持指定的播放速度。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DEVICE_MISSING<sup>13+</sup>      | 6611105 | 操作失败，因为媒体源设备或媒体接收器设备已被销毁。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_INVALID_PARAM<sup>13+</sup>       | 6611106 | 该参数无效。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_NO_MEMORY<sup>13+</sup>       | 6611107 | 内存分配失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_OPERATION_NOT_ALLOWED<sup>13+</sup>       | 6611108 | 不被允许的操作。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_UNSPECIFIED<sup>13+</sup>       | 6612000 | 未指定的输入/输出错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NETWORK_CONNECTION_FAILED<sup>13+</sup>       | 6612001 | 网络连接失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NETWORK_CONNECTION_TIMEOUT<sup>13+</sup>       | 6612002 | 网络连接超时。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_INVALID_HTTP_CONTENT_TYPE <sup>13+</sup>      | 6612003 | 无效的"Content-Type"。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_BAD_HTTP_STATUS<sup>13+</sup>        | 6612004 | HTTP服务器返回一个意外的HTTP响应状态码。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_FILE_NOT_FOUND<sup>13+</sup>   | 6612005 | 文件不存在。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NO_PERMISSION<sup>13+</sup>    | 6612006 | 不允许执行输入/输出的IO操作。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_CLEARTEXT_NOT_PERMITTED<sup>13+</sup>    | 6612007 | 应用的网络安全配置不允许访问明文HTTP流量。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_READ_POSITION_OUT_OF_RANGE<sup>13+</sup>        | 6612008 | 从数据绑定中读取数据。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NO_CONTENTS<sup>13+</sup>     | 6612100 | 媒体中没有可播放的内容。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_READ_ERROR<sup>13+</sup>        | 6612101 | 媒体无法读取。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_CONTENT_BUSY<sup>13+</sup>         | 6612102 | 该资源正在使用中。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_CONTENT_EXPIRED<sup>13+</sup>    | 6612103 | 输入/输出的IO请求内容已过期。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_USE_FORBIDDEN<sup>13+</sup>    | 6612104 | 不允许播放请求内容。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NOT_VERIFIED<sup>13+</sup>     | 6612105 | 无法验证所允许的内容。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_EXHAUSTED_ALLOWED_USES<sup>13+</sup>     | 6612106 | 此内容已达到允许的最大使用次数。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NETWORK_PACKET_SENDING_FAILED<sup>13+</sup>   | 6612107 | 从源设备发送数据包到接收设备时出现错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_UNSPECIFIED<sup>13+</sup>    | 6613000 | 未指定的内容解析错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_CONTAINER_MALFORMED<sup>13+</sup>    | 6613001 | 媒体容器比特流的格式解析错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_MANIFEST_MALFORMED<sup>13+</sup>     | 6613002 | 媒体清单解析错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_CONTAINER_UNSUPPORTED<sup>13+</sup>   | 6613003 | 文件的媒体容器格式/媒体容器特性不被支持。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_MANIFEST_UNSUPPORTED<sup>13+</sup>      | 6613004 | 媒体清单中不支持的特性。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_UNSPECIFIED<sup>13+</sup>     | 6614000 | 未指定的解码错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_INIT_FAILED<sup>13+</sup>   | 6614001 | 解码器初始化失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_QUERY_FAILED<sup>13+</sup>     | 6614002 | 解码器查询失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_FAILED<sup>13+</sup>     | 6614003 | 媒体样本解码失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_FORMAT_EXCEEDS_CAPABILITIES<sup>13+</sup>    | 6614004 | 设备的能力无法解码当前格式。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_FORMAT_UNSUPPORTED<sup>13+</sup>    | 6614005 | 不支持的解码格式。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_UNSPECIFIED<sup>13+</sup>       | 6615000 | 未指定的音频渲染器错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_INIT_FAILED <sup>13+</sup>     | 6615001 | 音频渲染器初始化失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_WRITE_FAILED<sup>13+</sup>    | 6615002 | 音频渲染器写入数据失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_UNSPECIFIED<sup>13+</sup>      | 6616000 | 未指定的DRM相关错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_SCHEME_UNSUPPORTED<sup>13+</sup>  | 6616001 | 设备不支持所选择的DRM保护方案。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_PROVISIONING_FAILED<sup>13+</sup>   | 6616002 | 设备配置失败。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_CONTENT_ERROR<sup>13+</sup>  | 6616003 | 受DRM保护的内容无法播放。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_LICENSE_ACQUISITION_FAILED<sup>13+</sup>    | 6616004 | 获取许可证失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_DISALLOWED_OPERATION<sup>13+</sup>     | 6616005 | 许可证策略不允许该操作。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_SYSTEM_ERROR<sup>13+</sup>     | 6616006 | DRM系统中发生错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_DEVICE_REVOKED<sup>13+</sup>     | 6616007 | 设备已撤销DRM权限。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_LICENSE_EXPIRED<sup>13+</sup>   | 6616008 | 加载中的DRM许可证已过期。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_PROVIDE_KEY_RESPONSE_ERROR<sup>13+</sup>    | 6616100 | DRM处理密钥响应时发生错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|

## SkipIntervals<sup>11+</sup>

表示session支持的快进快退时间间隔的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                   | 值 | 说明                     |
| ---------------------- | -- | ----------------------- |
| SECONDS_10             | 10 | 时间为10秒。             |
| SECONDS_15             | 15 | 时间为15秒。             |
| SECONDS_30             | 30 | 时间为30秒。             |
