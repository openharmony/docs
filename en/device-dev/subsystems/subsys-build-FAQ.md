# FAQs

## Common Build Problems and Solutions

###  "usr/sbin/ninja: invalid option -- w"

- **Symptom**<br>The build fails, and "usr/sbin/ninja: invalid option -- w" is displayed.

- **Possible Causes**<br>The Ninja version in use does not support the **--w** option.

- **Solution**<br>Uninstall Ninja and GN, and [install Ninja and GN of the required version](../../device-dev/get-code/gettools-ide.md).

### "/usr/bin/ld: cannot find -lncurses"

- **Symptom**<br>The build fails, and "/usr/bin/ld: cannot find -lncurses" is displayed.

- **Possible Causes**<br>The ncurses library is not available.

- **Solution**<br>

  ```shell
  sudo apt-get install lib32ncurses5-dev
  ```

### "line 77: mcopy: command not found"

- **Symptom**<br>The build fails, and "line 77: mcopy: command not found" is displayed.

- **Possible Causes**<br>mcopy is not available.

- **Solution**<br>

  ```shell
  sudo apt-get install dosfstools mtools
  ```

### "riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory"

- **Symptom**<br>The build fails, and "riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory" is displayed.

- **Possible Causes**<br>You do not have the permission to access files in the RISC-V compiler directory.

- **Solution**<br>1. Run the following command to locate **gcc_riscv32**.

  ```shell
  which riscv32-unknown-elf-gcc
  ```

  2. Run the **chmod** command to change the permission for the directory to **755**.

### "No module named 'Crypto'"

- **Symptom**<br>The build fails, and "No module named'Crypto'" is displayed.

- **Possible Causes**<br>Crypto is not installed in Python3.

- **Solution**<br>

  1. Run the following command to query the Python version:

     ```shell
     python3 --version
     ```

  2. Ensure that Python 3.9.2 or later is installed, and then run the following command to install PyCryptodome:

     ```shell
     sudo pip3 install pycryptodome
     ```

### "xx.sh: xx unexpected operator"

- **Symptom**<br>The build fails, and " xx.sh [: xx unexpected operator" is displayed.

- **Possible Causes**<br>The build environment shell is not bash.

- **Solution**<br>

  ```shell
  sudo rm -rf /bin/sh
  sudo ln -s /bin/bash /bin/sh
  ```


### "some services are not authenticated. Listed as follow"

- **Symptom**<br>The build fails, and " some services are not authenticated. Listed as follow" is displayed.

- **Possible Causes**<br>In the .cfg file of the processes listed in the error message, **uid** is set to **root** or **system**. However, these processes are not high-privilege processes defined by the product.

- **Solution**<br>

  Modify the process .cfg file to reduce the privilege level. Do not set **uid** to **root** or **system** unless necessary.

  If a process must have the **root** or **system** privilege due to service requirements, modify the **high_privilege_process_list.json** file with the approval of the security experts. The **high_privilege_process_list.json** file is located in **vendor/***{company_name}/{product_name }***/security_config**.

  For example, the file for rk3586 is **//vendor/hihope/rk3568/security_config/high_privilege_process_list.json**.


### "Error: some services do not match with critical whitelist"

- **Symptom**<br>The build fails, and "Error: some services do not match with critical whitelist" is displayed.

- **Possible Causes**<br>In the .cfg file of the processes listed in the error message, the **critical** field is defined and enabled. However, the **critical** field is not allowed for the processes, or the **critical** setting does not match the settings in the whitelist.

- **Solution**<br>

     Remove the **critical** field or set the first bit of the **critical** field to **0** in the .cfg file of the processes. Do not enable the **critical** field unless necessary.

     For details about how to use the **critical** field, see [Service Management](subsys-boot-init-service.md). If **critical** needs to be enabled for a process due to service requirements, modify the **//vendor/{company_name}/{product_name}/security_config/critical_reboot_process_list.json** file with the approval of the security experts.

     For example, the critical_reboot process control whitelist of rk3586 is **//vendor/hihope/rk3568/security_config/critical_reboot_process_list.json**.
