# image_packer_mdk.h


## Overview

The **image_packer_mdk.h** file declares the APIs used to pack an image or a PixelMap into a buffer or file.

The packing process is as follows:

1. Call **OH_ImagePacker_Create** to create an **ImagePacker** object.

2. Call **OH_ImagePacker_InitNative** to convert the **ImagePacker** object to an **ImagePacker_Native** object.

3. Call **OH_ImagePacker_PackToData** or **OH_ImagePacker_PackToFile** to pack the source into the target area with the specified packing options.

4. Call **OH_ImagePacker_Release** to release an **ImagePacker_Native** object.

**Library**: libimage_packer_ndk.z.so

**File to include**: &lt;multimedia/image_framework/image_packer_mdk.h&gt;

**System capability**: SystemCapability.Multimedia.Image

**Since**: 11

**Related module**: [Image](image.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [ImagePacker_Opts_](_image_packer___opts__.md) | Defines the image packing options. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct ImagePacker_Native_ [ImagePacker_Native](image.md#imagepacker_native) | Defines the **ImagePacker** instance at the native layer. | 
| typedef struct [ImagePacker_Opts_](_image_packer___opts__.md) [ImagePacker_Opts](image.md#imagepacker_opts) | Defines the alias of the image packing options. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_ImagePacker_Create](image.md#oh_imagepacker_create) (napi_env env, napi_value \*res) | Obtains an **ImagePacker** object at the JavaScript native layer. | 
| [ImagePacker_Native](image.md#imagepacker_native) \* [OH_ImagePacker_InitNative](image.md#oh_imagepacker_initnative) (napi_env env, napi_value packer) | Converts an **ImagePacker** object at the JavaScript native layer into an **ImagePacker_Native** object. | 
| int32_t [OH_ImagePacker_PackToData](image.md#oh_imagepacker_packtodata) ([ImagePacker_Native](image.md#imagepacker_native) \*native, napi_value source, [ImagePacker_Opts](image.md#imagepacker_opts) \*opts, uint8_t \*outData, size_t \*size) | Packs a **PixelMap** object or an **ImagePacker** object at the JavaScript native layer to a buffer (defined by **outData**) based on the specified **ImagePacker_Opts** struct.| 
| int32_t [OH_ImagePacker_PackToFile](image.md#oh_imagepacker_packtofile) ([ImagePacker_Native](image.md#imagepacker_native) \*native, napi_value source, [ImagePacker_Opts](image.md#imagepacker_opts) \*opts, int fd) | Packs a **PixelMap** object or an **ImagePacker** object at the JavaScript native layer to a file based on the specified **ImagePacker_Opts** struct. | 
| int32_t [OH_ImagePacker_Release](image.md#oh_imagepacker_release) ([ImagePacker_Native](image.md#imagepacker_native) \*native) | Releases an [ImagePacker_Native](image.md#imagepacker_native) object.| 
