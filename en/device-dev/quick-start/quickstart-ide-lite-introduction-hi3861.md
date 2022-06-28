# Introduction to the Hi3861 Development Board


## Introduction

Hi3861 is a 2 x 5 cm development board. It is a 2.4 GHz WLAN SoC chip that highly integrates the IEEE 802.11b/g/n baseband and radio frequency (RF) circuit. It supports OpenHarmony and provides an open and easy-to-use development and debugging environment.

**Figure 1** Hi3861 development board

![en-us_image_0000001226634692](figures/en-us_image_0000001226634692.png)

The Hi3861 development board can also be connected to the Hi3861 mother board to expand its peripheral capabilities. The following figure shows the Hi3861 mother board.

**Figure 2** Hi3861 mother board

![en-us_image_0000001226794660](figures/en-us_image_0000001226794660.png)

- The RF circuit includes modules such as the power amplifier (PA), low noise amplifier (LNA), RF Balun, antenna switch, and power management. It supports a standard bandwidth of 20 MHz and a narrow bandwidth of 5 MHz or 10 MHz, and provides a maximum rate of 72.2 Mbit/s at the physical layer.

- The Hi3861 WLAN baseband supports the orthogonal frequency division multiplexing (OFDM) technology and is backward compatible with the direct sequence spread spectrum (DSSS) and complementary code keying (CCK) technologies. In addition, the Hi3861 WLAN baseband supports various data rates specified in the IEEE 802.11 b/g/n protocol.

- The Hi3861 chip integrates the high-performance 32-bit microprocessor, hardware security engine, and various peripheral interfaces. The peripheral interfaces include the Synchronous Peripheral Interface (SPI), Universal Asynchronous Receiver & Transmitter (UART), the Inter-Integrated Circuit (I2C), Pulse Width Modulation (PWM), General Purpose Input/Output (GPIO) interface, and Analog to Digital Converter (ADC). The Hi3861 chip also supports the high-speed Secure Digital Input/Output (SDIO) 2.0 interface, with a maximum clock frequency of 50 MHz. This chip has a built-in static random access memory (SRAM) and flash memory, so that programs can run independently or run from a flash drive.

- The Hi3861 chip applies to Internet of Things (IoT) devices such as smart home appliances.

    **Figure 3** Functional block diagram of Hi3861
    
  ![en-us_image_0000001271234729](figures/en-us_image_0000001271234729.png)


## Resources and Constraints

The resources of the Hi3861 development board are limited. The entire board has a 2 MB flash memory and 352 KB RAM. When writing service code, pay attention to the resource usage efficiency.


## Development Board Specifications

**Table 1** Hi3861 specifications

| Item| Description|
| -------- | -------- |
| General specifications| -&nbsp;1 x 1 2.4 GHz frequency band (ch1–ch14)<br>-&nbsp;PHY supports IEEE 802.11b/g/n.<br>-&nbsp;MAC supports IEEE802.11d/e/h/i/k/v/w.<br>-&nbsp;Built-in PA and LNA; integrated TX/RX switch and Balun<br>-&nbsp;Support for STA and AP modes. When functioning as an AP, it supports a maximum of 6 STAs.<br>-&nbsp;Support for WFA WPA/WPA2 personal and WPS2.0.<br>-&nbsp;2/3/4-line PTA solution that coexists with BT/BLE chips.<br>-&nbsp;Input voltage range: 2.3 V to 3.6 V<br>-&nbsp;I/O power voltage: 1.8 V or 3.3 V.<br>-&nbsp;RF self-calibration<br>-&nbsp;Low power consumption:<br>&nbsp;&nbsp;-&nbsp;Ultra Deep Sleep mode: 5 μA@3.3 V<br>&nbsp;&nbsp;-&nbsp;DTIM1: 1.5 mA \@3.3V<br>&nbsp;&nbsp;-&nbsp;DTIM3: 0.8 mA \@3.3V|
| PHY features| -&nbsp;Supports all data rates of the IEEE802.11b/g/n single antenna.<br>-&nbsp;Supported maximum rate: 72.2 Mbps\@HT20&nbsp;MCS7<br>-&nbsp;20 MHz standard bandwidth and 5 MHz/10 MHz narrow bandwidth.<br>-&nbsp; STBC.<br>-&nbsp;Short-GI.|
| MAC features| -&nbsp;A-MPDU and A-MSDU.<br>-&nbsp;Blk-ACK.<br>-&nbsp;QoS to meet the quality requirements of different services.|
| CPU subsystem| - &nbsp;High-performance 32-bit microprocessor with a maximum working frequency of 160 MHz.<br>-&nbsp;Embedded SRAM of 352 KB; ROM of 288 KB<br>-&nbsp;Embedded 2 MB flash memory|
| Peripheral ports| -&nbsp;One SDIO interface, two SPI interfaces, two I2C interfaces, three UART interfaces, 15 GPIO interfaces, seven ADC inputs, six PWM interfaces, and one I2S interface (Note: These interfaces are all multiplexed.)<br>-&nbsp;Frequency of the external main crystal: 40 MHz or 24 MHz|
| Others| -&nbsp;Package: QFN-32, 5 mm x 5 mm<br>-&nbsp;Working temperature: -40°C to +85°C|


## OpenHarmony Key Features

OpenHarmony provides a wide array of available capabilities based on the Hi3861 platform. The following table describes the available key components.

**Table 2** Key components of OpenHarmony

| Component| Capability|
| -------- | -------- |
| WLAN| Provides the WLAN service capability. For example, connecting to or disconnecting from a station or hotspot, and querying the status of a station or hotspot.|
| IoT controller| Provides the capability of operating peripherals, including the I2C, I2S, ADC, UART, SPI, SDIO, GPIO, PWM and flash memory.|
| DSoftBus| Provides the capabilities of device discovery and data transmission in the distributed network.|
| hichainsdk| Provides the capability of securely transferring data between devices when they are interconnected.|
| huks| Provides capabilities of key management, encryption, and decryption.|
| System service management| Provides a unified OpenHarmony service development framework based on the service-oriented architecture.|
| Boot| Provides the entry identifier for starting a system service. When the system service management is started, the function identified by bootstrap is called to start a system service.|
| System attribute| Provides capabilities of obtaining and setting system attributes.|
| Base library| Provides the common basic library capability, including file operations and KV storage management.|
| DFX | Provides the DFX capability, such as logging and printing.|
| XTS | Provides a set of OpenHarmony certification test suites.|
