# Fixing hb Installation Issues


## What should I do if garbled characters and segmentation faults occur during hb installation?

- **Symptom**
  Garbled characters and segmentation faults occur during the execution of the **python3 -m pip install --user ohos-build** command.

- **Possible Causes**
  pip is of an early version.

- **Solution**
  Upgrade pip.

    
  ```
  python3 -m pip install -U pip
  ```


## What should I do if the message "cannot import 'sysconfig' from 'distutils'" is displayed during hb installation?

- **Symptom**
  The message "cannot import 'sysconfig' from 'distutils'" is displayed during the execution of the **python3 -m pip install --user ohos-build** command.

- **Possible Causes**
  The **distutils** module is unavailable.

- **Solution**
  Install distutils.

    
  ```
  sudo apt-get install python3.8-distutils
  ```


## What should I do if the message "module 'platform' has no attribute 'linux_distribution'" is displayed during hb installation?

- **Symptom**
  The message "module 'platform' has no attribute 'linux_distribution'" is displayed during the execution of the **python3 -m pip install --user ohos-build** command.

- **Possible Causes**
  There is a compatibility issue of python3-pip.

- **Solution**
  Reinstall pip.

    
  ```
  sudo apt remove python3-pip
  curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
  python get-pip.py
  ```


## What should I do if the message "Could not find a version that satisfies the requirement ohos-build" is displayed during hb installation?

- **Symptom**
  The message "Could not find a version that satisfies the requirement ohos-build" is displayed during the execution of the **python3 -m pip install --user ohos-build** command.

- **Possible Causes**
  The installation fails due to poor network connectivity.

- **Solution**
  1. Ensure that your computer has a good network connection. If the network connection is unstable, rectify the network fault and reinstall hb.
  2. If the network is functional, run the following commands to install hb by specifying a temporary PyPI source:
        
      ```
      python3 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple ohos-build
      ```
