# CompVerInfo


## **概述**

**所属模块:**

[Codec](_codec.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [compName](#compname)&nbsp;[[NAME_LENGTH](_codec.md#gaf71324c57f05ff9e24bd384925dd6b17)] | 组件名称 | 
| [compUUID](#compuuid)&nbsp;[[UUID_LENGTH](_codec.md#ga9226162b034cc837cd977f0fcf611c2c)] | 组件的UUID标识符 | 
| [compVersion](#compversion) | OMX组件版本信息 | 
| [specVersion](#specversion) | 构建组件所依据的规范的版本信息 | 


## **Details**


## **详细描述**


## **类成员变量说明**


### compName

  
```
char CompVerInfo::compName[NAME_LENGTH]
```

**描述：**

组件名称


### compUUID

  
```
uint8_t CompVerInfo::compUUID[UUID_LENGTH]
```

**描述：**

组件的UUID标识符


### compVersion

  
```
union OMX_VERSIONTYPE CompVerInfo::compVersion
```

**描述：**

OMX组件版本信息


### specVersion

  
```
union OMX_VERSIONTYPE CompVerInfo::specVersion
```

**描述：**

构建组件所依据的规范的版本信息
