# native_cencinfo.h


## Overview

The **native_cencinfo.h** file declares the native APIs used to set decryption parameters.

**Library**: libnative_media_avcencinfo.so

**Since**: 12

**Related module**: [Multimedia_Drm](_multimedia___drm.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [DrmSubsample](_drm_subsample.md) | Describes the subsample type.| 


### Macros

| Name| Description| 
| -------- | -------- |
| [DRM_KEY_ID_SIZE](_multimedia___drm.md#drm_key_id_size)   16 | The length of the key ID is 16 bytes.| 
| [DRM_KEY_IV_SIZE](_multimedia___drm.md#drm_key_iv_size)   16 | The length of the Initialization Vector (IV) is 16 bytes.| 
| [DRM_KEY_MAX_SUB_SAMPLE_NUM](_multimedia___drm.md#drm_key_max_sub_sample_num)   64 | The maximum number of subsamples is 64.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVBuffer](_multimedia___drm.md#oh_avbuffer) [OH_AVBuffer](_multimedia___drm.md#oh_avbuffer) | Defines a struct for the audio/video buffer.| 
| typedef struct [OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) [OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) | Defines a struct for the audio/video Common Encryption Scheme (CENC) information.| 
| typedef enum [DrmCencAlgorithm](_multimedia___drm.md#drmcencalgorithm) [DrmCencAlgorithm](_multimedia___drm.md#drmcencalgorithm) | Defines an enum for the DRM CENC algorithm types.| 
| typedef enum [DrmCencInfoMode](_multimedia___drm.md#drmcencinfomode) [DrmCencInfoMode](_multimedia___drm.md#drmcencinfomode) | Defines an enum for the modes for setting the key ID, IV, and subsample information in the CENC information.| 
| typedef struct [DrmSubsample](_drm_subsample.md) [DrmSubsample](_multimedia___drm.md#drmsubsample) | Defines a struct for the subsample type.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [DrmCencAlgorithm](_multimedia___drm.md#drmcencalgorithm) {<br>DRM_ALG_CENC_UNENCRYPTED = 0x0, DRM_ALG_CENC_AES_CTR = 0x1,<br>DRM_ALG_CENC_AES_WV = 0x2, DRM_ALG_CENC_AES_CBC = 0x3,<br>DRM_ALG_CENC_SM4_CBC = 0x4, DRM_ALG_CENC_SM4_CTR = 0x5<br>} | Enumerates the DRM CENC algorithm types.| 
| [DrmCencInfoMode](_multimedia___drm.md#drmcencinfomode) {<br>DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET = 0x0,<br>DRM_CENC_INFO_KEY_IV_SUBSAMPLES_NOT_SET = 0x1 } | Enumerates the modes for setting the key ID, IV, and subsample information in the CENC information.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \* [OH_AVCencInfo_Create](_multimedia___drm.md#oh_avcencinfo_create) () | Creates an **OH_AVCencInfo** instance for setting the CENC information.| 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_Destroy](_multimedia___drm.md#oh_avcencinfo_destroy) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo) | Destroys an **OH_AVCencInfo** instance and clears internal resources.| 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetAlgorithm](_multimedia___drm.md#oh_avcencinfo_setalgorithm) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, enum [DrmCencAlgorithm](_multimedia___drm.md#drmcencalgorithm) algo) | Sets an encryption algorithm of the CENC information.| 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetKeyIdAndIv](_multimedia___drm.md#oh_avcencinfo_setkeyidandiv) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, uint8_t \*keyId, uint32_t keyIdLen, uint8_t \*iv, uint32_t ivLen) | Sets the key ID and IV in the CENC information.| 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetSubsampleInfo](_multimedia___drm.md#oh_avcencinfo_setsubsampleinfo) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, uint32_t encryptedBlockCount, uint32_t skippedBlockCount, uint32_t firstEncryptedOffset, uint32_t subsampleCount, [DrmSubsample](_drm_subsample.md) \*subsamples) | Sets the subsample information in the CENC information.| 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetMode](_multimedia___drm.md#oh_avcencinfo_setmode) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, enum [DrmCencInfoMode](_multimedia___drm.md#drmcencinfomode) mode) | Sets the CENC information mode.| 
| [OH_AVErrCode](_core.md#oh_averrcode) \* [OH_AVCencInfo_SetAVBuffer](_multimedia___drm.md#oh_avcencinfo_setavbuffer) ([OH_AVCencInfo](_multimedia___drm.md#oh_avcencinfo) \*cencInfo, [OH_AVBuffer](_multimedia___drm.md#oh_avbuffer) \*buffer) | Sets the CENC information to an AVBuffer.| 
