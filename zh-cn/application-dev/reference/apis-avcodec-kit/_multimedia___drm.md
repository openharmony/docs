# Multimedia_Drm


## 概述

三方应用自行实现媒体解封装，可使用本模块提供的接口设置解密参数， 且当DRM实例和会话创建完成后，以实现DRM加密节目的解密功能。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_cencinfo.h](native__cencinfo_8h.md) | 声明用于设置解密参数的Native API。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [DrmSubsample](_drm_subsample.md) | Subsample结构类型定义。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_KEY_ID_SIZE](#drm_key_id_size)   16 | Key id长度为16字节。 | 
| [DRM_KEY_IV_SIZE](#drm_key_iv_size)   16 | Iv长度为16字节。 | 
| [DRM_KEY_MAX_SUB_SAMPLE_NUM](#drm_key_max_sub_sample_num)   64 | 最大的Subsample数量为64个。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVBuffer](#oh_avbuffer) [OH_AVBuffer](#oh_avbuffer) | AVBuffer结构。 | 
| typedef struct [OH_AVCencInfo](#oh_avcencinfo) [OH_AVCencInfo](#oh_avcencinfo) | AVCencInfo结构。 | 
| typedef enum [DrmCencAlgorithm](#drmcencalgorithm) [DrmCencAlgorithm](#drmcencalgorithm) | Drm CENC算法类型。 | 
| typedef enum [DrmCencInfoMode](#drmcencinfomode) [DrmCencInfoMode](#drmcencinfomode) | 枚举类型，表示cencInfo中keyId/iv/subsample信息是否设置。 | 
| typedef struct [DrmSubsample](_drm_subsample.md) [DrmSubsample](#drmsubsample) | Subsample结构类型定义。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DrmCencAlgorithm](#drmcencalgorithm) {<br/>DRM_ALG_CENC_UNENCRYPTED = 0x0, DRM_ALG_CENC_AES_CTR = 0x1,<br/>DRM_ALG_CENC_AES_WV = 0x2, DRM_ALG_CENC_AES_CBC = 0x3,<br/>DRM_ALG_CENC_SM4_CBC = 0x4, DRM_ALG_CENC_SM4_CTR = 0x5<br/>} | Drm CENC算法类型。 | 
| [DrmCencInfoMode](#drmcencinfomode) {<br/>DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET = 0x0,<br/>DRM_CENC_INFO_KEY_IV_SUBSAMPLES_NOT_SET = 0x1 } | 枚举类型，表示cencInfo中keyId/iv/subsample信息是否设置。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCencInfo](#oh_avcencinfo) \* [OH_AVCencInfo_Create](#oh_avcencinfo_create) () | 创建用于设置cencInfo的OH_AVCencInfo实例。 | 
| OH_AVErrCode [OH_AVCencInfo_Destroy](#oh_avcencinfo_destroy) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo) | 销毁OH_AVCencInfo实例并释放内部资源。 | 
| OH_AVErrCode [OH_AVCencInfo_SetAlgorithm](#oh_avcencinfo_setalgorithm) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, enum [DrmCencAlgorithm](#drmcencalgorithm) algo) | 设置cencInfo加密算法。 | 
| OH_AVErrCode [OH_AVCencInfo_SetKeyIdAndIv](#oh_avcencinfo_setkeyidandiv) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, uint8_t \*keyId, uint32_t keyIdLen, uint8_t \*iv, uint32_t ivLen) | 设置cencInfo的keyId和iv。 | 
| OH_AVErrCode [OH_AVCencInfo_SetSubsampleInfo](#oh_avcencinfo_setsubsampleinfo) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, uint32_t encryptedBlockCount, uint32_t skippedBlockCount, uint32_t firstEncryptedOffset, uint32_t subsampleCount, [DrmSubsample](_drm_subsample.md) \*subsamples) | 设置cencInfo的subsamples信息。 | 
| OH_AVErrCode [OH_AVCencInfo_SetMode](#oh_avcencinfo_setmode) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, enum [DrmCencInfoMode](#drmcencinfomode) mode) | 设置cencInfo的模式。 | 
| OH_AVErrCode [OH_AVCencInfo_SetAVBuffer](#oh_avcencinfo_setavbuffer) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, [OH_AVBuffer](#oh_avbuffer) \*buffer) | 将cencInfo设置到AVBuffer。 | 


## 宏定义说明


### DRM_KEY_ID_SIZE

```
#define DRM_KEY_ID_SIZE   16
```

**描述**

Key id长度为16字节。

**起始版本：** 12


### DRM_KEY_IV_SIZE

```
#define DRM_KEY_IV_SIZE   16
```

**描述**

Iv长度为16字节。

**起始版本：** 12


### DRM_KEY_MAX_SUB_SAMPLE_NUM

```
#define DRM_KEY_MAX_SUB_SAMPLE_NUM   64
```

**描述**

最大的Subsample数量为64个。

**起始版本：** 12


## 类型定义说明


### DrmCencAlgorithm

```
typedef enum DrmCencAlgorithm DrmCencAlgorithm
```

**描述**

Drm CENC算法类型。

**起始版本：** 12


### DrmCencInfoMode

```
typedef enum DrmCencInfoMode DrmCencInfoMode
```

**描述**

枚举类型，表示cencInfo中keyId/iv/subsample信息是否设置。

**起始版本：** 12


### DrmSubsample

```
typedef struct DrmSubsample DrmSubsample
```

**描述**

Subsample结构类型定义。

**起始版本：** 12


### OH_AVBuffer

```
typedef struct OH_AVBuffer OH_AVBuffer
```

**描述**

AVBuffer结构。

**起始版本：** 12


### OH_AVCencInfo

```
typedef struct OH_AVCencInfo OH_AVCencInfo
```

**描述**

AVCencInfo结构。

**起始版本：** 12


## 枚举类型说明


### DrmCencAlgorithm

```
enum DrmCencAlgorithm
```

**描述**

Drm CENC算法类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DRM_ALG_CENC_UNENCRYPTED | 不加密算法。 | 
| DRM_ALG_CENC_AES_CTR | AES CTR算法。 | 
| DRM_ALG_CENC_AES_WV | AES WV算法。 | 
| DRM_ALG_CENC_AES_CBC | AES CBC算法。 | 
| DRM_ALG_CENC_SM4_CBC | SM4 CBC算法。 | 
| DRM_ALG_CENC_SM4_CTR | SM4 CTR算法。 | 


### DrmCencInfoMode

```
enum DrmCencInfoMode
```

**描述**

枚举类型，表示cencInfo中keyId/iv/subsample信息是否设置。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET | keyId/iv/subsample信息已设置。 | 
| DRM_CENC_INFO_KEY_IV_SUBSAMPLES_NOT_SET | keyId/iv/subsample信息未设置。 | 


## 函数说明


### OH_AVCencInfo_Create()

```
OH_AVCencInfo* OH_AVCencInfo_Create ()
```

**描述**

创建用于设置cencInfo的OH_AVCencInfo实例。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

**返回：**

返回新创建的OH_AVCencInfo对象。如果返回nullptr，则表示创建对象失败。

可能失败的原因：应用程序地址空间已满，或者对象中的数据初始化失败。


### OH_AVCencInfo_Destroy()

```
OH_AVErrCode OH_AVCencInfo_Destroy (OH_AVCencInfo * cencInfo)
```

**描述**

销毁OH_AVCencInfo实例并释放内部资源。

同一个实例只能销毁一次。在再次创建实例之前，不应使用该实例。 建议在实例销毁成功后立即将实例指针设置为nullptr。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cencInfo | 指向OH_AVCencInfo实例的指针。 | 

**返回：**

参考[OH_AVErrCode](_core.md#oh_averrcode):

**AV_ERR_OK** 0 - 执行成功。 

**AV_ERR_INVALID_VAL** 3 - cencInfo为空。


### OH_AVCencInfo_SetAlgorithm()

```
OH_AVErrCode OH_AVCencInfo_SetAlgorithm (OH_AVCencInfo * cencInfo, enum DrmCencAlgorithm algo )
```

**描述**

设置cencInfo加密算法。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cencInfo | 指向OH_AVCencInfo实例的指针。 | 
| algo | 加密算法模式。 | 

**返回：**

参考[OH_AVErrCode](_core.md#oh_averrcode):

**AV_ERR_OK** 0 - 执行成功。 

**AV_ERR_INVALID_VAL** 3 - cencInfo为空。


### OH_AVCencInfo_SetAVBuffer()

```
OH_AVErrCode OH_AVCencInfo_SetAVBuffer (OH_AVCencInfo * cencInfo, OH_AVBuffer * buffer )
```

**描述**

将cencInfo设置到AVBuffer。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cencInfo | 指向OH_AVCencInfo实例的指针。 | 
| buffer | 携带数据的帧buffer。 | 

**返回：**

参考[OH_AVErrCode](_core.md#oh_averrcode):

**AV_ERR_OK** 0 - 执行成功。 

**AV_ERR_INVALID_VAL** 3 - 如果cencInfo为空，或者buffer为空， 或者buffer-&gt;buffer_为空，或者buffer-&gt;buffer_-&gt;meta_为空，则返回此错误码。


### OH_AVCencInfo_SetKeyIdAndIv()

```
OH_AVErrCode OH_AVCencInfo_SetKeyIdAndIv (OH_AVCencInfo * cencInfo, uint8_t * keyId, uint32_t keyIdLen, uint8_t * iv, uint32_t ivLen )
```

**描述**

设置cencInfo的keyId和iv。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cencInfo | 指向OH_AVCencInfo实例的指针。 | 
| keyId | Key标识。 | 
| keyIdLen | Key标识长度。 | 
| iv | 初始化向量。 | 
| ivLen | 初始化向量长度。 | 

**返回：**

参考[OH_AVErrCode](_core.md#oh_averrcode):

**AV_ERR_OK** 0 - 执行成功。 

**AV_ERR_INVALID_VAL** 3 - 如果cencInfo为空，或者keyId为空，或者keyIdLen != DRM_KEY_ID_SIZE，或者iv是空，或者ivLen != DRM_KEY_IV_SIZE，或者keyId拷贝失败，或者iv拷贝失败，则返回此错误码。


### OH_AVCencInfo_SetMode()

```
OH_AVErrCode OH_AVCencInfo_SetMode (OH_AVCencInfo * cencInfo, enum DrmCencInfoMode mode )
```

**描述**

设置cencInfo的模式。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cencInfo | 指向OH_AVCencInfo实例的指针。 | 
| mode | cencInfo模式，指示是否设置了keyId/iv/subsample。 | 

**返回：**

参考[OH_AVErrCode](_core.md#oh_averrcode):

**AV_ERR_OK** 0 - 执行成功。 

**AV_ERR_INVALID_VAL** 3 - cencInfo为空。


### OH_AVCencInfo_SetSubsampleInfo()

```
OH_AVErrCode OH_AVCencInfo_SetSubsampleInfo (OH_AVCencInfo * cencInfo, uint32_t encryptedBlockCount, uint32_t skippedBlockCount, uint32_t firstEncryptedOffset, uint32_t subsampleCount, DrmSubsample * subsamples )
```

**描述**

设置cencInfo的subsamples信息。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cencInfo | 指向OH_AVCencInfo实例的指针。 | 
| encryptedBlockCount | 加密块的数量。 | 
| skippedBlockCount | 不加密块的数量。 | 
| firstEncryptedOffset | 第一个加密有效负载的偏移量。 | 
| subsampleCount | Subsample数量。 | 
| subsamples | Subsample内容集。 | 

**返回：**

参考[OH_AVErrCode](_core.md#oh_averrcode):

**AV_ERR_OK** 0 - 执行成功。 

**AV_ERR_INVALID_VAL** 3 - 如果cencInfo为空， 或者subsampleCount &gt; DRM_KEY_MAX_SUB_SAMPLE_NUM，或者subsamples为空， 则返回此错误码。
