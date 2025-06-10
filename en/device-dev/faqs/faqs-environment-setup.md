# Environment Setup


## Mini and Small Systems

### hb Installation

#### Garbled Characters and segmentation Faults

- **Symptom**

  Garbled characters and segmentation faults occur during the execution of the **python3 -m pip install --user ohos-build** command.


- **Possible Causes**

  The pip version does not meet requirements. 

- **Solution**

  Run the following command to upgrade pip:

  ```
  python3 -m pip install -U pip
  ```


#### cannot import 'sysconfig' from 'distutils'

- **Symptom**

  During the execution of **python3 -m pip install --user ohos-build**, the following information is displayed:<br>cannot import 'sysconfig' from 'distutils'


- **Possible Causes**

  The **distutils** module is unavailable.

- **Solution**

  Install **distutils**.

  ```
  sudo apt-get install python3.8-distutils
  ```


#### module 'platform' has no attribute 'linux\_distribution'

- **Symptom**

  During the execution of **python3 -m pip install --user ohos-build**, the following information is displayed:<br>module 'platform' has no attribute 'linux\_distribution'


- **Possible Causes**

  There is a compatibility issue of python3-pip.

- **Solution**

  Reinstall pip.

  ```
  sudo apt remove python3-pip
  curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
  python get-pip.py
  ```


#### Could not find a version that satisfies the requirement ohos-build

- **Symptom**

  During the execution of **python3 -m pip install --user ohos-build**, the following information is displayed:<br>Could not find a version that satisfies the requirement ohos-build


- **Possible Causes**

  The installation fails due to poor network connectivity.

- **Solution**
  1. Ensure that your computer has a good network connection. If the network connection is unstable, rectify the network fault and reinstall hb.
  2. If the network is functional, run the following commands to install hb by specifying a temporary PyPI source:

     ```
     python3 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple ohos-build
     ```

### Python3 Installation

#### configure: error: no acceptable C compiler found in $PATH

- **Symptom**

  The following error occurs during Python 3 installation:

  ```
  configure: error: no acceptable C compiler found in $PATH. See 'config.log' for more details
  ```

- **Possible Causes**

  GCC is not installed.

- **Solution**

  1. Run the **apt-get install gcc** command to install GCC online.

  2. Install Python 3.


#### -bash: make: command not found

- **Symptom**

  The following error occurs during Python 3 installation:

  ```
  -bash: make: command not found
  ```

- **Possible Causes**

  make is not installed.

- **Solution**

  1. Run the **apt-get install make** command to install make online.

  2. Install Python 3.


#### zlib Not Available

- **Symptom**

  The following error occurs during Python 3 installation:

  ```
  zipimport.ZipImportError: can't decompress data; zlib not available
  ```

- **Possible Causes**

  **zlib** is not installed.

- **Solution**

  Method 1: Run the **apt-get install zlib** command to install zlib online.

  Method 2: If the software source does not contain zlib, download zlib from http://www.zlib.net/.

  ![](figures/download-zlib.png)

  Run the following command to install zlib:

  ```
  # tar xvf zlib-1.2.11.tar.gz
  # cd zlib-1.2.11
  # ./configure
  # make && make install
  ```

  Install Python 3.


#### No module named'\_ctypes'

- **Symptom**

  The following error occurs during Python 3 installation:

  ```
  ModuleNotFoundError: No module named '_ctypes'
  ```


- **Possible Causes**

  libffi and libffi-devel are not installed.


- **Solution**

  1. Run the **apt-get install libffi* -y** command to install libffi and libffi-devel online.

  2. Install Python 3.


### lsb_release Error Occurred During kconfiglib Installation

- **Symptom**

  The following information is displayed during the **kconfiglib** installation process:

  ```
  subprocess.CalledProcessError: Command '('lsb_release', '-a')' returned non-zero exit status 1.
  ```

- **Possible Causes**

  The Python version in use does not match the Python version on which the lsb_release module depends.

- **Solution**

  Run **find / -name lsb_release** to locate lsb_release and delete it, for example, **sudo rm -rf /usr/bin/lsb_release**.


### ImportError: No module named apt\_pkg

- **Symptom**

  The message "ImportError: No module named apt\_pkg" is displayed when an unidentifiable command is executed on the Linux server.


- **Possible Causes**

  There is a compatibility issue of python3-apt.

- **Solution**

  Reinstall python3-apt.

  ```
  sudo apt-get remove  python3-apt
  sudo apt-get install python3-apt
  ```

### Updating Source Code
- **Scenario**

  Update the OpenHarmony source code downloaded to the branch (for example, Master) source code.

- **Solution**

  1. Go to the OpenHarmony root directory.
   
     Check that the root directory has a **.repo** folder, which is usually hidden. If the **.repo** folder does not exist, decompress the obtained source code package again to obtain complete source code.
   
  2. Run the **repo init** command to initialize the source code repository information.

     In the command, *branch* indicates the branch name, for example, **master** or **OpenHarmony-3.2-Beta3**.
     ```shell
     repo init -u https://gitee.com/openharmony/manifest -b branch --no-repo-verify
     ```
 
  3. Download and update the source code file.

     ```shell
     repo sync -c
     repo forall -c 'pwd;git lfs pull'
     ```
     To keep the working directory clean, run the following command:
   
     >![icon-note.gif](public_sys-resources/icon-caution.gif) **CAUTION**<br>
     >This command will reset the local workspace and delete files or directories that are not managed by gitee. Exercise caution when performing this operation.
     ```shell
     repo forall -c 'git reset --hard;git clean -fdx'
     ```

  4. Run the prebuilts script to install the compiler and binary tool.

     ```shell
     bash build/prebuilts_download.sh
     ```
   
   
