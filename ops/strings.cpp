/**
Copyright (c) 2007 - 2009 Jordan "Earlz/hckr83" Earls  <http://www.Earlz.biz.tm>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the author may not be used to endorse or promote products
   derived from this software without specific prior written permission.
   
THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

This file is part of the x86Lib project.
**/
#include <x86Lib.h>
namespace x86Lib{
using namespace std;



void x86CPU::op_movsb(){
	WriteByte(cES,Reg(DI),ReadByte(DS,Reg(SI)));
	SetIndex8();
}

void x86CPU::op_movsW(){
	WriteW(cES, Reg(DI), ReadW(DS, Reg(SI)));
	SetIndex();
}

void x86CPU::op_cmpsb(){
	uint8_t prev = ReadCode8(-1);
	if( prev == 0xF3 || prev == 0xF2) string_compares=1; //only set string_compares if previous was REPZ/REPNZ
	Sub8(ReadByte(DS,Reg(SI)),ReadByte(cES,Reg(DI)));
	SetIndex8();
}

void x86CPU::op_cmpsW(){
	uint8_t prev = ReadCode8(-1);
	if( prev == 0xF3 || prev == 0xF2) string_compares=1;
	SubW(ReadW(DS, Reg(SI)), ReadW(cES,Reg(DI)));
	SetIndex();
}

void x86CPU::op_lodsb(){
	*regs8[AL]=ReadByte(DS,Reg(SI));
	SetIndex8();
}
void x86CPU::op_lodsW(){
	WriteReg(AX, ReadW(DS,Reg(SI)));
	SetIndex();
}

void x86CPU::op_scasb(){
	uint8_t prev = ReadCode8(-1);
	if( prev == 0xF3 || prev == 0xF2) string_compares=1;
	Sub8(*regs8[AL],ReadByte(cES,Reg(DI)));
	SetIndex8();
}
void x86CPU::op_scasW(){
	uint8_t prev = ReadCode8(-1);
	if( prev == 0xF3 || prev == 0xF2) string_compares=1;
	SubW(Reg(AX),ReadW(cES,Reg(DI)));
	SetIndex();
}

void x86CPU::op_stosb(){
	WriteByte(ES,Reg(DI),*regs8[AL]);
	SetIndex8();
}

void x86CPU::op_stosW(){
	WriteW(ES,Reg(DI),Reg(AX));
	SetIndex();
}




};



