CFLAGS=src/* -o substitution -g

all:
	g++ ${CFLAGS}

test:
	./substitution sub_ciphertext.txt sub_key.txt

clean:
	rm -f substitution
