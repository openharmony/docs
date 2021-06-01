# Building and Burning<a name="EN-US_TOPIC_0000001110903354"></a>

1.  Compile the Makefile and add the following content in this example.

    The file is available at  **./drivers/adapter/khdf/linux/model/input/Makefile**.

    Add the following content:

    ```
    obj-$(CONFIG_DRIVERS_HDF_TP_5P5_GT911) += \
                  $(INPUT_ROOT_DIR)/touchscreen/touch_gt911.o
    ```

    **touch\_gt911.o**  is the content added in this example.

2.  Conduct building and burn. For details about the building and burning operations, see  [Build and Burn in Getting Started with Standard System](../quick-start/standard-system.md).

