#pragma once
#include <utility>

template<class Type>
class UniquePtr
{
public:
	UniquePtr() :
		ptr{ nullptr }
	{}

	UniquePtr(Type* ptr) :
		ptr{ ptr }
	{}

	UniquePtr(UniquePtr&& other) :
		ptr{ other.ptr }
	{
		other.ptr = nullptr;
	}

	~UniquePtr() { delete ptr; }

	UniquePtr& operator=(UniquePtr&& other)
	{
		ptr = other.ptr;
		other.ptr = nullptr;
	}

	UniquePtr(const UniquePtr& other)				= delete;
	UniquePtr& operator=(const UniquePtr& other)	= delete;

	Type& operator*() const noexcept
	{
		return *ptr;
	}

	Type* operator->() const noexcept
	{
		return ptr;
	}

private:
	Type* ptr;
};