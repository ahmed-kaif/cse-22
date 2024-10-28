CC=g++

all: random insertion merge count

random: random_number.cpp
	$(CC) random_number.cpp -o random.out
	./random.out

insertion: insertion_sort.cpp
	$(CC) insertion_sort.cpp -o insertion.out
	./insertion.out

merge: merge_sort.cpp
	$(CC) merge_sort.cpp -o merge.out
	./merge.out

count: counting_sort.cpp
	$(CC) counting_sort.cpp -o counting.out
	./counting.out
hi: hybrid_sort.cpp
	$(CC) $^ -o hi.out
	./hi.out
hb: bubble.cpp
	$(CC) $^ -o hb.out
	./hb.out

clean:
	rm *.out
