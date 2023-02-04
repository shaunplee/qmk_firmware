# Hillside 48 Shaun's Keymap

In order to be able to plug the USB cable into either side, we need to flash different firmware to each side.
To flash the left side:
qmk flash -kb hillside/48 -km shaunplee -bl uf2-split-left -e CONVERT_TO=promicro_rp2040

To flash the right side:
qmk flash -kb hillside/48 -km shaunplee -bl uf2-split-right -e CONVERT_TO=promicro_rp2040
