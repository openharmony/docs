

# 轻量带屏解决方案之恒玄芯片移植案例

本文章基于恒玄科技`BES2600W`芯片的欧智通[Multi-modal V200Z-R开发板](https://gitee.com/openharmony/device_board_fnlink)，进行轻量带屏开发板的标准移植，开发了智能开关面板样例，同时实现了`ace_engine_lite`、`arkui_ui_lite`、`aafwk_lite`、`appexecfwk_lite`、`HDF`等部件基于`OpenHarmony LiteOS-M`内核的适配。移植架构上采用`Board`与`SoC`分离的方案，工具链`Newlib C`库与`Musl C`库可选，`LiteOS-M`内核编译采用`gn`结合`Kconfig`图形化配置等需求。

## 编译构建

### 目录规划

本案例在芯片移植架构方面进行了一些改进，以前的芯片适配目录规划为：

```
device
└── <device_company>
    └── <device_name>
```

这样会导致，小熊派`BearPi-HM Nano`开发板与润和的`HiSpark Pegasus`开发板使用小海思的`hi3861`的`SoC`时，需要在这两款开发板里面都放置一份重复的代码。为了解决该问题，本案例将单板厂商与`SoC`厂商进行分离，可以参考[Board和SoC解耦的设计思路](https://gitee.com/openharmony-sig/sig-content/blob/master/devboard/docs/board-soc-arch-design.md)，并把芯片适配目录规划为：

```
device
├── board                                --- 单板厂商目录
│   └── fnlink                           --- 单板厂商名字：欧智通
│       └── v200zr                       --- 单板名：v200zr
└── soc									 --- SoC厂商目录
    └── bestechnic                       --- SoC厂商名字：恒玄
        └── bes2600						 --- SoC Series名：bes2600是一个系列，里面包含bes2600w等SoC名
```

产品样例目录规划为：

```
vendor
└── bestechnic							 --- 开发产品样例厂商目录，恒玄开发的带屏样例，因此以bestechnic命名
    └── display_demo         			 --- 产品名字：以智能开关面板的带屏显示样例
```

### 预编译适配

在进行移植之前，需要进行预编译适配。

预编译适配主要使用`hb set`命令，设置整个项目的根目录、单板目录、产品目录、单板公司名等环境变量，为编译做准备。

具体的预编译适配步骤如下：

1. 在`vendor/bestechnic/display_demo`目录下新增`config.json`文件，用于描述这个产品样例所使用的单板、内核等信息，描述信息可参考如下内容：

```
{
  "product_name": "display_demo",       --- 用于hb set进行选择时，显示的产品名称
  "type": "mini",                       --- 构建系统的类型，mini/small/standard
  "version": "3.0",                     --- 构建系统的版本，1.0/2.0/3.0
  "device_company": "fnlink",           --- 单板厂商名，用于编译时找到/device/board/fnlink目录
  "board": "v200zr",                    --- 单板名，用于编译时找到/device/board/fnlink/v200zr目录
  "kernel_type": "liteos_m",            --- 内核类型，因为OpenHarmony支持多内核，一块单板可能适配了多个内核，所以需要指定某个内核进行编译
  "kernel_version": "3.0.0",            --- 内核版本，一块单板可能适配了多个linux内核版本，所以需要指定某个具体的内核版本进行编译
  "subsystems": [ ]                     --- 选择所需要编译构建的子系统
}
```

2. 在`device/board/fnlink/v200zr/liteos_m`目录下新增`config.gni`文件，用于描述这个产品样例所使用的单板、内核等信息，描述信息可参考如下内容：

```
# Kernel type, e.g. "linux", "liteos_a", "liteos_m".
kernel_type = "liteos_m"                --- 内核类型，跟config.json中kernel_type对应

# Kernel version.
kernel_version = "3.0.0"                --- 内核版本，跟config.json中kernel_version对应
```

3. 验证`hb set`配置是否正确，输入`hb set`能够显示如下图片表示配置正确。

   执行`hb set`输入项目根目录，并且回车，`hb`命令会遍历所有`//vendor/<product_company>/<product_name>`目录下的`config.json`，给出可选产品编译选项，`config.json`的`product_name`用于显示产品名，`device_company`和`board`用于关联出`//device/board/<device_company>/<board>`目录，并且匹配`<any_dir_name>/config.gni`文件，如果能够匹配多个文件，表示该单板适配了多个内核，那么可以根据`config.json`的`kernel_type`和`kernel_version`来唯一匹配`config.gni`的`kernel_type`和`kernel_version`，即可确定了需要编译适配了哪个内核的单板。
![hb set](figures/bes2600_hb_set.png)

			通过`hb env`可以查看选择出来的预编译环境变量。

![hb env](figures/bes2600_hb_env.png)

在执行`hb build`之前，需要准备好`LiteOS-M`内核适配，具体适配步骤请参[内核移植](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/porting/porting-bes2600w-on-minisystem-display-demo.md#%E5%86%85%E6%A0%B8%E7%A7%BB%E6%A4%8D)。

## 内核移植

内核移植需要完成`LiteOS-M Kconfig`适配、`gn`的编译构建和内核启动最小适配。

### LiteOS-M Kconfig适配

在`//kernel/liteos_m`目录下执行`make menuconfig`命令，完成编译配置选项的选择。在`Makefile`文件中，会将`hb env`的结果转换成环境变量，即`PRODUCT_PATH`、`DEVICE_PATH`和`BOARD_COMPANY`。如下代码块所示：

```
$(foreach line,$(shell hb env | sed 's/\[OHOS INFO\]/ohos/g;s/ /_/g;s/:_/=/g' || true),$(eval $(line)))
ifneq ($(ohos_kernel),liteos_m)
$(error The selected product ($(ohos_product)) is not a liteos_m kernel type product)
endif
--- 将hb env的每一行输出转化为变量形式，例如将[OHOS INFO] device company: fnlink转换为ohos_device_company=fnlink

……

ifeq ($(BOARD_COMPANY),)
BOARD_COMPANY:=$(ohos_device_company)
endif
……
export BOARD_COMPANY
--- 将ohos_device_company转化为BOARD_COMPANY环境变量
```

在`//kernel/liteos_m/Kconfig`文件中使用这些导出的环境变量，`Kconfiglib`采用`ulfalizer`开发基于`python`的版本，[源码地址](https://github.com/ulfalizer/Kconfiglib)，[功能介绍连接参考](https://github.com/zephyrproject-rtos/zephyr/blob/main/scripts/kconfig/kconfiglib.py)，里面用到了`orsource`关键字，其中`o`表示`optional`，表示这个文件是否存在可选，`r`表示`relative`，表示这个文件相对当前文件的相对路径。

```
config SOC_COMPANY
    string "SoC company name to locate soc build path"
    help
      This option specifies the SoC company name, used to locate the build path for soc. This option is set by the
      SoC's Kconfig file, and should be exactly the same with SoC company path, and the user should generally avoid
       modifying it via the menu configuration.

orsource "../../device/board/*/Kconfig.liteos_m.shields"                                 --- 将所有扩展板配置信息加载进来，因为单板厂商A提供扩展板可以给单板厂商B使用，所以这里使用*匹配所有的扩展板，而非BOARD_COMPANY。另外由于OpenHarmony支持多内核设计，Kconfig文件采用liteos_m作为后缀，在进行单板适配过程中，其他内核在适配过程中，可以使用对应的内核名作为后缀名进行扩展。

orsource "../../device/board/$(BOARD_COMPANY)/Kconfig.liteos_m.defconfig.boards"         --- 加载BOARD_COMPANY的所有单板预定义配置

choice
    prompt "Board Selection"

orsource "../../device/board/$(BOARD_COMPANY)/Kconfig.liteos_m.boards"                   --- 提供Board选择列表

endchoice

orsource "../../device/soc/*/Kconfig.liteos_m.defconfig"                                 --- 加载所有SoC的默认配置定义

choice
    prompt "SoC Series Selection"

orsource "../../device/soc/*/Kconfig.liteos_m.series"                                    --- 提供所有SoC Series选择列表

endchoice

orsource "../../device/soc/*/Kconfig.liteos_m.soc"                                       --- 加载所有SoC配置
```

从`//kernel/liteos_m/Kconfig`文件可以看出需要在`//device/board/fnlink`目录下新增如下`Kconfig`文件进行适配：

```
.
├── v200zr                                       --- v200zr单板配置目录
│   ├── Kconfig.liteos_m.board                   --- 提供v200zr单板的配置选项
│   ├── Kconfig.liteos_m.defconfig.board         --- 提供v200zr单板的默认配置项
│   └── liteos_m
│       └── config.gni
├── Kconfig.liteos_m.boards                      --- 提供fnlink单板厂商下Boards配置信息
├── Kconfig.liteos_m.defconfig.boards			 --- 提供fnlink单板厂商下Boards默认配置信息
├── Kconfig.liteos_m.shields					 --- 提供fnlink单板厂商下扩展板配置信息
└── shields										 --- fnlink单板厂商的扩展板目录
    ├── v200zr-t0								 --- fnlink单板厂商的扩展板v200zr-t0
    │   ├── Kconfig.liteos_m.defconfig.shield	 --- 扩展板v200zr-t0默认配置
    │   └── Kconfig.liteos_m.shield				 --- 扩展板v200zr-t0配置信息
    ├── v200zr-t1
    │   ├── Kconfig.liteos_m.defconfig.shield
    │   └── Kconfig.liteos_m.shield
    └── Kconfig.liteos_m.shields
```

在 `v200zr/Kconfig.liteos_m.board`需要配置选择该单板的选项，以及它依赖的`SoC`，如下：

```
config BOARD_v200zr
    bool "select board v200zr"
    depends on SOC_BES2600W		 --- v200zr单板用的bes2600w的SoC，只有 bes2600w的SoC被选择后，v200zr单板配置选项才可见，可以被选择。
```

在 `v200zr/Kconfig.liteos_m.defconfig.board`需要配置选择该单板后，默认定义 `BOARD` 的名字为 `"v200zr"` ，如下：

```
if BOARD_v200zr
config BOARD
    string		 --- string后没有带提示，因此用户不可见
    default "v200zr"

endif # BOARD_v200zr
```

从`//kernel/liteos_m/Kconfig`文件可以看出需要在`//device/soc/bestechnic`目录下新增如下`Kconfig`文件进行适配：

```
.
├── bes2600									 --- bes2600 SoC系列
│   ├── Kconfig.liteos_m.defconfig.bes2600w	 --- bestechnic芯片厂商bes2600w SoC Series配置
│   ├── Kconfig.liteos_m.defconfig.series	 --- bestechnic芯片厂商bes2600默认配置
│   ├── Kconfig.liteos_m.series				 --- bestechnic芯片厂商bes2600 SoC Series配置
│   └── Kconfig.liteos_m.soc				 --- bestechnic芯片厂商bes2600 SoC配置
├── Kconfig.liteos_m.defconfig				 --- bestechnic芯片厂商SoC默认配置
├── Kconfig.liteos_m.series					 --- bestechnic芯片厂商SoC Series配置
└── Kconfig.liteos_m.soc					 --- bestechnic芯片厂商 SoC配置
```

在 `bes2600/Kconfig.liteos_m.series` 需要配置`bes2600 SoC series`，以及它的芯片架构等信息，如下：

```
config SOC_SERIES_BES2600			 --- 提供bes2600 SoC Series选项
    bool "Bestechnic 2600 Series"
    select ARM						 --- 选择bes2600后，默认选择ARM架构
    select SOC_COMPANY_BESTECHNIC    --- 选择bes2600后，默认选择bestechnic芯片公司，驱动会依赖这个宏配置，选择配置编译对应厂商的驱动
    select CPU_CORTEX_M33			 --- 选择bes2600后，默认选择cortex-m33 CPU
    help
        Enable support for Bestechnic 2600 series
```

在 `bes2600/Kconfig.liteos_m.soc` 需要提供`bes2600 SoC series`下有多少个具体的`SoC`可供选择，如下：

```
choice
    prompt "Bestechnic 2600 series SoC"
    depends on SOC_SERIES_BES2600	 --- 只有选择了bes2600 Series后，才会出现如下配置选项

config SOC_BES2600W					 --- 增加bes2600w SoC配置选择项
    bool "SoC BES2600w"

endchoice
```

在 `bes2600/Kconfig.liteos_m.defconfig.series` 需要提供`bes2600 SoC series`选择后的默认配置，如下：

```
if SOC_SERIES_BES2600							 --- 选择了bes2600 Series后，才会增加如下默认配置选项

rsource "Kconfig.liteos_m.defconfig.bes2600w"	 --- 增加bes2600w SoC的默认配置

config SOC_SERIES								 --- 增加SOC_SERIES的默认配置
    string
    default "bes2600"

endif
```

配置完成后，还需要根据 `kernel/liteos_m/Makefile` 文件配置`make menuconfig`的`defconfig`保存路径：

```
ifeq ($(TEE:1=y),y)
tee = _tee
endif
ifeq ($(RELEASE:1=y),y)
CONFIG ?= $(PRODUCT_PATH)/kernel_configs/release$(tee).config
else
CONFIG ?= $(PRODUCT_PATH)/kernel_configs/debug$(tee).config		 --- 配置文件保存在$(CONFIG)中，由产品最终定义
endif

……

update_config menuconfig:
	$(HIDE)test -f "$(CONFIG)" && cp -v "$(CONFIG)" .config && menuconfig $(args) && savedefconfig --out "$(CONFIG)"
```

在这个例子中，`defconfig`配置路径为 `$(PRODUCT_PATH)/kernel_configs/debug.config`，创建该文件后，内容为空，产品的目录文件结构如下：

```
.
└── display_demo
    ├── config.json
    └── kernel_configs
        └── debug.config
```

配置完成后，在 `kernel/liteos_m` 目录下执行 `make menuconfig`能够对`SoC Series`/`SoC`/`Board`进行选择，如下：

![board make menuconfig](figures/bes2600_board_make_menuconfig.png)

结果将自动保存在`$(PRODUCT_PATH)/kernel_configs/debug.config`，下次执行`make menuconfig`时会导出保存的结果。

### gn编译适配

在上一步`Kconfig`的图形化配置后，将其生成的配置结果可以作为`gn`编译的输入，以控制不同模块是否编译。另外为了解决之前`gn`编写时，随意include的问题，内核编译做了模块化编译的设计，使得整个编译逻辑更加清晰，设计思路请参考[LiteOS-M内核BUILD.gn编写指南](https://gitee.com/caoruihong/kernel_liteos_m/wikis/LiteOS-M%E5%86%85%E6%A0%B8BUILD.gn%E7%BC%96%E5%86%99%E6%8C%87%E5%8D%97)。

在 `kernel/liteos_m/BUILD.gn` 中，指定了`Board`和`SoC`的编译入口为`//device/board/fnlink`和`//device/soc/bestechnic`。

```
deps += [ "//device/board/$device_company" ]
deps += [ "//device/soc/$LOSCFG_SOC_COMPANY" ]
```

在`//device/board/fnlink/BUILD.gn`中，新增内容如下：

```
if (ohos_kernel_type == "liteos_m") {                    --- 由于多内核设计，对于LiteOS-M内核适配，需要用宏来隔离
  import("//kernel/liteos_m/liteos.gni")				 --- 引入内核gn编写模板
  module_name = get_path_info(rebase_path("."), "name")	 --- 动态获取当前文件目录作为模块名，防止目录名修改后，这里还需要跟着修改
  module_group(module_name) {							 --- 采用module_group模板
    modules = [											 --- 添加需要编译的模块
    ]
  }
}
```

同理`//device/soc/bestechnic/BUILD.gn`也是一样。

### 内核启动适配

系统启动流程分为三个阶段：

| 阶段名称  | 分区规划                 | 描述                          |
| --------- | ------------------------ | ----------------------------- |
| BOOT1     | [0, 0x10000]             | 第一阶段启动，进行固件启动    |
| BOOT2     | [0x2C010000, 0x2C020000] | 第二阶段启动，进行OTA升级启动 |
| RTOS_MAIN | [0x2C080000, 0x2C860000] | 第三阶段启动，进行内核启动    |

在第三阶段内核启动中，需要适配的文件路径在 `//device/soc/bestechnic/bes2600/liteos_m/sdk/bsp/rtos/liteos/liteos_m/board.c`

内核启动适配总体思路如下：

1. 中断向量的初始化`os_vector_init` ，初始化中断的处理函数。
2. 内核初始化`osKernelInitialize` 。
3. 创建线程`board_main`，进行芯片平台初始化。
4. 内核启动，开始调度线程`osKernelStart` 。

其中，本章节详细对第3步进行展开，其他几步为对内核函数调用，不作详细描述。

第3步中`board_main`在启动`OHOS_SystemInit`之前，需要初始化必要的动作，如下：

```
...
    if(!ret) {
        ...
        OhosSystemAdapterHooks();    --- 系统启动时候设置钩子，启动OpenHarmonyOHOS_SystemInit的之前完成打印和驱动的初始化
        ...
        OHOS_SystemInit(); 			 --- 启动OpenHarmony服务，以及组件初始化
    }
....
```

`OhosSystemAdapterHooks`函数在`device/soc/bestechnic/bes2600/liteos_m/components/utils/src/hm_sys.c`文件中，如下：

```
int OhosSystemAdapterHooks(void)
{
    init_trace_system(); 	 --- 初始化打印函数
    DeviceManagerStart(); 	 --- 调用DeviceManagerStart函数进行HDF驱动初始化，这个过程会调用单板代码中的驱动配置文件hdf.hcs以及drivers源码实现
    return 0;
}

```

### littlefs文件系统移植

 `V200Z-R`开发板开发板采用最大`32MB`的支持`XIP`的`Nor Flash`，文件系统可以使用`example`，适配过程中，需要在指定路径下放置文件系统预置文件，根据配置可自动生成文件系统镜像，可以实现自动化生成和打包到烧录包中。

1. 配置指定目录放置打包文件系统`config.json`，通过`flash_partition_dir`指定目录：

```
  "flash_partition_dir": "fs" 	 --- 表示在vendor/bestechnic/display_demo/fs目录下放置文件系统预置文件
```

2. 在指定目录`vendor/bestechnic/display_demo/fs`下放置两部分内容：

  - `wifi_Download_cfg.yaml`：镜像的烧录配置文件，可以根据实际情况调整分区。
  - `/data/data`：第一个/`data`是挂载的根目录；第二个`data`是根目录里面的`data`目录，里面可以存放预置文件，或者在第二个`data`的同级目录再创建一个目录，打包的时候只认第一个`data`挂载根目录。

3. `config.json`中根据`wifi_Download_cfg.yaml`最后调整结果。

  - `fs_src`配置文件系统挂载名字。
  - `fs_name`是最后生成文件系统的名字。
  - `block_size`配置成`4K`对齐，建议不修改。
  - `fs_size`是生成文件系统的大小。
  - `burn_name`是烧录`bin`名字的大小。
  - `enable` 表示是否生成这个文件系统

4. 在`//device/soc/bestechnic/bes2600/liteos_m/components/hdf_config/hdf.hcs`文件配置文件系统的烧录的起始地址、文件系统的大小以及读数据块的大小`block_size`等信息，参考配置如下：

```
    misc {
        fs_config {
            example_config {
                match_attr = "littlefs_config";
                mount_points = ["/data"];
                partitions = [10];
                block_size = [4096];
                block_count = [1024];
            }
        }
        storage_config {
            flash_config {
                match_attr = "flash_config";
                partitions = [10];
                owner = [0];
                description = ["littlefs"];
                start_addr = [0xB60000];
                length = [0x400000];
                options = [3];
            }
        }
    }
```

最后在`device/soc/bestechnic/bes2600/liteos_m/components/fs/fs_init.c`中，通过`hdf`加载数据，进行读写`flash`，如下：

```
static int32_t FsDriverInit(struct HdfDeviceObject *object)
{
    if (object == NULL) {
        return HDF_FAILURE;
    }
    if (object->property) {
        if (FsGetResource(fs, object->property) != HDF_SUCCESS) {
            HDF_LOGE("%s: FsGetResource failed", __func__);
            return HDF_FAILURE;
        }
    }
    for (int i = 0; i < sizeof(fs) / sizeof(fs[0]); i++) {
        if (fs[i].mount_point == NULL)
            continue;

        fs[i].lfs_cfg.read = littlefs_block_read;
        fs[i].lfs_cfg.prog = littlefs_block_write;
        fs[i].lfs_cfg.erase = littlefs_block_erase;
        fs[i].lfs_cfg.sync = littlefs_block_sync;

        fs[i].lfs_cfg.read_size = 256;
        fs[i].lfs_cfg.prog_size = 256;
        fs[i].lfs_cfg.cache_size = 256;
        fs[i].lfs_cfg.lookahead_size = 16;
        fs[i].lfs_cfg.block_cycles = 1000;

        int ret = mount(NULL, fs[i].mount_point, "littlefs", 0, &fs[i].lfs_cfg);
        HDF_LOGI("%s: mount fs on '%s' %s\n", __func__, fs[i].mount_point, (ret == 0) ? "succeed" : "failed");
    }
    return HDF_SUCCESS;
}
```



### C库适配

在轻量系统中，C库适配比较复杂，设计思路请参考[LiteOS-M内核支持musl与newlib平滑切换方案](https://gitee.com/arvinzzz/ohos_kernel_design_specification/blob/master/liteos_m/%E6%94%AF%E6%8C%81newlib/%E5%86%85%E6%A0%B8%E9%80%82%E9%85%8Dnewlib%E6%96%B9%E6%A1%88%E6%80%9D%E8%B7%AF.md)，由于我们的工具链采用 [gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2](https://gitee.com/link?target=https%3A%2F%2Fdeveloper.arm.com%2F-%2Fmedia%2FFiles%2Fdownloads%2Fgnu-rm%2F10.3-2021.10%2Fgcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2) 自带`newlib`的C库，那么系统移植整体采用`newlib`的C库。那么在内核的`make menuconfig`中选择`newlib`，如下图：

![image-20211212191013553](figures/bes2600_newlib_make_menuconfig.png)

#### malloc适配

malloc适配参考[The Red Hat newlib C Library-malloc](https://sourceware.org/newlib/libc.html#malloc)。实现malloc适配有以下两种方法：

- 实现 `_sbrk_r` 函数。这种方法中，内存分配函数使用`newlib`中的。

- 实现 `_malloc_r`, `_realloc_r`, `_reallocf_r`, `_free_r`, `_memalign_r`, 和 `_malloc_usable_size_r`。这种方法中，内存分配函数可以使用内核的。

为了方便地根据业务进行内存分配算法调优和问题定位，在这两种方法中，本案例选择后者。

首先，由于`newlib`中已经存在这些函数的符号，因此需要用到`gcc`的`wrap`的链接选项替换这些函数符号为内核的实现，内核的实现为 `//kernel/liteos_m/kal/libc/newlib/porting/src/malloc.c`。

然后，在`//device/board/fnlink/v200zr/liteos_m/config.gni`的新增这些函数的`wrap`链接选项。

```
board_ld_flags += [
     "-Wl,--wrap=_malloc_r",
     "-Wl,--wrap=_realloc_r",
     "-Wl,--wrap=_reallocf_r",
     "-Wl,--wrap=_free_r",
     "-Wl,--wrap=_memalign_r",
     "-Wl,--wrap=_malloc_usable_size_r",
]
```

#### vsprintf等适配

参考 https://sourceware.org/newlib/libc.html#vfprintf ，实现 `vprintf`, `vfprintf`, `printf`, `snprintf` 和`sprintf`。

类似`malloc`适配，首先要提供这些函数的实现，`//device/soc/bestechnic/bes2600/liteos_m/components/utils/src/printf.c`，本案例直接采用开源协议友好的实现。与`malloc`适配不同的是，这个函数由芯片原厂提供。因为就打印来说，根据项目的需要，实现可大可小，内核不方便提供统一的实现。

然后，在`//device/board/fnlink/v200zr/liteos_m/config.gni`的新增这些函数的wrap链接选项。

```
board_ld_flags += [
     "-Wl,--wrap=printf",
     "-Wl,--wrap=sprintf",
     "-Wl,--wrap=snprintf",
     "-Wl,--wrap=vsnprintf",
     "-Wl,--wrap=vprintf",
]
```

#### open等适配

这部分实现由内核统一实现，芯片适配无须关注，内核文件`//kernel/liteos_m/kal/libc/newlib/porting/src/fs.c`，适配了`newlib`的`_read`、`_write`等函数，如下：

```
……
ssize_t _read(int fd, void *buf, size_t nbyte)
{
    return LOS_Read(fd, buf, nbyte);
}

ssize_t _write(int fd, const void *buf, size_t nbyte)
{
    return LOS_Write(fd, buf, nbyte);
}

off_t _lseek(int fd, off_t offset, int whence)
{
    return LOS_Lseek(fd, offset, whence);
}
……
```

## 板级系统移植

### 驱动移植

#### SoC芯片平台HDF驱动移植

驱动适配相关文件放置在`drivers/adapter/platform`中，对应有`gpio`，`i2c`，`pwm`，`spi`，`uart`，`watchdog`，都是通过`HDF`机制加载，本章节以`gpio`为例进行详细说明。

##### GPIO驱动适配

`gpio`驱动适配需要完成编译的适配、源码的适配。

在`//drivers/adapter/platform/gpio/BUILD.gn`文件中，描述了恒玄`gpio`驱动的编译适配。如下：

```
module_switch = defined(LOSCFG_DRIVERS_HDF_PLATFORM_GPIO)	 --- 如果打开HDF的GPIO配置开关，才进行如下编译
module_name = get_path_info(rebase_path("."), "name")

hdf_driver(module_name) {
  sources = []
  if (defined(LOSCFG_SOC_COMPANY_BESTECHNIC)) {				 --- 如果打开恒玄的芯片配置开关，才进行恒玄GPIO的驱动编译
    sources += [ "gpio_bes.c" ]
  }

  include_dirs = [ "." ]
}
```

在`//drivers/adapter/platform/gpio/gpio_bes.c`文件中，描述了恒玄`gpio`驱动的源码适配。
首先，按照`OpenHarmony`的`HDF`驱动框架加载驱动基本适配框架，如下：

```
struct HdfDriverEntry g_GpioDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "BES_GPIO_MODULE_HDF",
    .Bind = GpioDriverBind,
    .Init = GpioDriverInit,
    .Release = GpioDriverRelease,
};
HDF_INIT(g_GpioDriverEntry); 	 --- 通过HDF_INIT 加载GPIO驱动
```

然后，在初始化的时候会获取`hcs`参数进行初始化，如下：

```
static int32_t GpioDriverInit(struct HdfDeviceObject *device)
{
    int32_t ret;
    struct GpioCntlr *gpioCntlr = NULL;

    if (device == NULL) {
        HDF_LOGE("%s: device is NULL", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    gpioCntlr = GpioCntlrFromDevice(device); 	 --- gpioCntlr节点变量就可以获取具体gpio配置
    if (gpioCntlr == NULL) {
      ...
```

编码规范和设计思想见[bes 驱动适配PR](https://gitee.com/openharmony/drivers_adapter/pulls/278)的评论。

#### Board外设器件HDF驱动移植

`Board`外设器件表示通过`SoC`平台总线连接的外设器件，在本案例中，显示屏属于外设器件，其驱动适配放在`//device/board/fnlink/drivers/liteos_m`目录中。

##### 显示驱动适配

同`SoC`驱动适配，在`//device/board/fnlink/drivers/liteos_m/display/BUILD.gn`文件中，根据`hdf_driver`模板加载驱动模块，如下：

```
module_name = get_path_info(rebase_path("."), "name")
hdf_driver(module_name) {
  sources = [
    "zzw395.c",
  ]
  include_dirs = [
    "//drivers/peripheral/display/interfaces/include",
  ...
  ]
}
```

在`//device/board/fnlink/drivers/liteos_m/display/zzw395.c`文件中，根据驱动框架加载显示驱动，如下：

```
static struct HdfDriverEntry g_ZZW395DriverEntry = {
    .moduleVersion = 1,
    .moduleName = "HDF_PANEL_ZZW395",
    .Bind = PanelDriverBind,
    .Init = PanelDriverInit,
    .Release = PanelDriverRelease,
};

HDF_INIT(g_ZZW395DriverEntry);
```

其中的驱动参数根据`hcs`配置，在`PanelDriverInit`初始化时加载，如下：

```
static int32_t PanelDriverInit(struct HdfDeviceObject *object)
{
    if (object == NULL) {
        return HDF_FAILURE;
    }
    HDF_LOGD("%s entry !!!", __func__);
    if (object->property) {
        if (PanelGetResource(&priv, object->property) != HDF_SUCCESS) {
            HDF_LOGE("%s: PanelGetResource failed", __func__);
            return HDF_FAILURE;
        }
    }
...
```

### OpenHarmony子系统适配

`OpenHarmony`子系统适配一般包含两部分：

- 在`config.json`中增加对应子系统和部件，这样编译系统会将该部件纳入编译目标中。
- 针对该部件的`HAL`层接口进行硬件适配，或者可选的软件功能适配。

#### 分布式软总线子系统适配

##### wifi_lite部件适配

首先，在`config.json`文件中，增加`communication`子系统的`wifi_lite`部件，如下：

```
    {
      "subsystem": "communication",
      "components": [
        {
          "component": "wifi_lite",
          "optional": "true"
        }
      ]
    },
```

`wifi_lite`部件在`//build/lite/components/communication.json`文件中，描述如下：

```
    {
      "component": "wifi_lite",
……
      "targets": [
        "//foundation/communication/wifi_lite:wifi"		 --- wifi_lite的编译目标
      ],
……
    },

```

在`//foundation/communication/wifi_lite/BUILD.gn`文件中，描述需要适配的接口头文件路径，如下：

```
config("include") {
  include_dirs = [ "interfaces/wifiservice" ]	 --- 因为wifi_lite只提供头文件，不提供wifi的具体实现，所以wifi模块暴露出适配的目录路径提供给硬件厂商来适配，厂商提供wifi协议栈源码实现。
}

group("wifi") {
  public_configs = [ ":include" ]
}
```

因为在本案例中，`wifi`属于`SoC`提供的功能，所以适配源码放在`SoC`的`//device/soc/bestechnic/hals/communication/wifi_lite/wifiservice`目录下，包含`wifi_device.c`和`wifi_hotspot.c`分别适配`wifi_device.h`和`wifi_hotspot.h`。如下：

```
……
WifiErrorCode Scan(void)	 --- wifi_device.c中扫描wifi热点的函数，对wifi_device.h中Scan函数的适配实现
{
    WifiErrorCode ret = ERROR_WIFI_BUSY;


    if (IsWifiActive() != WIFI_STA_ACTIVE)
        return ERROR_WIFI_IFACE_INVALID;

    if (g_HalHmosWifiInfo.scan_state == SCAN_REQUEST ||
        g_HalHmosWifiInfo.scan_state == SCAN_TRIGGER)
        return ERROR_WIFI_BUSY;

    HalHmosWifiLock();
    ret = ((HalHmosSendEvent(HMOS_ON_WIFI_SCAN_STATE_CHANGED, NULL) == 0) ? WIFI_SUCCESS : ERROR_WIFI_BUSY);
    HalHmosWifiUnLock();

    return ret;
}
……
int GetSignalLevel(int rssi, int band)	 --- wifi_hotspot.c中获取wifi信号热点函数，对wifi_hotspot.h中GetSignalLevel函数的适配实现。
{
    if (band == HOTSPOT_BAND_TYPE_2G) {
        if (rssi >= RSSI_LEVEL_4_2_G)
            return RSSI_LEVEL_4;
        if (rssi >= RSSI_LEVEL_3_2_G)
            return RSSI_LEVEL_3;
        if (rssi >= RSSI_LEVEL_2_2_G)
            return RSSI_LEVEL_2;
        if (rssi >= RSSI_LEVEL_1_2_G)
            return RSSI_LEVEL_1;
    }

    if (band == HOTSPOT_BAND_TYPE_5G) {
        if (rssi >= RSSI_LEVEL_4_5_G)
            return RSSI_LEVEL_4;
        if (rssi >= RSSI_LEVEL_3_5_G)
            return RSSI_LEVEL_3;
        if (rssi >= RSSI_LEVEL_2_5_G)
            return RSSI_LEVEL_2;
        if (rssi >= RSSI_LEVEL_1_5_G)
            return RSSI_LEVEL_1;
    }
    return ERROR_WIFI_INVALID_ARGS;
}
```

##### LWIP部件适配

`LiteOS-M kernel`目录下默认配置了`lwip`，因而具有编译功能，可以在`kernel`组件中指定`lwip`编译的目录。如下：

```
    {
      "subsystem": "kernel",
      "components": [
        {
          "component": "liteos_m",
          "features": [
            "ohos_kernel_liteos_m_lwip_path = \"//device/soc/bestechnic/bes2600/liteos_m/components/net/lwip-2.1\""		 --- 指定在芯片厂商目录中进行适配
          ]
        }
      ]
    },
```

在`//device/soc/bestechnic/bes2600/liteos_m/components/net/lwip-2.1/BUILD.gn`文件中，描述了`lwip`的编译，如下：

```
import("//kernel/liteos_m/liteos.gni")
import("$LITEOSTHIRDPARTY/lwip/lwip.gni")
import("$LITEOSTOPDIR/components/net/lwip-2.1/lwip_porting.gni")

module_switch = defined(LOSCFG_NET_LWIP_SACK)
module_name = "lwip"
kernel_module(module_name) {
  sources = LWIP_PORTING_FILES + LWIPNOAPPSFILES -
            [ "$LWIPDIR/api/sockets.c" ] + [ "porting/src/ethernetif.c" ]		 --- 增加ethernetif.c文件，用以适配ethernet网卡的初始化适配
  defines = [ "LITEOS_LWIP=1" ]
  defines += [ "CHECKSUM_BY_HARDWARE=1" ]
}

config("public") {
  defines = [ "_BSD_SOURCE=1" ]
  include_dirs =
      [ "porting/include" ] + LWIP_PORTING_INCLUDE_DIRS + LWIP_INCLUDE_DIRS
}

```

在`//device/soc/bestechnic/bes2600/liteos_m/components/net/lwip-2.1/porting/include/lwip/lwipopts.h`文件中，说明原有`lwip`配置选项保持不变，软总线会依赖这些配置选项，并且新增硬件适配的配置项，如下：

```
#ifndef _PORTING_LWIPOPTS_H_
#define _PORTING_LWIPOPTS_H_

#include_next "lwip/lwipopts.h"				 --- 保持原来的配置项不变

#define LWIP_NETIF_STATUS_CALLBACK      1
#define LWIP_CHECKSUM_ON_COPY           0
#define CHECKSUM_GEN_UDP                0	 --- 新增硬件适配选项

#endif /* _PORTING_LWIPOPTS_H_ */

```

在`//device/soc/bestechnic/bes2600/liteos_m/components/net/lwip-2.1/porting/src/ethernetif.c`文件中，说明对`ethernet`网卡初始化的适配，如下：

```
err_t
ethernetif_init(struct netif *netif)
{
……
#ifdef CHECKSUM_BY_HARDWARE
    eth_hw_checksum_init();
#endif
……
    netif->linkoutput = low_level_output;

    netif->drv_send = liteos_low_level_output;
    netif->hwaddr_len = NETIF_MAX_HWADDR_LEN;
    low_level_init(netif);
    driverif_init(netif);
    return ERR_OK;
……
}
```

##### dsoftbus部件适配

在`config.json`中增加`dsoftbus`部件配置如下：

```
{
  "component": "dsoftbus",
  "features": [
    "softbus_adapter_config = \"//vendor/bestechnic/mini_distributed_music_player/dsoftbus_lite_config\""
  ]
},
```

`dsoftbus`部件在`//foundation/communication/dsoftbus/dsoftbus.gni`文件中提供了`softbus_adapter_config`配置选项可供移植过程进行配置，该配置设定了软总线移植适配的路径。

在本案例中，`softbus_adapter_config`配置为`//vendor/bestechnic/mini_distributed_music_player/dsoftbus_lite_config`路径，该路径下的内容为：

```
.
├── feature_config					--- 软总线功能特性配置，例如是否开启自发现功能等
│   └── mini
│       └── config.gni
└── spec_config						--- 软总线规格特性配置，例如设置软总线日志级别设置
    ├── softbus_config_adapter.c
    ├── softbus_config_adapter.h
    └── softbus_config_type.h
```

在`config.gni`文件中规定了以下配置项：

| 配置项                                     | 描述                     |
| ------------------------------------------ | ------------------------ |
| dsoftbus_feature_disc_ble         | 是否开启BLE发现功能      |
| dsoftbus_feature_disc_coap        | 是否开启COAP发现功能     |
| dsoftbus_feature_conn_tcp         | 是否开启TCP连接功能      |
| dsoftbus_feature_conn_br          | 是否开启BR连接功能       |
| dsoftbus_feature_conn_ble         | 是否开启BLE连接功能      |
| dsoftbus_feature_conn_p2p         | 是否开启P2P连接功能      |
| dsoftbus_feature_trans_udp        | 是否开启UDP传输功能      |
| dsoftbus_feature_trans_udp_stream | 是否开启UDP传输流功能    |
| dsoftbus_feature_trans_udp_file   | 是否开启UDP传输文件功能  |
| dsoftbus_feature_ip_auth          | 是否开启认证传输通道功能 |
| dsoftbus_feature_auth_account     | 是否开启基于账号认证功能 |
| dsoftbus_feature_qos              | 是否开启QoS功能          |

在`softbus_config_adapter.c`文件中规定了以下配置项：

| 配置项                               | 描述                          |
| ------------------------------------ | ----------------------------- |
| SOFTBUS_INT_MAX_BYTES_LENGTH         | SendBytes发送最大Bytes长度    |
| SOFTBUS_INT_MAX_MESSAGE_LENGTH       | SendMessage发送最大消息的长度 |
| SOFTBUS_INT_CONN_BR_MAX_DATA_LENGTH  | 蓝牙最大接收数据量            |
| SOFTBUS_INT_CONN_RFCOM_SEND_MAX_LEN  | 蓝牙最大接收数据量            |
| SOFTBUS_INT_ADAPTER_LOG_LEVEL        | 日志级别设置                  |
| SOFTBUS_STR_STORAGE_DIRECTORY        | 存储目录设置                  |

因为软总线配置了后，不会默认启动，所以需要在通过启动框架调用`InitSoftBusServer`函数，如下：

```
static void DSoftBus(void)
{
    osThreadAttr_t attr;
    attr.name = "dsoftbus task";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = 65536;
    attr.priority = 24;

    extern void InitSoftBusServer(void);
    if (osThreadNew((osThreadFunc_t) InitSoftBusServer, NULL, &attr) == NULL) {
        printf("Failed to create WifiSTATask!\n");
    }
}

APP_FEATURE_INIT(DSoftBus);
```

##### RPC部件适配

在`config.json`中增加`rpc`部件配置如下：

```
{
  "component": "rpc"
},
```

同样地，`rpc`部件需要通过启动框架调用`StartDBinderService`函数，由于该函数正常运行依赖主机已经获取`IP`地址，因此在`LWIP`协议栈注册`IP`地址变化事件的回调函数中调用该函数，如下：

```
static void RpcServerWifiDHCPSucCB(struct netif *netif, netif_nsc_reason_t reason,
                                   const netif_ext_callback_args_t *args)
{
    (void) args;
    if (netif == NULL) {
        printf("%s %d, error: input netif is NULL!\n", __FUNCTION__, __LINE__);
        return;
    }
    if (reason == LWIP_NSC_IPSTATUS_CHANGE) {
        if (netif_is_up(netif) && !ip_addr_isany(&netif->ip_addr)) {
            printf("%s %d, start rpc server!\n", __FUNCTION__, __LINE__);
            StartDBinderService();
        }
    }
}

static void WifiDHCPRpcServerCB(void)
{
    NETIF_DECLARE_EXT_CALLBACK(WifiReadyRpcServerCallback);
    netif_add_ext_callback(&WifiReadyRpcServerCallback, RpcServerWifiDHCPSucCB);
}

APP_FEATURE_INIT(WifiDHCPRpcServerCB);
```

#### 启动恢复子系统适配

启动恢复子系统适配`bootstrap_lite`/`syspara_lite`两个部件。请在`vendor/bestechnic_bak/display_demo/config.json`中新增对应的配置选项。

```
{
  "subsystem": "startup",
  "components": [
	{
	  "component": "bootstrap_lite"		 --- bootstrap_lite 部件
	},
	{
	  "component": "syspara_lite",		 --- syspara_lite 部件
	  "features": [
		"enable_ohos_startup_syspara_lite_use_posix_file_api = true"
	  ]
	}
  ]
},
```

适配`bootstrap_lite`部件时，需要在连接脚本文件`//device/soc/bestechnic/bes2600/liteos_m/sdk/bsp/out/best2600w_liteos/_best2001.lds`中手动新增如下段：

```
       __zinitcall_bsp_start = .;
      KEEP (*(.zinitcall.bsp0.init))
      KEEP (*(.zinitcall.bsp1.init))
      KEEP (*(.zinitcall.bsp2.init))
      KEEP (*(.zinitcall.bsp3.init))
      KEEP (*(.zinitcall.bsp4.init))
      __zinitcall_bsp_end = .;
      __zinitcall_device_start = .;
      KEEP (*(.zinitcall.device0.init))
      KEEP (*(.zinitcall.device1.init))
      KEEP (*(.zinitcall.device2.init))
      KEEP (*(.zinitcall.device3.init))
      KEEP (*(.zinitcall.device4.init))
      __zinitcall_device_end = .;
      __zinitcall_core_start = .;
      KEEP (*(.zinitcall.core0.init))
      KEEP (*(.zinitcall.core1.init))
      KEEP (*(.zinitcall.core2.init))
      KEEP (*(.zinitcall.core3.init))
      KEEP (*(.zinitcall.core4.init))
      __zinitcall_core_end = .;
      __zinitcall_sys_service_start = .;
      KEEP (*(.zinitcall.sys.service0.init))
      KEEP (*(.zinitcall.sys.service1.init))
      KEEP (*(.zinitcall.sys.service2.init))
      KEEP (*(.zinitcall.sys.service3.init))
      KEEP (*(.zinitcall.sys.service4.init))
      __zinitcall_sys_service_end = .;
      __zinitcall_sys_feature_start = .;
      KEEP (*(.zinitcall.sys.feature0.init))
      KEEP (*(.zinitcall.sys.feature1.init))
      KEEP (*(.zinitcall.sys.feature2.init))
      KEEP (*(.zinitcall.sys.feature3.init))
      KEEP (*(.zinitcall.sys.feature4.init))
      __zinitcall_sys_feature_end = .;
      __zinitcall_run_start = .;
      KEEP (*(.zinitcall.run0.init))
      KEEP (*(.zinitcall.run1.init))
      KEEP (*(.zinitcall.run2.init))
      KEEP (*(.zinitcall.run3.init))
      KEEP (*(.zinitcall.run4.init))
      __zinitcall_run_end = .;
      __zinitcall_app_service_start = .;
      KEEP (*(.zinitcall.app.service0.init))
      KEEP (*(.zinitcall.app.service1.init))
      KEEP (*(.zinitcall.app.service2.init))
      KEEP (*(.zinitcall.app.service3.init))
      KEEP (*(.zinitcall.app.service4.init))
      __zinitcall_app_service_end = .;
      __zinitcall_app_feature_start = .;
      KEEP (*(.zinitcall.app.feature0.init))
      KEEP (*(.zinitcall.app.feature1.init))
      KEEP (*(.zinitcall.app.feature2.init))
      KEEP (*(.zinitcall.app.feature3.init))
      KEEP (*(.zinitcall.app.feature4.init))
      __zinitcall_app_feature_end = .;
      __zinitcall_test_start = .;
      KEEP (*(.zinitcall.test0.init))
      KEEP (*(.zinitcall.test1.init))
      KEEP (*(.zinitcall.test2.init))
      KEEP (*(.zinitcall.test3.init))
      KEEP (*(.zinitcall.test4.init))
      __zinitcall_test_end = .;
      __zinitcall_exit_start = .;
      KEEP (*(.zinitcall.exit0.init))
      KEEP (*(.zinitcall.exit1.init))
      KEEP (*(.zinitcall.exit2.init))
      KEEP (*(.zinitcall.exit3.init))
      KEEP (*(.zinitcall.exit4.init))
      __zinitcall_exit_end = .;
```

需要新增上述段是因为`bootstrap_init`提供的对外接口，见`//utils/native/lite/include/ohos_init.h`文件，采用的是灌段的形式，最终会保存到上述链接段中。主要的服务自动初始化宏如下表格所示：

| 接口名                 | 描述                             |
| ---------------------- | -------------------------------- |
| SYS_SERVICE_INIT(func) | 标识核心系统服务的初始化启动入口 |
| SYS_FEATURE_INIT(func) | 标识核心系统功能的初始化启动入口 |
| APP_SERVICE_INIT(func) | 标识应用层服务的初始化启动入口   |
| APP_FEATURE_INIT(func) | 标识应用层功能的初始化启动入口   |

![](../public_sys-resources/icon-note.gif) **说明：** 
	通过上面加载的组件编译出来的lib文件需要手动加入强制链接。

​	如在 `vendor/bestechnic/display_demo/config.json` 中配置了`bootstrap_lite` 部件

```
    {
      "subsystem": "startup",
      "components": [
        {
          "component": "bootstrap_lite"
        },
        ...
      ]
    },
```

​	`bootstrap_lite`部件会编译`//base/startup/bootstrap_lite/services/source/bootstrap_service.c`，该文件中，通过`SYS_SERVICE_INIT`将`Init`函数符号灌段到`__zinitcall_sys_service_start`和`__zinitcall_sys_service_end`中，由于`Init`函数是没有显式调用它，所以需要将它强制链接到最终的镜像。如下：

```
static void Init(void)
{
    static Bootstrap bootstrap;
    bootstrap.GetName = GetName;
    bootstrap.Initialize = Initialize;
    bootstrap.MessageHandle = MessageHandle;
    bootstrap.GetTaskConfig = GetTaskConfig;
    bootstrap.flag = FALSE;
    SAMGR_GetInstance()->RegisterService((Service *)&bootstrap);
}
SYS_SERVICE_INIT(Init);   --- 通过SYS启动即SYS_INIT启动就需要强制链接生成的lib
```

​	在`//base/startup/bootstrap_lite/services/source/BUILD.gn`文件中，描述了在`out/v200zr/display_demo/libs` 生成 `libbootstrap.a`，如下：

```
static_library("bootstrap") {
  sources = [
    "bootstrap_service.c",
    "system_init.c",
  ]
  ....
```

​	那么需要在 `vendor/bestechnic/display_demo/config.json` 配置强制链接库`bootstrap`，如下：

```
  "bin_list": [
    {
      "elf_name": "wifiiot",
      "bsp_target_name": "best2600w_liteos",
      "signature": "false",
      "burn_name": "rtos_main",
      "enable": "true",
      "force_link_libs": [
        "bootstrap",	 --- 强制链接libbootstrap.a
        ...
      ]
    },
```



适配`syspara_lite`部件时，系统参数会最终写到文件中进行持久化保存。在轻量系统中，文件操作相关接口有`POSIX`接口与`HalFiles`接口这两套实现。

因为对接内核的文件系统，采用`POSIX`相关的接口，所以`features`字段中需要增加`enable_ohos_startup_syspara_lite_use_posix_file_api = true`。

如果对接`HalFiles`相关的接口实现的，则无须修改。

在适配`GetSerial`接口时，开发板不像产线生产过程那样，会写入一个具体的`Serial Number`，因而需要确定一个数据对开发板进行唯一标识。本案例采用`WiFi Mac`地址进行适配。

```
#define ETH_ALEN 6
#define MAC_BITS 4
#define MAC_HIGH_MASK 0xf0
#define MAC_LOW_MASK 0x0f
#define HEX_A 0xa
#define CHAR_NUM_OFFSET 0x30
#define CHAR_CAPITAL_OFFSET 0x37
#define STR_END_FLAG '\0'

typedef unsigned char               u8;

static char serialNumber[2*ETH_ALEN + 1];		 --- 最后一位留作'\0'结束符标识


static char Hex2Char(u8 hex)
{
    if (hex < HEX_A) {
        return hex + CHAR_NUM_OFFSET;			 --- 将数值0转为char的'0'
    } else {
        return hex + CHAR_CAPITAL_OFFSET;		 --- 将数值0xa转为char的'A'
    }
}

const char* HalGetSerial(void)
{
    char macAddr[ETH_ALEN];
    // as devboard has no production serial number, we just
    // use wifi mac address as device serial number.
    if (serialNumber[0] == STR_END_FLAG) {		 --- 只有第一次调用时，才去获取mac地址
        extern int bwifi_get_own_mac(u8 *addr);
        bwifi_get_own_mac(macAddr);				 --- 获取mac地址
        int j = 0;
        for (int i = 0; i < ETH_ALEN; i++) {
            u8 lowFour, highFour;
            highFour = (macAddr[i] & MAC_HIGH_MASK) >> MAC_BITS;
            serialNumber[j] = Hex2Char(highFour);
            j++;
            lowFour = macAddr[i] & MAC_LOW_MASK;
            serialNumber[j] = Hex2Char(lowFour);
            j++;
        }		 --- 将mac地址值转化为serial number
    }
    return serialNumber;
}
```

#### DFX子系统适配

进行`DFX`子系统适配需要添加`hilog_lite`部件，直接在`config.json`文件配置即可。

```
{
  "subsystem": "hiviewdfx",
  "components": [
	{
	  "component": "hilog_lite",
	  "optional": "true"
	}
  ]
},
```

配置完成之后，在`//device/soc/bestechnic/bes2600/liteos_m/components/utils/src/hm_sys.c`中注册日志输出实现函数。

```
boolean HilogProc_Impl(const HiLogContent *hilogContent, uint32 len)
{
    char tempOutStr[LOG_FMT_MAX_LEN] = {0};
    if (LogContentFmt(tempOutStr, sizeof(tempOutStr), hilogContent) > 0) {
        printf(tempOutStr);
    }
	return TRUE;   
}

HiviewRegisterHilogProc(HilogProc_Impl);
```

#### 系统服务管理子系统适配

进行系统服务管理子系统适配需要添加`samgr_lite`部件，直接在`config.json`配置即可。

```
{
  "subsystem": "systemabilitymgr",
  "components": [
	{
	  "component": "samgr_lite",
	  "features": [
		"config_ohos_systemabilitymgr_samgr_lite_shared_task_size = 4096"
	  ]
	}
  ]
},
```

在轻量系统中，`samgr_lite`配置的共享任务栈大小默认为`0x800`。当函数调用栈较大时，会出现栈溢出的问题。在本次适配过程中，将其调整为`0x1000`。

#### 安全子系统适配

进行安全子系统适配需要添加`huks/deviceauth_lite`部件，直接在`config.json`配置即可。

```
    {
      "subsystem": "security",
      "components": [
        {
          "component": "huks",
          "features": [
            "huks_use_lite_storage = true",
            "huks_use_hardware_root_key = true",
            "huks_config_file = \"hks_config_lite.h\"",
            "huks_key_store_path = \"/data/\"",
            "ohos_security_huks_mbedtls_porting_path = \"//device/soc/bestechnic/hals/mbedtls\""
          ]
        },
        {
          "component": "deviceauth_lite",
          "features": [
            "deviceauth_storage_path = \"/data/\"",
            "deviceauth_hichain_thread_stack_size = 9472"
          ]
        }
      ]
    }
```

`huks`部件适配时，`huks_key_store_path`配置选项用于指定存放秘钥路径，`ohos_security_huks_mbedtls_porting_path`配置选项用于指定进行`mbedtls`适配的目录，用于芯片对`mbedtls`进行硬件随机数等适配。

`deviceauth_lite`部件适配时，`deviceauth_storage_path`配置选项用于指定存放设备认证信息的路径，`deviceauth_hichain_thread_stack_size`用于指定线程栈大小。

#### 媒体子系统适配

进行媒体子系统适配需要添加`histreamer`部件，直接在`config.json`配置即可。

```
{
  "subsystem": "multimedia",
  "components": [
    {
      "component": "histreamer",
      "features": [
        "histreamer_enable_plugin_hdi_adapter = true",
        "histreamer_enable_plugin_minimp3_adapter = true",
        "histreamer_enable_plugin_ffmpeg_adapter = false",
        "config_ohos_histreamer_stack_size = 65536"
      ]
    }
  ]
},
```

`histreamer`部件配置项说明如下：

| 配置项                                   | 说明                            |
| ---------------------------------------- | ------------------------------- |
| histreamer_enable_plugin_hdi_adapter     | 是否使能histreamer对接到hdi接口 |
| histreamer_enable_plugin_minimp3_adapter | 是否使能插件适配minimp3         |
| histreamer_enable_plugin_ffmpeg_adapter  | 是否使能插件适配FFmpeg          |
| config_ohos_histreamer_stack_size        | histreamer栈大小设置            |

#### 公共基础库子系统适配

进行公共基础库子系统适配需要添加`kv_store`/`js_builtin`/`timer_task`/`kal_timer`部件，直接在`config.json`配置即可。

```
{
  "subsystem": "utils",
  "components": [
	{
	  "component": "kv_store",
	  "features": [
		"enable_ohos_utils_native_lite_kv_store_use_posix_kv_api = true"
	  ]
	},
	{
	  "component": "js_builtin"
	},
	{
	  "component": "timer_task"
	},
	{
	  "component": "kal_timer",
	}
  ]
},
```

与适配`syspara_lite`部件类似，适配`kv_store`部件时，键值对会写到文件中。在轻量系统中，文件操作相关接口有`POSIX`接口与`HalFiles`接口这两套实现。因为对接内核的文件系统，采用`POSIX`相关的接口，所以`features`需要增加`enable_ohos_utils_native_lite_kv_store_use_posix_kv_api = true`。如果对接`HalFiles`相关的接口实现的，则无须修改。

#### 图形子系统适配

进行图形子系统适配需要添加`graphic_utils`部件，直接在`config.json`配置即可。

```
    {
      "components": [
        {
          "component": "graphic_utils",
          "features": [
            "enable_ohos_graphic_utils_product_config = true"
          ]
        },
        {
          "component": "ui"
        }
      ]
    },
```

`graphic`配置文件见 `//vendor/bestechnic/display_demo/graphic_config/product_graphic_lite_config.h`。

`graphic`适配见`//device/soc/bestechnic/bes2600/liteos_m/components/ui`, 主要功能如下：

- `display_device`：实例化`BaseGfxEngine`。
- `touch_input`：实例化`PointerInputDevice`。
- `UiMainTask`：初始化字体引擎，执行渲染任务等。

图形子系统层次：

```
aafwk_lite + appexecfwk_lite    (AAFWK + APPEXECFWK)
      |
ace_engine_lite + jerryscript + i18n_lite + resmgr_lite + utils/native/lite/... (ACE,JS引擎及其依赖)
      |
arkui_ui_lite + graphic_utils      (图形框架)
      |
giflib + libjpeg + libpng + qrcodegen + freetype... (图形第三方库)
```

图形应用示例见文件`//vendor/bestechnic/display_demo/tests/app.cpp`，如下：

```
/* ui app entry */
void RunApp()
{
#ifdef UI_TEST
    AnimatorDemoStart(); 	 --- native ui demo
#elif defined(ABILITY_TEST)
    StartJSApp(); 			 --- js demo
#endif
}

void AppEntry(void)
{
    UiMain();
}

APP_FEATURE_INIT(AppEntry);
```

#### ACE开发框架子系统适配

进行`ACE`开发框架子系统适配需要添加`ace_engine_lite`部件，直接在`config.json`配置即可。

    {
      "subsystem": "ace",
      "components": [
        {
          "component": "ace_engine_lite",
          "features": [
            "ace_engine_lite_feature_product_config = true"
          ]
        }
      ]
    },

`ace_engine_lite`部件配置文件见 `//vendor/bestechnic/display_demo/ace_lite_config/product_acelite_config.h`。

`ace_lite`的应用采用js语言进行开发，详细步骤如下：

1. 用`DevEco Studio`编写js应用，参考[轻量级智能穿戴开发](https://developer.harmonyos.com/cn/docs/documentation/doc-references/lite-wearable-file-0000001176751380)。
2. 使用预览功能进行预览，并且得到js包：`entry\.preview\intermediates\res\debug\lite\assets\js\default`。
3. 将js包放到对应的文件系统目录下，文件系统路径为`vendor/bestechnic/display_demo/fs/data/data/js`，如下：

```
├── app.js
├── common
├── i18n
├── manifest.json
└── pages
```

4. 最终编译生成系统镜像，烧录到单板后，系统会从`app.js`加载启动`ace`的应用。

#### 元能力子系统适配

进行元能力子系统适配需要添加`aafwk_lite`部件，直接在`config.json`配置即可。

```
    {
      "subsystem": "aafwk",
      "components": [
        {
          "component": "aafwk_lite",
          "features": [
            "ability_lite_enable_ohos_appexecfwk_feature_ability = true",	 --- 支持FA特性，即包含图形能力
            "ability_lite_config_ohos_aafwk_ams_task_size = 4096"			 --- 配置aafwk栈的大小
          ]
        }
      ]
    },
```

`aafwk_lite`相关的应用样例见`vendor/bestechnic/display_demo/tests/ability`目录，包含`launcher`和`js app`这两类应用，应用的函数调用流程描述如下：

1. `launcher`应用，通过`InstallLauncher`安装`BundleName`为 `"com.example.launcher"`的`native ui`应用，在`AbilityMgrSliteFeature`启动后会调用`AbilityMgrHandler::StartLauncher()`启动`launcher`应用。
  
2. `StartJSApp`应用，通过`StartAbility`启动任意`Want`，通过将`want data`传递`JS_APP_PATH`,
   `SetWantData(&want, JS_APP_PATH, strlen(JS_APP_PATH) + 1)`。

#### 包管理子系统适配

进行包管理子系统适配需要添加`appexecfwk_lite`部件，直接在`config.json`配置即可。

```
    {
      "subsystem": "appexecfwk",
      "components": [
        {
          "component": "appexecfwk_lite"
        }
      ]
    },
```

## 兼容性认证

### 产品兼容性规范

产品兼容性规范文档请参考[产品兼容性SIG介绍](https://gitee.com/openharmony-sig/compatibility/tree/master)。

### XTS用例

`XTS`测试参考资料见[xts参考资料](../device-test/xts.md)，进行`XTS`子系统适配需要添加`xts_acts`/`xts_tools`部件，直接在`config.json`配置即可，配置如下：

    {
      "subsystem": "xts",
      "components": [
        { "component": "xts_acts", "features":
          [
            "config_ohos_xts_acts_utils_lite_kv_store_data_path = \"/data\"",
            "enable_ohos_test_xts_acts_use_thirdparty_lwip = true"
          ]
        },
        { "component": "xts_tools", "features":[] }
      ]
    }

其中，

- `config_ohos_xts_acts_utils_lite_kv_store_data_path` 是配置挂载文件系统根目录的名字。
- `enable_ohos_test_xts_acts_use_thirdparty_lwip` 表示如果使用`thirdparty/lwip`目录下的源码编译，则设置为`true`，否则设置为`false`。

全部跑完会有显示`xx Tests xx Failures xx Ignored`，如下：

```
...
[16:53:43:438]../../../test/xts/acts/utils_lite/kv_store_hal/src/kvstore_func_test.c:793:testKvStoreMaxSize004:PASS
[16:53:43:438]+-------------------------------------------+
[16:53:43:438]
[16:53:43:438]-----------------------
[16:53:43:438]32 Tests 0 Failures 0 Ignored 
[16:53:43:438]OK
[16:53:43:439]All the test suites finished!
```

### 报告提交

将上图`XTS`用例的情况保存为测试报告，上传到`OpenHarmony`兼容性测试网站进行认证，作为`sig`仓库转正到`master`仓库的必要条件。详细步骤如下：

步骤1：将`XTS`测试报告压缩成`zip`文件。

步骤2：生成测试报告的`SHA`校验码。本案例是将`zip`文件传到在线生成`hash`的[网站]( https://tool.lmeee.com/jiami/filehash)生成`SHA`校验码。

步骤3：进入`OpenHarmony`[兼容性测试网站](https://www.openharmony.cn/old/#/Compatibility_test)上传报告。

 - 其中`API Level`填写报告中的`"sdkApiLevel"`字段
 - `OS`版本号填写报告中的`"OS Version"`字段。

## todo

后续会补充以下方面的移植：

- 蓝牙
- `bms`包安装
- 验证运行`JS`的`bytecode`
- 分布式能力：`dms`、`dm`
- 分布式音乐播放器样例

porting-bes2600w-on-minisystem-display-demo.md