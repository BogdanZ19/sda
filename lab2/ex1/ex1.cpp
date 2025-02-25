#include <iostream>
#include "sortingAlg.h"
#include <chrono>

int main()
{
    int nr = 10000, contorBbl, contorSel, contorIns, contorBruteSrch, contorBinarySrch;
    // int x[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int x[nr];

    for (int i = 0; i < nr; i++)
        x[i] = rand() % 100 + 1;

    int *y, *z;

    y = copyArr(x, nr);
    z = copyArr(x, nr);

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    

    bubbleSort(x, nr, contorBbl);
    
    end = std::chrono::system_clock::now();
    std::cout << "Contor bubbleSort = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    std::cout << "Contor bubbleSort = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    std::cout << "Contor bubbleSort = " << contorBbl << " operatii" << std::endl;

    
    start = std::chrono::system_clock::now();
 
    selectionSort(y, nr, contorSel);
    
    end = std::chrono::system_clock::now();
    std::cout << "\nContor selectionSort = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    std::cout << "Contor selectionSort = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    std::cout << "Contor selectionSort = "  << contorSel << " operatii" << std::endl;

    
    start = std::chrono::system_clock::now();
 
    insertionSort(z, nr, contorIns);
    
    end = std::chrono::system_clock::now();
    std::cout << "\nContor insertionSort = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    std::cout << "Contor insertionSort = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    std::cout << "Contor insertionSort = " << " operatii" << contorIns  << std::endl;
    

    start = std::chrono::system_clock::now();
        
    std::cout << std::endl << "bruteForce(26): " << bruteForceSrch(x, nr, 26, contorBruteSrch);
    
    end = std::chrono::system_clock::now();
    std::cout << "\nContor bruteForceSrch = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    std::cout << "Contor bruteForceSrch = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    std::cout << "Contor bruteForceSrch = " << contorBruteSrch << " operatii" << std::endl;


    start = std::chrono::system_clock::now();
 
    std::cout << std::endl << "binarySrch(26): " << binarySrch(x, nr, 26, contorBinarySrch);
    
    end = std::chrono::system_clock::now();
    std::cout << "\nContor contorBinarySrch = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    std::cout << "Contor contorBinarySrch = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    std::cout << "Contor contorBinarySrch = " << contorIns << " operatii" << std::endl;


    // afisare(x, nr);
    // std::cout << std::endl;
    // afisare(y, nr);
    // std::cout << std::endl;
    // afisare(z, nr);
    // std::cout << std::endl;

    delete[] y;
    delete[] z;

    return 0;
}