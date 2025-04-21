# native_cencinfo.h


## 概述

声明用于设置解密参数的Native API。

**库：** libnative_media_avcencinfo.so

**起始版本：** 12

**相关模块：**[Multimedia_Drm](_multimedia___drm.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [DrmSubsample](_drm_subsample.md) | Subsample结构类型定义。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_KEY_ID_SIZE](_multimedia___drm.md#drm_key_id_size)   16 | Key id长度为16字节。 | 
| [DRM_KEY_IV_SIZE](_multimedia___drm.md#drm_key_iv_size)   16 | Iv长度为16字节。 | 
| [DRM_KEY_MAX_SUB_SAMPLE_NUM](_multimedia___drm.md#drm_key_max_sub_sample_num)   64 | 最大的Subsample数量为64个。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVBuffer](_multimedia___drm.md#oh_avbuffer) [OH_AVBuffer](_multimedia___drm.md#oh_avbuffer) | AVBuffer结构。 | 
| typedef struct [OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) [OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) | AVCencInfo结构。 | 
| typedef enum [DrmCencAlgorithm](_multimedia___drm.md#drmcencalgorithm) [DrmCencAlgorithm](_multimedia___drm.md#drmcencalgorithm) | Drm CENC算法类型。 | 
| typedef enum [DrmCencInfoMode](_multimedia___drm.md#drmcencinfomode) [DrmCencInfoMode](_multimedia___drm.md#drmcencinfomode) | 枚举类型，表示cencInfo中keyId/iv/subsample信息是否设置。 | 
| typedef struct [DrmSubsample](_drm_subsample.md) [DrmSubsample](_multimedia___drm.md#drmsubsample) | Subsample结构类型定义。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DrmCencAlgorithm](_multimedia___drm.md#drmcencalgorithm) {<br/>DRM_ALG_CENC_UNENCRYPTED = 0x0, DRM_ALG_CENC_AES_CTR = 0x1,<br/>DRM_ALG_CENC_AES_WV = 0x2, DRM_ALG_CENC_AES_CBC = 0x3,<br/>DRM_ALG_CENC_SM4_CBC = 0x4, DRM_ALG_CENC_SM4_CTR = 0x5<br/>} | Drm CENC算法类型。 | 
| [DrmCencInfoMode](_multimedia___drm.md#drmcencinfomode) {<br/>DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET = 0x0,<br/>DRM_CENC_INFO_KEY_IV_SUBSAMPLES_NOT_SET = 0x1 } | 枚举类型，表示cencInfo中keyId/iv/subsample信息是否设置。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \* [OH_AVCencInfo_Create](_multimedia___drm.md#oh_avcencinfo_create) () | 创建用于设置cencInfo的OH_AVCencInfo实例。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_Destroy](_multimedia___drm.md#oh_avcencinfo_destroy) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo) | 销毁OH_AVCencInfo实例并释放内部资源。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetAlgorithm](_multimedia___drm.md#oh_avcencinfo_setalgorithm) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, enum [DrmCencAlgorithm](_multimedia___drm.md#drmcencalgorithm) algo) | 设置cencInfo加密算法。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetKeyIdAndIv](_multimedia___drm.md#oh_avcencinfo_setkeyidandiv) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, uint8_t \*keyId, uint32_t keyIdLen, uint8_t \*iv, uint32_t ivLen) | 设置cencInfo的keyId和iv。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetSubsampleInfo](_multimedia___drm.md#oh_avcencinfo_setsubsampleinfo) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, uint32_t encryptedBlockCount, uint32_t skippedBlockCount, uint32_t firstEncryptedOffset, uint32_t subsampleCount, [DrmSubsample](_drm_subsample.md) \*subsamples) | 设置cencInfo的subsamples信息。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetMode](_multimedia___drm.md#oh_avcencinfo_setmode) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, enum [DrmCencInfoMode](_multimedia___drm.md#drmcencinfomode) mode) | 设置cencInfo的模式。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetAVBuffer](_multimedia___drm.md#oh_avcencinfo_setavbuffer) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, [OH_AVBuffer](_multimedia___drm.md#oh_avbuffer) \*buffer) | 将cencInfo设置到AVBuffer。 | 
