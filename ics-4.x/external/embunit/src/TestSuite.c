/*
 * COPYRIGHT AND PERMISSION NOTICE
 * 
 * Copyright (c) 2003 Embedded Unit Project
 * 
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, and/or sell copies of the Software, and to permit persons 
 * to whom the Software is furnished to do so, provided that the above 
 * copyright notice(s) and this permission notice appear in all copies 
 * of the Software and that both the above copyright notice(s) and this 
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT 
 * OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY 
 * SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER 
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF 
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 * Except as contained in this notice, the name of a copyright holder 
 * shall not be used in advertising or otherwise to promote the sale, 
 * use or other dealings in this Software without prior written 
 * authorization of the copyright holder.
 *
 * $Id: //DTV/MP_BR/DTV_X_IDTV0801_002158_10_001_158_001/android/ics-4.x/external/embunit/src/TestSuite.c#1 $
 */
#include "Test.h"
#include "TestSuite.h"

char* TestSuite_name(TestSuite* self)
{
	return self->name;
}

void TestSuite_run(TestSuite* self,TestResult* result)
{
	int i;
	Test* test;
	if (self->tests) {
		for (i=0; i<self->numberOfTests; i++) {
			test = self->tests[i];
			Test_run(test, result);
		}
	}
}

int TestSuite_countTestCases(TestSuite* self)
{
	int count = 0;
	int i;
	Test* test;
	if (self->tests) {
		for (i=0; i<self->numberOfTests; i++) {
			test = self->tests[i];
			count += Test_countTestCases(test);
		}
	}
	return count;
}

const TestImplement TestSuiteImplement = {
	(TestNameFunction)			TestSuite_name,
	(TestRunFunction)			TestSuite_run,
	(TestCountTestCasesFunction)TestSuite_countTestCases,
};