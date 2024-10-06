// file name as “s.sh’
// run: bash s.sh
#set -e
#g++ -std=c++17 -O2 -Wshadow -Wall -Wextra -Wshift-overflow=2 -fno-sanitize-recover -fstack-protector -o "%e" -g -D_GLIBCXX_DEBUG a.cpp -o a
#g++ -std=c++17 test.cpp -o test
#g++ -std=c++17 brute.cpp -o brute
ok=1
for((i = 1; i < 100; ++i)); do
    ./gen $i > input_file
    ./a < input_file > myAnswer
    ./brute < input_file > correctAnswer
    if ! diff -Z myAnswer correctAnswer > /dev/null; then
        ok=0
        break
    fi
    echo "Passed test: "  $i
done
if [ $ok -eq 0 ]; then
	echo "WA on the following test:"
	cat input_file
	echo "Your answer is:"
	cat myAnswer
	echo "Correct answer is:"
	cat correctAnswer
fi
echo "finished"

Checker.cpp must include
//ifstream fin("input_file", ifstream::in);
//ifstream ans("myAnswer", ifstream::in);
// ifstream cor("correctAnswer", ifstream::in);
