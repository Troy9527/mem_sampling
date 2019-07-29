if [ -z $1]
then
	echo "Usage: ./trace.sh [number of threads]"
else
	rm -f *.data*
	./workload.out $1 &
	sudo perf mem record --phys-data --freq=max -a --pid `ps aux | grep "./workload.out" | sed -e '$ d' | awk '{print $2}'`
	#sudo kill -2 `ps aux | grep "sudo perf mem record --phys-data -a -o mem_trace.data" | sed -e '$ d' | sed -e '$ d' | awk '{print $2}'`
	#sudo kill -2 `ps aux | grep "sudo perf mem record --phys-data*" | sed -e '$ d' | awk '{print $2}'`
fi
