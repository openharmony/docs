# 屏幕录制支持矩形区域录制

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xhjgc-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 基础概念

屏幕录制支持矩形区域录制是在现有的录制区域捕获基础上开放的高级能力，允许开发者自主选择录屏需要捕获的区域位置，并通过调整屏幕捕获ID和指定的捕获区域area确定矩形录制区域。
- 屏幕捕获ID：需要执行矩形区域录制的屏幕ID。
- 指定的捕获区域area：根据需要设置区域坐标和大小，设置想要捕获的区域，如创建区域的起点和矩形的长和宽。

## 适用场景

用户希望能够提供矩形区域录制功能的场景，例如：
- **指定窗口**：用户希望录制指定区域，通过现有接口录制指定窗口。

## 约束和限制

- **支持的系统**：OpenHarmony6.0及以后。
- **支持的编码模式**：Surface模式、Buffer模式。
- 

## 接口介绍

矩形区域录制接口支持开发者通过displayId和area设置需要捕获的区域位置，该接口设置的坐标和宽高不能为负数，捕获区域不能跨屏幕，区域位置设置失败后仍按照上一次的区域进行捕获。<br>
- displayId是需要捕获区域所在的屏幕Id，area是需要捕获区域的坐标和宽高。
- x、y分别为矩形区域起点的横坐标、纵坐标位置。
- width、height分别为矩形区域的宽度和长度。
- 多个参数之间通过";"连接，所有参数均为整数。
- 使用前请确保传入参数有效，并尽量避免坐标和宽高为负数。

|配置参数 |语义 |格式 |
|------- |------- |------- |
|capture   |指向[OH_AVScreenCapture]实例的指针 | struct*  |
|displayId |需要执行屏幕捕获的屏幕ID            | uint64_t |
|area      |指定捕获的区域                     | OH_Rect* |

**注意**
1. 该接口设置的坐标和宽高不能为负数，捕获区域不能跨屏幕，区域位置设置失败后仍按照上一次的区域进行捕获。

## 开发指导

1. 调用OH_AVScreenCapture_SetCaptureArea()接口传入希望录制的矩形区域。

    ```c++
    // 1. 可选，可以根据需要设置区域坐标和大小，设置想要捕获的区域，如下方创建了一个从（0, 0）为起点的长100，宽100的矩形区域。
    OH_Rect* region = new OH_Rect;
    region->x = 0;
    region->y = 0;
    region->width = 100;
    region->height = 100;
    // 2. 传入矩形区域所在的屏幕Id。
    unit64_t regionDisplayId = 0;
    OH_AVScreenCapture_SetCaptureArea(capture, regionDisplayId, region);
    ```
