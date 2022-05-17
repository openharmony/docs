# Compiling and Building the Linux Kernel<a name="EN-US_TOPIC_0000001076416924"></a>

-   [Example 1](#section19369206113115)

## Example 1<a name="section19369206113115"></a>

The following uses the Hi3516D V300 board and Ubuntu x86 server as an example.

Perform a full build for the project to generate the  **uImage**  kernel image.

```
./build.sh --product-name hispark_taurus_standard              # Build the hispark_taurus_standard image.
        --build-target build_kernel                    # Build the uImage kernel image of the hispark_taurus_standard.
    --gn-args linux_kernel_version=\"linux-5.10\" # Build the specified kernel version.
```

