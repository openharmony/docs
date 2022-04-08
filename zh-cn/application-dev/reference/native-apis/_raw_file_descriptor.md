# RawFileDescriptor


## **Overview**

**Related Modules:**

[Rawfile](rawfile.md)

**Description:**

提供rawfile文件描述符信息

RawFileDescriptor是[OH_ResourceManager_GetRawFileDescriptor](rawfile.md#ga8313a7d4bb361a98ced485346a9be4b1)的输出参数, 涵盖了rawfile文件的文件描述符以及在HAP包中的起始位置和长度。

**Since:**

8

**Version:**

1.0


## **Summary**


### Public Attributes

  | Public&nbsp;Attribute&nbsp;Name | Description | 
| -------- | -------- |
| fd |  | 
| start |  | 
| length |  | 


## **Details**


## **Member Data**


### fd

  
```
int RawFileDescriptor::fd
```

**Description:**

rawfile文件描述符


### length

  
```
long RawFileDescriptor::length
```

**Description:**

rawfile在HAP包中的长度


### start

  
```
long RawFileDescriptor::start
```

**Description:**

rawfile在HAP包中的起始位置
