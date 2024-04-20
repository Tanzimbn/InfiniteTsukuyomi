// file name as “s.sh’
// run: bash s.sh
set -e
g++ -std=c++17 -O2 -Wshadow -Wall -Wextra -Wshift-overflow=2 -fno-sanitize-recover -fstack-protector -o "%e" -g -D_GLIBCXX_DEBUG a.cpp -o a
g++ -std=c++17 test.cpp -o test
g++ -std=c++17 brute.cpp -o brute
for((i = 1; i < 1000; ++i)); do
	./test $i > input_file
	./a < input_file > myAnswer
	./brute < input_file > correctAnswer
	diff -Z myAnswer correctAnswer > /dev/null || break
	echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
echo "finished"
With checker:
set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ brute.cpp -o brute
g++ checker.cpp -o checker
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    ./checker > checker_log
    echo "Passed test: "  $i
done

Checker.cpp must include
//ifstream fin("input_file", ifstream::in);
//ifstream ans("myAnswer", ifstream::in);
// ifstream cor("correctAnswer", ifstream::in);
