# Multimedia_Drm


## Overview

The Multimedia_Drm module provides APIs for you to set decryption parameters. After a DRM instance and session are created, you can decrypt a DRM encrypted program.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_cencinfo.h](native__cencinfo_8h.md) | Declares the native APIs used to set decryption parameters.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [DrmSubsample](_drm_subsample.md) | Describes the subsample type.| 


### Macros

| Name| Description| 
| -------- | -------- |
| [DRM_KEY_ID_SIZE](#drm_key_id_size)   16 | The length of the key ID is 16 bytes.| 
| [DRM_KEY_IV_SIZE](#drm_key_iv_size)   16 | The length of the Initialization Vector (IV) is 16 bytes.| 
| [DRM_KEY_MAX_SUB_SAMPLE_NUM](#drm_key_max_sub_sample_num)   64 | The maximum number of subsamples is 64.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVBuffer](#oh_avbuffer) [OH_AVBuffer](#oh_avbuffer) | Defines a struct for the audio/video buffer.| 
| typedef struct [OH_AVCencInfo](#oh_avcencinfo) [OH_AVCencInfo](#oh_avcencinfo) | Defines a struct for the audio/video Common Encryption Scheme (CENC) information.| 
| typedef enum [DrmCencAlgorithm](#drmcencalgorithm) [DrmCencAlgorithm](#drmcencalgorithm) | Defines an enum for the DRM CENC algorithm types.| 
| typedef enum [DrmCencInfoMode](#drmcencinfomode) [DrmCencInfoMode](#drmcencinfomode) | Defines an enum for the modes for setting the key ID, IV, and subsample information in the CENC information.| 
| typedef struct [DrmSubsample](_drm_subsample.md) [DrmSubsample](#drmsubsample) | Defines a struct for the subsample type.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [DrmCencAlgorithm](#drmcencalgorithm) {<br>DRM_ALG_CENC_UNENCRYPTED = 0x0, DRM_ALG_CENC_AES_CTR = 0x1,<br>DRM_ALG_CENC_AES_WV = 0x2, DRM_ALG_CENC_AES_CBC = 0x3,<br>DRM_ALG_CENC_SM4_CBC = 0x4, DRM_ALG_CENC_SM4_CTR = 0x5<br>} | Enumerates the DRM CENC algorithm types.| 
| [DrmCencInfoMode](#drmcencinfomode) {<br>DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET = 0x0,<br>DRM_CENC_INFO_KEY_IV_SUBSAMPLES_NOT_SET = 0x1 } | Enumerates the modes for setting the key ID, IV, and subsample information in the CENC information.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVCencInfo](#oh_avcencinfo) \* [OH_AVCencInfo_Create](#oh_avcencinfo_create) () | Creates an **OH_AVCencInfo** instance for setting the CENC information.| 
| OH_AVErrCode [OH_AVCencInfo_Destroy](#oh_avcencinfo_destroy) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo) | Destroys an **OH_AVCencInfo** instance and clears internal resources.| 
| OH_AVErrCode [OH_AVCencInfo_SetAlgorithm](#oh_avcencinfo_setalgorithm) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, enum [DrmCencAlgorithm](#drmcencalgorithm) algo) | Sets an encryption algorithm of the CENC information.| 
| OH_AVErrCode [OH_AVCencInfo_SetKeyIdAndIv](#oh_avcencinfo_setkeyidandiv) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, uint8_t \*keyId, uint32_t keyIdLen, uint8_t \*iv, uint32_t ivLen) | Sets the key ID and IV in the CENC information.| 
| OH_AVErrCode [OH_AVCencInfo_SetSubsampleInfo](#oh_avcencinfo_setsubsampleinfo) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, uint32_t encryptedBlockCount, uint32_t skippedBlockCount, uint32_t firstEncryptedOffset, uint32_t subsampleCount, [DrmSubsample](_drm_subsample.md) \*subsamples) | Sets the subsample information in the CENC information.| 
| OH_AVErrCode [OH_AVCencInfo_SetMode](#oh_avcencinfo_setmode) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, enum [DrmCencInfoMode](#drmcencinfomode) mode) | Sets the CENC information mode.| 
| OH_AVErrCode [OH_AVCencInfo_SetAVBuffer](#oh_avcencinfo_setavbuffer) ([OH_AVCencInfo](#oh_avcencinfo) \*cencInfo, [OH_AVBuffer](#oh_avbuffer) \*buffer) | Sets the CENC information to an AVBuffer.| 


## Macro Description


### DRM_KEY_ID_SIZE

```
#define DRM_KEY_ID_SIZE   16
```

**Description**

The length of the key ID is 16 bytes.

**Since**: 12


### DRM_KEY_IV_SIZE

```
#define DRM_KEY_IV_SIZE   16
```

**Description**

The length of the Initialization Vector (IV) is 16 bytes.

**Since**: 12


### DRM_KEY_MAX_SUB_SAMPLE_NUM

```
#define DRM_KEY_MAX_SUB_SAMPLE_NUM   64
```

**Description**

The maximum number of subsamples is 64.

**Since**: 12


## Type Description


### DrmCencAlgorithm

```
typedef enum DrmCencAlgorithm DrmCencAlgorithm
```

**Description**

Defines an enum for the DRM CENC algorithm types.

**Since**: 12


### DrmCencInfoMode

```
typedef enum DrmCencInfoMode DrmCencInfoMode
```

**Description**

Defines an enum for the modes for setting the key ID, IV, and subsample information in the CENC information.

**Since**: 12


### DrmSubsample

```
typedef struct DrmSubsample DrmSubsample
```

**Description**

Defines a struct for the subsample type.

**Since**: 12


### OH_AVBuffer

```
typedef struct OH_AVBuffer OH_AVBuffer
```

**Description**

Defines a struct for the audio/video buffer.

**Since**: 12


### OH_AVCencInfo

```
typedef struct OH_AVCencInfo OH_AVCencInfo
```

**Description**

Defines a struct for the audio/video Common Encryption Scheme (CENC) information.

**Since**: 12


## Enum Description


### DrmCencAlgorithm

```
enum DrmCencAlgorithm
```

**Description**

Enumerates the DRM CENC algorithm types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| DRM_ALG_CENC_UNENCRYPTED | No encryption algorithm is used.| 
| DRM_ALG_CENC_AES_CTR | AES CTR algorithm.| 
| DRM_ALG_CENC_AES_WV | AES WV algorithm.| 
| DRM_ALG_CENC_AES_CBC | AES CBC algorithm.| 
| DRM_ALG_CENC_SM4_CBC | SM4 CBC algorithm.| 
| DRM_ALG_CENC_SM4_CTR | SM4 CTR algorithm.| 


### DrmCencInfoMode

```
enum DrmCencInfoMode
```

**Description**

Enumerates the modes for setting the key ID, IV, and subsample information in the CENC information.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET | The key ID, IV, and subsample information is set.| 
| DRM_CENC_INFO_KEY_IV_SUBSAMPLES_NOT_SET | The key ID, IV, and subsample information is not set.| 


## Function Description


### OH_AVCencInfo_Create()

```
OH_AVCencInfo* OH_AVCencInfo_Create ()
```

**Description**

Creates an **OH_AVCencInfo** instance for setting the CENC information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Returns**

Returns the pointer to the **OH_AVCencInfo** instance created if the operation is successful; returns a null pointer otherwise.

The possible causes of an operation failure are as follows: The application address space is full, or the data in the object fails to be initialized.


### OH_AVCencInfo_Destroy()

```
OH_AVErrCode OH_AVCencInfo_Destroy (OH_AVCencInfo * cencInfo)
```

**Description**

Destroys an **OH_AVCencInfo** instance and clears internal resources.

An instance can be destroyed only once. Do not use the instance until it is created again. You are advised to set the instance pointer to a null pointer once the instance is destroyed.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cencInfo | Pointer to an **OH_AVCencInfo** instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](_core.md#oh_averrcode). The following result codes are possible:

**AV_ERR_OK** (value: 0): The operation is successful.

**AV_ERR_INVALID_VAL** (value: 3): The cencInfo struct is empty.


### OH_AVCencInfo_SetAlgorithm()

```
OH_AVErrCode OH_AVCencInfo_SetAlgorithm (OH_AVCencInfo * cencInfo, enum DrmCencAlgorithm algo )
```

**Description**

Sets an encryption algorithm of the CENC information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cencInfo | Pointer to an **OH_AVCencInfo** instance.| 
| algo | Encryption algorithm.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](_core.md#oh_averrcode). The following result codes are possible:

**AV_ERR_OK** (value: 0): The operation is successful.

**AV_ERR_INVALID_VAL** (value: 3): The cencInfo struct is empty.


### OH_AVCencInfo_SetAVBuffer()

```
OH_AVErrCode OH_AVCencInfo_SetAVBuffer (OH_AVCencInfo * cencInfo, OH_AVBuffer * buffer )
```

**Description**

Sets the CENC information to an AVBuffer.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cencInfo | Pointer to an **OH_AVCencInfo** instance.| 
| buffer | Pointer to the frame buffer that carries data.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](_core.md#oh_averrcode). The following result codes are possible:

**AV_ERR_OK** (value: 0): The operation is successful.

**AV_ERR_INVALID_VAL** (value: 3): **cencInfo**, **buffer**, **buffer-&gt;buffer_**, or **buffer-&gt;buffer_-&gt;meta_** is null.


### OH_AVCencInfo_SetKeyIdAndIv()

```
OH_AVErrCode OH_AVCencInfo_SetKeyIdAndIv (OH_AVCencInfo * cencInfo, uint8_t * keyId, uint32_t keyIdLen, uint8_t * iv, uint32_t ivLen )
```

**Description**

Sets the key ID and IV in the CENC information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cencInfo | Pointer to an **OH_AVCencInfo** instance.| 
| keyId | Pointer to the key ID.| 
| keyIdLen | Length of the key ID.| 
| iv | Pointer to the IV.| 
| ivLen | Length of the IV.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](_core.md#oh_averrcode). The following result codes are possible:

**AV_ERR_OK** (value: 0): The operation is successful.

**AV_ERR_INVALID_VAL** (value: 3): **cencInfo**, **keyId**, or **iv** is null, **keyIdLen** is not equal to **DRM_KEY_ID_SIZE**, **ivLen** is not equal to **DRM_KEY_IV_SIZE**, the key ID or IV fails to be copied.


### OH_AVCencInfo_SetMode()

```
OH_AVErrCode OH_AVCencInfo_SetMode (OH_AVCencInfo * cencInfo, enum DrmCencInfoMode mode )
```

**Description**

Sets the CENC information mode.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cencInfo | Pointer to an **OH_AVCencInfo** instance.| 
| mode | CENC information mode, indicating whether the key ID, IV, and subsample information is set.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](_core.md#oh_averrcode). The following result codes are possible:

**AV_ERR_OK** (value: 0): The operation is successful.

**AV_ERR_INVALID_VAL** (value: 3): The cencInfo struct is empty.


### OH_AVCencInfo_SetSubsampleInfo()

```
OH_AVErrCode OH_AVCencInfo_SetSubsampleInfo (OH_AVCencInfo * cencInfo, uint32_t encryptedBlockCount, uint32_t skippedBlockCount, uint32_t firstEncryptedOffset, uint32_t subsampleCount, DrmSubsample * subsamples )
```

**Description**

Sets the subsample information in the CENC information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cencInfo | Pointer to an **OH_AVCencInfo** instance.| 
| encryptedBlockCount | Number of encrypted blocks.| 
| skippedBlockCount | Number of non-encrypted blocks.| 
| firstEncryptedOffset | Offset of the first encrypted payload.| 
| subsampleCount | Number of subsamples.| 
| subsamples | Pointer to the subsamples.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](_core.md#oh_averrcode). The following result codes are possible:

**AV_ERR_OK** (value: 0): The operation is successful.

**AV_ERR_INVALID_VAL** (value: 3): **cencInfo** is null, **subsampleCount** is greater than **DRM_KEY_MAX_SUB_SAMPLE_NUM**, or **subsamples** is null.
