#include "UniquePtr.h"
#include "Vector.h"
#include <memory>

struct TT
{
	TT() = default;
	int val;
};

int main()
{
	UniquePtr<TT> ptr{ new TT{6} };
	std::unique_ptr<TT> uptr{ new TT{5} };

	uptr->val = 5;

	ptr->val = 5;

	return 0;
}