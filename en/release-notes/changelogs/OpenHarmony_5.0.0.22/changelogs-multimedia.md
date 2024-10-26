# Multimedia Subsystem Changelog

## c1.multimedia.1 API Behavior of OH_VideoDecoder_Configure and OH_VideoEncoder_Configure Changed

**Access Level**

Public API

**Reason for Change**

The parameters passed by the encoder to the **Configure** API are not verified. In some scenarios, invalid values are passed in, causing effect-related issues. Parameter verification should be added to ensure that the parameters used during encoding or decoding meet the codec capabilities and requirements.

**Change Impact**

This change is a compatibility change. If an incorrect parameter is passed in to the **Configure** API, an error is thrown.

For details about the decoder parameter verification logic, see [OH_VideoDecoder_Configure()](../../../application-dev/reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_configure).

For details about the encoder parameter verification logic, see [OH_VideoEncoder_Configure()](../../../application-dev/reference/apis-avcodec-kit/_video_encoder.md#oh_videoencoder_configure).

**Start API Level**

API version 9

**Change Since**

OpenHarmony SDK 5.0.0.22

**Key API/Component Changes**

| Name                     | Description                       |
| ------------------------- | --------------------------- |
| OH_VideoDecoder_Configure | An error is thrown if an invalid parameter is passed in.|
| OH_VideoEncoder_Configure | An error is thrown if an invalid parameter is passed in.|

**Adaptation Guide**

You can use the codec capability query interface to obtain the encoder parameter ranges. For details, see [Obtaining Supported Codecs](../../../application-dev/media/avcodec/obtain-supported-codecs.md).

## c1.multimedia.1 API Behavior of OH_AVFormat Set Changed

**Access Level**

Public API

**Reason for Change**

**OH_AVFormat** supports multiple types of parameters (int, long, float, double, string, and buffer). When an incorrect **Set** API is called to pass in a value, no error is reported. Consequently, related functional modules cannot obtain the corresponding parameters, causing effect-related issues. Parameter type verification logic should be added to the **Set** API to ensure correct parameter settings.

**Change Impact**

This change is a compatibility change. The **Set** API returns **false** only when it is incorrectly called.

**Start API Level**

API version 9

**Change Since**

OpenHarmony SDK 5.0.0.22

**Key API/Component Changes**

| Name                      | Description                                   |
| -------------------------- | --------------------------------------- |
| OH_AVFormat_SetIntValue    | If this API is called to set a parameter of the non-int type, an error is reported.   |
| OH_AVFormat_SetLongValue   | If this API is called to set a parameter of the non-long type, an error is reported.  |
| OH_AVFormat_SetFloatValue  | If this API is called to set a parameter of the non-float type, an error is reported. |
| OH_AVFormat_SetDoubleValue | If this API is called to set a parameter of the non-double type, an error is reported.|
| OH_AVFormat_SetStringValue | If this API is called to set a parameter of the non-string type, an error is reported.|
| OH_AVFormat_SetBuffer      | If this API is called to set a parameter of the non-buffer type, an error is reported.|

**Adaptation Guide**

Use the **Set** API of **OH_AVFormat** to pass in parameters by referring to the type definition of each parameter.
