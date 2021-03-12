# Development<a name="EN-US_TOPIC_0000001054690948"></a>

1.  Complete the operations described in  [Getting Started with Hi3861](../quick-start/introduction-to-the-hi3861-development-board.md).

    LED control examples are stored in the file  **applications/sample/wifi-iot/app/iothardware/led\_example.c**.

2.  Refer to the schematic diagram to understand the cable connections. The LED of Hispark Pegasus should be connected to pin 9.

    ```
    #define LED_TEST_GPIO 9
    ```

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >For details about the schematic diagram of the development board, contact the Hi3861 customer service personnel.

3.  Initialize the GPIO pin, specify the pin usage, and create a task to turn on or off the LED periodically so that the LED blinks.

    ```
    static void LedExampleEntry(void)
    {
        osThreadAttr_t attr;
    
        /* Initialize the GPIO pin. */
        IoTGpioInit(LED_TEST_GPIO);
        /* Set pin 9 as the output direction. */
        IoTGpioSetDir(LED_TEST_GPIO, IOT_GPIO_DIR_OUT);
    
        attr.name = "LedTask";
        attr.attr_bits = 0U;
        attr.cb_mem = NULL;
        attr.cb_size = 0U;
        attr.stack_mem = NULL;
        attr.stack_size = LED_TASK_STACK_SIZE;
        attr.priority = LED_TASK_PRIO;
    
        /* Start the task. */
        if (osThreadNew((osThreadFunc_t)LedTask, NULL, &attr) == NULL) {
            printf("[LedExample] Failed to create LedTask!\n");
        }
    }
    ```

4.  Use a cyclic task in which the LED periodically turns on and off to implement LED blinking.

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
        return NULL;
    }
    ```

5.  Call  **SYS\_RUN\(\)**  of OpenHarmony to start the service. \(**SYS\_RUN**  is defined in the  **ohos\_init.h**  file.\)

    ```
    SYS_RUN(LedExampleEntry);
    ```

6.  Change the  **applications/sample/wifi-iot/app/BUILD.gn**  file to enable  **led\_example.c**  to participate in compilation.

    ```
    import("//build/lite/config/component/lite_component.gni")
    lite_component("app") {
        features = [
            "iothardware:led_example"
        ]
    }
    ```


