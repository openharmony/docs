# FAQs

## Common Build Problems and Solutions

###  "usr/sbin/ninja: invalid option -- w"

- **Symptom**

  The build fails, and **usr/sbin/ninja: invalid option -- w** is displayed.

- **Possible Causes**

  The Ninja version in use does not support the **--w** option.

- **Solution**

  Uninstall Ninja and GN, and [install Ninja and GN of the required version](../../device-dev/get-code/gettools-ide.md).

### "/usr/bin/ld: cannot find -lncurses"

- **Symptom**

  The build fails, and **/usr/bin/ld: cannot find -lncurses** is displayed.

- **Possible Causes**

  The ncurses library is not installed.

- **Solution**

  ```shell
  sudo apt-get install lib32ncurses5-dev
  ```

### "line 77: mcopy: command not found"

- **Symptom**

  The build fails, and **line 77: mcopy: command not found** is displayed.

- **Possible Causes**

  mcopy is not installed.

- **Solution**

  ```shell
  sudo apt-get install dosfstools mtools
  ```

### "riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory"

- **Symptom**

  The build fails, and the following information is displayed: <br>**riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory**

- **Possible Causes**

   You do not have the permission to access files in the RISC-V compiler directory.

- **Solution**

  1. Run the following command to locate **gcc_riscv32**:
  
     ```shell
     which riscv32-unknown-elf-gcc 
     ```

     
  
  2. Run the **chmod** command to change the directory permission to **755**.
  
     

### "No module named 'Crypto'"

- **Symptom**

  The build fails, and **No module named 'Crypto'** is displayed.

- **Possible Causes**

   Crypto is not installed in Python3.

- **Solution**

  1. Run the following command to query the Python version:

     ```shell
     python3 --version
     ```

  2. Ensure that Python 3.9.2 or later is installed, and then run the following command to install PyCryptodome:

     ```shell
     sudo pip3 install pycryptodome
     ```

### "xx.sh : xx unexpected operator"

- **Symptom**

  The build fails, and **xx.sh [: xx unexpected operator** is displayed.

- **Possible Causes**

  The build environment shell is not bash.

- **Solution**

  ```shell
  sudo rm -rf /bin/sh
  sudo ln -s /bin/bash /bin/sh
  ```


### "some services are not authenticated. Listed as follows"

- **Symptom**

  The build fails, and "some services are not authenticated. Listed as follows" is displayed.

- **Possible Causes**

  For the processes listed in the error information, the UID is set to **root** or **system** in the process configuration files. However, these processes are not high-privilege processes defined by the product.

- **Solution**

  Modify the process configuration file to reduce the privilege level. Do not set **UID** to **root** or **system** unless necessary.

  If a process must have the **root** or **system** privilege due to service requirements, modify the **high_privilege_process_list.json** file with the approval of security experts. The **high_privilege_process_list.json** file is located in **vendor/**{*company_name*}/{*product_name*}**/security_config**. For example, the file for rk3586 is **//vendor/hihope/rk3568/security_config/high_privilege_process_list.json**.


