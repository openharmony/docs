# Unpacking Tool


The unpacking tool is a commissioning tool provided by OpenHarmony. It can split a HAP file into folders or split an App Pack into HAP files in command line mode.


The **app_unpacking_tool.jar** package can be found in the OpenHarmony SDK downloaded locally.


- Unpacking a HAP File
  
  ```bash
  java -jar app_unpacking_tool.jar --mode <option> --hap-path <option>  --out-path <option> --force <option>
  ```

  The table below describes the command parameters.

  | Name| Mandatory| Description|
  | -------- | -------- | -------- |
  | --mode | Yes| Unpacking mode. In this scenario, set this parameter to **hap**.|
  | --hap-path | Yes| Path of the HAP file.|
  | --rpcid | No| Whether to extract the rpcid file from the HAP file to a specified directory. If the value is **true**, only the rpcid file is extracted and the HAP file is not unpacked.|
  | --out-path | Yes| Path of the target file.|
  | --force | No| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking.|

- Unpacking an App Pack
  
  ```bash
  java -jar app_unpacking_tool.jar --mode <option> --app-path <option>  --out-path <option> --force <option>
  ```

  The table below describes the command parameters.

  | Name| Mandatory| Description|
  | -------- | -------- | -------- |
  | --mode | Yes| Unpacking mode. In this scenario, set this parameter to **hap**.|
  | --app-path | Yes| Path of the App Pack.|
  | --out-path | Yes| Path of the target file.|
  | --force | No| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking.|

- Extracting the rpcid File from a HAP file
  
  ```bash
  java -jar app_unpacking_tool.jar --mode <option> --rpcid <option>  --hap-path <option> --out-path <option> --force <option>
  ```

  The table below describes the command parameters.

  | Name| Mandatory| Description|
  | -------- | -------- | -------- |
  | --mode | Yes| Unpacking mode. In this scenario, set this parameter to **hap**.|
  | --rpcid | No| Whether to extract the rpcid file from the HAP file to a specified directory. If the value is **true**, only the rpcid file is extracted and the HAP file is not unpacked.|
  | --out-path | Yes| Path of the target file.|
  | --hap-path | Yes| Path of the HAP file.|
