# Interfaces (其他)
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

## MediaTab

媒体标签页的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称          | 类型                                                         | 只读 | 可选 | 说明                                               |
| ------------- | ------------------------------------------------------------ | ---- | ---- | -------------------------------------------------- |
| tabId         | string                                                       | 否   | 否   | 标签页的标识。                                     |
| tabName       | string                                                       | 否   | 否   | 标签页的名称。                                     |
| tabIcon       | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否   | 是   | 标签页的图标（接入模板时在主界面的标签页中必填）。 |
| extraDataJson | string                                                       | 否   | 是   | 标签页上的附加内容。                               |

## OperResult

操作结果的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称      | 类型   | 只读 | 可选 | 说明       |
| --------- | ------ | ---- | ---- | ---------- |
| errorCode | number   | 否   | 否   | 错误码。   |
| errorMsg  | string | 否   | 是   | 错误信息。 |

## MediaTabContent

媒体标签页内容的定义。继承自[OperResult](#operresult)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称         | 类型                            | 只读 | 可选 | 说明                 |
| ------------ | ----------------------------- | ---- | ---- | -------------------- |
| tabId        | string                        | 否   | 否   | 标签页的ID。         |
| compilations | [Compilation](#compilation)[] | 否   | 否   | 页面内容的合集数组。 |

## Compilation

合集的定义。继承自[OperResult](#operresult)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称            | 类型                                                         | 只读 | 可选 | 说明                            |
| --------------- | ------------------------------------------------------------ | ---- | ---- |-------------------------------|
| id              | string                                                       | 否   | 否   | 合集的唯一标识。                      |
| title           | string                                                       | 否   | 否   | 合集的标题。                        |
| hasMoreData     | boolean                                                      | 否   | 否   | 是否有更多的合集数据。true表示有，false表示没有。无默认值。|
| totalSize       | number                                                       | 否   | 否   | 合集的总个数。                       |
| memberMediaType | [EntityType](arkts-apis-avMusicTemplate-e.md#entitytype) | 否   | 否   | 合集的媒体资源类型。                    |
| topElements     | [MediaEntity](#mediaentity)[]                                  | 否   | 否   | 合集的内容。                        |

## Banner

海报的定义。继承自[MediaEntity](#mediaentity)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称             | 类型    | 只读 | 可选 | 说明                                 |
| ---------------- | ------- | ---- | ---- |------------------------------------|
| isSupportOnePlay | boolean | 否   | 否   | 是否支持一键启播。true表示支持，false表示不支持。无默认值。 |

## Album

专辑的定义。继承自[MediaEntity](#mediaentity)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称             | 类型                          | 只读 | 可选 | 说明               |
| ---------------- | ----------------------------- | ---- | ---- | ------------------ |
| singer           | string                        | 否   | 否   | 歌手名。           |
| playCounts       | string                        | 否   | 否   | 播放量。           |
| favSubscribeData | [FavoriteData](#favoritedata) | 否   | 否   | 收藏或订阅的信息。 |
| episodeCounts    | string                        | 否   | 是   | 专辑的总音频数。   |

## Ranking

排行榜的定义。继承自[MediaEntity](#mediaentity)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称        | 类型                            | 只读 | 可选 | 说明               |
| ----------- | ----------------------------- | ---- | ---- | ------------------ |
| topElements | [MediaEntity](#mediaentity)[] | 否   | 否   | 榜单下的推荐歌曲。 |

## MediaEntity

媒体实例的定义。继承自[OperResult](#operresult)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称            | 类型                                                         | 只读 | 可选 | 说明                    |
| --------------- | ------------------------------------------------------------ | ---- | ---- | ----------------------- |
| mediaId         | string                                                       | 否   | 否   | 媒体资源的ID。          |
| mediaType       | [EntityType](arkts-apis-avMusicTemplate-e.md#entitytype) | 否   | 否   | 媒体资源的类型。        |
| parentId        | string                                                       | 否   | 否   | 父节点的媒体资源ID。    |
| parentMediaType | [EntityType](arkts-apis-avMusicTemplate-e.md#entitytype) | 否   | 否   | 父节点的媒体资源类型。  |
| title           | string                                                       | 否   | 否   | 媒体资源的标题。        |
| desc            | string                                                       | 否   | 是   | 媒体资源的描述。        |
| imageUrl        | string                                                       | 否   | 否   | 媒体资源的封面图片URL。 |
| playState       | [PlaybackState](arkts-apis-avMusicTemplate-e.md#playbackstate) | 否   | 否   | 媒体资源的播放状态。    |

## QueryMediaEntityParam

查询媒体实例参数的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称          | 类型                                                         | 只读 | 可选 | 说明                   |
| ------------- | ------------------------------------------------------------ | ---- | ---- | ---------------------- |
| entityId      | string                                                       | 否   | 否   | 媒体实例的ID。         |
| pageIndex     | number                                                       | 否   | 否   | 分页查询页码。     |
| type          | [EntityType](arkts-apis-avMusicTemplate-e.md#entitytype) | 否   | 否   | 媒体资源类型。         |
| subEntityType | [EntityType](arkts-apis-avMusicTemplate-e.md#entitytype) | 否   | 是   | 子节点的媒体资源类型。 |
| sort          | [Sort](arkts-apis-avMusicTemplate-e.md#sort)       | 否   | 是   | 查询到的列表数据排序。 |
| episodeRange  | [EpisodeRange](#episoderange) | 否   | 是   | 要查询的剧集区间。     |

## EpisodeRange

剧集的范围的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称  | 类型 | 只读 | 可选 | 说明         |
| ----- | ---- | ---- | ---- | ------------ |
| start | number | 否   | 否   | 开始的索引。 |
| end   | number | 否   | 否   | 结束的索引。 |

## PageMediaEntity

标签页媒体的定义。继承自[OperResult](#operresult)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称            | 类型                                                         | 只读 | 可选 | 说明                                         |
| --------------- | ------------------------------------------------------------ | ---- | ---- | -------------------------------------------- |
| pageIndex       | number                                                       | 否   | 否   | 分页查询页码。                               |
| pageSize        | number                                                       | 否   | 否   | 页面的大小。                                 |
| hasMoreData     | boolean                                                      | 否   | 否   | 是否有下一页。true表示有，false表示没有。无默认值。|
| totalSize       | number                                                       | 否   | 否   | 数据总大小。                                 |
| memberMediaType | [EntityType](arkts-apis-avMusicTemplate-e.md#entitytype) | 否   | 否   | 媒体资源类型。                               |
| elements        | [MediaEntity](#mediaentity)[] | 否   | 否   | 查询数据内容（根据类型传递相应的结构数据）。 |
| sort            | [Sort](arkts-apis-avMusicTemplate-e.md#sort)       | 否   | 是   | 数据排序。                                   |
| episodeRange    | [EpisodeRange](#episoderange) | 否   | 是   | 剧集区间。                                   |

## Single

单曲的定义。继承自[MediaEntity](#mediaentity)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称             | 类型                                                         | 只读 | 可选 | 说明                                       |
| ---------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------ |
| isVip            | boolean                                                      | 否   | 否   | 是否是VIP歌曲。true表示是，false表示不是。无默认值。|
| singer           | string                                                       | 否   | 否   | 歌手的名字。                               |
| playInfo         | [PlayInfo](#playinfo) | 否   | 否   | 播放歌曲信息。                             |
| favSubscribeData | [FavoriteData](#favoritedata) | 否   | 否   | 收藏或订阅的歌曲的信息。                   |
| tags             | string[]                                                     | 否   | 是   | 歌曲标签信息的数组。                       |
| settings         | [SettingItem](#settingitem)[]                                | 否   | 是   | 歌曲设置项的数组。                         |
| downloadStatus   | [DownloadStatus](arkts-apis-avMusicTemplate-e.md#downloadstatus) | 否   | 是   | 歌曲下载状态。                             |
| downloadProgress | number                                                       | 否   | 是   | 歌曲下载进度。                             |

## PlayInfo

播放信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称                   | 类型     | 只读 | 可选 | 说明                                  |
| ---------------------- | -------- | ---- | ---- |-------------------------------------|
| playCounts             | string   | 否   | 否   | 播放次数。                               |
| isSupportNext          | boolean  | 否   | 否   | 是否支持下一首。true表示支持，false表示不支持。无默认值。|
| isSupportPrev          | boolean  | 否   | 否   | 是否支持上一首。true表示支持，false表示不支持。无默认值。|
| isSupportQuickForward  | boolean  | 否   | 否   | 是否支持快进。true表示支持，false表示不支持。无默认值。|
| isSupportQuickBackward | boolean  | 否   | 否   | 是否支持快退。true表示支持，false表示不支持。无默认值。|
| quickForwardStep       | number     | 否   | 否   | 快进的步长，单位为毫秒（ms）。                           |
| quickBackwardStep      | number     | 否   | 否   | 快退的步长，单位为毫秒（ms）。                        |
| isSupportSkipHead      | boolean  | 否   | 否   | 是否支持跳过开头。true表示支持，false表示不支持。无默认值。|
| isSupportSkipTail      | boolean  | 否   | 否   | 是否支持跳过结尾。true表示支持，false表示不支持。无默认值。|
| isSupportPlayMode      | boolean  | 否   | 否   | 是否支持切换播放模式。true表示支持，false表示不支持。无默认值。|
| isSupportPlayRate      | boolean  | 否   | 否   | 是否支持改变播放速率。true表示支持，false表示不支持。无默认值。|
| supportedPlayRate      | string[] | 否   | 否   | 支持的播放速率的数组。                        |
| currentPlayRate        | string   | 否   | 否   | 当前的播放速率。                            |
| isSupportSoundQuality  | boolean  | 否   | 否   | 是否支持声音质量。true表示支持，false表示不支持。无默认值。|
| isSupportSoundEffect   | boolean  | 否   | 否   | 是否支持音效。true表示支持，false表示不支持。无默认值。|
| totalDuration          | number     | 否   | 否   | 播放总时长，单位为毫秒（ms）。                            |
| currentPlayDuration    | number     | 否   | 否   | 当前播放的时长，单位为毫秒（ms）。                         |
| isSupportProgress      | boolean  | 否   | 否   | 是否支持进度。true表示支持，false表示不支持。默认值为true。 |

## FavoriteData

收藏/订阅的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称         | 类型    | 只读 | 可选 | 说明                                                       |
| ------------ | ------- | ---- | ---- | ---------------------------------------------------------- |
| isSupportFav | boolean | 否   | 否   | 是否支持收藏/订阅。true表示支持，false表示不支持。无默认值。|
| isFavorite   | boolean | 否   | 否   | 是否已收藏/订阅。true表示已收藏/订阅，false表示未收藏/订阅。无默认值。|
| favCounts    | string  | 否   | 否   | 收藏/订阅的数量。                                          |

## SettingItem

设置项的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称         | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ------------ | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| id           | string                                                       | 否   | 否   | 设置项的唯一ID。                                             |
| title        | string                                                       | 否   | 否   | 设置项的标题。                                               |
| desc         | string                                                       | 否   | 否   | 设置项的描述。                                               |
| settingType  | [SettingType](arkts-apis-avMusicTemplate-e.md#settingtype) | 否   | 是   | 设置项的类型。                                               |
| settingValue | string \| boolean \| [SettingContent](#settingcontent)[] \| [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md#wantagent) | 否   | 是   | 设置项的值。<br>- 当settingType为SettingType.SWITCH时，该值为boolean类型。<br>- 当settingType为SettingType.LIST时，该值为SettingContent数组。<br>- 当settingType为SettingType.JUMP时，该值为string类型。 |
| mediaId      | string                                                       | 否   | 否   | 与当前设置关联的媒体ID。<br>如果设置与当前媒体信息相关联，需要设置mediaId；否则，不需要设置mediaId。 |

## SettingContent

设置内容的定义。用于在音频模板的设置页面中展示或配置相关内容。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称       | 类型                                                         | 只读 | 可选 | 说明                                                |
| ---------- | ------------------------------------------------------------ | ---- | ---- | --------------------------------------------------- |
| value      | string                                                       | 否   | 否   | 设置的内容。                                        |
| isSelected | boolean                                                      | 否   | 否   | 是否选择设置项内容。true表示选择，false表示不选择。无默认值。|
| textTags   | string[]                                                     | 否   | 是   | 设置内容的描述的数组。                              |
| imageTags  | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)[] | 否   | 是   | 设置内容的图片标签数组。                          |

## QrCodeInfo

二维码信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称        | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ----------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| id          | string                                                       | 否   | 否   | 用于唯一标识用户登录的二维码会话。<br>当二维码过期时，MediaUI将使用此ID从媒体应用查询并更新新的二维码。 |
| price       | string                                                       | 否   | 否   | 购买价格。                                                   |
| titleName   | string                                                       | 否   | 否   | 标题名称。                                                   |
| detailName  | string                                                       | 否   | 否   | 详情名称。                                                   |
| tips        | string                                                       | 否   | 否   | 提示信息。                                                   |
| icon        | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否   | 是   | 与二维码关联的应用图标，用于应用登录的二维码应显示目标应用的图标。 |
| content     | string                                                       | 否   | 否   | 二维码的内容。                                               |
| codeData    | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否   | 是   | 二维码图片。                                                 |
| validPeriod | number                                                       | 否   | 否   | 二维码有效期（单位：秒）。<br/>当二维码到期时，二维码ID将用于再次查询并获得新的二维码。 |

## DialogActionInfo

对话框动作信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称         | 类型    | 只读 | 可选 | 说明                                                        |
| ------------ | ------- | ---- | ---- | ----------------------------------------------------------- |
| dialogId     | string  | 否   | 否   | 对话框动作的唯一标识符。                                    |
| isChecked    | boolean | 否   | 否   | 对话框中的复选框是否已选中。true表示已选中，false表示未选中。无默认值。|
| clickedBtnId | string  | 否   | 否   | 用户点击的按钮的ID。                                        |

## DialogInfo

对话框信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称        | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ----------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| dialogId    | string                                                       | 否   | 否   | 对话框的唯一ID。                                             |
| dialogType  | [DialogType](arkts-apis-avMusicTemplate-e.md#dialogtype) | 否   | 否   | 对话框的类型。                                               |
| title       | string                                                       | 否   | 是   | 对话框的标题。                                               |
| text        | string                                                       | 否   | 是   | 对话框的内容。                                               |
| buttons     | [DialogButtonInfo](#dialogbuttoninfo)[] | 否   | 是   | 对话框按钮的数组。                                           |
| qrCodes     | [QrCodeInfo](#qrcodeinfo)[]                                  | 否   | 是   | 对话框二维码的数组。<br>当设置了二维码信息时，此对话框将被识别为二维码对话框，并将优先显示二维码信息。最多可以设置两个。 |
| description | string                                                       | 否   | 是   | 对话框的其他信息。                                           |

## DialogButtonInfo

对话框按钮信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称       | 类型                                                         | 只读 | 可选 | 说明         |
| ---------- | ------------------------------------------------------------ | ---- | ---- | ------------ |
| buttonId   | string                                                       | 否   | 否   | 按钮的ID。   |
| buttonText | string                                                       | 否   | 否   | 按钮的文本。 |
| buttonType | [ButtonType](arkts-apis-avMusicTemplate-e.md#buttontype) | 否   | 否   | 按钮的类型。 |

## MemberPurchaseInfo

会员购买信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称               | 类型                                                         | 只读 | 可选 | 说明                        |
| ------------------ | ------------------------------------------------------------ | ---- | ---- |---------------------------|
| id                 | string                                                       | 否   | 否   | 会员购买信息的唯一ID。              |
| diagramUrl         | string                                                       | 否   | 否   | 会员购买图片的URL（该图片必须采用21:9的宽高比）。 |
| diagramData        | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否   | 是   | 会员购买图片。                   |
| diagramContent     | string                                                       | 否   | 否   | 会员购买图片的内容。                |
| memberPurchaseType | [MemberPurchaseType](arkts-apis-avMusicTemplate-e.md#memberpurchasetype) | 否   | 否   | 会员购买类型。                   |

## CustomElement

“我的主页”（应用内用户个人主页）自定义元素的定义。继承自[OperResult](#operresult)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称               | 类型                         | 只读 | 可选 | 说明         |
| ------------------ | -------------------------- | ---- | ---- | ------------ |
| userInfo           | [UserInfo](#userinfo)      | 否   | 是   | 用户信息。   |
| tabs               | [MediaTab](#mediatab)[]    | 否   | 是   | 标签页信息。 |
| customCompilations | [Compilation](#compilation)[] | 否   | 是   | 合集数组。   |
| settings           | [SettingItem](#settingitem)[] | 否   | 是   | 设置项数组。 |

## UserInfo

用户信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称          | 类型    | 只读 | 可选 | 说明                                |
| ------------- | ------- | ---- | ---- |-----------------------------------|
| userInfoId    | string  | 否   | 否   | 用户的唯一ID。                          |
| nickName      | string  | 否   | 否   | 用户昵称。                             |
| profilePicUrl | string  | 否   | 否   | 用户的头像图片URL。                       |
| tips          | string  | 否   | 否   | 其他关于用户的描述。                        |
| isLogin       | boolean | 否   | 否   | 用户是否登录。true表示已登录，false表示未登录。无默认值。 |
| isVip         | boolean | 否   | 否   | 用户是否是VIP。true表示是，false表示不是。无默认值。  |

## SearchPlayInfo

搜播（搜索播放）信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称      | 类型                                          | 只读 | 可选 | 说明             |
| --------- | ------------------------------------------- | ---- | ---- | ---------------- |
| musicInfo | [SearchPlayMusicInfo](#searchplaymusicinfo) | 否   | 是   | 搜播的音频信息。 |
| videoInfo | [SearchPlayVideoInfo](#searchplayvideoinfo) | 否   | 是   | 搜播的视频信息。 |

## SearchPlayMusicInfo

搜播的音频信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称          | 类型                                          | 只读 | 可选 | 说明                                                |
| ------------- | --------------------------------------------- | ---- | ---- | --------------------------------------------------- |
| items         | [SearchPlayMusicItem](#searchplaymusicitem)[] | 否   | 否   | 音频列表。                                          |
| displayName   | string                                        | 否   | 是   | 音频的显示名称。                                    |
| description   | string                                        | 否   | 是   | 对音频的描述。                                      |
| playMusicOnly | boolean                                       | 否   | 是   | 是否仅执行播放音乐的操作。true表示是，false表示否。无默认值。|
| playMode      | string                                        | 否   | 是   | 音频的播放模式。                                    |

## SearchPlayMusicItem

搜播的音频项目的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称       | 类型   | 只读 | 可选 | 说明             |
| ---------- | ------ | ---- | ---- | ---------------- |
| entityId   | string | 否   | 否   | 音频的唯一标识。 |
| entityName | string | 否   | 是   | 音频的名称。     |

## SearchPlayVideoInfo

搜播的视频信息的定义。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称          | 类型   | 只读 | 可选 | 说明             |
| ------------- | ------ | ---- | ---- | ---------------- |
| entityId      | string | 否   | 否   | 视频的唯一标识。 |
| episodeId     | string | 否   | 是   | 视频的集数ID。   |
| episodeNumber | number   | 否   | 是   | 视频的剧集序号。     |
| extras        | string | 否   | 是   | 视频的额外信息。 |
