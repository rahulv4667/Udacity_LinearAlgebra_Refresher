#include<iostream>

namespace linear_algebra {

	template<class T>
	class Vector {
		T* coordinates;

	public:
		Vector() {
			coordinates = NULL;
		}

		Vector(T *co_ordinates) {
			coordinates=(T*)malloc()
		}

		bool isEmpty() {
			return (coordinates) ? false : true;
		}



	};

}