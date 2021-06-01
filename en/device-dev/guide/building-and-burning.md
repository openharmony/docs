# Building and Burning<a name="EN-US_TOPIC_0000001110744406"></a>

1.  Edit the Makefile and add a source file to it, as shown in the following example:

    ```
    include drivers/hdf/khdf/platform/platform.mk
    
    obj-y  += $(HDF_PLATFORM_FRAMEWORKS_ROOT)/src/i2c_core.o \
              $(HDF_PLATFORM_FRAMEWORKS_ROOT)/src/i2c_if.o \
              ./i2c_adapter.o \
              ./i2c_sample.o
    ```

    **./i2c\_sample.o**  is the source file added to the Makefile in this example.

2.  Build the version and burn the system image to the development board.

    For details about the building and burning operations, see  [Build and Burn in Getting Started with Standard System](../quick-start/standard-system.md).


