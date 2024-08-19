# 产品
### 产品配置规则

产品解决方案为基于开发板的完整产品，主要包含产品对OS的适配、部件拼装配置、启动配置和文件系统配置等。产品解决方案的源码路径规则为：**vendor/{产品解决方案厂商}/{产品名称}**_。

产品解决方案的目录树规则如下：

```shell
vendor                              
└── company                         # 产品解决方案厂商
    ├── product                     # 产品名称
    │   ├── init_configs
    │   │     ├── etc               # init进程启动配置（可选，仅linux内核需要）
    │   │     └── init.cfg          # 系统服务启动配置
    │   ├── hals                    # 产品解决方案OS适配
    │   ├── BUILD.gn                # 产品编译脚本
    │   └── config.json             # 产品配置文件
    │   └── fs.yml                  # 文件系统打包配置
    └── ......
```

> ![icon-note.gif](public_sys-resources/icon-note.gif)**注意**：新增产品须按如上的规则创建目录和文件，编译构建系统将按该规则扫描已配置的产品。

关键的目录和文件详细介绍如下：

1. **vendor/company/product/init_configs/etc** 该文件夹中包含rcS脚本，Sxxx脚本和fstab脚本。init进程在启动系统服务之前执行这些脚本。执行的流程为“rcS->fstab->S00-xxx“。Sxxx脚本中的内容与开发板和产品需要有关，主要包括设备节点的创建、创建目录、扫描设备节点、修改文件权限等等。这些文件在产品编译的BUILD.gn中按需拷贝到产品out目录中，最终打包到rootfs镜像中。

2. **vendor/company/product/init_configs/init.cfg** init进程启动服务的配置文件，当前支持解析的命令有：

   - start: 启动某个服务

   - mkdir: 创建文件夹

   - chmod: 修改指定路径/文件的权限

   - chown: 修改指定路径/文件的属组

   - mount: 挂载命令

     该文件中的各个字段的解释如下：

   ```shell
   {
       "jobs" : [{                                                     # job数组，一个job对应一个命令集合。job的执行顺序：pre-init -> init -> post-init。
               "name" : "pre-init",
               "cmds" : [
                   "mkdir /storage/data",                              # 创建目录
                   "chmod 0755 /storage/data",                         # 修改权限，权限值的格式为0xxx, 如0755
                   "mkdir /storage/data/log",
                   "chmod 0755 /storage/data/log",
                   "chown 4 4 /storage/data/log",                      # 修改属组，第一个数字为uid, 第二个数字为gid
                   ......
                   "mount vfat /dev/mmcblock0 /sdcard rw,umask=000"    # 挂载，格式为： mount [文件系统类型] [source] [target] [flags] [data]
                                                                       # 其中flags仅支持：nodev、noexec、nosuid和rdonly
               ]
           }, {
               "name" : "init",
               "cmds" : [                                              # 按cmds数组顺序启动启动服务
                   "start shell",                                      # 注意：start与服务名称之间有且只有一个空格
                   ......
                   "start service1"
               ]
           }, {
               "name" : "post-init",                                   # 最后执行的job, init进程启动完成后的处理（如驱动初始化后再mount设备）
               "cmds" : []
           }
       ],
       "services" : [{                                                 # service数组，一个service对应一个进程
               "name" : "shell",                                       # 服务名称
               "path" : ["/sbin/getty", "-n", "-l", "/bin/sh", "-L", "115200", "ttyS000", "vt100"],    # 可执行文件全路径，path必须为第一个元素
               "uid" : 0,                                              # 进程的uid，须与二进制文件的uid保持一致
               "gid" : 0,                                              # 进程的gid，须与二进制文件的gid保持一致
               "once" : 0,                                             # 是否为一次性进程，1：进程退出后，init不在重新拉起。0：常驻进程，进程若退出，init将重新拉起
               "importance" : 0,                                       # 是否为关键进程，1：是关键进程，若进程退出，init将会重启单板。0：非关键进程，若进程退出，init不会重启单板
               "caps" : [4294967295]
           }, 
           ......
       ]
   }
   ```

3. **vendor/company/product/init_configs/hals** 解决方案厂商对OS的适配，需要实现的接口请见各个部件的readme说明文档。

4. **vendor/company/product/config.json** config.json为编译构建的主入口，包含了开发板、OS部件和内核等配置信息。

   以基于hispark_taurus开发板的ipcamera产品为例，配置文件如下：

   ```shell
   {
        "product_name": "ipcamera",                       # 产品名称
        "version": "3.0",                                 # config.json的版本号, 固定"3.0"
        "type": "small",                                  # 系统类型, 可选[mini, small, standard]
        "ohos_version": "OpenHarmony 1.0",                # 选择的OS版本
        "device_company": "hisilicon",                    # 芯片厂商
        "board": "hispark_taurus",                        # 开发板名称
        "kernel_type": "liteos_a",                        # 选择的内核类型
        "kernel_version": "3.0.0",                        # 选择的内核版本
        "subsystems": [                            
          {
            "subsystem": "aafwk",                         # 选择的子系统
            "components": [
              { "component": "ability", "features":[ "ability_lite_enable_ohos_appexecfwk_feature_ability = true" ] }   # 选择的部件和部件特性配置
            ]
          },
          {
           ......
          }
         ......
         更多子系统和部件
        }
    }
   ```

5. **vendor/company/product/fs.yml** 该文件用于配置文件系统镜像制作过程，将编译产物打包成文件系统镜像，比如用户态根文件系统rootfs.img和可读写的userfs.img。它由多个列表组成，每个列表对应一个文件系统。字段说明如下：

   ```shell
   fs_dir_name： 必填，声明文件系统文件名, 如rootfs、userfs
   fs_dirs：     选填，配置out下文件目录与文件系统文件目录的映射关系，每个文件目录对应一个列表
   source_dir：  选填，out下目标文件目录，若缺失则将根据target_dir在文件系统下创建空目录
   target_dir：  必填，文件系统下对应文件目录
   ignore_files：选填，声明拷贝忽略文件
   dir_mode：    选填，文件目录权限，默认755
   file_mode：   选填，该文件目录下所有文件的权限，默认555
   fs_filemode： 选填，配置需要特殊声明权限的文件，每个文件对应一个列表
   file_dir：    必填，文件系统下具体文件路径
   file_mode：   必填，文件权限声明
   fs_symlink：  选填，配置文件系统软连接
   fs_make_cmd： 必填，配置需要制作文件系统脚本，OS提供的脚本在build/lite/make_rootfs下, 支持linux，liteos内核和ext4、jffs2、vfat格式。也支持芯片解决方案厂商自定义。   
   fs_attr：     选填，根据配置项动态调整文件系统
   ```

   其中fs_symlink、fs_make_cmd字段支持以下变量：

   - rootpath代码根目录，对应gn的{ohos_root_path}
   - outpath产品out目录，对应gn的{root_out_dir}
   - ${fs_dir} 文件系统目录，由以下变量拼接而成
   - ${root_path}
   - ${fs_dir_name}

>  ![icon-note.gif](public_sys-resources/icon-note.gif)**注意**：fs.yml是可选的，对于没有文件系统的设备可不配置。

6. **vendor/company/product/BUILD.gn** 产品编译的入口，主要用于编译解决方案厂商源码和拷贝启动配置文件。如果某个产品被选择为要编译的产品，那么对应产品目录下的BUILD.gn会默认编译。一个典型的产品编译BUILD.gn应该如下：

   ```shell
   group("product") {               # target名称需与product名称即三级目录名称一致
     deps = []
     deps += [ "init_configs" ]     # 拷贝init配置
     ......                         # 其他
   }
   ```

### 新增并编译产品

编译构建支持芯片解决方案和部件的灵活拼装，形成定制化的产品解决方案。具体步骤如下：

1. 创建产品目录 按照产品配置规则创建产品目录，以基于“rtl8720“开发板的wifiiot模组为例，在代码根目录执行：

   ```shell
   mkdir -p vendor/my_company/wifiiot
   ```

2. 拼装产品 在新建的产品目录下新建config.json文件，以步骤1中的wifiiot为例，vendor/my_company/wifiiot/config.json可以是：

   ```shell
   {
       "product_name": "wifiiot",                        # 产品名称
       "version": "3.0",                                 # config.json的版本号, 固定"3.0"
       "type": "small",                                  # 系统类型, 可选[mini, small, standard]
       "ohos_version": "OpenHarmony 1.0",                # 使用的OS版本
       "device_company": "realtek",                      # 芯片解决方案厂商名称
       "board": "rtl8720",                               # 开发板名称
       "kernel_type": "liteos_m",                        # 选择的内核类型
       "kernel_version": "3.0.0",                        # 选择的内核版本
       "subsystems": [                            
         {
           "subsystem": "kernel",                        # 选择的子系统
           "components": [
             { "component": "liteos_m", "features":[] }  # 选择的部件和部件特性
           ]
         },
         ...
         {
            更多子系统和部件
         }
       ]
   }
   ```

   ![icon-note.gif](public_sys-resources/icon-note.gif)**注意**：编译构建系统编译前会对device_company，board，kernel_type，kernel_version、subsystem、component字段进行有效性检查，其中device_company，board，kernel_type，kernel_version应与已知的芯片解决方案匹配，subsystem、component应与build/lite/components下的部件描述匹配。

3. 适配OS接口 在产品目录下创建hals目录，并将产品解决方案对OS适配的源码和编译脚本放入该目录下。

4. 配置系统服务 在产品目录下创建init_configs目录，并在init_configs目录下创建init.cfg文件，按需配置要启动的系统服务。

5. 配置init进程（仅linux内核需要） 在init_configs目录下创建etc目录，然后在etc下创建init.d文件夹和fstab文件。最后按产品需求在init.d文件下创建并编辑rcS文件和Sxxx文件。

6. 配置文件系统镜像（可选，仅支持文件系统的开发板需要） 在产品目录下创建fs.yml文件。fs.yml需按产品实际情况配置，一个典型的fs.yml文件如下：

   ```shell
   -
     fs_dir_name: rootfs # 镜像的名称
     fs_dirs:
       -
         # 将编译生成的out/my_board/my_product/bin目录下的文件拷贝到rootfs/bin中，并忽略测试bin
         source_dir: bin
         target_dir: bin
         ignore_files:
           - Test.bin
           - TestSuite.bin
       -
         # 将编译生成的out/my_board/my_product/libs目录下的文件拷贝到rootfs/lib中，忽略所有.a文件，并设置文件和文件夹的权限为644和755
         source_dir: libs
         target_dir: lib
         ignore_files:
           - .a
         dir_mode: 755
         file_mode: 644
       -
         source_dir: usr/lib
         target_dir: usr/lib
         ignore_files:
           - .a
         dir_mode: 755
         file_mode: 644
       -
         source_dir: config
         target_dir: etc
       -
         source_dir: system
         target_dir: system
       -
         source_dir: sbin
         target_dir: sbin
       -
         source_dir: usr/bin
         target_dir: usr/bin
       -
         source_dir: usr/sbin
         target_dir: usr/sbin
       -
         # 创建一个proc空目录
         target_dir: proc
       -
         target_dir: mnt
       -
         target_dir: opt
       -
         target_dir: tmp
       -
         target_dir: var
       -
         target_dir: sys
       -
         source_dir: etc
         target_dir: etc
       -
         source_dir: vendor
         target_dir: vendor
       -
         target_dir: storage
   
     fs_filemode:
       -
         file_dir: lib/ld-uClibc-0.9.33.2.so
         file_mode: 555
       -
         file_dir: lib/ld-2.24.so
         file_mode: 555
       -
         file_dir: etc/init.cfg
         file_mode: 400
     fs_symlink:
       -
         # 在rootfs/lib下创建软连接ld-musl-arm.so.1 -> libc.so
         source: libc.so
         link_name: ${fs_dir}/lib/ld-musl-arm.so.1
       -
         source: mksh
         link_name: ${fs_dir}/bin/sh
       -
         source: mksh
         link_name: ${fs_dir}/bin/shell
     fs_make_cmd:
       # 使用脚本将rootfs制作为ext4格式的image
       - ${root_path}/build/lite/make_rootfs/rootfsimg_linux.sh ${fs_dir} ext4
   -
     fs_dir_name: userfs
     fs_dirs:
       -
         source_dir: storage/etc
         target_dir: etc
       -
         source_dir: data
         target_dir: data
     fs_make_cmd:
       - ${root_path}/build/lite/make_rootfs/rootfsimg_linux.sh ${fs_dir} ext4
   ```

7. 配置产品Patch（可选，视产品涉及部件是否需要打补丁而定） 在产品目录下创建patch.yml文件。patch.yml需按产品实际情况配置，一个典型的patch.yml文件如下：

   ```shell
     # 需要打patch的路径
   foundation/communication/dsoftbus:
     # 该路径下需要打的patch存放路径
     - foundation/communication/dsoftbus/1.patch
     - foundation/communication/dsoftbus/2.patch
   third_party/wpa_supplicant:
     - third_party/wpa_supplicant/1.patch
     - third_party/wpa_supplicant/2.patch
     - third_party/wpa_supplicant/3.patch
   ...
   ```

   配置完成后，编译时增加--patch参数，即可在产品编译前将配置的Patch文件打到对应目录中，再进行编译：

   ```shell
   hb build -f --patch
   ```

8. 编写编译脚本 在产品目录下创建BUILD.gn文件，按产品实际情况编写脚本。以步骤1中的wifiiot为例，BUILD.gn示例如下：

   ```shell
   group("wifiiot") {             # target名称与产品名一致
     deps = []
     deps += [ "init_configs" ]   # 拷贝init配置
     deps += [ "hals" ]           # 将hals加入编译
     ......                       # 其他
   }
   ```

9. 编译产品。 主要有两种编译方式，[命令行方式和hb方式](subsys-build-all.md#编译命令)，这里以命令行方式为例，假设编译的产品名是hispark_taurus_standard，则编译命令是：

   ```
   ./build.sh --product-name hispark_taurus_standard --ccache
   ```

   
