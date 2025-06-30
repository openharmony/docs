# Vibrator Overview


The **vibrator** module extends the vibrator service via maximizing utilization of vibrator hardware capabilities. By innovatively integrating vibration and interaction, the module takes user interaction efficiency and usability to the next level.


## Working Principles

The vibrator is a Misc device that consists of four modules: Vibrator API, Vibrator Framework, Vibrator Service, and HDF layer.

  **Figure 1** Vibrator in Misc devices

![0752d302-aeb9-481a-bb8f-e5524eb61eeb](figures/0752d302-aeb9-481a-bb8f-e5524eb61eeb.png)

- Vibrator API: provides basic vibrator APIs, including the APIs for obtaining the vibrator list, querying the vibrator by effect, and triggering and stopping vibration.

- Vibrator Framework: manages the framework layer of the vibrator and communicates with the Misc Device Service.

- Vibrator Service: manages services of vibrators.

- HDF layer: adapts to different devices.


## Constraints

When using a vibrator, you must declare the **ohos.permission.VIBRATE** permission before you can control the vibration effect.
