# OHOS::AVSession::AVMetaData


## 概述

会话元数据类，提供获取metadata进程间传递的序列化和反序列话及数据拷贝的接口方法。


## 汇总


### Public 类型

  | 名称 | 描述 | 
| -------- | -------- |
| {<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref2118602748182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28ae99d5364d7a646080ede50f15b3c2724](#a7a1596eae23e0cf8ab02d02de37dea28ae99d5364d7a646080ede50f15b3c2724)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref1712783448182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a189fb78288cd6a3afbd81a88ed721b26](#a7a1596eae23e0cf8ab02d02de37dea28a189fb78288cd6a3afbd81a88ed721b26)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref195676889182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a0d56221d2b6d0230a8441b569ec79423](#a7a1596eae23e0cf8ab02d02de37dea28a0d56221d2b6d0230a8441b569ec79423)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref693195284182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a0f71f86527ce21d97666c33cac459a29](#a7a1596eae23e0cf8ab02d02de37dea28a0f71f86527ce21d97666c33cac459a29)&nbsp;=&nbsp;3,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref1603000664182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28af3b9104ec669ce3a252969fda137756e](#a7a1596eae23e0cf8ab02d02de37dea28af3b9104ec669ce3a252969fda137756e)&nbsp;=&nbsp;4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref740488576182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28adb25084cc3ccdfc1c0ccd5202c010b88](#a7a1596eae23e0cf8ab02d02de37dea28adb25084cc3ccdfc1c0ccd5202c010b88)&nbsp;=&nbsp;5,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref377729915182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a6ada4246477004d1f8c1c22805448f57](#a7a1596eae23e0cf8ab02d02de37dea28a6ada4246477004d1f8c1c22805448f57)&nbsp;=&nbsp;6,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref1579556667182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a6c87155e22476332c3afca2e362b6499](#a7a1596eae23e0cf8ab02d02de37dea28a6c87155e22476332c3afca2e362b6499)&nbsp;=&nbsp;7,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref952040068182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a573988a41fdc15138125de9e699b4410](#a7a1596eae23e0cf8ab02d02de37dea28a573988a41fdc15138125de9e699b4410)&nbsp;=&nbsp;8,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref1699648636182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28ae73aa81af3bd31e8af78edae31d14f69](#a7a1596eae23e0cf8ab02d02de37dea28ae73aa81af3bd31e8af78edae31d14f69)&nbsp;=&nbsp;9,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref210405995182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28af1063b65c0120e1e14298f16f8f48eb8](#a7a1596eae23e0cf8ab02d02de37dea28af1063b65c0120e1e14298f16f8f48eb8)&nbsp;=&nbsp;10,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref1304520289182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a87dff8b9a7fc5629047a6c49aa7ad075](#a7a1596eae23e0cf8ab02d02de37dea28a87dff8b9a7fc5629047a6c49aa7ad075)&nbsp;=&nbsp;11,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref1353365541182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a0e4b4d1fbe3f96f5875fc8a3db63665a](#a7a1596eae23e0cf8ab02d02de37dea28a0e4b4d1fbe3f96f5875fc8a3db63665a)&nbsp;=&nbsp;12,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref1860277742182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a22d6767a149cadb9f8adfcc2e7e883e0](#a7a1596eae23e0cf8ab02d02de37dea28a22d6767a149cadb9f8adfcc2e7e883e0)&nbsp;=&nbsp;13,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref1487235666182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28a3e66bd6d568e6d563ab64385d96f7b33](#a7a1596eae23e0cf8ab02d02de37dea28a3e66bd6d568e6d563ab64385d96f7b33)&nbsp;=&nbsp;14,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref919001485182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28aa8b557fe3184b235c6b76cfdee285253](#a7a1596eae23e0cf8ab02d02de37dea28aa8b557fe3184b235c6b76cfdee285253)&nbsp;=&nbsp;15,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref406831288182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28ad1907479ca45af05709d1b813cf1b59a](#a7a1596eae23e0cf8ab02d02de37dea28ad1907479ca45af05709d1b813cf1b59a)&nbsp;=&nbsp;16<br/>} | 会话元数据具体枚举项。&nbsp; | 
| [MetaMaskType](#metamasktype)&nbsp;=&nbsp;std::bitset&lt;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref871960788182348,link:zh-cn_topic_0000001423615938.xml#a7a1596eae23e0cf8ab02d02de37dea28ad1907479ca45af05709d1b813cf1b59a](#a7a1596eae23e0cf8ab02d02de37dea28ad1907479ca45af05709d1b813cf1b59a)&nbsp;&gt; | 引入掩码标记需要拷贝的会话元数据。&nbsp; | 


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [AVMetaData](#avmetadata)&nbsp;()=default | 会话元数据默认构造函数。&nbsp; | 
| [~AVMetaData](#avmetadata)&nbsp;()&nbsp;override | 会话元数据默认析构函数。&nbsp; | 
| [Marshalling](#marshalling)&nbsp;(Parcel&nbsp;&amp;data)&nbsp;const&nbsp;override | 实现会话元数据进程间传递的序列化。&nbsp; | 
| [SetAssetId](#setassetid)&nbsp;(const&nbsp;std::string&nbsp;&amp;assetId) | 设置曲目ID。&nbsp; | 
| [GetAssetId](#getassetid)&nbsp;()&nbsp;const | 获取曲目ID。&nbsp; | 
| [SetTitle](#settitle)&nbsp;(const&nbsp;std::string&nbsp;&amp;title) | 设置标题。&nbsp; | 
| [GetTitle](#gettitle)&nbsp;()&nbsp;const | 获取标题。&nbsp; | 
| [SetArtist](#setartist)&nbsp;(const&nbsp;std::string&nbsp;&amp;artist) | 设置艺术家名称。&nbsp; | 
| [GetArtist](#getartist)&nbsp;()&nbsp;const | 获取艺术家名称。&nbsp; | 
| [SetAuthor](#setauthor)&nbsp;(const&nbsp;std::string&nbsp;&amp;author) | 设置制作人名称。&nbsp; | 
| [GetAuthor](#getauthor)&nbsp;()&nbsp;const | 获取制作人名称。&nbsp; | 
| [SetAlbum](#setalbum)&nbsp;(const&nbsp;std::string&nbsp;&amp;album) | 设置专辑名称。&nbsp; | 
| [GetAlbum](#getalbum)&nbsp;()&nbsp;const | 获取专辑名称。&nbsp; | 
| [SetWriter](#setwriter)&nbsp;(const&nbsp;std::string&nbsp;&amp;writer) | 设置作词名称。&nbsp; | 
| [GetWriter](#getwriter)&nbsp;()&nbsp;const | 获取作词名称。&nbsp; | 
| [SetComposer](#setcomposer)&nbsp;(const&nbsp;std::string&nbsp;&amp;composer) | 设置作曲名称。&nbsp; | 
| [GetComposer](#getcomposer)&nbsp;()&nbsp;const | 获取作曲名称。&nbsp; | 
| [SetDuration](#setduration)&nbsp;(int64_t&nbsp;duration) | 设置媒体时长。&nbsp; | 
| [GetDuration](#getduration)&nbsp;()&nbsp;const | 获取媒体时长。&nbsp; | 
| [SetMediaImage](#setmediaimage)&nbsp;(const&nbsp;std::shared_ptr&lt;&nbsp;[AVSessionPixelMap](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_pixel_map.md)&nbsp;&gt;&nbsp;&amp;mediaImage) | 设置媒体图片。&nbsp; | 
| [GetMediaImage](#getmediaimage)&nbsp;()&nbsp;const | 获取媒体图片。&nbsp; | 
| [SetMediaImageUri](#setmediaimageuri)&nbsp;(const&nbsp;std::string&nbsp;&amp;mediaImageUri) | 设置媒体图片URI。&nbsp; | 
| [GetMediaImageUri](#getmediaimageuri)&nbsp;()&nbsp;const | 获取媒体图片URI。&nbsp; | 
| [SetPublishDate](#setpublishdate)&nbsp;(double&nbsp;date) | 设置曲目发布日期，时间戳，单位为ms。&nbsp; | 
| [GetPublishDate](#getpublishdate)&nbsp;()&nbsp;const | 获取曲目发布日期，时间戳，单位为ms。&nbsp; | 
| [SetSubTitle](#setsubtitle)&nbsp;(const&nbsp;std::string&nbsp;&amp;subTitle) | 设置子标题。&nbsp; | 
| [GetSubTitle](#getsubtitle)&nbsp;()&nbsp;const | 获取子标题。&nbsp; | 
| [SetDescription](#setdescription)&nbsp;(const&nbsp;std::string&nbsp;&amp;description) | 设置曲目描述。&nbsp; | 
| [GetDescription](#getdescription)&nbsp;()&nbsp;const | 获取曲目描述。&nbsp; | 
| [SetLyric](#setlyric)&nbsp;(const&nbsp;std::string&nbsp;&amp;lyric) | 设置歌词。&nbsp; | 
| [GetLyric](#getlyric)&nbsp;()&nbsp;const | 获取歌词。&nbsp; | 
| [SetPreviousAssetId](#setpreviousassetid)&nbsp;(const&nbsp;std::string&nbsp;&amp;assetId) | 设置上一曲曲目ID。&nbsp; | 
| [GetPreviousAssetId](#getpreviousassetid)&nbsp;()&nbsp;const | 获取上一曲曲目ID。&nbsp; | 
| [SetNextAssetId](#setnextassetid)&nbsp;(const&nbsp;std::string&nbsp;&amp;assetId) | 设置下一曲曲目ID。&nbsp; | 
| [GetNextAssetId](#getnextassetid)&nbsp;()&nbsp;const | 获取下一曲曲目ID。&nbsp; | 
| [Reset](#reset)&nbsp;() | 重置所有会话元数据项。&nbsp; | 
| [GetMetaMask](#getmetamask)&nbsp;()&nbsp;const | 获取掩码。&nbsp; | 
| [CopyToByMask](#copytobymask)&nbsp;([MetaMaskType](#metamasktype)&nbsp;&amp;mask,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref2143206164182348,link:zh-cn_topic_0000001423615938.xml](zh-cn_topic_0000001423615938.xml)&nbsp;&amp;metaOut)&nbsp;const | 根据metadata掩码,将metadata项复制到metaOut。&nbsp; | 
| [CopyFrom](#copyfrom)&nbsp;(const&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref1637590024182348,link:zh-cn_topic_0000001423615938.xml](zh-cn_topic_0000001423615938.xml)&nbsp;&amp;metaIn) | 根据metaIn元掩码的设置位从metaIn复制metadata项。&nbsp; | 
| [IsValid](#isvalid)&nbsp;()&nbsp;const | 会话元数据有效性判断。&nbsp; | 


### 静态 Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Unmarshalling](#unmarshalling)&nbsp;(Parcel&nbsp;&amp;data) | 实现会话元数据进程间传递的反序列化。&nbsp; | 


### 静态 Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [DURATION_ALWAYS_PLAY](#durationalwaysplay)&nbsp;=&nbsp;-1 | 持续时间全局变量宏定义。&nbsp; | 
| [localCapability](#localcapability) | 会话元数据数组，用于分布式业务，设置会话属性。&nbsp; | 


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
| META_KEY_ASSET_ID&nbsp; | 曲目ID | 
| META_KEY_TITLE&nbsp; | 标题 | 
| META_KEY_ARTIST&nbsp; | 艺术家 | 
| META_KEY_AUTHOR&nbsp; | 制作人 | 
| META_KEY_ALBUM&nbsp; | 专辑 | 
| META_KEY_WRITER&nbsp; | 作词 | 
| META_KEY_COMPOSER&nbsp; | 作曲 | 
| META_KEY_DURATION&nbsp; | 媒体时长 | 
| META_KEY_MEDIA_IMAGE&nbsp; | 媒体影像 | 
| META_KEY_MEDIA_IMAGE_URI&nbsp; | 媒体影像路径 | 
| META_KEY_PUBLISH_DATE&nbsp; | 曲目发布日期 | 
| META_KEY_SUBTITLE&nbsp; | 子标题 | 
| META_KEY_DESCRIPTION&nbsp; | 曲目描述 | 
| META_KEY_LYRIC&nbsp; | 歌词 | 
| META_KEY_PREVIOUS_ASSET_ID&nbsp; | 上一曲 | 
| META_KEY_NEXT_ASSET_ID&nbsp; | 下一曲 | 
| META_KEY_MAX&nbsp; | 无效指令，内部用来判断会话元数据是否有效 | 


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
| metaIn：会话元数据将要拷贝的入参{ |  | 


### CopyToByMask()

  
```
bool OHOS::AVSession::AVMetaData::CopyToByMask (MetaMaskType & mask, AVMetaData & metaOut ) const
```
**描述:**
根据metadata掩码,将metadata项复制到metaOut。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mask | metadata掩码[MetaMaskType](#metamasktype)。&nbsp; | 
| metaOut | metadata已拷贝成功的出参[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423615938.xml#xref2069636235182348,link:zh-cn_topic_0000001423615938.xml](zh-cn_topic_0000001423615938.xml)。&nbsp; | 

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
| data | 保存序列化值的对象**Parcel**。&nbsp; | 

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
| album | 专辑名称。&nbsp; | 

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
| artist | 艺术家名称。&nbsp; | 

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
| assetId | 曲目ID,不可为空。&nbsp; | 

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
| author | 制作人名称。&nbsp; | 

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
| composer | 作曲名称。&nbsp; | 

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
| description | 曲目描述。&nbsp; | 

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
| duration | 媒体时长，必须大于等于-1，单位为ms&nbsp;。&nbsp; | 

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
| lyric | 歌词。&nbsp; | 

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
| mediaImage | 媒体图片[AVSessionPixelMap](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_pixel_map.md)。&nbsp; | 

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
| mediaImageUri | 媒体图片URI。&nbsp; | 

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
| assetId | 下一曲曲目ID。&nbsp; | 

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
| assetId | 上一曲曲目ID。&nbsp; | 

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
| date | 曲目发布日期，时间戳，单位为ms。&nbsp; | 

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
| subTitle | 子标题。&nbsp; | 

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
| title | 标题。&nbsp; | 

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
| writer | 作词名称。&nbsp; | 

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
| data | 序列化对象**Parcel**。&nbsp; | 

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
