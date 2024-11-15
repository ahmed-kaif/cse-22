CC=g++

sort: random insertion merge count
convex: points graham quick

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

points: generate_points.cpp
	$(CC) $^ -o points.out
	./points.out
graham:	graham_scan.cpp
	$(CC) $^ -o graham_scan.out
	./graham_scan.out

quick: quickhull.cpp
	$$(CC) $^ -o quickhull.out
	./quickhull.out

clean:
	rm *.out
