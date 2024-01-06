# Hillside 48 Shaun's Keymap

In order to be able to plug the USB cable into either side, we need to flash different firmware to each side.
To flash the left side:
qmk flash -kb hillside/48 -km shaunplee -bl uf2-split-left -e CONVERT_TO=promicro_rp2040

To flash the right side:
qmk flash -kb hillside/48 -km shaunplee -bl uf2-split-right -e CONVERT_TO=promicro_rp2040

## keymap.c vs keymap_source.json
We can edit the keymap using keymap_source.json and use the online configurator. When the keymap_source.json file looks good, do:
qmk json2c keymap.json > keymap_source.c

Then copy/paste the generated part into the bottom of the keymap.c file (after the `bool caps_word_press_user(uint16_t keycode)` function.
