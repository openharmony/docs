# Linux内核编译与构建指导<a name="ZH-CN_TOPIC_0000001076416924"></a>

-   [以hi3516dv300开源开发板+ubuntu x86主机开发环境为例](#section19369206113115)
    -   [场景1：版本级编译原生方式](#section1025111193220)
    -   [场景2：单独编译修改后的内核](#section17446652173211)


## 以hi3516dv300开源开发板+ubuntu x86主机开发环境为例<a name="section19369206113115"></a>

### 场景1：版本级编译原生方式<a name="section1025111193220"></a>

使用工程的全量编译命令，编译生成uImage内核镜像

```
./build.sh --product-name Hi3516DV300 # 编译hi3516dv300的uImage内核镜像
```

### 场景2：单独编译修改后的内核<a name="section17446652173211"></a>

1.  准备工作

    1.  按[开发板Patch使用指导](OpenHarmony开发板Patch使用指导.md)打入所需补丁。
    2.  准备编译环境，可以使用开源arm clang/gcc编译器。

    进入工程主目录配置环境变量：

    ```
    export PATH=`pwd`/prebuilts/clang/host/linux-x86/clang-r353983c/bin:`pwd`/prebuilts/gcc/linux-x86/arm/gcc-linaro-7.5.0-arm-linux-gnueabi/bin/:$PATH # 配置编译环境
    MAKE_OPTIONES="ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- CC=clang HOSTCC=clang" # 使用工程项目自带的clang环境
    ```

2.  修改内核代码或内核config （OpenHarmony提供对应平台的defconfig供参考）。
3.  创建编译目录及生成内核.config。

    ```
    make ${MAKE_OPTIONES} hi3516dv300_emmc_smp_hos_l2_defconfig # 使用自带的默认config 构建内核
    ```

4.  编译生成对应的内核Image。

    ```
    make ${MAKE_OPTIONES} -j32 uImage # 编译uImage内核镜像
    ```


