# 多模输入开发概述

## 基本概念

多模输入是应用于标准系统之上，为设备提供输入能力。开发者根据提供的多模输入 API，可以获取输入设备列表、监听输入事件，变化鼠标样式，订阅组合按键等。

## Input Kit简介
多模输入子系统为多种输入设备提供服务，如触控板，触摸屏，鼠标。键盘等；通过对这些输入设备上报驱动事件的归一化处理，使输入设备于用户设备的交互体验统一，流畅。

Input Kit除了提供基础的输入事件服务之外，还提供了获取输入设备列表，改变鼠标光标样式等功能和接口。

## 运作机制
多模输入能力作为系统为应用提供的一种基础服务，通过处理上报的输入设备驱动事件，完成输入事件管理，接收，预处理，分发，通过inner SDK与JSkit上报应用。

![MMI-operation](figures/MMI-operation.png)

## 约束与限制

1. 在使用下列函数时，开发者需要请求相应的权限。

| 实例名 | 接口名  | 说明 |权限|
| ----------- | ------------------------------------------------------------ | -------------------------- |-----|
| inputConsumer | function setShieldStatus(shieldMode: ShieldMode, isShield: boolean): void； | 设置屏蔽按键拦截状态。 |ohos.permission.INPUT_CONTROL_DISPATCHING|
| inputConsumer | function getShieldStatus(shieldMode: ShieldMode): boolean; | 获取屏蔽按键拦截是否生效。 |ohos.permission.INPUT_CONTROL_DISPATCHING|
    
2. 组合按键，注入事件，输入监听，快捷键模块接口为系统接口。






