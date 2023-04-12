# 分布式远程启动


## 概述

分布式任务调度模块，通过主从设备服务代理机制，在OpenHarmony操作系统上建立起分布式服务平台，支持主设备(搭载OpenHarmony的智慧屏设备)启动从设备(IP Camera、运动手表等小内存OpenHarmony设备)FA的能力。

以智慧屏节目开播提醒为例，智慧屏上在喜欢的节目菜单中，点击“开播后提醒我”按钮，等节目开播后，智慧屏会拉起运动手表上的节目开播提醒FA。通过该FA用户可以快速知道喜欢的节目已经开始，达到协同互助的作用。


## 基本概念

- FA
  Feature Ability代表有界面的Ability，用于与用户进行交互。

- 远程启动
  即跨设备启动FA，与本地启动FA相对应。


## 接口说明

智慧屏端分布式开放能力如下表，包含在AbilitySlice类中，具体的API接口详见OpenHarmony应用接入接口文档：

  **表1** 分布式远程启动FA的API接口功能介绍

| 接口名 | 描述 | 
| -------- | -------- |
| void&nbsp;startAbility(Want&nbsp;want) | 远程启动FA，Want参数命名以实际开发平台API为准。 | 

  **表2** 参数Want功能介绍

| 参数名 | 类型 | 说明 | 
| -------- | -------- | -------- |
| want | ohos.aafwk.content.Want | 当开发者需要调用该接口启动远程FA时，需要显式指定待启动FA的设备id、bundleName和abilityName。 | 


## 约束与限制

- 支持主设备侧远程启动从设备侧FA，不支持从设备远程启动主设备FA。

- 远程启动前必须确保OpenHarmony设备间分布式组网成功（需要在同一网段内，可互相ping通），否则无法远程启动。

- 当前只支持拥有共同公钥信息的主从设备间FA（即主从设备的FA使用相同华为证书）的拉起。


## 开发步骤

智慧屏侧通过如下操作启动从设备侧FA，从设备侧FA默认已开发。

1. 打开DevEco Studio，完成智慧屏侧FA开发。

2. 获取目标在线从设备的设备ID。
     
   ```
   // 引入设备选择头文件
   import ohos.distributedschedule.interwork.DeviceInfo;
   import ohos.distributedschedule.interwork.DeviceManager;
   
   // 获取在线设备列表
   List<DeviceInfo> deviceInfoListOnline = DeviceManager.getDmsDeviceList(DeviceInfo.FLAG_GET_ONLINE_DEVICE);
   String remote_device_id;
   if (deviceInfoListOnline.size() > 0)
   {
       remote_device_id = deviceInfoListOnline[0].GetDeviceId(); // 获取在线列表中第一台设备的设备ID
   }
   ```

3. 构造want，首先使用ElementName类表明需要启动的远端设备ID，包名，Ability类名，传入want中，然后设置want中的分布式标志位Want.FLAG_ABILITYSLICE_MULTI_DEVICE表示需要远程启动。
     
   ```
   // 引入相关头文件
   import ohos.aafwk.ability.Ability;
   import ohos.aafwk.content.Want;
   import ohos.bundle.ElementName;
   
   // 启动远程设备FA
   Want want = new Want(); // 封装启动远端FA的Want
   // 使用步骤2中获取的设备ID，并指定FA信息
   ElementName name = new ElementName(remote_device_id, "com.huawei.remote_package_name", "remote_class_name"); 
   want.setElement(name); // 将待启动的FA信息添加到Want中
   want.setFlags(Want.FLAG_ABILITYSLICE_MULTI_DEVICE); // 设置分布式标记，若不设置将无法使用分布式能力
   startAbility(want); // 按照Want启动指定FA,Want参数命名以实际开发平台API为准
   ```
