# 主动关闭CPU访问窗口缓冲区数据降低功耗

## 概述

当前操作系统的窗口缓冲区默认使用CPU访问，这样具有较好的兼容性，但GPU访问窗口缓冲区的能效通常更优，使用CPU访问的能效开销较大。当开发者确定应用无需CPU访问时可手动关闭该能力，提高应用能效。

## 问题现象

通常自绘制应用在生产缓冲区内容时，会默认使用CPU访问能力。此时由于CPU访问缓冲区效率较低，性能开销较大。

## 解决措施

如果开发者确认应用不需要使用CPU访问窗口缓冲区数据，应用可在首次获取窗口句柄 (OnSurfaceCreatedCB) 时关闭CPU访问能力，由硬件平台选择最佳的图像格式以提高能效降低功耗。

在首次获取窗口句柄 (OnSurfaceCreatedCB) 时调用OH_NativeWindow_NativeWindowHandleOpt(…, SET_USAGE, …)方法设置缓冲区USAGE的值为NATIVEBUFFER_USAGE_CPU_READ，实现关闭CPU访问能力，系统会选择更高效的方法（GPU等）访问缓冲区，参考代码如下：

```c
void OnSurfaceCreatedCB(OH_NativeXComponent *component, void *window) {    
    uint64_t usage = 0;
    int32_t ret = OH_NativeWindow_NativeWindowHandleOpt((OHNativeWindow*)window, GET_USAGE, &usage);
    usage &= ~NATIVEBUFFER_USAGE_CPU_READ;
    int32_t ret2 = OH_NativeWindow_NativeWindowHandleOpt((OHNativeWindow*)window, SET_USAGE, usage);
}
```

对于大型游戏等高负载场景，关闭CPU访问可提高30%左右的能效。