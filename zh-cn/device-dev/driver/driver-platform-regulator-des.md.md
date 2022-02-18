# REGULATOR<a name="title_REGULATOR_des"></a>

-   [概述](#section1_REGULATOR_des)
-   [接口说明](#section2_REGULATOR_des)
-   [使用指导](#section3_REGULATOR_des)
    -   [使用流程](#section3.1_REGULATOR_des)
    -   [获取REGULATOR设备句柄](#section3.2_REGULATOR_des)
    -   [销毁REGULATOR设备句柄](#section3.3_REGULATOR_des)
    -   [使能](#section3.4_REGULATOR_des)
    -   [禁用](#section3.5_REGULATOR_des)
    -   [强制禁用](#section3.6_REGULATOR_des)
    -   [设置REGULATOR电压输出电压范围](#section3.7_REGULATOR_des)
    -   [获取REGULATOR设备电压](#section3.8_REGULATOR_des)
    -   [设置REGULATOR设备输出电流范围](#section3.9_REGULATOR_des)
    -   [获取REGULATOR设备电流](#section3.10_REGULATOR_des)
    -   [获取REGULATOR设备状态](#section3.11_REGULATOR_des)
-   [使用实例](#section4_REGULATOR_des)

## 概述<a name="section1_REGULATOR_des"></a>

- REGULATOR模块用于控制系统中某些设备的电压/电流供应。在嵌入式系统（尤其是手机）中，控制耗电量很重要，直接影响到电池的续航时间。所以，如果系统中某一个模块暂时不需要使用，就可以通过regulator关闭其电源供应；或者降低提供给该模块的电压、电流大小。

- REGULATOR接口定义了操作REGULATOR设备的通用方法集合，包括：
  - REGULATOR设备句柄获取和销毁。
  - REGULATOR设备电压、电流的设置。
  - REGULATOR设备使能和关闭。
  - REGULATOR设备电压、电流和状态的获取

## 接口说明<a name="section2_REGULATOR_des"></a>

**表1**  REGULATOR设备API功能介绍

<a name="table1_REGULATOR_des"></a>

<table border="0" cellpadding="0" cellspacing="0" width="600" style="border-collapse:
 collapse;table-layout:fixed;width:855pt">
 <colgroup><col width="183" style="mso-width-source:userset;mso-width-alt:5856;width:137pt">
 <col width="159" style="mso-width-source:userset;mso-width-alt:5088;width:119pt">
 <col width="213" style="mso-width-source:userset;mso-width-alt:6816;width:160pt">
 </colgroup><tbody><tr height="19" style="height:14.25pt">
  <td height="19" width="183" style="height:14.25pt;width:137pt">功能分类</td>
  <td width="159" style="width:119pt">接口名</td>
  <td width="213" style="width:160pt">描述</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td rowspan="2" height="38" class="xl65" style="height:28.5pt">REGULATOR句柄操作</td>
  <td>RegulatorOpen</td>
  <td>获取REGULATOR设备驱动句柄</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">RegulatorClose</td>
  <td>销毁REGULATOR设备驱动句柄</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td rowspan="3" height="57" class="xl65" style="height:42.75pt">使能/禁用REGULATOR</td>
  <td>RegulatorEnable</td>
  <td>使能REGULATOR</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">RegulatorDisable</td>
  <td>禁用REGULATOR</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">RegulatorForceDisable</td>
  <td>强制禁用REGULATOR</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td rowspan="2" height="38" class="xl65" style="height:28.5pt">设置/获取REGULATOR输出电压</td>
  <td>RegulatorSetVoltage</td>
  <td>设置REGULATOR输出电压</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">RegulatorGetVoltage</td>
  <td>获取REGULATOR输出电压</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td rowspan="2" height="38" class="xl65" style="height:28.5pt">设置/获取REGULATOR输出电流</td>
  <td>RegulatorSetCurrent</td>
  <td>设置REGULATOR输出电流</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">RegulatorGetCurrent</td>
  <td>获取REGULATOR输出电流</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" class="xl66" style="height:14.25pt">获取REGULATOR状态</td>
  <td>RegulatorGetStatus</td>
  <td>获取REGULATOR状态</td>
 </tr>
 <!--[if supportMisalignedColumns]-->
 <tr height="0" style="display:none">
  <td width="183" style="width:137pt"></td>
  <td width="159" style="width:119pt"></td>
  <td width="213" style="width:160pt"></td>
 </tr>
 <!--[endif]-->
</tbody></table>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>REGULATOR当前仅限内核态使用，不支持在用户态使用。

## 使用指导<a name="section3_REGULATOR_des"></a>

### 使用流程<a name="section3.1_REGULATOR_des"></a>

在操作系统启动过程中，驱动管理模块根据配置文件加载REGULATOR驱动，REGULATOR驱动会检测REGULATOR器件并初始化驱动。

使用REGULATOR设备的一般流程如[图1](#fig1_REGULATOR_des)所示。

**图 1**  REGULATOR设备使用流程图<a name="fig1_REGULATOR_des"></a>  


![](figures/REGULATOR设备使用流程图.png)

### 获取REGULATOR设备句柄<a name="section3.2_REGULATOR_des"></a>

在操作REGULATOR设备时，首先要调用RegulatorOpen获取REGULATOR设备句柄，该函数会返回指定设备名称的REGULATOR设备句柄。

```c
DevHandle RegulatorOpen(const char *name);
```

**表2**  RegulatorOpen参数和返回值描述

<a name="table2_REGULATOR_des"></a>

| 参数       | 参数描述                      |
| ---------- | ----------------------------- |
| name       | REGULATOR设备名称             |
| **返回值** | **返回值描述**                |
| handle     | 获取成功返回REGULATOR设备句柄 |
| NULL       | 获取失败                      |


```c
/* REGULATOR设备名称 */
const char *name = "regulator_virtual_1";
DevHandle handle = NULL;

/* 获取REGULATOR设备句柄 */
handle = RegulatorOpen(name);
if (handle  == NULL) {
    /* 错误处理 */
}
```

### 销毁REGULATOR设备句柄<a name="section3.3_REGULATOR_des"></a>

关闭REGULATOR设备，系统释放对应的资源。

```c
void RegulatorClose(DevHandle handle);
```

**表3**  RegulatorClose参数描述

<a name="table3_REGULATOR_des"></a>

| 参数   | 参数描述          |
| ------ | ----------------- |
| handle | REGULATOR设备句柄 |


```c
/* 销毁REGULATOR设备句柄 */
RegulatorClose(handle);
```

### 使能<a name="section3.4_REGULATOR_des"></a>

启用REGULATOR设备。

```c
int32_t RegulatorEnable(DevHandle handle);
```

**表4** RegulatorEnable参数描述

<a name="table4_REGULATOR_des"></a>

| 参数       | 参数描述          |
| ---------- | ----------------- |
| handle     | REGULATOR设备句柄 |
| **返回值** | **返回值描述**    |
| 0          | 使能成功          |
| 负数       | 使能失败          |

```c
int32_t ret;

/*启用REGULATOR设备*/
ret = RegulatorEnable(handle);
if (ret != 0) {
	/*错误处理*/
}
```

### 禁用<a name="section3.5_REGULATOR_des"></a>

禁用REGULATOR设备。

```c
int32_t RegulatorDisable(DevHandle handle);
```

**表5** RegulatorDisable参数描述

<a name="table5_REGULATOR_des"></a>

| 参数       | 参数描述          |
| ---------- | ----------------- |
| handle     | REGULATOR设备句柄 |
| **返回值** | **返回值描述**    |
| 0          | 禁用成功          |
| 负数       | 禁用失败          |

```c
int32_t ret;

/*禁用REGULATOR设备，如果REGULATOR设备状态为常开，或存在REGULATOR设备子节点未禁用，则禁用失败*/
ret = RegulatorDisable(handle);
if (ret != 0) {
	/*错误处理*/
}
```

### 强制禁用<a name="section3.6_REGULATOR_des"></a>

强制禁用REGULATOR设备。

```c
int32_t RegulatorForceDisable(DevHandle handle);
```

**表6** RegulatorForceDisable参数描述

<a name="table6_REGULATOR_des"></a>

| 参数       | 参数描述          |
| ---------- | ----------------- |
| handle     | REGULATOR设备句柄 |
| **返回值** | **返回值描述**    |
| 0          | 强制禁用成功      |
| 负数       | 强制禁用失败      |

```c
int32_t ret;

/*强制禁用REGULATOR设备，无论REGULATOR设备的状态是常开还是子节点已使能，REGULATOR设备都会被禁用*/
ret = RegulatorForceDisable(handle);
if (ret != 0) {
	/*错误处理*/
}
```
### 设置REGULATOR输出电压范围<a name="section3.7_REGULATOR_des"></a>

设置REGULATOR电压输出电压范围。

```c
int32_t RegulatorSetVoltage(DevHandle handle, uint32_t minUv, uint32_t maxUv);
```

**表7** RegulatorSetVoltage参数描述

<a name="table7_REGULATOR_des"></a>

| 参数       | 参数描述          |
| ---------- | ----------------- |
| handle     | REGULATOR设备句柄 |
| minUv      | 最小电压          |
| maxUv      | 最大电压          |
| **返回值** | **返回值描述**    |
| 0          | 设置成功          |
| 负数       | 设置失败          |

```c
int32_t ret;
int32_t minUv = 0;		//最小电压为0Uv
int32_t maxUv = 20000;  //最大电压为20000Uv

/*设置REGULATOR电压输出电压范围*/
ret = RegulatorSetVoltage(handle, minUv, maxUv);
if (ret != 0) {
	/*错误处理*/
}
```
### 获取REGULATOR电压<a name="section3.8_REGULATOR_des"></a>

获取REGULATOR电压。

```c
int32_t RegulatorGetVoltage(DevHandle handle, uint32_t *voltage);
```

**表8** RegulatorGetVoltage参数描述

<a name="table8_REGULATOR_des"></a>

| 参数       | 参数描述          |
| ---------- | ----------------- |
| handle     | REGULATOR设备句柄 |
| *voltage   | 参数指针          |
| **返回值** | **返回值描述**    |
| 0          | 获取成功          |
| 负数       | 获取失败          |

```c
int32_t ret;
uint32_t voltage;

/*获取REGULATOR电压*/
ret = RegulatorGetVoltage(handle, &voltage);
if (ret != 0) {
	/*错误处理*/
}
```


### 设置REGULATOR输出电流范围<a name="section3.9_REGULATOR_des"></a>

设置REGULATOR输出电流范围。

```c
int32_t RegulatorSetCurrent(DevHandle handle, uint32_t minUa, uint32_t maxUa);
```

**表9** RegulatorSetCurrent参数描述

<a name="table9_REGULATOR_des"></a>

| 参数       | 参数描述          |
| ---------- | ----------------- |
| handle     | REGULATOR设备句柄 |
| minUa      | 最小电流          |
| maxUa      | 最大电流          |
| **返回值** | **返回值描述**    |
| 0          | 设置成功          |
| 负数       | 设置失败          |

```c
int32_t ret;
int32_t minUa = 0;		//最小电流为0Ua
int32_t maxUa = 200;  //最大电流为200Ua

/*设置REGULATOR输出电流范围*/
ret = RegulatorSetCurrent(handle, minUa, maxUa);
if (ret != 0) {
	/*错误处理*/
}
```

### 获取REGULATOR电流<a name="section3.10_REGULATOR_des"></a>

获取REGULATOR电流。

```c
int32_t RegulatorGetCurrent(DevHandle handle, uint32_t *regCurrent);
```

**表10** RegulatorGetCurrent参数描述

<a name="table10_REGULATOR_des"></a>

| 参数        | 参数描述          |
| ----------- | ----------------- |
| handle      | REGULATOR设备句柄 |
| *regCurrent | 参数指针          |
| **返回值**  | **返回值描述**    |
| 0           | 获取成功          |
| 负数        | 获取失败          |

```c
int32_t ret;
uint32_t regCurrent;

/*获取REGULATOR电流*/
ret = RegulatorGetCurrent(handle, &regCurrent);
if (ret != 0) {
	/*错误处理*/
}
```
### 获取REGULATOR状态<a name="section3.11_REGULATOR_des"></a>

获取REGULATOR状态。

```c
int32_t RegulatorGetStatus(DevHandle handle, uint32_t *status);
```

**表11** RegulatorGetStatus参数描述

<a name="table11_REGULATOR_des"></a>

| 参数       | 参数描述          |
| ---------- | ----------------- |
| handle     | REGULATOR设备句柄 |
| *status    | 参数指针          |
| **返回值** | **返回值描述**    |
| 0          | 获取成功          |
| 负数       | 获取失败          |

```c
int32_t ret;
uint32_t status;

/*获取REGULATOR状态*/
ret = RegulatorGetStatus(handle, &status);
if (ret != 0) {
	/*错误处理*/
}
```

## 使用实例<a name="section4_REGULATOR_des"></a>

REGULATOR设备完整的使用示例如下所示，首先获取REGULATOR设备句柄，然后使能，设置电压，获取电压、状态，禁用，最后销毁REGULATOR设备句柄。

```c
void RegulatorTestSample(void)
{
    int32_t ret;
     
    /* REGULATOR设备名称 */
	const char *name = "regulator_virtual_1";
	DevHandle handle = NULL;

	/* 获取REGULATOR设备句柄 */
	handle = RegulatorOpen(name);
	if (handle  == NULL) {
    	HDF_LOGE("RegulatorOpen: failed!\n");
        return;
	}

	/*启用REGULATOR设备*/
	ret = RegulatorEnable(handle);
	if (ret != 0) {
		HDF_LOGE("RegulatorEnable: failed, ret %d\n", ret);
        goto _ERR;
	}
    
    int32_t minUv = 0;		//最小电压为0Uv
	int32_t maxUv = 20000;  //最大电压为20000Uv

	/*设置REGULATOR输出电压范围*/
	ret = RegulatorSetVoltage(handle, minUv, maxUv);
	if (ret != 0) {
		HDF_LOGE("RegulatorSetVoltage: failed, ret %d\n", ret);
        goto _ERR;
	}
    
    uint32_t voltage;

    /*获取REGULATOR电压*/
    ret = RegulatorGetVoltage(handle, &voltage);
    if (ret != 0) {
        HDF_LOGE("RegulatorGetVoltage: failed, ret %d\n", ret);
        goto _ERR;
    }
    
    uint32_t status;

    /*获取REGULATOR状态*/
    ret = RegulatorGetStatus(handle, &status);
    if (ret != 0) {
        HDF_LOGE("RegulatorGetStatus: failed, ret %d\n", ret);
        goto _ERR;
    }

   /*禁用REGULATOR设备*/
    ret = RegulatorDisable(handle);
    if (ret != 0) {
        HDF_LOGE("RegulatorDisable: failed, ret %d\n", ret);
        goto _ERR;
    }
    
_ERR:
    /* 销毁REGULATOR设备句柄 */
    RegulatorClose(handle); 
}
```