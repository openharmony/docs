# 录像开发指导


## 使用场景

使用Camera采集视频码流。


## 接口说明

参考[拍照开发指导](subsys-multimedia-camera-photo-guide.md)的“接口说明”。


## 约束与限制

无。


## 开发步骤

1. 参考[拍照开发指导](subsys-multimedia-camera-photo-guide.md)中步骤1、步骤2、步骤3、步骤4。

2. 获取录像FrameConfig。
     
   ```
   /* 从recorder获取surface */
   Surface *surface = recorder_->GetSurface(0);
   surface->SetWidthAndHeight(1920, 1080);
   surface->SetQueueSize(3);
   surface->SetSize(1024 * 1024);
   /* 将surface配置到帧配置中 */
   FrameConfig *fc = new FrameConfig(FRAME_CONFIG_RECORD);
   fc->AddSurface(*surface);
   ```

3. 开启和停止录像。
     
   ```
   stateCallback->camera_->TriggerLoopingCapture(*fc); // 开始录像
   stateCallback->camera_->StopLoopingCapture();       // 结束录像
   ```
