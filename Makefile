all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Sayi.cpp -o ./lib/Sayi.o
	g++ -c -I "./include" ./src/Basamak.cpp -o ./lib/Basamak.o
	g++ -c -I "./include" ./src/SayilarListesi.cpp -o ./lib/SayilarListesi.o
bagla:
	g++ ./lib/Sayi.o ./lib/main.o ./lib/Basamak.o ./lib/SayilarListesi.o -o ./bin/program
calistir:
	./bin/program