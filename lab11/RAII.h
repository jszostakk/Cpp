//
// Created by student on 10.01.22.
//

#ifndef LAB11_RAII_H
#define LAB11_RAII_H

using namespace std;

template <typename T>

class uPtr{
    T* data;
    int *references;
public:
    uPtr(T* data){
        references = new int;
        *references = 1;
    }
    uPtr(uPtr& u){
        references = u.references;
        //kopia wskaznika danych
        (*references)++;
    };
    uPtr operator=(uPtr&) = delete;

    ~uPtr(){
        *references -= 1;
        if(*references)
    }
};


#endif //LAB11_RAII_H
