#!/bin/sh
cd tests
mkdir dir1 && cd dir1 && touch README.TXT && cd ..
mkdir dir2 && cd dir2
echo "jajaja" > TOTO.TXT && mkdir dir3 && cd ..
mkisofs  -o test.iso .
cd ..
./my_read_iso tests/test.iso <cmd
