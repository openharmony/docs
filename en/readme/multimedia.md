# Multimedia<a name="EN-US_TOPIC_0000001083456986"></a>

-   [Introduction](#section38510214395)
-   [Directory Structure](#section1937963913399)
-   [Constraints](#section722512541395)
-   [Installation](#section11914418405)
-   [Usage Guidelines](#section1467220266400)
-   [Repositories Involved](#section7666411192217)

## Introduction<a name="section38510214395"></a>

This repository stores source code information of the multimedia subsystem. It provides unified interfaces for you to develop media applications. With this repository, you can easily obtain media resources and focus on service development. The following two figures show the framework and service flow of the multimedia subsystem, respectively.

**Figure  1**  Subsystem architecture<a name="fig14437165910531"></a>  
![](figures/subsystem-architecture.png "subsystem-architecture")

The multimedia framework supports the camera, recording, and playback functions. These functions support the development of JavaScript applications and various kit modules that use media capabilities. 

The multimedia framework includes the framework and system service layers. 

-   The framework layer provides native APIs and corresponding service implementation for applications. It implements audio/video input and output, audio/video encoding and decoding, as well as video file packing and demultiplexing for camera, recording, and playback services.
-   The system service layer uses the platform capabilities to invoke underlying hardware and related drivers.

**Figure  2**  Service flow<a name="fig69091712152911"></a>  
![](figures/service-flow.png "service-flow")

The multimedia subsystem includes camera, recorder, and player modules. The camera module provides YUV or RGB, JPEG, and H.264 or H.265 data, which is stored in the surface \(shared memory\); the recorder module packs H.264 or H.265 and AAC data in the surface into MP4 files; the player module demultiplexes the MP4 files into audio and video data, sends the data to corresponding decoders, and then plays the audio and video.

## Directory Structure<a name="section1937963913399"></a>

The directory structure of the source code is as follows \(only the main part is listed\):

```
foundation/multimedia                                      # Main directory
├── audio_lite 
│   ├── frameworks                                     # Implementation of the audio module
│   └── interfaces                                     # Definition of audio module APIs
├── camera_lite
│   ├── frameworks                                     # Implementation of the camera module
│   └── interfaces                                     # Definition of camera module APIs
├── media_lite
│   ├── frameworks                                     
│   │   ├── player_lite                               # Implementation of the player module
│   │   └── recorder_lite                             # Implementation of the recorder module
│   └── interfaces
│   │   └── kits
│   │       ├── player_lite                            # Implementation of player module APIs
│   │       ├── recorder_lite                          # Implementation of recorder module APIs
│   ├── services                                        # Code for starting the media service
│   └── test                                            # Test code
└── utils
    └── lite                                            # Implementation of common module APIs
         └── hals                                       # Header file declaring media adaptation APIs
```

## Constraints<a name="section722512541395"></a>

-   C++ 11 or later

## Installation<a name="section11914418405"></a>

-   Load the kernel and related drivers before installing the repository. For details, see readme files of kernel and driver subsystems.
-   Configure a proper configuration file. For details, see the configuration file in  **applications/sample/camera/media**  directory. If you want to adapt to other sensors, seek help from the open source community. Ensure that the configuration file is stored in the  **/storage/data**  directory of the development board in use. You can use this configuration file to adapt to the sensor, resolution, and frame rate.

## Usage Guidelines<a name="section1467220266400"></a>

For details about how to call native APIs, see the demo in the  **applications/sample/camera/media**  directory.

For details about how to call multimedia APIs to implement the video recording, preview, and playback, see  _Multimedia Development Guide_.

Create a  **CameraKit**  object and register various callbacks to respond to many events in the media module. Then, create a  **Camera**  object to operate camera resources, for example, to start preview, recording, and stream capturing, and set related parameters.

The following example code overrides the event callbacks:

```
#include "camera_kit.h"
#include "recorder.h"

#include <algorithm>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
using namespace OHOS;
using namespace OHOS::Media;

static int32_t SampleGetRecordFd()
{
    struct timeval tv = {};
    gettimeofday(&tv, nullptr);
    struct tm *ltm = localtime(&tv.tv_sec);
    int32_t fd = -1;
    if (ltm != nullptr) {
        ostringstream ss("Capture_");
        ss << "Record" << ltm->tm_hour << "-" << ltm->tm_min << "-" << ltm->tm_sec << ".mp4";
        fd = open(("/sdcard/" + ss.str()).c_str(), O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        cout << "Open "
             << "/sdcard/" << ss.str() << endl;

        if (fd == -1) {
            cout << "Failed to open the recorder file. strerr=" << strerror(errno) << endl;
        }
    }
    return fd;
}

static void SampleSaveCapture(const char *p, uint32_t size)
{
    cout << "Picture saving starts." << endl;
    struct timeval tv = {};
    gettimeofday(&tv, nullptr);
    struct tm *ltm = localtime(&tv.tv_sec);
    if (ltm != nullptr) {
        ostringstream ss("Capture_");
        ss << "Capture" << ltm->tm_hour << "-" << ltm->tm_min << "-" << ltm->tm_sec << ".jpg";

        ofstream pic("/sdcard/" + ss.str(), ofstream::out | ofstream::trunc);
        cout << "write " << size << " bytes" << endl;
        pic.write(p, size);
        pic.close();
        cout << "Saving picture complete." << endl;
    }
}

Recorder *SampleCreateRecorder()
{
    int ret = 0;
    int32_t sampleRate = 48000;
    int32_t channelCount = 1;
    AudioCodecFormat audioFormat = AAC_LC;
    AudioSourceType inputSource = AUDIO_MIC;
    int32_t audioEncodingBitRate = sampleRate;
    VideoSourceType source = VIDEO_SOURCE_SURFACE_ES;
    int32_t frameRate = 30;
    double fps = 30;
    int32_t rate = 4096;
    int32_t sourceId = 0;
    int32_t audioSourceId = 0;
    int32_t width = 1920;
    int32_t height = 1080;
    VideoCodecFormat encoder;
    encoder = HEVC;
    width = 1920;
    height = 1080;
    Recorder *recorder = new Recorder();
    if ((ret = recorder->SetVideoSource(source, sourceId)) != SUCCESS) {
        cout << "SetVideoSource failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetVideoEncoder(sourceId, encoder)) != SUCCESS) {
        cout << "SetVideoEncoder failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetVideoSize(sourceId, width, height)) != SUCCESS) {
        cout << "SetVideoSize failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetVideoFrameRate(sourceId, frameRate)) != SUCCESS) {
        cout << "SetVideoFrameRate failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetVideoEncodingBitRate(sourceId, rate)) != SUCCESS) {
        cout << "SetVideoEncodingBitRate failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetCaptureRate(sourceId, fps)) != SUCCESS) {
        cout << "SetCaptureRate failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetAudioSource(inputSource, audioSourceId)) != SUCCESS) {
        cout << "SetAudioSource failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetAudioEncoder(audioSourceId, audioFormat)) != SUCCESS) {
        cout << "SetAudioEncoder failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetAudioSampleRate(audioSourceId, sampleRate)) != SUCCESS) {
        cout << "SetAudioSampleRate failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetAudioChannels(audioSourceId, channelCount)) != SUCCESS) {
        cout << "SetAudioChannels failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetAudioEncodingBitRate(audioSourceId, audioEncodingBitRate)) != SUCCESS) {
        cout << "SetAudioEncodingBitRate failed." << ret << endl;
        goto ERROR;
    }
    if ((ret = recorder->SetMaxDuration(36000)) != SUCCESS) { // 36000s=10h
        cout << "SetAudioEncodingBitRate failed." << ret << endl;
        goto ERROR;
    }
    return recorder;

ERROR:
    delete recorder;
    return nullptr;
}

class SampleFrameStateCallback : public FrameStateCallback {
    void OnFrameFinished(Camera &camera, FrameConfig &fc, FrameResult &result) override
    {
        cout << "Receive complete frame information." << endl;
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
        }
        delete &fc;
    }
};

class SampleCameraStateMng : public CameraStateCallback {
public:
    SampleCameraStateMng() = delete;
    SampleCameraStateMng(EventHandler &eventHdlr) : eventHdlr_(eventHdlr) {}
    ~SampleCameraStateMng()
    {
        CloseRecorder();
    }
    void OnCreated(Camera &c) override
    {
        cout << "Receive information upon camera creation." << endl;
        auto config = CameraConfig::CreateCameraConfig();
        config->SetFrameStateCallback(&fsCb_, &eventHdlr_);
        c.Configure(*config);
        cam_ = &c;
    }
    void OnCreateFailed(const std::string cameraId, int32_t errorCode) override {}
    void OnReleased(Camera &c) override {}

    void CloseRecorder()
    {
        if (recorder_ != nullptr) {
            recorder_->Stop(true);
            recorder_->Release();
            delete recorder_;
            recorder_ = nullptr;
        }
        if (recordFd_ != -1) {
            close(recordFd_);
            recordFd_ = -1;
        }
    }

    int PrepareRecorder()
    {
        if (cam_ == nullptr) {
            cout << "The camera is not ready." << endl;
            return -1;
        }
        if (recorder_ == nullptr) {
            recorder_ = SampleCreateRecorder();
        }
        if (recorder_ == nullptr) {
            cout << "The recorder is not available." << endl;
            return -1;
        }
        if (recordFd_ == -1) {
            recordFd_ = SampleGetRecordFd();
        }
        if (recordFd_ == -1) {
            cout << "Failed to create the file descriptor." << endl;
            return -1;
        }
        return SUCCESS;
    }

    void StartRecord()
    {
        if (recordState_ == STATE_RUNNING) {
            cout << "The camera is recording." << endl;
            return;
        }
        int ret = PrepareRecorder();
        if (ret != SUCCESS) {
            cout << "PrepareRecorder failed." << endl;
            CloseRecorder();
            return;
        }
        ret = recorder_->SetOutputFile(recordFd_);
        if (ret != SUCCESS) {
            cout << "SetOutputPath failed. ret=" << ret << endl;
            CloseRecorder();
            return;
        }
        ret = recorder_->Prepare();
        if (ret != SUCCESS) {
            cout << "Prepare failed. ret=" << ret << endl;
            CloseRecorder();
            return;
        }
        ret = recorder_->Start();
        if (ret != SUCCESS) {
            cout << "Failed to start the recorder. ret=" << ret << endl;
            CloseRecorder();
            return;
        }
        FrameConfig *fc = new FrameConfig(FRAME_CONFIG_RECORD);
        Surface *surface = (recorder_->GetSurface(0)).get();
        surface->SetWidthAndHeight(1920, 1080);
        surface->SetQueueSize(3);
        surface->SetSize(1024 * 1024);
        fc->AddSurface(*surface);
        ret = cam_->TriggerLoopingCapture(*fc);
        if (ret != 0) {
            delete fc;
            CloseRecorder();
            cout << "Failed to start camera recording. ret=" << ret << endl;
            return;
        }
        recordState_ = STATE_RUNNING;
        cout << "Camera recording starts." << endl;
    }

    void StartPreview()
    {
        if (cam_ == nullptr) {
            cout << "The camera is not ready." << endl;
            return;
        }
        if (previewState_ == STATE_RUNNING) {
            cout << "The camera is in preview." << endl;
            return;
        }
        FrameConfig *fc = new FrameConfig(FRAME_CONFIG_PREVIEW);
        Surface *surface = Surface::CreateSurface();
        if (surface == nullptr) {
            delete fc;
            cout << "CreateSurface failed" << endl;
            return;
        }
        surface->SetWidthAndHeight(1920, 1080); /* 1920:width,1080:height */
        surface->SetUserData("region_position_x", "0");
        surface->SetUserData("region_position_y", "0");
        surface->SetUserData("region_width", "480");
        surface->SetUserData("region_height", "480");
        fc->AddSurface(*surface);
        int32_t ret = cam_->TriggerLoopingCapture(*fc);
        if (ret != 0) {
            delete fc;
            cout << "Failed to start camera preview. ret=" << ret << endl;
            return;
        }
        delete surface;
        previewState_ = STATE_RUNNING;
        cout << "Camera preview starts." << endl;
    }
    void Capture()
    {
        if (cam_ == nullptr) {
            cout << "The camera is not ready." << endl;
            return;
        }
        FrameConfig *fc = new FrameConfig(FRAME_CONFIG_CAPTURE);
        Surface *surface = Surface::CreateSurface();
        if (surface == nullptr) {
            delete fc;
            cout << "CreateSurface failed" << endl;
            return;
        }
        surface->SetWidthAndHeight(1920, 1080); /* 1920:width,1080:height */
        fc->AddSurface(*surface);
        cam_->TriggerSingleCapture(*fc);
    }
    void Stop()
    {
        if (cam_ == nullptr) {
            cout << "The camera is not ready." << endl;
            return;
        }
        cam_->StopLoopingCapture();
        if (recordState_ == STATE_RUNNING) {
            CloseRecorder();
        }
        recordState_ = STATE_IDLE;
        previewState_ = STATE_IDLE;
    }

private:
    enum State : int32_t { STATE_IDLE, STATE_RUNNING, STATE_BUTT };
    State previewState_ = STATE_IDLE;
    State recordState_ = STATE_IDLE;
    EventHandler &eventHdlr_;
    Camera *cam_ = nullptr;
    int32_t recordFd_ = -1;
    Recorder *recorder_ = nullptr;
    SampleFrameStateCallback fsCb_;
};

class SampleCameraDeviceCallback : public CameraDeviceCallback {
};

void SampleHelp()
{
    cout << "*******************************************" << endl;
    cout << "Select the action to take for the AVRecorder." << endl;
    cout << "1: Take a picture." << endl;
    cout << "2: Record (press S to stop)" << endl;
    cout << "3: Preview (press S to stop)" << endl;
    cout << "Press Q to quit." << endl;
    cout << "*******************************************" << endl;
}

int main()
{
    cout << "The sample starts." << endl;
    SampleHelp();
    CameraKit *camKit = CameraKit::GetInstance();
    if (camKit == nullptr) {
        cout << "Failed to get the CameraKit instance" << endl;
        return 0;
    }
    list<string> camList = camKit->GetCameraIds();
    string camId;
    for (auto &cam : camList) {
        cout << "camera name:" << cam << endl;
        const CameraAbility *ability = camKit->GetCameraAbility(cam);
        /* find camera which fits user's ability */
        list<CameraPicSize> sizeList = ability->GetSupportedSizes(0);
        for (auto &pic : sizeList) {
            if (pic.width == 1920 && pic.height == 1080) {
                camId = cam;
                break;
            }
        }
    }

    if (camId.empty()) {
        cout << "No available camera (1080p required)." << endl;
        return 0;
    }

    EventHandler eventHdlr; // Create a thread to handle callback events
    SampleCameraStateMng CamStateMng(eventHdlr);

    camKit->CreateCamera(camId, CamStateMng, eventHdlr);

    char input;
    while (cin >> input) {
        switch (input) {
            case '1':
                CamStateMng.Capture();
                break;
            case '2':
                CamStateMng.StartRecord();
                break;
            case '3':
                CamStateMng.StartPreview();
                break;
            case 's':
                CamStateMng.Stop();
                break;
            case 'q':
                CamStateMng.Stop();
                goto EXIT;
            default:
                SampleHelp();
                break;
        }
    }
EXIT:
    cout << "The sample ends." << endl;
    return 0;
}
```

## Repositories Involved<a name="section7666411192217"></a>

**Multimedia subsystem**

[camera\_lite](https://gitee.com/openharmony/multimedia_camera_lite/blob/master/README.md)

[camera\_sample\_lite](https://gitee.com/openharmony/applications_sample_camera/blob/master/README.md)

[media\_utils\_lite](https://gitee.com/openharmony/multimedia_utils_lite/blob/master/README.md)

[audio\_lite](https://gitee.com/openharmony/multimedia_audio_lite/blob/master/README.md)

[media\_lite](https://gitee.com/openharmony/multimedia_media_lite/blob/master/README.md)
