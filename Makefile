
imggen:imggen.c
clean:
	find -name 'imggen' -exec rm {} \;
install:
	cp 'imggen' /usr/bin
	chmod +x /usr/bin/imggen
