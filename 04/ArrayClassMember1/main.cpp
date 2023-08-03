	#include <iostream>
	#include <memory>

	class MyClass
	{
	public:
		void someMemberFunction()
		{
			std::cout << "Calling someMemberFunction()" << std::endl;
		}
	};

	int main()
	{
		// Creating a unique_ptr with a dynamically allocated object of MyClass
		std::unique_ptr<MyClass> sourcePtr = std::make_unique<MyClass>();

		// Accessing the object using the arrow operator (->)
		sourcePtr->someMemberFunction(); // Alternatively: (*sourcePtr).someMemberFunction();

		// Transferring ownership from sourcePtr to destinationPtr using move semantics
		std::unique_ptr<MyClass> destinationPtr = std::move(sourcePtr);

		// After the move, sourcePtr is now nullptr, and destinationPtr owns the object

		// Attempting to call someMemberFunction using sourcePtr after the move will result in a runtime error,
		// as sourcePtr no longer owns the object

		return 0;
	}
