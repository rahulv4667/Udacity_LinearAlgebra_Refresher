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

	linear_algebra::Vector<float> v(7.887,4.138);
	linear_algebra::Vector<float> w(-8.802,6.776);
	//linear_algebra::Vector<float> *cleaner;
	std::cout << "Dot product between v and w: " << v.dotProduct(w) << std::endl;
	
	
	//cleaner = &v;
	v=linear_algebra::Vector<float>(-5.955, -4.904, -1.874);
	//delete cleaner;
	//cleaner = &w;
	w=linear_algebra::Vector<float>(-4.496, -8.755, 7.103);
	//delete cleaner;
	std::cout << "Dot product between v and w: " << v.dotProduct(w) << std::endl;

	
	//cleaner = &v;
	//v.reassign<float>(3.183,-7.627);
	//free(cleaner);
	//cleaner = &w;
	//w.reassign(-2.668,5.319);
	//free(cleaner);
	std::cout << "Angle between v and w: " << v.angleWith(w) << std::endl;

	//cleaner = &v;
	//v.reassign(7.35, 0.221,5.188);
	//free(cleaner);
	//cleaner = &w;
	//w.reassign(2.751,8.259,3.985);
	//free(cleaner);
	std::cout << "Angle between v and w: " << v.angleWith(w) << std::endl;



	getchar();
	
}