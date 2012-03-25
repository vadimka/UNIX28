#include <unistd.h>

#define BSIZE 10

void reverse(char *buffer, int size) {
 	char *EOF = buffer + (size-1);
 	while (buffer < EOF) {
	       	*buffer ^= *EOF;
       		*EOF ^= *buffer;
        	*buffer ^= *EOF;
		buffer++;
		EOF--;
	}
}


void parser (char *buffer, int i, int count) {
	while ((i == count) && (buffer[i] != '\n')&&(i != BSIZE)) {
	count = count+read(0, buffer+count, BSIZE-count);
	}
	if (i != BSIZE) {
		if (buffer[i] == '\n') {
			reverse (buffer, i);
	        	write (1, buffer, i+1);
			memmove (buffer, buffer+i+1, count-i-1);
			count = count-i-1 + read (0, buffer+count-i-1, BSIZE-count+i+1);
			parser (buffer, 0, count);
		}
		parser (buffer, i+1, count);
	} else {
		count = read (0, buffer, BSIZE);
		i=0;
		while ((i < count) || (i==BSIZE)) {
			if (i==BSIZE) {
				parser(buffer, BSIZE, 0);
				}
			if (buffer[i] == '\n') {
				memmove(buffer, buffer+i+1, count-i-1);
				count = count-i-1 + read(0, buffer+count-i-1, BSIZE-count+i+1);
				parser (buffer, 0, count);
			}	
			i++;
		}
	}
	parser (buffer, i, count);
}

int main() {

	int count;
	char buffer[BSIZE];
	int i;
	i=0;
	count = read (0, buffer, BSIZE);
	parser (buffer, i, count);
	return 0;

}
