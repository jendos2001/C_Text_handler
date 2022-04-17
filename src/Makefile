all: cw

cw: deleteUpper.o freeMemory.o functions.o interface.o main.o pattern.o readAll.o readSent.o readText.o sameSent.o sameWords.o sortVowel.o splitSent.o splitText.o userChoiсe.o writeText.o
	gcc deleteUpper.o freeMemory.o functions.o interface.o main.o pattern.o readAll.o readSent.o readText.o sameSent.o sameWords.o sortVowel.o splitSent.o splitText.o userChoiсe.o writeText.o -o cw

deleteUpper.o: deleteUpper.c deleteUpper.h
	gcc -c deleteUpper.c

freeMemory.o: freeMemory.c freeMemory.h
	gcc -c freeMemory.c

functions.o: functions.c functions.h
	gcc -c functions.c

interface.o: interface.c interface.h
	gcc -c interface.c

main.o: main.c
	gcc -c main.c

pattern.o: pattern.c pattern.h
	gcc -c pattern.c

readAll.o: readAll.c readAll.h
	gcc -c readAll.c

readSent.o: readSent.c readSent.h
	gcc -c readSent.c

readText.o: readText.c readText.h
	gcc -c readText.c

sameSent.o: sameSent.c sameSent.h
	gcc -c sameSent.c

sameWords.o: sameWords.c sameWords.h
	gcc -c sameWords.c

sortVowel.o: sortVowel.c sortVowel.h
	gcc -c sortVowel.c

splitSent.o: splitSent.c splitSent.h
	gcc -c splitSent.c

splitText.o: splitText.c splitText.h
	gcc -c splitText.c

userChoiсe.o: userChoiсe.c userChoiсe.h
	gcc -c userChoiсe.c

writeText.o: writeText.c writeText.h
	gcc -c writeText.c

clear:
	rm *.o
	rm cw
