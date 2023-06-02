# AudioMmapBufferDescripter


## 概述

mmap缓冲区描述符。

**Since:**
3.2
**Version:**
1.0
**相关模块:**

[Audio](_audio.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [memoryAddress](#memoryaddress) | byte[]<br/>指向mmap缓冲区的指针。&nbsp; | 
| [memoryFd](#memoryfd) | int<br/>mmap缓冲区的文件描述符。&nbsp; | 
| [totalBufferFrames](#totalbufferframes) | int<br/>缓冲区总大小，单位：帧。&nbsp; | 
| [transferFrameSize](#transferframesize) | int<br/>传输大小，单位：帧。&nbsp; | 
| [isShareable](#isshareable) | int<br/>mmap缓冲区是否可以在进程间共享。&nbsp; | 
| [offset](#offset) | unsigned&nbsp;int<br/>文件偏移。&nbsp; | 
| [filePath](#filepath) | String<br/>mmap文件路径。&nbsp; | 


## 类成员变量说明


### filePath

  
```
String AudioMmapBufferDescripter::filePath
```
**描述:**
mmap文件路径。


### isShareable

  
```
int AudioMmapBufferDescripter::isShareable
```
**描述:**
mmap缓冲区是否可以在进程间共享。


### memoryAddress

  
```
byte [] AudioMmapBufferDescripter::memoryAddress
```
**描述:**
指向mmap缓冲区的指针。


### memoryFd

  
```
int AudioMmapBufferDescripter::memoryFd
```
**描述:**
mmap缓冲区的文件描述符。


### offset

  
```
unsigned int AudioMmapBufferDescripter::offset
```
**描述:**
文件偏移。


### totalBufferFrames

  
```
int AudioMmapBufferDescripter::totalBufferFrames
```
**描述:**
缓冲区总大小，单位：帧。


### transferFrameSize

  
```
int AudioMmapBufferDescripter::transferFrameSize
```
**描述:**
传输大小，单位：帧。
