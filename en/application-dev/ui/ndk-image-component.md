# Image Display (Image)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wu-yinxiao-->
<!--Designer: @liyujie43-->
<!--Tester: @wu-yinxiao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=d6a3d10ca5a6e91385b2cfd31a029ff913571c1b translatedAt=2026-08-05T10:09:17.610Z pushedAt=2026-08-06T06:21:51.394Z -->

Since API version 12, the ArkUI development framework provides the **Image** component in the NDK APIs for displaying images in apps. The **Image** component supports multiple image formats, including png, jpg, jpeg, bmp, webp, heif, and SVG. It supports multiple image sources (local resources, network images, PixelMap, etc.) and rich image processing features (scaling, interpolation, fill color, color filter, etc.). You can create **Image** components and set various attributes at the native layer to achieve high-performance image display effects, as well as the same display effects as the **Image** component on the ArkTS side. For ArkTS development guidance, see [Image Display (Image)](arkts-graphics-display.md).

## Constraints

1. **Thread safety**: All UI-related APIs must be called on the main thread. Multi-threaded operations may cause app crashes.

2. **Component mounting**: After a component is created, it must be added to a parent node via [addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild) to be displayed.

3. **Image path**:

   - Local images must use a full or relative path.

   - Network images require the `ohos.permission.INTERNET` permission.

4. **Resource release**: When releasing a component, you need to call [disposeNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#disposenode) to avoid memory leaks.

5. **Synchronous loading**: It is not recommended to use synchronous loading when the image takes a long time to load, as this will cause the page to become unresponsive.

## Prerequisites

Before using the **Image** component, complete the following preparations:

1. Create a Native C++ template project in DevEco Studio.

2.  [Integrate the ArkTS page](ndk-access-the-arkts-page.md) to complete the mounting configuration of the native component to the ArkTS page.

3. Add dependencies: Open the native project's **src/main/cpp/CMakeLists.txt, and add libace_ndk.z.so**, **libace_napi.z.so**, and the logging dependency **libhilog_ndk.z.so** to **target_link_libraries**.

    ```cmake
    cmake_minimum_required(VERSION 3.5.0)
    project(ImageExample)

    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

    if(DEFINED PACKAGE_FIND_FILE)
        include(${PACKAGE_FIND_FILE})
    endif()

    include_directories(${NATIVERENDER_ROOT_PATH})

    add_library(entry SHARED
        napi_init.cpp
        NativeEntry.cpp
        ImageExample.cpp
    )

    target_link_libraries(entry PUBLIC
        libace_napi.z.so      # NAPI API
        libace_ndk.z.so       # ArkUI NDK
        libhilog_ndk.z.so     # Logs
    )
    ```

4. Add header file references.

    <!-- @[image_headfiles](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

    ``` C++
    #include <arkui/native_node.h>
    #include <arkui/native_type.h>
    #include <arkui/native_interface.h>
    #include <hilog/log.h>
    ```

5. Prepare image resources: Prepare the image files to be displayed. The **Image** component supports multiple image sources. The following describes common resource preparation methods.

   - Using rawfile resources

    Place the image file in the `entry/src/main/resources/rawfile/` directory and reference it using a relative path in the code.

    <!-- @[image_source_rawfile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

    ``` C++
    // Set the image source (using a rawfile resource).
    ArkUI_AttributeItem srcItem = {nullptr, 0, "resource://RAWFILE/clouds.jpg"};
    nativeNodeApi->setAttribute(image1, NODE_IMAGE_SRC, &srcItem);
    ```

   - Using a network image

    Add the network permission in `entry/src/main/module.json5` and use the network URL directly in the code.

    ```json
    {
      "module": {
        "requestPermissions": [
          {
            "name": "ohos.permission.INTERNET"
          }
        ]
      }
    }
    ```

    <!-- @[network_image](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

    ``` C++
    ArkUI_AttributeItem srcItem = {nullptr, 0, "https://xxx.jpg"};
    nativeNodeApi->setAttribute(image0, NODE_IMAGE_SRC, &srcItem);
    ```

## Creating an Image Component

### Creating and Initializing the Image Component

Before using the **Image** component, you need to obtain the **nativeNodeApi** first, and then use the [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API to create the **Image** component.

<!-- @[image_getnode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
ArkUI_NativeNodeAPI_1* nativeNodeApi = nullptr;
OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nativeNodeApi);
if (nativeNodeApi == nullptr) {
    OH_LOG_ERROR(LOG_APP, "Get native node API failed");
    return nullptr;
}
```

<!-- @[create_image_component](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Create Image component 1 - basic image.
ArkUI_NodeHandle image1 = nativeNodeApi->createNode(ARKUI_NODE_IMAGE);
```

### Setting Image Sources

The **Image** component supports setting the image source via a string path or a [DrawableDescriptor](../reference/apis-arkui/js-apis-arkui-drawableDescriptor.md) object.

<!-- @[image_source_rawfile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set the image source (using a rawfile resource).
ArkUI_AttributeItem srcItem = {nullptr, 0, "resource://RAWFILE/clouds.jpg"};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_SRC, &srcItem);
```

## Setting Image Attributes

### Image Attributes

The following are the unique attributes of **Image**. For details, refer to the enum definitions in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

| Attribute Name | Description | Since |
|-------|--------|---------|
| NODE_IMAGE_SRC | String paths or **DrawableDescriptor**. | 12 |
| NODE_IMAGE_OBJECT_FIT | How the image fits the container. | 12 |
| NODE_IMAGE_INTERPOLATION | Interpolation quality when the image is enlarged. | 12 |
| NODE_IMAGE_OBJECT_REPEAT | Image tiling mode. | 12 |
| NODE_IMAGE_COLOR_FILTER | 5x4 color matrix. | 12 |
| NODE_IMAGE_AUTO_RESIZE | Whether to automatically resize the image source. | 12 |
| NODE_IMAGE_ALT | Image displayed when loading fails. | 12 |
| NODE_IMAGE_DRAGGABLE | Whether dragging is supported. | 12 |
| NODE_IMAGE_RENDER_MODE | Original color or black-and-white mode. | 12 |
| NODE_IMAGE_FIT_ORIGINAL_SIZE | Whether the display size follows the image source size. | 12 |
| NODE_IMAGE_FILL_COLOR | Fill color for SVG images. | 12 |
| NODE_IMAGE_RESIZABLE | Edge processing method when the image is stretched. | 12 |
| NODE_IMAGE_SYNC_LOAD | Whether to load the image synchronously. | 20 |
| NODE_IMAGE_SOURCE_SIZE | Image decoding size. | 21 |
| NODE_IMAGE_IMAGE_MATRIX | Image affine transformation matrix. | 21 |
| NODE_IMAGE_MATCH_TEXT_DIRECTION | Whether to follow the text direction. | 21 |
| NODE_IMAGE_COPY_OPTION | Whether the image can be copied. | 21 |
| NODE_IMAGE_ENABLE_ANALYZER | Whether to enable AI analysis. | 21 |
| NODE_IMAGE_DYNAMIC_RANGE_MODE | HDR display mode. | 21 |
| NODE_IMAGE_HDR_BRIGHTNESS | HDR image brightness. | 21 |
| NODE_IMAGE_ORIENTATION | Image rotation direction. | 21 |
| NODE_IMAGE_SUPPORT_SVG2 | SVG parsing capability scope. | 21 |
| NODE_IMAGE_CONTENT_TRANSITION | Image content transition animation. | 21 |
| NODE_IMAGE_ALT_PLACEHOLDER | Placeholder image displayed during loading. | 22 |
| NODE_IMAGE_ALT_ERROR | Placeholder image displayed when loading fails. | 22 |

### Setting the Image Scaling Type

Set the scaling mode of the image within its container through the **NODE_IMAGE_OBJECT_FIT** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_zoom](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set the scaling type.
ArkUI_NumberValue fitValue[] = {{.i32 = ARKUI_OBJECT_FIT_COVER}};
ArkUI_AttributeItem fitItem = {fitValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_OBJECT_FIT, &fitItem);
```

### Setting the Image Interpolation Effect

Set the image interpolation effect through the **NODE_IMAGE_INTERPOLATION** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_interpolation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set the interpolation effect.
ArkUI_NumberValue interpolationValue[] = {{.i32 = ARKUI_IMAGE_INTERPOLATION_HIGH}};
ArkUI_AttributeItem interpolationItem = {interpolationValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_INTERPOLATION, &interpolationItem);
```

### Setting the Image Repeat Style

Set the image repeat style through the **NODE_IMAGE_OBJECT_REPEAT** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_repeat](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set the repeating style.
ArkUI_NumberValue repeatValue[] = {{.i32 = ARKUI_IMAGE_REPEAT_NONE}};
ArkUI_AttributeItem repeatItem = {repeatValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_OBJECT_REPEAT, &repeatItem);
```

### Setting the Image Fill Color

Set the SVG image fill color through the **NODE_IMAGE_FILL_COLOR** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_fillcolor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set the fill color (blue).
ArkUI_NumberValue fillColorValue[] = {{.u32 = 0xFF007DFF}};
ArkUI_AttributeItem fillColorItem = {fillColorValue, 1};
nativeNodeApi->setAttribute(image2, NODE_IMAGE_FILL_COLOR, &fillColorItem);
```

### Setting the Placeholder Image

Set the placeholder image through the **NODE_IMAGE_ALT** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_alt_source](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set the placeholder image.
ArkUI_AttributeItem altItem = {nullptr, 0, "/data/storage/el2/base/haps/entry/files/placeholder.png"};
nativeNodeApi->setAttribute(image3, NODE_IMAGE_ALT, &altItem);
```

### Setting the Image Decoding Size

Set the image decoding size through the **NODE_IMAGE_SOURCE_SIZE** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_decode_size](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set the decoding size.
ArkUI_NumberValue sourceSizeValue[] = {{.i32 = 150}, {.i32 = 150}};
ArkUI_AttributeItem sourceSizeItem = {sourceSizeValue, 2};
nativeNodeApi->setAttribute(image3, NODE_IMAGE_SOURCE_SIZE, &sourceSizeItem);
```

### Setting the Image Render Mode

Set the image render mode through the **NODE_IMAGE_RENDER_MODE** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_render](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set the rendering mode.
ArkUI_NumberValue renderModeValue[] = {{.i32 = ARKUI_IMAGE_RENDER_MODE_ORIGINAL}};
ArkUI_AttributeItem renderModeItem = {renderModeValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_RENDER_MODE, &renderModeItem);
```

### Setting Synchronous Load

Set the synchronous or asynchronous load mode of the image through the **NODE_IMAGE_SYNC_LOAD** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_load_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set synchronous load.
ArkUI_NumberValue syncLoadValue[] = {{.i32 = 1}};
ArkUI_AttributeItem syncLoadItem = {syncLoadValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_SYNC_LOAD, &syncLoadItem);
```

### Setting Image Color Filter

Set the image color filter through the **NODE_IMAGE_COLOR_FILTER** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_color_filter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set the color filter (5x4 matrix, 20 floating-point numbers in total).
// Matrix format: Each row has 5 elements representing the coefficients and offsets for R, G, B, and A respectively.
// Row 1: R row - R_new = R*1 + G*0 + B*0 + A*0 + offset*0 = R
// Row 2: G row - G_new = R*0 + G*1 + B*0 + A*0 + offset*0 = G
// Row 3: B row - B_new = R*0 + G*0 + B*1 + A*0 + offset*0 = B
// Row 4: A row - A_new = R*0 + G*0 + B*0 + A*1 + offset*0 = A
// The example matrix is an identity matrix, meaning it does not change the color.
float colorFilterMatrix[20] = {
    1.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // R row: Coefficients and offsets for R, G, B, A
    0.0f, 1.0f, 0.0f, 0.0f, 0.0f,  // G row: Coefficients and offsets for R, G, B, A
    0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // B row: coefficients and offsets for R, G, B, A
    0.0f, 0.0f, 0.0f, 1.0f, 0.0f   // A row: coefficients and offsets for R, G, B, A
};
ArkUI_NumberValue colorFilterValue[20] = {
    {.f32 = colorFilterMatrix[0]}, {.f32 = colorFilterMatrix[1]},
    {.f32 = colorFilterMatrix[2]}, {.f32 = colorFilterMatrix[3]},
    {.f32 = colorFilterMatrix[4]}, {.f32 = colorFilterMatrix[5]},
    {.f32 = colorFilterMatrix[6]}, {.f32 = colorFilterMatrix[7]},
    {.f32 = colorFilterMatrix[8]}, {.f32 = colorFilterMatrix[9]},
    {.f32 = colorFilterMatrix[10]}, {.f32 = colorFilterMatrix[11]},
    {.f32 = colorFilterMatrix[12]}, {.f32 = colorFilterMatrix[13]},
    {.f32 = colorFilterMatrix[14]}, {.f32 = colorFilterMatrix[15]},
    {.f32 = colorFilterMatrix[16]}, {.f32 = colorFilterMatrix[17]},
    {.f32 = colorFilterMatrix[18]}, {.f32 = colorFilterMatrix[19]}
};
ArkUI_AttributeItem colorFilterItem = {colorFilterValue, 20};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_COLOR_FILTER, &colorFilterItem);
```

### Setting Image Display Orientation

Set the image display orientation through the **NODE_IMAGE_ORIENTATION** attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

<!-- @[image_orientation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Set image display orientation.
ArkUI_NumberValue orientationValue[] = {{.i32 = ARKUI_ORIENTATION_UP}};
ArkUI_AttributeItem orientationItem = {orientationValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_ORIENTATION, &orientationItem);
```

## Listening for Image Events

Listen for image events by registering a global event receiver to receive all node events, and registering specific events on specific nodes through the **NODE_IMAGE_ON_COMPLETE**, **NODE_IMAGE_ON_ERROR**, **NODE_IMAGE_ON_SVG_PLAY_FINISH**, and **NODE_IMAGE_ON_DOWNLOAD_PROGRESS** APIs in [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype).

### Registering the Global Event Receiver

Before handling image events, you need to register a global event receiver through the [registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver) API.

<!-- @[event_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Global event receiver function.
void GlobalEventReceiver(ArkUI_NodeEvent *event)
{
    auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
    if (eventType == NODE_IMAGE_ON_COMPLETE) {
        ArkUI_NodeComponentEvent *componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
        if (componentEvent != nullptr) {
            OH_LOG_INFO(LOG_APP, "Image loaded: %.0fx%.0f",
                        componentEvent->data[0].f32, componentEvent->data[1].f32);
        }
    } else if (eventType == NODE_IMAGE_ON_ERROR) {
        ArkUI_NodeComponentEvent *componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
        if (componentEvent != nullptr) {
            OH_LOG_ERROR(LOG_APP, "Image load failed, error: %d", componentEvent->data[0].i32);
        }
    } else if (eventType == NODE_IMAGE_ON_SVG_PLAY_FINISH) {
        OH_LOG_INFO(LOG_APP, "SVG animation play finished");
    }
}
```

<!-- @[register_image_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Register the global event receiver.
nativeNodeApi->registerNodeEventReceiver(GlobalEventReceiver);
```

### Listening for Image Load Completion Events

Use the [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent) API on the image node to register the **NODE_IMAGE_ON_COMPLETE** event. This event is triggered when the image is loaded successfully, and the image size information can be obtained in the event callback.

<!-- @[image_load_complete](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Handle the image load completion event.
void HandleImageComplete(ArkUI_NodeEvent* event)
{
    // Use the function to get componentEvent
    ArkUI_NodeComponentEvent* componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
    if (componentEvent == nullptr) {
        OH_LOG_ERROR(LOG_APP, "Get component event failed");
        return;
    }

    // Get image information.
    float width = componentEvent->data[0].f32;           // Original image width
    float height = componentEvent->data[1].f32;          // Original image height
    float componentWidth = componentEvent->data[2].f32;  // Component width
    float componentHeight = componentEvent->data[3].f32; // Component height
    float contentWidth = componentEvent->data[4].f32;    // Rendered content width
    float contentHeight = componentEvent->data[5].f32;   // Rendered content height

    OH_LOG_INFO(LOG_APP, "Image loaded: %.0fx%.0f, component: %.0fx%.0f",
                width, height, componentWidth, componentHeight);
}
```

<!-- @[register_image_load_complete](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Register the image load complete event.
nativeNodeApi->registerNodeEvent(image1, NODE_IMAGE_ON_COMPLETE, 0, nullptr);
```

### Listening for Image Load Failure Events

Use the [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent) API on the image node to register the **NODE_IMAGE_ON_ERROR** failure event. This event is triggered when image loading fails, and the error code information can be obtained in the event callback.

<!-- @[image_load_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Image load failure event handling.
void HandleImageError(ArkUI_NodeEvent* event)
{
    ArkUI_NodeComponentEvent* componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
    if (componentEvent == nullptr) {
        OH_LOG_ERROR(LOG_APP, "Get component event failed");
        return;
    }

    int32_t errorCode = componentEvent->data[0].i32;
    // 401: Invalid image path.
    OH_LOG_ERROR(LOG_APP, "Image load failed, error code: %d", errorCode);
}
```

<!-- @[register_image_load_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Register the image load failure event.
nativeNodeApi->registerNodeEvent(image1, NODE_IMAGE_ON_ERROR, 0, nullptr);
```

### Listening for SVG Playback Completion Event

Use the [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent) API on the image node to register the **NODE_IMAGE_ON_SVG_PLAY_FINISH** playback completion event, which is triggered when the SVG animation playback ends.

<!-- @[image_svg_complete](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// SVG playback completion event handling.
void HandleSvgPlayFinish(ArkUI_NodeEvent* event)
{
    OH_LOG_INFO(LOG_APP, "SVG animation play finished");
}
```

<!-- @[register_svg_play_component](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Register the SVG play finish event.
nativeNodeApi->registerNodeEvent(image1, NODE_IMAGE_ON_SVG_PLAY_FINISH, 0, nullptr);
```

### Unregistering event listeners

When you no longer need to listen for image events, you need to unregister the events registered on the node and the global event receiver.

<!-- @[unregister_node_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// Unregister the event listener.
nativeNodeApi->unregisterNodeEvent(image1, NODE_IMAGE_ON_COMPLETE);
nativeNodeApi->unregisterNodeEvent(image1, NODE_IMAGE_ON_ERROR);
nativeNodeApi->unregisterNodeEvent(image1, NODE_IMAGE_ON_SVG_PLAY_FINISH);

// Unregister the global event receiver.
nativeNodeApi->unregisterNodeEventReceiver();
```

## Complete Example

<!--RP2-->

[Display Image (Image)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/ImageCAPIGuide)

<!--RP2End-->