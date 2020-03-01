#include<iostream>

namespace linear_algebra {

	template<typename T>
	class Vector {
	private:
		T* coordinates;
		unsigned dimensions;

		void calculateDims(T& last) {
			dinemsions++;
		}

		void calculateDims(T& first,T&... ordinates) {
			dimensions++;
			calculateDims(ordinates...);
		}


	public:
		Vector() {
			coordinates = NULL;
			dimensions = 0;
		}

		Vector(T... co_ordinates) {
			dimensions = 0;
			calculateDims(co_ordinates...);
		}

		int getDimensions() {
			return dimensions;
		}

		bool isEmpty() {
			return (dimensions==0) ? false : true;
		}



	};

}