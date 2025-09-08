# ROI Video Encoding

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xhjgc-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## Basic Concepts

Region of Interest (ROI) video encoding is an advanced capability built on existing hardware encoding. It allows you to specify ROI areas and optimize encoding effects by adjusting bit rate allocation for these areas.
- ROI area: ROI typically refers to the eye-catching areas in a video, such as a face in a live broadcast.
- ROI encoding: This allows for higher bit rate allocation to the ROI areas in the frame while reducing the bit rate for non-ROI areas like the background, thereby enhancing the overall visual experience under limited bandwidth conditions.

## When to Use

Video encoding scenarios with distinct ROI areas, such as:
- **Live streaming scenarios**: Faces or products are usually the focal points. ROI encoding can effectively enhance the subjective clarity of these areas.
- **Surveillance scenarios**: License plates or faces are usually the focal points. ROI encoding can preserve clearer useful information.

## Constraints

- **Supported platforms**: Kirin 9000 and later
- **Supported systems**: OpenHarmony 6.0 and later
- **Supported encoders**: H.264 8-bit hardware encoding, H.265 8-bit hardware encoding, and H.265 10-bit hardware encoding
- **Supported bit rate control modes**: VBR, CBR, and SQR
- **Supported encoding modes**: surface mode and buffer mode
- A maximum of 6 ROI areas can be configured per frame, and the total ROI area cannot exceed 1/5 of the image area.
- The module only provides the underlying ROI encoding capability and does not include ROI area detection.

## Available APIs

The ROI encoding API enables you to send configuration parameters in string format. The parameters must follow the format "Top1,Left1-Bottom1,Right1=Offset1;Top2,Left2-Bottom2,Right2=Offset2;".<br>
- **Top**, **Left**, **Bottom**, and **Right** specify the top, left, bottom, and right boundaries of the ROI area, respectively.
- **Offset** specifies deltaQp. The **"=Offset"** part can be omitted. If it is omitted, the default parameter (**deltaQp=-3**) is used.
- Multiple ROI parameters are separated by semicolons (;). All parameters are integers.
- Before using the ROI encoding APIs, ensure that the input parameters are valid and avoid overlapping between multiple ROI areas as much as possible.

|Parameter|Description|Format|
|------- |------- |------- |
|OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS |ROI parameters.|String|

**NOTE**
1. For ease of use, ROI parameters support per-frame sending and real-time effectiveness. You do not need to perform capability queries or configure global switches.
2. If the underlying hardware encoder does not support ROI encoding, the encoder ignores the ROI parameters and performs normal encoding.
3. The valid range for deltaQp is [-51, 51]. The encoder overlays deltaQp on the block-level QP, and then clips it to the [minQp, maxQp] range to obtain the final QP.
4. If the parameters are not sent through **OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS**, the frame will reuse historical ROI information for encoding.
5. If an empty string is sent through **OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS**, ROI encoding is disabled, historical ROI information is cleared, and normal encoding is performed.
6. If the string sent through **OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS** cannot be parsed into any valid ROI information, ROI encoding does not take effect, historical ROI information is cleared, and normal encoding is performed.
7. If the total ROI area exceeds 1/5 of the image size, ROI encoding does not take effect, historical ROI information is cleared, and normal encoding is performed.
8. If more than 6 valid ROI parameters are input, the excess ROI parameters are ignored.
9. If multiple ROI areas overlap, only the first ROI parameter takes effect in the overlapping area.

## How to Develop

For details about basic encoding functionality, see [Video Encoding](video-encoding.md). The following are specific instructions for ROI encoding.

### Surface Mode


1. Call **OH_VideoEncoder_RegisterParameterCallback()** to register the frame-specific parameter callback.

    ```c++
    // 1. Implement the OH_VideoEncoder_OnNeedInputParameter callback function.
    static void OnNeedInputParameter(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter, void *userData)
    {
        /**
        * Configure two ROI areas and specify the corresponding deltaQp.
        * ROI1 has its top-left corner at (0, 0) and bottom-right corner at (64, 128), with a QP adjustment of -4.
        * ROI2 has its top-left corner at (200, 100) and bottom-right corner at (400, 300), with a QP adjustment of +3.
        **/
        const char *roiInfo = "0,0-128,64=-4;100,200-300,400=3";
        OH_AVFormat_SetStringValue(parameter, OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS, roiInfo);
        OH_VideoEncoder_PushInputParameter(codec, index);
    }
    // 2. Register the frame channel callback functions.
    OH_VideoEncoder_OnNeedInputParameter inParaCb = OnNeedInputParameter;
    OH_VideoEncoder_RegisterParameterCallback(videoEnc, inParaCb, nullptr); // nullptr: userData is null.
    ```

### Buffer Mode

1. Call **OH_AVBuffer_SetParameter()** to configure frame-specific parameters.

    ```c++
    void OnNeedInputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        /**
        * Configure two ROI areas and specify the corresponding deltaQp.
        * ROI1 has its top-left corner at (0, 0) and bottom-right corner at (64, 128), with a QP adjustment of -4.
        * ROI2 has its top-left corner at (200, 100) and bottom-right corner at (400, 300), with a QP adjustment of +3.
        **/
        const char *roiInfo = "0,0-128,64=-4;100,200-300,400=3";
        OH_AVFormat *parameter = OH_AVBuffer_GetParameter(buffer);
        OH_AVFormat_SetStringValue(parameter, OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS, roiInfo);
        OH_AVBuffer_SetParameter(buffer, parameter);
        OH_AVFormat_Destroy(parameter);

        inQueue.Enqueue(std::make_shared<CodecBufferInfo>(index, buffer));
    }
    ```
