# AudioMmapBufferDescriptor


## **概述**

Mmap缓冲区描述符。

**相关模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [memoryAddress](_audio.md#memoryaddress) | 指向Mmap缓冲区的指针 | 
| [memoryFd](_audio.md#memoryfd) | Mmap缓冲区的文件描述符 | 
| [totalBufferFrames](_audio.md#totalbufferframes) | 缓冲区总大小，单位：帧 | 
| [transferFrameSize](_audio.md#transferframesize) | 传输大小，单位：帧 | 
| [isShareable](_audio.md#isshareable) | Mmap缓冲区是否可以在进程间共享 | 
