# LED外设控制<a name="ZH-CN_TOPIC_0000001054530966"></a>


## 概述<a name="section14639174516337"></a>

OpenHarmony  WLAN模组基于Hi3861平台提供了丰富的外设操作能力，包含I2C、I2S、ADC、UART、SPI、SDIO、GPIO、PWM、FLASH等。本文介绍如何通过调用OpenHarmony的NDK接口，实现对GPIO控制，达到LED闪烁的效果。其他的IOT外设控制，开发者可根据API指导文档完成，此处不逐一介绍。

## 开发<a name="section13857170163412"></a>

1.  请先完成[轻量系统快速入门](../quick-start/quickstart-overview.md)。

    LED控制参考示例存放于applications/sample/wifi-iot/app/iothardware/led\_example.c文件中。

2.  实现IOT外设控制，首先需要通过查阅原理图明确接线关系。经过查阅，hispark pegasus的LED与芯片的9号管脚相连。

    ```
    #define LED_TEST_GPIO 9
    ```

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >开发板原理图，请开发者联系Hi3861购买渠道客服获取。

3.  使用GPIO前，需要完成GPIO管脚初始化，明确管脚用途，并创建任务，使LED周期性亮灭，达到闪烁的效果。

    ```
    static void LedExampleEntry(void)
    {
        osThreadAttr_t attr;
    
        /* 管脚初始化 */
        IoTGpioInit(LED_TEST_GPIO);
        /* 配置9号管脚为输出方向 */
        IoTGpioSetDir(LED_TEST_GPIO, IOT_GPIO_DIR_OUT);
    
        attr.name = "LedTask";
        attr.attr_bits = 0U;
        attr.cb_mem = NULL;
        attr.cb_size = 0U;
        attr.stack_mem = NULL;
        attr.stack_size = LED_TASK_STACK_SIZE;
        attr.priority = LED_TASK_PRIO;
    
        /* 启动任务 */
        if (osThreadNew((osThreadFunc_t)LedTask, NULL, &attr) == NULL) {
            printf("[LedExample] Failed to create LedTask!\n");
        }
    }
    ```

4.  在循环任务中通过周期性亮灭形式实现LED闪烁。

    ```
    static void *LedTask(const char *arg)
    {
        (void)arg;
        while (1) {
            switch (g_ledState) {
                case LED_ON:
                    IoTGpioSetOutputVal(LED_TEST_GPIO, 1);
                    usleep(LED_INTERVAL_TIME_US);
                    break;
                case LED_OFF:
                    IoTGpioSetOutputVal(LED_TEST_GPIO, 0);
                    usleep(LED_INTERVAL_TIME_US);
                    break;
                case LED_SPARK:
                    IoTGpioSetOutputVal(LED_TEST_GPIO, 0);
                    usleep(LED_INTERVAL_TIME_US);
                    IoTGpioSetOutputVal(LED_TEST_GPIO, 1);
                    usleep(LED_INTERVAL_TIME_US);
                    break;
                default:
                    usleep(LED_INTERVAL_TIME_US);
                    break;
            }
        }
    }
    ```

5.  在代码最下方，使用OpenHarmony启动恢复模块接口SYS\_RUN\(\)启动业务。（SYS\_RUN定义在ohos\_init.h文件中）

    ```
    SYS_RUN(LedExampleEntry);
    ```

6.  修改applications/sample/wifi-iot/app/BUILD.gn文件，使led\_example.c参与编译。

    ```
    import("//build/lite/config/component/lite_component.gni")
    lite_component("app") {
        features = [
            "iothardware:led_example"
        ]
    }
    ```


## 验证<a name="section1949121910344"></a>

编译过程请参考[轻量系统快速入门的编译章节](../quick-start/quickstart-ide-3861-build.md)，烧录过程请参考[轻量系统快速入门的烧录章节](../quick-start/quickstart-ide-3861-burn.md)。

完成以上两步后，按下RST键复位模组，可发现LED在周期性闪烁，与预期相符，验证完毕。

**图 1**  LED闪烁图<a name="fig20768175218527"></a>  
![](figures/LED闪烁图.gif "LED闪烁图")

