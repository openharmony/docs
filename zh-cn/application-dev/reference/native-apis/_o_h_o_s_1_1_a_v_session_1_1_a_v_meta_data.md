# OHOS::AVSession::AVMetaData


## 概述

会话元数据类，提供获取metadata进程间传递的序列化和反序列话及数据拷贝的接口方法。


## 汇总


### Public 类型

  | 名称 | 描述 | 
| -------- | -------- |
| {<br/>**META_KEY_ASSET_ID** = 0, **META_KEY_TITLE** = 1, **META_KEY_ARTIST** = 2, **META_KEY_AUTHOR** = 3, **META_KEY_ALBUM** = 4, **META_KEY_WRITER** = 5, **META_KEY_COMPOSER** = 6, **META_KEY_DURATION** = 7, **META_KEY_MEDIA_IMAGE** = 8, **META_KEY_MEDIA_IMAGE_URI** = 9, **META_KEY_PUBLISH_DATE** = 10, **META_KEY_SUBTITLE** = 11, **META_KEY_DESCRIPTION** = 12, **META_KEY_LYRIC** = 13, **META_KEY_PREVIOUS_ASSET_ID** = 14, **META_KEY_NEXT_ASSET_ID** = 15, **META_KEY_MAX** = 16<br/>} | 会话元数据具体枚举项。  | 
| [MetaMaskType](#metamasktype) = std::bitset&lt; META_KEY_MAX &gt; | 引入掩码标记需要拷贝的会话元数据。  | 


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [AVMetaData](#avmetadata) ()=default | 会话元数据默认构造函数。  | 
| [~AVMetaData](#avmetadata) () override | 会话元数据默认析构函数。  | 
| [Marshalling](#marshalling) (Parcel &amp;data) const override | 实现会话元数据进程间传递的序列化。  | 
| [SetAssetId](#setassetid) (const std::string &amp;assetId) | 设置曲目ID。  | 
| [GetAssetId](#getassetid) () const | 获取曲目ID。  | 
| [SetTitle](#settitle) (const std::string &amp;title) | 设置标题。  | 
| [GetTitle](#gettitle) () const | 获取标题。  | 
| [SetArtist](#setartist) (const std::string &amp;artist) | 设置艺术家名称。  | 
| [GetArtist](#getartist) () const | 获取艺术家名称。  | 
| [SetAuthor](#setauthor) (const std::string &amp;author) | 设置制作人名称。  | 
| [GetAuthor](#getauthor) () const | 获取制作人名称。  | 
| [SetAlbum](#setalbum) (const std::string &amp;album) | 设置专辑名称。  | 
| [GetAlbum](#getalbum) () const | 获取专辑名称。  | 
| [SetWriter](#setwriter) (const std::string &amp;writer) | 设置作词名称。  | 
| [GetWriter](#getwriter) () const | 获取作词名称。  | 
| [SetComposer](#setcomposer) (const std::string &amp;composer) | 设置作曲名称。  | 
| [GetComposer](#getcomposer) () const | 获取作曲名称。  | 
| [SetDuration](#setduration) (int64_t duration) | 设置媒体时长。  | 
| [GetDuration](#getduration) () const | 获取媒体时长。  | 
| [SetMediaImage](#setmediaimage) (const std::shared_ptr&lt; [AVSessionPixelMap](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_pixel_map.md) &gt; &amp;mediaImage) | 设置媒体图片。  | 
| [GetMediaImage](#getmediaimage) () const | 获取媒体图片。  | 
| [SetMediaImageUri](#setmediaimageuri) (const std::string &amp;mediaImageUri) | 设置媒体图片URI。  | 
| [GetMediaImageUri](#getmediaimageuri) () const | 获取媒体图片URI。  | 
| [SetPublishDate](#setpublishdate) (double date) | 设置曲目发布日期，时间戳，单位为ms。  | 
| [GetPublishDate](#getpublishdate) () const | 获取曲目发布日期，时间戳，单位为ms。  | 
| [SetSubTitle](#setsubtitle) (const std::string &amp;subTitle) | 设置子标题。  | 
| [GetSubTitle](#getsubtitle) () const | 获取子标题。  | 
| [SetDescription](#setdescription) (const std::string &amp;description) | 设置曲目描述。  | 
| [GetDescription](#getdescription) () const | 获取曲目描述。  | 
| [SetLyric](#setlyric) (const std::string &amp;lyric) | 设置歌词。  | 
| [GetLyric](#getlyric) () const | 获取歌词。  | 
| [SetPreviousAssetId](#setpreviousassetid) (const std::string &amp;assetId) | 设置上一曲曲目ID。  | 
| [GetPreviousAssetId](#getpreviousassetid) () const | 获取上一曲曲目ID。  | 
| [SetNextAssetId](#setnextassetid) (const std::string &amp;assetId) | 设置下一曲曲目ID。  | 
| [GetNextAssetId](#getnextassetid) () const | 获取下一曲曲目ID。  | 
| [Reset](#reset) () | 重置所有会话元数据项。  | 
| [GetMetaMask](#getmetamask) () const | 获取掩码。  | 
| [CopyToByMask](#copytobymask) ([MetaMaskType](#metamasktype) &amp;mask, AVMetaData &amp;metaOut) const | 根据metadata掩码,将metadata项复制到metaOut。  | 
| [CopyFrom](#copyfrom) (const AVMetaData &amp;metaIn) | 根据metaIn元掩码的设置位从metaIn复制metadata项。  | 
| [IsValid](#isvalid) () const | 会话元数据有效性判断。  | 


### 静态 Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Unmarshalling](#unmarshalling) (Parcel &amp;data) | 实现会话元数据进程间传递的反序列化。  | 


### 静态 Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [DURATION_ALWAYS_PLAY](#durationalwaysplay) = -1 | 持续时间全局变量宏定义。  | 
| [localCapability](#localcapability) | 会话元数据数组，用于分布式业务，设置会话属性。  | 


## 成员类型定义说明


### MetaMaskType

  
```
using OHOS::AVSession::AVMetaData::MetaMaskType = std::bitset<META_KEY_MAX>
```
**描述:**
引入掩码标记需要拷贝的会话元数据。


## 成员枚举类型说明


### anonymous enum

  
```
anonymous enum
```
**描述:**
会话元数据具体枚举项。

  | 枚举值 | 描述 | 
| -------- | -------- |
| META_KEY_ASSET_ID  | 曲目ID | 
| META_KEY_TITLE  | 标题 | 
| META_KEY_ARTIST  | 艺术家 | 
| META_KEY_AUTHOR  | 制作人 | 
| META_KEY_ALBUM  | 专辑 | 
| META_KEY_WRITER  | 作词 | 
| META_KEY_COMPOSER  | 作曲 | 
| META_KEY_DURATION  | 媒体时长 | 
| META_KEY_MEDIA_IMAGE  | 媒体影像 | 
| META_KEY_MEDIA_IMAGE_URI  | 媒体影像路径 | 
| META_KEY_PUBLISH_DATE  | 曲目发布日期 | 
| META_KEY_SUBTITLE  | 子标题 | 
| META_KEY_DESCRIPTION  | 曲目描述 | 
| META_KEY_LYRIC  | 歌词 | 
| META_KEY_PREVIOUS_ASSET_ID  | 上一曲 | 
| META_KEY_NEXT_ASSET_ID  | 下一曲 | 
| META_KEY_MAX  | 无效指令，内部用来判断会话元数据是否有效 | 


## 构造及析构函数说明


### AVMetaData()

  
```
OHOS::AVSession::AVMetaData::AVMetaData ()
```
**描述:**
会话元数据默认构造函数。


### ~AVMetaData()

  
```
OHOS::AVSession::AVMetaData::~AVMetaData ()
```
**描述:**
会话元数据默认析构函数。


## 成员函数说明


### CopyFrom()

  
```
bool OHOS::AVSession::AVMetaData::CopyFrom (const AVMetaData & metaIn)
```
**描述:**
根据metaIn元掩码的设置位从metaIn复制metadata项。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| metaIn | 会话元数据将要拷贝的入参。| 


### CopyToByMask()

  
```
bool OHOS::AVSession::AVMetaData::CopyToByMask (MetaMaskType & mask, AVMetaData & metaOut ) const
```
**描述:**
根据metadata掩码,将metadata项复制到metaOut。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mask | metadata掩码[MetaMaskType](#metamasktype)。  | 
| metaOut | metadata已拷贝成功的出参AVMetaData。  | 

**返回:**

成功返回true；失败则返回false。


### GetAlbum()

  
```
std::string OHOS::AVSession::AVMetaData::GetAlbum () const
```
**描述:**
获取专辑名称。

**返回:**

返回专辑名称。

**参见:**

[SetAlbum](#setalbum)


### GetArtist()

  
```
std::string OHOS::AVSession::AVMetaData::GetArtist () const
```
**描述:**
获取艺术家名称。

**返回:**

返回艺术家名称。

**参见:**

[SetArtist](#setartist)


### GetAssetId()

  
```
std::string OHOS::AVSession::AVMetaData::GetAssetId () const
```
**描述:**
获取曲目ID。

**返回:**

返回曲目ID。

**参见:**

[SetAssetId](#setassetid)


### GetAuthor()

  
```
std::string OHOS::AVSession::AVMetaData::GetAuthor () const
```
**描述:**
获取制作人名称。

**返回:**

返回制作人名称。

**参见:**

[SetAuthor](#setauthor)


### GetComposer()

  
```
std::string OHOS::AVSession::AVMetaData::GetComposer () const
```
**描述:**
获取作曲名称。

**返回:**

返回作曲名称。

**参见:**

[SetComposer](#setcomposer)


### GetDescription()

  
```
std::string OHOS::AVSession::AVMetaData::GetDescription () const
```
**描述:**
获取曲目描述。

**返回:**

返回曲目描述。

**参见:**

[SetDescription](#setdescription)


### GetDuration()

  
```
int64_t OHOS::AVSession::AVMetaData::GetDuration () const
```
**描述:**
获取媒体时长。

**返回:**

返回媒体时长，单位为ms。

**参见:**

[SetDuration](#setduration)


### GetLyric()

  
```
std::string OHOS::AVSession::AVMetaData::GetLyric () const
```
**描述:**
获取歌词。

**返回:**

返回歌词。

**参见:**

[SetLyric](#setlyric)


### GetMediaImage()

  
```
std::shared_ptr<AVSessionPixelMap> OHOS::AVSession::AVMetaData::GetMediaImage () const
```
**描述:**
获取媒体图片。

**返回:**

返回媒体图片[AVSessionPixelMap](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_pixel_map.md)。

**参见:**

[SetMediaImage](#setmediaimage)


### GetMediaImageUri()

  
```
std::string OHOS::AVSession::AVMetaData::GetMediaImageUri () const
```
**描述:**
获取媒体图片URI。

**返回:**

返回媒体图片URI。

**参见:**

[SetMediaImageUri](#setmediaimageuri)


### GetMetaMask()

  
```
MetaMaskType OHOS::AVSession::AVMetaData::GetMetaMask () const
```
**描述:**
获取掩码。

**返回:**

返回掩码[MetaMaskType](#metamasktype)。


### GetNextAssetId()

  
```
std::string OHOS::AVSession::AVMetaData::GetNextAssetId () const
```
**描述:**
获取下一曲曲目ID。

**返回:**

返回下一曲曲目ID。

**参见:**

[SetNextAssetId](#setnextassetid)


### GetPreviousAssetId()

  
```
std::string OHOS::AVSession::AVMetaData::GetPreviousAssetId () const
```
**描述:**
获取上一曲曲目ID。

**返回:**

返回上一曲曲目ID。

**参见:**

[SetPreviousAssetId](#setpreviousassetid)


### GetPublishDate()

  
```
double OHOS::AVSession::AVMetaData::GetPublishDate () const
```
**描述:**
获取曲目发布日期，时间戳，单位为ms。

**返回:**

返回曲目发布日期，时间戳，单位为ms。

**参见:**

[SetPublishDate](#setpublishdate)


### GetSubTitle()

  
```
std::string OHOS::AVSession::AVMetaData::GetSubTitle () const
```
**描述:**
获取子标题。

**返回:**

返回子标题。

**参见:**

[SetSubTitle](#setsubtitle)


### GetTitle()

  
```
std::string OHOS::AVSession::AVMetaData::GetTitle () const
```
**描述:**
获取标题。

**返回:**

返回标题。

**参见:**

[SetTitle](#settitle)


### GetWriter()

  
```
std::string OHOS::AVSession::AVMetaData::GetWriter () const
```
**描述:**
获取作词名称。

**返回:**

返回作词名称。

**参见:**

[SetWriter](#setwriter)


### IsValid()

  
```
bool OHOS::AVSession::AVMetaData::IsValid () const
```
**描述:**
会话元数据有效性判断。

**返回:**

有效返回true；无效则返回false。


### Marshalling()

  
```
bool OHOS::AVSession::AVMetaData::Marshalling (Parcel & data) const
```
**描述:**
实现会话元数据进程间传递的序列化。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| data | 保存序列化值的对象**Parcel**。  | 

**返回:**

如果序列化成功，则返回true；如果操作失败，则返回false。

**参见:**

[Unmarshalling](#unmarshalling)


### Reset()

  
```
void OHOS::AVSession::AVMetaData::Reset ()
```
**描述:**
重置所有会话元数据项。


### SetAlbum()

  
```
void OHOS::AVSession::AVMetaData::SetAlbum (const std::string & album)
```
**描述:**
设置专辑名称。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| album | 专辑名称。  | 

**参见:**

[GetAlbum](#getalbum)


### SetArtist()

  
```
void OHOS::AVSession::AVMetaData::SetArtist (const std::string & artist)
```
**描述:**
设置艺术家名称。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| artist | 艺术家名称。  | 

**参见:**

[GetArtist](#getartist)


### SetAssetId()

  
```
void OHOS::AVSession::AVMetaData::SetAssetId (const std::string & assetId)
```
**描述:**
设置曲目ID。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| assetId | 曲目ID,不可为空。  | 

**参见:**

[GetAssetId](#getassetid)


### SetAuthor()

  
```
void OHOS::AVSession::AVMetaData::SetAuthor (const std::string & author)
```
**描述:**
设置制作人名称。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| author | 制作人名称。  | 

**参见:**

[GetArtist](#getartist)


### SetComposer()

  
```
void OHOS::AVSession::AVMetaData::SetComposer (const std::string & composer)
```
**描述:**
设置作曲名称。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| composer | 作曲名称。  | 

**参见:**

[GetComposer](#getcomposer)


### SetDescription()

  
```
void OHOS::AVSession::AVMetaData::SetDescription (const std::string & description)
```
**描述:**
设置曲目描述。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| description | 曲目描述。  | 

**参见:**

[GetDescription](#getdescription)


### SetDuration()

  
```
void OHOS::AVSession::AVMetaData::SetDuration (int64_t duration)
```
**描述:**
设置媒体时长。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| duration | 媒体时长，必须大于等于-1，单位为ms 。  | 

**参见:**

[GetDuration](#getduration)


### SetLyric()

  
```
void OHOS::AVSession::AVMetaData::SetLyric (const std::string & lyric)
```
**描述:**
设置歌词。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| lyric | 歌词。  | 

**参见:**

[GetLyric](#getlyric)


### SetMediaImage()

  
```
void OHOS::AVSession::AVMetaData::SetMediaImage (const std::shared_ptr< AVSessionPixelMap > & mediaImage)
```
**描述:**
设置媒体图片。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mediaImage | 媒体图片[AVSessionPixelMap](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_pixel_map.md)。  | 

**参见:**

[GetMediaImage](#getmediaimage)


### SetMediaImageUri()

  
```
void OHOS::AVSession::AVMetaData::SetMediaImageUri (const std::string & mediaImageUri)
```
**描述:**
设置媒体图片URI。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mediaImageUri | 媒体图片URI。  | 

**参见:**

[GetMediaImageUri](#getmediaimageuri)


### SetNextAssetId()

  
```
void OHOS::AVSession::AVMetaData::SetNextAssetId (const std::string & assetId)
```
**描述:**
设置下一曲曲目ID。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| assetId | 下一曲曲目ID。  | 

**参见:**

[GetNextAssetId](#getnextassetid)


### SetPreviousAssetId()

  
```
void OHOS::AVSession::AVMetaData::SetPreviousAssetId (const std::string & assetId)
```
**描述:**
设置上一曲曲目ID。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| assetId | 上一曲曲目ID。  | 

**参见:**

[GetPreviousAssetId](#getpreviousassetid)


### SetPublishDate()

  
```
void OHOS::AVSession::AVMetaData::SetPublishDate (double date)
```
**描述:**
设置曲目发布日期，时间戳，单位为ms。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| date | 曲目发布日期，时间戳，单位为ms。  | 

**参见:**

[GetPublishDate](#getpublishdate)


### SetSubTitle()

  
```
void OHOS::AVSession::AVMetaData::SetSubTitle (const std::string & subTitle)
```
**描述:**
设置子标题。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| subTitle | 子标题。  | 

**参见:**

[GetSubTitle](#getsubtitle)


### SetTitle()

  
```
void OHOS::AVSession::AVMetaData::SetTitle (const std::string & title)
```
**描述:**
设置标题。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| title | 标题。  | 

**参见:**

[GetTitle](#gettitle)


### SetWriter()

  
```
void OHOS::AVSession::AVMetaData::SetWriter (const std::string & writer)
```
**描述:**
设置作词名称。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| writer | 作词名称。  | 

**参见:**

[GetWriter](#getwriter)


### Unmarshalling()

  
```
static AVMetaData* OHOS::AVSession::AVMetaData::Unmarshalling (Parcel & data)
```
**描述:**
实现会话元数据进程间传递的反序列化。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| data | 序列化对象**Parcel**。  | 

**返回:**

如果反序列化成功，返回AVMetaData类型指针；失败则返回nullptr。

**参见:**

[Marshalling](#marshalling)


## 结构体成员变量说明


### DURATION_ALWAYS_PLAY

  
```
constexpr std::int64_t OHOS::AVSession::AVMetaData::DURATION_ALWAYS_PLAY = -1
```
**描述:**
持续时间全局变量宏定义。


### localCapability

  
```
const std::vector<int32_t> OHOS::AVSession::AVMetaData::localCapability
```
**Value:**
  
```
{
 META_KEY_ASSET_ID,
 META_KEY_TITLE,
 META_KEY_ARTIST,
 META_KEY_AUTHOR,
 META_KEY_ALBUM,
 META_KEY_WRITER,
 META_KEY_COMPOSER,
 META_KEY_DURATION,
 META_KEY_MEDIA_IMAGE,
 META_KEY_MEDIA_IMAGE_URI,
 META_KEY_PUBLISH_DATE,
 META_KEY_SUBTITLE,
 META_KEY_DESCRIPTION,
 META_KEY_LYRIC,
 META_KEY_PREVIOUS_ASSET_ID,
 META_KEY_NEXT_ASSET_ID,
 }
```
**描述:**
会话元数据数组，用于分布式业务，设置会话属性。
