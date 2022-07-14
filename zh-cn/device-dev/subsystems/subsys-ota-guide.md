# OTA升级


## 概述

OTA（Over the Air）提供对设备远程升级的能力，可以让您的设备（如IP摄像头等），轻松支持远程升级能力。目前轻量和小型系统仅支持全量包升级，暂不支持差分包升级。全量包升级是将新系统全部内容做成升级包，进行升级；差分包升级是将新老系统的差异内容做成升级包，进行升级。


## 约束与限制

- 支持基于Hi3861/Hi3518EV300/Hi3516DV300芯片的开源套件。

- 对Hi3518EV300/Hi3516DV300开源套件，设备需要支持SD卡（VFAT格式）。
  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
  > 生成升级包需要在linux系统下面执行。


## 生成公私钥对

1. 准备工作：在Windows上，下载安装[OpenSSL工具](http://slproweb.com/products/Win32OpenSSL.html)，并配置环境变量。

2. 使用OpenSSL工具生成公私钥对。

3. 请妥善保管私钥文件，在升级包制作过程中将私钥文件作为制作命令的参数带入，用于升级包签名，公钥用于升级时对升级包进行签名校验，公钥的放置如下：
   轻量和小型系统将生成的公钥内容预置在代码中，需要厂商实现 HotaHalGetPubKey 这个接口来获取公钥。标准系统需要将生产的公钥放在 ./device/hisilicon/hi3516dv300/build/updater_config/signing_cert.crt 这个文件中。

4. 对使用 Hi3518EV300/Hi3516DV300 套件的轻量和小型系统，在上一步的基础上，还需用public_arr.txt里面的全部内容替换uboot模块device\hisilicon\third_party\uboot\u-boot-2020.01\product\hiupdate\verify\update_public_key.c 中的g_pub_key中的全部内容。
   示例，uboot模块的公钥：

     
   ```
   static unsigned char g_pub_key[PUBKEY_LEN] = {
       0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 0x01, 0x01,
       0x00, 0xBF, 0xAA, 0xA5, 0xB3, 0xC2, 0x78, 0x5E,
   }
   ```


## 生成升级包


### 轻量与小型系统升级包制作

1. 创建目标版本（target_package）文件夹，文件格式如下：
     
   ```
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

2. 将待升级的组件，包括镜像文件（例如：rootfs.img等）等放入目标版本文件夹的根目录下，代替上结构中的{component_N}部分。

3. 填写“update_config”文件夹中的“updater_specified_config.xml”组件配置文件。
   组件配置文件“updater_specified_config.xml”，格式如下：

     
   ```
   <?xml version="1.0"?>
   <package>
       <head name="Component header information">
           <info fileVersion="01" prdID="hisi" softVersion="OpenHarmony x.x" date="202x.xx.xx" time="xx:xx:xx">head info</info>
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
   | fileVersion | 必填 | 保留字段，内容不影响升级包生成 | 
   | prdID | 必填 | 保留字段，内容不影响升级包生成 | 
   | softVersion | 必填 | 软件版本号，即升级包版本号，版本必须在“VERSION.mbn”范围内，否则无法生产升级 | 
   | date | 必填 | 升级包制作日期，保留字段，不影响升级包生成 | 
   | time | 必填 | 升级包制作时间，保留字段，不影响升级包生成 | 

     **表2** 组件配置文件节点说明
   
   | 信息类别 | 节点名称 | 节点标签 | 是否必填 | 内容说明 | 
   | -------- | -------- | -------- | -------- | -------- |
   | 头信息（head节点） | info节点 | / | 必填 | 该节点内容配置为：head&nbsp;info | 
   | 头信息（head节点） | info节点 | fileVersion | 必填 | 保留字段，内容不影响升级包生成 | 
   | 头信息（head节点） | info节点 | prdID | 必填 | 保留字段，内容不影响升级包生成 | 
   | 头信息（head节点） | info节点 | softVersion | 必填 | 软件版本号，即升级包版本号，版本必须在“VERSION.mbn”范围内，否则无法生产升级 | 
   | 头信息（head节点） | info节点 | _date_ | _必填_ | 升级包制作日期，保留字段，不影响升级包生成 | 
   | 头信息（head节点） | info节点 | _time_ | _必填_ | 升级包制作时间，保留字段，不影响升级包生成 | 
   | 组件信息（group节点） | component节点 | / | 必填 | 该节点内容配置为：要打入升级包的组件/镜像文件的路径，默认为版本包根路径 | 
   | 组件信息（group节点） | component节点 | compAddr | 必填 | 该组件所对应的分区名称，例如：system、vendor等。 | 
   | 组件信息（group节点） | component节点 | compId | 必填 | 组件Id，不同组件Id不重复 | 
   | 组件信息（group节点） | component节点 | resType | 必填 | 保留字段，不影响升级包生成 | 
   | 组件信息（group节点） | component节点 | compType | 必填 | 处理方式全量/差分，配置镜像处理方式的，0为全量处理、1为差分处理。 | 

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 对轻量系统/小型系统，不支持做差分升级，component标签中，属性compType值，不能配为‘1’，必须全部配置为‘0’。
   > 
   > 对轻量系统/小型系统，不支持变分区升级包的制作。

4. 创建“OTA.tag文件”，内容为OTA升级包的魔数，固定如下：
     
   ```
   package_type:ota1234567890qwertw
   ```

5. 创建“config文件”，内容为设置bootargs以及bootcmd的信息。
   例如配置如下：

     
   ```
   setenv bootargs 'mem=128M console=ttyAMA0,115200 root=/dev/mmcblk0p3 rw rootfstype=ext4 rootwait blkdevparts=mmcblk0:1M
   (u-boot.bin),9M(kernel.bin),50M(rootfs_ext4.img),50M(userfs.img)' setenv bootcmd 'mmc read 0x0 0x82000000 0x800 0x4800;bootm 0x82000000'
   ```

6. 执行升级包制作命令。
     
   ```
   python build_update.py ./target_package/ ./output_package/ -pk ./rsa_private_key3072.pem -nz -nl2x
   ```

   - ./target_package/：指定target_package路径。
   - ./output_package/：指定升级包输出路径。
   - -pk ./rsa_private_key3072.pem：指定私钥路径。
   - -nz：打开not zip模式开关
   - -nl2：打开非“标准系统”模式开关


### 标准系统升级包制作

1. 创建目标版本（target_package）文件夹，文件格式如下：

     
   ```
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

2. 将待升级的组件，包括镜像文件（例如：system.img等）等放入目标版本文件夹的根目录下，代替上结构中的{component_N}部分。

3. 填写“update_config”文件夹中的组件配置文件。

4. 配置“update_config”文件夹中当前升级包支持的产品list：**BOARD.list**。

   例如配置如下：

     
   ```
   HI3516
   HI3518
   ```

5. 配置“update_config”文件夹中当前升级包所支持的版本范围：**VERSION.mbn**。

   版本名称格式：Hi3516DV300-eng 10 QP1A.XXXXXX.{大版本号（6位）}.XXX{小版本号（3位）}。

   例如：Hi3516DV300-eng 10 QP1A.190711.020。名称中“190711”为大版本号，“020”为小版本号。

   例如配置如下：

     
   ```
   Hi3516DV300-eng 10 QP1A.190711.001
   Hi3516DV300-eng 10 QP1A.190711.020
   Hi3518DV300-eng 10 QP1A.190711.021
   ```

6. 针对增量（差分）升级包，还需要准备一个源版本（source_package），文件内容格式与目标版本（target_package）相同，需要打包成zip格式，即为：source_package.zip。

7. 针对变分区升级包，还需要提供分区表文件“partition_file.xml”，partition_file.xml配置节点说明如下，可通过-pf参数指定。

   分区表会随镜像一起生成，格式如下：

     
   ```
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

     
   ```
   python build_update.py ./target_package/ ./output_package/ -pk ./rsa_private_key3072.pem
   ```

   - ./target_package/：指定target_package路径。
   - ./output_package/：指定升级包输出路径。
   - -pk ./rsa_private_key3072.pem：指定私钥文件路径。

   **增量（差分）升级包**

   命令如下：

     
   ```
   python build_update.py ./target_package/ ./output_package/  -s ./source_package.zip  -pk ./rsa_private_key3072.pem
   ```

   - ./target_package/：指定target_package路径。
   - ./output_package/：指定升级包输出路径。
   - -s ./source_package.zip：指定“source_package.zip”路径，当存在镜像需要进行差分处理时，必须使用-s参数指定source版本包。
   - -pk ./rsa_private_key3072.pem：指定私钥文件路径。

   **变分区升级包**

   命令如下：

     
   ```
   python build_update.py  ./target_package/ ./output_package/  -pk ./rsa_private_key3072.pem  -pf ./partition_file.xml
   ```

   - ./target_package/：指定target_package路径。
   - ./output_package/：指定升级包路径。
   - -pk ./rsa_private_key3072.pem：指定私钥文件路径。
   - -pf ./partition_file.xml：指定分区表文件路径。


## 上传升级包

将升级包上传到厂商的OTA服务器。


## 下载升级包

1. 厂商应用从OTA服务器下载升级包。

2. 对Hi3518EV300/Hi3516DV300开源套件，需要插入SD卡(容量&gt;100MBytes)。


## 厂商应用集成OTA能力

1. 轻量与小型系统

   - 调用OTA模块的动态库libhota.so，对应头文件位于：base\update\ota_lite\interfaces\kits\hota_partition.h&amp;hota_updater.h。
   - libhota.so对应的源码路径为base\update\ota_lite\frameworks\source。
   - API的使用方法，见本文“API应用场景”和API文档的OTA接口章节。
   - 如果需要适配开发板，请参考HAL层头文件：base\update\ota_lite\hals\hal_hota_board.h。

2. 标准系统请参考[JS参考规范](../../application-dev/reference/apis/js-apis-update.md)指导中的升级接口参考规范。


## API应用场景-默认场景

升级包是按照上文“生成公私钥对”和“生成升级包”章节制作的。


### 开发指导

1. 应用侧通过下载，获取当前设备升级包后，调用HotaInit接口初始化OTA模块。

2. 调用HotaWrite接口传入升级包数据流，接口内部实现校验、解析及写入升级数据流。

3. 写入完成后，调用HotaRestart接口重启系统，升级过程中，使用HotaCancel接口可以取消升级。


### 示例代码

  使用OpenHarmony的“升级包格式和校验方法“进行升级。
  
```
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


## API应用场景-定制场景

升级包不是按照上文“生成公私钥对”和“生成升级包”章节制作的，是通过其它方式制作的。


### 开发指导

1. 应用侧通过下载，获取当前设备升级包后，调用HotaInit接口初始化。

2. 使用HotaSetPackageType接口设置NOT_USE_DEFAULT_PKG，使用"定制"流程。

3. 调用HotaWrite接口传入升级包数据流，写入设备。

4. 写入完成后，调用HotaRead接口读取数据，厂商可以自行校验升级包。

5. 调用HotaSetBootSettings设置启动标记，在重启后需要进入uboot模式时使用（可选）。

6. 调用HotaRestart接口，进行重启，升级过程中，使用HotaCancel接口可以取消升级。


### 示例代码

  使用非OpenHarmony的“升级包格式和校验方法“进行升级。
  
```
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
        if (HotaRead(offset, READ_BUF_LEN, (unsigned char *)g_readBuf) != 0) {}
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


## 系统升级

厂商应用调用OTA模块的API，OTA模块执行升级包的签名验证、版本防回滚、烧写落盘功能，升级完成后自动重启系统。

对于使用Hi3518EV300/Hi3516DV300开源套件的轻量和小型系统，在需要实现防回滚功能的版本中，需要增加LOCAL_VERSION的值，如"ohos default 1.0"-&gt;"ohos default 1.1"，LOCAL_VERSION在device\hisilicon\third_party\uboot\u-boot-2020.01\product\hiupdate\ota_update\ota_local_info.c中。

  示例，增加版本号。
  
```
const char *get_local_version(void)
{
#if defined(CONFIG_TARGET_HI3516EV200) || \
    defined(CONFIG_TARGET_HI3516DV300) || \
    defined(CONFIG_TARGET_HI3518EV300)
#define LOCAL_VERSION "ohos default 1.0" /* increase: default release version */
```
