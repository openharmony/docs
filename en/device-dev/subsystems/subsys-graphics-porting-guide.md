# Small-System Graphics Framework Integration

The small-system graphics modules run in OpenHarmony as a framework. Therefore, you only need to adapt to and implement APIs at the OpenHarmony HDF layer. The graphics subsystem can run on different platforms. For example, when developing an application on Windows or macOS, you can use Qt Creator for simple page layout, development, and debugging. The graphics framework has been adapted to the Windows and macOS platforms. To integrate the graphics framework into an existing project independently, you need to carry out the following adaptation operations:

1. Initialize the graphics engine.
2. Adapt to the display.
3. Adapt to the input device.
4. Initialize the font engine.
5. Interconnect to screen flush.

For details, see [OpenHarmony Small-System Graphics Simulator Adaptation Implementation](https://gitee.com/openharmony/arkui_ui_lite/tree/master/tools/qt/simulator).

### Initializing the Graphics Engine
Initialize UI tasks, rendering modules, animation modules, and default styles.
```c++
// graphic_startup.h
GraphicStartUp::Init();
```

### Adapting to the Display

Set the screen size, connect to basic component rendering, obtain the graphics rendering buffer, and refresh the graphics rendering data to the screen for display.

During display layer adaptation, note that the classes to inherit and implement vary according to hardware rendering and software rendering. The **BaseGfxEngine** class in [gfx_engine_manager.h](https://gitee.com/openharmony/arkui_ui_lite/blob/master/interfaces/innerkits/engines/gfx/gfx_engine_manager.h) is a pure virtual implementation. It defines only functions and does not contain any implementation. It can be used as the parent class of hardware rendering. The **SoftEngine** class in [soft_engine.h](https://gitee.com/openharmony/arkui_ui_lite/blob/master/interfaces/innerkits/engines/gfx/soft_engine.h) inherits from **BaseGfxEngine** and implements the functions of **BaseGfxEngine** at the software layer. It can be used as the parent class of software rendering.

The **BaseGfxEngine** class has three types of functions:

Type 1: functions used to obtain the display memory, apply for the buffer, and release the buffer.

Type 2: basic rendering functions, such as line drawing, **Blit**, and **Fill**.

Type 3: display functions, which are called to send the rendered content to the display.

The functions for obtaining the display memory and the display functions must be implemented for different platforms. The second type of function is implemented by software by default in the graphics UI framework, that is, **SoftEngine** of **soft_engine.h**. You can inherit from **SoftEngine** to extend software rendering. If hardware acceleration is required on different platforms, for example, DMA2D, you can inherit from **BaseGfxEngine** of **gfx_engine_manager.h**, implement all pure virtual functions, and carry out scalability adaptation.

The code for interconnecting to the graphics functions is as follows:
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

### Adapting to the Input Device

The graphics framework supports touch, key, and rotation devices. Currently, you must inherit from **InputDevice** to implement the **Read** function for all input devices.

For touch devices, inherit from the **PointerInputDevice** class to implement the **Read** function. The x and y coordinates and pressed status need to be returned.

For key input devices, inherit from the **KeyInputDevice** class to implement the **Read** function. The key ID and key status need to be set.

For rotation input devices, inherit from the **RotateInputDevice** class to implement the **Read** function. The rotate value needs to be set.

The code for interconnecting to the **InputDevice** instance is as follows:

```c++
// Read function in input_device.h
/**
 * @brief Reads data from hardware. You should override this to set data. *
 * @param [out] Indicates device data. *
 * @returns Returns no more data to read if true.
 */
virtual bool Read(DeviceData& data) = 0;

// Inherit from and implement the Read function of the InputDevice base class. The following uses a touch event as an example:
class TouchInput : public OHOS::PointerInputDevice {
public:
    TouchInput() {}
    virtual TouchInput() {}
    // Implement the read function.
    bool Read(OHOS::DeviceData& data) override
    {
        // Set the position and state. You should update the value when it is being touched.
        data.point.x = g_lastX;
        data.point.y = g_lastY;
        data.state = g_leftButtonDown ? STATE_PRESS : STATE_RELEASE;
        return false;
    }
};
```



### Initializing the Font Engine

Fonts are classified into dot matrix fonts and vector fonts.

For dot matrix fonts, use the font packaging tool to generate a **font.bin** file. The tool supports packaging of Chinese and English fonts. For details about the supported font sizes and font IDs, see **ui_text_language.h** generated by the tool.

For vector fonts, **DEFAULT_VECTOR_FONT_FILENAME** is registered by default. To use other fonts, call **RegisterFontInfo** to register the required font files. Vector font parsing and layout depend on the third-party open-source software FreeType and ICU. To support complex languages such as Arabic, you must introduce the third-party open-source software HarfBuzz and enable **ENABLE_SHAPING** and **ENABLE_ICU**.

The code of font engine initialization is as follows:

```c++
// graphic_config.h
#define DEFAULT_VECTOR_FONT_FILENAME      "SourceHanSansSC-Regular.otf"
// Vector font switch
#define ENABLE_VECTOR_FONT                1
// Dot-matrix font switch
#define ENABLE_BITMAP_FONT                0
#define ENABLE_ICU                        0
#define ENABLE_SHAPING                    0

// ui_font.h
uint8_t RegisterFontInfo(const char* ttfName, uint8_t shaping = 0)

// graphic_startup.h
static void InitFontEngine(uintptr_t psramAddr, uint32_t psramLen, const char* dPath, const char* ttfName);
```

### Interconnecting to Screen Flush

Periodically call **TaskHandler** based on the screen hardware refresh signal (similar to Vsync).

The code for interconnecting to screen flush is as follows:

```c++
TaskManager::GetInstance()->TaskHandler();
```

### Sample Code

The macro definitions related to interconnection are described as follows:

```c++
// graphic_config.h
// By default, macro definitions of different levels of devices are defined. For lightweight devices, enable the VERSION_LITE macro.
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

// Disable window synthesis. Enabling window synthesis depends on the WMS window synthesis service.
/**
 * @brief Multi-window, which is disabled by default on WIN32.
 */
#define ENABLE_WINDOW                     0

// Disable the support for images in PNG and JPEG formats. To enable the support, introduce a third-party library.
#define ENABLE_JPEG_AND_PNG               0

// Hardware acceleration. If hardware acceleration is disabled, CPU soft rendering is used by default. You can disable this feature first and enable it after the page is displayed.
/**
 * @brief Graphics rendering hardware acceleration, which is disabled by default on WIN32.
 */
#define ENABLE_HARDWARE_ACCELERATION     0
```

The code snippet is as follows:

```c++
using namespace OHOS;

int main(int argc, char** argv)
{
    // Initialize the graphic engine.
    GraphicStartUp::Init();

    // Initialize the display and input device.
    InitHal();

    // Initialize the font engine.
    InitFontEngine();

    // Run your application code.
    RunApp();

    // Use while loop to simulate the hardware flush callback.
    // You should call *TaskHandler* in screen flush signal callback (like Vsync).
    while (1) {
        TaskManager::GetInstance()->TaskHandler();
        Sleep(DEFAULT_TASK_PERIOD);
    }
    return 0;
}

// Below is the memory pool.
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

// Display adapter
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

    // Implement the read function.
    bool Read(OHOS::DeviceData& data) override
    {
        // Set the position x, y, and state. You should update the
        // g_lastX/g_lastY/g_leftButtonDown when it is being touched.
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

    // Implement the read function.
    bool Read(OHOS::DeviceData& data) override
    {
        data.keyId = g_lastKeyId;
        data.state = g_lastState;
        g_lastState = INVALID_KEY_STATE;
        return false;
    }
};

// Other device to add, if required.
class XXInput : public OHOS::XXInputDevice {
public:
    KeyInput();
    virtual ~KeyInput() {}

    // Implement the read function.
    bool Read(OHOS::DeviceData& data) override
    {
        // Set the device data information.
    }
};

static void InitHal()
{
    // Set up the GFX engine.
    BaseGfxEngine::GetInstance()->InitEngine(new SDLMonitorGfxEngine());

    // Set up the touch device.
    TouchInput* touch = new TouchInput();
    InputDeviceManager::GetInstance()->Add(touch);

    // Set up the key device if required.
    KeyInput* key = new KeyInput();
    InputDeviceManager::GetInstance()->Add(key);

    // Set up xx device if required.
    XXInput* inputXX = new XXInput();
    InputDeviceManager::GetInstance()->Add(inputXX);
}
```
