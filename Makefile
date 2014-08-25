CC = g++ 
CFLAGS := -g -Wall 

%: %.cpp
	$(CC) $(CFLAGS) -o $@ $^

