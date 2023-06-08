# 小型系统图形框架集成指导

当前，小型系统图形模块以子系统的形式在 OpenHarmony 中运行。开发者只需适配实现OpenHarmony HDF 层 API 即可。由于使用场景不同，图形子系统也支持在不同平台集成运行。例如，在 Windows/Mac 上开发应用程序时，可以使用 QT Creator 进行简单的页面布局、开发和调试。此时，图形子系统已经适配到了 Windows/Mac 平台上运行。如果想要将图形子系统独立集成到现有项目中，则需要进行一些简单的适配工作，并分为以下几个主要部分：

1. 引擎初始化
2. 显示设备适配
3. 输入设备适配
4. 字体初始化
5. 屏幕刷新对接

具体步骤如下，步骤最后有参考示例代码，具体可参照 [OpenHarmony 小型系统图形 Simulator 适配实现](https://gitee.com/openharmony/arkui_ui_lite/tree/master/tools/qt/simulator)。

### 图形引擎初始化
主要包括初始化 UI 任务、渲染模块、动画模块、默认样式等
```c++
// graphic_startup.h
GraphicStartUp::Init();
```

### 显示设备适配

主要包括设置屏幕大小，对接基础图元绘制，获取图形绘制的 buffer，把图形绘制的数据刷到屏幕上显示等。

显示层适配根据硬件绘制和软件绘制不同，需继承实现不同的类。其中 [gfx_engine_manager.h](https://gitee.com/openharmony/arkui_ui_lite/blob/master/interfaces/innerkits/engines/gfx/gfx_engine_manager.h) 中的 BaseGfxEngine 类为纯虚实现，只定义了接口，不含任何实现，适合作为自行实现的硬件绘制的父类；[soft_engine.h](https://gitee.com/openharmony/arkui_ui_lite/blob/master/interfaces/innerkits/engines/gfx/soft_engine.h) 中的 SoftEngine 继承自 BaseGfxEngine，对 BaseGfxEngine 的接口进行了软件层实现，适合作为软件绘制的父类。

BaseGfxEngine 类中有3类接口：

第一类：获取显存、申请缓存、释放缓存；

第二类：绘制类基础接口，例如：画线、Blit、Fill 等；

第三类：送显接口，调用该接口完成把绘制内容送显。

其中获取显存和送显接口为移植不同平台必须实现的，第二类接口，图形 UI 框架有默认软件实现，具体在 soft_engine.h 的 SoftEngine 中，软件绘制可继承 SoftEngine 进行功能拓展；不同平台如有硬件加速，例如 DMA2D，可继承 gfx_engine_manager.h 的 BaseGfxEngine，对其纯虚方法进行全部实现后，进行扩展性适配。

图形对接接口代码如下：
```c++
// gfx_engine_manager.h
virtual void DrawArc(BufferInfo& dst,
                        ArcInfo& arcInfo,
                        const Rect& mask,
                        const Style& style,
                        OpacityType opacity,
                        uint8_t cap) = 0;

virtual void DrawLine(BufferInfo& dst,
                        const Point& start,
                        const Point& end,
                        const Rect& mask,
                        int16_t width,
                        ColorType color,
                        OpacityType opacity) = 0;

virtual void DrawLetter(BufferInfo& gfxDstBuffer,
                        const uint8_t* fontMap,
                        const Rect& fontRect,
                        const Rect& subRect,
                        const uint8_t fontWeight,
                        const ColorType& color,
                        const OpacityType opa) = 0;

virtual void DrawCubicBezier(BufferInfo& dst,
                                const Point& start,
                                const Point& control1,
                                const Point& control2,
                                const Point& end,
                                const Rect& mask,
                                int16_t width,
                                ColorType color,
                                OpacityType opacity) = 0;

virtual void
    DrawRect(BufferInfo& dst, const Rect& rect, const Rect& dirtyRect, const Style& style, OpacityType opacity) = 0;

virtual void DrawTransform(BufferInfo& dst,
                            const Rect& mask,
                            const Point& position,
                            ColorType color,
                            OpacityType opacity,
                            const TransformMap& transMap,
                            const TransformDataInfo& dataInfo) = 0;

// x/y: center of a circle
virtual void ClipCircle(const ImageInfo* info, float x, float y, float radius) = 0;

virtual void Blit(BufferInfo& dst,
                    const Point& dstPos,
                    const BufferInfo& src,
                    const Rect& subRect,
                    const BlendOption& blendOption) = 0;

virtual void Fill(BufferInfo& dst, const Rect& fillArea, const ColorType color, const OpacityType opacity) = 0;

virtual void DrawPath(BufferInfo& dst,
                        void* param,
                        const Paint& paint,
                        const Rect& rect,
                        const Rect& invalidatedArea,
                        const Style& style) = 0;

virtual void FillPath(BufferInfo& dst,
                        void* param,
                        const Paint& paint,
                        const Rect& rect,
                        const Rect& invalidatedArea,
                        const Style& style) = 0;

virtual uint8_t* AllocBuffer(uint32_t size, uint32_t usage) = 0;

virtual void FreeBuffer(uint8_t* buffer, uint32_t usage) = 0;

virtual BufferInfo* GetFBBufferInfo()
{
    return nullptr;
}

virtual void AdjustLineStride(BufferInfo& info) {}

virtual void Flush(const Rect& flushRect) {}

virtual uint16_t GetScreenWidth()
{
    return screenWidth_;
}

virtual uint16_t GetScreenHeight()
{
    return screenHeight_;
}

virtual void SetScreenShape(ScreenShape screenShape)
{
    screenShape_ = screenShape;
}

virtual ScreenShape GetScreenShape()
{
    return screenShape_;
}
```

### 输入设备适配

图形框架支持触摸、按键和旋转设备。当前所有输入设备都需要继承 InputDevice 实现 Read 接口。

触摸输入继承 PointerInputDevice 类实现 Read 接口，需要返回 x/y 坐标和按压状态；

按键输入继承 KeyInputDevice 类实现 Read 接口，需要设置 keyId 和按键状态；

旋转输入继承 RotateInputDevice 类实现 Read 接口，需要设置 rotate 值。

InputDevice 设备对接实例代码如下：

```c++
// input_device.h Read 接口
/**
 * @brief Read data from hardware.User should override this to set data *
 * @param [out] input device data. *
 * @returns no more data to read if true.
 */
virtual bool Read(DeviceData& data) = 0;

// 继承实现 InputDevice 基类的 Read 接口，以触摸事件对接为例，示例代码如下：
class TouchInput : public OHOS::PointerInputDevice {
public:
    TouchInput() {}
    virtual TouchInput() {}
    // implements read fouction
    bool Read(OHOS::DeviceData& data) override
    {
        // set position and state, you should update the value when touch
        data.point.x = g_lastX;
        data.point.y = g_lastY;
        data.state = g_leftButtonDown ? STATE_PRESS : STATE_RELEASE;
        return false;
    }
};
```



### 字体初始化

字体分为点阵字体和矢量字体。

点阵字体：需要使用字体打包工具生成对应字体 font.bin 文件，工具支持打包中英文字体，详细支持字号和 fontId 可以在工具生成的 ui_text_language.h 中查看。

矢量字体：默认注册了 DEFAULT_VECTOR_FONT_FILENAME，假如想使用其他字体，可以调用 RegisterFontInfo 注册其他字体文件。矢量字体解析和布局需要依赖三方开源软件 freetype 和 icu，假如想支持阿拉伯语等复杂语言需要依赖三软件 harfbuzz，同时打开 ENABLE_SHAPING 和 ENABLE_ICU。

字体初始化接口代码如下：

```c++
// graphic_config.h
#define DEFAULT_VECTOR_FONT_FILENAME      "SourceHanSansSC-Regular.otf"
// 矢量字体开关
#define ENABLE_VECTOR_FONT                1
// 点阵字体开关
#define ENABLE_BITMAP_FONT                0
#define ENABLE_ICU                        0
#define ENABLE_SHAPING                    0

// ui_font.h
uint8_t RegisterFontInfo(const char* ttfName, uint8_t shaping = 0)

// graphic_startup.h
static void InitFontEngine(uintptr_t psramAddr, uint32_t psramLen, const char* dPath, const char* ttfName);
```

### 屏幕刷新对接

根据屏幕硬件刷新信号（类似 Vsync 信号），周期性回调 TaskHandler

屏幕刷新对接接口代码如下：

```c++
TaskManager::GetInstance()->TaskHandler();
```

### 图形适配示例代码

对接相关宏定义说明如下：

```c++
// graphic_config.h
// 默认定义了不同级别设备宏定义，轻设备请启动 VERSION_LITE 宏
/**
 * Defines three graphics library versions: lightweight, standard, and extended versions.
 * The three versions have different requirements on the memory and hardware.
 * The standard version is enabled by default.
 *
 * The macros of the versions are defined as follows:
 * Name                | Version Description
 * ------------------- | ----------
 * VERSION_LITE        | Lightweight version
 * VERSION_STANDARD    | Standard version
 * VERSION_EXTENDED    | Extended version
 */
#ifdef _LITEOS
#define VERSION_LITE
#elif defined _WIN32 || defined __APPLE__
#define VERSION_LITE
#else
#define VERSION_STANDARD
#endif

// 关闭窗口合成，打开需要依赖 wms 窗口合成服务
/**
 * @brief Multi-window, which is disabled by default on WIN32.
 */
#define ENABLE_WINDOW                     0

// 关闭 png、jpeg 格式图片支持，打开需要引入三方库
#define ENABLE_JPEG_AND_PNG               0

// 硬件加速，关闭默认走CPU软绘制，可以先关闭，界面显示后再打开适配硬件能力
/**
 * @brief Graphics rendering hardware acceleration, which is disabled by default on WIN32.
 */
#define ENABLE_HARDWARE_ACCELERATION     0
```

对接示例代码如下：

```c++
using namespace OHOS;

int main(int argc, char** argv)
{
    // init graphic
    GraphicStartUp::Init();

    // init display/input device
    InitHal();

    // init font engine
    InitFontEngine();

    // run your app code
    RunApp();

    // use while loop to simulate hardware flush callback
    // you should call *TaskHandler* in screen flush signal callback(like Vsync).
    while (1) {
        TaskManager::GetInstance()->TaskHandler();
        Sleep(DEFAULT_TASK_PERIOD);
    }
    return 0;
}

// assuming below are the memory pool
static uint8_t g_fontPsramBaseAddr[MIN_FONT_PSRAM_LENGTH];
#if ENABLE_SHAPING
static uint8_t g_shapePsramBaseAddr[MIN_SHAPING_PSRAM_LENGTH];
#else
static uint8_t* g_shapePsramBaseAddr = nullptr;
#endif

static void InitFontEngine()

{
#if ENABLE_VECTOR_FONT
    GraphicStartUp::InitFontEngine(reinterpret_cast<uintptr_t>(g_fontMemBaseAddr), MIN_FONT_PSRAM_LENGTH, VECTOR_FONT_DIR, DEFAULT_VECTOR_FONT_FILENAME);
#else
    BitmapFontInit();
    std::string dPath(_pgmptr);
    size_t len = dPath.size();
    size_t pos = dPath.find_last_of('\\');
    dPath.replace((pos + 1), (len - pos), "..\\..\\simulator\\font\\font.bin");
    GraphicStartUp::InitFontEngine(reinterpret_cast<uintptr_t>(g_fontMemBaseAddr), MIN_FONT_PSRAM_LENGTH, dPath.c_str(), nullptr);
#endif

#if ENABLE_ICU
    GraphicStartUp::InitLineBreakEngine(reinterpret_cast<uintptr_t>(g_icuMemBaseAddr), SHAPING_WORD_DICT_LENGTH,
 VECTOR_FONT_DIR, DEFAULT_LINE_BREAK_RULE_FILENAME);
#endif
}

// display adaptor
class SDLMonitorGfxEngine : public BaseGfxEngine {
public:
    BufferInfo* GetFBBufferInfo() override
    {
        static BufferInfo* bufferInfo = nullptr;
        if (bufferInfo == nullptr) {
            bufferInfo = new BufferInfo;
            bufferInfo->rect = {0, 0, HORIZONTAL_RESOLUTION - 1, VERTICAL_RESOLUTION - 1};
            bufferInfo->mode = ARGB8888;
            bufferInfo->color = 0x44;
            bufferInfo->virAddr = GetFramBuff();
            bufferInfo->phyAddr = bufferInfo->virAddr;
            // 4: bpp
            bufferInfo->stride = HORIZONTAL_RESOLUTION * 4;
            bufferInfo->width = HORIZONTAL_RESOLUTION;
            bufferInfo->height = VERTICAL_RESOLUTION;
        }

        return bufferInfo;
    }

    void Flush() override
    {
        MonitorRenderFinish();
    }
};

class TouchInput : public OHOS::PointerInputDevice {
public:
    TouchInput() {}
    virtual TouchInput() {}

    // implements read function
    bool Read(OHOS::DeviceData& data) override
    {
        // set position x,y and state, you should update the
        // g_lastX/g_lastY/g_leftButtonDown when touch
        data.point.x = g_lastX;
        data.point.y = g_lastY;
        data.state = g_leftButtonDown ? STATE_PRESS : STATE_RELEASE;

        return false;
    }
};

class KeyInput : public OHOS::KeyInputDevice {
public:
    KeyInput();
    virtual ~KeyInput() {}

    // implements read fouction
    bool Read(OHOS::DeviceData& data) override
    {
        data.keyId = g_lastKeyId;
        data.state = g_lastState;
        g_lastState = INVALID_KEY_STATE;
        return false;
    }
};

// other device if you need to add
class XXInput : public OHOS::XXInputDevice {
public:
    KeyInput();
    virtual ~KeyInput() {}

    // implements read fouction
    bool Read(OHOS::DeviceData& data) override
    {
        // set device data info
    }
};

static void InitHal()
{
    // Setup gfxengine
    BaseGfxEngine::GetInstance()->InitEngine(new SDLMonitorGfxEngine());

    // Setup touch device
    TouchInput* touch = new TouchInput();
    InputDeviceManager::GetInstance()->Add(touch);

    // Setup key device if you need
    KeyInput* key = new KeyInput();
    InputDeviceManager::GetInstance()->Add(key);

    // Setup xx device if you need
    XXInput* inputXX = new XXInput();
    InputDeviceManager::GetInstance()->Add(inputXX);
}
```
