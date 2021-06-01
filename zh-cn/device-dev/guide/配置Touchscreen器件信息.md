# 配置Touchscreen器件信息<a name="ZH-CN_TOPIC_0000001113543350"></a>

配置文件路径：./drivers/adapter/khdf/linux/hcs/input/input\_config.hcs

input\_config.hcs中的信息由驱动代码进行读取解析，主要由公共驱动层的私有配置信息及器件驱动层的私有配置信息组成。文件中的配置包含板级硬件信息及器件私有配置信息，实际业务开发时，可根据具体需求增删及修改对应内容。

```
root {                                                              
    input_config {
        touchConfig {
            touch0 {                                                 // 第一款触摸屏
                boardConfig {                                        // 板级硬件信息
                    match_attr = "touch_device1";                    // 与设备描述配置信息中公共驱动层私有配置信息的“match_attr”字段保持一致    
                    inputAttr {
                        /* 0:touch 1:key 2:keyboard 3:mouse 4:button 5:crown 6:encoder */
                        inputType = 0;                               // input类型为touch
                        solutionX = 480;                             // 分辨率X信息
                        solutionY = 960;                             // 分辨率Y信息
                        devName = "main_touch";                      // 设备名称
                    }
                    busConfig {
                        /* 0:i2c 1:spi */
                        busType = 0;                                 // GT911采用I2C通信
                        busNum = 6;                                  // 与主机芯片第6路I2C通信
                        clkGpio = 86;                                // 主机芯片SCL管脚
                        dataGpio = 87;                               // 主机芯片SDA管脚
                        i2cClkIomux = [0x114f0048, 0x403];           // SCL管脚配置信息
                        i2cDataIomux = [0x114f004c, 0x403];          // SDA管脚配置信息
                    }
                    pinConfig {
                        rstGpio = 3;                                 // 复位管脚连接主机芯片的3号管脚
                        intGpio = 4;                                 // 中断管脚连接主机芯片的4号管脚
                        rstRegCfg = [0x112f0094, 0x400];             // 复位管脚配置信息
                        intRegCfg = [0x112f0098, 0x400];             // 中断管脚配置信息
                    }
                    powerConfig {
                        /* 0:unused 1:ldo 2:gpio 3:pmic */
                        vccType = 2;                                  // GPIO供电
                        vccNum = 20;                                  // gpio20
                        vccValue = 1800;                              // 电压幅值为1800mV
                        vciType = 1;                                  // LDO供电
                        vciNum = 12;                                  // ldo12
                        vciValue = 3300;                              // 电压幅值为3300mV 
                    }

                    featureConfig {
                        capacitanceTest = 0;                          // 容值测试
                        gestureMode = 0;                              // 手势模式
                        gloverMode = 0;                               // 手套模式
                        coverMode = 0;                                // 皮套模式
                        chargerMode = 0;                              // 充电模式
                        knuckleMode = 0;                              // 指关节模式
                    }
                }
                chipConfig {                                          // 器件私有信息配置
                    template touchChip {                              // 模板
                        match_attr = "";
                        chipName = "gt911";                           // 触摸屏IC型号
                        vendorName = "zsj";                           // 供应商
                        chipInfo = "AAAA11222";                       // 1~4字符代表产品名，5~6字符代表IC型号，7~9字符代表模型型号
                        busType = 0;                                  // 0代表I2C，1代表SPI
                        deviceAddr = 0x5D;                            // 器件IC通信地址
                        irqFlag = 2;                                  // 1代表上升沿触发，2代表下降沿触发，4代表高电平触发，8代表低电平触发
                        maxSpeed = 400;                               // 最大通信速率为400Hz
                        chipVersion = 0;                              // 触摸屏IC版本号
                        powerSequence {
                             /* 上电时序的配置含义说明：
                               [类型, 状态, 方向 , 延时]
                               <type> 0代表空，1代表vcc电源（1.8V），2代表VCI电源（3.3V），3代表复位管脚，4代表中断管脚
                               <status> 0代表下电或拉低，1代表上电或拉高，2代表无操作
                               <dir> 0代表输入方向，1代表输出方向，2代表无操作
                               <delay> 代表延时多少毫秒, 例如20代表延时20ms
                             */
                            powerOnSeq = [4, 0, 1, 0,                 // 中断管脚配置为输出，且进行拉低
                                         3, 0, 1, 10,                 // 复位管脚配置为输出，且进行拉低，延时10ms
                                         3, 1, 2, 60,                 // 复位管脚无操作，且进行拉高，延时60ms
                                         4, 2, 0, 0];                 // 中断管脚配置为输入
                            suspendSeq = [3, 0, 2, 10];               // 复位管脚无操作，且进行拉低，延时10ms
                            resumeSeq = [3, 1, 2, 10];                // 复位管脚无操作，且进行拉高，延时10ms
                            powerOffSeq = [3, 0, 2, 10,               // 复位管脚无操作，且进行拉低，延时10ms
                                           1, 0, 2, 20];              // 电源正极管脚无操作，且进行拉低，延时20ms
                        }
                    }

                    chip0 :: touchChip {
                        match_attr = "zsj_gt911_5p5";                 // 与设备描述配置信息中器件私有配置信息的“match_attr”字段保持一致
                        chipInfo = "ZIDN45100";                       // 产品名+模组编号+芯片编号的组合信息 用于给用户态区分当前器件
                        chipVersion = 0;                              // IC型号的版本
                    }
                }
            }
        }
    }
}
```

示例中“touchConfig”包含了“touch0”，"touch0"包含了“boardConfig”与“chipConfig”；“boardConfig”字段包含了Hi3516DV300板级硬件信息，“chipConfig”包含了触摸屏器件的私有信息，如果需要替换触摸屏器件，重新配置“chipConfig”对应的字段信息即可。同时产品可以配置多款触摸屏，示例中用“touch0”代表了套件中默认的触摸屏的硬件接口以及器件的配置信息，如产品需要配置副屏，可在与“touch0”并列的位置配置“touch1”的信息。

