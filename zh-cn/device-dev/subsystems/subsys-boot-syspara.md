# syspara系统属性组件


## 系统参数简介

syspara系统为各系统服务提供简单易用的键值对访问接口，使得各个系统服务可以通过各自的系统参数来进行业务功能的配置。系统参数的访问和操作有下图所示几个基本原语：

  **图1** 系统参数操作原语

  ![zh-cn_image_0000001154900834](figures/zh-cn_image_0000001154900834.png)

  **表1** 系统参数操作原语说明

| 功能 | 说明 | 
| -------- | -------- |
| get | 获取系统参数的值。 | 
| set | 设置系统参数的值。 | 
| wait | 同步等待系统参数的值变更。 | 
| watch | 异步观察系统参数的值变更。 | 

系统参数名称采用点分格式由多段组成，每一段由字母、数字、下划线组成，总长度不超过96字节。系统参数名称分为两类：

  **表2** 系统参数名称

| 类别 | 名称 | 示例 | 说明 | 
| -------- | -------- | -------- | -------- |
| 参数名称 | Parameter&nbsp;Name | const.product.**name** | 完整的系统参数名称，末尾不是"."。 | 
| 参数目录 | Parameter&nbsp;Directory | const.product**.** | 以"."结尾，标识相同前缀的所有系统参数集合。 | 

系统参数一共分为三大类：

  **表3** 系统参数分类

| 类别 | 前缀 | 说明 | 
| -------- | -------- | -------- |
| 常量 | **const.** | 常量参数，一旦赋值后续不会再变更，值最大长度为4096字节（包括结束符）。 | 
| 可写 | 其它 | 可写参数，重启后丢失，值最大长度96字节（包括结束符）。 | 
| 可持久化 | **persist.** | 可写并可持久化保存参数，重启后不会丢失，值最大长度96字节（包括结束符）。 | 

每个系统参数名称总体格式如下：[**const**|**persist**].**$sub_system**.**$desc**。

$sub_system为子系统或模块的名称。

$desc为子系统或模块下参数的描述字符，可以为点分格式进行分级描述。


## 系统参数定义规则

每个子系统定义各自模块的系统参数，包括系统参数名称、默认值以及系统参数的权限访问信息。


### 系统参数值定义文件

系统参数值定义文件后缀名为**".para"**，其格式示例如下：


```
# This is comment
const.product.name=OHOS-PRODUCT
const.os.version.api=26
const.telephony.enable=false|true

const.test.withblank=My Value
```

注意：系统参数值不支持注释及换行。


```
# 不支持
const.test.withcomment=MyValue # This should be omitted
# 不支持
const.test.multiline="This is a multiline parameter.
Line2 value.
Last line."
```

系统参数必须通过完整的系统参数命令来赋值，赋值方式分为三大类：

  **表4** 系统参数赋值方式

| 类别 | 示例 | 说明 | 
| -------- | -------- | -------- |
| 字符串 | const.product.name=OHOS-PRODUCT | 不支持多行字符串，不支持注释。 | 
| 数字 | const.os.version.api=26 | 数字不需要引号。 | 
| 布尔 | const.telephony.enable=false | 布尔型的可以为0,1或false,true。 | 


### 系统参数DAC访问控制定义文件

当前系统参数的访问权限控制通过自主访问控制（Discretionary Access Control）方式管理，访问权限定义文件后缀名为**".para.dac"**，示例如下：


```
const.product.="root:root:660"
```

如上所示，可以通过**参数路径**为相同前缀的所有系统参数定义一类访问权限信息；DAC信息通过":"分三段来描述，分别为参数的user，group以及UGO规则信息。

UGO规则信息每一位的定义如下图所示：

  **图2** UGO规则信息

  ![zh-cn_image_0000001155060626](figures/zh-cn_image_0000001155060626.png)


### 系统参数定义文件安装方法

.para和.para.dac文件都通过ohos_prebuilt_para模版安装到/etc/param/目录下，GN脚本示例如下：


```go
import("//base/startup/init_lite/services/etc/param/param_fixer.gni")

ohos_prebuilt_para("ohos.para") {
    source = "//base/startup/init_lite/services/etc/ohos.para"
    part_name = "init"
    module_install_dir = "etc/param"
}

ohos_prebuilt_para("ohos.para.dac") {
    source = "//base/startup/init_lite/services/etc/ohos.para.dac"
    part_name = "init"
    module_install_dir = "etc/param"
}
```

ohos_prebuilt_para模版会对para文件进行格式化处理，包括去注释，去空格等操作。该模版还支持通过extra_paras参数扩展编译时参数，示例如下：

```go
  ohos_prebuilt_para("ohos.para") {
    source = "//base/startup/init_lite/services/etc/param/ohos.para"
    part_name = "init"
    if (target_cpu == "arm64") {
      extra_paras = [ "const.product.cpu.abilist=arm64-v8a" ]
    }
    module_install_dir = "etc/param"
  }
```

其中extra_paras值的系统参数值处理方式为：source文件中没有定义该系统参数则添加；source文件中已经定义该参数则覆盖。

### 系统参数值定义文件的加载顺序

系统参数值的加载顺序如下：

  **表5** 系统参数加载顺序

| 类别 | 路径 | 说明 | 
| -------- | -------- | -------- |
| 内核参数 | /proc/cmdline | 内核参数中ohospara.xxx=valXXX类型的参数都转换成ohos.boot.xxx=valXXX系统参数。 | 
| OS固定值 | /system/etc/param/ohos_const/\*.para | OS固定系统参数值参数优先加载。 | 
| vendor参数值 | /vendor/etc/param/\*.para | 厂商参数值定义文件次优先级加载，可以覆盖system参数值定义。 | 
| system参数值 | /system/etc/param/\*.para | 最后加载system参数值定义文件，文件中的系统参数值如果已经存在，则忽略掉。 | 


## shell命令使用说明

通过shell命令中可直接操作系统参数。系统参数shell命令如下表所示：


  **表6** 系统参数shell命令说明

| 功能 | 说明 | 
| -------- | -------- |
| param&nbsp;get&nbsp;[**key**] | 获取指定key名称的系统参数值；如果不指定任何name，则返回所有系统参数值。 | 
| param&nbsp;set&nbsp;**key&nbsp;value** | 设置指定key名称的参数值为value。 | 
| param&nbsp;wait&nbsp;**keyvalue** | 同步等待指定key名称的系统参数值与value匹配。value可支持模糊匹配，如"\*"表示任何值，"val\*"表示只匹配前三个val字符。 | 
| param&nbsp;dump | 显示系统参数的统计信息。 | 


## syspara系统接口说明

  **表7** 系统属性接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| int&nbsp;GetParameter(const&nbsp;char\*&nbsp;key,&nbsp;const&nbsp;char\*&nbsp;def,&nbsp;char\*&nbsp;value,&nbsp;unsigned&nbsp;int&nbsp;len) | 获取系统参数。 | 
| int&nbsp;SetParameter(const&nbsp;char\*&nbsp;key,&nbsp;const&nbsp;char\*&nbsp;value) | 设置/更新系统参数。 | 
| const&nbsp;char\*&nbsp;GetDeviceType(void) | 返回当前设备类型。 | 
| const&nbsp;char\*&nbsp;GetManufacture(void) | 返回当前设备生产厂家信息。 | 
| const&nbsp;char\*&nbsp;GetBrand(void) | 返回当前设备品牌信息。 | 
| const&nbsp;char\*&nbsp;GetMarketName(void) | 返回当前设备传播名。 | 
| const&nbsp;char\*&nbsp;GetProductSeries(void) | 返回当前设备产品系列名。 | 
| const&nbsp;char\*&nbsp;GetProductModel(void) | 返回当前设备认证型号。 | 
| const&nbsp;char\*&nbsp;GetSoftwareModel(void) | 返回当前设备内部软件子型号。 | 
| const&nbsp;char\*&nbsp;GetHardwareModel(void) | 返回当前设备硬件版本号。 | 
| const&nbsp;char\*&nbsp;GetHardwareProfile(void) | 返回当前设备硬件profile。 | 
| const&nbsp;char\*&nbsp;GetSerial(void) | 返回当前设备序列号（SN号）。 | 
| const&nbsp;char\*&nbsp;GetOSFullName(void) | 返回操作系统名。 | 
| const&nbsp;char\*&nbsp;GetDisplayVersion(void) | 返回当前设备用户可见的软件版本号。 | 
| const&nbsp;char\*&nbsp;GetBootloaderVersion(void) | 返回当前设备Bootloader版本号。 | 
| const&nbsp;char\*&nbsp;GetSecurityPatchTag(void) | 返回安全补丁标签。 | 
| const&nbsp;char\*&nbsp;GetAbiList(void) | 返回当前设备支持的指令集（Abi）列表。 | 
| int&nbsp;GetSdkApiVersion(void) | 返回与当前系统软件匹配的SDK&nbsp;API&nbsp;版本号。 | 
| int&nbsp;GetFirstApiVersion(void) | 返回系统软件首版本SDK&nbsp;API&nbsp;版本号。 | 
| const&nbsp;char\*&nbsp;GetIncrementalVersion(void) | 返回差异版本号。 | 
| const&nbsp;char\*&nbsp;GetVersionId(void) | 返回版本id。 | 
| const&nbsp;char\*&nbsp;GetBuildType(void) | 返回构建类型。 | 
| const&nbsp;char\*&nbsp;GetBuildUser(void) | 返回构建账户用户名。 | 
| const&nbsp;char\*&nbsp;GetBuildHost(void) | 返回构建主机名。 | 
| const&nbsp;char\*&nbsp;GetBuildTime(void) | 返回构建时间。 | 
| const&nbsp;char\*&nbsp;GetBuildRootHash(void) | 返回当前版本hash。 | 
| const&nbsp;char\*&nbsp;GetOsReleaseType(void) | 返回系统发布类型。 | 
| int&nbsp;GetDevUdid(char&nbsp;\*udid,&nbsp;int&nbsp;size) | 获取设备udid。 | 


## 开发实例

系统属性使用实例


```
// set && get
char key1[] = "rw.sys.version";
char value1[] = "10.1.0";
int ret = SetParameter(key1, value1);
char valueGet1[128] = {0};
ret = GetParameter(key1, "version=10.1.0", valueGet1, 128);

// get sysparm
char* value1 = GetDeviceType();
printf("Product type =%s\n", value1);
free(value1);
char* value2 = GetManufacture();
printf("Manufacture =%s\n", value2);
free(value2);
char* value3 = GetBrand();
printf("GetBrand =%s\n", value3);
free(value3);
char* value4 = GetMarketName();
printf("MarketName =%s\n", value4);
free(value4);
char* value5 = GetProductSeries();
printf("ProductSeries =%s\n", value5);
free(value5);
char* value6 = GetProductModel();
printf("ProductModel =%s\n", value6);
free(value6);
char* value7 = GetSoftwareModel();
printf("SoftwareModel =%s\n", value7);
free(value7);
char* value8 = GetHardwareModel();
printf("HardwareModel =%s\n", value8);
free(value8);
char* value9 = GetHardwareProfile();
printf("Software profile =%s\n", value9);
free(value9);
char* value10 = GetSerial();
printf("Serial =%s\n", value10);
free(value10);
char* value11 = GetOSFullName();
printf("OS name =%s\n", value11);
free(value11);
char* value12 = GetDisplayVersion();
printf("Display version =%s\n", value12);
free(value12);
char* value13 = GetBootloaderVersion();
printf("bootloader version =%s\n", value13);
free(value13);
char* value14 = GetSecurityPatchTag();
printf("secure patch level =%s\n", value14);
free(value14);
char* value15 = GetAbiList();
printf("abi list =%s\n", value15);
free(value15);
int value16 = GetFirstApiVersion();
printf("first api level =%d\n", value16);
free(value16);
char* value17 = GetIncrementalVersion();
printf("Incremental version = %s\n", value17);
free(value17);
char* value18 = GetVersionId();
printf("formal id =%s\n", value18);
free(value18);
char* value19 = GetBuildType();
printf("build type =%s\n", value19);
free(value19);
char* value20 = GetBuildUser();
printf("build user =%s\n", value20);
free(value20);
char* value21 = GetBuildHost();
printf("Build host = %s\n", value21);
free(value21);
char* value22 = GetBuildTime();
printf("build time =%s\n", value22);
free(value22);
char* value23 = GetBuildRootHash();
printf("build root later..., %s\n", value23);
free(value23);
char* value24 = GetOsReleaseType();
printf("OS release type =%s\n", value24);
free(value24);
char* value25 = GetOsReleaseType();
printf("OS release type =%s\n", value25);
free(value25);
char value26[65] = {0};
GetDevUdid(value26, 65);
printf("device udid =%s\n", value26);
free(value26);
```
