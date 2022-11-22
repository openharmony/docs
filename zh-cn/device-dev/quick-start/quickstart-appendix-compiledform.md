# 编译形态整体说明


在编译过程中，需要根据实际需求选择不同的编译形态。单击下表中的链接可获取具体产品配置，从而了解其中差异。


  **表1** 编译构建支持的产品列表

| **编译形态** | **开发板** | **主芯片** | **内核** | **系统类型** | 
| -------- | -------- | -------- | -------- | -------- |
| [neptune100](https://gitee.com/openharmony/vendor_hihope/blob/master/neptune_iotlink_demo/config.json) | neptune100 | winnermicro | liteos_m | mini | 
| [rk3568](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/config.json) | rk3568 | rockchip | linux | standard | 
| [rk3568_mini_system](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568_mini_system/config.json) | rk3568 | rockchip | linux | standard | 
| [bearpi_hm_micro](https://gitee.com/openharmony/vendor_bearpi/blob/master/bearpi_hm_micro/config.json) | bearpi_hm_micro | stm32mp1xx | liteos_a | small | 
| [bearpi_hm_nano](https://gitee.com/openharmony/vendor_bearpi/blob/master/bearpi_hm_nano/config.json) | bearpi_hm_nano | hi3861v100 | liteos_m | mini | 
| [wifiiot_hispark_pegasus](https://gitee.com/openharmony/vendor_hisilicon/blob/master/hispark_pegasus/config.json) | hispark_pegasus | hi3861v100 | liteos_m | mini | 
| [ipcamera_hispark_aries](https://gitee.com/openharmony/vendor_hisilicon/blob/master/hispark_aries/config.json) | hispark_aries | hi3518ev300 | liteos_a | small | 
| [ipcamera_hispark_taurus](https://gitee.com/openharmony/vendor_hisilicon/blob/master/hispark_taurus/config.json) | hispark_taurus | hi3516dv300 | liteos_a | small | 
| [ipcamera_hispark_taurus_linux](https://gitee.com/openharmony/vendor_hisilicon/blob/master/hispark_taurus_linux/config.json) | hispark_taurus | hi3516dv300 | linux | small | 
| [hispark_taurus_standard](https://gitee.com/openharmony/vendor_hisilicon/blob/master/hispark_taurus_standard/config.json) | hispark_taurus | hi3516dv300 | linux | standard | 
| [watchos](https://gitee.com/openharmony/vendor_hisilicon/blob/master/watchos/config.json) | hispark_taurus | hi3516dv300 | linux | standard | 
| [hispark_phoenix](https://gitee.com/openharmony/vendor_hisilicon/blob/master/hispark_phoenix/config.json) | hispark_phoenix | hi3751v350 | linux | standard | 
| [hispark_taurus_mini_system](https://gitee.com/openharmony/vendor_hisilicon/blob/master/hispark_taurus_mini_system/config.json) | hispark_taurus | hi3516dv300 | liteos_a | mini | 
| [hispark_pegasus_mini_system](https://gitee.com/openharmony/vendor_hisilicon/blob/master/hispark_pegasus_mini_system/config.json) | hispark_pegasus | hi3861v100 | liteos_m | mini | 
| [gr5515_sk_iotlink_demo](https://gitee.com/openharmony/vendor_goodix/blob/master/gr5515_sk_iotlink_demo/config.json) | gr5515_sk | gr551x | liteos_m | mini | 
| [gr5515_sk_xts_demo](https://gitee.com/openharmony/vendor_goodix/blob/master/gr5515_sk_xts_demo/config.json) | gr5515_sk | gr551x | liteos_m | mini | 
| [wifi_demo](https://gitee.com/openharmony/vendor_asrmicro/blob/master/wifi_demo/config.json) | dev_wifi_a | asr582x | liteos_m | mini | 
| [xts_demo](https://gitee.com/openharmony/vendor_asrmicro/blob/master/xts_demo/config.json) | dev_wifi_a | asr582x | liteos_m | mini | 
| [display_demo](https://gitee.com/openharmony/vendor_bestechnic/blob/master/display_demo/config.json) | v200zr | bes2600 | liteos_m | mini | 
| [xts_demo](https://gitee.com/openharmony/vendor_bestechnic/blob/master/xts_demo/config.json) | v200zr | bes2600 | liteos_m | mini | 
| [iotlink_demo](https://gitee.com/openharmony/vendor_bestechnic/blob/master/iotlink_demo/config.json) | v200zr | bes2600 | liteos_m | mini | 
| [mini_distributed_music_player](https://gitee.com/openharmony/vendor_bestechnic/blob/master/mini_distributed_music_player/config.json) | v200zr | bes2600 | liteos_m | mini | 
| [niobe407](https://gitee.com/openharmony/vendor_talkweb/blob/master/niobe407/config.json) | niobe407 | stm32f4xx | liteos_m | mini | 
| [qemu_mini_system_demo](https://gitee.com/openharmony/vendor_ohemu/blob/master/qemu_mini_system_demo/config.json) | arm_mps2_an386 | qemu | liteos_m | mini | 
| [qemu_csky_mini_system_demo](https://gitee.com/openharmony/vendor_ohemu/blob/master/qemu_csky_mini_system_demo/config.json) | SmartL_E802 | qemu | liteos_m | mini | 
| [qemu_cm55_mini_system_demo](https://gitee.com/openharmony/vendor_ohemu/blob/master/qemu_cm55_mini_system_demo/config.json) | arm_mps3_an547 | qemu | liteos_m | mini | 
| [qemu_xtensa_mini_system_demo](https://gitee.com/openharmony/vendor_ohemu/blob/master/qemu_xtensa_mini_system_demo/config.json) | esp32 | qemu | liteos_m | mini | 
| [qemu_riscv_mini_system_demo](https://gitee.com/openharmony/vendor_ohemu/blob/master/qemu_riscv32_mini_system_demo/config.json) | ricsv32_virt | qemu | liteos_m | mini | 
| [qemu_ca7_mini_system_demo](https://gitee.com/openharmony/vendor_ohemu/blob/master/qemu_ca7_mini_system_demo/config.json) | arm_virt | qemu | liteos_a | small | 
| [qemu_small_system_demo](https://gitee.com/openharmony/vendor_ohemu/blob/master/qemu_small_system_demo/config.json) | arm_virt | qemu | liteos_a | small | 
| [qemu_arm_linux_min](https://gitee.com/openharmony/vendor_ohemu/blob/master/qemu_arm_linux_min/config.json) | qemu-arm-linux | qemu | linux | standard | 
| [qemu_arm_linux_headless](https://gitee.com/openharmony/vendor_ohemu/blob/master/qemu_arm_linux_headless/config.json) | qemu-arm-linux | qemu | linux | standard | 
| [iotlink_demo](https://gitee.com/openharmony/vendor_chipsea/blob/master/iotlink_demo/config.json) | cst85_wblink | chipsea | liteos_m | mini | 
| [dsoftbus_demo](https://gitee.com/openharmony/vendor_chipsea/blob/master/dsoftbus_demo/config.json) | cst85_wblink | chipsea | liteos_m | mini | 
| [xts_demo](https://gitee.com/openharmony/vendor_chipsea/blob/master/xts_demo/config.json) | cst85_wblink | chipsea | liteos_m | mini | 
