# OTA升级


## 概述


### 简介

随着设备系统日新月异，用户如何及时获取系统的更新，体验新版本带来的新的体验，以及提升系统的稳定和安全性成为了每个厂商都面临的严峻问题。

OTA（Over the Air）提供对设备远程升级的能力。升级子系统对用户屏蔽了底层芯片的差异，对外提供了统一的升级接口。基于接口进行二次开发后，可以让厂商的设备（如IP摄像头等）轻松支持远程升级能力。


### 基本概念

- 全量升级包：将所有目标版本的镜像均通过全量镜像的方式打包获得的升级包。

- 差分升级包：对源版本和目标版本差分，获得两个版本镜像之间的差异，以这种方式打包制作升级包。


### 实现原理

OTA 的升级原理是利用升级包制作工具，将编译出的版本打包生成升级包。厂商设备集成 OTA 升级能力后，将升级包上传至服务器，通过升级应用下载升级包，触发并完成升级。

<a href="#ab-升级场景">AB 升级</a>：是 OTA 升级的一个场景，原理是设备有一套备份的B系统，在A系统运行时，可以在正常使用的状态下，静默更新B系统，升级成功后，重启切换新系统，实现版本更新的机制。


### 约束与限制

- 支持基于Hi3861/Hi3516DV300/RK3568芯片的开源套件。

- 对Hi3516DV300/RK3568开源套件，设备需要支持SD卡（VFAT格式）。

- 生成升级包需要在linux系统下面执行。

- 目前轻量和小型系统仅支持全量包升级，暂不支持差分包、变分区包升级。

- AB 升级只适用于标准系统支持 AB 分区启动的设备。


## 环境准备

- 在Windows上，下载安装OpenSSL工具，并配置环境变量。
- 准备升级包制作工具
- 编译出版本镜像文件
- 将编译结果中的 out/rk3568/clang_x64/updater/updater/ 下的 diff 文件，out/rk3568/clang_x64/thirdparty/e2fsprogs 路径下的 libext2fs.so、e2fsdriod、libext2_com_err.so、libext2_misc.so 文件放入做包工具此路径下：packaging_tools/lib/


## 开发流程

<a href="#生成公私钥对">1. 使用OpenSSL工具生成公私钥对</a>

<a href="#制作升级包">2. 使用升级包制作工具制作升级包</a>

&ensp;&ensp;<a href="#轻量与小型系统升级包制作">2.1 轻量与小型系统升级包</a>

&ensp;&ensp;<a href="#标准系统升级包制作">2.2 标准系统升级包</a>

<a href="#上传升级包">3. 将升级包上传到厂商的OTA服务器</a>

<a href="#下载升级包">4. 厂商应用从OTA服务器下载升级包</a>

<a href="#厂商应用集成ota能力">5. 厂商应用集成OTA能力</a>

&ensp;&ensp;<a href="#api-应用默认场景">5.1 API 应用默认场景</a>

&ensp;&ensp;<a href="#api-应用定制场景">5.2 API 应用定制场景</a>

&ensp;&ensp;<a href="#ab-升级场景">5.2 AB 升级场景</a>


## 开发步骤


### 生成公私钥对
1. 使用OpenSSL工具生成公私钥对，将公钥 signing_cert.crt 放入做包工具此路径下：packaging_tools/sign_cert/

3. 请妥善保管私钥文件，在升级包制作过程中将私钥文件作为制作命令的参数带入，用于升级包签名，公钥用于升级时对升级包进行签名校验，公钥的放置如下： 轻量和小型系统将生成的公钥内容预置在代码中，需要厂商实现 HotaHalGetPubKey 这个接口来获取公钥。标准系统需要将生成的公钥放在device或vendor目录下的 /hisilicon/hi3516dv300/build/updater_config/signing_cert.crt 这个文件中。

5. 对使用 Hi3516DV300 套件的小型系统，在上一步的基础上，还需用public_arr.txt里面的全部内容替换uboot模块third_party\u-boot\u-boot-2020.01\product\hiupdate\verify\update_public_key.c 中的g_pub_key中的全部内容。
   示例，uboot模块的公钥：

   ```c
   static unsigned char g_pub_key[] = {
       0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 0x01, 0x01,
       0x00, 0xBF, 0xAA, 0xA5, 0xB3, 0xC2, 0x78, 0x5E,
   }
   ```


### 制作升级包


#### 轻量与小型系统升级包制作

1. 创建目标版本（target_package）文件夹，文件格式如下：

   轻量级系统和AB升级的小型系统不需要 OTA.tag 和 config。
     
   ```text
    target_package
    ├── OTA.tag
    ├── config
    ├── {component_1}
    ├── {component_2}
    ├── ......
    ├── {component_N}
    └── updater_config
        └── updater_specified_config.xml
   ```

2. 将待升级的组件，包括镜像文件（例如：rootfs.img）等放入目标版本文件夹的根目录下，代替上文结构中的{component_N}部分。

3. 填写“updater_config”文件夹中的“updater_specified_config.xml”组件配置文件。
   组件配置文件“updater_specified_config.xml”，格式如下：

     
   ```xml
   <?xml version="1.0"?>
   <package>
       <head name="Component header information">
           <info fileVersion="02" prdID="hisi" softVersion="OpenHarmony x.x" date="202x.xx.xx" time="xx:xx:xx">head info</info>
       </head>
       <group name="Component information">
       <component compAddr="ota_tag" compId="27" resType="5" compType="0" compVer="1.0">./OTA.tag</component>
       <component compAddr="config" compId="23" resType="5" compType="0" compVer="1.0">./config</component>
       <component compAddr="bootloader" compId="24" resType="5" compType="0" compVer="1.0">./u-boot-xxxx.bin</component>
       </group>
   </package>
   ```

     **表1** 组件配置文件节点说明
   
   | 信息类别 | 节点名称 | 节点标签 | 是否必填 | 内容说明 | 
   | -------- | -------- | -------- | -------- | -------- |
   | 头信息（head节点） | info节点 | / | 必填 | 该节点内容配置为：head&nbsp;info | 
   | 头信息（head节点） | info节点 | fileVersion | 必填 | update.bin文件校验方式，该节点内容配置为：02 |
   | 头信息（head节点） | info节点 | prdID | 必填 | 保留字段，内容不影响升级包生成 | 
   | 头信息（head节点） | info节点 | softVersion | 必填 | 软件版本号，即升级包版本号，版本必须比基础版本大，且OpenHarmony后没有其他字母，否则无法生产升级 | 
   | 头信息（head节点） | info节点 | _date_ | _必填_ | 升级包制作日期，保留字段，不影响升级包生成 | 
   | 头信息（head节点） | info节点 | _time_ | _必填_ | 升级包制作时间，保留字段，不影响升级包生成 |  
   | 组件信息（group节点） | component节点 | / | 必填 | 该节点内容配置为：要打入升级包的组件/镜像文件的路径，默认为版本包根路径 | 
   | 组件信息（group节点） | component节点 | compAddr | 必填 | 该组件所对应的分区名称，例如：system、vendor等。 | 
   | 组件信息（group节点） | component节点 | compId | 必填 | 组件Id，不同组件Id不重复 | 
   | 组件信息（group节点） | component节点 | resType | 必填 | 保留字段，不影响升级包生成 | 
   | 组件信息（group节点） | component节点 | compType | 必填 | 处理方式全量/差分，配置镜像处理方式的，0为全量处理、1为差分处理。 | 

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 对轻量系统/小型系统，不支持做差分升级，component标签中，属性compType值，不能配为 1，必须全部配置为 0。
   > 
   > 对轻量系统/小型系统，不支持变分区升级包的制作。

4. 创建“OTA.tag文件”，内容为OTA升级包的魔数，固定如下：
     
   ```text
   package_type:ota1234567890qwertw
   ```

5. 创建“config文件”，内容为设置bootargs以及bootcmd的信息。
   配置例如下：

     
   ```text
   setenv bootargs 'mem=128M console=ttyAMA0,115200 root=/dev/mmcblk0p3 rw rootfstype=ext4 rootwait blkdevparts=mmcblk0:1M
   (u-boot.bin),9M(kernel.bin),50M(rootfs_ext4.img),50M(userfs.img)' setenv bootcmd 'mmc read 0x0 0x82000000 0x800 0x4800;bootm 0x82000000'
   ```

6. 执行升级包制作命令。
     
   ```text
   python build_update.py ./target_package/ ./output_package/ -pk ./rsa_private_key3072.pem -nz -nl2
   ```

   - ./target_package/：指定target_package路径。
   - ./output_package/：指定升级包输出路径。
   - -pk ./rsa_private_key3072.pem：指定私钥路径。
   - -nz：打开not zip模式开关
   - -nl2：打开非“标准系统”模式开关


#### 标准系统升级包制作
1. 创建目标版本（target_package）文件夹，文件格式如下：

     
   ```text
   target_package
   ├── {component_1}
   ├── {component_2}
   ├── ......
   ├── {component_N}
   └── updater_config
           ├── BOARD.list
           ├── VERSION.mbn
           └── updater_specified_config.xml
   ```

2. 将待升级的组件（包括镜像文件和updater_binary文件）放入目标版本文件夹的根目录下，代替上文结构中的{component_N}部分。

   以RK3568为例，镜像文件的构建位置为：out/rk3568/packages/phone/images/

   二进制升级文件updater_binary位置为：out/rk3568/packages/phone/system/bin/

3. 填写“updater_config”文件夹中的组件配置文件。

4. 配置“updater_config”文件夹中当前升级包支持的产品list：**BOARD.list**。

   例如配置如下：

     
   ```text
   HI3516
   RK3568
   ```

   厂家可在路径base/updater/updater/utils/utils.cpp文件中的GetLocalBoardId()接口进行Local BoardId的配置。请确保utils.cpp文件中的Local BoardId包含在BOARD.list中，否则无法升级。

5. 配置“updater_config”文件夹中当前升级包所支持的版本范围：**VERSION.mbn**。

   版本名称格式：Hi3516DV300-eng 10 QP1A.XXXXXX.{大版本号（6位）}.XXX{小版本号（3位）}。

   例如：Hi3516DV300-eng 10 QP1A.190711.020。名称中“190711”为大版本号，“020”为小版本号。

   配置例如下：

     
   ```text
   Hi3516DV300-eng 10 QP1A.190711.001
   Hi3516DV300-eng 10 QP1A.190711.020
   ```

   请确保基础版本号包含在VERSION.mbn中

6. 针对增量（差分）升级包，还需要准备一个源版本（source_package），文件内容格式与目标版本（target_package）相同，需要打包成zip格式，即为：source_package.zip。

7. 针对变分区升级包，还需要提供分区表文件“partition_file.xml”，partition_file.xml配置节点说明如下，可通过-pf参数指定。

   分区表会随镜像一起生成，格式如下：

     
   ```xml
   <?xml version="1.0" encoding="GB2312" ?>
   <Partition_Info>
   <Part Sel="1" PartitionName="镜像名称1" FlashType="flash磁盘类型" FileSystem="文件系统类型" Start="该分区起始地址" Length="该分区大小" SelectFile="实际镜像所在路径"/>
   <Part Sel="1" PartitionName="镜像名称2" FlashType="flash磁盘类型" FileSystem="文件系统类型" Start="该分区起始地址" Length="该分区大小" SelectFile="实际镜像所在路径"/>
   </Partition_Info>
   ```

   **表2** 分区表Part标签说明

     | 标签名称 | 标签说明 | 
   | -------- | -------- |
   | Sel | 该分区是否生效，1表明生效，0表明不生效。 | 
   | PartitionName | 分区名称，例如：fastboot、boot等。 | 
   | FlashType | flash磁盘类型，例如emmc、ufs等。 | 
   | FileSystem | 文件系统类型，例如ext3/4、f2fs等，也可能为none。 | 
   | Start | 分区起始位置，所有分区最起始为0，单位为兆（M）。 | 
   | Length | 分区占用长度，单位为兆（M）。 | 
   | SelectFile | 实际镜像或文件所在路径。 | 

8. 执行升级包制作命令。

   **全量升级包**

   命令如下：

     
   ```text
   python build_update.py ./target_package/ ./output_package/ -pk ./rsa_private_key2048.pem
   ```

   - ./target_package/：指定target_package路径。
   - ./output_package/：指定升级包输出路径。
   - -pk ./rsa_private_key2048.pem：指定私钥文件路径。

   **增量（差分）升级包**

   命令如下：

     
   ```text
   python build_update.py ./target_package/ ./output_package/  -s ./source_package.zip  -pk ./rsa_private_key2048.pem
   ```

   - ./target_package/：指定target_package路径。
   - ./output_package/：指定升级包输出路径。
   - -s ./source_package.zip：指定“source_package.zip”路径，当存在镜像需要进行差分处理时，必须使用-s参数指定source版本包。
   - -pk ./rsa_private_key2048.pem：指定私钥文件路径。

   **变分区升级包**

   命令如下：

     
   ```text
   python build_update.py  ./target_package/ ./output_package/  -pk ./rsa_private_key2048.pem  -pf ./partition_file.xml
   ```

   - ./target_package/：指定target_package路径。
   - ./output_package/：指定升级包路径。
   - -pk ./rsa_private_key2048.pem：指定私钥文件路径。
   - -pf ./partition_file.xml：指定分区表文件路径。


### 上传升级包

将升级包上传到厂商的OTA服务器。


### 下载升级包

1. 厂商应用从OTA服务器下载升级包。

2. 对Hi3516DV300开源套件，需要插入SD卡(容量&gt;100MBytes)。


### 厂商应用集成OTA能力

1. 轻量与小型系统

   - 调用OTA模块的动态库libhota.so，对应头文件hota_partition.h和hota_updater.h路径：base\update\sys_installer_lite\interfaces\kits\。
   - libhota.so对应的源码路径为：base\update\sys_installer_lite\frameworks\source。
   - API的使用方法，见本文“API应用场景”和API文档的OTA接口章节。
   - 如果需要适配开发板，请参考HAL层头文件：base\update\sys_installer_lite\hals\hal_hota_board.h。

2. 标准系统请参考[JS参考规范](../../application-dev/reference/apis/js-apis-update.md)指导中的升级接口参考规范。


#### API 应用默认场景

升级包是按照上文“生成公私钥对”和“生成升级包”章节制作的。


##### 开发指导

1. 应用侧通过下载，获取当前设备升级包后，调用HotaInit接口初始化OTA模块。

2. 调用HotaWrite接口传入升级包数据流，接口内部实现校验、解析及写入升级数据流。

3. 写入完成后，调用HotaRestart接口重启系统，升级过程中，使用HotaCancel接口可以取消升级。


##### 示例代码

  使用OpenHarmony的“升级包格式和校验方法”进行升级。
  
```cpp
int main(int argc, char **argv)
{
    printf("this is update print!\r\n");
    if (HotaInit(NULL, NULL) < 0) {
        printf("ota update init fail!\r\n");
        return -1;
    }
    int fd = open(OTA_PKG_FILE, O_RDWR, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        printf("file open failed, fd = %d\r\n", fd);
        (void)HotaCancel();
        return -1;
    }
    int offset = 0;
    int fileLen = lseek(fd, 0, SEEK_END);
    int leftLen = fileLen;
    while (leftLen > 0) {
        if (lseek(fd, offset, SEEK_SET) < 0) {
            close(fd);
            printf("lseek fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        int tmpLen = leftLen >= READ_BUF_LEN ? READ_BUF_LEN : leftLen;
        (void)memset_s(g_readBuf, READ_BUF_LEN, 0, READ_BUF_LEN);
        if (read(fd, g_readBuf, tmpLen) < 0) {
            close(fd);
            printf("read fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        if (HotaWrite((unsigned char *)g_readBuf, offset, tmpLen) != 0) {
            printf("ota write fail!\r\n");
            close(fd);
            (void)HotaCancel();
            return -1;
        }
        offset += READ_BUF_LEN;
        leftLen -= tmpLen;
    }
    close(fd);
    printf("ota write finish!\r\n");
    printf("device will reboot in 10s...\r\n");
    sleep(10);
    (void)HotaRestart();
    return 0;
}
```


#### API 应用定制场景

升级包不是按照上文“生成公私钥对”和“生成升级包”章节制作的，是通过其它方式制作的。


##### 开发指导

1. 应用侧通过下载，获取当前设备升级包后，调用HotaInit接口初始化。

2. 使用HotaSetPackageType接口设置NOT_USE_DEFAULT_PKG，使用"定制"流程。

3. 调用HotaWrite接口传入升级包数据流，写入设备。

4. 写入完成后，调用HotaRead接口读取数据，厂商可以自行校验升级包。

5. 调用HotaSetBootSettings设置启动标记，在重启后需要进入uboot模式时使用（可选）。

6. 调用HotaRestart接口，进行重启，升级过程中，使用HotaCancel接口可以取消升级。


##### 示例代码

  使用非OpenHarmony的“升级包格式和校验方法“进行升级。
  
```cpp
int main(int argc, char **argv)
{
    printf("this is update print!\r\n");
    if (HotaInit(NULL, NULL) < 0) {
        printf("ota update init fail!\r\n");
        (void)HotaCancel();
        return -1;
    }
    (void)HotaSetPackageType(NOT_USE_DEFAULT_PKG);
    int fd = open(OTA_PKG_FILE, O_RDWR, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        printf("file open failed, fd = %d\r\n", fd);
        (void)HotaCancel();
        return -1;
    }
    int offset = 0;
    int fileLen = lseek(fd, 0, SEEK_END);
    int leftLen = fileLen;
    while (leftLen > 0) {
        if (lseek(fd, offset, SEEK_SET) < 0) {
            close(fd);
            printf("lseek fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        int tmpLen = leftLen >= READ_BUF_LEN ? READ_BUF_LEN : leftLen;
        (void)memset_s(g_readBuf, READ_BUF_LEN, 0, READ_BUF_LEN);
        if (read(fd, g_readBuf, tmpLen) < 0) {
            close(fd);
            printf("read fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        if (HotaWrite((unsigned char *)g_readBuf, offset, tmpLen) != 0) {
            printf("ota write fail!\r\n");
            close(fd);
            (void)HotaCancel();
            return -1;
        }
        offset += READ_BUF_LEN;
        leftLen -= tmpLen;
    }
    close(fd);
    printf("ota write finish!\r\n");
    leftLen = fileLen;
    while (leftLen > 0) {
        int tmpLen = leftLen >= READ_BUF_LEN ? READ_BUF_LEN : leftLen;
        (void)memset_s(g_readBuf, READ_BUF_LEN, 0, READ_BUF_LEN);
        if (HotaRead(offset, READ_BUF_LEN, (unsigned char *)g_readBuf) != 0) {
            printf("ota write fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        /* do your verify and parse */
        offset += READ_BUF_LEN;
        leftLen -= tmpLen;
    }
    /* set your boot settings */
    (void)HotaSetBootSettings();
    printf("device will reboot in 10s...\r\n");
    sleep(10);
    (void)HotaRestart();
    return 0;
}
```


##### 系统升级

厂商应用调用OTA模块的API，OTA模块执行升级包的签名验证、版本防回滚、烧写落盘功能，升级完成后自动重启系统。

对于使用Hi3516DV300开源套件的轻量和小型系统，在需要实现防回滚功能的版本中，需要增加LOCAL_VERSION的值，如"ohos default 1.0"-&gt;"ohos default 1.1"，LOCAL_VERSION在device\hisilicon\third_party\uboot\u-boot-2020.01\product\hiupdate\ota_update\ota_local_info.c中。

  示例，增加版本号。
  
```cpp
const char *get_local_version(void)
{
#if defined(CONFIG_TARGET_HI3516EV200) || \
    defined(CONFIG_TARGET_HI3516DV300)
#define LOCAL_VERSION "ohos default 1.0" /* increase: default release version */
```


#### AB 升级场景


##### 开发流程

1. 应用侧下载获取当前设备升级包
2. update_service 通过 SAMGR 将系统安装部件拉起
3. 由系统安装部件完成静默热安装
4. 下一次重启时激活新版本


##### 开发步骤

- JS API 通过 update_service 模块处理AB升级相关流程

   1.升级包安装进度显示接口：
   ```cpp
   on(eventType: "upgradeProgress", callback: UpdateProgressCallback): void;
   ```
   
   2.设置激活策略（立即重启，夜间重启，随下次重启激活）接口：
   ```cpp
   upgrade(apply)
   ```


- update_service 通过 SAMGR 将系统安装服务拉起
   
   1.拉起系统安装服务，并建立IPC连接：
   ```cpp
   int SysInstallerInit(void* callback)
   ```
   
   2.安装指定路径的AB升级包：
   ```cpp
   int StartUpdatePackageZip(string path)
   ```
   
   3.设置进度回调：
   ```cpp
   int SetUpdateProgressCallback(void* callback)
   ```
   
   4.获取升级包安装状态（0 未开始,1 安装中,2 安装结束）:
   ```cpp
   int GetUpdateStatus()
   ```


- 使用 HDI 接口南向激活新版本

   1.获取当前启动的slot，来决策待升级的分区：
   ```cpp
   int GetCurrentSlot()
   ```
   
   2.在升级结束后，将已升级好的slot进行切换，重启完成新版本更新：
   ```cpp
   int SetActiveBootSlot(int slot)
   ```
   
   3.在升级开始时，将待升级的分区slot设置成unbootable状态：
   ```cpp
   int setSlotUnbootable(int slot)
   ```
   
   4.获取slot个数，1位非AB，2为AB分区，用例兼容AB和非AB的流程判断：
   ```cpp
   int32 GetSlotNum(void)
   ```


##### 常见问题

1. 升级包下载，安装过程出现异常
<br>系统保持当前版本继续运行，在下一个搜包周期重新完成版本升级过程

2. 升级包完成非启动分区的包安装，在激活过程中出现异常
<br>需要进行异常回滚，并将无法启动的分区设置为 unbootable，下次则不从该分区启动


##### 调测验证

设备能在正常使用的情况下，在后台从服务器下载升级包，完成静默升级，并按照厂商设置的策略重启激活版本。