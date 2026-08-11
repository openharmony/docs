# 显示图片（Image）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wu-yinxiao-->
<!--Designer: @liyujie43-->
<!--Tester: @wu-yinxiao-->
<!--Adviser: @Brilliantry_Rui-->

从API version 12开始，ArkUI开发框架在NDK接口提供了Image组件，用于在应用中显示图片。Image组件支持多种图片格式，包括png、jpg、jpeg、bmp、webp、heif、SVG等格式，支持多种图片来源（本地资源、网络图片、PixelMap等）和丰富的图片处理功能（缩放、插值、填充颜色、颜色滤镜等）。开发者可以在Native层创建Image组件并设置各种属性，实现高性能的图片展示效果，以及与ArkTS侧Image组件相同的显示效果，ArkTS开发指导请参考[显示图片 (Image)](arkts-graphics-display.md)。

## 约束与限制

1. **线程安全**：所有UI相关接口必须在主线程调用，多线程操作可能导致应用崩溃。
2. **组件挂载**：组件创建后需要通过[addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild)添加到父节点才能显示。
3. **图片路径**：
   - 本地图片需使用完整路径或相对路径。
   - 网络图片需申请`ohos.permission.INTERNET`权限。
4. **资源释放**：释放组件时需要调用[disposeNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#disposenode)来避免内存泄漏。
5. **同步加载**：不建议在图片加载较长时间时使用同步加载，会导致页面无法响应。

## 前置条件

在开始使用Image组件前，需要先完成以下准备工作：

1. 创建Native C++工程：在DevEco Studio中创建Native C++模板项目。
2. 接入ArkTS页面：按照[接入ArkTS页面](ndk-access-the-arkts-page.md)完成Native组件到ArkTS页面的挂载配置。
3. 添加依赖：打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libace_ndk.z.so、libace_napi.z.so以及日志依赖libhilog_ndk.z.so。

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
        libace_napi.z.so      # NAPI接口
        libace_ndk.z.so       # ArkUI NDK
        libhilog_ndk.z.so     # 日志
    )
    ```

4. 添加头文件引用。

    <!-- @[image_headfiles](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->
    
    ``` C++
    #include <arkui/native_node.h>
    #include <arkui/native_type.h>
    #include <arkui/native_interface.h>
    #include <hilog/log.h>
    ```

5. 准备图片资源：准备需要显示的图片文件，Image组件支持多种图片来源，以下介绍常用的资源准备方式。

   - 使用rawfile资源

    将图片文件放到`entry/src/main/resources/rawfile/`目录下，在代码中使用相对路径引用。

    <!-- @[image_source_rawfile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

    ``` C++
    // 设置图片源（使用rawfile资源）
    ArkUI_AttributeItem srcItem = {nullptr, 0, "resource://RAWFILE/clouds.jpg"};
    nativeNodeApi->setAttribute(image1, NODE_IMAGE_SRC, &srcItem);
    ```

   - 使用网络图片

    在`entry/src/main/module.json5`中添加网络权限，在代码中直接使用网络URL。

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

## 创建Image组件

### 创建并初始化Image组件

在使用Image组件之前，需要先获取nativeNodeApi，然后使用[createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode)接口创建Image组件。

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
// 创建Image组件1 - 基础图片
ArkUI_NodeHandle image1 = nativeNodeApi->createNode(ARKUI_NODE_IMAGE);
```

### 设置图片源

Image组件支持通过字符串路径或[DrawableDescriptor](../reference/apis-arkui/js-apis-arkui-drawableDescriptor.md)对象设置图片源。

<!-- @[image_source_rawfile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置图片源（使用rawfile资源）
ArkUI_AttributeItem srcItem = {nullptr, 0, "resource://RAWFILE/clouds.jpg"};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_SRC, &srcItem);
```

## 设置图片属性

### Image属性

Image独有属性如下，具体说明请参考[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的枚举定义。

| 属性名 | 说明 | 起始版本 |
|-------|--------|---------|
| NODE_IMAGE_SRC | 支持字符串路径或DrawableDescriptor。 | 12 |
| NODE_IMAGE_OBJECT_FIT | 控制图片如何适应容器。 | 12 |
| NODE_IMAGE_INTERPOLATION | 图片放大时的插值质量。 | 12 |
| NODE_IMAGE_OBJECT_REPEAT | 图片平铺方式。 | 12 |
| NODE_IMAGE_COLOR_FILTER | 5x4颜色矩阵。 | 12 |
| NODE_IMAGE_AUTO_RESIZE | 是否自动调整图片源大小。 | 12 |
| NODE_IMAGE_ALT | 加载失败时显示的图片。 | 12 |
| NODE_IMAGE_DRAGGABLE | 是否支持拖拽。 | 12 |
| NODE_IMAGE_RENDER_MODE | 原色或黑白模式。 | 12 |
| NODE_IMAGE_FIT_ORIGINAL_SIZE | 显示大小是否跟随图片源尺寸。 | 12 |
| NODE_IMAGE_FILL_COLOR | SVG图片填充颜色。 | 12 |
| NODE_IMAGE_RESIZABLE | 图片拉伸时的边缘处理。 | 12 |
| NODE_IMAGE_SYNC_LOAD | 是否同步加载图片。 | 20 |
| NODE_IMAGE_SOURCE_SIZE | 设置图片解码尺寸。 | 21 |
| NODE_IMAGE_IMAGE_MATRIX | 图片仿射变换矩阵。 | 21 |
| NODE_IMAGE_MATCH_TEXT_DIRECTION | 是否跟随文本方向。 | 21 |
| NODE_IMAGE_COPY_OPTION | 图片是否可复制。 | 21 |
| NODE_IMAGE_ENABLE_ANALYZER | 是否启用AI分析。 | 21 |
| NODE_IMAGE_DYNAMIC_RANGE_MODE | HDR显示模式。 | 21 |
| NODE_IMAGE_HDR_BRIGHTNESS | HDR图片亮度。 | 21 |
| NODE_IMAGE_ORIENTATION | 图片旋转方向。 | 21 |
| NODE_IMAGE_SUPPORT_SVG2 | SVG解析能力范围。 | 21 |
| NODE_IMAGE_CONTENT_TRANSITION | 图片内容变换动画。 | 21 |
| NODE_IMAGE_ALT_PLACEHOLDER | 加载过程中显示的占位图。 | 22 |
| NODE_IMAGE_ALT_ERROR | 加载失败时显示的占位图。 | 22 |


### 设置图片缩放类型

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_OBJECT_FIT属性设置图片在容器中的缩放方式。

<!-- @[image_zoom](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置缩放类型
ArkUI_NumberValue fitValue[] = {{.i32 = ARKUI_OBJECT_FIT_COVER}};
ArkUI_AttributeItem fitItem = {fitValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_OBJECT_FIT, &fitItem);
```

### 设置图片插值效果

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_INTERPOLATION属性设置图片插值效果。

<!-- @[image_interpolation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置插值效果
ArkUI_NumberValue interpolationValue[] = {{.i32 = ARKUI_IMAGE_INTERPOLATION_HIGH}};
ArkUI_AttributeItem interpolationItem = {interpolationValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_INTERPOLATION, &interpolationItem);
```

### 设置图片重复样式

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_OBJECT_REPEAT属性设置图片重复样式。

<!-- @[image_repeat](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置重复样式
ArkUI_NumberValue repeatValue[] = {{.i32 = ARKUI_IMAGE_REPEAT_NONE}};
ArkUI_AttributeItem repeatItem = {repeatValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_OBJECT_REPEAT, &repeatItem);
```

### 设置图片填充颜色

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_FILL_COLOR属性设置SVG图片填充颜色。

<!-- @[image_fillcolor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置填充颜色（蓝色）
ArkUI_NumberValue fillColorValue[] = {{.u32 = 0xFF007DFF}};
ArkUI_AttributeItem fillColorItem = {fillColorValue, 1};
nativeNodeApi->setAttribute(image2, NODE_IMAGE_FILL_COLOR, &fillColorItem);
```

### 设置占位图

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_ALT属性设置占位图。

<!-- @[image_alt_source](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置占位图
ArkUI_AttributeItem altItem = {nullptr, 0, "/data/storage/el2/base/haps/entry/files/placeholder.png"};
nativeNodeApi->setAttribute(image3, NODE_IMAGE_ALT, &altItem);
```

### 设置图片解码尺寸

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_SOURCE_SIZE属性设置图片解码尺寸。

<!-- @[image_decode_size](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置解码尺寸
ArkUI_NumberValue sourceSizeValue[] = {{.i32 = 150}, {.i32 = 150}};
ArkUI_AttributeItem sourceSizeItem = {sourceSizeValue, 2};
nativeNodeApi->setAttribute(image3, NODE_IMAGE_SOURCE_SIZE, &sourceSizeItem);
```

### 设置图片渲染模式

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_RENDER_MODE属性设置图片渲染模式。

<!-- @[image_render](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置渲染模式
ArkUI_NumberValue renderModeValue[] = {{.i32 = ARKUI_IMAGE_RENDER_MODE_ORIGINAL}};
ArkUI_AttributeItem renderModeItem = {renderModeValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_RENDER_MODE, &renderModeItem);
```

### 设置同步加载

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_SYNC_LOAD属性设置图片的同步或异步加载方式。

<!-- @[image_load_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置同步加载
ArkUI_NumberValue syncLoadValue[] = {{.i32 = 1}};
ArkUI_AttributeItem syncLoadItem = {syncLoadValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_SYNC_LOAD, &syncLoadItem);
```

### 设置图片颜色滤镜

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_COLOR_FILTER属性设置图片颜色滤镜。

<!-- @[image_color_filter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置颜色滤镜（5x4矩阵，共20个浮点数）
// 矩阵格式：每行5个元素分别表示 R、G、B、A 的系数和偏移量
// 行1: R行 - R_new = R*1 + G*0 + B*0 + A*0 + offset*0 = R
// 行2: G行 - G_new = R*0 + G*1 + B*0 + A*0 + offset*0 = G
// 行3: B行 - B_new = R*0 + G*0 + B*1 + A*0 + offset*0 = B
// 行4: A行 - A_new = R*0 + G*0 + B*0 + A*1 + offset*0 = A
// 示例矩阵为恒等矩阵，即不改变颜色
float colorFilterMatrix[20] = {
    1.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // R行: R、G、B、A的系数及偏移量
    0.0f, 1.0f, 0.0f, 0.0f, 0.0f,  // G行: R、G、B、A的系数及偏移量
    0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // B行: R、G、B、A的系数及偏移量
    0.0f, 0.0f, 0.0f, 1.0f, 0.0f   // A行: R、G、B、A的系数及偏移量
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

### 设置图片显示方向

通过[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)中的NODE_IMAGE_ORIENTATION属性设置图片显示方向。

<!-- @[image_orientation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 设置图片显示方向
ArkUI_NumberValue orientationValue[] = {{.i32 = ARKUI_ORIENTATION_UP}};
ArkUI_AttributeItem orientationItem = {orientationValue, 1};
nativeNodeApi->setAttribute(image1, NODE_IMAGE_ORIENTATION, &orientationItem);
```

## 监听图片事件

通过注册全局事件接收器接收所有节点事件，并在具体节点上通过[ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)中的NODE_IMAGE_ON_COMPLETE，NODE_IMAGE_ON_ERROR，NODE_IMAGE_ON_SVG_PLAY_FINISH和NODE_IMAGE_ON_DOWNLOAD_PROGRESS接口来注册特定事件来实现图片事件的监听。

### 注册全局事件接收器

在处理图片事件之前，需要先通过[registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver)接口注册全局事件接收器。

<!-- @[event_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 全局事件接收器函数
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
// 注册全局事件接收器
nativeNodeApi->registerNodeEventReceiver(GlobalEventReceiver);
```

### 监听图片加载完成事件

在图片节点上使用[registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)接口注册加载NODE_IMAGE_ON_COMPLETE完成事件，当图片加载成功后触发该事件，事件回调中可获取图片尺寸信息。

<!-- @[image_load_complete](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 图片加载完成事件处理
void HandleImageComplete(ArkUI_NodeEvent* event)
{
    // 使用函数获取 componentEvent
    ArkUI_NodeComponentEvent* componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
    if (componentEvent == nullptr) {
        OH_LOG_ERROR(LOG_APP, "Get component event failed");
        return;
    }

    // 获取图片信息
    float width = componentEvent->data[0].f32;           // 图片原始宽度
    float height = componentEvent->data[1].f32;          // 图片原始高度
    float componentWidth = componentEvent->data[2].f32;  // 组件宽度
    float componentHeight = componentEvent->data[3].f32; // 组件高度
    float contentWidth = componentEvent->data[4].f32;    // 渲染内容宽度
    float contentHeight = componentEvent->data[5].f32;   // 渲染内容高度

    OH_LOG_INFO(LOG_APP, "Image loaded: %.0fx%.0f, component: %.0fx%.0f",
                width, height, componentWidth, componentHeight);
}
```

<!-- @[register_image_load_complete](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 注册图片加载完成事件
nativeNodeApi->registerNodeEvent(image1, NODE_IMAGE_ON_COMPLETE, 0, nullptr);
```

### 监听图片加载失败事件

在图片节点上使用[registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)接口注册加载NODE_IMAGE_ON_ERROR失败事件，当图片加载失败时触发该事件，事件回调中可获取错误码信息。

<!-- @[image_load_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 图片加载失败事件处理
void HandleImageError(ArkUI_NodeEvent* event)
{
    ArkUI_NodeComponentEvent* componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
    if (componentEvent == nullptr) {
        OH_LOG_ERROR(LOG_APP, "Get component event failed");
        return;
    }

    int32_t errorCode = componentEvent->data[0].i32;
    // 401: 图片路径无效
    OH_LOG_ERROR(LOG_APP, "Image load failed, error code: %d", errorCode);
}
```

<!-- @[register_image_load_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 注册图片加载失败事件
nativeNodeApi->registerNodeEvent(image1, NODE_IMAGE_ON_ERROR, 0, nullptr);
```
### 监听SVG播放完成事件

在图片节点上使用[registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)接口注册NODE_IMAGE_ON_SVG_PLAY_FINISH播放完成事件，当SVG动画播放结束时触发该事件。

<!-- @[image_svg_complete](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// SVG播放完成事件处理
void HandleSvgPlayFinish(ArkUI_NodeEvent* event)
{
    OH_LOG_INFO(LOG_APP, "SVG animation play finished");
}
```

<!-- @[register_svg_play_component](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 注册SVG播放完成事件
nativeNodeApi->registerNodeEvent(image1, NODE_IMAGE_ON_SVG_PLAY_FINISH, 0, nullptr);
```

### 注销事件监听

当不再需要监听图片事件时，需要注销在节点上注册的事件以及全局事件接收器。

<!-- @[unregister_node_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ImageCAPIGuide/entry/src/main/cpp/ImageExample.cpp) -->

``` C++
// 注销事件监听
nativeNodeApi->unregisterNodeEvent(image1, NODE_IMAGE_ON_COMPLETE);
nativeNodeApi->unregisterNodeEvent(image1, NODE_IMAGE_ON_ERROR);
nativeNodeApi->unregisterNodeEvent(image1, NODE_IMAGE_ON_SVG_PLAY_FINISH);

// 注销全局事件接收器
nativeNodeApi->unregisterNodeEventReceiver();
```

## 完整示例

<!--RP2-->
[显示图片（Image）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/ImageCAPIGuide)
<!--RP2End-->