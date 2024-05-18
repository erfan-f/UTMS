utms: main.o SystemController.o user.o student.o professor.o  major.o unit.o CommandOperator.o exception.o method.o post.o
	g++ -std=c++20 main.o SystemController.o user.o student.o professor.o  major.o unit.o CommandOperator.o exception.o method.o post.o -o utms.out

main.o: main.cpp
	g++ -std=c++20 -c main.cpp

SystemController.o: SystemController.cpp
	g++ -std=c++20 -c SystemController.cpp

user.o: user.cpp
	g++ -std=c++20 -c user.cpp	

student.o: student.cpp
	g++ -std=c++20 -c student.cpp	

professor.o: professor.cpp
	g++ -std=c++20 -c professor.cpp

major.o: major.cpp
	g++ -std=c++20 -c major.cpp

unit.o: unit.cpp
	g++ -std=c++20 -c unit.cpp

CommandOperator.o: CommandOperator.cpp
	g++ -std=c++20 -c CommandOperator.cpp

exception.o: exception.cpp
	g++ -std=c++20 -c exception.cpp


method.o: method.cpp
	g++ -std=c++20 -c method.cpp

post.o: post.cpp
	g++ -std=c++20 -c post.cpp

clean:
	rm *.o utms.out
