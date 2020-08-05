# Run 'make download build' to download and build fastcoll
# Run 'make all' to complete lab3.2
# Run 'make clean' to clear .bin and fastcoll data
# Run 'make cleanall' to clear the same as 'clean' including fastcoll binary and sources.

FASTCOLL_URL=https://github.com/upbit/clone-fastcoll/archive/master.zip
FASTCOLL_DIR=clone-fastcoll-master

all:
	xxd -r -p message1.hex > message1.bin
	xxd -r -p message2.hex > message2.bin
	openssl dgst -md5 message1.bin message2.bin
	openssl dgst -sha256 message1.bin message2.bin
	time ./fastcoll message2.hex
	openssl dgst -md5 md5_data*
	openssl dgst -sha256 md5_data*

download:
	wget ${FASTCOLL_URL}
	unzip *.zip
	rm -f *.zip

build:
	cd ${FASTCOLL_DIR} && make && mv fastcoll .. && make clean && cd ..

clean:
	rm -f *.bin
	rm -f md5_data*

cleanall:
	rm -f *.bin
	rm -f md5_data*
	rm -f fastcoll
	rm -rf ${FASTCOLL_DIR}

