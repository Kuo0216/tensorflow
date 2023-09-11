all:
	/usr/bin/g++ -std=c++20 -stdlib=libc++ -g main.cpp dataentry.cpp dataentryeq.cpp datacheck.cpp wat.cpp inlinetr.cpp runsheet.cpp eqlot.cpp defect.cpp -o test
	./test
