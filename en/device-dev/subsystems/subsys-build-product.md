# Product
### Configuration Rules

The product solution is a special component. It is a product built based on a development board. It includes the OS adaptation, component assembly and configuration, startup configuration, and file system configuration. The source code path of a product solution is in the **vendor/{Product_solution_vendor}/{Product_name}** format.

The product solution directory structure is as follows:

```shell
vendor                              
└── company                         # Product solution vendor
    ├── product                     # Product name
    │   ├── init_configs
    │   │     ├── etc               # Startup configuration of the init process (only required for the Linux kernel)
    │   │     └── init.cfg          # System service startup configuration
    │   ├── hals                    # OS adaptation
    │   ├── BUILD.gn                # Product build script
    │   └── config.json             # Product configuration file
    │   └── fs.yml                  # File system packaging configuration
    └── ......
```

> **NOTE**<br>Directories and files must be created for new products based on the preceding rules. The Compilation and Building subsystem scans the configured products based on the rules.

The key directories and files are described as follows:

1. **vendor/company/product/init_configs/etc**<br>This folder contains the rcS, Sxxx, and fstab scripts. The init process runs the rcS, fstab, and S00xxx scripts in sequence before starting system services. The Sxxx script is used to create device nodes and directories, scan device nodes, and change file permissions for the development board and product. These scripts are copied from the **BUILD.gn** file to the **out** directory of the product as required and packaged into the **rootfs** image.

2. **vendor/company/product/init_configs/init.cfg**<br>**init.cfg** defines how the init process starts services. Currently, the following commands can be parsed:

   - **start**: starts a service.

   - **mkdir**: creates a folder.

   - **chmod**: changes the permission on a specified directory or file.

   - **chown**: changes the owner group of a specified directory or file.

   - **mount**: mounts a device.

     The fields in the file are described as follows:

   ```shell
   {
       "jobs" : [{                                                     # An array of jobs. A job corresponds to a command set. Jobs are executed in the following sequence: pre-init > init > post-init.
               "name" : "pre-init",
               "cmds" : [
                   "mkdir /storage/data",                              # Create a directory.
                   "chmod 0755 /storage/data",                         # Modify the permissions. The format of the permission value is 0xxx, for example, 0755.
                   "mkdir /storage/data/log",
                   "chmod 0755 /storage/data/log",
                   "chown 4 4 /storage/data/log",                     # Change the owner group. The first number is the user ID (UID), and the second number is the group ID (GID).
                   ......
                   "mount vfat /dev/mmcblock0 /sdcard rw,umask=000"    # The command format is mount [File system type] [source] [target] [flags] [data].
                                                                       # The value of flags can be nodev, noexec, nosuid, or rdonly.
               ]
           }, {
               "name" : "init",
               "cmds" : [                                              # Start services based on the sequence in the cmds array.
                   "start shell",                                      # There is only one space between start and the service name.
                   ......
                   "start service1"
               ]
           }, {
               "name" : "post-init",                                   # Job that is finally executed. Operations performed after the init process is started, for example, mounting a device after the driver initialization).
               "cmds" : []
           }
       ],
       "services" : [{                                                 # An array of services. A service corresponds to a process.
               "name" : "shell",                                       # Service name.
               "path" : ["/sbin/getty", "-n", "-l", "/bin/sh", "-L", "115200", "ttyS000", "vt100"],    # Full path of the executable file. It must start with "path".
               "uid" : 0,                                              # Process UID, which must be the same as that in the binary file.
               "gid" : 0,                                              # Process GID, which must be the same as that in the binary file.
               "once" : 0,                                             # Whether the process is a one-off process. The value 1 indicates a one-off process, and the value 0 indicates the opposite. The init process does not restart the one-off process after the process exits.
               "importance" : 0,                                       # Whether the process is a key process. The value 1 indicates a key process, and the value 0 indicates the opposite. If a key process exits, the init process will restart the board.
               "caps" : [4294967295]
           }, 
           ......
       ]
   }
   ```

3. **vendor/company/product/init_configs/hals**<br>This folder contains the OS adaptation of the product. For details about the interfaces to be implemented, see readme of each component.

4. **vendor/company/product/config.json**<br>The **config.json** file is the main entry for compilation and build. It contains the configuration of the development board, OS components, and kernel.

   The following example shows the **config.json** file of the IP camera developed based on the hispark_taurus board:

   ```shell
   {
        "product_name": "ipcamera",                       # Product name
        "version": "3.0",                                 # Version of config.json. The value must be 3.0.
        "type": "small",                                  # System type. The value can be mini, small, or standard.
        "ohos_version": "OpenHarmony 1.0",                # OS version
        "device_company": "hisilicon",                    # Chipset vendor
        "board": "hispark_taurus",                        # Name of the development board
        "kernel_type": "liteos_a",                        # Kernel type
        "kernel_version": "3.0.0",                        # Kernel version
        "subsystems": [                            
          {
            "subsystem": "aafwk",                         # Subsystem
            "components": [
              { "component": "ability", "features":[ "ability_lite_enable_ohos_appexecfwk_feature_ability = true" ] }   # Selected component and feature configuration
            ]
          },
          {
           ......
          }
         ......
         More subsystems and components
        }
    }
   ```

5. **vendor/company/product/fs.yml**<br>The **fs.yml** file defines the process for creating a file system image, for example, **rootfs.img** (user-space root file system) and **userfs.img** (readable and writable file). It consists of multiple lists, and each list corresponds to a file system. The fields are described as follows:

   ```shell
   fs_dir_name: (mandatory) specifies the name of the file system, for example, rootfs or userfs.
   fs_dirs:     (optional) specifies the mapping between the file directory in the out directory and the system file directory. Each file directory corresponds to a list.
   source_dir:  (optional) specifies the target file directory in the out directory. If this field is not specified, an empty directory will be created in the file system based on target_dir.
   target_dir:  (mandatory) specifies the file directory in the file system.
   ignore_files: (optional) declares ignored files during the copy operation.
   dir_mode: (optional) specifies the file directory permissions. The default value is 755.
   file_mode: (optional) specifies the permissions of all files in the directory. The default value is 555.
   fs_filemode: (optional) specifies the files that require special permissions. Each file corresponds to a list.
   file_dir: (mandatory) specifies the detailed file path in the file system.
   file_mode:   (mandatory) declares file permissions.
   fs_symlink:  (optional) specifies the soft link of the file system.
   fs_make_cmd: (mandatory) creates the file system script. The script provided by the OS is located in the build/lite/make_rootfs directory. Linux, LiteOS, ext4, jffs2, and vfat are supported. Chipset vendors can also customize the script as required.  
   fs_attr:     (optional) dynamically adjusts the file system based on configuration items.
   ```

   The **fs_symlink** and **fs_make_cmd** fields support the following variables:

   - Code root directory, which corresponds to **{ohos_root_path}** of GN.
   - **out** directory of the product, which corresponds to **{root_out_dir}** of GN.
   - File system directory **${fs_dir}**, which consists of variables **${root_path}** and **${fs_dir_name}**.

>  **NOTE**<br>**fs.yml** is optional. You do not need to configure it for devices without a file system.

6. **vendor/company/product/BUILD.gn**<br>**BUILD.gn** provides the entry for product build. It is used to compile the source code of the solution vendor and copy the startup configuration file. The **BUILD.gn** file in the corresponding product directory will be built by default if a product is selected. The following is an example of the **BUILD.gn** file of a product:

   ```shell
   group("product") {               # The name must be the same as the product name (level-3 directory name under the product directory).
     deps = []
     deps += [ "init_configs" ]     # Copy init configuration.
     ...                            # Others
   }
   ```

### Adding and Building a Product

You can customize a product solution by assembling any chipset solution and components. The procedure is as follows:

1. Create a directory for the product. <br>The following uses the Wi-Fi IoT module on the RTL8720 development board as an example. <br>Run the following command in the root directory of the code:

   ```shell
   mkdir -p vendor/my_company/wifiiot
   ```

2. Configure the product. <br>Create a **config.json** file for the product (for example, wifiiot) in the product directory. <br>The **vendor/my_company/wifiiot/config.json** file is as follows:

   ```shell
   {
       "product_name": "wifiiot",                        # Product name
       "version": "3.0",                                 # Version of config.json. The value must be 3.0.
       "type": "small",                                  # System type. The value can be mini, small, or standard.
       "ohos_version": "OpenHarmony 1.0",                # OS version
       "device_company": "realtek",                      # Name of the chipset solution vendor
       "board": "rtl8720",                               # Name of the development board
       "kernel_type": "liteos_m",                        # Kernel type
       "kernel_version": "3.0.0",                        # Kernel version
       "subsystems": [                            
         {
           "subsystem": "kernel",                        # Subsystem
           "components": [
             { "component": "liteos_m", "features":[] }  # Component and its features
           ]
         },
         ...
         {
            More subsystems and components
         }
       ]
   }
   ```

   >**NOTE**<br>Before the build, the Compilation and Building subsystem checks the validity of the fields in **config.json**. The **device_company**, **board**, **kernel_type**, and **kernel_version** fields must match the chipset solution, and the **subsystem** and **component** fields must match the component description in **build/lite/components**.

3. Implement OS adaptation APIs. Create the **hals** directory in the product directory and save the source code as well as the build script for OS adaptation in the **hals** directory.

4. Create the **init_configs** directory in the product directory and then the **init.cfg** file in the **init_configs** directory, and configure the system services to be started.

5. (Optional) Configure the init process for the Linux kernel. Create the **etc** directory in the **init_configs** directory, and then create the **init.d** folder and the **fstab** file in the **etc** directory. Then, create the **rcS** and **S***xxx* files in the **init.d** file and edit them based on product requirements.

6. (Optional) Configure the file system image for the development board that supports the file system.<br> Create the **fs.yml** file in the product directory, and configure it as required. A typical **fs.yml** file is as follows:

   ```shell
   -
     fs_dir_name: rootfs # Image name
     fs_dirs:
       -
         # Copy the files in the out/my_board/my_product/bin directory to the rootfs/bin directory and ignore the .bin files related to testing.
         source_dir: bin
         target_dir: bin
         ignore_files:
           - Test.bin
           - TestSuite.bin
       -
         # Copy the files in the out/my_board/my_product/libs directory to the rootfs/lib directory, ignore all .a files, and set the file permissions to 644 and folder permissions to 755.
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
         # Create an empty proc directory.
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
         # Create the soft link ld-musl-arm.so.1 -> libc.so in the rootfs/lib directory.
         source: libc.so
         link_name: ${fs_dir}/lib/ld-musl-arm.so.1
       -
         source: mksh
         link_name: ${fs_dir}/bin/sh
       -
         source: mksh
         link_name: ${fs_dir}/bin/shell
     fs_make_cmd:
       # Run the script to create an ext4 image from rootfs.
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

7. (Optional) Configure patches if the product and components need to be patched.<br>Create a **patch.yml** file in the product directory. A typical **patch.yml** file is as follows:

   ```shell
     # Directory in which the patch is to be installed
   foundation/communication/dsoftbus:
     # Directory in which the patch is stored
     - foundation/communication/dsoftbus/1.patch
     - foundation/communication/dsoftbus/2.patch
   third_party/wpa_supplicant:
     - third_party/wpa_supplicant/1.patch
     - third_party/wpa_supplicant/2.patch
     - third_party/wpa_supplicant/3.patch
   ...
   ```

   Add **--patch** when running the **hb build** command. Then, the patch files can be added to the specified directory before the build.

   ```shell
   hb build -f --patch
   ```

8. Write the build script. <br>Create a **BUILD.gn** file in the product directory and write the script. The following **BUILD.gn** file uses the Wi-Fi IoT module in Step 1 as an example:

   ```shell
   group("wifiiot") {             # The target name must be the same as the product name.
     deps = []
     deps += [ "init_configs" ]   # Copy init configuration.
     deps += [ "hals" ]           # Add hals.
     ...                          # Others
   }
   ```

9. Build the product.<br> You can start the build by using the [CLI or hb tool](subsys-build-all.md#build-commands). The following uses the CLI as an example. For example, the product name is **hispark_taurus_standard**. Run the following command:

   ```
   ./build.sh --product-name hispark_taurus_standard --ccache
   ```

   
