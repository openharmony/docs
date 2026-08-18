# Enums
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_gyH0B0hP-->
<!--Designer: @ccfriend-->
<!--Tester: @chen-gong1-->
<!--Adviser: @w_Machine_cc-->

> **说明：**
>
> - 本模块首批接口从API version 23开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块仅适用于API version 23及以上版本的Car设备。

## AVMusicTemplateType

表示音频模板类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称    | 值         | 说明                                                         |
| ------- | ---------- | ------------------------------------------------------------ |
| DEFAULT | 'smartCar' | 音频模板类型的默认值。<br>用于标识当前音频模板应用的业务类型。 |

## EntityType

表示媒体资源类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称          | 值   | 说明                 |
| ------------- | ---- | -------------------- |
| UNKNOWN       | 0    | 未知的媒体资源类型。 |
| SINGLE        | 1    | 单曲类型。           |
| SINGER        | 2    | 歌手类型。           |
| ALBUM         | 3    | 专辑类型。           |
| RANKING       | 4    | 排行榜类型。         |
| BANNER        | 5    | 海报类型。           |
| RADIO_STATION | 6    | 电台类型。           |

## PlaybackState

表示媒体资源的播放状态的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称                     | 值   | 说明                                                         |
| ------------------------ | ---- | ------------------------------------------------------------ |
| PLAYBACK_STATE_PREPARE   | 0    | 准备中状态。<br>表示媒体文件尚未准备好播放，媒体正在加载或缓冲中。 |
| PLAYBACK_STATE_PLAY      | 1    | 正在播放状态。                                               |
| PLAYBACK_STATE_PAUSE     | 2    | 暂停状态。                                                   |
| PLAYBACK_STATE_STOP      | 3    | 停止状态。                                                   |
| PLAYBACK_STATE_COMPLETED | 4    | 播放完成状态。                                               |
| PLAYBACK_STATE_ERROR     | 5    | 播放错误状态。                                               |
| PLAYBACK_STATE_BUFFERING | 6    | 缓冲状态。                                                   |

## Sort

表示查询到的列表数据排序类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称          | 值   | 说明        |
| ------------- | ---- |-----------|
| NONE          | 0    | 不指定排序方式，使用默认正序。 |
| ORDER         | 1    | 正序。       |
| REVERSE_ORDER | 2    | 倒序。       |

## SettingType

表示设置类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称   | 值   | 说明                                             |
| ------ | ---- | ------------------------------------------------ |
| SWITCH | 0    | 开关设置，用于控制功能的开启或关闭。 |
| LIST   | 1    | 列表设置，用于从多个选项中选择一个选项。 |
| JUMP   | 2    | 跳转设置，用于跳转到另一个界面。             |

## DialogType

表示对话框类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称     | 值   | 说明         |
| -------- | ---- | ------------ |
| NORMAL   | 0    | 普通对话框。 |
| INTERNET | 1    | 联网对话框。 |
| FLOW     | 2    | 流程对话框。 |
| PAID     | 3    | 付费对话框。 |
| VIP      | 4    | VIP对话框。  |
| LOGIN    | 5    | 登录对话框。 |
| ERROR    | 6    | 错误对话框。 |
| UNKNOWN  | 7    | 未知对话框。 |

## ButtonType

表示按钮类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称      | 值   | 说明       |
| --------- | ---- | ---------- |
| NORMAL    | 0    | 普通按钮。 |
| EMPHASIZE | 1    | 强调按钮。 |

## MemberPurchaseType

表示会员购买类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称   | 值       | 说明      |
| ------ | -------- |---------|
| NORMAL | 'normal' | 常规购买。   |
| BANNER | 'banner' | 会员推广海报购买。 |

## SearchPlayInfoType

表示搜播信息类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称       | 值          | 说明       |
| ---------- | ----------- | ---------- |
| PLAY_MUSIC | 'playMusic' | 播放音乐。 |
| PLAY_VIDEO | 'playVideo' | 播放视频。 |

## DownloadStatus

表示下载状态类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称             | 值   | 说明       |
| ---------------- | ---- | ---------- |
| DOWNLOAD_SUCCESS | 0    | 下载成功。 |
| DOWNLOADING      | 1    | 下载中。   |
| DOWNLOAD_FAIL    | 2    | 下载失败。 |

## AVMusicTemplateErrorCode

表示错误码类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称             | 值   | 说明       |
| ---------------- | ---- | ---------- |
| ERR_CODE_CREATE_AV_MUSIC_TEMPLATE_FAILED | 35000001 | 音频模板创建失败。|
| ERR_CODE_CREATE_AV_MUSIC_TEMPLATE_CONTROLLER_FAILED | 35000002 | 音频模板控制器创建失败。 |
| ERR_CODE_TEMPLATE_LISTENER_NO_EXIT | 35000003 | 模板监听未注册。 |
| ERR_CODE_CONTROLLER_CALLBACK_NO_EXIT | 35000004 | 未注册模板控制器回调。 |
| ERR_CODE_AV_MUSIC_TEMPLATE_NOT_EXIST | 35000005 | 音频模板不存在。 |
| ERR_CODE_CONTROLLER_NOT_EXIST | 35000006 | 模板控制器不存在。 |
| ERR_CODE_CONTROLLER_IS_EXIST | 35000007 | 模板控制器已经存在。|
| ERR_CODE_SERVICE_NOT_EXIST | 35000008 | 音频模板管理服务不存在。 |
| ERR_CODE_SERVICE_EXCEPTION | 35000009 | 音频模板管理服务异常。 |
| ERR_CODE_EXCEED_MAX_DATA_SIZE | 35000010 | 数据超过了允许的最大传输容量。 |
| ERR_CODE_WRITE_RESULT_EXCEPTION | 35000011 | 写数据失败，数据不可用。 |
| ERR_CODE_AV_MUSIC_TEMPLATE_ERROR | 35000012 | 音频模板错误。 |