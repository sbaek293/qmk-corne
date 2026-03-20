# MCU and bootloader
MCU = RP2040
BOOTLOADER = rp2040

# Build options
BOOTMAGIC_ENABLE    = yes
MOUSEKEY_ENABLE     = yes
EXTRAKEY_ENABLE     = yes
CONSOLE_ENABLE      = no
COMMAND_ENABLE      = no
NKRO_ENABLE         = yes
BACKLIGHT_ENABLE    = no
RGBLIGHT_ENABLE     = no
AUDIO_ENABLE        = no
QMK_SETTINGS        = yes
COMBO_ENABLE        = yes
KEY_OVERRIDE_ENABLE = yes
AUTO_SHIFT_ENABLE   = yes

# Split keyboard
SPLIT_KEYBOARD      = yes
SERIAL_DRIVER       = vendor

# RGB Matrix
RGB_MATRIX_ENABLE   = yes
RGB_MATRIX_DRIVER   = WS2812
WS2812_DRIVER       = vendor

# OLED
OLED_ENABLE         = yes
OLED_DRIVER         = SSD1306
WPM_ENABLE          = yes

# LTO
LTO_ENABLE          = yes

LAYOUTS = split_3x6_3
