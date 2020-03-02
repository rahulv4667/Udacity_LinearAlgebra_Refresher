#include<iostream>
#include<cmath>
namespace linear_algebra {

	template<typename T>
	class Vector {
	private:
		T* coordinates;
		unsigned dimensions;

		
		template<typename H>
		int assignElements(H& last) {
			dimensions++;
			coordinates = new T[dimensions];
			if (coordinates)
				coordinates[dimensions - 1] = (T)last;
			else
				dimensions = 0;
			return dimensions - 2;
		}

		template<typename H,typename... Hs>
		int assignElements(H& first, Hs&... others) {
			dimensions++;
			int index = assignElements(others...);
			if(coordinates)
				coordinates[index] = (T)first;
			return index - 1;
		}

		


	public:

		

		Vector() {
			coordinates = NULL;
			dimensions = 0;
		}

		template<typename... Ts>
		Vector(Ts... co_ordinates) {
			
			try {
				dimensions = 0;
				if (assignElements(co_ordinates...) < -1)
					throw  -2;
					
			}
			catch (int x) {
				x = x + 1;
				std::cout << "Memory insufficient for allocation of Vector\n";
			}
			catch (...) {
				std::cout << "Error in assignment of elements\n";
			}

		}

		/*template<typename... Ts>
		void reassign(Ts... co_ordinates) {
			
			try {
				delete[] coordinates;
				if (assignElements(co_ordinates...) < -1)
					throw  -2;
			}
			catch (int x) {
				std::cout << "Memory insufficient for allocation of Vector\n";
			}
			catch (...) {
				std::cout << "Error in assignment of elements\n";
			}
		}*/

		void fromArray(T* arr, unsigned size) {
			
			try {
				dimensions = size;
				if(!coordinates)
					delete[] coordinates;
				coordinates = new T[dimensions];
				if (coordinates) {
					for (unsigned i = 0; i < dimensions; i++)
						coordinates[i] = (T)arr[i];

				}
				else throw - 2;
			}
			catch (int x) {
				x = x + 1;
				std::cout << "Memory insufficient for allocation of Vector\n";
			}
			catch (...) {
				std::cout << "Error in assignment of elements\n";
			}
			
		}
		

		Vector(const Vector& copy) {
			
			fromArray(copy.coordinates, copy.dimensions);
			
		}


		Vector& operator = (const Vector& vec) {
			
			fromArray(vec.coordinates, vec.dimensions);
			return *this;
		}




		void operator += (const Vector& vec) {
			try {
				for (unsigned i = 0; i < dimensions; i++)
					coordinates[i] += (T)vec.coordinates[i];
			}
			catch (...) {
				std::cout << "Error in addition of vectors due to non-matching dimensions";
			}

		}

		Vector operator + (const Vector& vec) {
			
			try {

				Vector<T> result;
				result.fromArray(coordinates, dimensions);
				result += vec;
				return result;
			}
			catch (...) {
				std::cout << "Error in addition operation on given vectors. May be caused due insufficient memory or non-matching dimensions of vectors";
			}
			
		}


		void operator -= (const Vector& vec) {
			try {
				for (unsigned i = 0; i < dimensions; i++)
					coordinates[i] -= (T)vec.coordinates[i];
			}
			catch (...) {
				std::cout << "Error in subtraction of vectors due to non-matching dimensions";
			}

		}

		Vector operator - (const Vector& vec) {

			try {

				Vector<T> result;
				result.fromArray(coordinates, dimensions);
				result -= vec;
				return result;
			}
			catch (...) {
				std::cout << "Error in subtraction operation on given vectors. May be caused due insufficient memory or non-matching dimensions of vectors";
			}

		}

		Vector operator * (const Vector& vec) {
			try {
				T* arr = new T[dimensions];
				for (unsigned i = 0; i < dimensions; i++)
					arr[i] = coordinates[i] * vec.coordinates[i];
				Vector<T> result;
				result.fromArray(arr, dimensions);
				delete[] arr;
				return result;
			}
			catch (...) {
				std::cout << "Exception raised in performing element wise multiplication. May be due to non-matching dimensions\n";
			}
		}

		void operator *= (const Vector& vec) {
			try {
				
				for (unsigned i = 0; i < dimensions; i++)
					coordinates[i] *= (T)vec.coordinates[i];
				
			}
			catch (...) {
				std::cout << "Exception raised in performing element wise multiplication. May be due to non-matching dimensions\n";
			}
		}
		
		Vector operator * (T scalar) {
			try {

				Vector<T> result;
				result.fromArray(coordinates, dimensions);
				result *= scalar;
				return result;
			}
			catch (...) {
				std::cout << "Error in subtraction operation on given vectors. May be caused due insufficient memory or non-matching dimensions of vectors";
			}
			
		}

		void operator *= (T scalar) {
			for (unsigned i = 0; i < dimensions; i++)
				coordinates[i] *= scalar;
		}

		


		 float getMagnitude() const {
			float magnitude = 0.0;
			for (unsigned i = 0; i < dimensions; i++)
				magnitude += ((float)coordinates[i] * (float)coordinates[i]);
			return sqrt(magnitude);
		}

		Vector getNormalisedVector() {
			try {
				float magnitude = getMagnitude();
				float *arr = new float[dimensions];
				for (unsigned i = 0; i < dimensions; i++)
					arr[i] = (float)coordinates[i] / magnitude;
				Vector<float> normalVec;
				normalVec.fromArray(arr, dimensions);
				delete[] arr;
				return normalVec;
			}
			catch (...) {
				std::cout << "Error in generating normalised vector. May be caused due to insufficient memoery or zero magnitude\n";
			}
		}


		T atDim(unsigned dim) const {
			return coordinates[dim];
		}


		float dotProduct(const Vector& vec) {
			float dotProd = 0.0;
			try {
				
				for (unsigned i = 0; i < dimensions; i++)
					dotProd += ((float)coordinates[i] * (float)vec.atDim(i));
				return dotProd;
			}
			catch (...) {
				std::cout << "Exception while calculating dot product. May be due to non-matching dimensions\n";
			}
		}

		float angleWith(const Vector& vec) {
			try {
				float angle = 0.0;
				float selfMag = getMagnitude();
				float vecMag = vec.getMagnitude();
				float dotprod = dotProduct(vec);
				angle = acos(dotprod / (selfMag * vecMag));
				return angle;
			}
			catch (...) {
				std::cout << "Error in calculating angle between vectors. May be due to non-matching dimensions or zero magnitude of vectors\n";
			}
			
		}


		bool isParallelTo(const Vector& vec) {
			if (floor(getMagnitude()) == 0.0f || floor(vec.getMagnitude()) == 0.0f) return true;
			float angle = angleWith(vec);
			return (floor(angle)==0.0f||angle==3.141592f);
		}

		bool isOrthogonalTo(const Vector& vec) {
			float dotProd = dotProduct(vec);
			return (dotProd == 0.0f);
		}


		Vector crossProduct(const Vector& vec) {
			try {
				Vector<T> result;
				T arr[3];
				if (dimensions == 3) {
					arr[0] = (coordinates[1] * vec.atDim(2)) - (coordinates[2] * vec.atDim(1));
					arr[1] = (coordinates[2] * vec.atDim(0)) - (coordinates[0] * vec.atDim(2));
					arr[2] = (coordinates[0] * vec.atDim(1)) - (coordinates[1] * vec.atDim(0));
					result.fromArray(arr, 3);
					return result;
				}
				return NULL;
			}
			catch (...) {

			}
		}


		void printElements() {
			std::cout << std::endl;
			for (unsigned i = 0; i < dimensions; i++)
				std::cout << coordinates[i] << " ";
			std::cout << std::endl;
		}

		int getDimensions() {
			return dimensions;
		}


		bool isEmpty() {
			return (dimensions == 0) ? false : true;
		}




		~Vector() {
			delete[] coordinates;
			coordinates = NULL;
			dimensions = 0;
		}

	};

}