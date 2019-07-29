all:
	gcc mem_workload.c -o workload.out -lpthread
clean:
	-rm -f *.out
	-rm -f vgcore*
	-rm -f *.data
