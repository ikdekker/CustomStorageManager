#include "ScannerReader.h"

ScannerReader::ScannerReader() {
	scannerHandle = hid_open(0x4b4,0x100,NULL);
        if (scannerHandle == NULL){
                printf("De scanner kon niet worden geopent. (Run het programma als root)");
        }
	running = false;
}

void ScannerReader::start() {
	watcherThread = thread(&ScannerReader::scanRead, this);
	watcherThread.detach();
	running = true;
}

void ScannerReader::stop() {
	running = false;
}

bool ScannerReader::isRunning() {
	return running;
}

void ScannerReader::scanRead() {
	//check for data
	map<int,char> hidMap ={{ 4, 'a'}, { 5, 'b'}, { 6, 'c'}, { 7, 'd'}, { 8, 'e'}, { 9, 'f'}, { 10, 'g'}, { 11, 'h'}, { 12, 'i'}, { 13, 'j'}, { 14, 'k'}, { 15, 'l'}, { 16, 'm'}, { 17, 'n'}, { 18, 'o'}, { 19, 'p'}, { 20, 'q'}, { 21, 'r'}, { 22, 's'}, { 23, 't'}, { 24, 'u'}, { 25, 'v'}, { 26, 'w'}, { 27, 'x'}, { 28, 'y'}, { 29, 'z'}, { 30, '1'}, { 31, '2'}, { 32, '3'}, { 33, '4'}, { 34, '5'}, { 35, '6'}, { 36, '7'}, { 37, '8'}, { 38, '9'}, { 39, '0'}, { 44, ' '}, { 45, '-'}, { 46, '='}, { 47, '['}, { 48, ']'}, { 49, '\\'}, { 51, ';' }, { 52, '\''}, { 53, '~'}, { 54, ','}, { 55, '.'}, { 56, '/'  } };
        map<int,char> hidMapShift = {{ 4, 'A'}, {5, 'B'}, {6, 'C'}, {7, 'D'}, {8, 'E'}, {9, 'F'}, {10, 'G'}, {11, 'H'}, {12, 'I'}, {13, 'J'}, {14, 'K'}, {15, 'L'}, {16, 'M'}, {17, 'N'}, {18, 'O'}, {19, 'P'}, {20, 'Q'}, {21, 'R'}, {22, 'S'}, {23, 'T'}, {24, 'U'}, {25, 'V'}, {26, 'W'}, {27, 'X'}, {28, 'Y'}, {29, 'Z'}, {30, '!'}, {31, '@'}, {32, '#'}, {33, '$'}, {34, '%'}, {35, '^'}, {36, '&'}, {37, '*'}, {38, '('}, {39, ')'}, {44, ' '}, {45, '_'}, {46, '+'}, {47, '{'}, {48, '}'}, {49, '|'}, {51, ':' }, {52, '"'}, {53, '~'}, {54, '<'}, {55, '>'}, {56, '?'  }};
        int res;
        ostringstream bar;
        unsigned char buf[65];
        int i, ii;
        int shift = 0;

	while(1) {
                res = hid_read(scannerHandle, buf, 65);
                for (i = 0; i < res; i++) {
                        if (buf[i] == 40) {
                                lastRead = bar.str();
				read = true;
				bar.str("");
                                continue;
                        }
                        if (buf[i] != 0) {
                            char asciiChar;
                            if (buf[i] == 2) {
                                shift = 1;
                                continue;
                            }

                            map<int,char>::iterator it = hidMap.find(buf[i]);
                            auto endit = end(hidMap);
                            if (shift == 1) {
                                it = hidMapShift.find(buf[i]);
                                endit = end(hidMapShift);
                            }
                            if (it == endit) {
                                asciiChar = '?';
                            } else {
                                asciiChar = it->second;
                            }
                            shift = 0;
                            bar << asciiChar;
                        }
                }
        }
}

string ScannerReader::getLastRead() {
	read = false;
	return lastRead;
}

bool ScannerReader::hasRead() {
	return read;
}

ScannerReader::~ScannerReader() {

}
