# Wake Word Detection



(See the [README.md](../README.md) file in the upper level 'examples' directory for more information about examples.)

This example is used to test performance of wakenet.(the word word engine of Espressif).


## How to use this example


### Hardware Required


This example can run on ESP32-Korvo or ESP32-S3-Korvo-1 board. For more information about [ESP32-Korvo Getting Started Guide](https://github.com/espressif/esp-skainet/blob/master/docs/en/hw-reference/esp32/user-guide-esp32-korvo-v1.1.md) and [ESP32-S3-Korvo-1 Getting Started Guide](https://github.com/espressif/esp-skainet/blob/master/docs/en/hw-reference/esp32s3/user-guide-korvo-1.md) for more information.

### Configure, Build and Flash


##### set-target 

```
idf.py set-target esp32s3
```

##### configure

Select the default sdkconfig according to the development board module

```
cp sdkconfig_esp32s3r8_8+4.defaults sdkconfig
```

Select the different wake word
```
idf.py menuconfig
ESP Speech Recognition -> Wake word engine    // select the version of wakenet
ESP Speech Recognition -> Wake word name      // select the wake word
```

##### build&flash

Build the project and flash it to the board, then run the monitor tool to view the output via serial port:

```
idf.py -b 2000000 flash monitor 
```

(To exit the serial monitor, type ``Ctrl-]``.)


