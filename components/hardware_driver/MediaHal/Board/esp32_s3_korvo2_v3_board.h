/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _AUDIO_S3_KORVO2_V3_BOARD_H_
#define _AUDIO_S3_KORVO2_V3_BOARD_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Board functions related */
#define BOARD_INFO                  "ESP32_S3_korvo2-v3"

#define USE_CODEC                   1
#define USE_ADC                     1
#define CONFIG_CODEC_CHIP_IS_ES8311
#define CONFIG_ADC_CHIP_IS_ES7210
#define USE_I2S_0                   0
#define USE_I2S_1                   1
#define GPIO_INPUT_IO_MUTE          1
#define ESP_INTR_FLAG_DEFAULT       0
/* I2C gpios */
#define IIC_CLK                     18
#define IIC_DATA                    17

/* PA */
#define GPIO_PA_EN                  48

/* I2S1 gpios */
#define IIS1_MCLK                   16
#define IIS1_SCLK                   9
#define IIS1_LCLK                   45
#define IIS1_DSIN                   8
#define IIS1_DOUT                   10

#define I2S1_CONFIG(){ \
        .mode = I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_TX, \
        .sample_rate = 16000, \
        .communication_format = I2S_COMM_FORMAT_STAND_I2S, \
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT, \
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT, \
        .dma_buf_count = 6, \
        .dma_buf_len = 160, \
        .use_apll = false, \
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1 \
};

#define I2S1_PIN(){ \
    .bck_io_num = IIS1_SCLK, \
    .ws_io_num = IIS1_LCLK, \
    .data_out_num = IIS1_DSIN, \
    .data_in_num = IIS1_DOUT, \
};

#define I2C_CONFIG(){ \
    .i2c_port_num = I2C_NUM_0, \
    .i2c_cfg = { \
        .mode = I2C_MODE_MASTER, \
        .sda_io_num = IIC_DATA, \
        .scl_io_num = IIC_CLK, \
        .sda_pullup_en = GPIO_PULLUP_ENABLE,\
        .scl_pullup_en = GPIO_PULLUP_ENABLE,\
        .master.clk_speed = 100000 \
    }, \
};

#ifdef __cplusplus
}
#endif

#endif
