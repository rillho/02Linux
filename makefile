COMPILATION = -g


all: 00client 00server 01multi_process


00client: 00client.cpp __hy__.cpp
	g++ $(COMPILATION) -o 00client 00client.cpp __hy__.cpp -lm

00server: 00server.cpp __hy__.cpp
	g++ $(COMPILATION) -o 00server 00server.cpp __hy__.cpp -lm

01multi_process: 01multi_process.cpp __hy__.cpp
	g++ $(COMPILATION) -o 01multi_process 01multi_process.cpp __hy__.cpp -lm


clean:
	rm -rf 00client 00server 01multi_process