CC=g++
CC_Flags = -Wall



ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif



student_prog: student_prog.cc median.o grade.o student_info.o
	$(CC) -o $@ $^ $(CC_Flags)


%.o: %.cc
	$(CC) -c -o $@ $< $(CC_Flags)



clean:
	rm -rf *.o student_prog
