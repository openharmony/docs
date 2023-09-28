# Photographing Development


## When to Use

Use the camera module APIs to capture frames (photographing).


## Available APIs

**Table 1** APIs for photographing

| Class| API| Description|
| -------- | -------- | -------- |
| CameraKit | int32_t&nbsp;GetCameraIds(std::list&lt;string&gt;&nbsp;cameraList) | Obtains IDs of cameras that are currently available.|
| CameraKit | CameraAbility&amp;&nbsp;GetCameraAbility(string&nbsp;cameraId) | Obtains the camera capability.|
| CameraKit | void&nbsp;RegisterCameraDeviceCallback(CameraDeviceCallback\*&nbsp;callback,&nbsp;EventHandler\*&nbsp;handler) | Registers a camera callback for camera status changes.|
| CameraKit | void&nbsp;UnregisterCameraDeviceCallback(CameraDeviceCallback\*&nbsp;callback) | Unregisters a camera callback.|
| CameraKit | void&nbsp;CreateCamera(string&nbsp;cameraId,&nbsp;CameraStateCallback\*&nbsp;callback,&nbsp;EventHandler\*&nbsp;handler) | Creates a **Camera** instance.|
| Camera | string&nbsp;GetCameraId() | Obtains the camera ID.|
| Camera | CameraConfig&amp;&nbsp;GetCameraConfig() | Obtains the camera configuration.|
| Camera | FrameConfig&amp;&nbsp;GetFrameConfig(int32_t&nbsp;type) | Obtains the frame configuration.|
| Camera | void&nbsp;Configure(CameraConfig&amp;&nbsp;config) | Configures the camera using a **CameraConfig** instance.|
| Camera | void&nbsp;Release() | Releases the **Camera** object and associated resources.|
| Camera | int&nbsp;TriggerLoopingCapture(FrameConfig&amp;&nbsp;frameConfig) | Starts looping-frame capture.|
| Camera | void&nbsp;StopLoopingCapture() | Stops looping-frame capture.|
| Camera | int32_t&nbsp;TriggerSingleCapture(FrameConfig&amp;&nbsp;frameConfig) | Starts single-frame capture.|
| CameraConfig | void&nbsp;SetFrameStateCallback(FrameStateCallback\*&nbsp;callback,&nbsp;EventHandler\*&nbsp;handler); | Sets a frame state callback to respond to state changes.|
| CameraConfig | static&nbsp;CameraConfig\*&nbsp;CreateCameraConfig() | Creates a **CameraConfig** instance.|
| CameraAbility | std::list&lt;Size&gt;&nbsp;GetSupportedSizes(int&nbsp;format) | Obtains the supported image sizes for a specified image format.|
| CameraAbility | std::list&lt;T&gt;&nbsp;GetParameterRange(uint32_t&nbsp;key) | Obtains the parameter value range based on a specified parameter key.|
| CameraDevice | CameraDeviceCallback() | A constructor used to create a **CameraDeviceCallback** instance.|
| CameraDevice | void&nbsp;OnCameraStatus​(std::string&nbsp;cameraId,&nbsp;int32_t&nbsp;status) | Called when the camera device status changes.|
| CameraStateCallback | CameraStateCallback​() | A constructor used to create a **CameraStateCallback** instance.|
| CameraStateCallback | void&nbsp;OnConfigured​(Camera&amp;&nbsp;camera) | Called when the camera is configured successfully.|
| CameraStateCallback | void&nbsp;OnConfigureFailed​(Camera&amp;&nbsp;camera,int32_t&nbsp;errorCode) | Called when the camera fails to be configured.|
| CameraStateCallback | void&nbsp;OnCreated​(Camera&amp;&nbsp;camera) | Called when the camera is created successfully.|
| CameraStateCallback | void&nbsp;OnCreateFailed​(std::string&nbsp;cameraId,int32_t&nbsp;errorCode) | Called when the camera fails to be created.|
| CameraStateCallback | void&nbsp;OnReleased​(Camera&amp;&nbsp;camera) | Called when the camera is released.|
| FrameStateCallback | FrameStateCallback​() | A constructor used to create a **FrameStateCallback** instance.|
| FrameStateCallback | void&nbsp;OnFrameFinished(Camera&amp;&nbsp;camera,&nbsp;FrameConfig&amp;&nbsp;frameConfig,&nbsp;FrameResult&amp;&nbsp;frameResult) | Called when the frame capture is completed.|
| FrameStateCallback | void&nbsp;OnFrameError​(Camera&amp;&nbsp;camera,&nbsp;FrameConfig&amp;&nbsp;frameConfig,&nbsp;int32_t&nbsp;errorCode,&nbsp;FrameResult&amp;&nbsp;frameResult) | Called when the frame capture fails.|
| FrameConfig | int32_t&nbsp;GetFrameConfigType() | Obtains the frame configuration type.|
| FrameConfig | std::list&lt;OHOS::Surface&gt;&nbsp;GetSurfaces() | Obtains a list of surface objects.|
| FrameConfig | void&nbsp;AddSurface(OHOS::AGP::UISurface&amp;&nbsp;surface); | Adds a surface.|
| FrameConfig | void&nbsp;RemoveSurface(OHOS::AGP::UISurface&amp;&nbsp;surface); | Removes a surface.|


## Constraints

None


## How to Develop

1. Implement the **CameraDeviceCallback** class and call **OnCameraStatus** to customize operations when the camera device changes, for example, when a camera becomes available or unavailable.
   
   ```
   class SampleCameraDeviceCallback : public CameraDeviceCallback {
       void OnCameraStatus(std::string cameraId, int32_t status) override
       {
           //do something when camera is available/unavailable
       }
   };
   ```

2. Implement the **FrameStateCallback** class. After obtaining the frame data, save the data as a file.
   
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

3. Implement the **CameraStateCallback** class and customize operations when the camera state changes (configuration successful or failed, and creation successful or failed).
   
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

4. Create a **CameraKit** instance to set and obtain camera information.
   
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

5. Create a **Camera** instance.
   
   ```
   EventHandler eventHdlr; // Create a thread to handle callback events
   SampleCameraStateMng CamStateMng(eventHdlr);
   
   camKit->CreateCamera(camId, CamStateMng, eventHdlr);
   ```

6. Based on the callback design in steps 1, 2, and 3, perform related operations until the **OnCreated** callback obtains **cam_**.
   
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
