# Multimedia Subsystem Changelog

## cl.multimedia.1 Changed the Parameter Type for the HEIF Format in image.Component.OH_PackingOptions_SetMimeType()

**Access Level**

Public API

**Reason for Change**

During HEIF encoding with the camera, the encoding fails with the standard-defined **image/heic** parameter. The current version of Image defines the format parameter as **image/heif**, which does not comply with the standard definition. To improve adherence to standards, the **mimeType** parameter for HEIF images is changed to **image/heic**.

**Change Impact**

This change is a non-compatible change.

Before change: The **mimeType** parameter for HEIF images is **image/heif**.

After change: The **mimeType** parameter for HEIF images is **image/heic**.

**Start API Level**

12

**Change Since**

OpenHarmony 5.0.0.53

**Key API/Component Changes**

API in image_packer_native.h:

Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format)

**Adaptation Guide**

When **OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format)** is called to set **mimeType** for HEIF images, the **format** parameter must be **image/heic**.


## cl.multimedia.2 Changed the Return Value Type for the HEIF Format in image.Component.OH_PackingOptions_GetMimeType()

**Access Level**

Public API

**Reason for Change**

During HEIF encoding with the camera, the encoding fails with the standard-defined **image/heic** parameter. The current version of Image defines the format parameter as **image/heif**, which does not comply with the standard definition. To improve adherence to standards, the **mimeType** parameter for HEIF images is changed to **image/heic**.

**Change Impact**

This change is a non-compatible change.

Before change: The **mimeType** parameter for HEIF images is **image/heif**.

After change: The **mimeType** parameter for HEIF images is **image/heic**.

**Start API Level**

12

**Change Since**

OpenHarmony 5.0.0.53

**Key API/Component Changes**

API in image_packer_native.h:

Image_ErrorCode OH_PackingOptions_GetMimeType (OH_PackingOptions * options, Image_MimeType * format)

**Adaptation Guide**

When **OH_PackingOptions_GetMimeType(OH_PackingOptions *options, Image_MimeType *format)** is called to obtain **mimeType** of HEIF images, **format** in the return value is **image/heic**. You need to review the sample project of the application and modify the format based on service requirements.


## cl.multimedia.3 Changed the Return Value Type for the HEIF Format in image.Component.supportedFormats for Decoding

**Access Level**

Public API

**Reason for Change**

During HEIF encoding with the camera, the encoding fails with the standard-defined **image/heic** parameter. The current version of Image defines the format parameter as **image/heif**, which does not comply with the standard definition. To improve adherence to standards, the **mimeType** parameter for HEIF images is changed to **image/heic**.

**Change Impact**

This change is a non-compatible change.

Before change: The return value of the decoding type supported by the device for HEIF images is **image/heif**.

After change: The return value of the decoding type supported by the device for HEIF images is **image/heic**.

**Start API Level**

10

**Change Since**

OpenHarmony 5.0.0.53

**Key API/Component Changes**

Property in /interface/sdk-js/api/@ohos.multimedia.image.d.ts:

image.Component.readonly supportedFormats: Array\<string>

**Adaptation Guide**

When this property is used to obtain the decoding type of a device, the calling behavior remains unchanged. If the device supports HEIF, the return value is changed from **image/heif** to **image/heic**.


## cl.multimedia.4 Changed the Return Value Type for the HEIF Format in image.Component.supportedFormats for Encoding

**Access Level**

Public API

**Reason for Change**

During HEIF encoding with the camera, the encoding fails with the standard-defined **image/heic** parameter. The current version of Image defines the format parameter as **image/heif**, which does not comply with the standard definition. To improve adherence to standards, the **mimeType** parameter for HEIF images is changed to **image/heic**.

**Change Impact**

This change is a non-compatible change.

Before change: The return value of the encoding type supported by the device for HEIF images is **image/heif**.

After change: The return value of the encoding type supported by the device for HEIF images is **image/heic**.

**Start API Level**

10

**Change Since**

OpenHarmony 5.0.0.53

**Key API/Component Changes**

Property in /interface/sdk-js/api/@ohos.multimedia.image.d.ts:

image.Component.readonly supportedFormats: Array\<string>

**Adaptation Guide**

When this property is used to obtain the encoding type of a device, the calling behavior remains unchanged. If the device supports HEIF, the return value is changed from **image/heif** to **image/heic**.


## cl.multimedia.5 Changed the Encoding Parameter for the HEIF Format in image.Component.packing()

**Access Level**

Public API

**Reason for Change**

During HEIF encoding with the camera, the encoding fails with the standard-defined **image/heic** parameter. The current version of Image defines the format parameter as **image/heif**, which does not comply with the standard definition. To improve adherence to standards, the **mimeType** parameter for HEIF images is changed to **image/heic**.

**Change Impact**

This change is a compatible change.

Before change: The **mimeType** parameter for HEIF encoding is **image/heif**.

After change: The **mimeType** parameter for HEIF encoding is **image/heic**.

**Start API Level**

12

**Change Since**

OpenHarmony 5.0.0.53

**Key API/Component Changes**

API in /interface/sdk-js/api/@ohos.multimedia.image.d.ts:

image.Component.packing()

**Adaptation Guide**

When calling the API to encode HEIF images, you can use both **image/heif** and **image/heic**. Both types can be used to encode the images into HEIC.


## cl.multimedia.6 Changed the Encoding Parameter for the HEIF Format in the Image.Component.OH_PackingOptions Struct

**Access Level**

Public API

**Reason for Change**

During HEIF encoding with the camera, the encoding fails with the standard-defined **image/heic** parameter. The current version of Image defines the format parameter as **image/heif**, which does not comply with the standard definition. To improve adherence to standards, the **mimeType** parameter for HEIF images is changed to **image/heic**.

**Change Impact**

This change is a compatible change.

Before change: The **mimeType** parameter for HEIF encoding is **image/heif**.

After change: The **mimeType** parameter for HEIF encoding is **image/heic**.

**Start API Level**

12

**Change Since**

OpenHarmony 5.0.0.53

**Key API/Component Changes**

Property in image_packer_native.h:

image.Component.OH_PackingOptions

**Adaptation Guide**

When calling the API to encode HEIF images, you can use both **image/heif** and **image/heic**. Both types can be used to encode the images into HEIC.
