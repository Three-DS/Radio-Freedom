cd source
bin2s default_font.bin > default_font.s
arm-gnu-eabi-as default_font.s -o default_font.o
	echo "extern const u8" `(echo $1 | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"_end[];" > `(echo $1 | tr . _)`.h
	echo "extern const u8" `(echo $1 | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"[];" >> `(echo $1 | tr . _)`.h
	echo "extern const u32" `(echo $1 | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`_size";" >> `(echo $1 | tr . _)`.h