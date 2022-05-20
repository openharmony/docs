# raw_dir.h


## **Overview**

**Related Modules:**

[Rawfile](rawfile.md)

**Description:**

提供rawfile目录相关功能

功能包括遍历和关闭rawfile目录

**Since:**
8
**Version:**
1.0

## **Summary**


### Typedefs

  | Typedef&nbsp;Name | Description | 
| -------- | -------- |
| [RawDir](rawfile.md#ga654d75f2b4badf0dac10c4127a9938c3) | typedef&nbsp;struct&nbsp;[RawDir](rawfile.md#ga654d75f2b4badf0dac10c4127a9938c3)<br/>提供对rawfile目录的访问 | 


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_ResourceManager_GetRawFileName](rawfile.md#gaf522ad160d8ca2bd476b6ad45696e1af)&nbsp;([RawDir](rawfile.md#ga654d75f2b4badf0dac10c4127a9938c3)&nbsp;\*rawDir,&nbsp;int&nbsp;index) | const&nbsp;char&nbsp;\*<br/>通过索引获取rawfile文件名称 | 
| [OH_ResourceManager_GetRawFileCount](rawfile.md#ga604cd2ced1bf4a0d1ace7b0fc89cb884)&nbsp;([RawDir](rawfile.md#ga654d75f2b4badf0dac10c4127a9938c3)&nbsp;\*rawDir) | int<br/>获取[RawDir](rawfile.md#ga654d75f2b4badf0dac10c4127a9938c3)中的rawfile数量 | 
| [OH_ResourceManager_CloseRawDir](rawfile.md#ga1db0825028507d355db4067f187223de)&nbsp;([RawDir](rawfile.md#ga654d75f2b4badf0dac10c4127a9938c3)&nbsp;\*rawDir) | void<br/>关闭已打开的[RawDir](rawfile.md#ga654d75f2b4badf0dac10c4127a9938c3)并释放所有相关联资源 | 
