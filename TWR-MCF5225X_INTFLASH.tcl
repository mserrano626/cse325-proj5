fl::target -lc "proj5ms_TWR-MCF5225X_Internal_Flash_PnE U-MultiLink"
fl::target -b 0x20000000 0xffff
fl::target -v off -l off
cmdwin::fl::device -d "CFM_MCF5225X_512" -o "256Kx16x1" -a 0x0 0x7ffff
cmdwin::fl::image -f "T:\\CodeWarrior\\proj5ms\\TWR-MCF5225X_Internal_Flash\\proj5ms.elf" -t "Auto Detect" -re off -oe off
cmdwin::fl::erase image
cmdwin::fl::write
cmdwin::fl::verify
cmdwin::fl::disconnect
