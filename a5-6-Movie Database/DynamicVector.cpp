#include "DynamicVector.h"
#include <assert.h>

void DynamicVectorTests::TestAll()
{
	TestConstructors();
	TestAdding();
	TestRemovingAndSubscript();
	TestAssignmentAndEquality();
}

void DynamicVectorTests::TestConstructors()
{
	DynamicVector<size_t> v1;
	assert(v1.currentSize == 0);
	assert(v1.maxSize == 0);
	assert(v1.elements == nullptr);

	DynamicVector<size_t> v2(10);
	assert(v2.currentSize == 0);
	assert(v2.maxSize == 10);
	assert(v2.elements != nullptr);
}

void DynamicVectorTests::TestAdding()
{
	DynamicVector<size_t> v1(1);
	v1.AddElement(2);
	assert(v1.currentSize == 1);
	v1.AddElement(3);
	assert(v1.currentSize == 2);
	assert(v1.maxSize == 2);
}

void DynamicVectorTests::TestRemovingAndSubscript()
{
	DynamicVector<size_t> v1(1);
	v1.AddElement(2);
	v1.AddElement(3);
	v1.AddElement(4);
	v1.AddElement(5);
	v1.AddElement(6);
	v1.RemoveElement(0);
	assert(v1[0] == 3);
	v1.RemoveElement(1);
	assert(v1[1] == 5);
}

void DynamicVectorTests::TestAssignmentAndEquality()
{
	DynamicVector<size_t> v1(1);
	v1.AddElement(2);
	v1.AddElement(3);
	v1.AddElement(4);
	v1.AddElement(5);
	v1.AddElement(6);
	DynamicVector<size_t> v2(8);

	v2 = v1;
	assert(v1 == v2);
	v2.RemoveElement(0);
	v2.AddElement(1);
	assert(!(v1 == v2));
}


