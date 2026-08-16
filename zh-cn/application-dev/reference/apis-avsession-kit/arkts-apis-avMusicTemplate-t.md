# Types
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

## NoParamAsyncCallback

type NoParamAsyncCallback = () => Promise&lt;void&gt;

定义无参数的异步回调函数类型。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

## QueryMainTabsEvent

type QueryMainTabsEvent = () => Promise<MediaTab[]>

主标签页查询事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<[MediaTab](arkts-apis-avMusicTemplate-i.md#mediatab)[]> | Promise对象，返回媒体标签页的集合。 |

## QueryMediaTabContentEvent

type QueryMediaTabContentEvent = (tabId: string) => Promise&lt;MediaTabContent&gt;

媒体标签页内容查询事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| tabId  | string | 是   | 标签页的ID。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<[MediaTabContent](arkts-apis-avMusicTemplate-i.md#mediatabcontent)> | Promise对象，返回媒体标签页内容。 |

## QueryMediaEntityEvent

type QueryMediaEntityEvent = (params: QueryMediaEntityParam) => Promise&lt;PageMediaEntity&gt;

媒体实体查询事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型                                                                                       | 必填 | 说明                 |
| ------ |------------------------------------------------------------------------------------------| ---- | -------------------- |
| params | [QueryMediaEntityParam](arkts-apis-avMusicTemplate-i.md#querymediaentityparam) | 是   | 查询媒体实体的参数。 |

**返回值：**

| 类型                                                         | 说明                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| Promise<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | Promise对象，返回查询的媒体实体分页对象。 |

## QueryCompilationEvent

type QueryCompilationEvent = (compilationId: string, pageIndex: number) => Promise&lt;PageMediaEntity&gt;

合集查询事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名        | 类型   | 必填 | 说明         |
| ------------- | ------ | ---- | ------------ |
| compilationId | string | 是   | 合集的ID。   |
| pageIndex     | number    | 是   | 页面的索引。 |

**返回值：**

| 类型                                                         | 说明                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| Promise<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | Promise对象，返回查询的合集媒体实体对象。 |

## QueryPlaylistEvent

type QueryPlaylistEvent = (pageIndex: number, sort: Sort) => Promise&lt;PageMediaEntity&gt;

播放列表查询事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名    | 类型                                                     | 必填 | 说明           |
| --------- | ------------------------------------------------------ | ---- | -------------- |
| pageIndex | number                                                    | 是   | 页面的索引。   |
| sort      | [Sort](arkts-apis-avMusicTemplate-e.md#sort) | 是   | 排序类型。 |

**返回值：**

| 类型                                                         | 说明                                        |
| ------------------------------------------------------------ | ------------------------------------------- |
| Promise<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | Promise对象，返回查询的播放列表的分页对象。 |

## QueryCurrentSingleEvent

type QueryCurrentSingleEvent = () => Promise&lt;Single&gt;

当前单曲查询事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<[Single](arkts-apis-avMusicTemplate-i.md#single)> | Promise对象，返回Single对象。 |

## QueryCompilationByKeywordEvent

type QueryCompilationByKeywordEvent = (keyword: string) => Promise&lt;Compilation[]&gt;

按关键字查询合集的事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名  | 类型   | 必填 | 说明                   |
| ------- | ------ | ---- | ---------------------- |
| keyword | string | 是   | 用于查找合集的关键字。 |

**返回值：**

| 类型                                                         | 说明                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| Promise<[Compilation](arkts-apis-avMusicTemplate-i.md#compilation)[]> | Promise对象，返回与关键字相关的合集数组。 |

## QueryMediaEntityByKeywordEvent

type QueryMediaEntityByKeywordEvent = (keyword: string, searchType: EntityType, pageIndex: number) => Promise&lt;PageMediaEntity&gt;

按关键字查询媒体实体的事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型                                                                 | 必填 | 说明                   |
| ---------- |--------------------------------------------------------------------| ---- | ---------------------- |
| keyword    | string                                                             | 是   | 用于查找媒体的关键字。 |
| searchType | [EntityType](arkts-apis-avMusicTemplate-e.md#entitytype) | 是   | 要搜索的媒体资源类型。 |
| pageIndex  | number                                                                | 是   | 页面的索引。从0开始。  |

**返回值：**

| 类型                                                         | 说明                                              |
| ------------------------------------------------------------ | ------------------------------------------------- |
| Promise<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | Promise对象，返回关键字相关的媒体实体的分页对象。 |

## QueryRecommendMediaEntityListEvent

type QueryRecommendMediaEntityListEvent = () => Promise&lt;MediaEntity[]&gt;

推荐媒体实体列表查询事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise<[MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity)[]> | Promise对象，返回推荐的媒体实体的数组。 |

## QueryHotWordsEvent

type QueryHotWordsEvent = () => Promise&lt;string[]&gt;

热词查询事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型              | 说明                          |
| ----------------- | ----------------------------- |
| Promise<string[]> | Promise对象，返回热词的数组。 |

## QuerySearchHistoryEvent

type QuerySearchHistoryEvent = () => Promise&lt;string[]&gt;

搜索历史查询事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
| Promise<string[]> | Promise对象，返回搜索历史的数组。 |

## ClearSearchHistoryEvent

type ClearSearchHistoryEvent = () => Promise&lt;OperResult&gt;

清除搜索历史事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                                                         | 说明                                            |
| ------------------------------------------------------------ | ----------------------------------------------- |
| Promise<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回清除搜索历史的操作结果的对象。 |

## LoginEvent

type LoginEvent = (controlType: LoginType, id?: string) => Promise&lt;QrCodeInfo[]&gt;

登录事件。用于控制登录流程，包括查询登录信息、刷新登录信息、取消操作和退出登录。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                    | 必填 | 说明       |
| ----------- | ----------------------- | ---- | ---------- |
| controlType | [LoginType](#logintype) | 是   | 登录类型。 |
| id          | string                  | 否   | 二维码ID。 |

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<[QrCodeInfo](arkts-apis-avMusicTemplate-i.md#qrcodeinfo)[]> | Promise对象，返回二维码信息的数组。 |

## LoginType

type LoginType = 'queryLoginInfo' | 'refreshLoginInfo' | 'cancel' | 'logout'

登录的类型。该类型可取的值为下表字符串。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 类型               | 说明           |
| ------------------ | -------------- |
| 'queryLoginInfo'   | 查询登录信息。 |
| 'refreshLoginInfo' | 刷新登录信息。 |
| 'cancel'           | 取消。         |
| 'logout'           | 退出登录。     |

## RequestDialogInfoEvent

type RequestDialogInfoEvent = (actionType: DialogActionType, actionInfo?: DialogActionInfo) => Promise&lt;DialogInfo&gt;

对话框信息请求事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                   |
| ---------- | ------------------------------------------------------------ | ---- | ---------------------- |
| actionType | [DialogActionType](#dialogactiontype)                        | 是   | 对话框操作类型。           |
| actionInfo | [DialogActionInfo](arkts-apis-avMusicTemplate-i.md#dialogactioninfo) | 否   | 对话框动作结果的信息。 |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<[DialogInfo](arkts-apis-avMusicTemplate-i.md#dialoginfo)> | Promise对象，返回对话框信息。 |

## DialogActionType

type DialogActionType = 'open' | 'close' | 'refresh'

对话框操作类型。该类型可取的值为下表字符串。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 类型      | 说明   |
| --------- | ------ |
| 'open'    | 打开。 |
| 'close'   | 关闭。 |
| 'refresh' | 刷新。 |

## HandleMemberPurchaseEvent

type HandleMemberPurchaseEvent = (info: MemberPurchaseInfo) => Promise&lt;DialogInfo&gt;

处理购买会员事件。系统会在用户触发购买操作时调用此事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明             |
| ------ | ------------------------------------------------------------ | ---- | ---------------- |
| info   | [MemberPurchaseInfo](arkts-apis-avMusicTemplate-i.md#memberpurchaseinfo) | 是   | 购买会员的信息。 |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<[DialogInfo](arkts-apis-avMusicTemplate-i.md#dialoginfo)> | Promise对象，返回对话框信息。 |

## QueryMemberPurchaseEvent

type QueryMemberPurchaseEvent = (memberPurchaseType: MemberPurchaseType) => Promise&lt;MemberPurchaseInfo[]&gt;

购买会员查询事件。用于根据会员购买类型查询可用的会员购买信息，系统会在用户进入会员购买页面时调用此事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名             | 类型                                                         | 必填 | 说明             |
| ------------------ | ------------------------------------------------------------ | ---- | ---------------- |
| memberPurchaseType | [MemberPurchaseType](arkts-apis-avMusicTemplate-e.md#memberpurchasetype) | 是   | 购买会员的类型。 |

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise<[MemberPurchaseInfo](arkts-apis-avMusicTemplate-i.md#memberpurchaseinfo)[]> | Promise对象，返回会员购买信息的数组。 |

## QueryCustomContentEvent

type QueryCustomContentEvent = (queryType: CustomType[]) => Promise&lt;CustomElement&gt;

自定义内容查询事件。用于查询用户基本信息、界面选项卡配置、代码编译选项和系统设置项等自定义内容。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名    | 类型                          | 必填 | 说明                                        |
| --------- | --------------------------- | ---- | ------------------------------------------- |
| queryType | [CustomType](#customtype)[] | 是   | 自定义类型：包含用户基本信息、界面选项卡配置、代码编译选项和系统设置项。 |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise<[CustomElement](arkts-apis-avMusicTemplate-i.md#customelement)> | Promise对象，返回我的页面的自定义元素。 |

## CustomType

type CustomType = 'USER_INFO' | 'TAB' | 'COMPILATION' | 'SETTINGS'

自定义类型。该类型可取的值为下表字符串。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 类型          | 说明       |
| ------------- | ---------- |
| 'USER_INFO'   | 用户信息。 |
| 'TAB'         | 选项卡。   |
| 'COMPILATION' | 合集。     |
| 'SETTINGS'    | 设置。     |

## DownloadMediaEntityEvent

type DownloadMediaEntityEvent = (controlType: DownloadControlType, mediaEntity: MediaEntity) => Promise&lt;OperResult&gt;

媒体实体下载事件。用于控制媒体实体的下载流程，支持开始下载、暂停下载、恢复下载和删除下载操作。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                                       |
| ----------- | ---------------------------------------------------------- | ---- | ------------------------------------------ |
| controlType | [DownloadControlType](#downloadcontroltype)                | 是   | controlType的可选项包括：开始下载、删除下载、恢复下载、暂停下载。 |
| mediaEntity | [MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity) | 是   | 媒体实体。                                 |

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回下载媒体实体的操作结果对象。 |

## DownloadControlType

type DownloadControlType = 'startDownload' | 'deleteDownload' | 'resumeDownload' | 'pauseDownload'

下载操作控制类型。该类型可取的值为下表字符串。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 类型             | 说明       |
| ---------------- | ---------- |
| 'startDownload'  | 开始下载。 |
| 'deleteDownload' | 删除下载。 |
| 'resumeDownload' | 恢复下载。 |
| 'pauseDownload'  | 暂停下载。 |

## SettingsChangeEvent

type SettingsChangeEvent = (settingItem: SettingItem) => Promise&lt;SettingItem&gt;

设置变更事件类型。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明     |
| ----------- | ------------------------------------------------------------ | ---- | -------- |
| settingItem | [SettingItem](arkts-apis-avMusicTemplate-i.md#settingitem) | 是   | 设置项。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<[SettingItem](arkts-apis-avMusicTemplate-i.md#settingitem)> | Promise对象，返回变更过的设置项。 |

## ProblemAndAdviceEvent

type ProblemAndAdviceEvent = (advice: string) => Promise&lt;OperResult&gt;

问题和建议事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| advice | string | 是   | 问题和建议的内容。 |

**返回值：**

| 类型                                                         | 说明                                        |
| ------------------------------------------------------------ | ------------------------------------------- |
| Promise<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回问题和建议的操作结果对象。 |

## PlayForSearchEvent

type PlayForSearchEvent = (command: SearchPlayInfoType, args: SearchPlayInfo) => Promise&lt;OperResult&gt;

搜索并播放媒体的事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明             |
| ------- | ------------------------------------------------------------ | ---- | ---------------- |
| command | [SearchPlayInfoType](arkts-apis-avMusicTemplate-e.md#searchplayinfotype) | 是   | 搜播信息的类型。 |
| args    | [SearchPlayInfo](arkts-apis-avMusicTemplate-i.md#searchplayinfo) | 是   | 搜播信息。       |

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回搜播的操作结果对象。 |

## ExecuteActionEvent

type ExecuteActionEvent = (actionType: string, params: string) => Promise&lt;string&gt;

执行操作事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型   | 必填 | 说明       |
| ---------- | ------ | ---- | ---------- |
| actionType | string | 是   | 动作类型。 |
| params     | string | 是   | 参数信息。 |

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回执行操作的结果字符串。 |

## PlayMediaEntityEvent

type PlayMediaEntityEvent = (mediaEntity: MediaEntity) => Promise&lt;void&gt;

媒体实体播放事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                 |
| ----------- | ------------------------------------------------------------ | ---- | -------------------- |
| mediaEntity | [MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity) | 是   | 需要播放的媒体实体。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

## FavoriteMediaEntityEvent

type FavoriteMediaEntityEvent = (actionType: MediaFavoriteType, mediaEntity: MediaEntity) => Promise&lt;OperResult&gt;

媒体实体收藏事件。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                                                        | 必填 | 说明       |
| ----------- | ---------------------------------------------------------- | ---- | ---------- |
| actionType  | [MediaFavoriteType](#mediafavoritetype)                   | 是   | 操作类型。 |
| mediaEntity | [MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity) | 是   | 媒体实体。 |

**返回值：**

| 类型                      | 说明                                          |
| ------------------------- | --------------------------------------------- |
| Promise&lt;OperResult&gt; | Promise对象，返回收藏媒体实体的操作结果对象。 |

## MediaFavoriteType

type MediaFavoriteType = 'addFavorite' | 'removeFavorite'

媒体收藏类型的定义。该类型可取的值为下表字符串。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 类型             | 说明       |
| ---------------- | ---------- |
| 'addFavorite'    | 添加收藏。 |
| 'removeFavorite' | 取消收藏。 |

## DialogControlType

type DialogControlType = 'open' | 'close' | 'refresh' | 'toast'

对话框控制类型的定义。该类型可取的值为下表字符串。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 类型      | 说明   |
| --------- | ------ |
| 'open'    | 打开。 |
| 'close'   | 关闭。 |
| 'refresh' | 刷新。 |
| 'toast'   | 提示。 |

## ActionType

type ActionType = 'add' | 'remove'

操作类型的定义。该类型可取的值为下表字符串。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 类型     | 说明   |
| -------- | ------ |
| 'add'    | 添加。 |
| 'remove' | 移除。 |

## ReportDialogCommandEvent

type ReportDialogCommandEvent = (type: DialogControlType, buttonInfo: DialogInfo) => void

对话框命令上报事件。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明             |
| ---------- | ------------------------------------------------------------ | ---- | ---------------- |
| type       | [DialogControlType](#dialogcontroltype)                      | 是   | 对话框控制类型。 |
| buttonInfo | [DialogInfo](arkts-apis-avMusicTemplate-i.md#dialoginfo) | 是   | 对话框信息。     |

## ReportTabContentEvent

type ReportTabContentEvent = (tabId: string, tabContent: MediaTabContent) => void

标签页内容上报事件。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明           |
| ---------- | ------------------------------------------------------------ | ---- | -------------- |
| tabId      | string                                                       | 是   | 标签页的ID。   |
| tabContent | [MediaTabContent](arkts-apis-avMusicTemplate-i.md#mediatabcontent) | 是   | 标签页的内容。 |

## ReportCustomElementsChangeEvent

type ReportCustomElementsChangeEvent = (actionType: ActionType, customType: CustomType, customElement: CustomElement) => void

上报自定义元素改变事件。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名        | 类型                                                      | 必填 | 说明         |
| ------------- | ------------------------------------------------------- | ---- | ------------ |
| actionType    | [ActionType](#actiontype)                               | 是   | 操作类型。   |
| customType    | [CustomType](#customtype)                               | 是   | 自定义类型。 |
| customElement | [CustomElement](arkts-apis-avMusicTemplate-i.md#customelement) | 是   | 自定义元素。 |

## ReportExecuteActionEvent

type ReportExecuteActionEvent = (actionType: string, params: string) => void

执行动作上报事件。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型   | 必填 | 说明             |
| ---------- | ------ | ---- | ---------------- |
| actionType | string | 是   | 操作类型。       |
| params     | string | 是   | 执行动作的信息。 |

## ReportExecuteAbilityEvent

type ReportExecuteAbilityEvent = (want: WantAgent) => void

通知音频模板控制方拉起指定媒体应用界面事件。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| want   | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md#wantagent) | 是   | 媒体应用页面启动信息。 |