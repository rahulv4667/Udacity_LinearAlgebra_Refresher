#include<iostream>
#include"LinearAlgebra.cpp"
int main() {

	/*linear_algebra::Vector<int> v(1, 2, 3,5.0,7);
	std::cout << v.getDimensions() << std::endl;
	std::cout << "Printing elements in vector v:\n";
	v.printElements();

	std::cout << std::endl;
	int a[] = { 1,2,3 };

	linear_algebra::Vector<int> v1;
	v1.fromArray(a, 3);
	std::cout << v1.getDimensions() << std::endl;
	std::cout << "Printing elements in vector v1:\n";
	v1.printElements();

	std::cout << std::endl;
	linear_algebra::Vector<int> v2(v1);
	std::cout << v2.getDimensions() << std::endl;
	std::cout << "Printing elements in vector v2:\n";
	v2.printElements();

	std::cout << std::endl;
	linear_algebra::Vector<int> v3;
	v3 = v1 + v2;

	std::cout << v3.getDimensions() << std::endl;
	std::cout << "Printing elements in vector v3:\n";
	v3.printElements();

	std::cout << std::endl;
	v3 -= v1;
	std::cout << v3.getDimensions() << std::endl;
	std::cout << "Printing elements in vector v3:\n";
	v3.printElements();

	std::cout << std::endl;
	v3 = v1*4;
	std::cout << v3.getDimensions() << std::endl;
	std::cout << "Printing elements in vector v3:\n";
	v3.printElements();*/

	linear_algebra::Vector<float> v(8.462,7.893,-8.187);
	linear_algebra::Vector<float> w(6.984,-5.975,4.778);
	
	linear_algebra::Vector<float> result;

	result = v.crossProduct(w);

	std::cout << std::endl;
	std::cout << "Cross Product of v and w : \t";
	result.printElements();
	std::cout << std::endl;
	
	
	v=linear_algebra::Vector<float>(-8.987,-9.838,5.031);
	w=linear_algebra::Vector<float>(-4.268,-1.861,-8.866);


	result = v.crossProduct(w);

	std::cout << std::endl;
	std::cout<<"Area of parallelogram: \t"<<result.getMagnitude()<<std::endl;
	std::cout << std::endl;


	
	v=linear_algebra::Vector<float>(1.5,9.547,3.691);
	w=linear_algebra::Vector<float>(-6.007,0.124,5.772);

	result = v.crossProduct(w);

	std::cout << std::endl;
	std::cout << "Area of Triangle: \t" << result.getMagnitude()/2 << std::endl;
	std::cout << std::endl;


	getchar();
	
}