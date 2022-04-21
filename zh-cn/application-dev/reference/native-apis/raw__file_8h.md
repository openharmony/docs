# raw_file.h


## **Overview**

**Related Modules:**

[Rawfile](rawfile.md)

**Description:**

提供rawfile文件相关功能

功能包括搜索、读取和关闭rawfile文件

**Since:**
8
**Version:**
1.0

## **Summary**


### Classes

  | Classe&nbsp;Name | Description | 
| -------- | -------- |
| [RawFileDescriptor](_raw_file_descriptor.md) | 提供rawfile文件描述符信息 | 


### Typedefs

  | Typedef&nbsp;Name | Description | 
| -------- | -------- |
| [RawFile](rawfile.md#gacf2dc23017812d7daf535b80f1a6ab27) | typedef&nbsp;struct&nbsp;[RawFile](rawfile.md#gacf2dc23017812d7daf535b80f1a6ab27)<br/>提供对rawfile的访问功能 | 


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_ResourceManager_ReadRawFile](rawfile.md#ga2958ba7372ae1232365358115a82c219)&nbsp;(const&nbsp;[RawFile](rawfile.md#gacf2dc23017812d7daf535b80f1a6ab27)&nbsp;\*rawFile,&nbsp;void&nbsp;\*buf,&nbsp;size_t&nbsp;length) | int<br/>读取rawfile | 
| [OH_ResourceManager_SeekRawFile](rawfile.md#ga7fc0d124fd184498b0a0bfad3454f45c)&nbsp;(const&nbsp;[RawFile](rawfile.md#gacf2dc23017812d7daf535b80f1a6ab27)&nbsp;\*rawFile,&nbsp;long&nbsp;offset,&nbsp;int&nbsp;whence) | int<br/>基于指定的offset，在rawfile文件内搜索读写数据的位置 | 
| [OH_ResourceManager_GetRawFileSize](rawfile.md#gafcc6036360466ab5193b7b4eba5eae50)&nbsp;([RawFile](rawfile.md#gacf2dc23017812d7daf535b80f1a6ab27)&nbsp;\*rawFile) | long<br/>获取rawfile长度，单位为int32_t | 
| [OH_ResourceManager_CloseRawFile](rawfile.md#ga5cccee53550670a2111705d56a1d427b)&nbsp;([RawFile](rawfile.md#gacf2dc23017812d7daf535b80f1a6ab27)&nbsp;\*rawFile) | void<br/>关闭已打开的[RawFile](rawfile.md#gacf2dc23017812d7daf535b80f1a6ab27)&nbsp;以及释放所有相关联资源 | 
| [OH_ResourceManager_GetRawFileOffset](rawfile.md#ga57dc379d6df6b7c7f8e76303ad4957a4)&nbsp;(const&nbsp;[RawFile](rawfile.md#gacf2dc23017812d7daf535b80f1a6ab27)&nbsp;\*rawFile) | long<br/>获取rawfile当前的offset，单位为int32_t | 
| [OH_ResourceManager_GetRawFileDescriptor](rawfile.md#ga8313a7d4bb361a98ced485346a9be4b1)&nbsp;(const&nbsp;[RawFile](rawfile.md#gacf2dc23017812d7daf535b80f1a6ab27)&nbsp;\*rawFile,&nbsp;[RawFileDescriptor](_raw_file_descriptor.md)&nbsp;&amp;descriptor) | bool<br/>基于offset(单位为int32_t)和文件长度打开rawfile，并获取rawfile文件描述符 | 
| [OH_ResourceManager_ReleaseRawFileDescriptor](rawfile.md#gabf9db7f05088a11cc311a6ef890eda6b)&nbsp;(const&nbsp;[RawFileDescriptor](_raw_file_descriptor.md)&nbsp;&amp;descriptor) | bool<br/>关闭rawfile文件描述符 | 
