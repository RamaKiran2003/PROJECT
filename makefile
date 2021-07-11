all : EXAM_RESULT_SYSTEM

EXAM_RESULT_SYSTEM : result.cpp Database.cpp Database.h Student.cpp Student.h  Marks.h Marks.cpp
	g++ -o project result.cpp Database.cpp Marks.cpp Student.cpp

clean : 
	rm -f project

