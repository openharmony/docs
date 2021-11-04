# Guidelines for Building the Linux Kernel<a name="EN-US_TOPIC_0000001076416924"></a>

The following uses the Hi3516D V300 development board and Ubuntu x86 server as an example.

Perform a full build for the project to generate the **uImage** kernel image.

```
./build.sh --product-name Hi3516DV300              # Build the Hi3516D V300 image.
    --build-target build_kernel                    # Build the uImage kernel image of Hi3516D V300.
    --gn-args linux_kernel_version=\"linux-5.10\"  # Build the specified kernel version.
```
