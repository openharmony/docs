# Guidelines for Using Patches on OpenHarmony Development Boards<a name="EN-US_TOPIC_0000001081980461"></a>

The patch files are stored in the  **kernel/linux/patches/linux-4.19**  source code path of the project. You can obtain the driver patch of a specific chip architecture from this directory.

To use the patch of a specific chip platform driver, you need to merge the required kernel patch into the kernel code.

Merge the corresponding patches for different chip platforms.

The following uses Hi3516D V300 as an example:

```
patch -p1 < device/hisilicon/hi3516dv300/sdk_linux/open_source/linux/hisi_linux-4.19_hos_l2.patch 
```

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>Because patches are applied after the code environment of  **kernel/linux-4.19**  is copied during compilation and building of the OpenHarmony project, you must retain the original code environment of  **kernel/linux-4.19**  before running the OpenHarmony version-level build command.

