# Usage of Third- and Fourth-Party Libraries

## What does the following error message mean: "Stage model module... does not support including OpenHarmony npm packages or modules in FA model. OpenHarmony build tasks will not be executed, and OpenHarmony resources will not be packed."  

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

The third- and fourth-party libraries are not yet compatible with the stage model of API version 9 and cannot be used.

## Can I transfer project-level dependencies?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

For example, if project A depends on project B and project B depends on project C, can project A directly use the APIs provided by project C?

No. Project A cannot directly use the APIs provided by project C. The project packing tool NPM does not support dependency transfer. To use the APIs provided by project C, you can add the dependency of project C to project A.

## How do I obtain available third-party libraries?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

For details, see [Third-Party Components That Can Be Directly Used on OpenHarmony](https://gitee.com/openharmony-sig/third_party_app_libs).

## Which third-party libraries are related to network requests?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

The [Axios](https://gitee.com/openharmony-sig/axios) library is related to network requests.

## How do I use NPM to import third- and fourth-party libraries?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9
- Method 1:
  1. Open the **Terminal** window and run the following command to go to the **entry** directory:
     
      ```
      cd entry
      ```
  2. Run the following command to install a third-party package, for example, **dayjs**:
     
      ```
      npm install dayjs --save
      ```
  3. Add the following statement in the .js file to import the package:
     
      ```
      import dayjs from 'dayjs'; 
      ```

- Method 2:
  1. Enter the **entry** directory of the project and open the **package.json** file.
  2. Write the third-party NPM package to be installed (for example, **dayjs**) in the **package.json** file.
     
      ```
      {
        "dependencies": {
          "dayjs": "^1.10.4",
        }
      }
      ```
  3. Open the **Terminal** window and run the following command to go to the **entry** directory:
     
      ```
      cd entry
      ```
  4. Run the following command to install NPM:
     
      ```
      npm install
      ```
  5. Add the following statement in the .js file to import the package:
     
      ```
      import dayjs from 'dayjs'; 
      ```
