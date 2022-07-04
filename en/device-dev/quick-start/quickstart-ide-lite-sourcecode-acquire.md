# Obtaining Source Code


In the Ubuntu environment, perform the following steps to obtain the OpenHarmony source code:


## Preparations

1. Register your account with Gitee.

2. Register an SSH public key for access to Gitee.

3. Install the git client and git-lfs if they are unavailable.

     Update the software source:
     
   ```
   sudo apt-get update
   ```

    Run the following command to install the tools:
   
   ```
   sudo apt-get install git git-lfs
   ```

4. Configure user information.
   
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

5. Run the following commands to install the **repo** tool:
   
   ```
   curl https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 -o /usr/local/bin/repo  # If you do not have the access permission to this directory, download the tool to any other accessible directory and configure the directory to the environment variable.
   chmod a+x /usr/local/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


## Obtaining Source Code

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> Download the master code if you want to get quick access to the latest features for your development. Download the release code, which is more stable, if you want to develop commercial functionalities.

- **Obtaining OpenHarmony master code**

    Method 1 \(recommended\): Use the **repo** tool to download the source code over SSH. \(You must have registered an SSH public key for access to Gitee.\)
    
  ```
  repo init -u git@gitee.com:openharmony/manifest.git -b master --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

  Method 2: Use the **repo** tool to download the source code over HTTPS.

  
  ```
  repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

- **Obtaining OpenHarmony release code**

  For details about how to obtain the source code of an OpenHarmony release, see the [Release-Notes](../../release-notes/Readme.md).


### Running prebuilts

Go to the root directory of the source code and run the following script to install the compiler and binary tool:

```
bash build/prebuilts_download.sh
```
