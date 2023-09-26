# 预览开发指导


## 使用场景

使用Camera产生视频流并播放。


## 接口说明

参考[拍照开发指导](subsys-multimedia-camera-photo-guide.md)的“接口说明”。


## 约束与限制

无。


## 开发步骤

1. 参考[拍照开发指导](subsys-multimedia-camera-photo-guide.md)中步骤1、步骤2、步骤3、步骤4。

2. 设置预览显示的区域。
     
   ```
   Surface *surface = Surface::CreateSurface();
   /* 设置显示区域 */
   surface->SetUserData("region_position_x", "480"); // 矩形左上角横坐标
   surface->SetUserData("region_position_y", "270"); // 矩形左上角纵坐标
   surface->SetUserData("region_width", "960");      // 宽
   surface->SetUserData("region_height", "540");     // 高
   
   fc->AddSurface(*surface);
   ```

3. 开始和结束预览。
     
   ```
   stateCallback->camera_->TriggerLoopingCapture(*fc); // 开始预览
   stateCallback->camera_->StopLoopingCapture();       // 停止预览
   ```
