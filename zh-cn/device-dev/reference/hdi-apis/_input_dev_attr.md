# InputDevAttr


## **概述**

**所属模块:**

[Input](_input.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [devName](#devname) | 设备名 | 
| [id](#id) | 设备识别信息 | 
| [axisInfo](#axisinfo)  | 设备维度信息 |

## **详细描述**

Input设备属性。


## **类成员变量说明**


### devName

```
char InputDevAttr::devName[DEV_NAME_LEN]
```

**描述：**

设备名。

### id

```
InputDevIdentify InputDevAttr::id
```

**描述：**

设备识别信息。

### axisInfo

```
InputDimensionInfo InputDevAttr::axisInfo[ABS_CNT];
```

**描述：**

设备维度信息。