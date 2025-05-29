# 拍照开发指导<a name="ZH-CN_TOPIC_0000001054915940"></a>

-   [使用场景](#zh-cn_topic_0000001052170554_section1963312376119)
-   [接口说明](#zh-cn_topic_0000001052170554_section56549532016)
-   [约束与限制](#zh-cn_topic_0000001052170554_section1165911177314)
-   [开发步骤](#zh-cn_topic_0000001052170554_section138543918214)

## 使用场景<a name="zh-cn_topic_0000001052170554_section1963312376119"></a>

使用Camera产生图片帧（拍照）。

## 接口说明<a name="zh-cn_topic_0000001052170554_section56549532016"></a>

**表 1**  API列表

| 类名  | 接口名| 描述 |     
| --------- | ------------| -------- |
| CameraKit | int32_t GetCameraIds(std::list\<string\> cameraList)  | 获取cameraId列表。 |
| CameraKit | CameraAbility& GetCameraAbility(string cameraId)  | 获取指定camera的能力。 |
| CameraKit | void RegisterCameraDeviceCallback(CameraDeviceCallback* callback, EventHandler* handler)  | 注册camera设备状态回调。 |
| CameraKit | void UnregisterCameraDeviceCallback(CameraDeviceCallback* callback)  | 去注册camera设备状态回调。 |
| CameraKit | void CreateCamera(string cameraId, CameraStateCallback* callback, EventHandler* handler)  | 创建camera实例。 |
| Camera | string GetCameraId()  | 获取cameraID。 |
| Camera | CameraConfig& GetCameraConfig()  | 获取camera配置信息。 |
| Camera | FrameConfig& GetFrameConfig(int32_t type)  | 获取捕获帧类型。 |
| Camera | void Configure(CameraConfig& config)  | 配置camera。 |
| Camera | void Release()  | 释放camera。 |
| Camera | int TriggerLoopingCapture(FrameConfig& frameConfig)  | 开始循环帧捕获。 |
| Camera | void StopLoopingCapture()  | 停止循环帧捕获。 |
| Camera | int32_t TriggerSingleCapture(FrameConfig& frameConfig)  | 抓图。 |
| CameraConfig | void SetFrameStateCallback(FrameStateCallback* callback, EventHandler* handler)  | 设置帧状态回调。 |
| CameraConfig | static CameraConfig* CreateCameraConfig()  | 创建camera配置信息实例。 |
| CameraAbility | std::list\<Size\> GetSupportedSizes(int format)  | 根据类型获取支持输出图像尺寸大小。 |
| CameraAbility | std::list\<T\> GetParameterRange(uint32_t key)  | 获取支持的参数范围。 |
| CameraDevice | CameraDeviceCallback()  | camera设备回调类构造函数。 |
| CameraDevice | void OnCameraStatus​(std::string cameraId, int32_t status)  | camera设备状态变化时的回调。 |
| CameraStateCallback | CameraStateCallback​()  | camera状态回调类构造函数。 |
| CameraStateCallback | void OnConfigured​(Camera& camera)  | camera配置成功回调。 |
| CameraStateCallback | void OnConfigureFailed​(Camera& camera,int32_t errorCode)  | camera配置失败回调。 |
| CameraStateCallback | void OnCreated​(Camera& camera)  | camera创建成功回调。 |
| CameraStateCallback | void OnCreateFailed​(std::string cameraId,int32_t errorCode)  | camera创建失败回调。 |
| CameraStateCallback | void OnReleased​(Camera& camera)  | camera释放回调。 |
| FrameStateCallback | FrameStateCallback​()  | 帧状态回调类构造函数。 |
| FrameStateCallback | void OnFrameFinished(Camera& camera, FrameConfig& frameConfig, FrameResult& frameResult)  | 拍照帧完成回调。 |
| FrameStateCallback | void OnFrameError​(Camera& camera, FrameConfig& frameConfig, int32_t errorCode, FrameResult& frameResult)  | 拍照帧异常回调。 |
| FrameConfig | int32_t GetFrameConfigType()  | 获取帧配置类型。 |
| FrameConfig | std::list<OHOS::Surface> GetSurfaces()  | 获取帧配置的surface。 |
| FrameConfig | void AddSurface(OHOS::AGP::UISurface& surface)  | 添加surface。 |
| FrameConfig | void RemoveSurface(OHOS::AGP::UISurface& surface)  | 删除surface。 |

## 约束与限制<a name="zh-cn_topic_0000001052170554_section1165911177314"></a>

无。

## 开发步骤<a name="zh-cn_topic_0000001052170554_section138543918214"></a>

1.  <a name="zh-cn_topic_0000001052170554_li378084192111"></a>实现设备状态回调的派生类，用户在设备状态发生变更（如新插入相机设备/相机掉线）时，自定义操作。

    ```
    class SampleCameraDeviceCallback : public CameraDeviceCallback {
        void OnCameraStatus(std::string cameraId, int32_t status) override
        {
            //do something when camera is available/unavailable.
        }
    };
    ```

2.  <a name="zh-cn_topic_0000001052170554_li8716104682913"></a>实现帧事件回调的派生类，这里在拿到帧数据以后将其转存为文件。

    ```
    static void SampleSaveCapture(const char *p, uint32_t size)
    {
        cout << "Start saving picture" << endl;
        struct timeval tv;
        gettimeofday(&tv, NULL);
        struct tm *ltm = localtime(&tv.tv_sec);
        if (ltm != nullptr) {
            ostringstream ss("Capture_");
            ss << "Capture" << ltm->tm_hour << "-" << ltm->tm_min << "-" << ltm->tm_sec << ".jpg";
    
            ofstream pic("/sdcard/" + ss.str(), ofstream::out | ofstream::trunc);
            cout << "write " << size << " bytes" << endl;
            pic.write(p, size);
            cout << "Saving picture end" << endl;
        }
    }
    
    class TestFrameStateCallback : public FrameStateCallback {
        void OnFrameFinished(Camera &camera, FrameConfig &fc, FrameResult &result) override
        {
            cout << "Receive frame complete inform." << endl;
            if (fc.GetFrameConfigType() == FRAME_CONFIG_CAPTURE) {
                cout << "Capture frame received." << endl;
                list<Surface *> surfaceList = fc.GetSurfaces();
                for (Surface *surface : surfaceList) {
                    SurfaceBuffer *buffer = surface->AcquireBuffer();
                    if (buffer != nullptr) {
                        char *virtAddr = static_cast<char *>(buffer->GetVirAddr());
                        if (virtAddr != nullptr) {
                            SampleSaveCapture(virtAddr, buffer->GetSize());
                        }
                        surface->ReleaseBuffer(buffer);
                    }
                    delete surface;
                }
                delete &fc;
            }
        }
    };
    ```

3.  <a name="zh-cn_topic_0000001052170554_li6671035102514"></a>实现相机状态回调的派生类，自定义相机状态发生变化（配置成功/失败，创建成功/失败\)时的操作。

    ```
    class SampleCameraStateMng : public CameraStateCallback {
    public:
        SampleCameraStateMng() = delete;
        SampleCameraStateMng(EventHandler &eventHdlr) : eventHdlr_(eventHdlr) {}
        ~SampleCameraStateMng()
        {
            if (recordFd_ != -1) {
                close(recordFd_);
            }
        }
        void OnCreated(Camera &c) override
        {
            cout << "Sample recv OnCreate camera." << endl;
            auto config = CameraConfig::CreateCameraConfig();
            config->SetFrameStateCallback(&fsCb_, &eventHdlr_);
            c.Configure(*config);
            cam_ = &c;
        }
        void OnCreateFailed(const std::string cameraId, int32_t errorCode) override {}
        void OnReleased(Camera &c) override {}
    };
    ```

4.  创建CameraKit，用于创建和获取camera信息。

    ```
    CameraKit *camKit = CameraKit::GetInstance();
    list<string> camList = camKit->GetCameraIds();
    string camId;
    for (auto &cam : camList) {
        cout << "camera name:" << cam << endl;
        const CameraAbility *ability = camKit->GetCameraAbility(cam);
        /* find camera which fits user's ability */
        list<CameraPicSize> sizeList = ability->GetSupportedSizes(0);
        if (find(sizeList.begin(), sizeList.end(), CAM_PIC_1080P) != sizeList.end()) {
            camId = cam;
            break;
        }
    }
    ```

5.  创建Camera实例。

    ```
    EventHandler eventHdlr; // Create a thread to handle callback events.
    SampleCameraStateMng CamStateMng(eventHdlr);
    
    camKit->CreateCamera(camId, CamStateMng, eventHdlr);
    ```

6.  根据[步骤1](#zh-cn_topic_0000001052170554_li378084192111)、[步骤2](#zh-cn_topic_0000001052170554_li8716104682913)、[步骤3](#zh-cn_topic_0000001052170554_li6671035102514)中的回调设计，同步等待 OnCreated 回调拿到 cam\_ 之后，进行相关操作。

    ```
    void OnCreated(Camera &c) override
    {
        cout << "Sample recv OnCreate camera." << endl;
        auto config = CameraConfig::CreateCameraConfig();
        config->SetFrameStateCallback(&fsCb_, &eventHdlr_);
        c.Configure(*config);
        cam_ = &c;
    }
    
    void Capture()
    {
        if (cam_ == nullptr) {
            cout << "Camera is not ready." << endl;
            return;
        }
        FrameConfig *fc = new FrameConfig(FRAME_CONFIG_CAPTURE);
        Surface *surface = Surface::CreateSurface();
        if (surface == nullptr) {
            delete fc;
            return;
        }
        surface->SetWidthAndHeight(1920, 1080); /* 1920:width,1080:height */
        fc->AddSurface(*surface);
        cam_->TriggerSingleCapture(*fc);
    }
    ```


