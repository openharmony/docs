# 系统参数
## 概述
### 功能简介

OHOS系统参数为各系统服务提供简单易用的键值对访问接口，使得各个系统服务可以通过各自的系统参数来进行业务功能的配置。

### 基本概念

图1 系统参数操作原语

![系统参数操作原语](figures/系统参数操作原语.png)

**表1** 系统参数操作原语说明
| 功能 | 说明 |
| -------- | -------- |
| get      | 获取系统参数的值        |
| set      | 设置系统参数的值        |
| wait     | 同步等待系统参数的值变更 |
| watch    | 异步观察系统参数的值变更 |

#### 系统参数定义

- 系统参数命名格式

  系统参数名称采用点分格式，由多段组成，每一段可以由字母、数字、下划线组成，总长度不超过96字节；系统参数名称分为两类：

  **表2** 系统参数名称

  | 类别 | 名称 | 示例 | 说明 |
  | -------- | -------- | -------- | -------- |
  | 参数名称 | Parameter Name | const.product.**name** | 完整的系统参数名称，末尾不是"."。           |
  | 参数目录 | Parameter Directory | const.product **.**     | 以"."结尾，标识相同前缀的所有系统参数集合。 |

- 系统参数类型

  系统参数一共分为三大类：

  **表3** 系统参数分类

  | 类别 | 前缀 | 说明 |
  | -------- | -------- | -------- |
  | 常量 | const. | 常量参数，一旦赋值后续不会再变更；值最大长度为4096字节（包括结束符）。 |
  | 可写 | 其它 | 可写参数，重启后丢失，值最大长度96字节（包括结束符）。|
  | 可持久化 | persist. | 可写并可持久化保存参数，重启后不会丢失，值最大长度96字节（包括结束符）。|

  每个系统参数名称总体格式如下：
  ```
  [ const | persist ].$sub_system.$desc
  ```
  $sub_system为子系统或模块的名称。

  $desc为子系统或模块下参数的描述字符，可以为点分格式进行分级描述。

#### 系统参数定义规则

每个子系统定义各自模块的系统参数，包括系统参数名称、默认值以及系统参数的权限访问信息。

- 系统参数值定义文件

  - 系统参数值定义文件后缀名为".para" ，其格式示例如下：

    ```shell
    # This is comment
    const.product.name=OHOS-PRODUCT
    const.os.version.api=26
    const.telephony.enable=false|true

    const.test.withblank=My Value
    const.test.withcomment=MyValue # This should be ommitted
    const.test.multiline="This is a multiline parameter.
    Line2 value.
    Last line."
    ```

  - 系统参数必须通过完整的系统参数命令来赋值，赋值方式分为三大类：

    **表4** 系统参数赋值方式

    | 类别 | 示例 | 说明 |
    | -------- | -------- | -------- |
    | 字符串   | const.product.name=OHOS-PRODUCT | 多行字符串需要通过引号扩起来。 |
    | 数字     | const.os.version.api=26         | 数字不需要。|
    | 布尔     | const.telephony.enable=false    | 布尔型的可以为0,1,false,true。|

- 系统参数DAC访问控制定义文件

  当前系统参数的访问权限控制通过自主访问控制（Discretionary Access Control）方式管理，访问权限定义文件后缀名为".para.dac" ，示例如下：

  ```java
  const.product.="root:root:660"
  ```

  如上所示，可以通过参数路径为相同前缀的所有系统参数定义一类访问权限信息；DAC信息通过":"分三段来描述，分别为参数的user，group以及UGO规则信息。

  UGO规则信息每一位的定义如下：

  **图2** UGO规则信息

  ![UGO规则信息](figures/系统参数DAC.png)

- 系统参数配置selinux策略

  - 添加selinux标签

    为系统参数添加selinux标签，首先需要在文件/base/security/selinux/sepolicy/base/public/parameter.te中定义标签，例如：

    ```java
    type servicectrl_param, parameter_attr
    ```

    标签定义完成后，在文件/base/security/selinux/sepolicy/base/public/parameter_contexts中添加和标签关联的系统参数前缀，这里以前缀ohos.servicectrl.为例：

    ```java
    ohos.servicectrl.           u:object_r:servicectrl_param:s0
    ```

  - 给init授权，允许map等操作，在文件/base/security/selinux/sepolicy/ohos_policy/startup/init/public/init.te中补充下面内容：

    ```java
    allow servicectrl_param tmpfs:filesystem associate;
    allow init servicectrl_param:file { map open read relabelto relabelfrom };
    ```

  - 设置写权限，这里允许init samgr hdf_devmgr 进行系统参数写：

    ```java
    allow { init samgr hdf_devmgr } servicectrl_param:parameter_service { set };
    ```

  - 设置读权限，如果只允许部分进程访问可单独对该进程授权：

    ```java
    allow { xxx } servicectrl_param:file { map open read };
    ```

  - 如果全部允许，则设置为：

    ```java
    allow { domain -limit_domain } servicectrl_param:file { map open read };
    ```

-  建议：

   各个子系统只保留两个系统参数标签：

   一个私有，用来控制系统参数设置

   一个公有，允许所有服务进行访问

-  默认参数加载

    系统参数的加载顺序如下：

    **表5** 系统参数加载顺序
    | 类别 | 路径 | 说明 |
    | -------- | -------- | -------- |
    | 内核参数    | /proc/cmdline | 将内核参数中的部分值转化成系统参数，并保存。内核参数中.xxx=valXXX类型的参数都转换成ohos.boot.xxx=valXXX系统参数。 |
    | OS系统参数 | /system/etc/param/ohos_const/*.para | OS固定系统参数值参数优先加载。                               |
    | vendor参数 | /vendor/etc/param/*.para | 厂商定义的系统参数次优先级加载。                             |
    | system参数 | /system/etc/param/*.para | 加载各子系统定义的参数参数。如果系统参数已经存在，则忽略掉。 |
    | persist参数 | /data/parameters/ | 如果持久化参数存在，则最后加载持久化系统参数。持久化系统参数会覆盖加载的默认系统参数。 |

#### 系统参数标签文件大小配置

如果标签对应的系统参数个数多，超过5条时，需要配置系统参数标签文件的大小，默认大小（512），配置文件为/base/startup/init/services/etc/param/ohos.para.size

配置规则：

系统参数标签=大小

例如：

```java
startup_init_param=40960
```

### 约束与限制

仅限小型系统、标准系统下使用。

## 开发指导

### 场景介绍
设定特定的系统参数

### 接口说明

  - Shell命令接口

    通过shell命令中可直接操作系统参数（只在标准系统提供）。系统参数shell命令如下表所示：

    **表6** 系统参数shell命令说明

    | 功能 | 说明 |
    | -------- | -------- |
    | param get [**key**] | 获取指定key名称的系统参数值；如果不指定任何name，则返回所有系统参数值。 |
    | param set **key value** | 设置指定key名称的参数值为value。 |
    | param wait **key** **value** | 同步等待指定key名称的系统参数值与value匹配。value可支持模糊匹配，如"*"表示任何值，"val\*"表示只匹配前三个val字符。 |
    | param watch | 异步观察系统参数的值变更。|

  - syspara系统接口

    在Coding中可以调用下列函数接口，获取对应的系统参数值（系统参数接口返回的为const字符串，不支持free操作）。

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
    | const char *AclGetSerial(void); | 返回当前设备序列号（SN号）（带访问权限检查）。 |
    | int AclGetDevUdid(char *udid, int size); | 获取设备udid（带访问权限检查）。 |

### 开发步骤

1. 系统参数定义

    通过定义子系统或者产品的.para和.para.dac文件，实现默认系统参数的定义和权限控制。

    ​    	在标准系统上通过ohos_prebuilt_para模版安装配置文件到到/etc/param/目录下，GN脚本示例如下：

    ```go
    import("//base/startup/init/services/etc/param/param_fixer.gni")

    ohos_prebuilt_para("ohos.para") {
        source = "//base/startup/init/services/etc/ohos.para"
        part_name = "init"
        module_install_dir = "etc/param"
    }

    ohos_prebuilt_para("ohos.para.dac") {
        source = "//base/startup/init/services/etc/ohos.para.dac"
        part_name = "init"
        module_install_dir = "etc/param"
    }
    ```

    在小系统上，通过copy命令，把对应的系统参数定义文件拷贝到system/etc/param目录下
    ```go
    copy("ohos.para") {
      sources = [ "//base/startup/init/services/etc/param/ohos.para" ]
      outputs = [ "$root_out_dir/system/etc/param/ohos.para" ]
    }
    copy("ohos.para.dac") {
      sources = [ "//base/startup/init/services/etc/param/ohos.para.dac" ]
      outputs = [ "$root_out_dir/system/etc/param/ohos.para.dac" ]
    }
    ```
    在mini系统上，通过action把所有定义的默认系统参数转化成头文件，并编译到系统中
    ```go
    action("lite_const_param_to") {
      script = "//base/startup/init/scripts/param_cfg_to_code.py"
      args = [
        "--source",
        rebase_path(
            "//base/startup/init/services/etc_lite/param/ohos_const/ohospara"),
        "--dest_dir",
        rebase_path("$root_out_dir/gen/init/"),
        "--priority",
        "0",
      ]
      outputs = [ "$target_gen_dir/${target_name}_param_cfg_to_code.log" ]
    }
    ```
2. 系统参数使用实例
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

    char* value2 = GetManufacture();
    printf("Manufacture =%s\n", value2);

    char* value3 = GetBrand();
    printf("GetBrand =%s\n", value3);

    char* value4 = GetMarketName();
    printf("MarketName =%s\n", value4);

    char* value5 = GetProductSeries();
    printf("ProductSeries =%s\n", value5);

    char* value6 = GetProductModel();
    printf("ProductModel =%s\n", value6);

    char* value7 = GetSoftwareModel();
    printf("SoftwareModel =%s\n", value7);

    char* value8 = GetHardwareModel();
    printf("HardwareModel =%s\n", value8);

    char* value9 = GetHardwareProfile();
    printf("Software profile =%s\n", value9);

    char* value10 = GetSerial();
    printf("Serial =%s\n", value10);

    char* value11 = GetOSFullName();
    printf("OS name =%s\n", value11);

    char* value12 = GetDisplayVersion();
    printf("Display version =%s\n", value12);

    char* value13 = GetBootloaderVersion();
    printf("bootloader version =%s\n", value13);

    char* value14 = GetSecurityPatchTag();
    printf("secure patch level =%s\n", value14);

    char* value15 = GetAbiList();
    printf("abi list =%s\n", value15);

    int value16 = GetFirstApiVersion();
    printf("first api level =%d\n", value16);

    char* value17 = GetIncrementalVersion();
    printf("Incremental version = %s\n", value17);

    char* value18 = GetVersionId();
    printf("formal id =%s\n", value18);

    char* value19 = GetBuildType();
    printf("build type =%s\n", value19);

    char* value20 = GetBuildUser();
    printf("build user =%s\n", value20);

    char* value21 = GetBuildHost();
    printf("Build host = %s\n", value21);

    char* value22 = GetBuildTime();
    printf("build time =%s\n", value22);

    char* value23 = GetBuildRootHash();
    printf("build root later..., %s\n", value23);

    char* value24 = GetOsReleaseType();
    printf("OS release type =%s\n", value24);

    char* value25 = GetOsReleaseType();
    printf("OS release type =%s\n", value25);

    char value26[65] = {0};
    GetDevUdid(value26, 65);
    printf("device udid =%s\n", value26);
    ```