#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include "simplecalc.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;;

int simplecalc(FILE * input_stream)
{
	// Your code codes here
	uint64_t accumulator = 0;
	uint8_t buf[8192];
	int readAmount = fread(buf, sizeof(uint8_t), 8192, input_stream);
  	uint64_t operand = 0;
  	string op = "";
  	for(int i = 0; i < readAmount; ++i) {
  		
  		if(buf[i] == '\n' || buf[i] == ' ') {
  			continue;
  		}
  		else if(buf[i] == '\r') {
  			if(op == "SET") {
  				accumulator = operand;
  			}
  			else if(op == "ADD") {
				accumulator += operand;
  			}
  			else if(op == "SUB") {
  				accumulator -= operand;
  			}
  			else if(op == "MUL"){
  				accumulator *= operand;
  			}
  			else if(op == "") {
  				cout << accumulator << endl;
  				accumulator = 0;
  			}
  			else {
  				cout << "Invalid operator" << endl;
  				return -1;
  			}
  			operand = 0;
  			op = "";
  		}
  		else if(buf[i] >= '0' && buf[i] <= '9') {
  			
  			operand = operand * 10 + (buf[i] - '0');
  		}
  		else {
  			op += buf[i];
  		}
  	}
	// return 0 on success, non-zero on error
	return 0;
}
